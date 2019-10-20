#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList(int firstNodeValue) {
	head = new Node;
	head->next = nullptr;
	head->value = firstNodeValue;
}

SingleLinkedList::~SingleLinkedList() {
	Node* temp = head;

	while (temp != nullptr) {
		head = temp;
		delete head;
		temp = temp->next;
	}
}

void SingleLinkedList::insertNodeFront(int value) {
	Node* insert = new Node;
	insert->value = value;

	insert->next = head;
	head = insert;
}

void SingleLinkedList::insertNodeBack(int value) {
	Node* temp = head;
	Node* insert = new Node;
	insert->value = value;

	while (temp->next != nullptr) {
		temp = temp->next;
	}

	temp->next = insert;
	insert->next = nullptr;
}

void SingleLinkedList::insertNodeAt(int node, int value) {
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

void SingleLinkedList::swapNodes(int node1, int node2) {
	//Swaps the nodes at 2 given positions
	//Edge cases: if a given node is head or tail
}

int SingleLinkedList::getNumberNodes() {
	Node* temp = head;
	int nodeCounter = 1;

	while (temp->next != nullptr) {
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

void SingleLinkedList::printList() {
	Node* temp = head;

	std::cout << "Printing list..." << std::endl;

	while (temp != nullptr) {
		std::cout << temp->value << std::endl;
		temp = temp->next;
	}
}

SingleLinkedList::Node* SingleLinkedList::getHeadNode() {
	return head;
}

//My take on sorting a linked list prior to knowledge of common sorting algorithms
void SingleLinkedList::mySortLeastToGreat() {
	Node* temp = head;
	int position = 1;

	while (temp != nullptr) {
		if (temp->next == nullptr || temp->next->next == nullptr)
			break;
		if (temp->value > temp->next->value)
			moveNode(position + 1, position);

		temp = temp->next;
		position++;
	}
}

void SingleLinkedList::reverse() {
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

void SingleLinkedList::mergeSort() {

}

void SingleLinkedList::selectionSort() {

}

void SingleLinkedList::bubbleSort() {

}

void SingleLinkedList::insertionSort() {

}

void SingleLinkedList::quickSort() {

}

