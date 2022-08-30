cmake_minimum_required(VERSION 3.5)

project(Server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(Boost_ADDITIONAL_VERSIONS "1.79.0" "1.79")



find_package(Boost REQUIRED)


add_subdirectory(src/)
add_subdirectory(test/)
add_subdirectory(app/)
