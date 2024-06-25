#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Professor.h"
using std::cout;
using std::endl;

int main() {
    char subject[3][20] = {
        "Math", "Sci", "PE"
    };

    char** pointer = new char*[3];
    pointer[0] = subject[0];
    pointer[1] = subject[1];
    pointer[2] = subject[2];

    Professor p("Ivan", 12, pointer, 3);
    cout << p.getName() << endl;

    delete[] pointer;
}