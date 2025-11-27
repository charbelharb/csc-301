#pragma once
#include "ICallLogRepository.h"

class TemporaryCallLogRepository final : public ICallLogRepository {
public:
    std::vector<Dtos::CallLogDto> getAllCallLogs() override;
    Dtos::CallLogDto getCallLogById(int) override;
    int insertNewCallLog(Dtos::CallLogDto) override;
    int deleteCallLog(int) override;
    ~TemporaryCallLogRepository() override = default;
};