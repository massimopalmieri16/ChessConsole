#include <iostream>
#include "Board.h"
#include "Game.h"

#define WHITE 0xDB
#define BLACK 0xFF


Board::Board()
{

}


void Board::setDefBoard()
{
}

void Board::printBoard() {
    std::cout << "   A      B      C      D      E      F      G      H\n\n";

    for (int lineIndex = 0; lineIndex <= 7; lineIndex ++) {
        if (lineIndex % 2 == 0) {
            // Black line
            printLine(lineIndex, BLACK, WHITE);
        }
        else {
            // White line
            printLine(lineIndex, WHITE, BLACK);
        }
    }
}

void Board::printLine(int lineIndex, int Color1, int Color2) {

    for (int internalLine = 0; internalLine <= 2; internalLine++) {
        for (int colIndex = 0; colIndex <= 7; colIndex++) {
            for (int internalCol = 0; internalCol <= 6; internalCol++) {
                if (internalLine == 1 && internalCol == 3 && boardMatrix[abs(lineIndex - 7)][colIndex] != 0x20) {
                    std::cout << boardMatrix[abs(lineIndex - 7)][colIndex];
                }
                else {
                    if (colIndex % 2 == 0) {
                        std::cout << char(Color1);
                    }
                    else {
                        std::cout << char(Color2);
                    }
                }
            }
        }
        
        if (internalLine == 1) {
            std::cout << "   " << abs(lineIndex - 8) << std::endl;
        }
        else {
            std::cout << std::endl;
        }
    }
    
    return;
}