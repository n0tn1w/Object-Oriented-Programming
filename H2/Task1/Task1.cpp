#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    MyString my("@aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa@");
    cout << my;
    MyString my2("bbb");
    my2 += "wfawf";
    cin >> my;

    cout << my << endl;
    cout << my2;
    cin >> my;
    cout << my << endl;
}
