//
// Created by richa on 24/10/2022.
//

#include "StaticEvaluator.h"

StaticEvaluator::StaticEvaluator() {
    // Initialise hashmap?


    nodes = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124};
    adjacencyMatrix = std::vector<std::vector<bool>> (125);

    // Set the adjacency matrix bools for an empty hex board
    for (int i = 0; i <= 124; i++) {
        adjacencyMatrix[i] = std::vector<bool> (125, false);
        if (i >= 121) { continue; }

        // Get offsets for all 6 surrounding hex pieces of any position
        std::vector<int> offsetIndex = {-11, -10, -1, 1, 10, 11};

        // Fix offsets for edge cases around sides of board
        // General case of left edge
        if (i % 11 == 0) { offsetIndex = {-11, -10, 1, 11}; }
        // General case of right edge
        if ((i+1) % 11 == 0) { offsetIndex = {-11, -1, 10, 11}; }
        // Specific corner cases
        switch (i) {
            case 0: offsetIndex = {1, 11}; break;
            case 10: offsetIndex = {-1, 10, 11}; break;
            case 110: offsetIndex = {-11, -10, 1}; break;
            case 120: offsetIndex = {-11, -1}; break;
            default: break;
        }

        // Go through all the offsets and connect the adjacent nodes in the matrix.
        for (int offset : offsetIndex) {
            if ((i+offset <0) || (i+offset >= 121)) {continue;}
            adjacencyMatrix[i][i+offset] = true;
        }
    }

    for (int i = 0; i < adjacencyMatrix.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < adjacencyMatrix[i].size(); j++)
        {
            if (adjacencyMatrix[i][j]) {
                count++;
            }
        }
        std::cout << i << " connects to " << count << " nodes" << std::endl;
    }
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
