//
// Created by Ignacio Mora on 5/5/17.
//

#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <sys/termios.h>
#include <zconf.h>
#include "Serial.h"

Serial::Serial() {
    connected = false;

    USB = open("/dev/cu.usbserial-AL00VOSH", O_RDWR| O_NOCTTY | O_NDELAY);


    struct termios tty;
    struct termios tty_old;
    memset (&tty, 0, sizeof(tty));

/* Error Handling */
    if ( tcgetattr ( USB, &tty ) != 0 ) {
        std::cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
        connected = false;
    }

/* Save old tty parameters */
    tty_old = tty;

/* Set Baud Rate */
    cfsetospeed (&tty, (speed_t)B9600);
    cfsetispeed (&tty, (speed_t)B9600);

/* Setting other Port Stuff */
    tty.c_cflag     &=  ~PARENB;            // Make 8n1
    tty.c_cflag     &=  ~CSTOPB;
    tty.c_cflag     &=  ~CSIZE;
    tty.c_cflag     |=  CS8;

    tty.c_cflag     &=  ~CRTSCTS;           // no flow control
    tty.c_cc[VMIN]   =  1;                  // read doesn't block
    tty.c_cc[VTIME]  =  5;                  // 0.5 seconds read timeout
    tty.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

/* Make raw */
    cfmakeraw(&tty);

/* Flush Port, then applies attributes */
    tcflush( USB, TCIFLUSH );
    connected = true;
    if ( tcsetattr ( USB, TCSANOW, &tty ) != 0) {
        std::cout << "Error " << errno << " from tcsetattr" << std::endl;
        connected = false;
    }


}

void Serial::writeData(std::string data, int largo) {

    int n_written = write( USB, data.c_str(), largo);

}

void Serial::readData() {
    int n = 0,
            spot = 0;
    char* buf = (char *) malloc(13);

/* Whole response*/
    char response[1024];
//    memset(response, '\0', sizeof response);

    n = read(USB, buf, 11);
    std::cout << n << std::endl;

//    do {
//        n = read( USB, buf, 1 );
//        std::cout<< n << std::endl;
//        sprintf( response, "%c", buf );
//        spot += n;
//    } while( *buf != '\r' && n > 0);

    if (n < 0) {
        std::cout << "Error reading: " << strerror(errno) << std::endl;
    }
    else if (n == 0) {
        std::cout << "Read nothing!" << std::endl;
    }
    else {
        std::cout << buf << std::endl;
    }

}

bool Serial::isConnected() {
    return connected;
}
