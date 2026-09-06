package me.gaetan.androidApp.me.gaetan.androidApp.imgur

import okhttp3.RequestBody
import retrofit2.Call
import retrofit2.http.GET
import retrofit2.http.Path
import retrofit2.http.Header
import retrofit2.http.Query
import retrofit2.http.POST
import retrofit2.http.Multipart
import retrofit2.http.Part

interface UserInfoEndPoint {
    @GET("/3/account/{username}")
    fun getUserInfo(@Header("Authorization") authorization: String, @Path("username") username: String): Call<AccountInfoResponse>
}

interface UserImageEndPoint {
    @GET("/3/account/me/images")
    fun getUserImage(@Header("Authorization") authorization: String): Call<ImageInfoResponse>
}

interface UploadImageEndPoint {
    @Multipart
    @POST("/3/image")
    fun uploadImage(@Header("Authorization") authorization: String, @Part("image") imageData: RequestBody): Call<UploadResponse>
}

interface GalleryImageEndPoint {
    @GET("/3/gallery/{section}/{sort}/{window}/{page}")
    fun getGalleryImage(@Header("Authorization") authorization: String, @Path("section") section: String, @Path("sort") sort: String, @Path("window") window: String, @Path("page") page: Int, @Query("showViral") showViral: Boolean, @Query("showMature") showMature: Boolean, @Query("albumPreviews") albumPreviews: Boolean): Call<GalleryInfoResponse>
    @GET("/3/gallery/album/{album}")
    fun getGalleryAlbum(@Header("Authorization") authorization: String, @Path("album") album: String): Call<AlbumResponse>
    @POST("/3/album/{album}/favorite")
    fun favAlbum(@Header("Authorization") authorization: String, @Path("album") album: String): Call<BasicResponse>
}

interface SearchEndPoint {
    @GET("/3/gallery/search")
    fun getSearch(@Header("Authorization") authorization: String, @Query("q") search: String): Call<GalleryInfoResponse>
}

interface CommentEndPoint {
    @GET("/3/gallery/{post_id}/comments/")
    fun getComment(@Header("Authorization") authorization: String, @Path("post_id") postId: String): Call<CommentInfoResponse>
}

interface VoteEndPoint {
    @POST("/3/gallery/{gallery_hash}/vote/{vote}")
    fun voteImage(@Header("Authorization") authorization: String, @Path("gallery_hash") imageId: String, @Path("vote") vote: String): Call<BasicResponse>
    fun upvoteImage(authorization: String, imageId: String) { voteImage(authorization, imageId, "up")}
    fun downvoteImage(authorization: String, imageId: String) { voteImage(authorization, imageId, "down")}
    fun vetovoteImage(authorization: String, imageId: String) { voteImage(authorization, imageId, "veto")}
}

interface PostCommentEndPoint {
    @Multipart
    @POST("/3/gallery/{gallery_hash}/comment")
    fun postComment(@Header("Authorization") authorization: String, @Path("gallery_hash") imageId: String, @Part("comment") comment: RequestBody): Call<CommentResponse>
}