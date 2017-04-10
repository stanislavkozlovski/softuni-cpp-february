//
// Created by netherblood on 07.04.17.
//

#ifndef CHESS_CHESSENGINE_H
#define CHESS_CHESSENGINE_H

#include <vector>
#include "ChessFigure.h"
using std::vector;
class ChessEngine {
private:
    ChessFigure*** board;
      vector<ChessFigure*> blackFigures;
    vector<ChessFigure*> whiteFigures;
    ChessFigure* whiteKing;
    ChessFigure* blackKing;
    bool whiteKingIsDead;
    bool blackKingIsDead;
    ChessFigure*** createBoard();
    void removePiece(int row, int col);
    void removePieceFromVector(ChessFigure* cf, vector<ChessFigure*> &pieces);
public:
    ChessEngine();
    bool hasWon(Color c);
    bool kingIsInDanger(Color c);
    ChessFigure* getFigure(int row, int col);
    void movePiece(int row, int col, Color clr, int newRow, int newCol);
//    ChessEngine(Che)
    ChessFigure*** getBoard();
};


#endif //CHESS_CHESSENGINE_H
