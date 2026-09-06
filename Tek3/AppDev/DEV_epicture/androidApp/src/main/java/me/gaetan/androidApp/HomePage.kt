package me.gaetan.androidApp

import android.app.Activity
import android.content.Intent
import android.graphics.Bitmap
import android.os.Bundle
import android.provider.MediaStore
import android.view.View
import android.widget.FrameLayout
import android.widget.ImageView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.google.android.material.bottomnavigation.BottomNavigationView
import com.google.android.material.snackbar.Snackbar
import com.google.gson.Gson
import com.google.gson.reflect.TypeToken
import com.ncapdevi.fragnav.FragNavController
import me.gaetan.androidApp.me.gaetan.androidApp.imgur.*
import okhttp3.MediaType
import okhttp3.RequestBody
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import java.io.ByteArrayOutputStream
import java.io.File

class HomePage() : AppCompatActivity() {
    private val navController: FragNavController = FragNavController(supportFragmentManager, R.id.fragment_container)
    private val fragments = listOf(Feed.newInstance(), Research.newInstance(),Account.newInstance())
    private var accessToken: String = ""
    private var username: String = ""

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_home_page)

        loadCredential()
        val tmp = fragments[2] as Account
        tmp.userToken = accessToken
        val feed = fragments[0] as Feed
        feed.token = accessToken
        feed.username = username
        val search = fragments[1] as Research
        search.token = accessToken
        navController.rootFragments = fragments
        navController.initialize(FragNavController.TAB1)
        navController.switchTab(FragNavController.TAB1)
        val bottomView = findViewById<BottomNavigationView>(R.id.bottom_navigation)
        bottomView.setOnNavigationItemSelectedListener {
            when (it.itemId) {
                R.id.nav_item_home -> navController.switchTab(FragNavController.TAB1)
                R.id.nav_item_research -> navController.switchTab(FragNavController.TAB2)
                R.id.nav_item_account -> navController.switchTab(FragNavController.TAB3)
            }
            true
        }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)
        println("request $requestCode")
        println("result $resultCode")
        println("data $data")
        if (data == null)
            return

        val request = ServiceBuilder.buildService(UploadImageEndPoint::class.java)
        val bitmap: Bitmap = MediaStore.Images.Media.getBitmap(contentResolver, data?.data)
        val imgData: ByteArrayOutputStream = ByteArrayOutputStream()
        bitmap.compress(Bitmap.CompressFormat.PNG, 100, imgData)
        val body = RequestBody.create(MediaType.parse("text/plain"), imgData.toByteArray())
        val call = request.uploadImage("Bearer $accessToken", body)
        call.enqueue(object : Callback<UploadResponse> {
            override fun onResponse(call: Call<UploadResponse>, response: Response<UploadResponse>) {
                if (response.isSuccessful){
                    println(response.body()!!)
                    val view = findViewById<FrameLayout>(R.id.fragment_container)
                    Snackbar.make(view, "Image upload", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show()
                    val account = fragments[2] as Account
                    account.getUserImage()
                } else {
                    println("Error ${response.code()}  ${response.errorBody()}")
                    Toast.makeText(getApplicationContext() , "Error upload Image", Toast.LENGTH_LONG).show()
                }
            }
            override fun onFailure(call: Call<UploadResponse>, t: Throwable) {
                println("Error ${t.message}")
                Toast.makeText(getApplicationContext() , "Error upload Image", Toast.LENGTH_LONG).show()
            }
        })
        if (resultCode == Activity.RESULT_OK && requestCode == IMAGE_PICK_CODE) {
            // I'M GETTING THE URI OF THE IMAGE AS DATA AND SETTING IT TO THE IMAGEVIEW
            println("get image")
        }
    }

    private fun loadCredential() {
        var dir = applicationContext.filesDir
        var file = File("$dir/credential")
        if (file.exists()) {
            val str: String = applicationContext.openFileInput("credential").bufferedReader().useLines { lines ->
                lines.fold("") { some, text ->
                    if (some != "") {
                        "$some\n$text"
                    } else {
                        "$text"
                    }
                }
            }
            val data = str.split("\n")
            accessToken = data[0]
            username = data[4]
        } else {
            startActivity(Intent(this, MainActivity::class.java))
        }
    }
}