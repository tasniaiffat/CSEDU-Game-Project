#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>
#include<vector>


#include "RenderWindow.h"//check if i need to render here
#include"constants.h"

//save in seperate debug release folders if you want platformer first linux video

//to run, make release. to play, ./Saving-the-Wild

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO)>0 )
        std::cout << "SDL_INIT has FAILED. SDL_ERROR: "<< SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_INIT has FAILED. SDL_ERROR: "<< SDL_GetError() << std::endl;
        
    RenderWindow STW("Saving The Wild", SCREEN_WIDTH, SCREEN_HEIGHT);

    bool gameRunning = true;

    SDL_Event event;

    // const float timeStep=0.01f;
    // float accumulator =0.0f;
    // float currentTime = utils::timeInSeconds();

    while(gameRunning)
    {   
        // int startTick = SDL_GetTicks();
        
        // float newTime = utils::timeInSeconds();
        // float frameTime = newTime - currentTime;

        // currentTime = newTime;
        // accumulator+= frameTime;

        handleEvent(event,gameRunning);//declared in initializations, defined in gameloop
        if(!gameRunning)
            break;

        gameloop(gameRunning,STW);//declared in initializations, defined in gameloop
    }

    STW.cleanUp();
    SDL_Quit();

    return 0;
}
