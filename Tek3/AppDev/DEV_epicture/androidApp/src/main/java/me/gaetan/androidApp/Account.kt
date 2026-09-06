package me.gaetan.androidApp

import android.Manifest
import android.content.Intent
import android.content.pm.PackageManager
import android.os.Build
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.widget.AppCompatImageButton
import androidx.core.content.ContextCompat
import androidx.fragment.app.Fragment
import androidx.recyclerview.widget.GridLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide
import jp.wasabeef.recyclerview.adapters.AlphaInAnimationAdapter
import jp.wasabeef.recyclerview.animators.SlideInUpAnimator
import me.gaetan.androidApp.me.gaetan.androidApp.imgur.*
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import java.io.File

const val PERMISSION_CODE_READ: Int = 1001
const val IMAGE_PICK_CODE: Int = 1000

/**
 * A simple [Fragment] subclass.
 * Use the [Account.newInstance] factory method to
 * create an instance of this fragment.
 */

class Account : Fragment() {
    var imgList: ArrayList<ImageInfo> = ArrayList<ImageInfo>()
    lateinit var adapter: PictureListAdapter
    var username: String = ""
    var avatarUrl: String = ""
    var coverUrl: String = ""
    var userToken: String? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        println("bearer $userToken")
        getUserImage()
        loadUserInfo()
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        val pseudoLbl = view.findViewById<TextView>(R.id.username_label)
        val avatar = view.findViewById<ImageView>(R.id.avatar)
        val cover = view.findViewById<ImageView>(R.id.cover_image_view)
        if (avatarUrl != "") {
            Glide.with(view).load(avatarUrl).into(avatar)
        }
        if (coverUrl != "") {
            Glide.with(view).load(coverUrl).into(cover)
        }
        pseudoLbl?.text = username

        val recView = view.findViewById<RecyclerView>(R.id.account_rec_view)
        adapter = PictureListAdapter(imgList)
        recView.adapter = AlphaInAnimationAdapter(adapter)
        recView.layoutManager = GridLayoutManager(view.context, 2)
        recView.setHasFixedSize(true)

        configureButton()
    }

    private fun loadUserInfo() {
        val req = ServiceBuilder.buildService(UserInfoEndPoint::class.java)
        val c = req.getUserInfo("Client-ID d247b54a5263816", "gandous")
        c.enqueue(object : Callback<AccountInfoResponse> {
            override fun onResponse(call: Call<AccountInfoResponse>, response: Response<AccountInfoResponse>) {
                if (response.isSuccessful) {
                    if (response.body() != null) {
                        val pseudoLbl = view?.findViewById<TextView>(R.id.username_label)
                        pseudoLbl?.text = response.body().data.url
                        username = response.body().data.url
                        val avatar = view?.findViewById<ImageView>(R.id.avatar)
                        avatarUrl = response.body().data.avatar
                        Glide.with(view?.context!!).load(avatarUrl).into(avatar!!)
                        val cover = view?.findViewById<ImageView>(R.id.cover_image_view)
                        coverUrl = response.body().data.cover
                        Glide.with(view?.context!!).load(coverUrl).into(cover!!)
                    }
                    println(response.body()!!)
                }
            }

            override fun onFailure(call: Call<AccountInfoResponse>, t: Throwable) {
                println("Error")
                Toast.makeText(getActivity(), "Can't load Account Info", Toast.LENGTH_LONG).show()
            }
        })
    }

    fun getUserImage() {
        val request = ServiceBuilder.buildService(UserImageEndPoint::class.java)
        val call = request.getUserImage("Bearer $userToken")
        call.enqueue(object : Callback<ImageInfoResponse> {
            override fun onResponse(call: Call<ImageInfoResponse>, response: Response<ImageInfoResponse>) {
                if (response.isSuccessful) {
                    if (response.body() != null) {
                        imgList.clear()
                        imgList.addAll(response.body()!!.data)
                        adapter.notifyDataSetChanged()
                    }
                    println(response.body()!!)
                }
            }

            override fun onFailure(call: Call<ImageInfoResponse>, t: Throwable) {
                println("Error ${t.message}")
                Toast.makeText(getActivity(), "Can't to load Account Images", Toast.LENGTH_LONG).show()
            }
        })
    }

    private fun configureButton() {
        val uploadButton = view?.findViewById<AppCompatImageButton>(R.id.upload_button)
        uploadButton?.setOnClickListener {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                if ((ContextCompat.checkSelfPermission(context!!, Manifest.permission.READ_EXTERNAL_STORAGE) == PackageManager.PERMISSION_DENIED)) {
                    val permission = arrayOf(Manifest.permission.READ_EXTERNAL_STORAGE)
                    requestPermissions(permission, PERMISSION_CODE_READ)
                } else {
                    val intent = Intent(Intent.ACTION_PICK)
                    intent.type = "image/*"
                    startActivityForResult(intent, IMAGE_PICK_CODE)
                }
            }
        }
        val logoutButton = view?.findViewById<AppCompatImageButton>(R.id.logout_button)
        logoutButton?.setOnClickListener {
            println("delete ${clearCacheFolder(context?.cacheDir)} cache file")
            println("${clearCacheFolder(context?.filesDir)} file dir")
            startActivity(Intent(view?.context, MainActivity::class.java))
        }
    }

    fun clearCacheFolder(dir: File?): Int {
        var deletedFiles = 0
        if (dir != null && dir.isDirectory) {
            try {
                for (child in dir.listFiles()) {
                    if (child.isDirectory) {
                        deletedFiles += clearCacheFolder(child)
                    }
                    if (child.delete()) {
                        deletedFiles++
                    }
                }
            } catch (e: Exception) {
                println("Failed to clean the cache, error ${e.message}")
            }
        }
        return deletedFiles
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_account, container, false)
    }

    companion object {
        @JvmStatic
        fun newInstance() = Account()
    }

}