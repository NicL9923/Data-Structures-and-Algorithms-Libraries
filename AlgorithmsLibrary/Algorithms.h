#pragma once
/*
-----Array Sorts-----
A library/class about sorting algorithms performed
on arrays.

Notes:
-Yes I know the arguments are unecessary, it's there
for learning purposes

Created by Nicolas Layne (11/2019)
*/

#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>

class Algorithms {
private:
	std::vector<int> itemList;
	int listSize;

	void merge(std::vector<int> B, std::vector<int> C);
	void mergeSort(std::vector<int> A);
	void quickSort(int L, int R);
	int partition(int L, int R);

public:
	Algorithms(int size);
	~Algorithms();

	void assignRandomValues();
	void randomizeArrayOrder();

	void binarySearch(int val);

	void selectionSort();
	void bubbleSort();
	void insertionSort();
	void quickSort();
	void mergeSort();
};