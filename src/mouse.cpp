#include "mouse.h"

// Buttons for different pages
LButton Menu_Buttons[8];
LButton SelectLevel_Buttons[3];
LButton Back_Button;

LButton::LButton()
{
    mPosition.x = 0;
    mPosition.y = 0;
}

void LButton::setPosition(int x, int y)
{
    mPosition.x = x;
    mPosition.y = y;
}

bool LButton::handleEvent(SDL_Event &E_MOUSE, int width, int height)
{
    if (E_MOUSE.type == SDL_MOUSEBUTTONDOWN)
    {
        if(sound) Mix_PlayChannel(-1, gSoundMouseClick, 0);
        //if (E_MOUSE.type == SDL_MOUSEBUTTONDOWN)
            // cout << "mouse down" << endl;
        // else
            // cout << "mouse up" << endl;
        // Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        // Check if mouse is in button
        bool inside = true;

        // Mouse is left of the button
        if (x < mPosition.x)
        // if (x < 483)
        {
            inside = false;
        }
        // Mouse is right of the button
        else if (x > mPosition.x + width)
        // else if (x > 483 + 400)
        {
            inside = false;
        }
        // Mouse above the button
        else if (y < mPosition.y)
        // else if (y < 296)
        {
            inside = false;
        }
        // Mouse below the button
        else if (y > mPosition.y + height)
        // else if (y > 296 + 120)
        {
            inside = false;
        }
        // cout << "inside " << inside << endl;

        if (inside)
        {
            // Set mouse over sprite
            switch (E_MOUSE.type)
            {
            case SDL_MOUSEBUTTONDOWN:
                return true;
                break;
            default:
                return false;
            }
        }
    }
    return false;
}