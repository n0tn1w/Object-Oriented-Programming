#include <iostream>
using namespace std;

struct A {
    void f() {
        std::cout << "A()" << endl;
    }
};

struct B : A { };

struct C : B {
    void f() {
        std::cout << "C()" << endl;
    }
};

int main() {
    C obj;
    A* p1 = &obj;
    B* p2 = &obj;
    C* p3 = &obj;

    p1->f(); // A()
    p2->f(); // A()
    p3->f(); // C()
}
