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

void CallLogService::init() {
    load_call_logs();
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
    this->wait_user_input();
}

vector<unique_ptr<Models::Call> > CallLogService::map_from_repository(const vector<Dtos::CallLogDto> &records) {
    vector<unique_ptr<Models::Call> > calls;
    // unique_ptr instead of vector<Models::Call*> oldPtr;
    for (const auto &call: records) {
        // If there is a zone -> It's a local call
        if (call.getZone().has_value()) {
            auto iteration_local_call = make_unique<Models::LocalCall>(
                call.getId(), call.getReceiver(), call.getCaller(), call.getDuration(),
                call.getZone().value());
            calls.push_back(std::move(iteration_local_call));
        }
        // If there is a country -> It's an international call
        else if (call.getCountryCode().has_value()) {
            auto iteration_international_call = make_unique<Models::InternationalCall>(
                call.getId(), call.getReceiver(), call.getCaller(), call.getDuration(),
                call.getCountryCode().value());
            calls.push_back(std::move(iteration_international_call));
        }
        // If both are null -> Skip - Corrupted Data
    }
    return calls;
}

void CallLogService::printCallLogs() {
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


    for (const auto &_call: this->_calls) {
        std::cout << "| " << std::left << std::setw(Models::Call::getIdWidth() - 2) << std::to_string(_call->getId())
                << "| " << std::left << std::setw(Models::Call::getCallerWidth() - 2) << _call->getCaller()
                << "| " << std::left << std::setw(Models::Call::getReceiverWidth() - 2) << _call->getReceiver()
                << "| " << std::left << std::setw(Models::Call::getDurationWidth() - 2) << std::to_string(
                    _call->getDuration())
                << "| " << std::left << std::setw(Models::Call::getCustomColumnWidth() - 2) << _call->getType()
                << "|" << std::endl;
    }

    // Footer
    std::cout << std::setfill('-') << std::setw(Models::Call::getTotaWidth()) << "" << std::endl;
    this->wait_user_input();
}

void CallLogService::wait_user_input() {
    char user_selection = '1';
    constexpr char quit = 'q';
    while (user_selection != quit) {
        // Difference between const and constexpr:
        // const can be evaluated at compile-time or runtime.
        // while constexpr, only at compile-time
        // It is used for final and fixed value
        constexpr char print = '1';
        constexpr char average_duration = '2';
        constexpr char total_duration = '3';
        constexpr char longest_call = '4';
        constexpr char total_coast = '5';
        constexpr char new_record = '6';
        constexpr char delete_record = '7';
        constexpr char reload = 'r';
        cout << "Enter command:" << endl;
        cout << "Enter "
                "" << print << " to display all logs" << endl;
        cout << "Enter " << average_duration << " to display average duration" << endl;
        cout << "Enter " << total_duration << " to display total duration" << endl;
        cout << "Enter " << longest_call << " to display longest call" << endl;
        cout << "Enter " << total_coast << " to display total cost" << endl;
        cout << "Enter " << new_record << " to insert a new record" << endl;
        cout << "Enter " << delete_record << " to delete a record" << endl;
        cout << "Enter r to reload all logs" << endl;
        cout << "Enter q to quit" << endl;
        cin >> user_selection;
        // We're re-calling the same method (recursion)
        // so the program won't exist. i.e. we give the
        // end-user the possibility to do multiple operations
        // until he press `q` when the program exits
        switch (user_selection) {
            case print:
                printCallLogs();
                wait_user_input();
            case average_duration:
                this->average_duration();
                wait_user_input();
            case total_duration:
                this->total_duration();
                wait_user_input();
            case reload:
                this->load_call_logs();
                wait_user_input();
            case longest_call:
                this->longest_call();
                wait_user_input();
            case total_coast:
                this->total_cost();
                wait_user_input();
            case new_record:
                this->new_record();
                wait_user_input();
            case delete_record:
                this->delete_record();
                wait_user_input();
            case quit:
                std::cout << R"(
                | |
                | |__  _   _  ___
                | '_ \| | | |/ _ \
                | |_) | |_| |  __/
                |_.__/ \__, |\___|
                        __/ |
                       |___/
                )" << std::endl;
                exit(EXIT_SUCCESS);
            default:
                cout << "Invalid command." << endl;
                wait_user_input();
        }
    }
}

