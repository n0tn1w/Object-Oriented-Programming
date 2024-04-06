#include <iostream>
#include "StaticBitSet.h"
using namespace std;

int main() {
    StaticBitSet sbs;
        cout << sbs.check(132) << endl;

//     sbs.add(64);
//         sbs.printMemory();

//     sbs.add(1);
//     sbs.add(45);
 
//      sbs.printMemory();


//    sbs.add(1000);
//     sbs.printMemory();
    sbs.add(0);
    sbs.add(100);
    sbs.add(1000);
    //sbs.add(1001);

    cout << sbs.check(132) << endl;
    cout << sbs.check(100) << endl;
    cout << sbs.check(1000) << endl;

    sbs.remove(0);
    cout << sbs.check(0) << endl;
    cout << sbs.check(100) << endl;
    cout << sbs.check(1000) << endl;

    sbs.add(0);
        sbs.add(131);
    sbs.remove(100);
    sbs.add(1000);
    cout << sbs.check(0) << endl;
    cout << sbs.check(100) << endl;
    cout << sbs.check(1000) << endl;

    sbs.print();

    StaticBitSet sbs2;
    sbs2.add(1);
    sbs2.add(12);
    sbs2.add(13);
    sbs2.add(14);
    sbs2.add(12);

    section(sbs, sbs2).print();
    unification(sbs, sbs2).print();

}