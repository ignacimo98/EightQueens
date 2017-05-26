//
// Created by jimena on 09/05/17.
//

#ifndef EIGHTQUEENS_MENU_H
#define EIGHTQUEENS_MENU_H

#include "screen.h"
#include "string"

class menu : public screen{
public:
    menu();
    int run(sf::RenderWindow &window, std::string& port);
    static std::string port;
};

#endif //EIGHTQUEENS_MENU_H
