#include <iostream>
using namespace std;

struct A
{
    char a;
    char b;
    //virtual void func() = 0;
    virtual ~A() = default;
};

struct B : A
{
    int c;
};

struct V
{
    virtual ~V() = default;
};

struct Anorm
{
   int a;
   char b;
};

struct Bnorm : Anorm {
    char c;
};

struct AC {
    double ch2;
    int ch1;

    virtual ~AC() = default;
};

struct BC : AC {
    bool ch1;
};



int main() {
    // cout << "A: " << sizeof(A) << endl;
    // cout << "B: " << sizeof(B) << endl;

    // cout << "V: " << sizeof(V) << endl;

    cout << sizeof(AC) << endl;

    cout << sizeof(BC);
}
