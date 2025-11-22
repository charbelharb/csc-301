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
    std::cout << R"(
    *************************************************************
    *                                                           *
    *                    WELCOME TO CALL LOG MANAGER            *
    *                                                           *
    *                   _.===========================._         *
    *                .'`  .-  - __- - - -- --__--- -.  `'.      *
    *            __ / ,'`     _|--|_________|--|_     `'. \     *
    *          /'--| ;    _.'\ |  '         '  | /'._    ; |    *
    *         //   | |_.-' .-'.'    -  -- -    '.'-. '-._| |    *
    *        (\)   \"` _.-` /                     \ `-._ `"/    *
    *        (\)    `-`    /      .---------.      \    `-`     *
    *        (\)           |      ||1||2||3||      |            *
    *       (\)            |      ||4||5||6||      |            *
    *      (\)             |      ||7||8||9||      |            *
    *     (\)           ___|      ||*||0||#||      |            *
    *     (\)          /.--|      '---------'      |            *
    *      (\)        (\)  |\_  _  __   _   __  __/|            *
    *     (\)        (\)   |                       |            *
    *    (\)_._._.__(\)    |                       |            *
    *     (\\\\ccc\\\)      '.___________________.'             *
    *      '-'-'-'--'                                           *
    *                                                           *
    *************************************************************
)" << std::endl;
    cout << "Fetching call Logs..." << endl;
    const auto callLogs = this->_repository->getAllCallLogs();
    cout << "Logs Fetched -- Mapping to business models" << endl;
    this->_calls = map_from_repository(callLogs);
    cout << "Mapping Done" << endl;
    this->wait_user_input();
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
    // Header
    std::cout << std::setfill('-') << std::setw(Models::Call::getTotaWidth()) << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "| " << std::left << std::setw(Models::Call::getIdWidth() - 2) << "ID"
              << "| " << std::left << std::setw(Models::Call::getCallerWidth() - 2) << "Caller"
              << "| " << std::left << std::setw(Models::Call::getReceiverWidth() - 2) << "Receiver"
              << "| " << std::left << std::setw(Models::Call::getDurationWidth() - 2) << "Duration"
              << "| " << std::left << std::setw(Models::Call::getCustomColumnWidth() - 2) << "Type"
              << "|" << std::endl;
    std::cout << std::setfill('-') << std::setw(Models::Call::getTotaWidth()) << "" << std::endl;
    std::cout << std::setfill(' ');
    for (const auto & _call : this->_calls) {
        std::cout << "| " << std::left << std::setw(Models::Call::getIdWidth() - 2) << std::to_string(_call->getId())
                     << "| " << std::left << std::setw(Models::Call::getCallerWidth() - 2) << _call->getCaller()
                     << "| " << std::left << std::setw(Models::Call::getReceiverWidth() - 2) << _call->getReceiver()
                     << "| " << std::left << std::setw(Models::Call::getDurationWidth() - 2) << std::to_string(_call->getDuration())
                     << "| " << std::left << std::setw(Models::Call::getCustomColumnWidth() - 2) << _call->getType()
                     << "|" << std::endl;
    }
    std::cout << std::setfill('-') << std::setw(Models::Call::getTotaWidth()) << "" << std::endl;
    this->wait_user_input();
}

void CallLogService::wait_user_input() const {
    char user_selection = '1';
    constexpr char quit = 'q';
    while (user_selection != quit) {
        cout << "Enter command:" << endl;
        cout << "Enter 1 to display all logs" << endl;
        cin >> user_selection;
        switch (user_selection) {
            case '1':
                printCallLogs();
            case 'q':
                exit(EXIT_SUCCESS);
            default:
                cout << "Invalid command." << endl;
                wait_user_input();
        }
    }
}


