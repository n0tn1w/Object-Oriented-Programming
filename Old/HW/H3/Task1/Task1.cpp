#include <iostream>
#include "Script.h"
#include "Solver.h"

using namespace std;

int main()
{

    createFiles();

    MyString fileName("set.bin");
    Solver s(fileName);

    s.run();

}