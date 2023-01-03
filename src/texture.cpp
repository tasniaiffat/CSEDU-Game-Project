#include "headers.h"


LTexture gSymbolScoreTexture;
LTexture gSymbolLifeTexture;
// image of BGmenupage texture
LTexture gBGTexture;

// image of BGmenupage texture
LTexture gBGTitlePageTexture;
LTexture gBGMenuPageTexture;
LTexture gBGHelpPageTexture;
LTexture gBGSelectLevelTexture;
LTexture gBGNameInputTexture;
LTexture gBGScoreboardTexture;

// image textures of level one
LTexture gBGLevelOne;
LTexture gSpriteTexture;
LTexture gSpriteCaveTexture;
LTexture gLevelOne_FloatingPlatformTexture;
LTexture gLevelOne_BatteryTexture;
LTexture gRunning_platformTexture;
LTexture gLevelOne_Waste_BagTexture;
LTexture gLevelOne_CanTexture;
LTexture gFlyingLevelOne_Birds_1Texture;
LTexture gFlyingLevelOne_Birds_2Texture;
LTexture gShootingSpriteTexture;
LTexture gShootingSpriteCaveTexture;
LTexture gLevelOne_BulletTexture;
LTexture gLevelCave_BulletTexture;
LTexture gLevelOne_Hunter_1Texture;
LTexture gLevelOne_LionTexture;
LTexture gLevelOne_TigerTexture;
LTexture gLevelOne_LifeTexture;
LTexture gLevelCave_LifeTexture;
LTexture gLevelOne_Clouds1Texture;
LTexture gLevelOne_Clouds2Texture;
LTexture gLevelOne_Clouds3Texture;
LTexture gLevelOne_Barrier_1Texture;
LTexture gLevelOne_Barrier_2Texture;
LTexture gLevelTwo_PebbleTexture;

// text textures
LTexture gNameTexture;
LTexture gScore;
LTexture gUpdatedScoreTextureLevelOne;
LTexture gLife;
LTexture gUpdatedLifeTextureLevelOne;
LTexture gHighestScoreTexture;
LTexture gGreatestNameTexture;

// image textures of level two
LTexture gBGLevelTwo;
LTexture gUpdatedScoreTextureLevelTwo;
LTexture gUpdatedLifeTextureLevelTwo;
LTexture gCarTexture;
LTexture gLevelTwo_TrafficTexture;
LTexture gLevelTwo_EnemyCarTexture;
LTexture gLevelTwo_FuelTexture;

//image textures of cave level
LTexture gBGLevelCave;
LTexture gBGLevelCaveLoading;
LTexture gBGLevelCaveGameOver;
LTexture gQuartzTexture;
LTexture gFireballTexture;
LTexture gPinkCrystalTexture;
LTexture gGreenCrystalTexture;
LTexture gLevelCave_Hunter_1Texture;
LTexture gUpdatedScoreTextureLevelCave;
LTexture gUpdatedLifeTextureLevelCave;

// function implementation of classes and others
LTexture::LTexture()
{
    // Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture()
{
    // Deallocate
    free();
}

#if defined(SDL_TTF_MAJOR_VERSION)
bool LTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
    // Get rid of preexisting texture
    free();

    // Render text surface
    SDL_Surface *textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    if (textSurface != NULL)
    {
        // Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (mTexture == NULL)
        {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
            // Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        // Get rid of old surface
        SDL_FreeSurface(textSurface);
    }
    else
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }

    // Return success
    return mTexture != NULL;
}
#endif

