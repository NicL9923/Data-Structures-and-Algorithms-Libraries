#include "SingleLinkedList.h"

//Possible TODO: Constructor parameter to init list with certain number of nodes
SingleLinkedList::SingleLinkedList() {
	head = new Node;
	head->next = nullptr;
}

SingleLinkedList::~SingleLinkedList() {
	Node* temp = head;
	Node* remove;

	while (temp != nullptr) {
		remove = temp;
		delete remove;
		temp = temp->next;
	}
}

//TODO: (optional?) parameter to set value of the new node
void SingleLinkedList::insertNodeFront() {
	Node* temp = head;
	Node* insert = new Node;

	insert->next = head;
	head = insert;
}

void SingleLinkedList::insertNodeBack() {
	Node* temp = head;
	Node* insert = new Node;

	while (temp != nullptr) {
		temp = temp->next;
	}

	temp = insert;
	insert->next = nullptr;
}

//TODO
void SingleLinkedList::insertNodeAt(int node) {
	Node* temp = head;
	Node* insert = new Node;

	for (int i = 0; i < node) {
		temp = temp->next;
	}

}

void SingleLinkedList::removeNode(int node) {

}

void SingleLinkedList::moveNode(int node, int place) {

}

void SingleLinkedList::changeNodeValue(int node, int value) {

}

int SingleLinkedList::getNumberNodes() {

}

int SingleLinkedList::getNodeValue(int node) {

}

int SingleLinkedList::getAllValues() {

}

void SingleLinkedList::sortLeastToGreat() {
	//Possible routes:
	//*Have to create new linked list for sorted values?

	//Could just be a matter of moving values, no need to move addresses?
}

void SingleLinkedList::sortGreatToLeast() {

}

void SingleLinkedList::reverse() {

}