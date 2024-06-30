#include <stddef.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;

#include "Employee.h"

class Manager: public Employee {

public:

    Employee* clone() const override;
    size_t getWorkersCount() const override;
    void print() const override;
    void addSubordinate(Employee* subordinate) override;

    Manager(const std::string&, const std::string&, size_t);

    Manager();
    Manager(const Manager&);
    Manager(Manager&&);
    Manager& operator=(const Manager&);
    Manager& operator=(Manager&&);
    ~Manager();

private:
    void print(const std::string&) const override;

    void copyFrom(const Manager&);
    void moveFrom(Manager&&);
    void free();
    void resize();

    std::string _position;
    
    Employee** _emps = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;

};
