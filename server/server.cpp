//
// Created by nevo on 27/12/16.
//

#include <iostream>
#include "managment/MainFlow.h"

int main(int argc, char *argv[]) {
    MainFlow *mf = new MainFlow(atoi(argv[1]));
    mf->input();
    delete (mf);
    return 0;
}