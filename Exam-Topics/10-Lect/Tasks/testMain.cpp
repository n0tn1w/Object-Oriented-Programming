#include <iostream>
using namespace std;

class A {
public:
    int dev = 0;
    A() {
        cout << "A()" << endl;
    }
    A& operator=(const A& oth) {
        cout << "OP=A" << endl;
        dev = 1;

        return *this;
    }
};

class B : public A {
public:

};

int main() {
    B b;
    B b2;
    b2 = b;
    cout << b2.dev << endl;
}