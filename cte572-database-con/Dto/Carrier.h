//
// Created by charbel on 11/21/25.
//

#ifndef CTE572_DATABASE_CON_CARRIER_H
#define CTE572_DATABASE_CON_CARRIER_H

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
    };
}

#endif //CTE572_DATABASE_CON_CARRIER_H