// Exercise_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	double num1, num2, num3;

	cout << "Calculate the average" << endl;
    cout << "Fill in 3 numbers\n"; 
	cout << "Number 1:  ";
	cin >> num1;
	cout << "Number 2:  ";
	cin >> num2;
	cout << "Number 3:  ";
	cin >> num3;
	cout << "\n1= " << num1 << " 2= " << num2 << " 3= " << num3 << endl;
	cout << "The average is: " << (num1+num2+num3)/3;
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
