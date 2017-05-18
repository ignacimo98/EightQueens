#include <iostream>

#include "solver.h"
#include <SFML/Graphics.hpp>
#include <zconf.h>
#include "GUIManager.h"

#include "Serial.h"

using namespace std;
int main() {

    Serial* Arduino = new Serial();


    while( Arduino->isConnected() ) {
        char palabra[] = "geekytheory";

        cout << "Arduino conectado" << endl;

//        Arduino->writeData(palabra, sizeof(palabra) - 1);

        usleep(500000);

        Arduino->readData();


        cout << "-------------------" << endl;
        usleep(1000);
    }

   /* Solver solver;
    solver.solve8Queens();
    solver.printBoard();*/

    sf::RenderWindow window(sf::VideoMode(1366,768), "EightQueens", sf::Style::Close | sf::Style::Titlebar);

    GUIManager application;
    application.run(window);


    return 0;
}