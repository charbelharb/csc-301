//
//

#pragma once
#include "../Repositories/ICallLogRepository.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
class MockICallLogRepository final : public ICallLogRepository{
    public:
    MOCK_METHOD(std::vector<Dtos::CallLogDto>, getAllCallLogs, (), (override));
    MOCK_METHOD(int, insertNewCallLog, (Dtos::CallLogDto), (override));
    MOCK_METHOD(int, deleteCallLog, (int), (override));
};