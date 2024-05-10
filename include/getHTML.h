#ifndef GETHTML_H
#define GETHTML_H

#include <iostream>
#include <string>
#include <curl/curl.h>
#include "customParser.h"

#define LATEST_BG 27341

class getHTML
{
public:
    getHTML();
    ~getHTML();

private:
    const std::string URL = "https://www.wow-mania.com/pvpstats/redemption/battleground.php?id=";
    CURL* curl;
    CURLcode res;
};

size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* buffer);

#endif // GETHTML_H
