//
// Created by jimena on 09/05/17.
//

#ifndef EIGHTQUEENS_GUIMANAGER_H
#define EIGHTQUEENS_GUIMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <iostream>
#include "screen.h"
#include "solver.h"
#include "Board.h"
#include "Serial.h"

class GUIManager : public screen{
public:
    GUIManager();
    ~GUIManager();
    int run(sf::RenderWindow &window, std::string& port);
    void moveQueens(sf::RenderWindow &window);
    void drawQueens(sf::RenderWindow &window);
    void createQueens();
    void writeBoard();
    void checkJaque();



    void solve8Queens(sf::RenderWindow &window);
    bool isSafe(Board* board, int row, int col, sf::RenderWindow &window);
    bool solve8QueensAux(Board* board, int col, sf::RenderWindow &window);

    bool running = true;
    bool move_made = true;


    Board* board;



    std::vector<sf::Sprite> queens;


    std::string arduinoPort;
    sf::Texture backgroundTexture;
    sf::Texture chessBoardTexture;
    sf::Texture miniQueenTexture;
    sf::Texture miniQueenJaqueTexture;

    sf::Sprite chessBoardSprite;
    sf::Sprite backgroundSprite;
    sf::Text titleLabel;
    sf::Font cardsFont;
    sf::Music backgroundMusic;

private:
    Serial* arduinoManager;

};


#endif //EIGHTQUEENS_GUIMANAGER_H