#pragma once
#include "ICallLogRepository.h"

class CallLogRepository final : public ICallLogRepository {
public:
    std::vector<Dtos::CallLogDto> getAllCallLogs() override;
    ~CallLogRepository() override = default;
};