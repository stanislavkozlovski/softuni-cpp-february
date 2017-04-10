//
// Created by netherblood on 08.04.17.
//

#include <iostream>
#include <tuple>
using std::tuple;
#include "Chess.h"
#include "InputReader.h"

#define BOARD_SIZE 8

Chess::Chess() {
    this->engine = ChessEngine();
    this->isWhitePlayerTurn = true;
}

void Chess::runGame() {
    while (true) {
        Color playerColor = this->isWhitePlayerTurn ? Color::WHITE : Color::BLACK;
        this->printState(this->engine.getBoard());

        runTurn(playerColor);
        // check for win
        if (this->engine.hasWon(playerColor)) {
            std::cout << (playerColor == Color::BLACK ? "Black" : "White")
                      << " Player has won the game!" << std::endl;
            break;
        }
        this->isWhitePlayerTurn = !this->isWhitePlayerTurn;
    }

}

void Chess::runTurn(Color playerColor) {
    /* Runs a single turn of the game */
    tuple<int, int, int, int> coordinates = InputReader::readInput(playerColor, this->engine.getBoard());
    int row = std::get<0>(coordinates);
    int col = std::get<1>(coordinates);
    int newRow = std::get<2>(coordinates);
    int newCol = std::get<3>(coordinates);

    this->engine.movePiece(row, col, playerColor, newRow, newCol);
}

void Chess::printState(ChessFigure*** board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << *board[i][j];
        }
        std::cout << std::endl;
    }
}
