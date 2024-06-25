#include "Person.h"

Person::Person(const char* name, unsigned age) {
    setName(name);
    setAge(age);
}

Person::Person(const Person& oth) {
    copyFrom(oth);
}

Person& Person::operator=(const Person& oth) {
    if(this != &oth) {
        free();
        copyFrom(oth);
    }

    return *this;
}

Person::~Person() {
    free();
}

Person::Person(Person&& oth) {
    moveFrom(std::move(oth));
}

Person& Person::operator=(Person&& oth) {
    if(this != &oth) {
        free();
        moveFrom(std::move(oth));
    }

    return *this;
}

void Person::copyFrom(const Person& oth) {
    _age = oth._age;

    unsigned len = strlen(oth._name);
    _name = new char[len + 1];
    _name[len] = '\0';
}

void Person::moveFrom(Person&& oth) {
    _age = oth._age;
    _name = oth._name;

    oth._age = 0;
    oth._name = nullptr;
}

void Person::free() {
    _age = 0;
    delete [] _name;
}

void Person::setName(const char* name) {

    if(name != nullptr) {
        unsigned len = strlen(name);
        _name = new char[len + 1];
        _name[len] = '\0';
    }

}

void Person::setAge(unsigned age) {
    if(age <= 100) {
        _age = age;
    }
}

const char* Person::getName() const {
    return _name;
}

unsigned Person::getAge() const {
    return _age;
}