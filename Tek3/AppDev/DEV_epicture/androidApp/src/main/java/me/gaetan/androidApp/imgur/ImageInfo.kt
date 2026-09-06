package me.gaetan.androidApp.me.gaetan.androidApp.imgur

data class ImageInfo (
    val title: String,
    val description: String,
    val link: String,
    val views: Int,
    val ups: Int,
    val downs: Int,
)

data class ImageInfoResponse (
    val data: List<ImageInfo>,
    val success: String,
    val status: Int
)