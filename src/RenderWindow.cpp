#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* p_title, int p_w,int p_h)
    :STW(NULL),renderer(NULL)
{
    STW = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,p_w,p_h,SDL_WINDOW_SHOWN);
    if(STW == NULL)
    {
        std::cout << "Window has failed to init. Error: "<< SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(STW, -1, SDL_RENDERER_ACCELERATED );

}

SDL_Texture* RenderWindow::loadTexture(const char* p_filepath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filepath);

    if(texture == NULL)
        std::cout << "Failed to load texture. Error: "<<SDL_GetError() << std::endl;

    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(STW);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* p_tex)
{
    SDL_RenderCopy(renderer,p_tex,NULL,NULL);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}