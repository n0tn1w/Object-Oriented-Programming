#include <iostream>
#include <utility>
using namespace std;

class A {
    
public:
    int data = 1;
    A();
    A(const A&) = delete;
    //A(A&&) = delete;
    //A& operator=(const A&) = delete;
    A& operator=(const A&) = default;
    //A& operator=(A&&) = default;


    //A(const A& oth) { cout << "CC of A" << endl; }
    //A& operator=(const A& oth) { cout << "OP= of A" << endl; return *this;}

    //A& operator=(A&&) { cout << "move OP= of A" << endl; return *this;}
};
A::A() { data = 2;}


int main() {

    A a;
    a.data = 2;
    
    //A(const A&) = delete; 
    A c;
    c = a;   // yes
    c = std::move(a);

    A g;
    A b(g); // no
    A d(std::move(g));

    //A& operator=(const A&) = delete;
    //A c;
    //c = a;   // no
    //c = std::move(a); // no
    //A b = a; // yes
    //A b = (std::move(a)); // yes

    
    //A(A&&) = delete;
    //A b(a);  // no
    //A b(std::move(a));  // no

    //A(const A&) = delete;
    //A b(a);  // no
    //A b(std::move(a)); //no


    //A(const A& oth) { cout << "CC of A" << endl; }
    //A c(std::move(a)); // CC of A


    //cout << b.data;
}