cmake_minimum_required(VERSION 4.0)
project(final_project)

set(CMAKE_CXX_STANDARD 20)
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)
add_executable(final_project main.cpp
        Repositories/ICallLogRepository.h
        Repositories/TemporaryCallLogRepository.cpp
        Repositories/TemporaryCallLogRepository.h
        Services/CallLogService.cpp
        Services/CallLogService.h
        Dtos/CallLogDto.h
        Models/Call.h
        Models/LocalCall.cpp
        Models/LocalCall.h
        Models/InternationalCall.cpp
        Models/InternationalCall.h
        Repositories/PostgresCallLogRepository.cpp
        Repositories/PostgresCallLogRepository.h)

target_include_directories(final_project
        PRIVATE ${PQXX_INCLUDE_DIRS}
)

target_link_libraries(final_project
        PRIVATE ${PQXX_LIBRARIES}
)
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)
add_executable(tests tests/Tests.cpp
        tests/MockICallLogRepository.cpp
        tests/MockICallLogRepository.h
        Repositories/ICallLogRepository.h
        Repositories/TemporaryCallLogRepository.cpp
        Repositories/TemporaryCallLogRepository.h
        Services/CallLogService.cpp
        Services/CallLogService.h
        Dtos/CallLogDto.h
        Models/Call.h
        Models/LocalCall.cpp
        Models/LocalCall.h
        Models/InternationalCall.cpp
        Models/InternationalCall.h)
target_link_libraries(tests
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
        GTest::gmock_main
)
enable_testing()
