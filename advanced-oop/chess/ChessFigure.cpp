//
// Created by netherblood on 07.04.17.
//

#include "ChessFigure.h"

// helpers
bool inBounds(int rowOrCol) {
    return rowOrCol >= 0 && rowOrCol < BOARD_SIZE;
}
ChessFigure::ChessFigure() {
    this->color = Color::NONE;
}

//ChessFigure::ChessFigure(const ChessFigure& cf) {
//
//}
ChessFigure::ChessFigure(int r, int c, Color col) : row(r), col(c), color(col){ }

std::vector<std::tuple<int, int>> ChessFigure::getAvailableMoves(ChessFigure** otherFigures) {
    std::vector<std::tuple<int, int>> avMoves;

    if (this->canMoveByMultipleCells) {
        for (int i = 0; i < this->directions.size(); ++i) {
            // for each direction, try to go that way until you go out of bounds or find a target
            std::tuple<int, int> dir = directions[i];
            int newRow = this->row + std::get<0>(dir);
            int newCol = this->col + std::get<1>(dir);

            while (inBounds(newRow) && inBounds(newCol) && otherFigures[newRow][newCol].color != this->color) {
                avMoves.push_back(std::make_tuple(newRow, newCol));
                if (otherFigures[newRow][newCol].color != Color::NONE) {
                    // Found enemy piece, stop going further
                    break;
                }
                newRow += std::get<0>(dir);
                newCol += std::get<1>(dir);
            }
        }
    } else {
        for (int i = 0; i < this->directions.size(); ++i) {
            std::tuple<int, int> dir = directions[i];
            int newRow = this->row + std::get<0>(dir);
            int newCol = this->col + std::get<1>(dir);
            if (inBounds(newRow) && inBounds(newCol) && otherFigures[newRow][newCol].color != this->color) {
                avMoves.push_back(dir);
            }
        }
    }

    return avMoves;
}

bool ChessFigure::move(std::tuple<int, int> newPosition) {
    // TODO: remove figures in Game class and validate in other class
    this->row = std::get<0>(newPosition);
    this->col = std::get<1>(newPosition);
}

// Chess Pieces

Pawn::Pawn(int r, int c, Color col) : ChessFigure(r, c, col) {
    this->canMoveByMultipleCells = false;
    this->directions = std::vector<std::tuple<int, int>>({
            std::make_tuple(-1, 0), // up
            std::make_tuple(1, 0), // down
            std::make_tuple(0, -1), // left
            std::make_tuple(0, 1) // right
                                                         });
}

Knight::Knight(int r, int c, Color col) : ChessFigure(r, c, col) {
    this->canMoveByMultipleCells = false;
    this->directions = std::vector<std::tuple<int, int>>({
            std::make_tuple(-3, -1), // up left
            std::make_tuple(-3, 1), // up right
            std::make_tuple(-1, -3), // left up
            std::make_tuple(1, -3), // left down
            std::make_tuple(3, -1), // down left
            std::make_tuple(3, 1), // down right
            std::make_tuple(-1, 3), // right up
            std::make_tuple(1, 3) // right down
                                                         });
}

Bishop::Bishop(int r, int c, Color col) : ChessFigure(r, c, col) {
    this->canMoveByMultipleCells = true;
    this->directions = std::vector<std::tuple<int, int>>({
            std::make_tuple(-1, -1),  // up-left
            std::make_tuple(1, 1),  // down-right
            std::make_tuple(-1, 1),  // up-right
            std::make_tuple(1, -1)  // down-left
                                                         });
}


Rook::Rook(int r, int c, Color col) : ChessFigure(r, c, col) {
    this->canMoveByMultipleCells = true;
    this->directions = std::vector<std::tuple<int, int>>({
            std::make_tuple(0, -1), // left
            std::make_tuple(0, 1), // right
            std::make_tuple(-1, 0), // up
            std::make_tuple(1, 0)
                                                         });
}

Queen::Queen(int r, int c, Color col) : ChessFigure(r, c, col) {
    this->canMoveByMultipleCells = true;
    this->directions = std::vector<std::tuple<int, int>>({
            std::make_tuple(0, -1), // left
            std::make_tuple(0, 1), // right
            std::make_tuple(-1, 0), // up
            std::make_tuple(1, 0), // down
            std::make_tuple(-1, -1),  // up-left
            std::make_tuple(1, 1),  // down-right
            std::make_tuple(-1, 1),  // up-right
            std::make_tuple(1, -1)  // down-left
                                                         });
}


King::King(int r, int c, Color col) : ChessFigure(r, c, col) {
    this->canMoveByMultipleCells = false;
    this->directions = std::vector<std::tuple<int, int>>({
            std::make_tuple(0, -1), // left
            std::make_tuple(0, 1), // right
            std::make_tuple(-1, 0), // up
            std::make_tuple(1, 0), // down
            std::make_tuple(-1, -1),  // up-left
            std::make_tuple(1, 1),  // down-right
            std::make_tuple(-1, 1),  // up-right
            std::make_tuple(1, -1)  // down-left
                                                         });
}

