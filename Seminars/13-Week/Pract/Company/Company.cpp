#include "Company.h"

Company::Company() {
    _size = 0;
    _capacity = 16;
    _emps = new Employee*[_capacity] {nullptr};
}

Company::Company(const Company& oth) { copyFrom(oth); }
Company::Company(Company&& oth) {moveFrom(std::move(oth)); }
Company& Company::operator=(const Company& oth) { if(this != &oth) {free(); copyFrom(oth);} return *this; }
Company& Company::operator=(Company&& oth) { if(this != &oth) {free(); moveFrom(std::move(oth));} return *this; }
Company::~Company() { free(); }

void Company::addWorker() {
    unsigned monts, age, salary;
    char* buff;
    std::cin >> monts >> buff >> age >> salary;

    addEmployee(new Worker(monts, buff, age, salary));
}
void Company::addTrainee() {
    unsigned daysLeft, age, salary;
    char* buff;
    std::cin >> daysLeft >> buff >> age >> salary;

    addEmployee(new Trainee(daysLeft, buff, age, salary));

}
void Company::addSpecialTrainee() {
    unsigned daysLeft, monts, age, salary;
    char* buff;
    std::cin >> daysLeft >> monts >> buff >> age >> salary;

    addEmployee(new SpecialTrainee(daysLeft, monts, buff, age, salary));

}

void Company::addEmployee(Employee* emp){
    if(_size == _capacity)
        resize();

    _emps[_size++] = emp;

    _isModified = true;
    sort();
}

void Company::sort() {

    for(size_t i = 0; i < _size; i++) {
        size_t minIndex = i;

        for(size_t k = i + 1; k < _size; k++) {
            if(_emps[k]->getSalary() < _emps[i]->getSalary()) {
                minIndex = k;
            }
        }

        if(minIndex != i) {
            std::swap(_emps[i], _emps[minIndex]);
        }
    }
}

size_t Company::avg() const {
    if(!_isModified)
        return _avg_salary;

    _avg_salary = 0;
    for(size_t i = 0; i < _size; i++) {
        _avg_salary += _emps[i]->getSalary();
    }

    return _avg_salary /= _size;
}

void Company::resize() {
    _capacity *= 2;
    Employee** temp = new Employee*[_capacity];
    for(size_t i = 0; i < _size; i++) {
        temp[i] = _emps[i];
    }
    delete[] _emps;
    temp = _emps;
}


void Company::copyFrom(const Company& oth) {
    _emps = new Employee*[oth._capacity];
    for(size_t i = 0; i < oth._size; i++) {
        _emps[i] = oth._emps[i]->clone();
    }
    _size = oth._size;
    _capacity = oth._capacity;
}
void Company::moveFrom(Company&& oth) {
    _emps = oth._emps;
    _size = oth._size;
    _capacity = oth._capacity;
    oth._emps = nullptr;
    oth._size = 0;
    oth._capacity = 0;
}
void Company::free() {
    for(size_t i = 0; i <_size; i++) {
        delete _emps[i];
    }
    delete[] _emps;
}

void Company::print() const {
    for(size_t i = 0; i <_size; i++) {
        _emps[i]->print();
        std::cout << std::endl;
    }
}
