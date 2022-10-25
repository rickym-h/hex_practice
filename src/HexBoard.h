//
// Created by richa on 20/10/2022.
//

#ifndef HEX_PRACTICE_HEXBOARD_H
#define HEX_PRACTICE_HEXBOARD_H

#include <vector>
#include <iostream>


class HexBoard {
private:
    // Variables
    std::vector<char> board;

    //Functions
public:
    // Variables


    // Functions
    HexBoard();
    explicit HexBoard(const std::vector<char>&);

    std::vector<char> getBoard();

    void printBoard();

    void placePiece(int index, char piece);
    void placePiece(int x, int y, char piece);

    std::vector<int> getPossibleMoves();
};


#endif //HEX_PRACTICE_HEXBOARD_H
