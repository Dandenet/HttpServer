set(HEADER_LIST ${Server_SOURCE_DIR}/include/HttpRequest.h
${Server_SOURCE_DIR}/include/HttpRequestParser.h
${Server_SOURCE_DIR}/include/TcpConnection.h
${Server_SOURCE_DIR}/include/HttpResponse.h)

add_library(servlib
    HttpRequest.cpp
    HttpRequestParser.cpp
    TcpConnection.cpp
    HttpResponse.cpp
    ${HEADER_LIST})


target_include_directories(servlib PUBLIC ../include)

include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(servlib PUBLIC ${Boost_LIBRARIES})
