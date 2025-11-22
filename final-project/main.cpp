#include <memory>
#include "Repositories/CallLogRepository.h"
#include "Services/CallLogService.h"



[[noreturn]] int main() {
    const auto repository = std::make_unique<CallLogRepository>();
    const auto pService = std::make_unique<CallLogService>(repository.get());
    while (true) {
        pService->Run();
    }
}
