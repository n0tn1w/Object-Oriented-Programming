#include <iostream>
using std::cout;
using std::endl;

class A {
public:
	A() {
		cout << "A()" << endl;
	}
	A(const A& other) {
		cout << "CC of A()" << endl;
	}
	A& operator=(const A& other) {
		cout << "OP= of A()" << endl;
		return *this;
	}
	~A() {
		cout << "~A()" << endl;
	}
};

class B {
public:
	B() {
		cout << "B()" << endl;
	}
	B(const B& other) {
		cout << "CC of B()" << endl;
	}
	B& operator=(const B& other) {
		cout << "OP= of B()" << endl;
		return *this;
	}
	~B() {
		cout << "~B()" << endl;
	}
};

class C {
public:
	C() {
		cout << "C()" << endl;
	}
	C(const C& other) {
		cout << "CC of C()" << endl;
	}
	C& operator=(const C& other) {
		cout << "OP= of C()" << endl;
		return *this;
	}
	~C() {
		cout << "~C()" << endl;
	}
};

class X {
    A a1, a2;
    B obj1;
    C obj2;
public:
	X() {
		cout << "X()" << endl;
	}
	X(const X& other): a1(other.a1), a2(other.a2), obj1(other.obj1), obj2(other.obj2) {
		cout << "CC of X()" << endl;
	}
	X& operator=(const X& other) {
		cout << "OP= of X()" << endl;
        a1 = other.a1;
        a2 = other.a2;
        obj1 = other.obj1;
        obj2 = other.obj2;

		return *this;
	}
	~X() {
		cout << "~X()" << endl;
	}
};

X f(X x) {
    return x;
}

int main() {
    X x = f(X());
	cout << "End";
}                  