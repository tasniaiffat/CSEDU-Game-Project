#ifndef texture
#define texture

#include "headers.h"

class LTexture
{
public:
    // Initializes variables
    LTexture();
    // Deallocates memory
    ~LTexture();

    // Loads image at specified path
    bool loadFromFile(std::string path);

#if defined(SDL_TTF_MAJOR_VERSION)
    // Creates image from font string
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
#endif

    // Deallocates texture
    void free();

    // Set color modulation
    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    // Set blending
    void setBlendMode(SDL_BlendMode blending);

    // Set alpha modulation
    void setAlpha(Uint8 alpha);

    // Renders texture at given point
    void render(int x, int y, int check, SDL_Rect *clip = NULL, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void RenderSprite(int x, int y, SDL_Rect *clip);
    void RenderCar(int x, int y, SDL_Rect *clip);

    // Gets image dimensions
    int getWidth();
    int getHeight();

private:
    // The actual hardware texture
    SDL_Texture *mTexture;

    // Image dimensions
    int mWidth;
    int mHeight;
};

// image of BGmenupage texture
extern LTexture gBGTitlePageTexture;
extern LTexture gBGMenuPageTexture;
extern LTexture gBGHelpPageTexture;
extern LTexture gBGSelectLevelTexture; 
extern LTexture gBGNameInputTexture;
extern LTexture gBGScoreboardTexture;


extern LTexture gSymbolScoreTexture;
extern LTexture gSymbolLifeTexture;
extern LTexture gBGTexture;
extern LTexture gBGLevelOne;
extern LTexture gSpriteTexture;
extern LTexture gLevelOne_FloatingPlatformTexture;
extern LTexture gLevelOne_BatteryTexture;
extern LTexture gRunning_platformTexture;
extern LTexture gLevelOne_Waste_BagTexture;
extern LTexture gLevelOne_CanTexture;
extern LTexture gFlyingLevelOne_Birds_1Texture;
extern LTexture gFlyingLevelOne_Birds_2Texture;
extern LTexture gShootingSpriteTexture;
extern LTexture gLevelOne_BulletTexture;
extern LTexture gLevelOne_Hunter_1Texture;
extern LTexture gLevelOne_LionTexture;
extern LTexture gLevelOne_TigerTexture;
extern LTexture gLevelOne_LifeTexture;
extern LTexture gLevelOne_Clouds1Texture;
extern LTexture gLevelOne_Clouds2Texture;
extern LTexture gLevelOne_Clouds3Texture;
extern LTexture gLevelOne_Barrier_1Texture;
extern LTexture gLevelOne_Barrier_2Texture;

// text textures
extern LTexture gNameTexture;
extern LTexture gScore;
extern LTexture gUpdatedScoreTextureLevelOne;
extern LTexture gLife;
extern LTexture gUpdatedLifeTextureLevelOne;
extern LTexture gHighestScoreTexture;
extern LTexture gGreatestNameTexture;

// image textures of level two
extern LTexture gBGLevelTwo;
extern LTexture gUpdatedScoreTextureLevelTwo;
extern LTexture gUpdatedLifeTextureLevelTwo;
extern LTexture gCarTexture;
extern LTexture gLevelTwo_TrafficTexture;
extern LTexture gLevelTwo_EnemyCarTexture;
extern LTexture gLevelTwo_PebbleTexture;
extern LTexture gLevelTwo_FuelTexture;

//image textures of cavelevel
extern LTexture gBGLevelCave;
extern LTexture gBGLevelCaveGameOver;
extern LTexture gBGLevelCaveLoading;
extern LTexture gQuartzTexture;
extern LTexture gPinkCrystalTexture;
extern LTexture gGreenCrystalTexture;
extern LTexture gFireballTexture;
extern LTexture gLevelCave_Hunter_1Texture;
extern LTexture gUpdatedScoreTextureLevelCave;
extern LTexture gUpdatedLifeTextureLevelCave;

#endif



