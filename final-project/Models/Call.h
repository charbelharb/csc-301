#pragma once
#include <string>
using namespace std;

namespace Models {
    class Call {
        int _id;
        string _caller;
        string _receiver;
        int _duration;
    protected:
        Call(const int id, const string &receiver,
            const string &caller, const int duration) {
            _id = id;
            _receiver = receiver;
            _caller = caller;
            _duration = duration;
        }
    public:
        virtual double Cost() = 0;
        virtual ~Call() = default;
    };
}