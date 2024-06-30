#include "Employee.h"

Employee* Employee::clone() const {
    return new Employee(*this);
}

size_t Employee::getWorkersCount() const {
    return 0;
}

void Employee::print() const {
    cout << " - Employee : " << _name << endl;
}
void Employee::print(const std::string& str) const {
    cout << str << " - Employee : " << _name << endl;
}

void Employee::addSubordinate(Employee* subordinate) {
    return;
}


Employee::Employee(const std::string& name, size_t salary) {
    // Validation
    _name = name;
    _salary = salary;
}
