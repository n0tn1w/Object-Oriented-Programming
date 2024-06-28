#include <iostream>
using std::cout;
#include "SharedPtrWithCounter.hpp"

int main() {
    SharedPtrWithCounter<int, 3> spc(new int(3));
    cout << "1";
    SharedPtrWithCounter<int, 3> spc2 = spc;
    cout << "2";
    SharedPtrWithCounter<int, 3> spc3 = spc;
    cout << "3";

    try {
        SharedPtrWithCounter<int, 3> spc4 = spc;
    } catch(std::runtime_error& rn) {
        cout << "4"<< rn.what();
    }

}