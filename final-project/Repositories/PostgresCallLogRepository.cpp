//
// Created by charbel on 11/27/25.
//

#include "PostgresCallLogRepository.h"

#include <iostream>

unique_ptr<pqxx::connection> PostgresCallLogRepository::get_db_connection() {
    if (this->_connection == nullptr) {
        connect_db();
    }
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
            // 0,1,2,3... are the indexes of the line
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

int PostgresCallLogRepository::insertNewCallLog(const Dtos::CallLogDto record) {
    int result = 0;
    try {
        const auto connection = this->get_db_connection();
        pqxx::work transaction(*connection);
        pqxx::params params;
        params.append(record.getReceiver());
        params.append(record.getCaller());
        params.append(record.getDuration());
        params.append(record.getZone());
        params.append(record.getCountryCode());
        pqxx::result r = transaction.exec(
         R"(INSERT INTO csc301.call
         (receiver, caller, duration, zone, country_code)
         VALUES ($1, $2, $3, $4, $5)
         RETURNING Id;)", params);
        if (r.empty()) {
            result = -1;
        }else {
            pqxx::row row = r[0];
            result = row[0].as<int>();
        }
        transaction.commit();
    }
    catch (const pqxx::sql_error &e) {
        std::cerr << "SQL error: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return result;
}

int PostgresCallLogRepository::deleteCallLog(const int id) {
    int result = 0;
    try {
        const auto connection = this->get_db_connection();
        pqxx::work transaction(*connection);
        pqxx::params params;
        params.append(id);
        const pqxx::result r = transaction.exec(
         R"(DELETE FROM csc301.call
         WHERE Id = $1
         RETURNING Id;)", params);
        if (r.empty()) {
            result = -1;
        }else {
            const pqxx::row row = r[0];
            result = row[0].as<int>();
        }
        transaction.commit();
    }
    catch (const pqxx::sql_error &e) {
        std::cerr << "SQL error: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return result;
}