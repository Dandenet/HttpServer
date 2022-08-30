#include <boost/asio.hpp>

#include <exception>
#include <iostream>

#include "TcpServer.h"



int main()
{

    try {

        boost::asio::io_context ioContext;
        TcpServer server(ioContext);
        ioContext.run();

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
