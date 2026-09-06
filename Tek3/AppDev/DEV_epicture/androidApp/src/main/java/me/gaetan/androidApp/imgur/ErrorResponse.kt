package me.gaetan.androidApp.me.gaetan.androidApp.imgur

data class ErrorData (
    val error: String,
    val success: String,
    val method: String
)

data class ErrorResponse (
    val data: ErrorData,
    val success: String,
    val status: Int
)