package me.gaetan.androidApp

import android.content.Context
import android.content.Intent
import android.net.Uri
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle

class RedirectActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_redirect)

        if (intent?.data != null) {
            val data: Uri? = intent?.data
            val dataStr = (data?.toString()?.split("#"))!![1]
            val value = dataStr.split(Regex("=*&"))
            val token = value[0].split("=")[1]
            val expire = value[1].split("=")[1]
            val refreshToken = value[2].split("=")[1]
            val accountUsername = value[3].split("=")[1]
            val accountId = value[4].split("=")[1]
            val fileContents = "$token\n$expire\n$refreshToken\n$accountUsername\n$accountId"
            applicationContext.openFileOutput("credential", Context.MODE_PRIVATE).use {
                it.write(fileContents.toByteArray())
            }
            val i: Intent = Intent(this@RedirectActivity, HomePage::class.java)
            i.putExtra("access_token", token)
            i.putExtra("expire", expire)
            i.putExtra("refresh_token", refreshToken)
            i.putExtra("username", accountUsername)
            i.putExtra("account_id", accountId)
            startActivity(i)
        }
    }
}