#include "Game.h"
#include "Board.h"
#include <iostream>
#include <string>

Game::Game()
{
	
}


void Game::newGame()
{
	board.printBoard();
	int menuInput = -1;
	std::string moveInput = "";

	while (menuInput != 0)
	{
		if (upperTurn) std::cout << "\n Upper Turn";
		if (lowerTurn) std::cout << "\n Lower Turn";
		
		std::cout << "\n1 - Move\n2 - Print Board\n0 - Quit Game\n\n";
		std::cout << "Waiting for input... ";
		std::cin.clear(); 
		std::cin >> menuInput;

		switch (menuInput)
		{
		case 1:
			std::cout << "\nWrite move (eg a2 a4)\n";
			std::cin.ignore();
			getline(std::cin, moveInput);

			if (moveInput.length() == 5 && moveInput[2] == 0x20)
			{
				char cColStart = ::tolower(moveInput[0]);
				char cColEnd = ::tolower(moveInput[3]);
				char cRowStart = moveInput[1];
				char cRowEnd = moveInput[4];

				int colStart = cColStart - 97;
				int colEnd = cColEnd - 97;
				int rowStart = cRowStart - '0' - 1;
				int rowEnd = cRowEnd - '0' - 1;

				//if (colStart >= 97 && colStart <= 104 && colEnd >= 97 && colEnd <= 104 && rowStart >= 1 && rowStart <= 8 && rowEnd >= 1 && rowEnd <= 8)
				if (colStart >= 0 && colStart <= 7 && colEnd >= 0 && colEnd <= 7 && rowStart >= 0 && rowStart <= 7 && rowEnd >= 0 && rowEnd <= 7)
				{
					if (move(rowStart, colStart, rowEnd, colEnd)) {
						board.printBoard();
						std::cout << "\nMove valid\n";
					}
					else
					{
						std::cout << "\nMove not valid\n";
					}
				}
				else
				{
					std::cout << "\nMove not valid\n";
				}
			}
			else
			{
				std::cout << "\nMove not valid\n";
			}


			break;
		case 2:
			board.printBoard();
			break;
		case 0:
			break;
		default:
			std::cout << "Invalid command\n";
			break;
		}
	}
}

bool Game::move(int rowStart, int colStart, int rowEnd, int colEnd)
{
	char elemStart = board.boardMatrix[rowStart][colStart];
	char elemEnd = board.boardMatrix[rowEnd][colEnd];

	// Check if moving the right elem according to the turn
	if ((isupper(elemStart) && upperTurn) || (!isupper(elemStart) && lowerTurn)) {

		board.boardMatrix[rowEnd][colEnd] = board.boardMatrix[rowStart][colStart];
		board.boardMatrix[rowStart][colStart] = 0x20;

		if (upperTurn) {
			upperTurn = false;
			lowerTurn = true;
		}
		else {
			lowerTurn = false;
			upperTurn = true;
		}

		return true;
	}
	else
	{
		return false;
	}
}
