#pragma once
#include "Employee.h"

class Worker : public virtual Employee {

public:

    Worker(unsigned, const char*, unsigned, unsigned);

    void print() const override;
    Employee* clone() const override;

protected:

    unsigned _monthsInCompany= 0;

};