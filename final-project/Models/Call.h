#pragma once
#include <iomanip>
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
        static int getIdWidth(){ return 16; }
        static int getCallerWidth(){ return 40; }
        static int getReceiverWidth(){ return 40; }
        static int getDurationWidth(){ return 16; }
        static int getCustomColumnWidth(){ return 45; }
        static int getTotaWidth() {
            return getIdWidth() + getCallerWidth() + getReceiverWidth()
            + getDurationWidth() + getCustomColumnWidth() + 3;
        }
        virtual double Cost() = 0;
        virtual string getType() = 0;
        virtual ~Call() = default;
    };
}