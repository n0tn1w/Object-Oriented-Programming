#include "Manager.h"

StaffMember* Manager::clone() const {
    return new Manager(*this);
}

size_t Manager::getWorkersCount() const {
    return _size;
}

void Manager::print() const {
    cout << " - " << _position << endl;
    for(size_t i = 0; i < _size; i++) {
        _emps[i]->print();
    }
}

void Manager::addSubordinate(StaffMember* subordinate) {
    if(_size  == _capacity)
        resize();

    _emps[_size++] = subordinate;
}

void Manager::resize() {
    _capacity *= 2;
    StaffMember** newEmps = new StaffMember*[_capacity];

    for(size_t i = 0; i < _size; i++) {
        newEmps[i] = _emps[i];
    }

    delete [] _emps;
    _emps = newEmps;
} 

void Manager::copyFrom(const Manager& oth) {
    _emps = new StaffMember*[oth._capacity];
    _capacity = oth._capacity;
    _size = oth._size;

    for(size_t i = 0; i < _size; i++) {
        _emps[i] = oth._emps[i]->clone();
    }
}
void Manager::moveFrom(Manager&& oth) {
    _emps = oth._emps;
    _size = oth._size;
    _capacity = oth._capacity;

    oth._emps = nullptr;
    oth._size = 0;
    oth._capacity = 0;
}
void Manager::free() {
    for(size_t i = 0; i < _size; i++) {
        delete _emps[i];
    }

    delete[] _emps;
}

Manager::Manager() : StaffMember() {
    _capacity = 4;
    _emps = new StaffMember*[_capacity];
}
Manager::Manager(const Manager& oth) : StaffMember(oth) {
    copyFrom(oth);
}
Manager::Manager(Manager&& oth) : StaffMember(std::move(oth)) {
    moveFrom(std::move(oth));
}
Manager& Manager::operator=(const Manager& oth) {
    if(this != &oth) {
        StaffMember::operator=(oth);
        free();
        copyFrom(oth);
    }
    return *this;
}
Manager& Manager::operator=(Manager&& oth) {
    if(this != &oth) {
        StaffMember::operator=(std::move(oth));
        free();
        moveFrom(std::move(oth));
    }
    return *this;
}
Manager::~Manager() {
    free();
}

