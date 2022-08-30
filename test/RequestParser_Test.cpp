#define BOOST_TEST_MODULE Request module name
#include <boost/test/unit_test.hpp>
#include <HttpRequestParser.h>
#include <HttpRequest.h>


BOOST_AUTO_TEST_SUITE(Server_Test)


BOOST_AUTO_TEST_CASE(RequstParser_Test)
{

    std::string requestBuffer("GET / HTTP/1.1\n\r");

    HttpRequest request = {1, 1, "/", "GET"};
    HttpRequest result = HttpRequestParser::Parse(requestBuffer);

    bool res = request == result;

    BOOST_TEST( res );


    requestBuffer = std::string("POST /info HTTP/1.1\n\r");

    request = {1, 1, "/info", "POST"};
    result = HttpRequestParser::Parse(requestBuffer);

    res = request == result;
    BOOST_TEST(res);

}


BOOST_AUTO_TEST_SUITE_END()
