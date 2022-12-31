#pragma once

#include<SDL2/SDL.h>
#include<math.h>

namespace utils
{
    inline float timeInSeconds()
    {
        float t = SDL_GetTicks();
        t = 0.001f*t;

        return t;
    }
}