//
//

#include "LocalCall.h"

namespace Models {
    double LocalCall::Cost() {
        return this->getDuration() * 0.75;
    }

    string LocalCall::getType() {
        return "Local Call - Zone: " + to_string(this->_zone);
    }
}
