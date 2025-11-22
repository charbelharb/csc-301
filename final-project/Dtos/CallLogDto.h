#pragma once
#include <optional>
#include <string>
using namespace std;

namespace Dtos {
    class CallLogDto final {
        /* Dtos should be immutable
         Private fields are used to disallow external modification
         */
        int _id;
        string _caller;
        string _receiver;
        int _duration;
        optional<int> _zone;
        optional<string> _countryCode;
    public:
        CallLogDto(const int id,
            const string& receiver,
            const string& caller,
            const int duration,
            const optional<int> zone,
            const optional<string> &countryCode)
        {
            this->_id = id;
            this->_receiver = receiver;
            this->_duration = duration;
            this->_zone = zone;
            this->_countryCode = countryCode;
            this->_zone = zone;
            this->_caller = caller;
        }
        // [[nodiscard]] is an attribute introduced in C++17
        // Its function is to warn programmer if the returning value is being discarded
        // e.g. GetId() on its own shouldn't be allowed, but it accept int id = GetId();
        [[nodiscard]] int getId() const {
            return _id;
        }

        [[nodiscard]] string getCaller() const {
            return _caller;
        }

        [[nodiscard]] string getReceiver() const {
            return _receiver;
        }

        [[nodiscard]] int getDuration() const {
            return _duration;
        }

        [[nodiscard]] optional<int> getZone() const {
            return _zone;
        }

        [[nodiscard]] optional<string> getCountryCode() const {
            return _countryCode;
        }
    };
}