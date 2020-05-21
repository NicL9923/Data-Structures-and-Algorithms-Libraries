/*
-----Double Linked Lists-----
My recreation of doubly linked lists and various methods
to manipulate/traverse them.
-Nicolas Layne (11/2019)

Notes:
-All linked lists start with one node (on instantiation, head pointer created and linked to first node)
-Parameters labeled as 'node' are the node's position in the list (Positions start at 1)

-TODO: Implement a 'tail' pointer to make insertNodeBack and other operations
a little more efficient
-TODO: edge cases (empty list, etc.)
*/

#pragma once
#include <iostream>

template<class type>
class DoubleLinkedList {
private:
	struct Node {
		type value;
		Node* prev, * next;
	};
	Node* head;

public:
	//Initialize head
	DoubleLinkedList(type firstNodeValue);
	//Delete all nodes/entire list
	~DoubleLinkedList();

	//Basic list operations
	void insertNodeFront(type value);
	void insertNodeBack(type value);
	void insertNodeAt(int node, type value);
	void removeNode(int node);
	void moveNode(int node, int place);
	void setNodeValue(int node, type value);
	void swapNodes(int node1, int node2);

	//Retrieving values
	int getNumberNodes();
	type getNodeValue(int node);
	void printList();

};

template<class type>
DoubleLinkedList<type>::DoubleLinkedList(type firstNodeValue) {
	head = new Node;
	head->value = firstNodeValue;
	head->next = nullptr;
	head->prev = nullptr;
}

template<class type>
DoubleLinkedList<type>::~DoubleLinkedList() {
	Node* temp = head;

	while (temp != nullptr) {
		head = temp;
		delete head;
		temp = temp->next;
	}
}

template<class type>
void DoubleLinkedList<type>::insertNodeFront(type value) {
	Node* insert = new Node;
	insert->value = value;
	insert->prev = head;
	
	insert->next = head;
	head = insert;
}

template<class type>
void DoubleLinkedList<type>::insertNodeBack(type value) {
	Node* temp = head;
	Node* insert = new Node;
	insert->value = new Node;
	insert->next = nullptr;

	while (temp->next != nullptr) {
		temp = temp->next;
	}

	temp->next = insert;
	insert->prev = temp;
}

template<class type>
void DoubleLinkedList<type>::insertNodeAt(int node, type value) {
	Node* temp = head;
	Node* insert = new Node;
	insert->value = value;

	for (int i = 0; i < node - 2; i++)
		temp = temp->next;

	insert->next = temp->next;
	temp = insert;
	insert->prev = temp;
}

template<class type>
void DoubleLinkedList<type>::removeNode(int node) {
	Node* temp = head;
	Node* remove;

	for (int i = 0; i < node - 2; i++)
		temp = temp->next;

	remove = temp->next;
	temp->next = remove->next;
	delete remove;
}

template<class type>
void DoubleLinkedList<type>::moveNode(int node, int place) {

}

template<class type>
void DoubleLinkedList<type>::setNodeValue(int node, type value) {
	Node* temp = head;

	for (int i = 0; i < node - 1; i++)
		temp = temp->next;

	temp->value = value;
}

template<class type>
void DoubleLinkedList<type>::swapNodes(int node1, int node2) {
	//Swaps the nodes at 2 given positions
	//Edge cases: if a given node is head or tail
}

template<class type>
int DoubleLinkedList<type>::getNumberNodes() {
	//Could keep track of num nodes through object member but alas
	Node* temp = head;
	int nodeCount = 0;

	while (temp != nullptr) {
		nodeCount++;
		temp = temp->next;
	}

	return nodeCount;
}

template<class type>
type DoubleLinkedList<type>::getNodeValue(int node) {
	Node* temp = head;

	for (int i = 0; i < node - 1; i++)
		temp = temp->next;

	return temp->value;
}

template <class type>
void DoubleLinkedList<type>::printList() {
	Node* temp = head;

	while (temp != nullptr) {
		std::cout << temp->value << " ";
		temp = temp->next;
	}
	
	std::cout << std::endl;
}