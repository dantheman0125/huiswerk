#pragma once
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Array
{
private:
	int size;
	int *arr;
	int itemsInArray;
public:
	Array(int size);
	~Array();

	void initRandom();
	void initIncrement();
	void bubbleSort(); //O(n^2)
	int binarySearch(int value);
	void mergesort();
	void quickSort(int left, int right);
};