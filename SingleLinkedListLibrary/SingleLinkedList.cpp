#include "SingleLinkedList.h"

//Possible TODO: Constructor parameter to init list with certain number of nodes
SingleLinkedList::SingleLinkedList() {
	head = new Node;
	head->next = nullptr;
}

SingleLinkedList::~SingleLinkedList() {
	Node* temp = head;

	while (temp != nullptr) {
		head = temp;
		delete head;
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

void SingleLinkedList::insertNodeAt(int node) {
	Node* temp = head;
	Node* insert = new Node;

	for (int i = 0; i < (node - 2); i++) {
		temp = temp->next;
	}
	
	insert->next = temp->next;
	temp = insert;


}

void SingleLinkedList::removeNode(int node) {
	Node* temp = head;
	Node* remove;

	for (int i = 0; i < (node - 2); i++)
		temp = temp->next;

	remove = temp->next;
	temp->next = remove->next;
	
	delete remove;
}

void SingleLinkedList::moveNode(int node, int place) {
	//Probably just combining remove and then insert at operations
	//Dont quote me on that, haven't thought it through at all yet
}

void SingleLinkedList::setNodeValue(int node, int value) {
	Node* temp = head;

	for (int i = 0; i < (node - 1); i++)
		temp = temp->next;

	temp->value = value;
}

int SingleLinkedList::getNumberNodes() {
	Node* temp = head;
	int nodeCounter = 1;

	while (temp != nullptr) {
		nodeCounter++;
		temp = temp->next;
	}

	return nodeCounter;
}

int SingleLinkedList::getNodeValue(int node) {
	Node* temp = head;

	for (int i = 0; i < (node - 1); i++)
		temp = temp->next;

	return temp->value;
}

void SingleLinkedList::sortLeastToGreat() {
	//Possible routes:
	//*Have to create new linked list for sorted values?

	//Could just be a matter of moving values, no need to move addresses?
}

void SingleLinkedList::sortGreatToLeast() {

}

void SingleLinkedList::reverse() {
	//Reverse by values and reverse by nodes (pointers)
	//Value Method: store values in array and iterate through all nodes assigning array values
	//Same could work for pointers? Store pointers in array? Kinda doubt but TBE (To Be Explored)
}