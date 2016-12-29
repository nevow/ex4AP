//
// Created by nevo on 27/12/16.
//

#include <iostream>
#include "sockets/Udp.h"
#include "managment/MainFlow.h"

int main(int argc, char *argv[]) {
    MainFlow *mf = new MainFlow(atoi(argv[1]));
    mf->input();

    Udp udp(1, atoi(argv[1]));
    udp.initialize();

    char buffer[1024];
    udp.reciveData(buffer, sizeof(buffer));
    cout << buffer << endl;
    udp.sendData("sup?");


//
//    usleep(5000);
    Udp udp2(1, 5554);
    udp2.initialize();

    char buffer2[1024];
    udp2.reciveData(buffer2, sizeof(buffer2));
    cout << buffer2 << endl;
    udp2.sendData("sup?");

// support more than one client?
    delete (mf);
    return 0;
}