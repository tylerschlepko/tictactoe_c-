// TicTacToeBoard.h
#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H

#include <iostream>

const int MAX_SIZE = 10;
const char PLAYER = 'X';
const char COMPUTER = 'O';
const char EMPTY = '.';

class TicTacToeBoard {
private:
    char **board;
    int size;
    bool isFull() const;
    bool checkWin(char player) const;

public:
    TicTacToeBoard(int size);
    ~TicTacToeBoard();

    friend std::ostream& operator<<(std::ostream& out, const TicTacToeBoard& b);
    friend std::istream& operator>>(std::istream& in, TicTacToeBoard& b);

    void makeComputerMove();
    bool isGameOver(char& winner) const;
};

#endif // TICTACTOEBOARD_H
