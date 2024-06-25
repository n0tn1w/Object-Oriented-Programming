#pragma once
#include "Person.h"
#include <stdexcept>

class Student : public Person {

public:

    Student() = default;
    Student(const char*, unsigned, int);

    int getFn() const;
private:

    void setFn(int);

    int _fn = 0;
};