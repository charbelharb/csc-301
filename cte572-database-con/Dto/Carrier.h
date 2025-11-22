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
        string _addressId;

    public:
        Carrier(string id,
            string code,
            string name,
            string dotNumber,
            string mcnNumber,
            string addressId) {
            this->_id = std::move(id);
            this->_code = std::move(code);
            this->_name = std::move(name);
            this->_dotNumber = std::move(dotNumber);
            this->_mcnNumber = std::move(mcnNumber);
            this->_addressId = std::move(addressId);
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
        string GetAddressId() {
            return this->_addressId;
        }
    };
}