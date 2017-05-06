//
// Created by Ignacio Mora on 5/5/17.
//

#include "solver.h"

Solver::Solver() {
    printBoard();
}

void Solver::printBoard(){
    int i, j;

    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            std::cout << board[i][j] << " ";
        }
        std::cout << std:: endl;
    }
}

bool Solver::isSafe(int board[8][8], int row, int col) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j>= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; i < 8 && j >= 0; i++, j--)
        if (board[i][j])
            return false;
    return true;


}

bool Solver::solve8QueensAux(int board[8][8], int col) {
    if (col >= 8)
        return true;

    int i;

    for (i = 0; i < 8; i++){
        if (isSafe(board, i, col)){
            board[i][col] = 1;

            if (solve8QueensAux(board, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

void Solver::solve8Queens(){

    if (solve8QueensAux(board, 0) == false){
        std::cout << "There's no solution";
    }

}