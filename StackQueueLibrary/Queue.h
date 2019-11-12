/*
-----Queue-----
A library/class about queues and various methods
to manipulate/traverse them.

Notes:
-

Created by Nicolas Layne (11/2019)
*/

#pragma once
#include <iostream>

template <class type>
class Queue {
private:
	type* queueArray;
	int size, head, tail;

public:
	Queue();
	~Queue();

	void push();
	void pop();
	type front();
	bool isEmpty();
};

template <class type>
Queue<type>::Queue() {
	queueArray = new type[10];
	size = 10;
	head = 0;
	tail = 0;
}

template <class type>
Queue<type>::~Queue() {
	delete[] queueArray;
}

template <class type>
void Queue<type>::push() {
	queueArray[tail] = value;
	tail = (tail + 1) % size;

	if (tail == head) {
		type* resizedArray = new type[size * 2];

		for (int i = 0; i < size; i++) {
			resizedArray[i] = queueArray[head];
			head = (head + 1) % size;
		}

		delete[] queueArray;
		queueArray = resizedArray;
		tail = size;
		size *= 2;
		head = 0;
	}
}

template <class type>
void Queue<type>::pop() {
	if (!isEmpty())
		head++;
}

template <class type>
type Queue<type>::front() {
	return queueArray[head];
}

template <class type>
bool Queue<type>::isEmpty() {
	return (head == tail);
}