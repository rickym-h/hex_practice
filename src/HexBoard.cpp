//
// Created by richa on 20/10/2022.
//

#include "HexBoard.h"

// Constructor for a new board
HexBoard::HexBoard() {
    std::cout << "Initialising new HexBoard..." << std::endl;
    board = std::vector<Hex>(121, Hex::Empty);
}

HexBoard::HexBoard(std::vector<int> boardVector) {
    if (boardVector.size() != 121) {
        throw std::length_error("Board Vector must be 121 long.");
    }

    board = std::vector<Hex>(121, Hex::Empty);

    std::transform(boardVector.begin(), boardVector.end(),
                   board.begin(),
                   intToHex);

}

std::vector<Hex> HexBoard::getBoard() {
    return this->board;
}

Hex HexBoard::intToHex(int i) {
    switch (i) {
        case 1:
            return Hex::A;
        case 0:
            return Hex::Empty;
        case -1:
            return Hex::B;
        default:
            throw std::invalid_argument("int should be -1, 0, or 1");
    }
}

void HexBoard::printBoard() {
    int i = 0;
    for (Hex h : this->board) {
        std::cout << h << " ";
        if ((i+1)%11 == 0) {
            std::cout << std::endl;
        }
        i++;
    }
}
