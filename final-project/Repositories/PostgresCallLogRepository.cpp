//
// Created by charbel on 11/27/25.
//

#include "PostgresCallLogRepository.h"

#include <iostream>

unique_ptr<pqxx::connection> PostgresCallLogRepository::get_db_connection() {
    if (this->_connection->is_open()) {
        return std::move(this->_connection);
    }
    connect_db();
    return std::move(this->_connection);
}

void PostgresCallLogRepository::connect_db() {
    this->_connection = make_unique<pqxx::connection>(this->_connectionString);
}

std::vector<Dtos::CallLogDto> PostgresCallLogRepository::getAllCallLogs() {
    vector<Dtos::CallLogDto> callLogs;
    try {
        const auto connection = this->get_db_connection();
        pqxx::work transaction(*connection);
        pqxx::result r = transaction.exec(
        R"(SELECT "id",
                        "receiver",
                        "caller",
                        "duration",
                        "zone",
                        "country_code"
                FROM
                    "csc301"."call")");
        for (const pqxx::row &row: r) {
            auto id = row[0].as<int>();
            auto receiver = row[1].as<std::string>();
            auto caller = row[2].as<std::string>();
            auto duration = row[3].as<int>();
            auto zone = row[4].as<std::optional<int>>();
            auto country_code = row[5].as<std::optional<string>>();
            auto record = Dtos::CallLogDto(id,receiver,caller,duration,zone,country_code);
            callLogs.push_back(std::move(record));
        }
    }
    catch (const pqxx::sql_error &e) {
        std::cerr << "SQL error: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return callLogs;
}

Dtos::CallLogDto PostgresCallLogRepository::getCallLogById(int id) {
    auto record = Dtos::CallLogDto(1, "P1", "P2", 1, 1, nullopt);
    return record;
}

int PostgresCallLogRepository::insertNewCallLog(Dtos::CallLogDto record) {
    return 0;
}

int PostgresCallLogRepository::deleteCallLog(int id) {
    return 0;
}