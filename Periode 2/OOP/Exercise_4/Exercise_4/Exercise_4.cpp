// Exercise_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	srand(static_cast<unsigned int>(time(0)));  //seed random number generator

	int guess;
	int tries;
	bool GotIt = false, play=true;
	char input;
	int low, high, dif;

	do {
		cout << "\tWelcome to Guess My Number\n\n";
		cout << "Think of a number between 1 and 100\n";
		guess = rand() % 100 + 1;  // random number between 1 and 100
		low = 1, high = 100, dif = 0;
		tries = 0;
		GotIt = false;

		do {
			if (dif != 1) {
				cout << "Are you Thinking of: " << guess;
				cout << "\n (C) Correct!";
				cout << "\n (h) Higher";
				cout << "\n (l) lower\n";
				cin >> input;
			}
			else {
				cout << "\nWhat do you mean. That's the only number left.";
				cout << "\nUnless something went wrong. Did something go wrong";
				cin >> input;
				if (input=='n')
				{
					cout << "\nIn that case:";
					cout << "\nThe Computer got it in " << tries << " guesses!\n";
					GotIt = true;
					goto cnt;
				}
				else {
					cout << "\nOkay we are sorry!\n";
					GotIt = true;
					goto cnt;
				}
			}
			tries++;
			switch (input) {
			case 'c':
				if (tries == 1) {
					cout << "\nDamn, you must have a very smart computer, because he got it in just one guess!\n\n";
				}
				else
				{
					cout << "\nThe Computer got it in " << tries << " guesses!\n";
				}
				GotIt = true;
				break;
			case 'h':
				low = guess;
				dif = high- low++;
				guess = rand() % --dif + low;  // random number between lowest picked number and highest picked number
				goto cnt;
				break;
			case 'l':
				high = guess;
				dif = high - low;
				guess = rand() % dif + low;  // random number between lowest picked number and highest picked number
				goto cnt;
				break;
			default:
				cout << "\nInvalid input please follow the instructions!\n\n";
				continue;
			}
			cnt:;
		} while (!GotIt);
		cout << "\nDo you want to play again?";
		cout << "\n (y) Yes!";
		cout << "\n (n) No\n";
		cin >> input;
		switch (input) {
		case 'y':
			system("cls");
			goto retry;
			break;
		case 'n':
			play = false;
			break;
		default:
			cout << "\nInvalid input please follow the instructions!\n\n";
			continue;
		}
		retry:;
	} while (play);
	cout << "Okay bye!";
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
