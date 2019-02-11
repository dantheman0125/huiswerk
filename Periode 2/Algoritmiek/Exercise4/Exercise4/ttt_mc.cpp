// ttt_mc.cpp
// Compile with: g++ -std=c++11 -o ttt_mc ttt_mc.cpp ttt.cpp

#include "pch.h"

#include <iostream>
#include <algorithm>
#include <map>
#include "ttt.h"

unsigned const n_trials = 1000;
unsigned const mc_match = 1;
unsigned const mc_other = 1;
//std::array<int, 9> scores;

enum class PlayerType { Human, Computer };

std::array<int, 9> getScores() { std::array<int, 9> scores; return scores; }


void mcUpdateScores(std::array<int,9> &scores, const State &board, const Player &player)
{
	
	if (player == Player::X) {
		int i = 0;
		for (auto spot : board) {
			switch ((int)board[i])
			{
			case 0:
				scores[i] + mc_other;
				break;
			case 1:
				scores[i] - mc_match;
				break;
			}
			i++;
		}
	}
	else if (player == Player::O) {
		int i = 0;
		for (auto spot : board) {
			switch ((int)board[i])
			{
			case 0:
				scores[i] - mc_other;
				break;
			case 1:
				scores[i] + mc_match;
				break;
			}
			i++;
		}
	}
}

void mcTrial(const State &board) {
	Player player = getWinner(board);
	std::array<int, 9> score = getScores();
	mcUpdateScores(score, board, player);
}

Move getBestMove(const std::array<int,9> &scores, const State &board)
{
	std::vector<Move> moves = getMoves(board);
	std::vector<Move> keep;
	for (int i = 0; i < 9; i++) {
		int indexLow = (int)moves[i];
		int indexHigh = (int)moves[i+1];
		int hold = scores[indexLow];
		if (hold < scores[indexHigh]) {
		}
	}
}

Move mcMove(const State &board, const Player &player)
{
	std::array<int, 9> score = getScores();
	return getBestMove(score,board);
}

int main()
{
	std::srand(std::time(0));

	std::map<Player,PlayerType> playerType;
	playerType[Player::X] = PlayerType::Human;
	playerType[Player::O] = PlayerType::Computer;

	for (int i = 0; i < n_trials; i++) {
		State board = {
			Player::None, Player::None, Player::None,
			Player::None, Player::None, Player::None,
			Player::None, Player::None, Player::None };
		std::cout << board << std::endl;

		std::vector<Move> moves = getMoves(board);
		while (moves.size() > 0) {
			if (playerType[getCurrentPlayer(board)] == PlayerType::Human) {
				std::cout << "+-+-+-+" << std::endl <<
					"|0|1|2|" << std::endl <<
					"+-+-+-+" << std::endl <<
					"|3|4|5|" << std::endl <<
					"+-+-+-+" << std::endl <<
					"|6|7|8|" << std::endl <<
					"+-+-+-+" << std::endl << std::endl;
				std::cout << "Enter a move ( ";
				for (Move m : moves) std::cout << m << " ";
				std::cout << "): ";
				Move m;
				std::cin >> m;
				board = doMove(board, m);
			}
			else {
				board = doMove(board, mcMove(board, getCurrentPlayer(board)));
			}
			std::cout << board << std::endl;
			moves = getMoves(board);
		}
		mcTrial(board);
	}
	return 0;
}