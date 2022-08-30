#ifndef REQUESTPARSER_H
#define REQUESTPARSER_H

#include <string>
#include <exception>

#include "HttpRequest.h"


class HttpRequestParser
{
public:
    static HttpRequest Parse(const std::string& path);

    HttpRequestParser() = delete;
    HttpRequestParser(const HttpRequestParser&) = delete;
    HttpRequestParser(HttpRequestParser&&) = delete;

    HttpRequestParser& operator= (const HttpRequestParser&) = delete;
    HttpRequestParser&& operator= (HttpRequestParser&&) = delete;
};



class HttpRequestParseException : public std::exception {
public:
    HttpRequestParseException (const std::string& message) :
        std::exception(message.c_str()) {}
};


#endif // REQUESTPARSER_H
