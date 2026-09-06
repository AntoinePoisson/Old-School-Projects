package me.gaetan.androidApp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.content.Intent
import java.io.File

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val button: Button = findViewById<Button>(R.id.button)
        button.setOnClickListener {
            startActivity(Intent(this@MainActivity, LoginPage::class.java))
        }
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
            val i: Intent = Intent(this@MainActivity, HomePage::class.java)
            i.putExtra("access_token", data[0])
            i.putExtra("expire", data[1])
            i.putExtra("refresh_token", data[2])
            i.putExtra("username", data[3])
            i.putExtra("account_id", data[4])
            startActivity(i)
        } else {
            println("credential file does not exist")
        }
    }
}
