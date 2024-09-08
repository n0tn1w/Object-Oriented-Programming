#include "Date.h"

Date::Date() : _day(0), _month(0), _year(0) {}

Date::Date(unsigned day, unsigned month, unsigned year) {
    setDay(day);
    setMonth(month);
    setYear(year);

    validate();
}

bool Date::good() const {
    return this->_isValid;
}

unsigned Date::getDay() const {
    if(!good()) {return 0 ;}

    return this->_day;
}

unsigned Date::getMonth() const {
    if(!good()) {return 0 ;}

    return this->_month;
}

unsigned Date::getYear() const {
    if(!good()) {return 0 ;}

    return this->_year;
}
 

void Date::setDay(unsigned day) {
    this->_day = day;

    validate();
}

void Date::setMonth(unsigned month) {
    this->_month = month;

    validate();
}

void Date::setYear(unsigned year) {
    this->_year = year;

    validate();
}

void Date::validate(){
    this->_isValid = false;

    if(0 <= this->_year) {
        if(0 <= this->_month && this->_month <= 12) {
            unsigned maxDaysInMonth = DateConst::DAYS_IN_MONTH[this->_month];

            if(this->_month == 2 && this->_year % 4 == 0 && !this->_year % 100 == 0) {
                maxDaysInMonth++;
            }

            if(0 <= this->_day && this->_day <= maxDaysInMonth) {
                this->_isValid = true;
            }
        }
    }

}
