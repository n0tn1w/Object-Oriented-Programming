#include "Vector.hpp"

struct A {

};

class Factory {
public:
    //static const int* create(const char* str) {
      //  return nullptr;
    //}
    static A* create(const char* str) {
        return nullptr;
    }
};

int main() {
    Vector<A, Factory> vector;
    vector.add("baa");
    //int ptr = vector[0];
}