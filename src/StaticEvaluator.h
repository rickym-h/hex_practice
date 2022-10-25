//
// Created by richa on 24/10/2022.
//

#ifndef HEX_PRACTICE_STATICEVALUATOR_H
#define HEX_PRACTICE_STATICEVALUATOR_H


#include <map>
#include "HexBoard.h"

struct Graph {
    std::vector<int> nodes;
    std::vector<std::vector<bool>> adjacencyMatrix;
};

class StaticEvaluator {
private:
    // Hashmap for a cache of some kind for board layouts? Key is the vector rep of board, value is the computed value
    // IF WE DO THIS MAKE IT CYCLIC AS OLD EVALUATIONS WON'T BE USEFUL LATER
    //

    std::vector<int> nodes;
    std::vector<std::vector<bool>> adjacencyMatrix;

    int GetEvaluationForPlayer(HexBoard board, char player);

    Graph generateGraphRepresentation(HexBoard board, char player);
public:
    StaticEvaluator();

    int getEvaluation(HexBoard board);

    // Returns 1 if A won, -1 if B won, and 0 if game is not finished
    int isGameOver(HexBoard board);



};


#endif //HEX_PRACTICE_STATICEVALUATOR_H
