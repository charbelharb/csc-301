#pragma once
#include "Call.h"

namespace Models {
    class LocalCall final : Call {
        int _zone;
    public:
        LocalCall(const int id, const string &receiver,
        const string &caller, const int duration, const int zone):Call(id, receiver,
        caller, duration) {
            this->_zone = zone;
        }
        double Cost() override;
    };
}