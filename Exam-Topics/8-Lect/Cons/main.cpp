#include <iostream>
#include "other.cpp"


//void test();
class B;
//void test2();

int main() {
    //test();
    // linker error
    //test2(); // can't call test2 because it's static
    // it is related to the other .cpp and can not be called by another
    B b;
    A v =  b.a;

}