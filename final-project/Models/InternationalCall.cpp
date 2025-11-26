#include "InternationalCall.h"

namespace Models {
    double InternationalCall::Cost() {
        return this->getDuration() * 2.1;
    }

    string InternationalCall::getType() {
        return "International Call - Country Code: " + this->_countryCode;
    }
}
