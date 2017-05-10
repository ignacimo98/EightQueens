//
// Created by jimena on 09/05/17.
//

#ifndef EIGHTQUEENS_GUIMANAGER_H
#define EIGHTQUEENS_GUIMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class GUIManager{
public:
    GUIManager();
    void run(sf::RenderWindow &window);
    bool running = true;



///Cosas de la segunda pantalla
    sf::Texture backgroundTexture;
    sf::Texture chessBoardTexture;
    sf::Sprite chessBoardSprite;
    sf::Sprite backgroundSprite;
    sf::Text titleLabel;
    sf::Font cardsFont;
    sf::Music backgroundMusic;
};


#endif //EIGHTQUEENS_GUIMANAGER_H
