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
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

int main()
{
	vector<string>::iterator myIterator;
	vector<string>::const_iterator iter;
	int num;
	char inputc;
	int inputi;
	string inputs;
	bool quit = false;

	vector<string> games;
	games.push_back("Counter-Strike: Global Offensive");
	games.push_back("Assassin's Creed Origins");
	games.push_back("METAL GEAR SOLID V: THE PHANTOM PAIN");
	games.push_back("Watch_Dogs 2");
	games.push_back("Sid Meier's Civilization 6");
	
	
	cout << "\t\t\tWelcome to Your Favourite Games List!\n\n";
	do {
		cout << "Your current list is:\n";
		num = 1;
		for (string s : games) {
			cout << num << ": " << s << "\n";
			num++;
		}
		cout << "Enter 'H' to show the help.\n\n";
		cin >> inputc;
		inputc = toupper(inputc);

		if (inputc == 'A') {
			cout << "What game title would you like to add		Write 'C' to cancel\n";
			cin.ignore(); // Without this getline will only get a blank line because of the last "cin >>" that has been used.
			getline(cin, inputs);
			if (inputs != "c" && inputs != "C") {
				games.push_back(inputs);
				cout << inputs << " has been added.";
				sleep_for(1500ms);
				continue;
			}
			else {
				cout << "Action has been canceled.";
				sleep_for(1500ms);
				continue;
			}
		}
		else if (inputc == 'D') {
			cout << "What game title would you like to delete		Write '0' to cancel\n";
			cout << "Write the number that corresponds with the title you want to delete.\n";
			cin >> inputi;

			if (inputi != 0) {
				iter = (games.begin() + --inputi);
				inputs = *iter;
				games.erase(iter);
				cout << inputs << " has been deleted.";
				sleep_for(1500ms);
				continue;
			}
			else {
				cout << "Action has been canceled.";
				sleep_for(1500ms);
				continue;
			}

		}
		else if (inputc == 'H') {
			cout << "Enter 'A' to Add a game title.\n";
			cout << "Enter 'D' to Delete a game title.\n";
			cout << "Enter 'Q' to quit this application.\n";
			continue;
		}
		else if (inputc == 'Q') {
			cout << "Okay bye!";
			sleep_for(1500ms);
			quit = true;
		}
		else {
			cout << "\nInvalid input!\n\n";
			continue;
		}
		system("cls");
	} while (!quit);
	
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
