#include <iostream>
using std::cout;

struct A {

    void f() const {
        cout << this;
    }

};

int main() {
    A a;
    a.f();
}
