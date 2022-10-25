#include <iostream>
#include "HexBoard.h"
#include "StaticEvaluator.h"

int main() {
    StaticEvaluator staticEvaluator;

    HexBoard board;

    int eval = staticEvaluator.getEvaluation(board);
    std::cout << eval << std::endl;


    return 0;
}
