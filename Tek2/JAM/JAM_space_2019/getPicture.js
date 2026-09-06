function getPictures()
{
    var pictures = [];
    var url = "https://api.nasa.gov/planetary/apod?api_key=XXXXXXXX_NASA_APOD_API_KEY_REDACTED_XXXX&date=";
	var date = new Date();
	static var count = 0;

    date.setDate(date.getDate() - count);
    for (i = 0; i < 20; i++) {
		$.getJSON(url + date.toJSON().substr(0, 10), function(data) {
			if (data.media_type.localeCompare("image") == 0)
				pictures.push(data);
			else
				i = i - 1;
		});
		date.setDate(date.getDate() - 1);
    }
    count = count + 20;
	return pictures;
}