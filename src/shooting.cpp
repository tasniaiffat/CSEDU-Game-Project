#include "headers.h"

void shooting(int shoot)
{
    if (shoot == 1)
    {
        SpriteQuad.w = 0;
        SpriteQuad.h = 0;
        ShootingSprite_rect.w = 213;
        ShootingSprite_rect.h = 180;

        for (int i = 0; i < 5; i++)
        {
            LevelOne_Bullet_go[i] = 1;
            LevelOne_Bullet_width[i] = 27;
            LevelOne_Bullet_height[i] = 10;
        }

    }
    else
    {
        ShootingSprite_rect.w = 0;
        ShootingSprite_rect.h = 0;
        SpriteQuad.w = 213;
        SpriteQuad.h = 180;
    
    }
}

// void shootingCave(int shoot)
// {
//     if (shoot == 1)
//     {
//         SpriteCaveQuad.w = 0;
//         SpriteCaveQuad.h = 0;
//         ShootingSpriteCave_rect.w = 213;
//         ShootingSpriteCave_rect.h = 180;

//         for (int i = 0; i < 5; i++)
//         {
//             LevelCave_Bullet_go[i] = 1;
//             LevelCave_Bullet_width[i] = 27;
//             LevelCave_Bullet_height[i] = 10;
//         }

//     }
//     else
//     {
//         ShootingSpriteCave_rect.w = 0;
//         ShootingSpriteCave_rect.h = 0;
//         SpriteCaveQuad.w = 213;
//         SpriteCaveQuad.h = 180;
    
//     }
// }