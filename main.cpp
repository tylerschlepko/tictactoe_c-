// main.cpp
#include "TicTacToeBoard.h"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    int choice, boardSize;
    std::cout << "Tic-Tac-Toe Game\n";

    do {
        std::cout << "1. Play the game\n2. Exit\nEnter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter board size (3 to 10): ";
            std::cin >> boardSize;

            if (boardSize < 3 || boardSize > MAX_SIZE) {
                std::cout << "Invalid size. Using default 3x3 board.\n";
                boardSize = 3;
            }

            TicTacToeBoard gameBoard(boardSize);
            char winner = EMPTY;
            while (!gameBoard.isGameOver(winner)) {
                std::cout << gameBoard;
                std::cin >> gameBoard;
                if (gameBoard.isGameOver(winner)) break;
                gameBoard.makeComputerMove();
            }

            std::cout << gameBoard;
            std::cout << "Game Over! ";
            if (winner == PLAYER) std::cout << "You win!\n";
            else if (winner == COMPUTER) std::cout << "Computer wins!\n";
            else std::cout << "It's a draw!\n";
        } else if (choice == 2) {
            std::cout << "Exiting game.\n";
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 2);

    return 0;
}
