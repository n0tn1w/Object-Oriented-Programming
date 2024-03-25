#pragma once

class Time {
private:
    unsigned hours, minutes, seconds;

    Time(unsigned seconds);
public:
    Time();
    Time(unsigned hours, unsigned minutes, unsigned seconds);

    unsigned getHours() const;
    unsigned getMinutes() const;
    unsigned getSeconds() const;

    void setHours(unsigned newValue);
    void setMinutes(unsigned newValue);
    void setSeconds(unsigned newValue);

    void addSecond();

    unsigned getTotalSeconds() const;

    void print() const;
};