#pragma once


class DoubleLinkedList {
private:
	struct Node {
		int value;
		Node *next, *prev;
	};

	Node* head;

public:
	DoubleLinkedList();
	~DoubleLinkedList();



};