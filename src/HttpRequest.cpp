#include "HttpRequest.h"

bool operator ==(const HttpRequest &l, const HttpRequest &r)
{
    return  l.httpVersionMajor    == r.httpVersionMajor   &&
            l.httpVersionMinor    == r.httpVersionMinor   &&
            l.uri                 == r.uri                &&
            l.method              == r.method;
}
