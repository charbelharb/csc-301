//
// Created by charbel on 11/20/25.
//

#include "Repository.h"

#include <iostream>

unique_ptr<pqxx::connection> Repository::get_db_connection() {
    if (this->_connection->is_open()) {
        return std::move(this->_connection);
    }

    return std::move(this->_connection);
}

void Repository::connect_db() {
    this->_connection = make_unique<pqxx::connection>(this->_connectionString);
}

std::vector<Dto::Carrier> Repository::GetAllCarriers() {
    vector<Dto::Carrier> result = {};
    try {
        const auto connection = this->get_db_connection();
        pqxx::work transaction(*connection);
        pqxx::result r = transaction.exec(
            R"(SELECT "Id", "Code", "Name",
                                "AddressId", "dotnumber", "mcnumber"
                                    FROM demo0."Carrier")");
        for (const pqxx::row &row: r) {
            auto id = row[0].as<string>();
            auto code = row[1].as<string>();
            auto name = row[2].as<string>();
            auto addressId = row[3].as<string>();
            auto dotNumber = row[4].as<string>();
            auto mcNumber = row[5].as<string>();
            auto record = Dto::Carrier(id, code, name, dotNumber,
                                       mcNumber, addressId);
            result.push_back(std::move(record));
        }
    } catch (const pqxx::sql_error &e) {
        std::cerr << "SQL error: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return result;
}
