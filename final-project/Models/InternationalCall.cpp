#include "InternationalCall.h"

namespace Models {
    double InternationalCall::Cost() {
        return -1;
    }

    string InternationalCall::getType() {
        return "International Call - Country Code: " + this->_countryCode;
    }
}