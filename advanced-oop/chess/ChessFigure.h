//
// Created by netherblood on 07.04.17.
//

enum Color { BLACK, WHITE, NONE };

#ifndef CHESS_CHESSFIGURE_H
#define CHESS_CHESSFIGURE_H

#include <vector>
#include <tuple>

class ChessFigure {
protected:
    int row, col;
    std::vector<std::tuple<int,int>> directions;
    bool canMoveByMultipleCells;  // indicates if he can move one cell at a time or not
public:
    Color color;
    ChessFigure();
//    ~ChessFigure();
//    ChessFigure(const ChessFigure& cf);
    ChessFigure(int r, int c, Color col);
    std::vector<std::tuple<int, int>> getAvailableMoves(ChessFigure** otherFigures);
    bool move(std::tuple<int, int> newPosition);
};


#endif //CHESS_CHESSFIGURE_H


#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

class Pawn : public ChessFigure {
public:
    Pawn(int r, int c, Color col);
};

#endif //CHESS_PAWN_H

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

class Knight : public ChessFigure {
public:
    Knight(int r, int c, Color col);
};

#endif //CHESS_KNIGHT_H

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

class Bishop : public ChessFigure {
public:
    Bishop(int r, int c, Color col);
};

#endif //CHESS_BISHOP_H


#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

class Rook : public ChessFigure {
public:
    Rook(int r, int c, Color col);
};

#endif //CHESS_ROOK_H


#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

class Queen : public ChessFigure {
public:
    Queen(int r, int c, Color col);
};

#endif //CHESS_QUEEN_H


#ifndef CHESS_KING_H
#define CHESS_KING_H

class King : public ChessFigure {
public:
    King(int r, int c, Color col);
};

#endif //CHESS_KING_H


