//
// Created by netherblood on 10.04.17.
//

#ifndef CHESS_INPUTREADER_H
#define CHESS_INPUTREADER_H

#include <vector>
#include <tuple>
#ifndef CHESS_CHESSFIGURE_H
    #include "ChessFigure.h"
#endif
using std::vector;
using std::tuple;

/* Reads and validates user input */
class InputReader {
private:
    static tuple<int, int> getTargetCoords(Color playerColor, ChessFigure* chosenPiece, ChessFigure*** board);
    static tuple<int, int> getFigureCoords(Color playerColor, ChessFigure*** board);
public:
    static tuple<int, int, int, int> readInput(Color playerColor, ChessFigure*** board);
    static void printValidTargetCoords(ChessFigure* chosenPiece, ChessFigure*** board);
};


#endif //CHESS_INPUTREADER_H
