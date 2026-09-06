package me.gaetan.androidApp

import android.content.Context
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.view.inputmethod.InputMethod
import android.view.inputmethod.InputMethodManager
import android.widget.Button
import android.widget.Toast
import androidx.appcompat.widget.AppCompatImageButton
import androidx.recyclerview.widget.GridLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.airbnb.lottie.LottieAnimationView
import com.google.android.material.textfield.TextInputEditText
import kotlinx.android.synthetic.main.feed_items_row.*
import me.gaetan.androidApp.me.gaetan.androidApp.imgur.*
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response

/**
 * A simple [Fragment] subclass.
 * Use the [Research.newInstance] factory method to
 * create an instance of this fragment.
 */
class Research : Fragment() {
    var token: String = ""
    var imgList: ArrayList<GalleryInfo> = ArrayList<GalleryInfo>()
    lateinit var adapter: GalleryImageListAdapter

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_research, container, false)
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        val textInput = view.findViewById<TextInputEditText>(R.id.search_text_input)
        val searchButton = view.findViewById<AppCompatImageButton>(R.id.search_button)
        searchButton.setOnClickListener {
            searchString(textInput.text.toString())
            view.let {
                var keyboard = activity?.getSystemService(Context.INPUT_METHOD_SERVICE) as InputMethodManager
                keyboard.hideSoftInputFromWindow(view.windowToken, 0)
            }
        }
        val recView = view.findViewById<RecyclerView>(R.id.search_recycler_view)
        adapter = GalleryImageListAdapter(imgList, activity!!, token)
        recView.adapter = adapter
        recView.layoutManager = GridLayoutManager(view.context, 1)
        val anim = view.findViewById<LottieAnimationView>(R.id.search_lottie_animation)
        anim.visibility = View.GONE
        anim.pauseAnimation()
    }

    private fun searchString(search: String) {
        println("Searching $search")
        val anim = view?.findViewById<LottieAnimationView>(R.id.search_lottie_animation)
        anim?.visibility = View.VISIBLE
        anim?.playAnimation()
        val req = ServiceBuilder.buildService(SearchEndPoint::class.java)
        val c = req.getSearch("Client-ID d247b54a5263816", search)
        c.enqueue(object : Callback<GalleryInfoResponse> {
            override fun onResponse(call: Call<GalleryInfoResponse>, response: Response<GalleryInfoResponse>) {
                if (response.isSuccessful) {
                    if (response.body() != null) {
                        imgList.clear()
                        imgList.addAll(response.body()!!.data)
                        adapter.notifyDataSetChanged()
                        println(response.body()!!)
                        anim?.visibility = View.GONE
                        anim?.pauseAnimation()
                    }
                }
            }
            override fun onFailure(call: Call<GalleryInfoResponse>, t: Throwable) {
                println("Error ${t.message}")
                Toast.makeText(getActivity() , "Failure search", Toast.LENGTH_LONG).show()
            }
        })
    }

    companion object {
        /**
         * Use this factory method to create a new instance of
         * this fragment using the provided parameters.
         *
         * @return A new instance of fragment Research.
         */
        @JvmStatic
        fun newInstance() = Research()
    }
}