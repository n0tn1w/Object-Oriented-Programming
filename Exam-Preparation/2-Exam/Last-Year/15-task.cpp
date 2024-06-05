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

void add(A** Arr,A&& obj, unsigned ind) {
    if(Arr[ind] != nullptr)
        delete Arr[ind];
    Arr[ind] = new A(std::move(obj));
}    

void add2(A** arr,A&& obj, unsigned ind) {
    //if(arr[ind] != nullptr) {
        *arr[ind] = std::move(obj);
    //} else {
        arr[ind] = new A(std::move(obj));
    //}
}

int main() {
    A** arr = new A*[3] {nullptr} ;
    //arr[1] = new A();

    //cout << "Func" << endl;
    //add(arr, A(), 1);

    //cout << "New Func" << endl;
    add2(arr, A(), 1);
}
