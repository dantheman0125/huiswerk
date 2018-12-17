// Exercise_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int GetNum();
int GetNum(string txt);
int GetNum2(string txt = "insert a different number\n");

int main()
{
	int a = GetNum();
	int b = GetNum("insert another number\n");
	int c = GetNum2();
	int d = GetNum2("Number, please\n");
    
	cout << "This is your number " << a << "\n";
	cout << "This is your number " << b << "\n";
	cout << "This is your number " << c << "\n";
	cout << "This is your number " << d << "\n";
}

int GetNum( string txt) {
	int num;
	cout << txt;
	cin >> num;
	return num;
}

int GetNum() {
	int num;
	cout << "insert a number\n";
	cin >> num;
	return num;
}

int GetNum2(string txt) {
	int num;
	cout << txt;
	cin >> num;
	return num;
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
