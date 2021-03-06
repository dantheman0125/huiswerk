// Exercise_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

char guess;
void Input();
char Correct(string);


int main()
{
	// set-up
	const int MAX_WRONG = 8;  // maximum number of incorrect guesses allowed

	vector<string> words;  // collection of possible words to guess
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	words.push_back("PEANUT");
	words.push_back("SWORD");
	words.push_back("KANGAROO");
	words.push_back("ZODIAC");
	words.push_back("PETABYTE");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];            // word to guess
	int wrong = 0;                               // number of incorrect guesses
	string soFar(THE_WORD.size(), '_');          // word guessed so far
	string used = "";                            // letters already guessed

	cout << "Welcome to Hangman.  Good luck!\n";

	// main loop
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar << endl;

		Input();

		//cout << "\n\nEnter your guess: ";
		//cin >> guess;
		//guess = toupper(guess); //make uppercase since secret word in uppercase
		
		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			Input();
		}
		char check = Correct(THE_WORD);
		if (check !=' ')
		{
			// update soFar to include newly guessed letter
			for (unsigned int i = 0; i < THE_WORD.length(); i++)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			wrong++;
		}
		used += guess;
	}

	// shut down
	if (wrong == MAX_WRONG)
		cout << "\nYou've been hanged!";
	else
		cout << "\nYou guessed it!";

	cout << "\nThe word was " << THE_WORD << endl;

	return 0;
}

inline void Input() {
	cout << "\n\nEnter your guess: ";
	cin >> guess;
	guess = toupper(guess); //make uppercase since secret word in uppercase
}

inline char Correct(string word) {
	if (word.find(guess) != string::npos)
	{
		cout << "That's right! " << guess << " is in the word.\n";
		// update soFar to include newly guessed letter
		return guess;
	}
	else
	{
		cout << "Sorry, " << guess << " isn't in the word.\n";
		return ' ';
	}

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
