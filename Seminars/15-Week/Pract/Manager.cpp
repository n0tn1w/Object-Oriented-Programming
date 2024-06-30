#include "Manager.h"

Employee* Manager::clone() const {
    return new Manager(*this);
}

size_t Manager::getWorkersCount() const {
    return _size;
}

void Manager::print() const {
    cout << " - " << _position  << " : "<< _name << endl;
    for(size_t i = 0; i < _size; i++) {
        _emps[i]->print("\t");
    }
}

void Manager::print(const std::string& str) const {
    cout << str << " - " << _position  << " : "<< _name << endl;
    for(size_t i = 0; i < _size; i++) {
        std::string std = str + '\t';
        _emps[i]->print(std);
    }
}


void Manager::addSubordinate(Employee* subordinate) {
    if(_size  == _capacity)
        resize();

    _emps[_size++] = subordinate;
}

void Manager::resize() {
    _capacity *= 2;
    Employee** newEmps = new Employee*[_capacity];

    for(size_t i = 0; i < _size; i++) {
        newEmps[i] = _emps[i];
    }

    delete [] _emps;
    _emps = newEmps;
} 

Manager::Manager(const std::string& position, 
const std::string& name, size_t salary) : Employee(name, salary), _position(position)
{ }

void Manager::copyFrom(const Manager& oth) {
    _emps = new Employee*[oth._capacity];
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

Manager::Manager() : Employee() {
    _capacity = 4;
    _emps = new Employee*[_capacity];
}
Manager::Manager(const Manager& oth) : Employee(oth) {
    copyFrom(oth);
}
Manager::Manager(Manager&& oth) : Employee(std::move(oth)) {
    moveFrom(std::move(oth));
}
Manager& Manager::operator=(const Manager& oth) {
    if(this != &oth) {
        Employee::operator=(oth);
        free();
        copyFrom(oth);
    }
    return *this;
}
Manager& Manager::operator=(Manager&& oth) {
    if(this != &oth) {
        Employee::operator=(std::move(oth));
        free();
        moveFrom(std::move(oth));
    }
    return *this;
}
Manager::~Manager() {
    free();
}

