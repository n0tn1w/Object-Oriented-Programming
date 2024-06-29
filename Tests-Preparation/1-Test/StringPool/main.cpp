#include <iostream>
using std::cout;
using std::endl;

#include "StringPool.h"

int main() {
    StringPool sp;

    const char* f1 = sp.getAllocatedString("br");
    const char** addressOfF1 = &f1;


    if(f1 == nullptr) {
        cout << "f1 is nullptr" << endl;
    } else {
        cout << f1 << endl;
    }

    const char* f2 = sp.getAllocatedString("br");
    const char** addressOfF2 = &f2;

    cout << "f1: " << f1 << ' ' << static_cast<const void*>(f1) << endl;
    cout << "f2: " << f2 << ' ' << static_cast<const void*>(f2) << endl;

    sp.releaseString("br");
    sp.releaseString("br");

    try {
    sp.releaseString("br");
    } catch(std::runtime_error& er) {
        cout << er.what() << endl;
    }
}