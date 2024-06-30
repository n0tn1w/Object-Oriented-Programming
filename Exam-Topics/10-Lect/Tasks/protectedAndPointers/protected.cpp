#include <iostream>

class Base {
protected:
    int n;
public:
    double p;
};

class Derived : public Base {
public:
    void f() {
        std::cout << "Protected member: " << n << std::endl;
    }

    //void g(Base* base) {
    //    std::cout << "Protected member: " << base->n << std::endl;
    //}

    void h(Derived* der) {
        std::cout << "Protected member: " << der->n << std::endl;

    }
};

int main() {
    Derived d{};
    d.f(); // This works
    d.h(&d);

    Base* b = &d;
    b->p;
    //b->n; // Will not work
    //d.g(b); // Will not work

    return 0;
}

