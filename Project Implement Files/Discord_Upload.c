#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl.h>

// Replace with your actual bot token and channel ID
const char* BOT_TOKEN = "";
const char* CHANNEL_ID = "1223264248348676226";

// Function to upload a file to Discord
void uploadFile(const char* filePath) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error initializing libcurl\n");
        return;
    }

    // Construct the API URL
    char apiUrl[200];
    snprintf(apiUrl, sizeof(apiUrl), "https://discord.com/api/v10/channels/%s/messages", CHANNEL_ID);

    // Set up headers
    struct curl_slist* headers = NULL;
    char authHeader[100];
    snprintf(authHeader, sizeof(authHeader), "Authorization: Bot %s", BOT_TOKEN);
    headers = curl_slist_append(headers, authHeader);
    headers = curl_slist_append(headers, "Content-Type: multipart/form-data");

    // Set up form data using curl_mime API
    struct curl_mime* mime = curl_mime_init(curl);
    struct curl_mimepart* part = curl_mime_addpart(mime);
    curl_mime_name(part, "file");
    curl_mime_filedata(part, filePath);

    // Make the POST request
    curl_easy_setopt(curl, CURLOPT_URL, apiUrl);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_MIMEPOST, mime);

    // Disable SSL certificate verification (not recommended for production)
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error uploading file: %s\n", curl_easy_strerror(res));
    }

    // Clean up
    curl_easy_cleanup(curl);
    curl_mime_free(mime);
    curl_slist_free_all(headers);
}

int main() {
    const char* filePath = "E:\\Codeing\\Python Language\\Projects\\Project_19\\log.txt"; // Replace with your file path
    uploadFile(filePath);
    return 0;
}
