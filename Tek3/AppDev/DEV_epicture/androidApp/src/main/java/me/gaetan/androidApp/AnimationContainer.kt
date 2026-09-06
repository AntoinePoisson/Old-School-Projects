package me.gaetan.androidApp

import android.graphics.drawable.Drawable
import android.view.View
import com.airbnb.lottie.LottieAnimationView
import com.bumptech.glide.load.DataSource
import com.bumptech.glide.load.engine.GlideException
import com.bumptech.glide.request.RequestListener
import com.bumptech.glide.request.target.Target

class AnimationContainer(private val anim: LottieAnimationView): RequestListener<Drawable> {
    override fun onLoadFailed(e: GlideException?, model: Any?, target: Target<Drawable>?, isFirstResource: Boolean): Boolean {
        anim.pauseAnimation()
        anim.visibility = View.GONE
        return false
    }

    override fun onResourceReady(resource: Drawable?, model: Any?, target: Target<Drawable>?, dataSource: DataSource?, isFirstResource: Boolean): Boolean {
        anim.pauseAnimation()
        anim.visibility = View.GONE
        return false
    }
}