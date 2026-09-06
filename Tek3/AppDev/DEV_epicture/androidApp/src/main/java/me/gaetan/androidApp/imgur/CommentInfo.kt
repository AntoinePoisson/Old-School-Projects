package me.gaetan.androidApp.me.gaetan.androidApp.imgur

data class CommentInfo (
    val id: String,
    val image_id: String,
    val comment: String,
    val author: String,
    val ups: Int,
    val downs: Int
)

data class CommentInfoResponse (
    val data: List<CommentInfo>,
    val success: String,
    val status: Int
)