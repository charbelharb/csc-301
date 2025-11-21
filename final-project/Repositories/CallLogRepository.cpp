#include "CallLogRepository.h"

std::vector<Dtos::CallLogDto> CallLogRepository::getAllCallLogs() {
    vector<Dtos::CallLogDto> callLogs;

    // Mock LocalCall
    callLogs.emplace_back(
        1,"P1","P2",1,1,nullopt);

    // Mock International Call
    callLogs.emplace_back(
        2,"P1","P3",2,nullopt,"+1");
    return callLogs;
}
