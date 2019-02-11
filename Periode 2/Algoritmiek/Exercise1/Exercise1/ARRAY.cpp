//array.cpp
#include "pch.h"
#include "ARRAY.h"

//DOE BUBBLESORT!!!!

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
	int c = a; a = b; b = c;
}

void Array::initRandom() {
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 1000 + 1;
	itemsInArray = size - 1;
}

void Array::quicksort(int low, int high){
	if (low < high) {
		int p = partition(low, high);
		quicksort(low, p);
		quicksort(p + 1, high);
	}
}

int Array::partition(int low, int high) {
	int pivot= arr[(low + high) / 2];
	int i = low - 1;
	int j = high + 1;
	for (; arr[i] < pivot; i++) {}
	for (; arr[j] > pivot; j--){}
	if (i >= j)
		return j;
	else {
		int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
		return i;
	}
}