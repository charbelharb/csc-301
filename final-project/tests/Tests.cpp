//
//

#include "Tests.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../Services/CallLogService.h"
#include "MockICallLogRepository.h"

TEST(CallLogService, load_call_logs_should_call_repository) {
    MockICallLogRepository mockRepository;
    CallLogService sut(&mockRepository);

    // Inject input "q"
    std::streambuf* orig = std::cin.rdbuf();
    const std::istringstream input("q");
    std::cin.rdbuf(input.rdbuf());
    sut.printCallLogs();
    std::cin.rdbuf(orig);
    EXPECT_CALL(mockRepository, getAllCallLogs());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}