#pragma once
#include <stddef.h>
#include <cstring>
#include <utility>
#include <iostream>

class Employee {

public:

    Employee() = default;
    Employee(const char*, unsigned, unsigned);
    Employee(const Employee&);
    Employee(Employee&&);
    Employee& operator=(const Employee&);
    Employee& operator=(Employee&&);
    virtual ~Employee();

    virtual void print() const = 0;
    virtual Employee* clone() const  = 0;

    size_t getSalary() const;

private:

    void copyFrom(const Employee&);
    void moveFrom(Employee&&);
    void free();

    char* _name = nullptr;
    unsigned _age = 0;
    unsigned _salary = 0;

};