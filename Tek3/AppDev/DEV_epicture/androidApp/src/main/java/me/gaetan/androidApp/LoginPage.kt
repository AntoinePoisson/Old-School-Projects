package me.gaetan.androidApp

import androidx.appcompat.app.AppCompatActivity
import android.webkit.WebView
import android.os.Bundle
import android.webkit.CookieManager
import android.webkit.CookieSyncManager
import android.widget.Button
import android.widget.ImageView


/**
 * An example full-screen activity that shows and hides the system UI (i.e.
 * status bar and navigation/system bar) with user interaction.
 */
class LoginPage : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_login_page)

        val loginView: WebView = findViewById<WebView>(R.id.webViewLogin)
        loginView.getSettings().setJavaScriptEnabled(true)
        loginView.settings.setAppCacheEnabled(false)
        CookieManager.getInstance().removeAllCookies(null)
        CookieManager.getInstance().flush()
        loginView.loadUrl("https://api.imgur.com/oauth2/authorize?client_id=d247b54a5263816&response_type=token")
    }
}