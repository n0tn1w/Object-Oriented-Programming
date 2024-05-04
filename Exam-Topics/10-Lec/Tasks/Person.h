#pragma once
#include <utility>
#include <cstring>

class Person {

public:

    Person() = default;
    Person(const char*, unsigned);
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();

    Person(Person&&);
    Person& operator=(Person&&);

    const char* getName() const;
    unsigned getAge() const;
private:

    void copyFrom(const Person&);
    void moveFrom(Person&&);
    void free();

    void setName(const char*);
    void setAge(unsigned);

    char* _name = nullptr;
    unsigned _age = 0;

};