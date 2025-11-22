//
//

#include "LocalCall.h"

namespace Models {
    double LocalCall::Cost() {
        return -1;
    }
    string LocalCall::to_string() {
        return Call::to_string() + "Type: Local -- Zone: " + std::to_string(this->_zone);
    }
}
