//
// Created by Ignacio Mora on 5/24/17.
//

#ifndef EIGHTQUEENS_BOARD_H
#define EIGHTQUEENS_BOARD_H


#include "Cell.h"

class Board {
public:
    Board();

    Cell* board[8][8];

    Cell* getCell(int row, int col);

    bool hasQueen(int row, int col);

};


#endif //EIGHTQUEENS_BOARD_H
