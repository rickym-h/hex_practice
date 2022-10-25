//
// Created by richa on 24/10/2022.
//

#ifndef HEX_PRACTICE_STATICEVALUATOR_H
#define HEX_PRACTICE_STATICEVALUATOR_H


#include <map>
#include "HexBoard.h"

class StaticEvaluator {
private:
    // Hashmap for a cache of some kind for board layouts? Key is the vector rep of board, value is the computed value
    // IF WE DO THIS MAKE IT CYCLIC AS OLD EVALUATIONS WON'T BE USEFUL LATER
    std::map<std::vector<char>, int> evaluationMap;

    std::vector<int> nodes;
    std::vector<std::vector<bool>> adjacencyMatrix;

    //generateGraphRepresentation(HexBoard board);
public:
    StaticEvaluator();

    int getEvaluation(HexBoard board);
};


#endif //HEX_PRACTICE_STATICEVALUATOR_H
