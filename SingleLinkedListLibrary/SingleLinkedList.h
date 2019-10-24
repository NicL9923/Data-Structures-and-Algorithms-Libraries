/*
-----Single Linked Lists-----
A library/class about single linked lists and various methods
to manipulate/traverse them.

Notes:
-All linked lists start with one node (on instantiation, head pointer created and linked to first node)
-Parameters labeled as 'node' are the node's position in the list (Positions start at 1)

Created by Nicolas Layne (09/2019)
*/

#pragma once
#include <iostream>

class SingleLinkedList {
private:
	struct Node {
		int value;
		Node* next;
	};
	Node* head;

public:
	//Create head
	SingleLinkedList(int firstNodeValue);
	//Delete all nodes/entire list
	~SingleLinkedList();

	//Basic list operations
	void insertNodeFront(int value);
	void insertNodeBack(int value);
	void insertNodeAt(int node, int value);
	void removeNode(int node);
	void moveNode(int node, int place);
	void setNodeValue(int node, int value);
	void swapNodes(int node1, int node2);

	//Retrieving values
	int getNumberNodes();
	int getNodeValue(int node);
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