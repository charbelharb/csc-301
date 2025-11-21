#pragma once
#include "ICallLogRepository.h"

class CallLogRepository final : public ICallLogRepository {
    std::vector<Dtos::CallLogDto> getAllCallLogs() override;
    ~CallLogRepository() override = default;
};