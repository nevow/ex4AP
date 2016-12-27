#include "src/managment/MainFlow.h"

int main() {
    MainFlow *mf = new MainFlow();
    mf->input();
    delete (mf);
    return 0;
}