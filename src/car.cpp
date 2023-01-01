#include "headers.h"


int car_VelX, car_VelY;

void Car ::handleEvent(SDL_Event &e)
{
    // If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        // Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            car_VelY -= car_VELYC;
            break;
        case SDLK_DOWN:
            car_VelY += car_VELYC;
            break;
        case SDLK_LEFT:
            car_VelX -= car_VELXC;
            break;
        case SDLK_RIGHT:
            car_VelX += car_VELXC;
            break;
        }
    }
    // If a key was released
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        // Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            car_VelY += car_VELYC;
            break;
        case SDLK_DOWN:
            car_VelY -= car_VELYC;
            break;
        case SDLK_LEFT:
            car_VelX += car_VELXC;
            break;
        case SDLK_RIGHT:
            car_VelX -= car_VELXC;
            break;
        }
    }
}

void Car ::move(Uint32 &score, Uint32 &life)
{
    // Move the car left or right
    CarQuad.x += car_VelX;

    // If the car went too far to the left or right
    if ((CarQuad.x < 0) or (CarQuad.x + 300 > SCREEN_WIDTH))
    {
        // Move back
        CarQuad.x -= car_VelX;
    }
    // Move the car up or down
    CarQuad.y += car_VelY;

    // If the car went too far up or down
    if ((CarQuad.y < 50) or (CarQuad.y + 150 > 880))
    {
        CarQuad.y = RESET_CAR_Y;
        // Move back
        life--;
    }

    for (int i = 0; i < 3; i++)
    {
        if (checkCollision(CarQuad, LevelTwo_Battery_rect[i]) == 1)
        // if( ( SpriteQuad.x < 0 ) || ( SpriteQuad.x + sprite_WIDTH > SCREEN_WIDTH ) || SDL_HasIntersection(&SpriteQuad, &obstacle) )
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundTrash, 0);
            LevelTwo_Battery_width[i] = 0;
            LevelTwo_Battery_height[i] = 0;
            score++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (checkCollision(CarQuad, LevelTwo_Waste_Bag_rect[i]) == 1)
        // if( ( SpriteQuad.x < 0 ) || ( SpriteQuad.x + sprite_WIDTH > SCREEN_WIDTH ) || SDL_HasIntersection(&SpriteQuad, &obstacle) )
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundTrash, 0);
            // cout << "vanish" << endl;
            LevelTwo_Waste_Bag_width[i] = 0;
            LevelTwo_Waste_Bag_height[i] = 0;
            score++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (checkCollision(CarQuad, LevelTwo_Can_rect[i]) == 1)
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundTrash, 0);
            LevelTwo_Can_width[i] = 0;
            LevelTwo_Can_height[i] = 0;
            score++;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (checkCollision(CarQuad, LevelTwo_Fuel_rect[i]) == 1)
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundLife, 0);
            LevelTwo_Fuel_width[i] = 0;
            LevelTwo_Fuel_height[i] = 0;
            LevelTwo_Fuel_pos_x[i] = 8100;
            // CarQuad.x = RESET_CAR_X;
            // CarQuad.y = RESET_CAR_Y;
            life++;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (checkCollision(CarQuad, LevelTwo_Pebble_rect[i]) == 1)
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundHit, 0);
            CarQuad.x = RESET_CAR_X;
            CarQuad.y = RESET_CAR_Y;
            if (life > 0 and (life-1)<=100)
                life--;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (checkCollision(CarQuad, LevelTwo_EnemyCar_rect[i]) == 1)
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundHit, 0);
            CarQuad.x = RESET_CAR_X;
            CarQuad.y = RESET_CAR_Y;
            if (life > 0 and (life-1)<=100)
                life--;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (checkCollision(CarQuad, LevelTwo_Traffic_rect[i]) == 1)
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundHit, 0);
            CarQuad.x = RESET_CAR_X;
            CarQuad.y = RESET_CAR_Y;
            if (life > 0 and (life-1)<=100)
                life--;
        }
    }
}

