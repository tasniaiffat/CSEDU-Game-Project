#ifndef FREE
#define FREE

#include "headers.h"

void close()
{
    // Free the music
    Mix_FreeMusic(gMusicMenu);
    gMusicMenu = NULL;
    Mix_FreeMusic(gMusicScoreboard);
    gMusicScoreboard = NULL;
    Mix_FreeMusic(gMusicLevelOne);
    gMusicLevelOne = NULL;
    Mix_FreeMusic(gMusicLevelTwo);
    gMusicLevelTwo = NULL;
    Mix_FreeMusic(gMusicLevelCave);
    gMusicLevelCave = NULL;
    Mix_FreeChunk(gSoundTrash);
    gSoundTrash = NULL;
    Mix_FreeChunk(gSoundLife);
    gSoundLife = NULL;
    Mix_FreeChunk(gSoundShooting);
    gSoundShooting = NULL;
    Mix_FreeChunk(gSoundHit);
    gSoundHit = NULL;
    Mix_FreeChunk(gSoundMouseClick);
    gSoundMouseClick = NULL;

    // Free loaded images
    gBGTexture.free();
    gBGTexture.free();
    gBGTexture.free();
    gBGTexture.free();
    gBGTexture.free();
    gBGLevelOne.free();
    gBGTexture.free();
    gBGTexture.free();
    gBGTexture.free();
    gBGTexture.free();
    gBGTexture.free();
    gBGTexture.free();

    gBGLevelCave.free();
    gBGLevelCaveLoading.free();
    gBGLevelCaveGameOver.free();

    gSymbolLifeTexture.free();
    gSymbolScoreTexture.free();

    // free different objects
    gSpriteTexture.free();
    gSpriteCaveTexture.free();
    gLevelOne_CanTexture.free();
    gLevelOne_FloatingPlatformTexture.free();
    gLevelOne_BatteryTexture.free();
    gRunning_platformTexture.free();
    gLevelOne_Waste_BagTexture.free();
    gFlyingLevelOne_Birds_1Texture.free();
    gLevelOne_Barrier_1Texture.free();
    gLevelOne_Barrier_2Texture.free();
    gLevelOne_BulletTexture.free();
    gLevelCave_BulletTexture.free();
    gLevelOne_Hunter_1Texture.free();
    gLevelOne_LionTexture.free();
    gLevelOne_TigerTexture.free();
    gLevelOne_LifeTexture.free();
    gLevelCave_LifeTexture.free();
    gLevelOne_Clouds1Texture.free();
    gLevelOne_Clouds2Texture.free();
    gLevelOne_Clouds3Texture.free();
    gShootingSpriteTexture.free();
    gShootingSpriteCaveTexture.free();
    gLevelTwo_TrafficTexture.free();
    gLevelTwo_EnemyCarTexture.free();
    gLevelTwo_PebbleTexture.free();
    gQuartzTexture.free();
    gPinkCrystalTexture.free();
    gGreenCrystalTexture.free();
    gFireballTexture.free();

    // free loaded text textures
    gUpdatedScoreTextureLevelOne.free();
    gUpdatedScoreTextureLevelTwo.free();
    gUpdatedLifeTextureLevelOne.free();
    gUpdatedLifeTextureLevelTwo.free();
    gUpdatedLifeTextureLevelCave.free();
    gUpdatedLifeTextureLevelCave.free();
    gHighestScoreTexture.free();
    gGreatestNameTexture.free();
    gBGTexture.free();
    gNameTexture.free();

    gScore.free();
    gLife.free();

    // Free global font
    TTF_CloseFont(gFont);
    gFont = NULL;

    // Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    // Quit SDL subsystems
    player.close_file();
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
#endif