#pragma once
#include "ICallLogRepository.h"

class CallLogRepository final : public ICallLogRepository {
public:
    std::vector<Dtos::CallLogDto> getAllCallLogs() override;
    Dtos::CallLogDto getCallLogById(int) override;
    int insertNewCallLog(Dtos::CallLogDto) override;
    int deleteCallLog(int) override;
    ~CallLogRepository() override = default;
};