#include <iostream>
using namespace std;

class  A
{
public:
    A() { cout << "A()" << endl;}
    A(const A&) {cout << "CC A()" << endl;}
    A(A&&) {cout << "MM A()" << endl;}
    A& operator=(const A&) {cout << "OP= A" << endl; return *this;}
    A& operator=(A&&) {cout << "MM OP= A" << endl; return *this;}
    ~ A() {cout << "~A()" << endl;}
};

void add(A** arr,A&& obj, unsigned ind) {
    if(arr[ind] != nullptr) {
        *arr[ind] = std::move(obj);
    } else {
        arr[ind] = new A(std::move(obj));
    }
}


int main() {
    A** arr = new A*[3] {nullptr} ;
    add(arr, A(), 1);
}
