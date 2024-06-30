#include <stddef.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;

#include "StaffMember.h"

struct Manager : StaffMember {

public:

    StaffMember* clone() const override;
    size_t getWorkersCount() const override;
    void print() const override;
    void addSubordinate(StaffMember* subordinate) override;


    Manager();
    Manager(const Manager&);
    Manager(Manager&&);
    Manager& operator=(const Manager&);
    Manager& operator=(Manager&&);
    ~Manager();

private:

    void copyFrom(const Manager&);
    void moveFrom(Manager&&);
    void free();
    void resize();

    std::string _position;
    
    StaffMember** _emps = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;

};
