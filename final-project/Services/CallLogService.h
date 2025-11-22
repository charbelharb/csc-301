#pragma once
#include "../Repositories/ICallLogRepository.h"

class CallLogService final {
    ICallLogRepository* _repository;

    public:
        void Run();

        // This is a pattern used to make code unit-testable
        // We inject a pure abstract base class and then we mock it
        explicit CallLogService(ICallLogRepository* repository) {
            _repository = repository;
        }
};
