package me.gaetan.androidApp.me.gaetan.androidApp.imgur

data class AccountInfo (
    val id: String,
    val url: String,
    val bio: String,
    val avatar: String,
    val avatar_name: String,
    val cover: String,
    val cover_name: String,
    val reputation: Int,
    val reputation_name: String,
    val created: String
)

data class AccountInfoResponse (
    val data: AccountInfo,
    val success: String,
    val status: Int
)