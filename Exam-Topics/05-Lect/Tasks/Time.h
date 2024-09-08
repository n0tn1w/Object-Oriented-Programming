#pragma once

namespace TimeConst {
    constexpr unsigned SECONDS_IN_HOUR = 3600;
    constexpr unsigned SECONDS_IN_MINUTE = 60;
    constexpr unsigned SECONDS_IN_DAY = 24 * SECONDS_IN_HOUR;
}

class Time {

    unsigned _secondsFromMidnight = 0;

public:
    Time() = default;
    Time(unsigned hours, unsigned min, unsigned sec);

    unsigned getHours() const;
    unsigned getMins() const;
    unsigned getSecs() const;

    void setHours(unsigned hours);
    void setMins(unsigned mins);
    void setSecs(unsigned secs);

    unsigned getSecondsFromMidnight() const;
};

bool firstIsEarlierThenSecond(const Time& t1, const Time& t2);