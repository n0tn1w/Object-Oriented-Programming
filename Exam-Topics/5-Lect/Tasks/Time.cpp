#include "Time.h"

Time::Time(unsigned hours, unsigned mins, unsigned sec) {
    setHours(hours);
    setMins(mins);
    setSecs(sec);
}

unsigned Time::getHours() const {
    return _secondsFromMidnight / TimeConst::SECONDS_IN_HOUR;
}
unsigned Time::getMins() const {
    return (_secondsFromMidnight % TimeConst::SECONDS_IN_HOUR) / TimeConst::SECONDS_IN_MINUTE;
}
unsigned Time::getSecs() const {
    return (_secondsFromMidnight % TimeConst::SECONDS_IN_HOUR) % TimeConst::SECONDS_IN_MINUTE;
}

void Time::setHours(unsigned hours) {
    if(0 <= hours && hours <= 23) {
       _secondsFromMidnight = _secondsFromMidnight % TimeConst::SECONDS_IN_HOUR + hours * TimeConst::SECONDS_IN_HOUR;
    }
}
void Time::setMins(unsigned mins) {
    if(0 <= mins && mins <= 59) {
       _secondsFromMidnight = (_secondsFromMidnight - getMins() * TimeConst::SECONDS_IN_MINUTE) + (mins * TimeConst::SECONDS_IN_MINUTE);
    }
}
void Time::setSecs(unsigned secs) {
     if(0 <= secs && secs <= 59) {
       _secondsFromMidnight = (_secondsFromMidnight - getSecs()) + (secs);
    }
}

unsigned Time::getSecondsFromMidnight() const {
    return _secondsFromMidnight;
}

bool firstIsEarlierThenSecond(const Time& t1, const Time& t2) {
   return t1.getSecondsFromMidnight() <=  t2.getSecondsFromMidnight();
}