//
// Created by Ignacio Mora on 5/5/17.
//

#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <cstring>
#include <string>
#include <fstream>

class Serial
{

public:
	Serial();
    void writeData(std::string data, int largo);
    void readData();
    bool isConnected();

private:
    bool connected;
    int USB;
};

#endif
