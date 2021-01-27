#pragma once
#include "Board.h"

class Game
{
private:
	Board board;
	bool upperTurn = true;
	bool lowerTurn = false;
public:
	Game();
	void newGame();
	bool move(int rowStart, int colStart, int rowEnd, int colEnd);
};

