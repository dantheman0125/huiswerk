// Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "ARRAY.h"
#include <iostream>
#include <chrono>

int main()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;
    
	for (int s = 10; s < 2000; s += 10) {
		Array * arr = new Array(s);
		start = std::chrono::system_clock::now();
		arr->quicksort(0, s - 1);
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << s << " " << elapsed_seconds.count() << std::endl;
		//for (int i = 0; arr[i] < s; i++) {
			//std::cout << i << "	"; //<< arr[i];
		//}
		delete arr;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
