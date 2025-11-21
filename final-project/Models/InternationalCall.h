#pragma once
#include "Call.h"

namespace Models  {
    class InternationalCall final : Call {
        string _countryCode;
    public:
        InternationalCall(const int id, const string &receiver,
        const string &caller, const int duration, const string &countryCode):Call(id, receiver,
        caller, duration) {
            this->_countryCode = countryCode;
        }
        double Cost() override;
    };
}