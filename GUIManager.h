//
// Created by jimena on 09/05/17.
//

#ifndef EIGHTQUEENS_GUIMANAGER_H
#define EIGHTQUEENS_GUIMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "screen.h"
#include "solver.h"

class GUIManager : public screen{
public:
    GUIManager();
    ~GUIManager();
    int run(sf::RenderWindow &window);
    void moveQueens(sf::RenderWindow &window);
    void drawQueens(sf::RenderWindow &window);
    void createQueens();

    void solve8Queens(sf::RenderWindow &window);
    bool isSafe(int board[8][8], int row, int col);
    bool solve8QueensAux(int board[8][8], int col, sf::RenderWindow &window);

    bool running = true;
    bool move_made = true;


    int board[8][8] = {{0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0}};


    std::vector<sf::Sprite> queens;


    sf::Texture backgroundTexture;
    sf::Texture chessBoardTexture;
    sf::Texture miniQueenTexture;

    sf::Sprite chessBoardSprite;
    sf::Sprite backgroundSprite;
    sf::Text titleLabel;
    sf::Font cardsFont;
    sf::Music backgroundMusic;

};


#endif //EIGHTQUEENS_GUIMANAGER_H