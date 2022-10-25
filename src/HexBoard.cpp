//
// Created by richa on 20/10/2022.
//

#include "HexBoard.h"

// Constructor for a new board
HexBoard::HexBoard() {
    board = std::vector<char>(121, '.');
}

HexBoard::HexBoard(const std::vector<char>& boardVector) {
    if (boardVector.size() != 121) {
        throw std::length_error("Board Vector must be 121 long.");
    }

    board = std::vector<char>(boardVector);
}

std::vector<char> HexBoard::getBoard() {
    return this->board;
}

void HexBoard::printBoard() {
    int i = 0;
    std::cout << "---------------------" << std::endl;
    for (char h : this->board) {
        std::cout << h << " ";
        if ((i+1)%11 == 0) {
            std::cout << std::endl;
        }
        i++;
    }
    std::cout << "---------------------" << std::endl;
}

void HexBoard::placePiece(int index, char piece) {
    board.at(index) = piece;
}

void HexBoard::placePiece(int row, int col, char piece) {
    board.at((11 * row) + col) = piece;
}

std::vector<int> HexBoard::getPossibleMoves() {
    std::vector<int> possibleMoves;
    for (int i = 0; i < 121; i++) {
        if (board[i] == 0) {
            possibleMoves.push_back(i);
        }
    }
    return possibleMoves;
}