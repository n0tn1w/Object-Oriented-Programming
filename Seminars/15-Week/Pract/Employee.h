#include <string>
#include <iostream>
using std::cout;
using std::endl;

#include "StaffMember.h"

class Employee : StaffMember {
    
public:

    StaffMember* clone() const override;
    size_t getWorkersCount() const override;
    void print() const override;
    void addSubordinate(StaffMember* subordinate) override;

};