// Silent bool flag is used for code re-use
// Note: We could've also added call retrieval in a separate method
void CallLogService::load_call_logs(const bool silent) {
    if (!silent) {
        cout << "Fetching call Logs..." << endl;
    }
    const auto callLogs = this->_repository->getAllCallLogs();
    if (!silent) {
        cout << "Logs Fetched -- Mapping to business models" << endl;
    }
    this->_calls = map_from_repository(callLogs);
    if (!silent) {
        cout << "Mapping Done" << endl;
    }
}

void CallLogService::average_duration() {
    cout << "Average duration is: " << to_string(this->get_total_duration() / this->_calls.size()) << endl;
    this->wait_user_input();
}

void CallLogService::total_duration() const {
    int total_duration = 0;
    for (const auto &_call: this->_calls) {
        total_duration += _call->getDuration();
    }
    cout << "Total duration is: " << total_duration << endl;
}

void CallLogService::longest_call() const {
    int longest_call = 0;
    size_t longest_call_id = 0;
    for (size_t i = 0; i < this->_calls.size(); ++i) {
        if (const auto &_call = _calls[i]; _call->getDuration() > longest_call) {
            longest_call = _call->getDuration();
            longest_call_id = i;
        }
    }
    cout << "Longest call is ID: " << _calls[longest_call_id].get()->getId() << endl;
    cout << "Caller: " << _calls[longest_call_id].get()->getCaller() << endl;
    cout << "Receiver: " << _calls[longest_call_id].get()->getReceiver() << endl;
    cout << "Duration: " << _calls[longest_call_id].get()->getDuration() << endl;
    cout << "Type: " << _calls[longest_call_id].get()->getType() << endl;
}

void CallLogService::total_cost() const {
    double total_cost = 0;
    for (const auto &_call: this->_calls) {
        total_cost += _call->Cost();
    }
    cout << "Total cost is: " << std::setprecision(3) << total_cost << " $" << endl;
}

int CallLogService::get_total_duration() const {
    int total_duration = 0;
    for (const auto &_call: this->_calls) {
        total_duration += _call->getDuration();
    }
    return total_duration;
}

void CallLogService::new_record() {
    cout << "Press 'l' for local call" << endl;
    cout << "Press 'i' for international call" << endl;
    cout << "Press 'q' to go back to menu" << endl;
    char user_selection;
    cin >> user_selection;
    switch (user_selection) {
        case 'l':
            new_local_call();
            ask_for_display();
            break;
        case 'i':
            new_internation_call();
            ask_for_display();
            break;
        case 'q':
            break;
        default:
            cout << "Invalid user selection." << endl;
            new_record();
    }
    wait_user_input();
}

void CallLogService::new_local_call() {
    const auto shared_info = new_shared_call_info();
    cout << "Enter Zone" << endl;
    int zone;
    cin >> zone;
    const Dtos::CallLogDto record(0, shared_info.receiver, shared_info.caller, shared_info.duration,
                                  zone, nullopt);
    if (const int result = _repository->insertNewCallLog(record); result > 0) {
        load_call_logs(true);
        cout << "Record insertest successfully";
        ask_for_display();
    }
    else {
        cout << "Failed to insert record";
    }
}

void CallLogService::new_internation_call() {
    const auto shared_info = new_shared_call_info();
    cout << "Enter Country Code" << endl;
    string country_code;
    cin >> country_code;
    const Dtos::CallLogDto record(0, shared_info.receiver, shared_info.caller, shared_info.duration,
                                  nullopt, country_code);

    if (const int result = _repository->insertNewCallLog(record); result > 0) {
        load_call_logs(true);
        cout << "Record inserted successfully \n";
        ask_for_display();
    }
    else {
        cout << "Failed to insert record \n";
    }
}

CallLogService::shared_call_info CallLogService::new_shared_call_info() {
    shared_call_info data;
    cout << "Enter Caller" << endl;
    getline(cin >> std::ws, data.caller);
    cout << "Enter Receiver" << endl;
    getline(cin >> std::ws, data.receiver);
    cout << "Enter Duration" << endl;
    cin >> data.duration;
    return data;
}

void CallLogService::delete_record()  {
    cout << "Enter record ID to delete" << endl;
    int record_id;
    cin >> record_id;
    if (const int result = _repository->deleteCallLog(record_id); result > 0) {
        cout << "Record deleted successfully \n";
        load_call_logs(true);
        ask_for_display();
    }
    else {
        cout << "Failed to delete record \n";
    }
    cout << endl;
}

void CallLogService::ask_for_display() {
    cout << "Do you want to display new data y/n ?" << endl;
    char user_selection;
    cin >> user_selection;
    if (user_selection == 'y') {
        printCallLogs();
    }
}