bool LTexture::loadFromFile(std::string path)
{
    // Get rid of preexisting texture
    free();

    // The final texture
    SDL_Texture *newTexture = NULL;

    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        // Color key image
        // SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));

        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            // Get image dimensions
            mWidth = loadedSurface->w;
            // mWidth = 100;
            mHeight = loadedSurface->h;
            // mHeight = 100;

            // different pages of the game
            gBGTexture.mHeight = 878;
            gBGTexture.mWidth = 1402;
            gBGTexture.mHeight = 878;
            gBGTexture.mWidth = 1402;
            gBGTexture.mHeight = 878;
            gBGTexture.mWidth = 1402;
            gBGTexture.mHeight = 878;
            gBGTexture.mWidth = 1402;
            gBGTexture.mHeight = 878;
            gBGLevelCave.mHeight = 878;
            gBGLevelCave.mWidth = 1402;
            gBGLevelCaveLoading.mWidth = 1402;
            gBGLevelCaveLoading.mHeight = 878;
            gBGLevelCaveGameOver.mWidth = 1402;
            gBGLevelCaveGameOver.mHeight = 878;

            // objects of level one
            gSpriteTexture.mHeight = 180;
            gSpriteTexture.mWidth = 213;
            gSpriteCaveTexture.mHeight = 180;
            gSpriteCaveTexture.mWidth = 213;
            // gShootingSpriteTexture.mWidth = 213;
            // gShootingSpriteTexture.mHeight = 180;
            gLevelOne_FloatingPlatformTexture.mHeight = 156;
            gLevelOne_FloatingPlatformTexture.mWidth = 270;
            gRunning_platformTexture.mHeight = 178;
            gRunning_platformTexture.mWidth = 1402;
            gLevelOne_BatteryTexture.mWidth = 50;
            gLevelOne_BatteryTexture.mHeight = 90;
            gLevelOne_Waste_BagTexture.mWidth = 70;
            gLevelOne_Waste_BagTexture.mHeight = 84;
            gLevelOne_CanTexture.mWidth = 85;
            gLevelOne_CanTexture.mHeight = 51;
            gFlyingLevelOne_Birds_1Texture.mWidth = 205;
            gFlyingLevelOne_Birds_1Texture.mHeight = 154;
            // gLevelOne_BulletTexture.mWidth = 54;
            // gLevelOne_BulletTexture.mHeight = 20;
            gLevelOne_Hunter_1Texture.mWidth = 170;
            gLevelOne_Hunter_1Texture.mHeight = 180;
            gLevelOne_LionTexture.mWidth = 300;
            gLevelOne_LionTexture.mHeight = 214;
            gLevelOne_TigerTexture.mWidth = 380;
            gLevelOne_TigerTexture.mHeight = 164;
            gLevelOne_LifeTexture.mWidth = 100;
            gLevelOne_LifeTexture.mHeight = 100;
            gLevelCave_LifeTexture.mWidth = 100;
            gLevelCave_LifeTexture.mHeight = 100;
            gLevelOne_Clouds1Texture.mWidth = 250;
            gLevelOne_Clouds1Texture.mHeight = 100;
            gLevelOne_Clouds2Texture.mWidth = 250;
            gLevelOne_Clouds2Texture.mHeight = 100;
            gLevelOne_Clouds3Texture.mWidth = 250;
            gLevelOne_Clouds3Texture.mHeight = 100;
            gLevelCave_Hunter_1Texture.mWidth = 170;
            gLevelCave_Hunter_1Texture.mHeight = 180;


            // 0bjects of level two
            gCarTexture.mHeight = 600;
            gCarTexture.mWidth = 300;
        }
        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    // Return success
    mTexture = newTexture;
    return mTexture != NULL;
}

