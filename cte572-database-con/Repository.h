//
// Created by charbel on 11/20/25.
//

#pragma once

#include <pqxx/pqxx>
#include <utility>

#include "Dto/Carrier.h"

class Repository {
    string _connectionString;
    unique_ptr<pqxx::connection> _connection;
    unique_ptr<pqxx::connection> get_db_connection();
    void connect_db();
public:
    explicit Repository(string connectionString) {
        this->_connectionString = std::move(connectionString);
        this->connect_db();
    }
    std::vector<Dto::Carrier> GetAllCarriers();
};