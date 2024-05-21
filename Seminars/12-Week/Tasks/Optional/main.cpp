#include <iostream>
#include "Optional.hpp"
using std::cout;

int main() {

    Optional<int> a;
    if(a) {
        cout << "a";
    }
}