#include <iostream>
#include "HexBoard.h"
#include "StaticEvaluator.h"
#include "MiniMax.h"

int main() {
    HexBoard board;

    MiniMax minimax;
    int move = minimax.getMoveFromBoardPos(board);

    std::cout << move << std::endl;

    return 0;
}
