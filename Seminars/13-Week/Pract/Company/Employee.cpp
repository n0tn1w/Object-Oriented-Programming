#include "Employee.h"

Employee::Employee(const char* name, unsigned age, unsigned salary) {
    std::cout << "Employee" << std::endl;
    size_t len = strlen(name);
    _name = new char[len + 1];
    strcpy(_name, name);
    _age = age;
    _salary = salary;
}

Employee::Employee(const Employee& oth) {
    copyFrom(oth);
}

Employee::Employee(Employee&& oth) {
    moveFrom(std::move(oth));
}

Employee& Employee::operator=(const Employee& oth) {
    if(this != &oth) {
        free();
        copyFrom(oth);
    }

    return *this;
}

Employee& Employee::operator=(Employee&& oth) {
    if(this != &oth) {
        free();
        moveFrom(std::move(oth));
    }

    return *this;
}

Employee::~Employee() {
    free();
}

void Employee::copyFrom(const Employee& oth) {
    size_t len = strlen(oth._name);
    _name = new char[len];
    strcpy(_name, oth._name);
    _age = oth._age;
    _salary = oth._salary;
}

void Employee::moveFrom(Employee&& oth) {
    _name = oth._name;
    _age = oth._age;
    _salary = oth._salary;

    oth._name = nullptr;
    oth._age = 0;
    oth._salary = 0;
}

void Employee::free() {
    delete[] _name;
    _age = 0;
    _salary = 0;
}

void Employee::print() const{ 
    std::cout << _name << " " << _age << " " << _salary;
}

size_t Employee::getSalary() const {
    return _salary;
}
