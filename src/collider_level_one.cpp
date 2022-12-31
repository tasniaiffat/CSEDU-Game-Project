#include "headers.h"

void Collider_LevelOne::render()
{
    // Show the Collider_LevelOne
    gLevelOne_FloatingPlatformTexture.render(0, 0, 1, 0, SDL_FLIP_NONE);
    gLevelOne_BatteryTexture.render(0, 0, 2, 0, SDL_FLIP_NONE);
    gLevelOne_Waste_BagTexture.render(0, 0, 3, 0, SDL_FLIP_NONE);
    gLevelOne_CanTexture.render(0, 0, 4, 0, SDL_FLIP_NONE);
    gFlyingLevelOne_Birds_1Texture.render(0, 0, 5, 0, SDL_FLIP_NONE);
    gLevelOne_BulletTexture.render(0, 0, 6, 0, SDL_FLIP_NONE);
    gLevelOne_Hunter_1Texture.render(0, 0, 7, 0, SDL_FLIP_NONE);
    gLevelOne_LionTexture.render(0, 0, 8, 0, SDL_FLIP_NONE);
    gLevelOne_TigerTexture.render(0, 0, 11, 0, SDL_FLIP_NONE);
    gLevelOne_LifeTexture.render(0, 0, 12, 0, SDL_FLIP_NONE);
    gLevelOne_Clouds1Texture.render(0, 0, 13, 0, SDL_FLIP_NONE);
    gLevelOne_Clouds2Texture.render(0, 0, 14, 0, SDL_FLIP_NONE);
    gLevelOne_Clouds3Texture.render(0, 0, 15, 0, SDL_FLIP_NONE);
    gLevelOne_Barrier_1Texture.render(0, 0, 22, 0, SDL_FLIP_NONE);
    gLevelOne_Barrier_2Texture.render(0, 0, 23, 0, SDL_FLIP_NONE);
    // gLevelOne_FloatingPlatformTexture.render(LevelOne_FloatingPlatform_pos_x[1], LevelOne_FloatingPlatform_pos_y[1], 1, 0, SDL_FLIP_NONE);
    // gLevelOne_FloatingPlatformTexture.render( posAx3, posAy3, 1, 0, SDL_FLIP_NONE );
}