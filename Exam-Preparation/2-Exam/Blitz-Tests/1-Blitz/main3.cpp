#include <iostream>

class Base {
	int a;
public:
	Base() {
		std::cout << "Base()\n";
	}
	virtual void f() const {
		std::cout << "Base::f\n";
	}
	~Base() {
		std::cout << "~Base()\n";
	}

};

class Der1 : public Base {
	int b;
public:
	Der1() {
		std::cout << "Der1()\n";
	}
	void f() const override {
		Base::f();
		std::cout << "Der1::f\n";
	}

	~Der1() {
		std::cout << "~Der1()\n";
	}
};

class Der2 : public Der1 {
	int c;
public:
	Der2() {
		std::cout << "Der2()\n";
	}

	~Der2() {
		std::cout << "~Der2()\n";
	}

};

int main() {
	Base* ptr = new Der2();
	ptr->f();
	delete ptr;
}