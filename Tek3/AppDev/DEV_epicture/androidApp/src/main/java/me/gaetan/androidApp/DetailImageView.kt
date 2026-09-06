package me.gaetan.androidApp

import android.graphics.Color
import android.os.Bundle
import android.view.MenuItem
import android.widget.*
import androidx.appcompat.app.ActionBar
import com.google.android.material.floatingactionbutton.FloatingActionButton
import com.google.android.material.snackbar.Snackbar
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat
import androidx.recyclerview.widget.DividerItemDecoration
import androidx.recyclerview.widget.GridLayoutManager
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.airbnb.lottie.LottieAnimationView
import jp.wasabeef.recyclerview.adapters.SlideInBottomAnimationAdapter
import me.gaetan.androidApp.me.gaetan.androidApp.DetailImageViewListAdapter
import me.gaetan.androidApp.me.gaetan.androidApp.imgur.*
import org.w3c.dom.Text
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response

class DetailImageView : AppCompatActivity() {
    private lateinit var token: String
    private lateinit var id: String
    private lateinit var title: String
    private lateinit var url: String
    private lateinit var description: String
    private lateinit var author: String
    private lateinit var cover: String
    private var ups: Int = 0
    private var downs: Int = 0
    private var fav: Int = 0
    private var data: ArrayList<CommentInfo> = ArrayList<CommentInfo>()
    private lateinit var adapter: DetailImageViewListAdapter
    private var isUpvote: Boolean = false
    private var isDownvote: Boolean = false
    private var isFav: Boolean = false
    private lateinit var upVoteLbl: TextView
    private lateinit var downVoteLbl: TextView
    private lateinit var  favLbl: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_detail_image_view)

        setSupportActionBar(findViewById(R.id.image_info_toolbar))
        supportActionBar?.setDisplayHomeAsUpEnabled(true)

        id = intent.getStringExtra("id")
        title = intent.getStringExtra("title")
        url = intent.getStringExtra("url")
        description = intent.getStringExtra("description")
        author = intent.getStringExtra("author")
        cover = intent.getStringExtra("cover")
        token = intent.getStringExtra("token")
        ups = intent.getIntExtra("ups", 0)
        downs = intent.getIntExtra("downs", 0)
        fav = intent.getIntExtra("fav", 0)
        isFav = intent.getBooleanExtra("isfav", false)
        val tmpVote = intent.getStringExtra("vote")

        when (tmpVote) {
            "up" -> isUpvote = true
            "down" -> isDownvote = true
        }

        supportActionBar?.title = title

        upVoteLbl = findViewById(R.id.detail_image_up_text)
        downVoteLbl = findViewById(R.id.detail_image_down_text)
        favLbl = findViewById(R.id.detail_image_fav_text)

        supportActionBar?.title = title

        val imgData = DetailImageViewListAdapter.ImageInfo(id, title, description, url, author, cover, ups, downs)
        val recView = findViewById<RecyclerView>(R.id.image_detail_recycler_view)
        val divider: RecyclerView.ItemDecoration = DividerItemDecoration(this, DividerItemDecoration.VERTICAL)
        recView.addItemDecoration(divider)
        adapter = DetailImageViewListAdapter(imgData, data, id)
        recView.adapter = SlideInBottomAnimationAdapter(adapter)
        recView.layoutManager = LinearLayoutManager(this)

        val req = ServiceBuilder.buildService(CommentEndPoint::class.java)
        val c = req.getComment("Client-ID d247b54a5263816", id)
        c.enqueue(object : Callback<CommentInfoResponse> {
            override fun onResponse(call: Call<CommentInfoResponse>, response: Response<CommentInfoResponse>) {
                if (response.isSuccessful) {
                    if (response.body() != null) {
                        data.addAll(response.body()!!.data)
                        adapter.notifyDataSetChanged()
                    }
                }
            }
            override fun onFailure(call: Call<CommentInfoResponse>, t: Throwable) {
                println("Error ${t.message}")
                Toast.makeText(getApplicationContext() , "Error loading image details", Toast.LENGTH_LONG).show()
            }
        })



        val upvote: LinearLayout = findViewById<LinearLayout>(R.id.detail_upvote)
        upvote.setOnClickListener {
            isUpvote = !isUpvote
            if (isUpvote) {
                changeImgVote("up")
                ups++
                if (isDownvote)
                    downs--
                isDownvote = false
            } else {
                changeImgVote("veto")
                ups--
            }
            updateVoteUi()
        }
        val downvote: LinearLayout = findViewById<LinearLayout>(R.id.detail_downvote)
        downvote.setOnClickListener {
            isDownvote = !isDownvote
            if (isDownvote) {
                changeImgVote("down")
                downs++
                if (isUpvote)
                    ups--
                isUpvote = false
            } else {
                changeImgVote("veto")
                downs--
            }
            updateVoteUi()
        }
        val favL: LinearLayout = findViewById<LinearLayout>(R.id.detail_favorite)
        favL.setOnClickListener {
            isFav = !isFav
            if (!isFav) {
                fav--
            } else {
                fav++
            }
            changeImgFav()
            updateFavUi()
        }
        updateVoteUi()
        updateFavUi()
    }

    private fun updateVoteUi() {
        val upvoteAnim: LottieAnimationView = findViewById<LottieAnimationView>(R.id.detail_upvote_lottie)
        if (!isUpvote) {
            upvoteAnim.pauseAnimation()
            upvoteAnim.frame = 0
            upVoteLbl.setTextColor(ContextCompat.getColor(this, R.color.vote_default))
        } else {
            upvoteAnim.playAnimation()
            upVoteLbl.setTextColor(ContextCompat.getColor(this, R.color.upvote))
        }
        if (!isDownvote) {
            downVoteLbl.setTextColor(ContextCompat.getColor(this, R.color.vote_default))
        } else {
            downVoteLbl.setTextColor(ContextCompat.getColor(this, R.color.downvote))
        }
        upVoteLbl.text = "$ups"
        downVoteLbl.text = "$downs"
    }

    private fun updateFavUi() {
        val favAnim: LottieAnimationView = findViewById<LottieAnimationView>(R.id.detail_favorite_lottie)
        if (isFav) {
            favAnim.setMaxFrame(60)
            favAnim.playAnimation()
            favLbl.setTextColor(ContextCompat.getColor(this, R.color.upvote))
        } else {
            favAnim.pauseAnimation()
            favAnim.frame = 0
            favLbl.setTextColor(ContextCompat.getColor(this, R.color.vote_default))
        }
        favLbl.text = "$fav"
    }

    private fun changeImgFav() {
        val req = ServiceBuilder.buildService(GalleryImageEndPoint::class.java)
        val c = req.favAlbum("Bearer $token", id)
        c.enqueue(object : Callback<BasicResponse> {
            override fun onResponse(call: Call<BasicResponse>, response: Response<BasicResponse>) {
                if (response.isSuccessful) {
                    println("fav OK")
                }
            }
            override fun onFailure(call: Call<BasicResponse>, t: Throwable) {
                println("Error ${t.message}")
                val view = findViewById<FrameLayout>(R.id.image_detail_recycler_view)
                Snackbar.make(view, "Failed to change fav", Snackbar.LENGTH_LONG).setAction("Action", null).show()
            }
        })
    }

    private fun changeImgVote(str: String) {
        val req = ServiceBuilder.buildService(VoteEndPoint::class.java)
        val c = req.voteImage("Bearer $token", id, str)
        c.enqueue(object : Callback<BasicResponse> {
            override fun onResponse(call: Call<BasicResponse>, response: Response<BasicResponse>) {
                if (response.isSuccessful) {
                    println("$str OK")
                }
            }
            override fun onFailure(call: Call<BasicResponse>, t: Throwable) {
                println("Error ${t.message}")
                val view = findViewById<FrameLayout>(R.id.image_detail_recycler_view)
                Snackbar.make(view, "$str failed", Snackbar.LENGTH_LONG).setAction("Action", null).show()
            }
        })
    }

    override fun onOptionsItemSelected(item: MenuItem?): Boolean {
        val id = item?.itemId

        if (id == android.R.id.home)
            this.finish()
        return super.onOptionsItemSelected(item)
    }
}