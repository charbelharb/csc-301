//
// Created by charbel on 11/21/25.
//

#pragma once

#include <string>
#include <utility>

using namespace std;

namespace Dto {
    class Carrier final {
        string _id;
        string _code;
        string _name;
        string _dotNumber;
        string _mcnNumber;
        string _address;

    public:
        Carrier(string id,
            string code,
            string name,
            string dotNumber,
            string mcnNumber,
            string address) {
            this->_id = std::move(id);
            this->_code = std::move(code);
            this->_name = std::move(name);
            this->_dotNumber = std::move(dotNumber);
            this->_mcnNumber = std::move(mcnNumber);
            this->_address = std::move(address);
        }
        string GetId() {
            return this->_id;
        }
        string GetCode() {
            return this->_code;
        }
        string GetName() {
            return this->_name;
        }
        string GetDotNumber() {
            return this->_dotNumber;
        }
        string GetMcnNumber() {
            return this->_mcnNumber;
        }
        string GetAddress() {
            return this->_address;
        }
    };
}