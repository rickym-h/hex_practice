//
// Created by richa on 25/10/2022.
//

#include "MiniMax.h"
#include "StaticEvaluator.h"

MiniMax::MiniMax() {
    // Initialise a cyclic pseudocache with a hashmap?

}

int MiniMax::getMoveFromBoardPos(HexBoard board, int MAX_DEPTH, int MAX_TIME) {
    // Perform iterative deepening search with minimax with a/b pruning until time runs out or a move is found
    StaticEvaluator staticEvaluator;

    int bestMove = randomPossibleMove(board);
    for(int depth = 1; depth < MAX_DEPTH && !outOfTime(); depth++) {
        int bestmove = MiniMaxFromRoot(board, depth);
    }
    return bestMove
}

int MiniMax::MiniMaxFromRoot(HexBoard board, int depth) {
    return 0;
}
