#ifndef RESPONCE_H
#define RESPONCE_H

#include <string>
#include <map>

class HttpResponse {
public:
    enum HttpStatusCode {
        Ok = 200,
        Created = 201,
        Accepted = 202,
        NoContent = 204,
        BadRequest = 400,
        Forbidden = 403,
        NotFound = 404,
        NotImplemented = 501,
        BadGateway = 502,
    };



    HttpResponse (HttpStatusCode statusCode,
                  const std::string& body = std::string());



    std::string ToString() const;

private:
    static std::map<HttpStatusCode, std::string> m_StatusTable;


    HttpStatusCode m_StatusCode;

    std::string m_Body;

};

#endif // RESPONCE_H
