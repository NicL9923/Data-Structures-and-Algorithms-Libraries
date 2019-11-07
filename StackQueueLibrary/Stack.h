/*
-----Stack-----
A library/class about stacks and various methods
to manipulate/traverse them.

Notes:
-

Created by Nicolas Layne (11/2019)
*/

#pragma once
#include <iostream>

template <class type>
class Stack {
private:
	int* stackArray, size, index;

public:
	Stack();
	~Stack();

	void push();
	void pop();
	type top();
	bool isEmpty();
};

template <class type>
Stack<type>::Stack() {
	stackArray = new int[10];
	size = 10;
	index = 0;
}

template <class type>
Stack<type>::~Stack() {
	delete[] stackArray;
}