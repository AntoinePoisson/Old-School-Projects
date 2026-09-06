package me.gaetan.androidApp

import android.graphics.Picture
import android.media.Image
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.FrameLayout
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.GridLayoutManager
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.airbnb.lottie.LottieAnimationView
import com.google.android.material.snackbar.Snackbar
import me.gaetan.androidApp.me.gaetan.androidApp.imgur.*
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response

/**
 * A simple [Fragment] subclass.
 * Use the [Feed.newInstance] factory method to
 * create an instance of this fragment.
 */
class Feed : Fragment() {
    var token: String = ""
    var username: String = ""
    var imgList: ArrayList<GalleryInfo> = ArrayList<GalleryInfo>()
    lateinit var adapter: GalleryImageListAdapter

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        val req = ServiceBuilder.buildService(GalleryImageEndPoint::class.java)
        val c = req.getGalleryImage("Bearer $token", "hot", "viral", "week", 1, true, true, true)
        Toast.makeText(getActivity() , "Welcome Back $username!", Toast.LENGTH_SHORT).show()
        c.enqueue(object : Callback<GalleryInfoResponse> {
            override fun onResponse(call: Call<GalleryInfoResponse>, response: Response<GalleryInfoResponse>) {
                if (response.isSuccessful) {
                    if (response.body() != null) {
                        imgList.addAll(response.body()!!.data)
                        adapter.notifyDataSetChanged()
                        val anim = view?.findViewById<LottieAnimationView>(R.id.feed_loading_lottie_view)
                        anim?.pauseAnimation()
                        anim?.visibility = View.GONE
                    }
                }
            }
            override fun onFailure(call: Call<GalleryInfoResponse>, t: Throwable) {
                println("Error ${t.message}")
                Toast.makeText(getActivity() , "Failure to load Gallery images", Toast.LENGTH_LONG).show()
            }
        })
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        return inflater.inflate(R.layout.fragment_feed, container, false)
    }

    override fun onResume() {
        super.onResume()
        if (adapter.selected != -1) {
            val selected = adapter.selected
            val req = ServiceBuilder.buildService(GalleryImageEndPoint::class.java)
            val c = req.getGalleryAlbum("Bearer $token", imgList[selected].id)
            c.enqueue(object : Callback<AlbumResponse> {
                override fun onResponse(call: Call<AlbumResponse>, response: Response<AlbumResponse>) {
                    if (response.isSuccessful) {
                        if (response.body() != null) {
                            imgList[selected] = response.body()!!.data
                            adapter.notifyItemChanged(selected)
                        }
                    }
                }
                override fun onFailure(call: Call<AlbumResponse>, t: Throwable) {
                    println("Error ${t.message}")
                    Snackbar.make(view!!, "Failed to update", Snackbar.LENGTH_LONG).setAction("Action", null).show()
                }
            })
        }
    }

    fun updateImageData(index: Int) {

    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        val recView = view.findViewById<RecyclerView>(R.id.list_feed)
        adapter = GalleryImageListAdapter(imgList,  activity!!, token)
        recView.adapter = adapter
        recView.layoutManager = GridLayoutManager(view.context, 1)
        if (imgList.size > 0) {
            val anim = view.findViewById<LottieAnimationView>(R.id.feed_loading_lottie_view)
            anim?.pauseAnimation()
            anim?.visibility = View.GONE
        }
    }

    override fun onDestroyView() {
        super.onDestroyView()
    }

    companion object {
        @JvmStatic
        fun newInstance() = Feed()
    }
}