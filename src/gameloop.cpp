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

    //load textures
    SDL_Texture* bgTexture = STW.loadTexture("res/images/levelonebackground.png");
    SDL_Texture* carTexture = STW.loadTexture("res/images/car.png");
    SDL_Texture* batteryTexture = STW.loadTexture("res/images/battery.png");

    //declare entities
    Entity background(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,bgTexture);
    Entity car(10,530,305,163,carTexture);
    Entity battery(1000,510,44,44,batteryTexture);

    std::vector<Entity> entities;


    //render thingies and finally display
    STW.clear();
    STW.render(background);

    // int scrollingOffset =0;
    // --scrollingOffset;
    // if(scrollingOffset < SCREEN_WIDTH)
    // {
    //     scrollingOffset =0;
    // }

    STW.render(car);
    STW.render(battery);
    STW.display();
    SDL_Delay(1000/30);

}