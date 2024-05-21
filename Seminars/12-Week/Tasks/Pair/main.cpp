#include <iostream>
#include "Pair.hpp"

using std::cout;
using std::endl;
using std::cin;

int main() {
    Pair<int, double> p(1, 2.2);
    cout << p.getFirst() << " " << p.getSecond();
}