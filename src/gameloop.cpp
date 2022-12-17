//from here, i will navigate to other files. This is the dump and I will keep the mainfile for initialization and cleanup only
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>

#include "constants.h"

void handleEvent(SDL_Event& event,bool& gameRunning)
{
    while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                gameRunning = false;
        }
}


void gameloop(bool& gameRunning, RenderWindow STW){


    SDL_Texture* bgTexture = STW.loadTexture("res/images/levelonebackground.png");//i loaded first level here

    STW.clear();
    STW.render(bgTexture);
    STW.display();

}