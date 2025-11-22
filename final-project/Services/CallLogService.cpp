#include "CallLogService.h"
#include <iostream>
#include <cstdlib>
#include <memory>

#include "../Models/InternationalCall.h"
#include "../Models/LocalCall.h"

using namespace std;

void CallLogService::Run() {
    this->init();
    exit(EXIT_SUCCESS);
}

void CallLogService::init()  {
    cout << "Press Enter to load call logs data:" << endl;
    std::cin.get();
    cout << "Fetching call Logs...";
    const auto callLogs = this->_repository->getAllCallLogs();
    cout << "Logs Fetched -- Mapping to business models" << endl;
    this->_calls = map_from_repository(callLogs);
    cout << "Mapping Done" << endl;
    this->printCallLogs();
}

vector<unique_ptr<Models::Call>> CallLogService::map_from_repository(const vector<Dtos::CallLogDto>& records) {
    vector<unique_ptr<Models::Call>> calls;
    for (const auto& call : records) {
        // If there is a zone -> It's a local call
        if (call.getZone().has_value()) {
            auto interation_local_call = make_unique<Models::LocalCall>(
            call.getId(), call.getReceiver(), call.getCaller(), call.getDuration(),
            call.getZone().value());
            calls.push_back(std::move(interation_local_call));
        }
        // If there is a country -> It's an international call
        else if (call.getCountryCode().has_value()) {
            auto interation_international_call = make_unique<Models::InternationalCall>(
            call.getId(), call.getReceiver(), call.getCaller(), call.getDuration(),
        call.getCountryCode().value());
            calls.push_back(std::move(interation_international_call));
        }
        // If both are null -> Skip - Corrupted Data
    }
    return calls;
}

void CallLogService::printCallLogs() const {
    cout << "Printing call Logs..." << endl;
    for (const auto & _call : this->_calls) {
        cout << _call->to_string() << endl;
    }
}

