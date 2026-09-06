package me.gaetan.androidApp.me.gaetan.androidApp

import android.media.Image
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import androidx.recyclerview.widget.StaggeredGridLayoutManager
import com.bumptech.glide.Glide
import com.google.android.material.snackbar.Snackbar
import me.gaetan.androidApp.R
import me.gaetan.androidApp.TagListAdapter
import me.gaetan.androidApp.me.gaetan.androidApp.imgur.*
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response

class DetailImageViewListAdapter(private val img: DetailImageViewListAdapter.ImageInfo, private val data: List<CommentInfo>, private val id: String): RecyclerView.Adapter<RecyclerView.ViewHolder>() {

    public data class ImageInfo(
        val id: String,
        val title: String,
        val description: String,
        val url: String,
        val author: String,
        val cover: String,
        val ups: Int,
        val downs: Int,
    )

    private fun getFormatedNbr(number: Int): String {
        if (number < 1000)
            return number.toString()
        val exp = (kotlin.math.ln(number.toDouble()) / kotlin.math.ln(1000.0)).toInt()
        return String.format("%.1f %c", number / Math.pow(1000.0, exp.toDouble()), "kMGTPE"[exp - 1])
    }

    inner class ViewHolder(listItemView: View, private val id: String) : RecyclerView.ViewHolder(listItemView) {
        val imgView = itemView.findViewById<ImageView>(R.id.cell_image_detail_image)!!
        val description = itemView.findViewById<TextView>(R.id.cell_image_detail_description)!!
        val userImg = itemView.findViewById<ImageView>(R.id.cell_image_detail_user_image)!!
        val author = itemView.findViewById<TextView>(R.id.cell_image_detail_username)!!
        val upVote = itemView.findViewById<TextView>(R.id.text_up_vode)!!
        val downVote = itemView.findViewById<TextView>(R.id.text_down_vote)!!
        val tagRecycler = itemView.findViewById<RecyclerView>(R.id.cell_image_tag)!!
        var tags: ArrayList<GalleryInfoTag> = ArrayList<GalleryInfoTag>()
        private lateinit var tagAdapter: TagListAdapter

        init {
            loadTag()
        }

        private fun loadTag() {
            tagAdapter = TagListAdapter(tags)
            tagRecycler.adapter = tagAdapter
            tagRecycler.layoutManager = StaggeredGridLayoutManager(2, StaggeredGridLayoutManager.HORIZONTAL)
            val req = ServiceBuilder.buildService(GalleryImageEndPoint::class.java)
            val c = req.getGalleryAlbum("Client-ID d247b54a5263816", id)
            c.enqueue(object : Callback<AlbumResponse> {
                override fun onResponse(call: Call<AlbumResponse>, response: Response<AlbumResponse>) {
                    if (response.isSuccessful) {
                        if (response.body() != null) {
                            tags.addAll(response.body().data.tags)
                            tagAdapter.notifyDataSetChanged()
                        }
                    }
                }
                override fun onFailure(call: Call<AlbumResponse>, t: Throwable) {
                    println("Error ${t.message}")
                    Snackbar.make(tagRecycler, "Failed to load tags", Snackbar.LENGTH_LONG).setAction("Action", null).show()
                }
            })
        }
    }

    inner class ViewHolder2(listItemView: View) : RecyclerView.ViewHolder(listItemView) {
        val imgView = itemView.findViewById<ImageView>(R.id.cell_image_comment_image)!!
        val author = itemView.findViewById<TextView>(R.id.cell_image_comment_author)!!
        val comment = itemView.findViewById<TextView>(R.id.cell_image_comment_description)!!
        val upVoteTwo = itemView.findViewById<TextView>(R.id.text_up_vode)!!
        val upDownTwo = itemView.findViewById<TextView>(R.id.text_down_vote)!!
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): RecyclerView.ViewHolder {
        val context = parent.context
        val inflater = LayoutInflater.from(context)
        if (viewType == 0) {
            val contactView = inflater.inflate(R.layout.cell_image_detail, parent, false)
            return ViewHolder(contactView, id)
        } else {
            val contactView = inflater.inflate(R.layout.cell_image_detail_comment, parent, false)
            return ViewHolder2(contactView)
        }
    }

    override fun getItemViewType(position: Int): Int {
        if (position == 0)
            return 0
        return 1
    }

    override fun onBindViewHolder(viewHolder: RecyclerView.ViewHolder, position: Int) {
        if (viewHolder.itemViewType == 0) {
            val view = viewHolder as ViewHolder
            view.description.text = img.description
            Glide.with(viewHolder.itemView).load(img.url).into(view.imgView)
            if (img.cover != "") {
                Glide.with(viewHolder.itemView).load(img.cover).into(view.userImg)
            } else {
                Glide.with(viewHolder.itemView).load(R.drawable.image_not_found).into(view.userImg)
            }
            view.author.text = img.author
            view.upVote.text = getFormatedNbr(img.ups)
            view.downVote.text = getFormatedNbr(img.downs)
        } else if (viewHolder.itemViewType == 1) {
            val view = viewHolder as ViewHolder2
            Glide.with(viewHolder.itemView).load("https://imgur.com/user/${data[position - 1].author}/avatar").into(view.imgView)
            view.author.text = data[position - 1].author
            view.comment.text = data[position - 1].comment
            view.upVoteTwo.text = getFormatedNbr(data[position - 1].ups)
            view.upDownTwo.text = getFormatedNbr(data[position - 1].downs)
        }
    }

    // Returns the total count of items in the list
    override fun getItemCount(): Int {
        return 1 + data.size
    }
}