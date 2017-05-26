//
// Created by Ignacio Mora on 5/24/17.
//

#include "Board.h"

Board::Board() {
    int i, j;
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            board[i][j] = new Cell(i,j);
        }
    }

}

bool Board::hasQueen(int row, int col) {
    return board[row][col]->queen;

}

Cell* Board::getCell(int row, int col) {
    return board[row][col];
}
