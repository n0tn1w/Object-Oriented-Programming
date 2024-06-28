#include "SpecialTrainee.h"


SpecialTrainee::SpecialTrainee(unsigned daysLeft, unsigned monthsInCompany, const char* name, unsigned age, unsigned salary)
: Employee(name, age, salary), Trainee(daysLeft, name, age, salary), Worker(monthsInCompany, name, age, salary) { 
    std::cout << "SpecialTrainee" << std::endl;
} 

void SpecialTrainee::print() const {
    std::cout << _daysLeft << " ";
    Worker::print();
}

Employee* SpecialTrainee::clone() const {
    return new SpecialTrainee(*this);
}
