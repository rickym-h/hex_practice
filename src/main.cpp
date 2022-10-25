#include <iostream>
#include "HexBoard.h"
#include "StaticEvaluator.h"

int main() {
    StaticEvaluator staticEvaluator;

    HexBoard board;
    board.placePiece(0, 'A');
    board.placePiece(1, 'A');
    board.placePiece(2, 'A');
    board.placePiece(10, 'B');
    board.placePiece(9, 'B');
    board.placePiece(20, 'B');
    board.placePiece(21, 'B');
    board.printBoard();

    std::cout << staticEvaluator.getEvaluation(board) << std::endl;

    return 0;
}
