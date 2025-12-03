#include <memory>

#include "Repositories/PostgresCallLogRepository.h"
// #include "Repositories/TemporaryCallLogRepository.h"
#include "Services/CallLogService.h"


// Indicate that main will not return an exit code
[[noreturn]] int main() {
    // make_unique: smart pointer
    const auto repository = std::make_unique<PostgresCallLogRepository>(
        "dbname=uls user=postgres password=123 host=127.0.0.1 port=5432");
    const auto pService = std::make_unique<CallLogService>(repository.get());
    while (true) {
        pService->Run();
    }
}
