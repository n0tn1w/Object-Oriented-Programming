#pragma once
#include <iostream>

#include "Employee.h"

class Trainee : public virtual Employee {

public:

    Trainee(unsigned, const char*, unsigned, unsigned);

    void print() const override;
    Employee* clone() const override;

protected:

    unsigned _daysLeft = 0;

};