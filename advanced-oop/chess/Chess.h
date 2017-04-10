//
// Created by netherblood on 08.04.17.
//

#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H

#include "ChessEngine.h"
class Chess {
    ChessEngine engine;
    bool isWhitePlayerTurn;
public:
    Chess();
    void runGame();
    void runTurn(Color playerColor);
    void printState(ChessFigure*** board);
};


#endif //CHESS_CHESS_H
