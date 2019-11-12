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
	type* stackArray;
	int size, index;

public:
	Stack();
	~Stack();

	void push(type value);
	void pop();
	type top();
	bool isEmpty();
};

template <class type>
Stack<type>::Stack() {
	stackArray = new type[10];
	size = 10;
	index = 0;
}

template <class type>
Stack<type>::~Stack() {
	delete[] stackArray;
}

template <class type>
void Stack<type>::push(type value) {
	stackArray[index] = value;
	index++;
	
	if (index == size) {
		type* resizedArray = new type[size * 2];

		for (int i = 0; i < size; i++)
			resizedArray[i] = stackArray[i];

		delete[] stackArray;
		size *= 2;
		stackArray = resizedArray;
	}
}

template <class type>
void Stack<type>::pop() {
	if (!isEmpty())
		index--;
}

template <class type>
type Stack<type>::top() {
	return stackArray[index];
}

template <class type>
bool Stack<type>::isEmpty() {
	return (index == 0);
}