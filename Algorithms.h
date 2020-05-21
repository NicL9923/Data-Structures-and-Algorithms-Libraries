#pragma once
/*
-----Algorithms-----
My recreation of various search and sort algorithms.
-Nicolas Layne (11/2019)
*/

#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>

class Algorithms {
private:
	std::vector<int> itemList;
	int listSize;

	void merge(std::vector<int> mergingVector, int L, int M, int R);
	void mergeSort(int L, int R);
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

Algorithms::Algorithms(int size) {
	listSize = size;

	for (int i = 0; i < listSize; i++) {
		itemList.push_back(rand() % 100 + 1);
	}
}

void Algorithms::assignRandomValues() {
	for (int i = 0; i < listSize; i++) {
		itemList[i] = rand() % 100 + 1;
	}
}

void Algorithms::randomizeArrayOrder() {
	for (int i = 0; i < listSize; i += 2) {
		std::swap(itemList[i], itemList[rand() % listSize]);
	}
}

void Algorithms::binarySearch(int val) {
	int L = 0;
	int R = itemList.size() - 1;

	while (L <= R) {
		int mid = (L + R) / 2;

		//We land on the value
		if (itemList[mid] == val) {
			std::cout << "The value " << val << " was found at index " << mid << std::endl;
			return;
		}

		//Continue the search in the half that has the value
		if (itemList[mid] > val) {
			R = mid - 1;
		}
		else {
			L = mid + 1;
		}
	}

	//If we don't find the value
	std::cout << "Value " << val << " was not found in the first array" << std::endl;
}

//Find index with smallest value then swap
void Algorithms::selectionSort() {
	int minIndex = 0;

	for (int i = 0; i < listSize - 1; i++) {
		for (int j = i + 1; j < listSize; j++) {
			if (itemList[j] < itemList[minIndex]) {
				minIndex = j;
			}
		}
		std::swap(itemList[i], itemList[minIndex]);
	}
}

//Compares two values in 'bubbles' that travels
//the length of the array
void Algorithms::bubbleSort() {
	for (int i = 0; i < listSize - 1; i++) {
		for (int j = 0; j < listSize - i - 1; j++) {
			if (itemList[j] > itemList[j + 1]) {
				std::swap(itemList[j], itemList[j + 1]);
			}
		}
	}
}

//Builds a sorted list on left as it scans array to right
void Algorithms::insertionSort() {
	int key, j;

	for (int i = 1; i < listSize; i++) {
		key = itemList[i];
		j = i - 1;

		while (j >= 0 && itemList[j] > key) {
			itemList[j + 1] = itemList[j];
			j--;
		}
		itemList[j + 1] = key;
	}
}

//Uses a pivot to continually break array into
//sorted halves (less on left of pivot, and vice versa)
void Algorithms::quickSort() {
	int L = 0;
	int R = listSize - 1;

	if (L < R) {
		int pivot = partition(L, R);

		quickSort(L, pivot - 1);
		quickSort(pivot + 1, R);
	}
}

void Algorithms::quickSort(int L, int R) {
	if (L < R) {
		int pivot = partition(L, R);

		quickSort(L, pivot - 1);
		quickSort(pivot + 1, R);
	}
}

int Algorithms::partition(int L, int R) {
	int pivot = itemList[L];
	int i = L;
	int j = R + 1;

	while (i < j) {
		do {
			i++;
		} while (itemList[i] < pivot);

		do {
			j--;
		} while (itemList[j] > pivot);

		std::swap(itemList[i], itemList[j]);
	}

	std::swap(itemList[i], itemList[j]);
	std::swap(itemList[L], itemList[j]);

	return j;
}

//Breaks down array into single nodes then merges/sorts
//back up to completely sorted array
void Algorithms::mergeSort() {
	mergeSort(0, listSize - 1);
}

void Algorithms::mergeSort(int L, int R) {
	if (L < R) {
		int M = (L + R) / 2;
		std::vector<int> mergingVector = itemList;

		mergeSort(L, M);
		mergeSort(M + 1, R);
		merge(mergingVector, L, M, R);
	}
}

void Algorithms::merge(std::vector<int> mergingVector, int L, int M, int R) {
	int i = L, j = M + 1, k = L;

	//Compare the two sorted subarrays and put them into sorted 'b' array
	while (i <= M && j <= R) {
		if (itemList[i] < itemList[j]) {
			mergingVector[k] = itemList[i];
			i++; k++;
		}
		else {
			mergingVector[k] = itemList[j];
			j++; k++;
		}
	}

	//Once all comparisons are done, add the remaining values of the larger array
	while (i <= M) {
		mergingVector[k] = itemList[i];
		i++; k++;
	}
	while (j <= R) {
		mergingVector[k] = itemList[j];
		j++; k++;
	}

	//Copy all values over
	for (int i = L; i <= R; i++) {
		itemList[i] = mergingVector[i];
	}
} 