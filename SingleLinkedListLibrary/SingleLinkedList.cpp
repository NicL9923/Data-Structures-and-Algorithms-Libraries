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

	Node* temp = head;
	Node* move, * nodePushedBack;

	//Node being moved is "removed" from its spot in the linked list
	for (int i = 0; i < (node - 2); i++) {
		temp = temp->next;
	}

	move = temp->next;
	temp->next = move->next;

	//Node being moved is then inserted at the specified place
	temp = head;
	for (int i = 0; i < (place - 2); i++) {
		temp = temp->next;
	}
	nodePushedBack = temp->next;
	move->next = nodePushedBack->next;
	temp->next = move;

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

//Sorting algorithms are going to be solely by node (not value) to be
//compatible with nodes that have >1 data member
void SingleLinkedList::sortLeastToGreat() {
	
}

void SingleLinkedList::sortGreatToLeast() {

}

void SingleLinkedList::reverse() {
	//Store pointers in array? Kinda doubt but TBE (To Be Explored)
}