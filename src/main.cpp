#include <iostream>
#include "HexBoard.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Test" << std::endl;

    HexBoard board;

    board.printBoard();
    board.placePiece(50, B);
    board.printBoard();
    return 0;
}
