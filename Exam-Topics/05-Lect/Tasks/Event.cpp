#include "Event.h"

#include <cstring>
#include <iomanip>
// Include of a lib needs to be here because if they were in the header
// when you a include the header inside another header the lib will be copied
// I think there are guards in the libs and they wont allow you to be coppied 2 times over
// one of this guards is #pragma once

Event::Event() : Event(0, 0, 0, 0, 0, 0, 0, 0, 0, "") {} // This is done so that it could be used in arrays like Event arr[2]

Event::Event(const Date& date, const Time& start, const Time& end, const char* name):
    _date(date), _start(start), _end(end) 
{
    // Both ways
    //_date = date;
    //_start = start;
    //_end = end;

    setName(name);
    validateTimeAndSwapIfNeeded();
}

Event::Event(unsigned year, unsigned month, unsigned day, 
          unsigned startHours, unsigned startMinutes, unsigned startSeconds,
          unsigned endHours, unsigned endMinutes, unsigned endSeconds,
          const char* name):
          _date(year, month, day),
          _start(startHours, startMinutes, startSeconds)
{
    // Both ways
    //_date = Date(year, month, day);
    //_start = Time(startHours, startMinutes, startSeconds);
    //_end = Time(endHours, endMinutes, endSeconds);

    setName(name);
    validateTimeAndSwapIfNeeded();
}
 
const Date& Event::getDate() const {
    return _date;
}

const Time& Event::getStart() const {
    return _start;
}

const Time& Event::getEnd() const {
    return _end;
}

const char* Event::getName() const {
    return _name;
}

void Event::setName(const char* name) {
    size_t len = strlen(name);
    if(Const::MAX_NAME_LENGHT > len) {
        return;
    }

    strcpy(this->_name, name);
}

void Event::validateTimeAndSwapIfNeeded() {
    if(!firstIsEarlierThenSecond(_start, _end)) {
        std::swap(_start, _end);
    }
}