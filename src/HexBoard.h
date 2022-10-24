//
// Created by richa on 20/10/2022.
//

#ifndef HEX_PRACTICE_HEXBOARD_H
#define HEX_PRACTICE_HEXBOARD_H

#include <vector>
#include <iostream>

enum Hex {
    Empty = 0,
    A = 1,
    B = -1,
};


class HexBoard {
private:
    std::vector<Hex> board;

    static Hex intToHex(int);
public:
    HexBoard();
    explicit HexBoard(std::vector<int>);

    std::vector<Hex> getBoard();

    void printBoard();

    void placePiece(int index, Hex piece);
    void placePiece(int x, int y, Hex piece);

    std::vector<int> getPossibleMoves();

    float getStaticEvaluation();
};


#endif //HEX_PRACTICE_HEXBOARD_H
