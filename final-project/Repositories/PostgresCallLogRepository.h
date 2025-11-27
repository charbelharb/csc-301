//
// Created by charbel on 11/27/25.
//

#pragma once
#include <pqxx/pqxx>
#include "ICallLogRepository.h"

class PostgresCallLogRepository final : public ICallLogRepository {
    string _connectionString;
    unique_ptr<pqxx::connection> _connection;
    unique_ptr<pqxx::connection> get_db_connection();
    void connect_db();
    public:
    explicit PostgresCallLogRepository(string connectionString) {
        this->_connectionString = std::move(connectionString);
        this->connect_db();
    }
        std::vector<Dtos::CallLogDto> getAllCallLogs() override;
        Dtos::CallLogDto getCallLogById(int) override;
        int insertNewCallLog(Dtos::CallLogDto) override;
        int deleteCallLog(int) override;
        ~PostgresCallLogRepository() override = default;
};