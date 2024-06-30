#pragma once

#include <string>
#include <iostream>
#include <stddef.h>
#include <string>

using std::cout;
using std::endl;

class Employee {

public:

    Employee() = default;
    Employee(const std::string&, size_t);
    virtual Employee* clone() const;
    virtual size_t getWorkersCount() const;
    virtual void addSubordinate(Employee* subordinate);

    virtual void print() const;
    virtual ~Employee() = default;

    virtual void print(const std::string&) const;
protected:

    std::string _name = "";
    size_t _salary = 0;


};