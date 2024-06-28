#include "Worker.h"

Worker::Worker(unsigned monthsInCompany, const char* name, unsigned age, unsigned salary) : Employee(name, age, salary), _monthsInCompany(monthsInCompany) {
     std::cout << "Worker" << std::endl;
}

void Worker::print() const {
    std::cout << _monthsInCompany;
    Employee::print();
}

Employee* Worker::clone() const {
    return new Worker(*this);
}
