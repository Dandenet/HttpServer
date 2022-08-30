#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <stdint.h>
#include <string>

struct HttpRequest
{
    uint64_t httpVersionMajor;
    uint64_t httpVersionMinor;
    std::string uri;
    std::string method;


    friend bool operator == (const HttpRequest& l, const HttpRequest& r);
};

bool operator == (const HttpRequest& l, const HttpRequest& r);

#endif // HTTPREQUEST_H
