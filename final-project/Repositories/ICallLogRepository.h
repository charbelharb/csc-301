#pragma once

#include <vector>

#include "../Dtos/CallLogDto.h"


class ICallLogRepository {
    public:
        virtual std::vector<Dtos::CallLogDto> getAllCallLogs() = 0;
        virtual ~ICallLogRepository() = default;
};
