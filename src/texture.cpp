#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* p_title, int p_w,int p_h)
    :STW(NULL),renderer(NULL)
{
    STW = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,p_w,p_h,SDL_WINDOW_SHOWN);
    if(STW == NULL)
    {
        std::cout << "Window has failed to init. Error: "<< SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(STW, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

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


void RenderWindow::render(Entity &p_entity)//i can render both background and objects with this
{
    SDL_Rect src;//source image
    src.x=p_entity.getCurrentFrame().x;
    src.y=p_entity.getCurrentFrame().y;
    src.w=p_entity.getCurrentFrame().w;
    src.h=p_entity.getCurrentFrame().h;

    SDL_Rect dst;//destination image, where that image will load can be manipulated by x and y
    dst.x=p_entity.getX();
    dst.y=p_entity.getY();
    dst.w=p_entity.getW();
    dst.h=p_entity.getH();

    SDL_RenderCopy(renderer,p_entity.getTex(),&src,&dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}