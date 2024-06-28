#include "Trainee.h"

Trainee::Trainee(unsigned daysLeft, const char* name, unsigned age, unsigned salary) : Employee(name, age, salary), _daysLeft(daysLeft) {
    std::cout << "Trainee" << std::endl;
}

void Trainee::print() const {
    std::cout << _daysLeft;
    Employee::print();
}

Employee* Trainee::clone() const {
    return new Trainee(*this);
}
