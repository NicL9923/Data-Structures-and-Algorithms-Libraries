#include "Algorithms.h"

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
		std::swap(itemList[i], itemList[rand() % listSize];
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
			j++;
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
	mergeSort(itemList);
}

void Algorithms::mergeSort(std::vector<int> A) {
	if (listSize > 1) {
		std::vector<int> B;
		std::vector<int> C;

		for (int i = 0; i < listSize; i++) {
			if (i < num / 2) {
				B.push_back(itemList[i]);
			}
			else if (i >= num / 2) {
				C.push_back(itemList[i]);
			}
		}

		mergeSort(B);
		mergeSort(C);
		merge(list, num / 2, B, num - (num / 2), C);
	}
}

void Algorithms::merge(std::vector<int> B, std::vector<int> C) {
	int i = 0, j = 0, k = 0;
	int n = B.size();
	int m = C.size();

	while (i < n && j < m) {
		if (B[i] <= C[j]) {
			A[k] = B[i];
			i++;
		}
		else {
			A[k] = C[j];
			j++;
		}
		k++;
	}

	if (i == n) {
		while (j < m) {
			A[k] = C[j];
			k++; j++;
		}
	}
	else {
		while (i < n) {
			A[k] = B[i];
			k++; i++;
		}
	}
}