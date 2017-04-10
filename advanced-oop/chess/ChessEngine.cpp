//
// Created by netherblood on 07.04.17.
//

#include <algorithm>
#include <iostream>
#include "ChessEngine.h"
#define BOARD_SIZE 8

ChessFigure***  ChessEngine::createBoard() {
    ChessFigure*** board = new ChessFigure**[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; ++i) {
        board[i] = new ChessFigure*[BOARD_SIZE];
        if (i == 1 || i == 6) {
            Color col = i == 1 ? Color::BLACK : Color::WHITE;
            vector<ChessFigure*> &figures = col == Color ::BLACK ? this->blackFigures : this->whiteFigures;
            for (int j = 0; j < BOARD_SIZE; ++j) {
                figures.push_back(board[i][j] = new Pawn(i, j, col));
            }
        }
        else if (i == 0 || i == 7) {
            Color col = i == 0 ? Color::BLACK : Color::WHITE;
            vector<ChessFigure*> &figures = col == Color ::BLACK ? this->blackFigures : this->whiteFigures;
            figures.push_back(board[i][0] = new Rook(i, 0, col));
            figures.push_back(board[i][1] = new Knight(i, 1, col));
            figures.push_back(board[i][2] = new Bishop(i, 2, col));
            figures.push_back(board[i][3] = new King(i, 3, col));
            figures.push_back(board[i][4] = new Queen(i, 4, col));
            figures.push_back(board[i][5] = new Bishop(i, 5, col));
            figures.push_back(board[i][6] = new Knight(i, 6, col));
            figures.push_back(board[i][7] = new Rook(i, 7, col));
        } else {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                board[i][j] = new ChessFigure();
            }
        }
    }
    return board;
}

ChessFigure* ChessEngine::getFigure(int row, int col) {
    return this->board[row][col];
}

bool isInBounds(int rowOrCol) {
    return rowOrCol >= 0 && rowOrCol < BOARD_SIZE;
}

bool ChessEngine::kingIsInDanger(Color c) {
    /* Returns a boolean indicating if the king is in danger */
    ChessFigure* king = c == Color::BLACK ? this->blackKing : this->whiteKing;
    Color oppositeColor = Color ::BLACK == c ? Color::WHITE : Color::BLACK;
    std::vector<std::tuple<int, int>> adjacentPositions = std::vector<std::tuple<int, int>>({
            std::make_tuple(-1, 0),
            std::make_tuple(0, -1),
            std::make_tuple(0, 1),
            std::make_tuple(-1, 0),
    });
    // check adjacent positions
    for (int i = 0; i < adjacentPositions.size(); ++i) {
        std::tuple<int, int> posToAdd = adjacentPositions[i];
        int newRow = std::get<0>(posToAdd) + king->getRow();
        int newCol = std::get<1>(posToAdd) + king->getCol();
        if (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE) {
            // in bounds
            if (this->board[newRow][newCol]->color == oppositeColor) {
                return true;
            }
        }
    }

    // check further positions
    std::vector<std::tuple<int, int>> possibleDirections = std::vector<std::tuple<int, int>>({
            std::make_tuple(0, -1), // left
            std::make_tuple(0, 1), // right
            std::make_tuple(-1, 0), // up
            std::make_tuple(1, 0), // down
            std::make_tuple(-1, -1),  // up-left
            std::make_tuple(1, 1),  // down-right
            std::make_tuple(-1, 1),  // up-right
            std::make_tuple(1, -1)  // down-left
    });

    for (int i = 0; i < possibleDirections.size(); ++i) {
            // for each direction, try to go that way until you go out of bounds or find a target
            std::tuple<int, int> dir = possibleDirections[i];
            int newRow = king->getRow() + std::get<0>(dir);
            int newCol = king->getCol() + std::get<1>(dir);
            while (isInBounds(newRow) && isInBounds(newCol) && this->board[newRow][newCol]->color != king->color) {
                if (this->board[newRow][newCol]->color == oppositeColor) {
                    // Found enemy piece, see if he can reach our king
                    ChessFigure* enemyPiece = this->board[newRow][newCol];
                    if (enemyPiece->canMoveTo(std::make_tuple(king->getRow(), king->getCol()), this->board)) {
                        return true;
                    }
                }
                newRow += std::get<0>(dir);
                newCol += std::get<1>(dir);
            }
        }

    return false;
}

void ChessEngine::movePiece(int row, int col, Color clr, int newRow, int newCol) {
    // validate move
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        std::cout << "Row:" << row << " Col:" << col << " are out of bounds!" << std::endl;
        throw "Piece is out of bounds!";
    }
    if (this->board[row][col]->color != clr) {
        throw "You cannot move that piece!";
    }
    if (newRow < 0 || newRow >= BOARD_SIZE || newCol < 0 || newCol >= BOARD_SIZE) {
        throw "Piece is out of bounds!";
    }
    if (this->board[newRow][newCol]->color == clr) {
        std::cout << "You tried getting a piece that is the same color as you!" << std::endl;
        throw "You cannot go to a piece of your color!";
    }

    ChessFigure* figure = this->board[row][col];
    if (!figure->canMoveTo(std::make_tuple(newRow, newCol), this->board)) {
        // CANT MOVE
        std::cout << "The piece cannot move to that position!" << std::endl;
        throw "Piece cannot move to there";
    }
    this->removePiece(newRow, newCol);
    // move
    figure->move(std::make_tuple(newRow, newCol), this->board);
    this->board[newRow][newCol] = figure;
    this->board[row][col] = new ChessFigure();
}

void ChessEngine::removePiece(int row, int col) {
    /* Determines whether the piece is in bounds and removes it from the
     * appropriate vector */
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        std::cout << "Piece is out of bounds!" << std::endl;
        throw "Piece is out of bounds!";
    }

    ChessFigure* pieceToRemove = this->board[row][col];
    if (pieceToRemove->color != Color::NONE) {
        if (pieceToRemove->color == Color::BLACK) {
            this->removePieceFromVector(pieceToRemove, this->blackFigures);
            if (pieceToRemove == this->blackKing) {
                blackKingIsDead=true;
            }
        } else {
            this->removePieceFromVector(pieceToRemove, this->whiteFigures);
            if (pieceToRemove == this->whiteKing) {
                whiteKingIsDead=true;
            }
        }
    }
}

void ChessEngine::removePieceFromVector(ChessFigure* cf, vector<ChessFigure*> &pieces) {
    /* Finds a piece's index in the vector */
    auto it = std::find(pieces.begin(), pieces.end(), cf);
    if (it == pieces.end()) {
        std::cout << "Piece is not in the vector!" << std::endl;
        throw "Piece is not in the vector!";
    } else {
        pieces.erase(it);
    }
}

ChessFigure*** ChessEngine::getBoard() {
    return this->board;
}

ChessEngine::ChessEngine() {
    this->blackKingIsDead = this->whiteKingIsDead = false;
    this->board=createBoard();
    this->blackKing = board[0][3];
    this->whiteKing = board[7][3];
}

bool ChessEngine::hasWon(Color c) {
    return c == Color::WHITE ? this->blackKingIsDead : this->whiteKingIsDead;
}