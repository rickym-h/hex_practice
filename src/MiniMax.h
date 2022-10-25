//
// Created by richa on 25/10/2022.
//

#ifndef HEX_PRACTICE_MINIMAX_H
#define HEX_PRACTICE_MINIMAX_H


#include "HexBoard.h"

// MINIMAX SHOULD HAVE CACHE - only initialized per move - instead of one for the whole game
class MiniMax {
    int MiniMaxFromRoot(HexBoard board, int depth);
public:
    MiniMax();
    int getMoveFromBoardPos(HexBoard board, int MAX_DEPTH, int MAX_TIME);

};


#endif //HEX_PRACTICE_MINIMAX_H
