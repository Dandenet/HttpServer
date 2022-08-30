#include "TcpServer.h"

TcpServer::TcpServer(boost::asio::io_context& ioContext) :
    m_IoContext(ioContext),
    m_Acceptor(m_IoContext, boost::asio::ip::tcp::endpoint(
                   boost::asio::ip::tcp::v4(), 8080))
{
    startAccept();
}

void TcpServer::startAccept()
{
    TcpConnection::Pointer connection = TcpConnection::create(m_IoContext);

    m_Acceptor.async_accept(connection->socket(),
                      boost::bind(&TcpServer::handleAccept, this,
                                  connection, boost::asio::placeholders::error));
}

void TcpServer::handleAccept(TcpConnection::Pointer &connection,
                             boost::system::error_code error)
{
    if (!error)
    {
        connection->start();
    }

    startAccept();
}



