#include <iostream>
using namespace std;

struct A {
    virtual void f() {
        std::cout << "A::f" << endl;
    }

    virtual void g() {
        std::cout << "A::g" << endl;
    }
};

struct B : A { 
    virtual void f() override{
        std::cout << "B::f" << endl;
    }

    virtual void g() override{
        std::cout << "B::g" << endl;
    }
};

struct C : B {
    virtual void g() override{
        std::cout << "C::g" << endl;
    }
};

int main() {
    C obj;
    A* p1 = &obj;
    B* p2 = &obj;
    C* p3 = &obj;

    p1->f(); // B::f
    p2->f(); // B::f
    p3->f(); // B::f

    p1->g(); // C::f
    p2->g(); // C::f
    p3->g(); // C::f

}