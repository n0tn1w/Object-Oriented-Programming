#include <iostream>
#include "Stack.hpp"
using std::cout;
using std::endl;
using std::cin;

int main() {

    Stack<int, 3> st;

    st.push(6);
    st.push(7);
    st.push(8);

    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.isEmpty();
}