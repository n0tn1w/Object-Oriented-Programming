#include "NVector.h"
#include <iostream>
using namespace std;

int main() {
    NVector v1;
    NVector v2;

    v1.pushBack(1);
    v1.pushBack(2);
    v1.pushBack(3);

    v2.pushBack(3);
    v2.pushBack(6);
    v2.pushBack(9);

    bool res = v1 || v2;
    cout << res;

    cout << v1;
    cin >> v2;
    cout << v2;
    NVector v3 = v2 + v1;
    NVector v4 = v2 - v1;
    NVector v5 = v1*4;
    cout << v3 << endl << v4 << endl << v5 << endl;
}