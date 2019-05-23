//array.cpp
#include "pch.h"
#include "ARRAY.h"

Array::Array(int size)
{
	this->size = size;
	arr = new int[size];
	itemsInArray = 0;

	srand(time(0));
	initRandom();
}

Array::~Array()
{
	delete [] arr;
}

void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

void Array::initIncrement()
{
    for (int i = 0; i < size; ++i)
        arr[i] = i;
    itemsInArray = size - 1;
}

void Array::initRandom() {
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 1000 + 1;
	itemsInArray = size - 1;
}

void Array::bubbleSort() {
    for (int i = size - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j+1]) 
				swap(arr[j], arr[j + 1]);
}

// O(log n)
int Array::binarySearch(int value) {
	int low = 0;
	int high = size;

	while (low <= high) {
		int mid = (high + low) / 2;
		if (arr[mid] < value)
			low = mid + 1;
		else if (arr[mid] > value)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

// O(n log n)
void Array::mergesort() {
	std::stable_sort(arr, arr + size);
}

// O(n log n)
void Array::quickSort(int low, int high) {
	int i = low, j = high;
	int tmp;
	int pivot = arr[(low + high) / 2];

	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) 
			swap(arr[i++],arr[j--]); 
	};

	if (low < j)
		quickSort(low, j);
	if (i < high)
		quickSort(i, high);
}