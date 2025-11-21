#include <iostream>
#include <memory>

#include "Services/CallLogService.h"



[[noreturn]] int main() {
    const auto pService = std::make_unique<CallLogService>();
    while (true) {
        pService->Run();
    }
}
