//
// Created by richa on 24/10/2022.
//

#include "StaticEvaluator.h"

StaticEvaluator::StaticEvaluator() {
    // Initialise hashmap?
}

// Takes a board layout, and computes the static evaluation of it
int StaticEvaluator::getEvaluation(HexBoard board) {
    // Take a hardcoded representation of an empty board.

    // For every piece, connect all adjacent empty pieces to all other connected pieces
    // todo write out with 2 pieces to make sure order doesnt matter

    // check if game is won and return -infinity or +infinity depending.

    // do a bfs and find the shortest distance to the end for each side

    // return distance(A)-distance(B)
    // possibly store in a hashmap as a pseudo-cache? for efficiency later



    // TEMP IMPLEMENTATION:
    // Take the number of pieces that are adjacent to other pieces of the same colour and subtract from each other.
    int ACount = 0, BCount = 0;

    // These are the offsets to find all adjacent cells.
    std::vector<int> offsetIndex = {-11, -10, -1, 1, 10, 11};

    for (int i = 0; i < 121; i++) {
        if (board.getBoard()[i] != '.') {
            // Piece is not empty
            for (int offset : offsetIndex) {
                try {
                    if (board.getBoard().at(i+offset) == board.getBoard()[i]) {
                        if (board.getBoard()[i] == 'A') {
                            ACount++;
                        } else {
                            BCount++;
                        }
                        break;
                    }
                } catch (...) {

                }
            }
        }
    }
    return ACount - BCount;
}
