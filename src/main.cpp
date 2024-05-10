#include <iostream>
#include <curl/curl.h>
#include <sstream>
#include "customParser.h"

size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* buffer);

int main() {
    CURL* curl;
    CURLcode res;
    const std::string URL = "https://www.wow-mania.com/pvpstats/redemption/battleground.php?id=";
    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    for (int i = 1; i < 10; i++) {
        std::string htmlContent;
        std::string currentURL = URL + std::to_string(i);
        curl_easy_setopt(curl, CURLOPT_URL, currentURL.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &htmlContent);
        res = curl_easy_perform(curl);

        customParser CParser(htmlContent);
        CParser.findHeaders();
        std::cout << CParser.battlegroundName << " " << CParser.faction << std::endl;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}

size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    size_t totalSize = size * nmemb;
    buffer->append((char*)contents, totalSize);
    return totalSize;
}
