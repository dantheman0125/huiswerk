// TheBigO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "array.h"

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

int main()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;

	for (int s = 0; s <= 20000000; s += 200000) {
		Array *arr = new Array(s);
		//arr->initIncrement(); // before using binarySearch
		start = std::chrono::system_clock::now();
		//arr->addItem(2); // O(1)
		//arr->countOccurences(2); // O(n)
		//arr->bubbleSort(); // O(n^2)
		//arr->binarySearch(2); // O(log n)
		arr->quickSort(0, s - 1);
		//arr->mergesort(); // O(n log n)
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout /*<< s << " " */<< elapsed_seconds.count() << std::endl;
		delete arr;
	}
}