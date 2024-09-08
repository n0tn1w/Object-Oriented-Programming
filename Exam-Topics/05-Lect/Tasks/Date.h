#include <iostream>

// if you think you can do the bulgariandate first try on exam day good for you

namespace DateConst {

    const unsigned DAYS_IN_MONTH[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    

};

class Date {
private:

    unsigned _day;
    unsigned _month;
    unsigned _year;

    bool _isValid = false;

public:

    Date();
    Date(unsigned day, unsigned month, unsigned year);

    unsigned getDay() const;
    unsigned getMonth() const;
    unsigned getYear() const;

private:

    bool good() const;
    void validate();

    void setDay(unsigned day);
    void setMonth(unsigned month);
    void setYear(unsigned year);

};