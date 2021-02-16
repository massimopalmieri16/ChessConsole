// ChessConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Board.h"
#include "Game.h"

Game game;
int main()
{

	int menuInput = -1;

	while (menuInput != 1)
	{
		std::cout << std::endl << std::endl << "Chess Game" << std::endl << std::endl;
		std::cout << "2 - New Game" << std::endl << "1 - Exit" << std::endl << std::endl;
		std::cout << "Waiting for input... ";
		std::cin.clear();
		std::cin >> menuInput;

		switch (menuInput)
		{
		case 2:
			std::cout << "Starting new game\n\n";
			game.newGame();

			break;
		case 1:
			std::cout << "Exit" << std::endl;
			break;
		default:
			std::cout << "Invalid command" << std::endl;

			break;
		}
	}
}
