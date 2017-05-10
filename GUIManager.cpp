//
// Created by jimena on 09/05/17.
//
#include "GUIManager.h"

GUIManager::GUIManager() {
    std::cout<<"GUI Created"<<std::endl;
    backgroundTexture.loadFromFile("Resources/Background1.jpeg");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0,0);
    backgroundSprite.setTextureRect(sf::IntRect(0,0,1400,800));

    chessBoardTexture.loadFromFile("Resources/ChessBoard.jpg");
    chessBoardSprite.setTexture(chessBoardTexture);
    chessBoardSprite.setPosition(500, 160);

    cardsFont.loadFromFile("Resources/CardsFont.TTF");
    titleLabel.setFont(cardsFont);
    titleLabel.setCharacterSize(60);
    titleLabel.setString("The Eight Queens' Problem");
    titleLabel.setPosition(50,50);
    titleLabel.setStyle(sf::Text::Italic);
}


void GUIManager::run(sf::RenderWindow &window) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        window.clear();
        window.draw(backgroundSprite);
        window.draw(chessBoardSprite);
        window.draw(titleLabel);



        window.display();
    }
}
