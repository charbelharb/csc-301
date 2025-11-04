//
// Created by charbel on 11/4/25.
//

#include "HttpClient.h"

#include <iostream>

class HttpClient {
    static void TryGet(std::string url) {
        curl_global_init(CURL_GLOBAL_DEFAULT);
        if (CURL *curl = curl_easy_init()) {
            curl_easy_setopt(curl, CURLOPT_URL, &url);
            if (const CURLcode res = curl_easy_perform(curl); res != CURLE_OK)
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();
    }
};
