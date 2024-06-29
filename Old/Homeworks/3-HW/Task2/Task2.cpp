// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "kPriorityQueue.hpp"
using namespace std;

int main()
{
	kPriorityQueue<char> q(4); // 4 priorities - 0, 1, 2 è 3.

	q.push('A', 0); //adds A with lowest priority: 0
	q.push('B', 3);
	q.push('C', 2);
	q.push('D', 2);
	q.push('E', 1); 
	try
	{
		q.push('F', 5); //error! No such priority!
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	cout << q.peek() << endl; // B
	q.pop();

	cout << q.peek() << endl; // C
	q.pop();

	cout << q.peek() << endl; // D
	q.pop();

	cout << q.peek() << endl; // E
	q.pop();

	cout << q.peek() << endl; // A
	q.pop();

}


