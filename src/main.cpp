#include "headers.h"

int main(int argc, char *args[])
{
    bool time_counted=0;
    Back_Button.setPosition(BACK_BUTTON_POSX, BACK_BUTTON_POSY);

    Uint32 CURRENT_TIME=0;

    // Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        gameloop(time_counted,CURRENT_TIME);
    }

    // Free resources and close SDL
    close();
    return 0;
}
