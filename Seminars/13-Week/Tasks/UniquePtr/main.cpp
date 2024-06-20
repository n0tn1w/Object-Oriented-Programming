#include "UniquePtr.hpp"
#include <iostream>
using std::cout;
using std::endl;

class A {

public:

    A() {
        cout << "A()" << endl;
    }
    int x =3;

    void f() {
        cout << "F()" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }
};

int main() {
    UniquePtr<A> up(new A());
    UniquePtr<A> up2(new A());
    
    // Throwing
    // UniquePtr<A> up2(up);
    // up = up2;

    cout << up->x << endl;

}