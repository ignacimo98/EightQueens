//
// Created by Ignacio Mora on 5/5/17.
//

#ifndef EIGHTQUEENS_SOLVER_H
#define EIGHTQUEENS_SOLVER_H

#include <iostream>

class Solver {

public:
    Solver();
    void printBoard();
    void solve8Queens();

private:
    int board[8][8] = {{0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0}};
    bool isSafe(int board[8][8], int row, int col);
    bool solve8QueensAux(int board[8][8], int col);
};


#endif //EIGHTQUEENS_SOLVER_H
