cmake_minimum_required(VERSION 4.0)
project(cte572_database_con)

set(CMAKE_CXX_STANDARD 20)
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

add_executable(cte572_database_con main.cpp
        Repository.cpp
        Repository.h
        Dto/Carrier.h
        PrintOutUtility.cpp
        PrintOutUtility.h)

target_include_directories(cte572_database_con
        PRIVATE ${PQXX_INCLUDE_DIRS}
)

target_link_libraries(cte572_database_con
        PRIVATE ${PQXX_LIBRARIES}
)