#ifndef CAR
#define CAR

#include"all_headers.h"

class Car
{
public:
    static const int car_VELXC = 20;
    static const int car_VELYC = 10;
    void handleEvent(SDL_Event &e);
    void move(Uint32 &score, Uint32 &life);

private:
    // The actual hardware texture
    SDL_Texture *mTexture;
};
extern int car_VelX, car_VelY;
#endif