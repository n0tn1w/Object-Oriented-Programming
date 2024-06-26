#include <iostream>
#include <cstring>
#include "EventManager.h"
using namespace std;

int main() {
    
    EventManager e;

    e.addEvent("ffile.txt");
    e.addEvent("t30");

    e.addObserver("stdout");
    e.addObserver("foutfile.txt");
    e.run();
}