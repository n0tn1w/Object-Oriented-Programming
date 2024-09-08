#include "iostream"
using std::cout;
using std::endl;

struct A {
    int n = 1;

    operator bool() const {
        return n == 1;
    }
};

struct B {
    int n = 0;

    explicit operator bool() const {
        return n == 0;
    }
};

int main() {
    A a;
    B b;

    if(a) {
        cout << "normal a" << endl;
    }

    if(b) { // >C++11 the explicit cast is not need when the operation is inside for, if, while
        cout << "explicit b" << endl;
    }

    //bool wrongRes = b; // Expilicit cast is needed in this situation
    bool res = static_cast<bool>(b);
    if(res) {
        cout << "casted" << endl;
    }
}