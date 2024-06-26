#pragma once

class Observer {

public:
    virtual Observer* clone() const = 0;
    virtual ~Observer() = default;

    virtual void notify(const char*) const = 0;

};