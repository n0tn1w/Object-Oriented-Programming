#include "Employee.h"

StaffMember* Employee::clone() const {
    return new Employee(*this);
}

size_t Employee::getWorkersCount() const {
    return 0;
}

void Employee::print() const {
    cout << " - Employee " << endl;
}

void Employee::addSubordinate(StaffMember* subordinate) {
    return;
}
