#include "MultiSet.h"
#include <iostream>
using namespace std;

int main() {
    MultiSet ms(100);
    ms.add(3);
        ms.add(3);

        ms.print();

    cout << ms.count(3);
        ms.add(3);
    cout << ms.count(3);
            ms.add(3);
        ms.add(3);

    cout << ms.count(3)<< endl;
    ms.remove(3);
    cout << ms.count(3) << endl;
        ms.remove(3);
    cout << ms.count(3) << endl;
        ms.remove(3);
    cout << ms.count(3) << endl;
        ms.remove(3);
    cout << ms.count(3) << endl;
        ms.print();

    ms.add(5);
    cout <<ms.count(5);
    ms.remove(5);
    cout <<ms.count(5);
        ms.print();

    ms.add(5);
        ms.print();

    ms.add(5);
    ms.add(5);
        ms.print();

    ms.remove(5);
    ms.remove(5);
    cout<< ms.count(5) << endl;

    ms.print();

    cout << "final" << endl;

    
    MultiSet s1(9);
    s1.add(1);
    s1.print();

    MultiSet s2(3);
    s2.add(1);
    s2.print();

    MultiSet res = unify(s1, s2);
    res.print();

}