add_executable(Server main.cpp TcpServer.cpp TcpServer.h)
target_link_libraries(Server servlib)
