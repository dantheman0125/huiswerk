// Exercise_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype> //For toupper and tolower function.

using namespace std;

int main()
{
	vector<string>::iterator myIterator;
	vector<string>::const_iterator iter;
	int num;
	char inputc;
	int inputi;
	string inputs;

	vector<string> games;
	games.push_back("Counter-Strike: Global Offensive");
	games.push_back("Assassin's Creed Origins");
	games.push_back("METAL GEAR SOLID V: THE PHANTOM PAIN");
	games.push_back("Watch_Dogs 2");
	games.push_back("Sid Meier's Civilization 6");
	
	void showlist(); {
		cout << "Your current list is:\n";
		for (string s : games) {

			cout << num << ": " << s << "\n";
			num++;
		}
	}

	cout << "\t\t\tWelcome to the Game Rating System (GRS)!\n\n";
	cout << "\n";
	cout << "Enter 'help' to show the options.\n\n";

	num = 1;
	cout << "Enter 'H' to show Help.\n\n";
	cin >> inputc;
	inputc = tolower(inputc);

	if (inputc == 'A') {
		cout << "What game title would you like to add\n";
		cin >> inputs;

		cout << "Above which title do want to add this game?\n";
		showlist();
		cin >> inputi;

		games.push_back(inputs);
	}
	else if(inputc == 'C'){

	}
	else if (inputc == 'D') {

	}
	else if (inputc == 'H') {
	
	}
	else {
		cout << "\nInvalid input please follow the instructions!\n\n";
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
