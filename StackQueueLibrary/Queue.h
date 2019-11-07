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
	int* queueArray, size, head, tail;

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
	queueArray = new int[10];
	size = 10;
	head = 0;
	tail = 0;
}

template <class type>
Queue<type>::~Queue() {
	delete[] queueArray;
}