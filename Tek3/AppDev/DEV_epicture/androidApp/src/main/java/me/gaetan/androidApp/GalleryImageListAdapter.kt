package me.gaetan.androidApp

import android.content.Context
import android.content.Intent
import android.graphics.Bitmap
import android.graphics.drawable.Drawable
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import android.widget.EditText
import android.widget.ImageButton
import android.widget.Toast
import androidx.fragment.app.FragmentActivity
import androidx.recyclerview.widget.RecyclerView
import com.airbnb.lottie.LottieAnimationView
import com.bumptech.glide.Glide
import com.bumptech.glide.load.DataSource
import com.bumptech.glide.load.engine.GlideException
import com.bumptech.glide.request.RequestListener
import com.bumptech.glide.request.target.Target
import java.security.PrivilegedAction
import android.view.inputmethod.InputMethodManager;
import androidx.core.content.ContextCompat.getSystemService
import me.gaetan.androidApp.me.gaetan.androidApp.imgur.*
import okhttp3.MediaType
import okhttp3.RequestBody
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import java.io.ByteArrayOutputStream


class GalleryImageListAdapter(private val data: List<GalleryInfo>, private val activity: FragmentActivity, private val token: String): RecyclerView.Adapter<GalleryImageListAdapter.ViewHolder>() {
    var selected: Int = -1

    private fun getFormatedNbr(number: Int): String {
        if (number < 1000)
            return number.toString()
        val exp = (kotlin.math.ln(number.toDouble()) / kotlin.math.ln(1000.0)).toInt()
        return String.format("%.1f %c", number / Math.pow(1000.0, exp.toDouble()), "kMGTPE"[exp - 1])
    }

    class ViewHolder(listItemView: View, private val activity: FragmentActivity, private val token: String, private val parent: GalleryImageListAdapter) : RecyclerView.ViewHolder(listItemView), View.OnClickListener {
        val accountIcon = itemView.findViewById<ImageView>(R.id.account_icon)!!
        val textTitle = itemView.findViewById<TextView>(R.id.text_title)!!
        val textAuthor = itemView.findViewById<TextView>(R.id.text_author)!!
        val textNbrView = itemView.findViewById<TextView>(R.id.text_nbr_view)!!
        val imageGallery = itemView.findViewById<ImageView>(R.id.image_gallery)!!
        val textUpVote = itemView.findViewById<TextView>(R.id.text_up_vode)!!
        val textDescription = itemView.findViewById<TextView>(R.id.text_description)!!
        val textLike = itemView.findViewById<TextView>(R.id.text_like)!!
        val lottieLoadingImg = itemView.findViewById<LottieAnimationView>(R.id.image_loading_lottie)
        var id: String = ""
        var url: String = ""
        var cover: String = ""
        var description: String = ""
        var vote: String = ""
        lateinit var data: GalleryInfo

        init {
            listItemView.setOnClickListener(this)
        }

        override fun onClick(view: View?) {
            val position = adapterPosition
            if (position != RecyclerView.NO_POSITION) {
                println("click pos: $position")
                parent.selected = position
                val i: Intent = Intent(activity, DetailImageView::class.java)
                i.putExtra("id", id)
                i.putExtra("title", textTitle.text.toString())
                i.putExtra("url", url)
                i.putExtra("description", description)
                i.putExtra("author", textAuthor.text.toString())
                i.putExtra("cover", cover)
                i.putExtra("token", token)
                i.putExtra("vote", vote)
                i.putExtra("fav", data.favorite_count)
                i.putExtra("ups", data.ups)
                i.putExtra("downs", data.downs)
                i.putExtra("isfav", data.favorite)
                activity.startActivity(i)
            }
        }
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): GalleryImageListAdapter.ViewHolder {
        val context = parent.context
        val inflater = LayoutInflater.from(context)
        val contactView = inflater.inflate(R.layout.feed_items_row, parent, false)
        return ViewHolder(contactView, activity, token, this)
    }

