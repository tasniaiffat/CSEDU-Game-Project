#include "headers.h"

void Collider_LevelTwo::render()
{
    gLevelOne_BatteryTexture.render(0, 0, 9, 0, SDL_FLIP_NONE);
    gLevelOne_Waste_BagTexture.render(0, 0, 10, 0, SDL_FLIP_NONE);
    gLevelOne_CanTexture.render(0, 0, 16, 0, SDL_FLIP_NONE);
    gLevelTwo_TrafficTexture.render(0, 0, 19, 0, SDL_FLIP_NONE);
    gLevelTwo_EnemyCarTexture.render(0, 0, 20, 0, SDL_FLIP_NONE);
    gLevelTwo_PebbleTexture.render(0, 0, 21, 0, SDL_FLIP_NONE);
    gLevelTwo_FuelTexture.render(0, 0, 26, 0, SDL_FLIP_NONE);
}