#include "SingleLinkedList.h"
#include <iostream>


int main() {
	SingleLinkedList list1(1);
	list1.printList();

	list1.insertNodeAt(2, 5);
	list1.printList();

	list1.insertNodeFront(79);
	list1.printList();

	list1.insertNodeBack(40);
	list1.printList();

	list1.reverse();
	list1.printList();

	//list1.mySortLeastToGreat();

	std::cout << "Number of nodes in list: " << list1.getNumberNodes() << std::endl;

	std::cin.get();
	return 0;
}