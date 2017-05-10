#include <iostream>

#include "solver.h"
#include <SFML/Graphics.hpp>
#include "GUIManager.h"


int main() {

   /* Solver solver;
    solver.solve8Queens();
    solver.printBoard();*/

    sf::RenderWindow window(sf::VideoMode(1366,768), "EightQueens", sf::Style::Close | sf::Style::Titlebar);

    GUIManager application;
    application.run(window);


    return 0;
}