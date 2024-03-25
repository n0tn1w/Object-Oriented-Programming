#include "Time.h"

#include <iostream>
#include <iomanip>

namespace TimeConstants {
    const unsigned HOURS_IN_DAY = 24;
    const unsigned MINUTES_IN_HOUR = 60;
    const unsigned SECONDS_IN_MINUTE = 60;
    const unsigned SECONDS_IN_HOUR = 60 * 60;
};

Time::Time(unsigned seconds) {
    setSeconds(seconds % 60);
    seconds /= 60;
    setMinutes(seconds % 60);
    seconds /= 60;
    setHours(seconds);
}

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(unsigned hours, unsigned minutes, unsigned seconds) {
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

unsigned Time::getHours() const {
    return hours;
}

unsigned Time::getMinutes() const {
    return minutes;
}

unsigned Time::getSeconds() const {
    return seconds;
}

void Time::setHours(unsigned newValue) {
    if (newValue >= TimeConstants::HOURS_IN_DAY) {
        newValue = 0;
    }
    hours = newValue;
}

void Time::setMinutes(unsigned newValue) {
    if (newValue >= TimeConstants::MINUTES_IN_HOUR) {
        newValue = 0;
    }
    minutes = newValue;
}

void Time::setSeconds(unsigned newValue) {
    if (newValue > TimeConstants::SECONDS_IN_MINUTE) {
        newValue = 0;
    }
    seconds = newValue;
}

void Time::addSecond() {
    if (++seconds >= TimeConstants::SECONDS_IN_MINUTE) {
        ++minutes;
        seconds = 0;
    }
    if (minutes >= TimeConstants::MINUTES_IN_HOUR) {
        ++hours;
        minutes = 0;
    }
    if (hours >= TimeConstants::HOURS_IN_DAY) {
        hours = 0;
    }
}

unsigned Time::getTotalSeconds() const {
    return
        hours * TimeConstants::SECONDS_IN_HOUR +
        minutes * TimeConstants::SECONDS_IN_MINUTE +
        seconds;
}

void Time::print() const {
    std::cout
        << std::setw(2) << std::setfill('0') << getHours() << ":"
        << std::setw(2) << std::setfill('0') << getMinutes() << ":"
        << std::setw(2) << std::setfill('0') << getSeconds();
}