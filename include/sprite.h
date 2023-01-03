#ifndef SPRITE
#define SPRITE

#include "headers.h"

// The sprite that will move around on the screen
class Sprite // level one
{
public:
    // The dimensions of the sprite
    static const int sprite_WIDTH = 20;
    static const int sprite_HEIGHT = 20;

    // //Maximum axis velocity of the sprite
    static const int sprite_VELXC = 10;
    static const int sprite_VELYC = 50;

    // Initializes the variables
    Sprite();

    // Takes key presses and adjusts the sprite's velocity
    void handleEvent(SDL_Event &e);

    // Moves the sprite
    void move(Uint32 &score, Uint32 &life);

    // Shows the sprite on the screen

private:
    // The actual hardware texture
    SDL_Texture *mTexture;
};

// The sprite that will move around on the screen
class SpriteCave // level one
{
public:
    // The dimensions of the sprite
    static const int spriteCave_WIDTH = 20;
    static const int spriteCave_HEIGHT = 20;

    // //Maximum axis velocity of the sprite
    static const int spriteCave_VELXC = 10;
    static const int spriteCave_VELYC = 50;

    // Initializes the variables
    SpriteCave();

    // Takes key presses and adjusts the sprite's velocity
    void handleEvent(SDL_Event &e);

    // Moves the sprite
    void move(Uint32 &score, Uint32 &life);

    // Shows the sprite on the screen

private:
    // The actual hardware texture
    SDL_Texture *mTexture;
};

#endif