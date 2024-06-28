#pragma once
#include <stddef.h>

#include "Employee.h"
#include "SpecialTrainee.h"
#include "Trainee.h"
#include "Worker.h"

class Company {

public:

    Company();
    Company(const Company&);
    Company(Company&&);
    Company& operator=(const Company&);
    Company& operator=(Company&&);
    ~Company();

    void addWorker();
    void addTrainee();
    void addSpecialTrainee();

    size_t avg() const;
    void print() const;

private:

    void addEmployee(Employee*);
    void resize();

    void sort();

    void copyFrom(const Company&);
    void moveFrom(Company&&);
    void free();

    Employee** _emps = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;

    mutable size_t _avg_salary = 0;
    mutable bool _isModified = true;

};