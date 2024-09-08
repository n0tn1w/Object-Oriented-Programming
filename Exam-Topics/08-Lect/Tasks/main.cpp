#include <iostream>
#include "SelfCountingClass.h"
using std::cout;
using std::endl;

int main() {

    SelfCounting sc1;
    cout << sc1.getLive() << endl;
    cout << sc1.getTotal() << endl;

    {
        SelfCounting sc2;
        cout << sc1.getLive() << endl;
        cout << sc1.getTotal() << endl;
    }

    cout << sc1.getLive() << endl;
    cout << sc1.getTotal() << endl;

}