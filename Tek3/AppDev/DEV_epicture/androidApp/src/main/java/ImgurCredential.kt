package me.gaetan.androidApp

import android.content.Context
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import android.net.Uri
import com.google.android.material.bottomnavigation.BottomNavigationView
import com.ncapdevi.fragnav.FragNavController

class ImgurCredential {
    var accessToken: String = ""
    var expire: Int = 0
    var refreshToken: String = ""
    var username: String = ""
    var accountId: Int = 0
}