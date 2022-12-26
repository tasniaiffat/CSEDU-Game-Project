//from here, i will navigate to other files. This is the dump and I will keep the mainfile for initialization and cleanup only
#include "constants.h"


void handleEvent(SDL_Event& event,bool& gameRunning)
{
    while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                gameRunning = false;
        }
}


void gameloop(bool& gameRunning, RenderWindow STW){//basically level 1


    SDL_Texture* bgTexture = STW.loadTexture("res/images/levelonebackground.png");

    Entity background(0,0,bgTexture);

    STW.clear();
    STW.render(background);
    STW.display();

}