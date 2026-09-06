package me.gaetan.androidApp

import android.graphics.drawable.Drawable
import androidx.recyclerview.widget.RecyclerView
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import com.airbnb.lottie.LottieAnimationView
import com.bumptech.glide.Glide
import com.bumptech.glide.load.DataSource
import com.bumptech.glide.load.engine.GlideException
import com.bumptech.glide.request.RequestListener
import com.bumptech.glide.request.target.Target
import me.gaetan.androidApp.AnimationContainer
import me.gaetan.androidApp.me.gaetan.androidApp.imgur.ImageInfo

class PictureListAdapter(private val data: List<ImageInfo>): RecyclerView.Adapter<PictureListAdapter.ViewHolder>() {

    private fun getFormatedNbr(number: Int): String {
        if (number < 1000)
            return number.toString()
        val exp = (kotlin.math.ln(number.toDouble()) / kotlin.math.ln(1000.0)).toInt()
        return String.format("%.1f %c", number / Math.pow(1000.0, exp.toDouble()), "kMGTPE"[exp - 1])
    }

    inner class ViewHolder(listItemView: View) : RecyclerView.ViewHolder(listItemView) {
        val imgView = itemView.findViewById<ImageView>(R.id.cell_image)!!
        val textTitle = itemView.findViewById<TextView>(R.id.comment_description)!!
        val textViews = itemView.findViewById<TextView>(R.id.text_up_vode)!!
        val lottieAnim = itemView.findViewById<LottieAnimationView>(R.id.cell_image_lottie_anim)!!
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): PictureListAdapter.ViewHolder {
        val context = parent.context
        val inflater = LayoutInflater.from(context)
        val contactView = inflater.inflate(R.layout.cell_image_view, parent, false)
        return ViewHolder(contactView)
    }

    override fun onBindViewHolder(viewHolder: PictureListAdapter.ViewHolder, position: Int) {

        if (data[position].link != "") {
            Glide.with(viewHolder.itemView).load(data[position].link).addListener(AnimationContainer(viewHolder.lottieAnim)).into(viewHolder.imgView)
        } else {
            Glide.with(viewHolder.itemView).load(R.drawable.image_not_found).addListener(AnimationContainer(viewHolder.lottieAnim)).into(viewHolder.imgView)
        }
        if (data[position].views <= 50) {
            viewHolder.textTitle.text = "Hidden"
            viewHolder.textViews.text = "0"
        } else {
            viewHolder.textTitle.text = "Public"
            viewHolder.textViews.text = getFormatedNbr(data[position].views)
        }
    }

    // Returns the total count of items in the list
    override fun getItemCount(): Int {
        return data.size
    }
}