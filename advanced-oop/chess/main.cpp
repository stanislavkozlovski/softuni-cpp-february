#include <iostream>
#include "ChessEngine.h"
#include "Chess.h"
//#include "ChessFigure.h"
#define BOARD_SIZE 8

bool testKingMoves();
bool testQueenMoves();

int main() {
    std::cout << "Hello, World!" << std::endl;
    if (!testKingMoves()) {
        throw "King did not move as expected!";
    }
    if (!testQueenMoves()) {
        throw "Queen did not move as expected!";
    }
    Chess c = Chess();
    c.runGame();
//    ChessEngine ce = ChessEngine();
//    ce.movePiece(1, 0, Color::BLACK, 7, 3);
//    std::cout << ce.hasWon(Color::BLACK);
//    ChessFigure(10, 10, Color::BLACK);
    return 0;
}

ChessFigure*** createBoardHelper() {
    ChessFigure*** board = new ChessFigure**[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; ++i) {
        board[i] = new ChessFigure*[BOARD_SIZE];
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = new ChessFigure();
        }
    }
    return board;
}

bool testKingMoves() {
    ChessFigure*** board = createBoardHelper();
    King* kng = new King(0, 0, Color::BLACK);
    std::vector<std::tuple<int, int>> expectedPositions = std::vector<std::tuple<int, int>>({
            std::make_tuple(0, 1), std::make_tuple(1,0),std::make_tuple(1, 1)
                                                                                            });
    board[0][0] = kng;
    auto a = kng->getAvailableMoves(board);
    if (a.size() != expectedPositions.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (std::get<0>(a[i]) != std::get<0>(expectedPositions[i]) || std::get<1>(expectedPositions[i]) != std::get<1>(a[i])) {
            return false;
        }
    }
    return true;
}

bool testQueenMoves() {
    ChessFigure*** board = createBoardHelper();
    Queen* queen = new Queen(0, 0, Color::BLACK);
    Pawn* pwn1 = new Pawn(1, 0, Color::WHITE);
    Pawn* pwn2 = new Pawn(1, 1, Color::WHITE);
    Pawn* pwn3 = new Pawn(0, 1, Color::BLACK);
    std::vector<std::tuple<int, int>> expectedPositions = std::vector<std::tuple<int, int>>({
            std::make_tuple(1, 0), std::make_tuple(1,1)
                                                                                            });
    board[0][1] = pwn3;
    board[1][1] = pwn2;
    board[1][0] = pwn1;
    auto queenMoves = queen->getAvailableMoves(board);

    if (queenMoves.size() != expectedPositions.size()) {
        return false;
    }
    for (int i = 0; i < queenMoves.size(); ++i) {
        if (std::get<0>(queenMoves[i]) != std::get<0>(expectedPositions[i]) || std::get<1>(expectedPositions[i]) != std::get<1>(queenMoves[i])) {
            return false;
        }
    }
    return true;
}
