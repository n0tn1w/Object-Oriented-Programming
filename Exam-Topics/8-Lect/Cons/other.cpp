#include <iostream>

// void test() {
//     std::cout << "Hello";
// }

// static void test2() {
//     std::cout << "Hello2";
// }

class A {
    int x;
    int z;
public:
    A() = delete;
};

class B {
public:
    static A a;

};