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
	void quicksort(int low, int high); //O(n^2)
	int partition(int low, int high); //O(n^2)
};