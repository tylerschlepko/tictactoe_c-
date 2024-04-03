// TicTacToeBoard.cpp
#include "TicTacToeBoard.h"
#include <cstdlib>

TicTacToeBoard::TicTacToeBoard(int size) : size(size > MAX_SIZE ? MAX_SIZE : size) {
    board = new char*[this->size];
    for (int i = 0; i < this->size; ++i) {
        board[i] = new char[this->size];
        for (int j = 0; j < this->size; ++j)
            board[i][j] = EMPTY;
    }
}

TicTacToeBoard::~TicTacToeBoard() {
    for (int i = 0; i < size; ++i)
        delete[] board[i];
    delete[] board;
}

bool TicTacToeBoard::isFull() const {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (board[i][j] == EMPTY)
                return false;
    return true;
}

bool TicTacToeBoard::checkWin(char player) const {
    // Check rows and columns
    for (int i = 0; i < size; ++i) {
        bool rowWin = true, colWin = true;
        for (int j = 0; j < size; ++j) {
            if (board[i][j] != player) rowWin = false;
            if (board[j][i] != player) colWin = false;
        }
        if (rowWin || colWin) return true;
    }

    // Check diagonals
    bool diag1Win = true, diag2Win = true;
    for (int i = 0; i < size; ++i) {
        if (board[i][i] != player) diag1Win = false;
        if (board[i][size - 1 - i] != player) diag2Win = false;
    }
    return diag1Win || diag2Win;
}

std::ostream& operator<<(std::ostream& out, const TicTacToeBoard& b) {
    for (int i = 0; i < b.size; ++i) {
        for (int j = 0; j < b.size; ++j)
            out << b.board[i][j] << " ";
        out << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToeBoard& b) {
    int x, y;
    do {
        std::cout << "Enter row and column (0 to " << b.size - 1 << "): ";
        in >> x >> y;
    } while (x < 0 || x >= b.size || y < 0 || y >= b.size || b.board[x][y] != EMPTY);
    b.board[x][y] = PLAYER;
    return in;
}

void TicTacToeBoard::makeComputerMove() {
    int x, y;
    do {
        x = rand() % size;
        y = rand() % size;
    } while (board[x][y] != EMPTY);
    board[x][y] = COMPUTER;
}

bool TicTacToeBoard::isGameOver(char& winner) const {
    if (checkWin(PLAYER)) {
        winner = PLAYER;
        return true;
    } else if (checkWin(COMPUTER)) {
        winner = COMPUTER;
        return true;
    } else if (isFull()) {
        winner = EMPTY;
        return true;
    }
    return false;
}
