#pragma once

#include "Date.h"
#include "Time.h"
#include <cstddef>

namespace Const {
    constexpr size_t MAX_NAME_LENGHT = 20;
}

class Event {
    Date _date;
    Time _start;
    Time _end;
    char _name[Const::MAX_NAME_LENGHT + 1];

public:
    Event();

    Event(const Date& date, const Time& start, const Time& end, const char* name);

    Event(unsigned year, unsigned month, unsigned day, 
          unsigned startHours, unsigned startMinutes, unsigned startSeconds,
          unsigned endHours, unsigned endMinutes, unsigned endSeconds,
          const char* name);

    const Date& getDate() const;
    const Time& getStart() const;
    const Time& getEnd() const;
    const char* getName() const;

private:

    void setName(const char* name);
    void validateTimeAndSwapIfNeeded();
};