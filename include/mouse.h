#ifndef BUTTONS
#define BUTTONS

#include "headers.h"

class LButton
{
public:
    // Initializes internal variables
    LButton();

    // Sets top left position
    void setPosition(int x, int y);

    // Handles mouse event
    bool handleEvent(SDL_Event &e, int width, int height);
private:
    // Top left position
    SDL_Point mPosition;
};

// Buttons for different pages
extern LButton Menu_Buttons[8];
extern LButton SelectLevel_Buttons[3];
extern LButton Back_Button;

#endif