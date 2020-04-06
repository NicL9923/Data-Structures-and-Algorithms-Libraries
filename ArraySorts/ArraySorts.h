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

class ArraySorts {
private:
	int* arr, * arr2, size;
	void merge(int a[], int b[], int L, int M, int R);
public:
	ArraySorts();
	~ArraySorts();

	void assignValues();
	void randomizeArray();

	void binarySearch(int a[], int L, int R, int val);

	void selectionSort();
	void bubbleSort();
	void quickSort(int a[], int L, int R);
	void mergeSort(int a[], int b[], int L, int R);
};

ArraySorts::ArraySorts() {
	size = 10;
	arr = new int[size];
	arr2 = new int[size];
}

ArraySorts::~ArraySorts() {
	delete[] arr;
	delete[] arr2;
}

void ArraySorts::assignValues() {

}

//Unsorts array
void ArraySorts::randomizeArray() {

}

void ArraySorts::binarySearch(int a[], int L, int R, int val) {
	if (L <= R) {
		int mid = (L + R) / 2;

		//We find the value
		if (a[mid] == val) {
			std::cout << "The value " << val << " was found at index " << mid << std::endl;
			return;
		}
		//Continue the search in the half that will have the value
		if (a[mid] > val)
			binarySearch(a, L, mid - 1, val);
		else
			binarySearch(a, mid + 1, R, val);
	}

	//If we don't find the value
	std::cout << "Value " << val << " was not found in the first array" << std::endl;
}

//Find index with smallest value then swap
void ArraySorts::selectionSort() {
	int minIndex = 0;
	
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}

//Compares two values in 'bubbles' that travels
//the length of the array
void ArraySorts::bubbleSort() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1];
			}
		}
	}
}

//Builds a sorted list on left as it scans array to right
void ArraySorts::insertionSort() {
	int key, j;

	for (int i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

//Uses a pivot to continually break array into
//sorted halves (less on left of pivot, and vice versa)
void ArraySorts::quickSort(int a[], int L, int R) {
	int pivot = a[L]; //Rule 1 (Initialize pivot, L, and R)
	int left = L, right = R;

	while (L < R) {
		//Confirm that L < R so stuff doesn't break
		//Rule 2
		while (pivot <= a[R] && L < R) {
			R--;
		}

		//Rule 3
		if (pivot > a[R]) {
			a[L] = a[R];
			L++;
		}

		//Rule 4
		while (pivot >= a[L] && L < R) {
			L++;
		}

		//Rule 5
		if (pivot < a[L]) {
			a[R] = a[L];
			R--;
		}
	}
	a[L] = pivot; //Rule 6 (Break loop if/when L == R, and insert pivot)

	//Rule 7 (If subarrays to left and right of pivot have > 1 num,
	//repeat the process until there's only 1 or 0 nums in a given subarray))
	if (left < L - 1) {
		quickSort(a, left, L - 1);
	}

	if (R + 1 < right) {
		quickSort(a, R + 1, right);
	}
}

//Breaks down array into single nodes then merges/sorts
//back up to completely sorted array
void ArraySorts::mergeSort(int a[], int b[], int L, int R) {
	if (L < R) {
		int M = (L + R) / 2;
		mergeSort(a, b, L, M);
		mergeSort(a, b, M + 1, R);
		merge(a, b, L, M, R);
	}
}

void ArraySorts::merge(int a[], int b[], int L, int M, int R) {
	int i = L, j = M + 1, k = L;

	//Compare the two sorted subarrays and put them into sorted 'b' array
	while (i <= M && j <= R) {
		if (a[i] < a[j]) {
			b[k] = a[i];
			i++; k++;
		}
		else {
			b[k] = a[j];
			j++; k++;
		}
	}

	//Once all comparisons are done, add the remaining values of the larger array
	while (i <= M) {
		b[k] = a[i];
		i++; k++;
	}
	while (j <= R) {
		b[k] = a[j];
		j++; k++;
	}

	//Copy all values over
	for (int i = L; i <= R; i++) {
		a[i] = b[i];
	}
}
