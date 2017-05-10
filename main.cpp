#include <iostream>

#include "solver.h"
#include <SFML/Graphics.hpp>
#include "GUIManager.h"
#include "screens.h"


int main() {

   /* Solver solver;
    solver.solve8Queens();
    solver.printBoard();*/

    std::vector<screen*> screens;
    int screen =0;

    sf::RenderWindow window(sf::VideoMode(1366,768), "EightQueens", sf::Style::Close | sf::Style::Titlebar);

    menu menuScreen;
    screens.push_back(&menuScreen);

    GUIManager guiManager;
    screens.push_back(&guiManager);

    while(screen>=0){
        screen = screens[screen]->run(window);
    }




    return EXIT_SUCCESS;
}