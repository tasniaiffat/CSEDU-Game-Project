#include "headers.h"

Sprite::Sprite()
{
    // Initialize the offsets
    SpriteQuad.x = 100;
    SpriteQuad.y = base;
}

void Sprite::handleEvent(SDL_Event &e)
{
    // If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        // Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            sprite_VelY -= sprite_VELYC;
            break;
        case SDLK_LEFT:
            sprite_VelX -= sprite_VELXC;
            break;
        case SDLK_RIGHT:
            sprite_VelX += sprite_VELXC;
            break;
        case SDLK_RETURN:
            if (sound)
                Mix_PlayChannel(-1, gSoundShooting, 0);
            shooting(1);
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
            sprite_VelY += sprite_VELYC;
            break;
        case SDLK_LEFT:
            sprite_VelX += sprite_VELXC;
            break;
        case SDLK_RIGHT:
            sprite_VelX -= sprite_VELXC;
            break;
        case SDLK_RETURN:
            shooting(0);
            break;
        }
    }
}

void Sprite::move(Uint32 &score, Uint32 &life)
{
    // cout << SpriteQuad.x << " " << drawn_rect.x << endl;
    // SpriteQuad.x++;
    SpriteQuad.x += sprite_VelX;
    drawn_rect.x = SpriteQuad.x + 50;

    SpriteQuad.y += sprite_VelY;
    drawn_rect.y = SpriteQuad.y;

    if (SpriteQuad.x >= 1200) // so that the sprite doesn't cross the window in the right
    {
        SpriteQuad.x -= sprite_VelX;
        drawn_rect.x = SpriteQuad.x + 50;
        SpriteQuad.x--;
        drawn_rect.x = SpriteQuad.x + 50;
    }

    if (SpriteQuad.x <= 100) // so that the sprite doesn't cross the window in the left
    {
        SpriteQuad.x -= sprite_VelX;
        drawn_rect.x = SpriteQuad.x + 50;
    }

    if (SpriteQuad.y <= -200) // so that the sprite doesn't get cross the window from the top
    {
        SpriteQuad.y -= sprite_VelY;
        drawn_rect.y = SpriteQuad.y;
    }

    if (SpriteQuad.y < base)
    {
        SpriteQuad.y += 10;
        drawn_rect.y = SpriteQuad.y;
    }

    int flag = 0;
    for (int i = 0; i < 3; i++)
    {
        if (checkCollision(drawn_rect, LevelOne_FloatingPlatform_rect[i]) == 1)
        // if( ( SpriteQuad.x < 0 ) || ( SpriteQuad.x + sprite_WIDTH > SCREEN_WIDTH ) || SDL_HasIntersection(&SpriteQuad, &obstacle) )
        {
            flag = 1;
            // cout << drawn_rect.x << " " << SpriteQuad.x << " " << LevelOne_FloatingPlatform_rect[i].x << endl;
            // SpriteQuad.x = drawn_rect.x = 579;
            // if (SpriteQuad.y > LevelOne_FloatingPlatform_pos_y[i] and SpriteQuad.y < LevelOne_FloatingPlatform_pos_y[i] + LevelOne_FloatingPlatform_width[i])
            // {
            SpriteQuad.y -= sprite_VelY;
            drawn_rect.y = SpriteQuad.y;
            base = LevelOne_FloatingPlatform_rect[i].y - SpriteQuad.h;

            // if ((drawn_rect.x + drawn_rect.w >= LevelOne_FloatingPlatform_pos_x[i] or drawn_rect.x <= LevelOne_FloatingPlatform_pos_x[i] + LevelOne_FloatingPlatform_width[i]) and (drawn_rect.y + drawn_rect.h > LevelOne_FloatingPlatform_pos_y[i] or drawn_rect.y < LevelOne_FloatingPlatform_pos_y[i] + LevelOne_FloatingPlatform_height[i]))
            // {
            //     if (SpriteQuad.x>150 and SpriteQuad.x + SpriteQuad.w + LevelOne_FloatingPlatform_width[i] > 700)
            //     {
            //         SpriteQuad.x = LevelOne_FloatingPlatform_rect[i].x - SpriteQuad.w + 150;
            //         drawn_rect.x = SpriteQuad.x + 50;
            //     }
            //     SpriteQuad.x -= sprite_VelX;
            //     drawn_rect.x = SpriteQuad.x + 50;
            //     SpriteQuad.x--;
            //     drawn_rect.x = SpriteQuad.x + 50;
            // }
            break;
            //}
        }
        else
            flag = 0;
    }

    if (flag == 0)
    {
        // cout << "landed" << endl;
        base = 579;
    }

    for (int i = 0; i < 1; i++)
    {
        if (checkCollision(drawn_rect, LevelOne_Life_rect[i]) == 1)
        // if( ( SpriteQuad.x < 0 ) || ( SpriteQuad.x + sprite_WIDTH > SCREEN_WIDTH ) || SDL_HasIntersection(&SpriteQuad, &obstacle) )
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundLife, 0);
            // cout << "vanish" << endl;
            LevelOne_Life_width[i] = 0;
            LevelOne_Life_height[i] = 0;
            LevelOne_Life_pos_x[i] = 6000;
            //SpriteQuad.x = RESET_SPRITE_X;
            // drawn_rect.x = SpriteQuad.x + 50;
            
            life++;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (checkCollision(drawn_rect, LevelOne_Battery_rect[i]) == 1)
        // if( ( SpriteQuad.x < 0 ) || ( SpriteQuad.x + sprite_WIDTH > SCREEN_WIDTH ) || SDL_HasIntersection(&SpriteQuad, &obstacle) )
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundTrash, 0);
            // cout << "vanish" << endl;
            LevelOne_Battery_width[i] = 0;
            LevelOne_Battery_height[i] = 0;

            score++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (checkCollision(drawn_rect, LevelOne_Waste_Bag_rect[i]) == 1)
        // if( ( SpriteQuad.x < 0 ) || ( SpriteQuad.x + sprite_WIDTH > SCREEN_WIDTH ) || SDL_HasIntersection(&SpriteQuad, &obstacle) )
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundTrash, 0);
            // cout << "vanish" << endl;
            LevelOne_Waste_Bag_width[i] = 0;
            LevelOne_Waste_Bag_height[i] = 0;

            score++;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        if (checkCollision(drawn_rect, LevelOne_Can_rect[i]) == 1)
        // if( ( SpriteQuad.x < 0 ) || ( SpriteQuad.x + sprite_WIDTH > SCREEN_WIDTH ) || SDL_HasIntersection(&SpriteQuad, &obstacle) )
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundTrash, 0);
            // cout << "vanish" << endl;
            LevelOne_Can_width[i] = 0;
            LevelOne_Can_height[i] = 0;

            score++;
        }
    }
    for (int i = 0; i < 1; i++)
    {
        if (checkCollision(drawn_rect, LevelOne_Barrier_1_rect[i]) == 1)
        // if( ( SpriteQuad.x < 0 ) || ( SpriteQuad.x + sprite_WIDTH > SCREEN_WIDTH ) || SDL_HasIntersection(&SpriteQuad, &obstacle) )
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundHit, 0);
            SpriteQuad.x = RESET_SPRITE_X;
            drawn_rect.x = SpriteQuad.x + 50;
            SpriteQuad.y = drawn_rect.y = RESET_SPRITE_Y;

            if (life > 0)
                life--;
        }
    }
    for (int i = 0; i < 1; i++)
    {
        if (checkCollision(drawn_rect, LevelOne_Barrier_2_rect[i]) == 1)
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundHit, 0);
            SpriteQuad.x = RESET_SPRITE_X;
            drawn_rect.x = SpriteQuad.x + 50;
            SpriteQuad.y = drawn_rect.y = RESET_SPRITE_Y;

            if (life > 0  )
                life--;
        }
    }
    for (int i = 0; i < 1; i++)
    {
        if (checkCollision(SpriteQuad, LevelOne_Hunter_1_rect[i]) == 1)
        {
            if (sound)
                Mix_PlayChannel(-1, gSoundHit, 0);
            SpriteQuad.x = RESET_SPRITE_X;
            drawn_rect.x = SpriteQuad.x + 50;
            SpriteQuad.y = drawn_rect.y = RESET_SPRITE_Y;

            if (life > 0 )
                life--;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (checkCollision(LevelOne_Bullet_rect[i], LevelOne_Hunter_1_rect[j]) == 1)
            {
                if (sound)
                    Mix_PlayChannel(-1, gSoundHit, 0);
                LevelOne_Bullet_go[i] = 0;
                LevelOne_Bullet_width[i] = 0;
                LevelOne_Bullet_height[i] = 0;
                LevelOne_Bullet_pos_x[i] = SpriteQuad.x + SpriteQuad.w / 2;
                LevelOne_Bullet_rect[i].x = SpriteQuad.x + SpriteQuad.w / 2;
                LevelOne_Bullet_pos_y[i] = SpriteQuad.y + SpriteQuad.h / 2;
                LevelOne_Bullet_rect[i].y = SpriteQuad.y + SpriteQuad.h / 2;

                LevelOne_Hunter_1_width[j] = 0;
                LevelOne_Hunter_1_height[j] = 0;

                score += 10;
            }
        }
    }
}