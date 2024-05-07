#include <fstream>
#include "StringView.h"
#include "MyString.h"
#include <iostream>
using namespace std;

int main() {
    MyString ms("hello");
    cout << ms;
    StringView sv(ms);
    cout << sv.size() << endl;
    cout << sv;
}