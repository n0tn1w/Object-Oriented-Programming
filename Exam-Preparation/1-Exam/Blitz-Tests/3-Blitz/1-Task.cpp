// 1. Какво ще изкара следният код?

#include <iostream>

class A {
public:
	A() {
		std::cout << "A()";
	}
	A(const A& other) {
		std::cout << "CC of A()";
	}
	A& operator=(const A& other) {
		std::cout << "OP= of A()";
		return *this;
	}
	~A() {
		std::cout << "~A()";
	}
};

class B {
public:
	B() {
		std::cout << "B()";
	}
	B(const B& other) {
		std::cout << "CC of B()";
	}
	B& operator=(const B& other) {
		std::cout << "OP= of B()";
		return *this;
	}
	~B() {
		std::cout << "~B()";
	}
};

class X {
	A obj1;
	B obj2;
public:
	X(const A& a, const B& b) {
		obj1 = a;
		obj2 = b;
		std::cout << "X()";
	}

	~X() {
		std::cout << "~X()";
	}
};

int main() {
	A obj1;
	B obj2;
	X obj(obj1, obj2);
}

// A()B()A()B()OP= of A()OP= of B()X()~X()~B()~A()~B()~A()