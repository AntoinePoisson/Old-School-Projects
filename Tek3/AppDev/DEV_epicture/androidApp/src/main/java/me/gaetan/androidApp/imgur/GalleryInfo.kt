package me.gaetan.androidApp.me.gaetan.androidApp.imgur

data class GalleryInfoImage (
    val id: String,
    val title: String,
    val description: String,
    val datetime: Long,
    val type: String,
    val animated: Boolean,
    val width: Int,
    val height: Int,
    val size: Int,
    val views: Int,
    val favorite: Boolean,
    val is_ad: Boolean,
    val in_most_viral: Boolean,
    val has_sound: Boolean,
    val ad_type: Int,
    val ad_url: String,
    val in_gallery: Boolean,
    val link: String,
)

data class GalleryInfoTag (
    val name: String,
    val display_name: String,
    val followers: Int,
    val total_items: Int,
    val following: Boolean,
    val is_whitelisted: Boolean,
    val background_hash: String,
    val accent: String?,
    val background_is_animated: Boolean,
    val thumbnail_is_animated: Boolean,
    val is_promoted: Boolean,
    val description: String,
)

data class GalleryInfo (
    val id: String,
    val title: String,
    val description: String?,
    val datetime: Long,
    val cover: String?,
    val cover_width: Int,
    val cover_height: Int,
    val account_url: String?,
    val account_id: Long,
    val privacy: String,
    val layout: String,
    val views: Int,
    val link: String,
    val ups: Int,
    val downs: Int,
    val points: Int,
    val score: Int,
    val is_album: Boolean,
    val vote: String?,
    val favorite: Boolean,
    val nsfw: Boolean,
    val section: String,
    val comment_count: Int,
    val favorite_count: Int,
    val topic: String,
    val topic_id: Int,
    val images_count: Int,
    val in_gallery: Boolean,
    val is_ad: Boolean,
    val tags: List<GalleryInfoTag>,
    val ad_type: Int,
    val ad_url: String,
    val in_most_viral: Boolean,
    val include_album_ads: Boolean,
    val images: List<GalleryInfoImage>,
)

data class GalleryInfoResponse (
    val data: List<GalleryInfo>,
    val success: String,
    val status: Int
)

data class AlbumResponse (
    val data: GalleryInfo,
    val success: String,
    val status: Int
)

data class UploadResponse (
    val data: GalleryInfo,
    val success: String,
    val status: Int
)

data class CommentInfos (
    val id: Int,
)

data class CommentResponse (
    val data: Array<CommentInfos>,
    val success: Boolean,
    val status: Int
)