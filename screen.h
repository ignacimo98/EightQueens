//
// Created by jimena on 09/05/17.
//

#ifndef EIGHTQUEENS_SCREEN_H
#define EIGHTQUEENS_SCREEN_H

#include <SFML/Graphics.hpp>

class screen{
public:
    virtual int run (sf::RenderWindow &window) = 0;
};

#endif //EIGHTQUEENS_SCREEN_H
