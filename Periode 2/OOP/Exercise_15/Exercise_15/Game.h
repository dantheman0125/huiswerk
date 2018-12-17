// Game.h

#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "House.h"
#include "Player.h"
#include <vector>
#include <String>

using namespace std;

class Game
{
public:
	Game(const vector<string>& names);

	~Game();

	//plays the game of blackjack    
	void Play();

private:
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;
};

#endif //GAME_H