#include "InternationalCall.h"

namespace Models {
    double InternationalCall::Cost() {
        return -1;
    }
    string InternationalCall::to_string() {
        return Call::to_string() + "Type: International -- Country Code: " + this->_countryCode;
    }
}