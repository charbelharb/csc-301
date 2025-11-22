#pragma once
#include <memory>

#include "../Repositories/ICallLogRepository.h"
#include "../Models/Call.h"

namespace Models {
    class Call;
}

class CallLogService final {
    ICallLogRepository* _repository;
    vector<unique_ptr<Models::Call>> _calls;
    void init();
    static vector<unique_ptr<Models::Call>> map_from_repository(const vector<Dtos::CallLogDto>& records);
    void printCallLogs();
    void wait_user_input();
    void load_call_logs();
    void total_duration() const;
    void average_duration();
    void longest_call() const;
    void total_cost() const;
    int get_total_duration() const;
public:
        void Run();
        // This is a pattern used to make code unit-testable
        // We inject a pure abstract base class and then we mock it
        explicit CallLogService(ICallLogRepository* repository) {
            _repository = repository;
        }
};
