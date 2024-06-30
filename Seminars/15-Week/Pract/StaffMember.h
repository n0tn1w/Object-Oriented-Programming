#pragma once
#include <stddef.h>
#include <string>

class StaffMember {

protected:

    std::string _name = "";
    size_t _salary = 0;

public:

    StaffMember() = default;
    StaffMember(const std::string&, size_t);
    virtual StaffMember* clone() const = 0;
    virtual size_t getWorkersCount() const = 0;
    virtual ~StaffMember() = default;
    virtual void addSubordinate(StaffMember* subordinate) = 0;

    virtual void print() const = 0;
};