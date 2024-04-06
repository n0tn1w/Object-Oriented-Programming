#include <iostream>
#include "StaticBitSet.h"
#include "DynamicBitSet.h"
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

    cout << "=======" << endl;
    DynamicBitSet d(10);

    d.add(1);
    d.add(0);
    d.add(2);
    d.print();

    d.remove(1);
    d.remove(6);
    d.remove(9);
    d.add(3);
    d.print();

    d.remove(3);
    d.print();

    DynamicBitSet d2(5);
    d2.add(0);
    section(d, d2).print();

    d2.add(3);
    d2.add(1);
    unification(d, d2).print();

}