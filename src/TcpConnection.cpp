#include <sstream>

#include "TcpConnection.h"
#include "HttpResponse.h"

#include <fstream>
#include <sstream>

TcpConnection::Pointer TcpConnection::create(boost::asio::io_context &ioContext)
{
    return Pointer(new TcpConnection(ioContext));
}

boost::asio::ip::tcp::socket &TcpConnection::socket()
{
    return m_Socket;
}


void TcpConnection::start()
{
    m_Socket.async_read_some(boost::asio::buffer(m_Buffer, m_BufferSize),
                             boost::bind(&TcpConnection::handleRead, shared_from_this(),
                                         std::placeholders::_1,
                                         std::placeholders::_2));
}

TcpConnection::TcpConnection(boost::asio::io_context &ioContext) :
    m_Socket(ioContext), m_BufferSize(1024), m_Buffer(m_BufferSize, '\0')
{}

void TcpConnection::handleRead(boost::system::error_code code,
                               size_t bytesTransfered)
{

    std::ifstream fin ("res/index.html");

    if (fin.is_open())
    {
        std::stringstream ss;
        ss << fin.rdbuf();

        HttpResponse response(HttpResponse::Ok, ss.str());
        m_Response = response.ToString();
    } else
    {
        HttpResponse response(HttpResponse::NotFound);
        m_Response = response.ToString();
    }



    m_Socket.async_write_some(boost::asio::buffer(m_Response), boost::bind(&TcpConnection::handleWrite,
                                                                           shared_from_this()));

}

void TcpConnection::handleWrite()
{

}
