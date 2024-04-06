#include <iostream>
#include <fstream>
#include <cstring>
using std::cout;
using std::endl;

class DynamicStudent
{
    char* _name;
    int _age;
    int _fn;

public:

    DynamicStudent();
    DynamicStudent(const char*, int, int);
    DynamicStudent(const DynamicStudent&);
    DynamicStudent& operator=(const DynamicStudent&);
    ~DynamicStudent();

    friend std::ifstream& operator>>(std::ifstream&, DynamicStudent&);
    friend std::ofstream& operator<<(std::ofstream&, const DynamicStudent&);

    void print() const;

private:

    void free();
    void copyFrom(const DynamicStudent&);

};