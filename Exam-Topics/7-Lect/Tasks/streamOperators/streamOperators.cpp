#include <iostream>
#include <fstream>
using std::istream;
using std::ostream;
using std::cin;

struct A
{
    istream& operator>>(std::istream& is) {
        return is;
    }
};

int main() {
    A a;
    //cin >> a;
    a >> cin;
}
