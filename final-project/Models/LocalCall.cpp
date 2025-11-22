//
//

#include "LocalCall.h"

namespace Models {
    double LocalCall::Cost() {
        return -1;
    }

    string LocalCall::getType() {
        return "Local Call - Zone: " + to_string(this->_zone);
    }
}