void LTexture::free()
{
    // Free texture if it exists
    if (mTexture != NULL)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
    // Modulate texture rgb
    SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
    // Set blending function
    SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
    // Modulate texture alpha
    SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::render(int x, int y, int check, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip)
{
    // Set rendering space and render to screen
    if (check == 0)
    {
        SDL_Rect renderQuad = {x, y, mWidth, mHeight};
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip); // this is just like SDL_RenderCopy with some additional stuff
        // Set clip rendering dimensions
        if (clip != NULL)
        {
            renderQuad.w = clip->w;
            renderQuad.h = clip->h;
        }
    }
    else if (check == 18)
    {
        SDL_Rect other_BG = {0, 0, 1402, 878};
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &other_BG, angle, center, flip);
    }

    else if (check == 1) // if the texture is of floating platform
    {
        for (int i = 0; i < 3; i++)
        {
            LevelOne_FloatingPlatform_rect[i].x = LevelOne_FloatingPlatform_pos_x[i];
            LevelOne_FloatingPlatform_rect[i].y = LevelOne_FloatingPlatform_pos_y[i];
            LevelOne_FloatingPlatform_rect[i].w = LevelOne_FloatingPlatform_width[i];
            LevelOne_FloatingPlatform_rect[i].h = LevelOne_FloatingPlatform_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_FloatingPlatform_rect[i], angle, center, flip);
        }
    }

    else if (check == 2) // if the texture is of LevelOne_Battery
    {
        for (int i = 0; i < 5; i++)
        {
            ////cout << "level 1 battery" << endl;
            LevelOne_Battery_rect[i].x = LevelOne_Battery_pos_x[i];
            LevelOne_Battery_rect[i].y = LevelOne_Battery_pos_y[i];
            LevelOne_Battery_rect[i].w = LevelOne_Battery_width[i];
            LevelOne_Battery_rect[i].h = LevelOne_Battery_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Battery_rect[i], angle, center, flip);
        }
    }

    else if (check == 3) // if the texture is of waste bag
    {
        for (int i = 0; i < 5; i++)
        {
            LevelOne_Waste_Bag_rect[i].x = LevelOne_Waste_Bag_pos_x[i];
            LevelOne_Waste_Bag_rect[i].y = LevelOne_Waste_Bag_pos_y[i];
            LevelOne_Waste_Bag_rect[i].w = LevelOne_Waste_Bag_width[i];
            LevelOne_Waste_Bag_rect[i].h = LevelOne_Waste_Bag_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Waste_Bag_rect[i], angle, center, flip);
        }
    }

    else if (check == 4) // if the texture is of LevelOne_Can
    {
        for (int i = 0; i < 6; i++)
        {
            LevelOne_Can_rect[i].x = LevelOne_Can_pos_x[i];
            LevelOne_Can_rect[i].y = LevelOne_Can_pos_y[i];
            LevelOne_Can_rect[i].w = LevelOne_Can_width[i];
            LevelOne_Can_rect[i].h = LevelOne_Can_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Can_rect[i], angle, center, flip);
        }
    }

    else if (check == 5) // if the texture is of LevelOne_Birds_ 1
    {
        for (int i = 0; i < 1; i++)
        {
            LevelOne_Birds_1_rect[i].x = LevelOne_Birds_1_pos_x[i];
            LevelOne_Birds_1_rect[i].y = LevelOne_Birds_1_pos_y[i];
            LevelOne_Birds_1_rect[i].w = LevelOne_Birds_1_width[i];
            LevelOne_Birds_1_rect[i].h = LevelOne_Birds_1_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Birds_1_rect[i], angle, center, flip);
        }
    }

    else if (check == 6) // if the texture is of LevelOne_Bullet
    {
        for (int i = 0; i < 5; i++)
        {
            LevelOne_Bullet_rect[i].x = LevelOne_Bullet_pos_x[i];
            LevelOne_Bullet_rect[i].y = LevelOne_Bullet_pos_y[i];
            LevelOne_Bullet_rect[i].w = LevelOne_Bullet_width[i];
            LevelOne_Bullet_rect[i].h = LevelOne_Bullet_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Bullet_rect[i], angle, center, flip);
        }
    }

    else if (check == 33) // if the texture is of LevelOne_Bullet
    {
        for (int i = 0; i < 5; i++)
        {
            LevelCave_Bullet_rect[i].x = LevelCave_Bullet_pos_x[i];
            LevelCave_Bullet_rect[i].y = LevelCave_Bullet_pos_y[i];
            LevelCave_Bullet_rect[i].w = LevelCave_Bullet_width[i];
            LevelCave_Bullet_rect[i].h = LevelCave_Bullet_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelCave_Bullet_rect[i], angle, center, flip);
        }
    }

    else if (check == 7) // if the texture is of LevelOne_Bullet
    {
        for (int i = 0; i < 2; i++)
        {
            LevelOne_Hunter_1_rect[i].x = LevelOne_Hunter_1_pos_x[i];
            LevelOne_Hunter_1_rect[i].y = LevelOne_Hunter_1_pos_y[i];
            LevelOne_Hunter_1_rect[i].w = LevelOne_Hunter_1_width[i];
            LevelOne_Hunter_1_rect[i].h = LevelOne_Hunter_1_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Hunter_1_rect[i], angle, center, flip);
        }
    }
    else if (check == 8)
    {
        LevelOne_Lion_rect[0].x = LevelOne_Lion_pos_x[0];
        LevelOne_Lion_rect[0].y = LevelOne_Lion_pos_y[0];
        LevelOne_Lion_rect[0].w = LevelOne_Lion_width[0];
        LevelOne_Lion_rect[0].h = LevelOne_Lion_height[0];
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Lion_rect[0], angle, center, flip);
    }

    else if (check == 9) // if the texture is of LevelOne_Battery
    {
        for (int i = 0; i < 3; i++)
        {
            // cout << "level 2 battery" << endl;
            LevelTwo_Battery_rect[i].x = LevelTwo_Battery_pos_x[i];
            LevelTwo_Battery_rect[i].y = LevelTwo_Battery_pos_y[i];
            LevelTwo_Battery_rect[i].w = LevelTwo_Battery_width[i];
            LevelTwo_Battery_rect[i].h = LevelTwo_Battery_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelTwo_Battery_rect[i], angle, center, flip);
        }
    }
    else if (check == 10) // if the texture is of waste bag
    {
        for (int i = 0; i < 3; i++)
        {
            LevelTwo_Waste_Bag_rect[i].x = LevelTwo_Waste_Bag_pos_x[i];
            LevelTwo_Waste_Bag_rect[i].y = LevelTwo_Waste_Bag_pos_y[i];
            LevelTwo_Waste_Bag_rect[i].w = LevelTwo_Waste_Bag_width[i];
            LevelTwo_Waste_Bag_rect[i].h = LevelTwo_Waste_Bag_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelTwo_Waste_Bag_rect[i], angle, center, flip);
        }
    }

    else if (check == 11)
    {
        LevelOne_Tiger_rect[0].x = LevelOne_Tiger_pos_x[0];
        LevelOne_Tiger_rect[0].y = LevelOne_Tiger_pos_y[0];
        LevelOne_Tiger_rect[0].w = LevelOne_Tiger_width[0];
        LevelOne_Tiger_rect[0].h = LevelOne_Tiger_height[0];
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Tiger_rect[0], angle, center, flip);
    }

    else if (check == 12)
    {
        LevelOne_Life_rect[0].x = LevelOne_Life_pos_x[0];
        LevelOne_Life_rect[0].y = LevelOne_Life_pos_y[0];
        LevelOne_Life_rect[0].w = LevelOne_Life_width[0];
        LevelOne_Life_rect[0].h = LevelOne_Life_height[0];
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Life_rect[0], angle, center, flip);
    }

    else if (check == 32)
    {
        LevelCave_Life_rect[0].x = LevelCave_Life_pos_x[0];
        LevelCave_Life_rect[0].y = LevelCave_Life_pos_y[0];
        LevelCave_Life_rect[0].w = LevelCave_Life_width[0];
        LevelCave_Life_rect[0].h = LevelCave_Life_height[0];
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelCave_Life_rect[0], angle, center, flip);
    }

    else if (check == 13)
    {
        LevelOne_Clouds1_rect[0].x = LevelOne_Clouds1_pos_x[0];
        LevelOne_Clouds1_rect[0].y = LevelOne_Clouds1_pos_y[0];
        LevelOne_Clouds1_rect[0].w = LevelOne_Clouds1_width[0];
        LevelOne_Clouds1_rect[0].h = LevelOne_Clouds1_height[0];
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Clouds1_rect[0], angle, center, flip);
    }
    else if (check == 14)
    {
        LevelOne_Clouds2_rect[0].x = LevelOne_Clouds2_pos_x[0];
        LevelOne_Clouds2_rect[0].y = LevelOne_Clouds2_pos_y[0];
        LevelOne_Clouds2_rect[0].w = LevelOne_Clouds2_width[0];
        LevelOne_Clouds2_rect[0].h = LevelOne_Clouds2_height[0];
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Clouds2_rect[0], angle, center, flip);
    }
    else if (check == 15)
    {
        LevelOne_Clouds3_rect[0].x = LevelOne_Clouds3_pos_x[0];
        LevelOne_Clouds3_rect[0].y = LevelOne_Clouds3_pos_y[0];
        LevelOne_Clouds3_rect[0].w = LevelOne_Clouds3_width[0];
        LevelOne_Clouds3_rect[0].h = LevelOne_Clouds3_height[0];
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Clouds3_rect[0], angle, center, flip);
    }

    else if (check == 16) // if the texture is of waste bag
    {
        for (int i = 0; i < 3; i++)
        {
            LevelTwo_Can_rect[i].x = LevelTwo_Can_pos_x[i];
            LevelTwo_Can_rect[i].y = LevelTwo_Can_pos_y[i];
            LevelTwo_Can_rect[i].w = LevelTwo_Can_width[i];
            LevelTwo_Can_rect[i].h = LevelTwo_Can_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelTwo_Can_rect[i], angle, center, flip);
        }
    }

    else if (check == 17)
    {
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &ShootingSprite_rect, angle, center, flip);
    }

    else if (check == 35)
    {
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &ShootingSpriteCave_rect, angle, center, flip);
    }

    else if(check == 19)
    {
        for (int i = 0; i < 2; i++)
        {
            LevelTwo_Traffic_rect[i].x = LevelTwo_Traffic_pos_x[i];
            LevelTwo_Traffic_rect[i].y = LevelTwo_Traffic_pos_y[i];
            LevelTwo_Traffic_rect[i].w = LevelTwo_Traffic_width[i];
            LevelTwo_Traffic_rect[i].h = LevelTwo_Traffic_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelTwo_Traffic_rect[i], angle, center, flip);
        }
    }

    else if(check == 20)
    {
        for (int i = 0; i < 3; i++)
        {
            LevelTwo_EnemyCar_rect[i].x = LevelTwo_EnemyCar_pos_x[i];
            LevelTwo_EnemyCar_rect[i].y = LevelTwo_EnemyCar_pos_y[i];
            LevelTwo_EnemyCar_rect[i].w = LevelTwo_EnemyCar_width[i];
            LevelTwo_EnemyCar_rect[i].h = LevelTwo_EnemyCar_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelTwo_EnemyCar_rect[i], angle, center, flip);
        }
    }
    else if(check == 21)
    {
        for (int i = 0; i < 2; i++)
        {
            LevelTwo_Pebble_rect[i].x = LevelTwo_Pebble_pos_x[i];
            LevelTwo_Pebble_rect[i].y = LevelTwo_Pebble_pos_y[i];
            LevelTwo_Pebble_rect[i].w = LevelTwo_Pebble_width[i];
            LevelTwo_Pebble_rect[i].h = LevelTwo_Pebble_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelTwo_Pebble_rect[i], angle, center, flip);
        }
    }   
    else if (check == 22) // if the texture is of waste bag
    {
        for (int i = 0; i < 1; i++)
        {
            LevelOne_Barrier_1_rect[i].x = LevelOne_Barrier_1_pos_x[i];
            LevelOne_Barrier_1_rect[i].y = LevelOne_Barrier_1_pos_y[i];
            LevelOne_Barrier_1_rect[i].w = LevelOne_Barrier_1_width[i];
            LevelOne_Barrier_1_rect[i].h = LevelOne_Barrier_1_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Barrier_1_rect[i], angle, center, flip);
        }
    }
    else if (check == 23) // if the texture is of waste bag
    {
        for (int i = 0; i < 1; i++)
        {
            LevelOne_Barrier_2_rect[i].x = LevelOne_Barrier_2_pos_x[i];
            LevelOne_Barrier_2_rect[i].y = LevelOne_Barrier_2_pos_y[i];
            LevelOne_Barrier_2_rect[i].w = LevelOne_Barrier_2_width[i];
            LevelOne_Barrier_2_rect[i].h = LevelOne_Barrier_2_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelOne_Barrier_2_rect[i], angle, center, flip);
        }
    }    
    else if(check == 24)
    {
        SymbolScore_rect.x = 25;
        SymbolScore_rect.y = 20;
        SymbolScore_rect.w = 40;
        SymbolScore_rect.h = 40;
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &SymbolScore_rect, angle, center, flip);
    }
    else if(check == 25)
    {
        SymbolLife_rect.x = 25;
        SymbolLife_rect.y = 70;
        SymbolLife_rect.w = 40;
        SymbolLife_rect.h = 40;
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &SymbolLife_rect, angle, center, flip);
    }
    else if (check == 26) // if the texture is of waste bag
    {
        for (int i = 0; i < 2; i++)
        {
            LevelTwo_Fuel_rect[i].x = LevelTwo_Fuel_pos_x[i];
            LevelTwo_Fuel_rect[i].y = LevelTwo_Fuel_pos_y[i];
            LevelTwo_Fuel_rect[i].w = LevelTwo_Fuel_width[i];
            LevelTwo_Fuel_rect[i].h = LevelTwo_Fuel_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelTwo_Fuel_rect[i], angle, center, flip);
        }
    } 

    else if (check == 27)
    {
        for (int i = 0; i < 3; i++)
        {
            LevelCave_Quartz_rect[i].x = LevelCave_Quartz_pos_x[i];
            LevelCave_Quartz_rect[i].y = LevelCave_Quartz_pos_y[i];
            LevelCave_Quartz_rect[i].w = LevelCave_Quartz_width[i];
            LevelCave_Quartz_rect[i].h = LevelCave_Quartz_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelCave_Quartz_rect[i], angle, center, flip);
        }
    }

    else if (check == 28)
    {
        for (int i = 0; i < 3; i++)
        {
            LevelCave_PinkCrystal_rect[i].x = LevelCave_PinkCrystal_pos_x[i];
            LevelCave_PinkCrystal_rect[i].y = LevelCave_PinkCrystal_pos_y[i];
            LevelCave_PinkCrystal_rect[i].w = LevelCave_PinkCrystal_width[i];
            LevelCave_PinkCrystal_rect[i].h = LevelCave_PinkCrystal_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelCave_PinkCrystal_rect[i], angle, center, flip);
        }
    }

    else if (check == 29)
    {
        for (int i = 0; i < 3; i++)
        {
            LevelCave_GreenCrystal_rect[i].x = LevelCave_GreenCrystal_pos_x[i];
            LevelCave_GreenCrystal_rect[i].y = LevelCave_GreenCrystal_pos_y[i];
            LevelCave_GreenCrystal_rect[i].w = LevelCave_GreenCrystal_width[i];
            LevelCave_GreenCrystal_rect[i].h = LevelCave_GreenCrystal_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelCave_GreenCrystal_rect[i], angle, center, flip);
        }
    }

    else if (check == 30) // if the texture is of Levelcave hunter
    {
        for (int i = 0; i < 1; i++)
        {
            LevelCave_Hunter_1_rect[i].x = LevelCave_Hunter_1_pos_x[i];
            LevelCave_Hunter_1_rect[i].y = LevelCave_Hunter_1_pos_y[i];
            LevelCave_Hunter_1_rect[i].w = LevelCave_Hunter_1_width[i];
            LevelCave_Hunter_1_rect[i].h = LevelCave_Hunter_1_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelCave_Hunter_1_rect[i], angle, center, flip);
        }
    }

    else if (check == 31)
    {
        for (int i = 0; i < 2; i++)
        {
            LevelCave_Fireball_rect[i].x = LevelCave_Fireball_pos_x[i];
            LevelCave_Fireball_rect[i].y = LevelCave_Fireball_pos_y[i];
            LevelCave_Fireball_rect[i].w = LevelCave_Fireball_width[i];
            LevelCave_Fireball_rect[i].h = LevelCave_Fireball_height[i];

            SDL_RenderCopyEx(gRenderer, mTexture, clip, &LevelCave_Fireball_rect[i], angle, center, flip);
        }
    }
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}

void LTexture ::RenderSprite(int x, int y, SDL_Rect *clip)
{
    SDL_RenderCopy(gRenderer, mTexture, clip, &SpriteQuad);
}


void LTexture ::RenderCar(int x, int y, SDL_Rect *clip)
{
    SDL_RenderCopy(gRenderer, mTexture, clip, &CarQuad);
}

void LTexture ::RenderSpriteCave(int x, int y, SDL_Rect *clip)
{
    SDL_RenderCopy(gRenderer, mTexture, clip, &SpriteCaveQuad);
}