    override fun onBindViewHolder(viewHolder: GalleryImageListAdapter.ViewHolder, position: Int) {
        if (data[position].account_url != null)
            Glide.with(viewHolder.itemView).load("https://imgur.com/user/${data[position].account_url!!}/avatar").into(viewHolder.accountIcon)
        viewHolder.textTitle.text = data[position].title
        viewHolder.textAuthor.text = data[position].account_url
        viewHolder.textNbrView.text = getFormatedNbr(data[position].views)
        if ((data[position].cover != null) && data[position].images.isNotEmpty()) {
            if (data[position].images[0].type.isNotEmpty() && (data[position].images[0].type.split("/").toTypedArray()[0] == "image")) {
                Glide.with(viewHolder.itemView).load(data[position].images[0].link).addListener(AnimationContainer(viewHolder.lottieLoadingImg)).into(viewHolder.imageGallery)
            } else if (data[position].images[0].type.isNotEmpty() && (data[position].images[0].type.split("/").toTypedArray()[0] == "video")) {
                Glide.with(viewHolder.itemView).load(data[position].images[0].link).addListener(AnimationContainer(viewHolder.lottieLoadingImg)).into(viewHolder.imageGallery)
            } else {
                Glide.with(viewHolder.itemView).load(R.drawable.image_not_found).addListener(AnimationContainer(viewHolder.lottieLoadingImg)).into(viewHolder.imageGallery)
            }
        } else {
            Glide.with(viewHolder.itemView).load(R.drawable.image_not_found).addListener(AnimationContainer(viewHolder.lottieLoadingImg)).into(viewHolder.imageGallery)
        }
        viewHolder.textUpVote.text = getFormatedNbr(data[position].ups)
        viewHolder.textDescription.text = getFormatedNbr(data[position].comment_count)
        viewHolder.textLike.text = getFormatedNbr(data[position].favorite_count)
        viewHolder.cover = "https://imgur.com/user/${data[position].account_url}/avatar"
        viewHolder.url = "https://i.imgur.com/${data[position].cover}.jpg"
        viewHolder.id = data[position].id
        val msgComment = viewHolder.itemView.findViewById<EditText>(R.id.message)
        val btComment = viewHolder.itemView.findViewById<ImageButton>(R.id.bouton_comment)

        btComment.setOnClickListener {
            val msg = msgComment.text
            if (msg.isNotEmpty()) {
                msgComment.setText("")
                val request = ServiceBuilder.buildService(PostCommentEndPoint::class.java)
                val body = RequestBody.create(MediaType.parse("text/plain"), msg.toString().toByteArray())
                val call = request.postComment("Bearer $token", data[position].id, body)
                call.enqueue(object : Callback<CommentResponse> {
                    override fun onResponse(call: Call<CommentResponse>, response: Response<CommentResponse>) {
                        if (response.isSuccessful) {
                            println("Send Comment !")
                            Toast.makeText(activity, "Send Comment !", Toast.LENGTH_SHORT).show()
                        } else {
                            println("Error Comment: $token")
                            println(data[position].id)
                            Toast.makeText(activity, "Can't Send Comment !", Toast.LENGTH_SHORT).show()
                        }
                    }
                    override fun onFailure(call: Call<CommentResponse>, t: Throwable) {
                        println("Error ${t.message}")
                        Toast.makeText(activity, "Send Comment !", Toast.LENGTH_SHORT).show()
                    }
                })
            }
            var keyboard = activity?.getSystemService(Context.INPUT_METHOD_SERVICE) as InputMethodManager
            keyboard.hideSoftInputFromWindow(activity.getCurrentFocus().windowToken, 0)
        }
        if (data[position].description != null)
            viewHolder.description = data[position].description!!
        if (data[position].vote != null)
            viewHolder.vote = data[position].vote!!
        viewHolder.data = data[position]
    }

    override fun getItemCount(): Int {
        return data.size
    }
}