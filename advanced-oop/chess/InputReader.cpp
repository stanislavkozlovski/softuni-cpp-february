//
// Created by netherblood on 10.04.17.
//

#include <iostream>
#include "InputReader.h"

#define BOARD_SIZE 8

tuple<int, int, int, int> InputReader::readInput(Color playerColor, ChessFigure*** board) {
    /* Read the input of the user as to which figure he wants to pick and where he wants to go with it
     *  Returns: A tuple, containing the coords (X, Y) of the figure we chose to move and the coords of the target destination (X, Y)
     * */
    tuple<int, int> figureCoords = InputReader::getFigureCoords(playerColor, board);

    ChessFigure* chosenPiece = board[std::get<0>(figureCoords)][std::get<1>(figureCoords)];

    InputReader::printValidTargetCoords(chosenPiece, board);
    tuple<int, int> targetCoords = InputReader::getTargetCoords(playerColor, chosenPiece, board);

    return std::tuple_cat(figureCoords, targetCoords);
}


tuple<int, int> InputReader::getTargetCoords(Color playerColor, ChessFigure* chosenPiece, ChessFigure*** board) {
    int newRow, newCol;
    std::cout << "Please choose the position you'd like your figure to go to: " << std::endl;
    std::cin >> newRow >> newCol;

    bool newCoordsAreValid = newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol <= BOARD_SIZE && board[newRow][newCol]->color != playerColor;
    while (!newCoordsAreValid || !chosenPiece->canMoveTo(std::make_tuple(newRow, newCol), board)) {
        if (board[newRow][newCol]->color == playerColor) {
            std::cout << "You cannot remove a piece that's the same color as you!" << std::endl;
        } else if (!(newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol <= BOARD_SIZE)){
            std::cout << "The coordinates you gave were outside the board!" << std::endl;
        } else {
            std::cout << "Your piece cannot move to that location!" << std::endl;
        }
        std::cout << "Please choose again!" << std::endl;
        std::cin >> newRow >> newCol;
        newCoordsAreValid = newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol <= BOARD_SIZE && board[newRow][newCol]->color != playerColor;
    }

    return std::make_tuple(newRow, newCol);
}

tuple<int, int> InputReader::getFigureCoords(Color playerColor, ChessFigure*** board) {
    int pieceRow, pieceCol;
    std::cout << "FIGURE COLOR IS " << (playerColor == Color::BLACK ? "BLACK" : "WHITE");

    std::cout << "Please enter the coordinates of the figure you'd like to move: " << std::endl;
    std::cin >> pieceRow >> pieceCol;
    bool pieceCoordsAreValid = pieceRow >= 0 && pieceRow < BOARD_SIZE && pieceCol >= 0 && pieceCol <= BOARD_SIZE && board[pieceRow][pieceCol]->color == playerColor;
    while (!pieceCoordsAreValid) {
        if (board[pieceRow][pieceCol]->color != playerColor) {
            if (board[pieceRow][pieceCol]->color == Color::NONE) {
                std::cout << "You cannot choose an empty cell!" << std::endl;
            } else {
                std::cout << "That piece is not the same color as you!" << std::endl;
            }
        } else {
            std::cout << "The coordinates you gave were outside the board!" << std::endl;
        }
        std::cout << "Please choose again!" << std::endl;
        std::cin >> pieceRow >> pieceCol;
        pieceCoordsAreValid = pieceRow >= 0 && pieceRow < BOARD_SIZE && pieceCol >= 0 && pieceCol < BOARD_SIZE && board[pieceRow][pieceCol]->color == playerColor;
    }

    return std::make_tuple(pieceRow, pieceCol);
}

void InputReader::printValidTargetCoords(ChessFigure* chosenPiece, ChessFigure*** board) {
    auto validMoves = chosenPiece->getAvailableMoves(board);
    for (int i = 0; i < validMoves.size(); ++i) {
        std::cout << "{" << std::get<0>(validMoves[i]) << ", " << std::get<1>(validMoves[i]) << "} ";
    }
    std::cout << std::endl;
}