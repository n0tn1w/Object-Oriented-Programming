#include <iostream>
#include "SharedPtr.hpp"
#include "WeakPtr.hpp"
using std::cout;
using std::endl;

class A {

public:

    A() {
        cout << "A()" << endl;
    }
    int x;

    void f() {
        cout << "F()" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }
};

int main() {
    SharedPtr<A> sp(new A());
    SharedPtr<A> sp2 = sp;
    SharedPtr<A> sp3 = sp;

    (*sp3).f();
    sp3->f();
    
    // There is no such syntax
    // This is an object it doesnt have a operator-> until we said so
    //(sp2->)->f();    

    WeakPtr<A> wp;
	{
		SharedPtr<A> pt(new A());
		wp = pt;

		std::cout << wp.expired() << std::endl;
	}

	std::cout << wp.expired() << std::endl;
}