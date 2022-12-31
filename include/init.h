#ifndef INIT
#define INIT

#include "headers.h"
// Starts up SDL and creates window
bool init();

//main gameloop
void gameloop(bool time_counted,Uint32 CURRENT_TIME);

#endif