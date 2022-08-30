#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <boost/asio.hpp>
#include <TcpConnection.h>

class TcpServer
{
public:
    TcpServer(boost::asio::io_context& ioContext);

private:
    boost::asio::io_context& m_IoContext;
    boost::asio::ip::tcp::acceptor m_Acceptor;

    void startAccept();

    void handleAccept(TcpConnection::Pointer& connection,
                      boost::system::error_code error);
};

#endif // TCPSERVER_H
