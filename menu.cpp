//
// Created by jimena on 09/05/17.
//
#include <iostream>
#include "menu.h"

menu::menu() {}

int menu::run(sf::RenderWindow &window) {
    sf::Event event;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Texture queenTexture;
    sf::Sprite queenSprite;
    sf::Font cardsFont;
    sf::Text titleLabel;
    sf::Text comPortLabel;
    sf::Text comStatus;
    sf::Text startLabel;


    int menuNumber = 0;

    bool running = true;
    std::string comPort;


    backgroundTexture.loadFromFile("Resources/Background1.jpeg");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0,0);
    backgroundSprite.setTextureRect(sf::IntRect(0,0,1400,800));

    queenTexture.loadFromFile("Resources/Queen.png");
    queenTexture.setSmooth(true);
    queenSprite.setTexture(queenTexture);
    queenSprite.setPosition(850, 380);



    cardsFont.loadFromFile("Resources/CardsFont.TTF");

    titleLabel.setFont(cardsFont);
    titleLabel.setCharacterSize(45);
    titleLabel.setString("The Eight Queens' Problem");
    titleLabel.setPosition(450,200);

    comPortLabel.setFont(cardsFont);
    comPortLabel.setCharacterSize(40);
    comPortLabel.setString("COM Port");
    comPortLabel.setPosition(400, 350);

    comStatus.setFont(cardsFont);
    comStatus.setCharacterSize(40);
    comStatus.setPosition(680, 350);

    startLabel.setFont(cardsFont);
    startLabel.setCharacterSize(40);
    startLabel.setString("Start");
    startLabel.setPosition(400, 450);




    while(running){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                return -1;
            }

            if(event.type == sf::Event::TextEntered && menuNumber ==0){
                comPort.push_back((char)event.text.unicode);
            }

            if(event.type == sf::Event::KeyPressed){
                switch (event.key.code){
                    case sf::Keyboard::Escape:
                        return 0;
                    case sf::Keyboard::Up:
                        menuNumber--;
                        if(menuNumber<0)
                            menuNumber=0;
                        break;
                    case sf::Keyboard::Down:
                        menuNumber++;
                        if(menuNumber>1)
                            menuNumber=1;
                        break;
                    case sf::Keyboard::Return:
                        if(menuNumber==1)
                            return 1;
                    default:
                        break;
                }
            }

            if(event.key.code == sf::Keyboard::BackSpace && comPort.size()!=0 && menuNumber == 0){
                comPort.pop_back();
            }
        }
        if (menuNumber == 0){
            comPortLabel.setColor(sf::Color::Red);
            startLabel.setColor(sf::Color::White);
        }
        else if(menuNumber==1){
            comPortLabel.setColor(sf::Color::White);
            startLabel.setColor(sf::Color::Red);
        }

        comStatus.setString(comPort);

        window.clear();

        window.draw(backgroundSprite);
        window.draw(queenSprite);
        window.draw(titleLabel);
        window.draw(comPortLabel);
        window.draw(comStatus);
        window.draw(startLabel);

        window.display();
    }


}
