#include <fstream>
#include <stdexcept>
#include <iostream>
using std::cout;

class Base { 
public:
    virtual ~Base() = default;
};
class A : public Base {
public:
    A() { cout << "A()"; }; 
    ~A() { cout << "~A()"; }; 
};
class B : public Base {
public:
    B() { cout << "B()"; }; 
    ~B() { cout << "~B()"; }; 
};

class SignletonFactory {

public:

    static SignletonFactory& getInstance() {
        static SignletonFactory instance;
        return instance;
    }
    
    Base* create() {
        if(_numbersCount <= _currIndex) {
            //return nullptr; // Angel's way
            throw std::runtime_error("All numbers used!");
        }

        if(_data[_currIndex++] % 2 == 0) {
            return new A();
        } else {
            return new B();
        }
    }

private:

    SignletonFactory() {
        std::ifstream ifs("data.txt", std::ios::in);

        if(!ifs.is_open()) {
            throw std::runtime_error("Cannot open file");
        }   

        ifs >> _numbersCount;

        _currIndex = 0;
        _data = new int[_numbersCount];
        try{
            
            int i = 0;
            while(!ifs.eof()) {
                ifs >> _data[i++];
            }

        }catch(std::bad_alloc& ex) {
            delete[] _data;
            throw;
        }
    }

    // Destr is private because otherwise it could be called via delete to a pointer
    ~SignletonFactory() {
        delete[] _data;
    }

    SignletonFactory(const SignletonFactory&) = delete;
    SignletonFactory& operator=(const SignletonFactory&) = delete;

    int* _data;
    size_t _numbersCount;
    size_t _currIndex;

};

int main() {
    {
        SignletonFactory& sf = SignletonFactory::getInstance();
        
        Base* o1 = sf.create();
        Base* o2 = sf.create();
        Base* o3 = sf.create();

        delete o1;
        delete o2;
        delete o3;
    }
}