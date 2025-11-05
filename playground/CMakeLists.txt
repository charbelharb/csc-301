cmake_minimum_required(VERSION 4.0)
project(playground)

set(CMAKE_CXX_STANDARD 20)
find_package(CURL REQUIRED)
add_executable(playground main.cpp
        HttpClient.cpp
        HttpClient.h)



target_link_libraries(playground PRIVATE CURL::libcurl)


