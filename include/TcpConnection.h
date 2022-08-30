#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

#include <memory>
#include <string>

class TcpConnection : public std::enable_shared_from_this<TcpConnection>
{
public:
    using Pointer = std::shared_ptr<TcpConnection>;


    static Pointer create(boost::asio::io_context& ioContext);

    boost::asio::ip::tcp::socket& socket();

    void start();

private:
    TcpConnection(boost::asio::io_context& ioContext);

    void handleRead(boost::system::error_code code,
                    size_t bytesTransfered);

    void handleWrite();



    boost::asio::ip::tcp::socket    m_Socket;

    size_t                          m_BufferSize;
    std::string                     m_Buffer;
    std::string                     m_Response;
};

#endif // TCPCONNECTION_H
