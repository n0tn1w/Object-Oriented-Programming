#pragma once

class Event {

public:
    virtual Event* clone() const = 0;
    virtual ~Event() = default;

    virtual const char* check() const = 0;
};
