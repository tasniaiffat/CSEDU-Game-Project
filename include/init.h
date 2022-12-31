#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

//to handle how long the main loop runs
void handleEvent(SDL_Event& event,bool& gameRunning);

//inside this function, the main flow will occur like loading textures, moving, calling other places etc unless i decide otherwise
void gameloop(bool& gameRunning,RenderWindow STW);