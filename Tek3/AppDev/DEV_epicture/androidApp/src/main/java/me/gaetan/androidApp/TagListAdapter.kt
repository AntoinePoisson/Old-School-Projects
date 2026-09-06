package me.gaetan.androidApp

import android.graphics.Color
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.cardview.widget.CardView
import androidx.recyclerview.widget.RecyclerView
import com.airbnb.lottie.LottieAnimationView
import com.bumptech.glide.Glide
import me.gaetan.androidApp.me.gaetan.androidApp.imgur.GalleryInfoTag
import me.gaetan.androidApp.me.gaetan.androidApp.imgur.ImageInfo

class TagListAdapter(private val data: List<GalleryInfoTag>): RecyclerView.Adapter<TagListAdapter.ViewHolder>() {

    inner class ViewHolder(listItemView: View) : RecyclerView.ViewHolder(listItemView) {
        val tag: TextView = itemView.findViewById(R.id.cell_tag_text)
        val bg: CardView = itemView.findViewById(R.id.cell_tag_background)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): TagListAdapter.ViewHolder {
        val context = parent.context
        val inflater = LayoutInflater.from(context)
        val contactView = inflater.inflate(R.layout.cell_tag, parent, false)
        return ViewHolder(contactView)
    }

    override fun onBindViewHolder(viewHolder: TagListAdapter.ViewHolder, position: Int) {
        viewHolder.tag.text = data[position].name
        if (data[position].accent != null)
            viewHolder.bg.setCardBackgroundColor(Color.parseColor("#" + data[position].accent))
    }

    // Returns the total count of items in the list
    override fun getItemCount(): Int {
        return data.size
    }
}