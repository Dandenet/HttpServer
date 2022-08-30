#include "HttpResponse.h"
#include <sstream>
std::map<HttpResponse::HttpStatusCode, std::string>
HttpResponse::m_StatusTable = {
    { HttpResponse::Ok, "OK"},
    { HttpResponse::Created, "Created"},
    { HttpResponse::Accepted, "Accepted"},
    { HttpResponse::NoContent, "No Content"},
    { HttpResponse::BadRequest, "Bad Request"},
    { HttpResponse::Forbidden, "Forbidden"},
    { HttpResponse::NotFound, "Not Found"},
    { HttpResponse::NotImplemented, "Not Implemented"},
    { HttpResponse::BadGateway, "Bad Gateway"}
};


HttpResponse::HttpResponse(HttpStatusCode statusCode, const std::string &body) :
    m_StatusCode(statusCode), m_Body(body)
{

}

std::string HttpResponse::ToString() const
{
    std::stringstream ss;

    ss << "HTTP/1.1 " << m_StatusCode << " "
       << m_StatusTable.at(m_StatusCode) << "\r\n"
       << "\r\n" << m_Body;

    return ss.str();
}
