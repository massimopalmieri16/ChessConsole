// ChessConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Board.h"
#include "Game.h"

Game game;
int main()
{

	int menuInput = -1;

	while (menuInput != 0)
	{
		std::cout << std::endl << std::endl << "Chess Game" << std::endl << std::endl;
		std::cout << "1 - New Game" << std::endl << "0 - Exit" << std::endl << std::endl;
		std::cout << "Waiting for input... ";
		std::cin.clear();
		std::cin >> menuInput;

		switch (menuInput)
		{
		case 1:
			std::cout << "Starting new game\n\n";
			game.newGame();

			break;
		case 0:
			break;
		default:
			std::cout << "Invalid command" << std::endl;

			break;
		}
	}
}
