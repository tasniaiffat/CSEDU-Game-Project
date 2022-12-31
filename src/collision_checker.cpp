#include "headers.h"

bool checkCollision(SDL_Rect a, SDL_Rect b)
{
    bool hasCollided = 1; // hasn't collided yet
    // a.w = SpriteQuad.w;
    // a.h = SpriteQuad.h;

    // The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    // Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if (bottomA < topB)
    {
        hasCollided = 0;
    }

    if (topA > bottomB)
    {
        hasCollided = 0;
    }

    if (rightA < leftB)
    {
        hasCollided = 0;
    }

    if (leftA > rightB)
    {
        hasCollided = 0;
    }
    return hasCollided;
}