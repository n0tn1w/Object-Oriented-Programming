#pragma once
#include <iostream>
#include <exception>
#include "UniquePointer.hpp"
#include "MyQueue.hpp"

using namespace std;

template<typename T>
class kPriorityQueue 
{
private:
	UniquePointer<MyQueue<T>*> queues = nullptr;
	size_t size;

	void checkIfIndexIsValid(size_t);

public:
	kPriorityQueue(size_t);
	~kPriorityQueue();

	void push(const T& obj, size_t);
	void push(T&& obj, size_t);
	void pop();

	const T& peek();

	MyQueue<T>& operator[](size_t);
	const MyQueue<T>& operator[](size_t) const;
	
};

template<typename T>
void kPriorityQueue<T>::checkIfIndexIsValid(size_t index)
{
	if (index < 0 || index >= this->size) {
		throw out_of_range("Error! No such priority!");
	}
}

template<typename T>
kPriorityQueue<T>::kPriorityQueue(size_t size) : queues(nullptr)
{
	this->size = size;

	if (size > 0) {
		this->queues.reset(new MyQueue<T>*[size] {nullptr} );
	}
	else {
		throw out_of_range("Invalid size!");
	}

}

template<typename T>
kPriorityQueue<T>::~kPriorityQueue()
{
	for (int i = 0; i < this->size; i++) {
		delete queues.get()[i];
	}
}

template <typename T>
void kPriorityQueue<T>::push(const T& obj, size_t index)
{
	checkIfIndexIsValid(index);
	MyQueue<T>* curr = queues.get()[index];
	if (curr == nullptr) {
		curr = new MyQueue<T>();
	}
	curr->push(obj);
}

template <typename T>
void kPriorityQueue<T>::push(T&& obj, size_t index)
{
	checkIfIndexIsValid(index);
	MyQueue<T>* curr = queues.get()[index];
	if (curr == nullptr) {
		curr = new MyQueue<T>();
	} 
	curr->push(obj);
	queues.get()[index] = curr;
}

template <typename T>
void kPriorityQueue<T>::pop()
{
	for (int i = this->size - 1; i >= 0; i--) {
		if (queues.get()[i] != nullptr && !queues.get()[i]->isEmpty()) {
			queues.get()[i]->pop();
			return;
		}
	}
}

template <typename T>
const T& kPriorityQueue<T>::peek()
{
	for (int i = this->size - 1; i >= 0; i--) {
		if (queues.get()[i] != nullptr && !queues.get()[i]->isEmpty()) {
			return queues.get()[i]->peek();
		}
	}
}

template<typename T>
MyQueue<T>& kPriorityQueue<T>::operator[](size_t index)
{
	return queues[index];
}

template<typename T>
const MyQueue<T>& kPriorityQueue<T>::operator[](size_t index) const 
{
	return queues[index];
}
