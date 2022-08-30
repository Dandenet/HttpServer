#define BOOST_TEST_MODULE Response module name
#include <boost/test/unit_test.hpp>
#include <HttpResponse.h>

BOOST_AUTO_TEST_SUITE(HttpResponse_Test)


BOOST_AUTO_TEST_CASE(HttpResponse_Test_Simple)
{
    BOOST_TEST (HttpResponse(HttpResponse::Ok).ToString()
                == std::string("HTTP/1.1 200 OK\r\n\r\n"));

    BOOST_TEST (HttpResponse(HttpResponse::NotFound).ToString()
                == std::string("HTTP/1.1 404 Not Found\r\n\r\n"));



    BOOST_TEST (HttpResponse(HttpResponse::NotImplemented).ToString()
                == std::string("HTTP/1.1 501 Not Implemented\r\n\r\n"));
}

BOOST_AUTO_TEST_CASE(HttpResponse_Test_WithBody)
{
    BOOST_TEST (HttpResponse(HttpResponse::Ok, "<title>Test</title>\n").ToString()
                == std::string("HTTP/1.1 200 OK\r\n"
                               "\r\n"
                               "<title>Test</title>\n"));
}


BOOST_AUTO_TEST_SUITE_END()
