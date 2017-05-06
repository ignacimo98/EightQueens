#include <iostream>

#include "solver.h"


int main() {

    Solver solver;
    solver.solve8Queens();
    solver.printBoard();
    return 0;

}