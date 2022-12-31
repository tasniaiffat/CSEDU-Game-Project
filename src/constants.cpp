#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "constants.h"

Entity::Entity(float p_x,float p_y,float p_w,float p_h,SDL_Texture* p_tex)
:x(p_x),y(p_y),w(p_w),h(p_h),tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = SCREEN_WIDTH;
    currentFrame.h = SCREEN_HEIGHT;
    
}

float Entity::getX()
{
    return x;
}

float Entity::getY()
{
    return y;
}

float Entity::getW()
{
    return w;
}

float Entity::getH()
{
    return h;
}

SDL_Texture* Entity::getTex()
{
    return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}