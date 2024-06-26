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
	X(const X& other): a1(other.a1), a2(other.a2), obj2(other.obj2) {
		cout << "CC of X()" << endl;
	}
	X& operator=(const X& other) {
		cout << "OP= of X()" << endl;
        a1 = other.a1;
        a2 = other.a2;
        obj2 = other.obj2;

		return *this;
	}
	~X() {
		cout << "~X()" << endl;
	}
};

void f(X obj) {}
void g(X* obj) {}


int main() {
    X obj;          // A(), A(), B(), C(), X() 
    X obj2 = obj;   // CC of A(), CC of A(), B(), CC of C(), CC of X()
    obj = obj2;     // op= X(), op= A(), op= A(), op= C()
    X* ptr = &obj;  // ..
    cout << "Functions" << endl;
    f(*ptr);        // CC of A(), CC of A(), B(), CC of C(), CC of X(), ~X(), ~C(), ~B(), ~A(), ~A()
    g(ptr);         // ..
    cout << "Destructors" << endl;
}                   // ~X(), ~C(), ~B(), ~A(), ~A() ~X(), ~C(), ~B(), ~A(), ~A()