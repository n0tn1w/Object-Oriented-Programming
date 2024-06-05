#include <iostream>
#include "Optional.hpp"
using namespace std;

struct A {
    int a;
    A() { cout << "A()" << endl; }
    A(int an) {
        a = an;
    }
    static A* create(int a) {
        if(a == 0) 
            return nullptr;
        return new A(a);
    }
    A(const A&) { cout << "CC A()" << endl; }
    A& operator=(const A&) { cout << "OP= A()" << endl; return *this;}
    ~A() { cout << "~A()" << endl; }

};

int main() {
    A a;
    Optional<A> sf;
    Optional<A> fd(new A(2));
    sf.set_value(A::create(4));
    cout << (*sf.getData()).a << " " << sf.getValue().a << " " << endl;
}