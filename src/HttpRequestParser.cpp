#include "HttpRequestParser.h"
#include <sstream>
#include <exception>

/**
 * Requst example: GET /images/logo.png HTTP/1.1
**/
HttpRequest HttpRequestParser::Parse(const std::string &buffer)
{
    if (buffer.empty())
        throw HttpRequestParseException("HttpRequestParser::Parser. Empty buffer");

    HttpRequest request;
    std::stringstream stream(buffer);
    std::string version;

    stream >> request.method >> request.uri >> version;

    auto index = version.find("/");
    if ( index == std::string::npos)
        throw HttpRequestParseException("HttpRequestParser. Invalid request");


    version = version.substr(index + 1, version.length());

    index = version.find(".");
    if ( index == std::string::npos)
        throw HttpRequestParseException("HttpRequestParser. Invalid request");


    request.httpVersionMajor = std::stoul(version.substr(0, index));
    request.httpVersionMinor = std::stoul(version.substr(index + 1,
                                                         version.length()));




    return request;
}
