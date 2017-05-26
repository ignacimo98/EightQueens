//
// Created by Ignacio Mora on 5/5/17.
//

#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <cstring>
#include <string>
#include <fstream>
#include "Board.h"

class Serial
{

public:


    Serial(std::string COM);

    int writeData(std::string data, int largo);
    void readData();
    bool isConnected();
    void turnOn(int row, int col, char color);
    void turnOff(int row, int col);

    void lightBoard(Board *board);

private:
    bool connected;
    int USB;
};

#endif
