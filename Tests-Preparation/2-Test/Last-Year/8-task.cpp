#include <iostream>
using namespace std;

class A {
public:
    A() = default;

    // Copy Constructor
    A(const A& other) {
        cout << "A: Copy Constructor" << endl;
    }

    // Copy Assignment Operator
    A& operator=(const A& other) {
        if (this != &other) {
            cout << "A: Copy Assignment Operator" << endl;
        }
        return *this;
    }
};

class B {
public:
    B() = default;

    // Copy Constructor
    B(const B& other) {
        cout << "B: Copy Constructor" << endl;
    }

    // Copy Assignment Operator
    B& operator=(const B& other) {
        if (this != &other) {
            cout << "B: Copy Assignment Operator" << endl;
        }
        return *this;
    }
};

class C {
public:
    C() = default;

    // Copy Constructor
    C(const C& other) {
        cout << "C: Copy Constructor" << endl;
    }

    // Copy Assignment Operator
    C& operator=(const C& other) {
        if (this != &other) {
            cout << "C: Copy Assignment Operator" << endl;
        }
        return *this;
    }
};

class D {
public:
    D() = default;

    // Copy Constructor
    D(const D& other) {
        cout << "D: Copy Constructor" << endl;
    }

    // Copy Assignment Operator
    D& operator=(const D& other) {
        if (this != &other) {
            cout << "D: Copy Assignment Operator" << endl;
        }
        return *this;
    }
};

class E {
public:
    E() = default;

    // Copy Constructor
    E(const E& other) {
        cout << "E: Copy Constructor" << endl;
    }

    // Copy Assignment Operator
    E& operator=(const E& other) {
        if (this != &other) {
            cout << "E: Copy Assignment Operator" << endl;
        }
        return *this;
    }
};

class X : A, B, C {
    D obj1;
    E obj2;
public:
    X() = default;

    // Copy Constructor
    X(const X& other): A(other), B(other), C(other), obj1(other.obj1), obj2(other.obj2)  {
        cout << "X: Copy Constructor" << endl;
    }

    // Copy Assignment Operator
    X& operator=(const X& other) {
        cout << "X: Copy Assignment Operator" << endl;
        if (this != &other) {
            A::operator=(other);
            B::operator=(other);
            C::operator=(other);
            obj1 = other.obj1;
            obj2 = other.obj2;
        }
        return *this;
    }
};

void f(X x) { }
void g(X&& x) { }

int main() {

    X obj1;
    X obj2;
    f(obj1); // CC of A, B, C, D, E, X
    g(std::move(obj2)); 
    obj1 = obj2; // OP X  A B C D E
}