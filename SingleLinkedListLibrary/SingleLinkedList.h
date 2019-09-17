/*
-----Single Linked Lists-----
A library/class about single linked lists and various methods
to manipulate/traverse them.

Notes:
-All linked lists start with one node (on instantiation, head pointer created and linked to first node)

Created by Nicolas Layne (09/2019)
*/

#pragma once

class SingleLinkedList {
private:
	struct Node {
		int value;
		Node* next;
	};
	Node* head;

public:
	//Create head
	SingleLinkedList();
	//Delete all nodes/entire list
	~SingleLinkedList();

	void insertNodeFront();
	void insertNodeBack();
	void insertNodeAt(int node);
	void removeNode(int node);
	void moveNode(int node, int place);
	
	void changeNodeValue(int node, int value);

	void sortLeastToGreat();

};