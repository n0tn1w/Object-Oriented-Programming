#include "Student.h"

Student::Student(const char* name, unsigned age, int fn) : Person(name, age) {
    setFn(fn);
}

void Student::setFn(int fn) {
    if(fn < 0)
        throw std::logic_error(""); 

    _fn = fn;
}

int Student::getFn() const {
    return _fn;
}