cmake_minimum_required(VERSION 4.0)
project(final_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(final_project main.cpp
        Repositories/ICallLogRepository.h
        Repositories/CallLogRepository.cpp
        Repositories/CallLogRepository.h
        Services/CallLogService.cpp
        Services/CallLogService.h
        Dtos/CallLogDto.h
        Models/Call.h
        Models/LocalCall.cpp
        Models/LocalCall.h
        Models/InternationalCall.cpp
        Models/InternationalCall.h)
