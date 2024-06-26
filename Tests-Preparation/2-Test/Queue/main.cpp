#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Queue.hpp"

int main() {
    Queue<int> q;
    q.push_back(1);
    q.push_back(2);

    cout << q.peek();
    q.pop();
    cout << q.isEmpty();
    cout << q.peek();
    q.pop();
    cout << q.isEmpty();
    q.push_back(3);
    cout << q.peek();
    q.pop();
    cout << q.isEmpty();

}