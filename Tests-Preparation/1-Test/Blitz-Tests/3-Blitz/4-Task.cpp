// 2. Какво ще изпринти следният код?

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
	A* obj1;
	B& obj2;
public:
	X(const A& a, B& b): obj2(b){
		obj1 = new A(a);
		std::cout << "X()";
	}

	~X() {
		delete obj1;
		std::cout << "~X()";
	}
};

int main() {
	A obj1; // A()
	B obj2; // B()
	X obj(obj1, obj2); // CC A(), X()
    // ~A(), ~X(), ~B(), ~A()
}