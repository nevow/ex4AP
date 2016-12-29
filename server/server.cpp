//
// Created by nevo on 27/12/16.
//

#include <iostream>
#include "managment/MainFlow.h"

int main(int argc, char *argv[]) {
    MainFlow *mf = new MainFlow();
    mf->input(atoi(argv[1]));
    delete (mf);
    return 0;
}