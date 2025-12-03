#pragma once

#include <vector>
#include "../Dtos/CallLogDto.h"

// imitate interface: in C++, act like abstract class
class ICallLogRepository {
    public:
        virtual std::vector<Dtos::CallLogDto> getAllCallLogs() = 0;
        virtual int insertNewCallLog(Dtos::CallLogDto) = 0;
        virtual int deleteCallLog(int) = 0;
        virtual ~ICallLogRepository() = default;
};
