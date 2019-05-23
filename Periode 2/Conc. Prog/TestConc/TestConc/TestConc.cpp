// TestConc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>
#include <time.h>
#include <stdio.h>

std::mutex vectLock;
std::vector<unsigned int> primeVect;

void FindPrimes(unsigned int start,
	unsigned int end) {

	// Cycle through numbers while ignoring evens
	for (unsigned int x = start; x <= end; x += 2) {

		// If a modulus is 0 we know it isn't prime
		for (unsigned int y = 2; y < x; y++) {
			if ((x % y) == 0) {
				break;
			}
			else if ((y + 1) == x) {
				vectLock.lock();
				primeVect.push_back(x);
				vectLock.unlock();
			}
		}
	}
}

void FindPrimesWithThreads(unsigned int start,
	unsigned int end,
	unsigned int numThreads) {

	std::vector<std::thread> threadVect;

	// Divide up the calculation so each thread
	// operates on different primes
	unsigned int threadSpread = end / numThreads;
	unsigned int newEnd = start + threadSpread - 1;

	// Create prime list for each thread
	for (unsigned int x = 0; x < numThreads; x++) {
		threadVect.emplace_back(FindPrimes,
			start, newEnd);

		start += threadSpread;
		newEnd += threadSpread;
	}

	for (auto& t : threadVect) {
		t.join();
	}

}

int main()
{
	// Get time before code starts executing
	int startTime = clock();

	FindPrimesWithThreads(1, 100000, 12);

	// Get time after execution
	int endTime = clock();

	//for (auto i : primeVect)
	//	std::cout << i << "\n";

	// Print out the number of seconds
	std::cout << "Execution Time : " <<
		(endTime - startTime) / double(CLOCKS_PER_SEC)
		<< std::endl;

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
