// array.cpp

#include "pch.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "array.h"
#include "..\..\..\..\Examples\array.h"

Array::Array(int size) {
    this->size = size;
    arr = new int[size];
    itemsInArray = 0;

    srand(time(0));
    initRandom();
}

Array::~Array() {
    delete [] arr;
}

void Array::initRandom()
{
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 1000 + 1;
    itemsInArray = size - 1; 
}

void Array::initIncrement()
{
    for (int i = 0; i < size; ++i)
        arr[i] = i;
    itemsInArray = size - 1;
}

// O(1)
void Array::addItem(int item) {
    arr[itemsInArray++] = item;
}

// O(n)
int Array::countOccurences(int value) {
    int sum = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i] == value) 
            sum++;
    return sum;
}

// O(n^2)
void Array::bubbleSort() {
    for (int i = size - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

// O(log n)
int Array::binarySearch(int value) {
    int lowIndex = 0;
    int highIndex = size;

    while (lowIndex <= highIndex) {
        int middleIndex = (highIndex + lowIndex) / 2;

        if (arr[middleIndex] < value)
            lowIndex = middleIndex + 1;
        else if (arr[middleIndex] > value)
            highIndex = middleIndex - 1;
        else
            return middleIndex;
    }
    return -1;
}

// O(n log n)
void Array::mergesort() {
    std::stable_sort(arr,arr+size);
}

void Array::quickSort(int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	// partition
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	// recursion
	if (left < j)
		quickSort(left, j);
	if (i < right)
		quickSort(i, right);
}
