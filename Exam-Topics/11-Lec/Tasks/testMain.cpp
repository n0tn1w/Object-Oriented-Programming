#include <iostream>
using namespace std;

struct Base {
private: 
    int a;
protected:
    int b;
public:
    int c;

    void setA(int ab) {
        a = ab;
    }
};

struct Der : public Base {
private: 
    int g;
protected:
    int h;
public:
    int k;

    void f(int ab) {
        Base::setA(ab);
    }
};


int main() {
    Der d;
    d.f(1);
}