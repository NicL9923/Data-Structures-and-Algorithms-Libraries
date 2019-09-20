#include "SingleLinkedList.h"
#include <iostream>


int main() {
	SingleLinkedList list1;

	list1.insertNodeAt(2);
	list1.insertNodeFront();

	std::cout << list1.getNumberNodes() << std::endl;

	std::cin.get();
	return 0;
}