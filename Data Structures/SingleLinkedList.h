/*
-----Single Linked Lists-----
A library/class about single linked lists and various methods
to manipulate/traverse them.

Notes:
-All linked lists start with one node (on instantiation, head pointer created and linked to first node)
-Parameters labeled as 'node' are the node's position in the list (Positions start at 1)
-TODO: edge cases (empty list, etc.)

Created by Nicolas Layne (09/2019)
*/

#pragma once
#include <iostream>

template <class type>
class SingleLinkedList {
private:
	struct Node {
		type value;
		Node* next;
	};
	Node* head;

public:
	//Initialize head
	SingleLinkedList(type firstNodeValue);
	//Delete all nodes/entire list
	~SingleLinkedList();

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
	Node* getHeadNode();

	//Various sorting things
	void reverse();
	void mergeSort();
	void selectionSort();
	void bubbleSort();
	void insertionSort();
	void quickSort();

};

template <class type>
SingleLinkedList<type>::SingleLinkedList(type firstNodeValue) {
	head = new Node;
	head->next = nullptr;
	head->value = firstNodeValue;
}

template <class type>
SingleLinkedList<type>::~SingleLinkedList() {
	Node* temp = head;

	while (temp != nullptr) {
		head = temp;
		delete head;
		temp = temp->next;
	}
}

template <class type>
void SingleLinkedList<type>::insertNodeFront(type value) {
	Node* insert = new Node;
	insert->value = value;

	insert->next = head;
	head = insert;
}

template <class type>
void SingleLinkedList<type>::insertNodeBack(type value) {
	Node* temp = head;
	Node* insert = new Node;
	insert->value = value;

	while (temp->next != nullptr) {
		temp = temp->next;
	}

	temp->next = insert;
	insert->next = nullptr;
}

template <class type>
void SingleLinkedList<type>::insertNodeAt(int node, type value) {
	Node* temp = head;
	Node* insert = new Node;
	insert->value = value;

	if (head->next == nullptr) {
		head->next = insert;
		insert->next = nullptr;
		return;
	}

	for (int i = 0; i < (node - 2); i++) {
		temp = temp->next;
	}

	insert->next = temp->next;
	temp = insert;

}

template <class type>
void SingleLinkedList<type>::removeNode(int node) {
	Node* temp = head;
	Node* remove;

	for (int i = 0; i < (node - 2); i++)
		temp = temp->next;

	remove = temp->next;
	temp->next = remove->next;

	delete remove;
}

template <class type>
void SingleLinkedList<type>::moveNode(int node, int place) {

	Node* temp = head;
	Node* move, * nodePushedBack;

	//Node being moved is "removed" from its spot in the linked list
	for (int i = 0; i < (node - 2); i++)
		temp = temp->next;

	move = temp->next;
	temp->next = move->next;

	//Node being moved is then inserted at the specified place
	temp = head;
	for (int i = 0; i < (place - 2); i++)
		temp = temp->next;

	nodePushedBack = temp->next;
	move->next = nodePushedBack;
	temp->next = move;

}

template <class type>
void SingleLinkedList<type>::setNodeValue(int node, type value) {
	Node* temp = head;

	for (int i = 0; i < (node - 1); i++)
		temp = temp->next;

	temp->value = value;
}

template <class type>
void SingleLinkedList<type>::swapNodes(int node1, int node2) {
	//Swaps the nodes at 2 given positions
	//Edge cases: if a given node is head or tail
}

template <class type>
int SingleLinkedList<type>::getNumberNodes() {
	Node* temp = head;
	int nodeCounter = 1;

	while (temp->next != nullptr) {
		nodeCounter++;
		temp = temp->next;
	}

	return nodeCounter;
}

template <class type>
type SingleLinkedList<type>::getNodeValue(int node) {
	Node* temp = head;

	for (int i = 0; i < (node - 1); i++)
		temp = temp->next;

	return temp->value;
}

template <class type>
void SingleLinkedList<type>::printList() {
	Node* temp = head;

	std::cout << "Printing list..." << std::endl;

	while (temp != nullptr) {
		std::cout << temp->value << std::endl;
		temp = temp->next;
	}
}

template <class type>
SingleLinkedList<type>::Node* SingleLinkedList<type>::getHeadNode() {
	return head;
}

template <class type>
void SingleLinkedList<type>::reverse() {
	Node* temp = head;
	Node* prev = nullptr;
	Node* current = nullptr;

	while (temp != nullptr) {
		//Keep track of where we are in the list
		current = temp;
		temp = temp->next;

		//Reverse the pair of nodes as it goes down the list to completion
		current->next = prev;
		prev = current;
		head = current;
	}
}

template <class type>
void SingleLinkedList<type>::mergeSort() {

}

template <class type>
void SingleLinkedList<type>::selectionSort() {

}

template <class type>
void SingleLinkedList<type>::bubbleSort() {

}

template <class type>
void SingleLinkedList<type>::insertionSort() {

}

template <class type>
void SingleLinkedList<type>::quickSort() {

}