#include <iostream>
using namespace std;

struct Base {
    virtual void f() {cout << "base";} ;
};

struct Der : Base
{
    void f(){
        cout << "der";
    }
};


int main()
{
	try
	{
		throw std::invalid_argument("ERROR");
	}
	catch (const std::runtime_error&)
	{
		std::cout << "Runtime error";
	}
	catch (const std::logic_error&)
	{
		std::cout << "Logic error";
	}
	catch (const std::invalid_argument&)
	{
		std::cout << "Invalid argument";
	}
	catch (const std::exception&)
	{
		std::cout << "Exception";
	}
}