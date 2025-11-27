#include "TemporaryCallLogRepository.h"

#include <memory>

std::vector<Dtos::CallLogDto> TemporaryCallLogRepository::getAllCallLogs() {
    vector<Dtos::CallLogDto> callLogs;

    // Mock LocalCall
    callLogs.emplace_back(
        1, "P1", "P2", 1, 1, nullopt);
    callLogs.emplace_back(
        11, "P1", "P2", 3, 1, nullopt);
    callLogs.emplace_back(
        111, "P1", "P2", 6, 1, nullopt);

    // Mock International Call
    callLogs.emplace_back(
        2, "P1", "P3", 2, nullopt, "+1");
    callLogs.emplace_back(
        22, "P1", "P5", 4, nullopt, "+1");;
    callLogs.emplace_back(
        222, "P1", "P5", 7, nullopt, "+1");;
    return callLogs;
}

int TemporaryCallLogRepository::insertNewCallLog(Dtos::CallLogDto record) {
    return 0;
}

int TemporaryCallLogRepository::deleteCallLog(int id) {
    return 0;
}
