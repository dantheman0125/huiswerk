// Exercise_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <thread>
#include <vector>
#include <iostream>
#include <mutex>

using Vector = std::vector<int>;

struct DotProduct
{
	std::mutex	mutex;

	DotProduct(const Vector &a, const Vector &b) : a(a), b(b)
	{
		if (a.size() != b.size())
			throw "The vectors are of unequal length";
	}

	double operator()()
	{
		size_t nr_threads = 2;
		size_t length = a.size();

		int delta = length / nr_threads;
		int remainder = length % nr_threads;
		int L = 0, R = 0;

		result = 0;

		// Create threads
		for (int i = 0; i < nr_threads; ++i) {
			R = L + delta;
			if (i == nr_threads - 1)
				R += remainder;
			workers.push_back(std::thread(&DotProduct::partial_dot_product, this, L, R));
			L = R;
		}
		// Join threads
		for (auto &thread : workers) {
			thread.join();
		}

		return result;
	}

private:
	const Vector &a;
	const Vector &b;

	std::vector<std::thread> workers;
	int result;

	void partial_dot_product(int L, int R)
	{
		std::lock_guard<std::mutex> guard(mutex);
		for (int i = L; i < R; ++i) {
			result += a[i] * b[i];
		}
	}

};

int main()
{
	int nr_elements = 100000;

	// Fill two vectors with some values 
	Vector v1(nr_elements, 1), v2(nr_elements, 2);

	// Create Functor object
	DotProduct dp(v1, v2);

	// Print the result
	std::cout << dp() << std::endl;

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
