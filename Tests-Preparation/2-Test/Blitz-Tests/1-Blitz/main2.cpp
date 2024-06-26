#include <iostream>
using namespace std;

struct A
{
	A()
	{
		std::cout << "A()";
	}

	~A()
	{
		std::cout << "~A()";
	}
};


struct B
{
	B()
	{
		std::cout << "B()";
		throw std::exception();
	}

	~B()
	{
		std::cout << "~B()";
	}
};


struct C
{
	C()
	{
		std::cout << "C()";
	}

	~C()
	{
		std::cout << "~C()";
	}
};

struct X
{
	A a;
	B b;
	C c;
	X()
	{
		std::cout << "X()";
	}

	~X()
	{
		std::cout << "~X()";
	}
};

int main()
{
    try
    {
        X x;
    }
    catch(const std::exception& e)
    {
        // HANDLE ERROR
    }
}