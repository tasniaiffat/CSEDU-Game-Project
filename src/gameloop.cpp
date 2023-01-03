#include "headers.h"
#include "stages.h"

int level_one_played = 0;
int level_two_played = 0;
int flag_music_2 = 0; 

void gameloop(bool time_counted,Uint32 CURRENT_TIME)
{
    stage= TITLE;
    bool closewindow = false;
        SDL_Event E_MAIN;
        while (!closewindow)
        {
            SDL_PollEvent(&E_MAIN);
            if (stage == TITLE)
            {
                if (!time_counted)
                {
                    CURRENT_TIME = SDL_GetTicks();
                    time_counted = true;
                }

                if (SDL_GetTicks() - CURRENT_TIME < 4000)
                {
                    loadMediaTitle();
                    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    SDL_RenderClear(gRenderer);

                    // Render background
                    gBGTexture.render(0, 0, 18, 0, SDL_FLIP_NONE);
                    SDL_RenderPresent(gRenderer);
                }
                else
                {
                    time_counted = false;
                    stage = MENU;
                }
            }

            if (stage == LOCKED)
            {
                if (!time_counted)
                {
                    CURRENT_TIME = SDL_GetTicks();
                    time_counted = true;
                }

                if (SDL_GetTicks() - CURRENT_TIME < 4000)
                {
                    loadMediaLocked();
                    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    SDL_RenderClear(gRenderer);

                    // Render background
                    gBGTexture.render(0, 0, 18, 0, SDL_FLIP_NONE);
                    SDL_RenderPresent(gRenderer);
                }
                else
                {
                    time_counted = false;
                    stage = SELECT_LEVEL;
                }
            }

            if (stage == UNLOCKED)
            {
                if (!time_counted)
                {
                    CURRENT_TIME = SDL_GetTicks();
                    time_counted = true;
                }

                if (SDL_GetTicks() - CURRENT_TIME < 4000)
                {
                    loadMediaUnlocked();
                    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    SDL_RenderClear(gRenderer);

                    // Render background
                    gBGTexture.render(0, 0, 18, 0, SDL_FLIP_NONE);
                    SDL_RenderPresent(gRenderer);
                }
                else
                {
                    time_counted = false;
                    stage = SELECT_LEVEL;
                }
            }

            if (stage == SORRY)
            {
                if (!time_counted)
                {
                    CURRENT_TIME = SDL_GetTicks();
                    time_counted = true;
                }

                if (SDL_GetTicks() - CURRENT_TIME < 4000)
                {
                    loadMediaSorry();
                    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    SDL_RenderClear(gRenderer);

                    // Render background
                    gBGTexture.render(0, 0, 18, 0, SDL_FLIP_NONE);
                    SDL_RenderPresent(gRenderer);
                }
                else
                {
                    time_counted = false;
                    stage = MENU;
                }
            }

            else if (stage == MENU)
            {
                level_one_played = 0;
                level_two_played = 0;
                score_levelOne = 0;
                score_levelTwo = 0;
                score_levelCave =0;
                life_levelOne = 10;
                life_levelTwo = 10;
                life_levelCave =10;
                if (Mix_PlayingMusic() != 0 and flag_music == 0)
                {
                    Mix_HaltMusic();
                    flag_music = 1;
                }

                loadMediaMenu();
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                if (Mix_PlayingMusic() == 0)
                {
                    // Play the music
                    if (music)
                        Mix_PlayMusic(gMusicMenu, -1);
                }
                // Render background
                gBGTexture.render(0, 0, 18, 0, SDL_FLIP_NONE);
                SDL_RenderPresent(gRenderer);
            }

            else if (stage == SELECT_LEVEL)
            {
                if (Mix_PlayingMusic() == 0)
                {
                    // Play the music
                    if (music)
                        Mix_PlayMusic(gMusicMenu, -1);
                }
                loadMediaSelectLevel();
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);
                // Render background
                gBGTexture.render(0, 0, 18, 0, SDL_FLIP_NONE);
                SDL_RenderPresent(gRenderer);
            }

            else if (stage == HELP)
            {
                loadMediaHelp();
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);
                // Render background
                gBGTexture.render(0, 0, 18, 0, SDL_FLIP_NONE);
                SDL_RenderPresent(gRenderer);
            }

            else if (stage == SCOREBOARD)
            {
                loadMediaScoreboard();
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);
                // Render background
                gBGTexture.render(0, 0, 18, 0, SDL_FLIP_NONE);
                player.output_highest_score();
                player.output_name();
                SDL_RenderPresent(gRenderer);
            }

            while (SDL_PollEvent(&E_MAIN) != 0) // poll event of whole game
            {
                if (E_MAIN.type == SDL_QUIT)
                {
                    closewindow = true;
                }
                else if (E_MAIN.type == SDL_MOUSEBUTTONDOWN)
                {
                    if (stage == MENU)
                    {
                        if (Menu_Buttons[0].handleEvent(E_MAIN, MENU_PAGE_BUTTON_WIDTH, MENU_PAGE_BUTTON_HEIGHT))
                        {
                            stage = NAME_INPUT;
                        }
                        else if (Menu_Buttons[1].handleEvent(E_MAIN, MENU_PAGE_BUTTON_WIDTH, MENU_PAGE_BUTTON_HEIGHT))
                        {
                            stage = HELP;
                        }
                        else if (Menu_Buttons[2].handleEvent(E_MAIN, MENU_PAGE_BUTTON_WIDTH, MENU_PAGE_BUTTON_HEIGHT))
                        {
                            stage = SCOREBOARD;
                        }
                        else if (Menu_Buttons[3].handleEvent(E_MAIN, 103, 103))
                        {
                            //cout << "turn off sound" << endl;
                            sound = false;
                        }
                        else if (Menu_Buttons[4].handleEvent(E_MAIN, 103, 103))
                        {
                            sound = true;
                        }
                        else if (Menu_Buttons[7].handleEvent(E_MAIN, 106, 106))
                        {
                            closewindow = true;
                        }
                    }
                    else if (stage == HELP or stage == SCOREBOARD or stage == SELECT_LEVEL or stage == LEVEL_ONE_LOADING or stage == LEVEL_TWO_LOADING)
                    {
                        if (Back_Button.handleEvent(E_MAIN, BACK_BUTTON_WIDTH, BACK_BUTTON_HEIGHT))
                        {
                            stage = MENU;
                        }
                    }
                }

                if (stage == NAME_INPUT)
                {
                    loadMediaNameInput();
                    // Set text color as black
                    SDL_Color textColor = {255, 255, 255, 0xFF};
                    // The current input text.
                    std::string inputText = " ";

                    gNameTexture.loadFromRenderedText(inputText.c_str(), textColor);
                    // Enable text input
                    SDL_StartTextInput();
                    bool renderText = false;
                    SDL_Event E_NAME;

                    while (stage != SELECT_LEVEL)
                    {
                        while (SDL_PollEvent(&E_NAME) != 0)
                        {
                            if (E_NAME.type == SDL_QUIT)
                            {
                                closewindow = true;
                            }
                            // User requests quit
                            // Special key input
                            if (E_NAME.type == SDL_KEYDOWN)
                            {
                                if (E_NAME.key.keysym.sym == SDLK_RETURN) // go to game
                                {
                                    // Disable text input
                                    SDL_StopTextInput();
                                    //cout << player.input_name << endl;
                                    stage = SELECT_LEVEL; // name input done
                                    break;
                                }

                                // Handle backspace
                                if (E_NAME.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0)
                                {
                                    // lop off character
                                    inputText.pop_back();
                                    renderText = true;
                                }
                                // Handle copy
                                else if (E_NAME.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
                                {
                                    SDL_SetClipboardText(inputText.c_str());
                                }
                                // Handle paste
                                else if (E_NAME.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
                                {
                                    inputText = SDL_GetClipboardText();
                                    renderText = true;
                                }
                            }
                            // Special text input event
                            else if (E_NAME.type == SDL_TEXTINPUT)
                            {
                                // Not copy or pasting
                                if (!(SDL_GetModState() & KMOD_CTRL && (E_NAME.text.text[0] == 'c' || E_NAME.text.text[0] == 'C' || E_NAME.text.text[0] == 'v' || E_NAME.text.text[0] == 'V')))
                                {
                                    // Append character
                                    inputText += E_NAME.text.text;
                                    renderText = true;
                                }
                            }
                        }

                        player.input_name = inputText;

                        // Rerender text if needed
                        if (renderText)
                        {
                            gNameTexture.loadFromRenderedText(inputText.c_str(), textColor);
                        }

                        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                        SDL_RenderClear(gRenderer);
                        // Render background
                        gBGTexture.render(0, 0, 18, 0, SDL_FLIP_NONE);
                        gNameTexture.render(400, 480, 0, 0, SDL_FLIP_NONE);
                        SDL_RenderPresent(gRenderer);

                        if (closewindow)
                            break;
                    }
                }

                else if (stage == SELECT_LEVEL)
                {
                    //life_levelCave=10;
                    if (SelectLevel_Buttons[0].handleEvent(E_MAIN, SELECT_LEVEL_BUTTON_WIDTH, SELECT_LEVEL_BUTTON_HEIGHT))
                    {
                        if (level_one_played < 2)
                        {
                            stage = LEVEL_ONE_LOADING;
                        }
                        else
                        {
                            // level_one_played=0;
                            stage = SORRY;
                        }
                    }

                    else if (SelectLevel_Buttons[1].handleEvent(E_MAIN, SELECT_LEVEL_BUTTON_WIDTH, SELECT_LEVEL_BUTTON_HEIGHT))
                    {
                        if (score_levelOne < 1200)
                            stage = LOCKED;
                        else
                        {
                            stage = LEVEL_TWO_LOADING;
                            level_two_played++;
                        }
                    }

                    else if (SelectLevel_Buttons[2].handleEvent(E_MAIN, SELECT_LEVEL_BUTTON_WIDTH, SELECT_LEVEL_BUTTON_HEIGHT))
                    {
                        // cout << "enter level " << 3 << endl;
                        //life_levelCave=10;
                        stage = LEVEL_CAVE_LOADING;
                    }
                
                }

                else if (stage == LEVEL_ONE_LOADING)
                {
                    Mix_HaltMusic();
                    if (!time_counted)
                    {
                        CURRENT_TIME = SDL_GetTicks();
                        time_counted = true;
                    }

                    if (SDL_GetTicks() - CURRENT_TIME < 4000)
                    {
                        loadMediaLEVEL_ONE_LOADING();
                        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                        SDL_RenderClear(gRenderer);

                        // Render background
                        gBGTexture.render(0, 0, 0, 0, SDL_FLIP_NONE);
                        SDL_RenderPresent(gRenderer);
                    }
                    else
                    {
                        time_counted = false;
                        stage = LEVEL_ONE;
                    }
                }

                else if (stage == LEVEL_ONE_GAME_OVER)
                {

                    Mix_HaltMusic();

                    if (!time_counted)
                    {
                        CURRENT_TIME = SDL_GetTicks();
                        time_counted = true;
                    }
                    if (SDL_GetTicks() - CURRENT_TIME < 4000)
                    {
                        // cout << SDL_GetTicks() - CURRENT_TIME << endl;
                        loadMediaLEVEL_ONE_GAME_OVER();
                        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                        SDL_RenderClear(gRenderer);
                        gBGTexture.render(0, 0, 0, 0, SDL_FLIP_NONE);
                        SDL_RenderPresent(gRenderer);
                    }
                    else
                    {
                        time_counted = false;
                        //life_levelCave=10;
                        stage = SELECT_LEVEL;
                    }
                }

                else if (stage == LEVEL_TWO_LOADING)
                {
                    Mix_HaltMusic();
                    if (!time_counted)
                    {
                        CURRENT_TIME = SDL_GetTicks();
                        time_counted = true;
                    }

                    if (SDL_GetTicks() - CURRENT_TIME < 4000)
                    {
                        loadMediaLEVEL_TWO_LOADING();
                        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                        SDL_RenderClear(gRenderer);

                        // Render background
                        gBGTexture.render(0, 0, 0, 0, SDL_FLIP_NONE);
                        SDL_RenderPresent(gRenderer);
                    }
                    else
                    {
                        time_counted = false;
                        stage = LEVEL_TWO;
                    }
                }

                else if (stage == LEVEL_TWO_GAME_OVER)
                {
                    level_two_played++;
                    Mix_HaltMusic();
                    if (!time_counted)
                    {
                        CURRENT_TIME = SDL_GetTicks();
                        time_counted = true;
                    }

                    if (SDL_GetTicks() - CURRENT_TIME < 4000)
                    {
                        loadMediaLEVEL_TWO_GAME_OVER();
                        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                        SDL_RenderClear(gRenderer);

                        // Render background
                        gBGTexture.render(0, 0, 0, 0, SDL_FLIP_NONE);
                        SDL_RenderPresent(gRenderer);
                    }
                    else
                    {
                        time_counted = false;
                        stage = SELECT_LEVEL;
                    }
                }

                if (stage == LEVEL_ONE)
                {
                    // cout << level_one_played << endl;
                    life_levelOne = 10;
                    Mix_HaltMusic();
                    // cout << "entered level 1" << endl;
                    loadMediaLevel_One();

                    if (Mix_PlayingMusic() == 0)
                        if (music)
                            Mix_PlayMusic(gMusicLevelOne, -1);

                    // level one game quitter
                    bool quit_lev1 = false;

                    // The sprite that will be moving around on the screen
                    Sprite sprite;

                    drawn_rect.x = SpriteQuad.x + 50;
                    drawn_rect.y = SpriteQuad.y;
                    drawn_rect.w = 130;
                    drawn_rect.h = SpriteQuad.h;

                    // Current animation frame
                    int frame = 0;

                    // Collider_LevelOne
                    Collider_LevelOne Collider_LevelOne;

                    // The background scrolling offset
                    int scrollingOffset_bg = 0;
                    int scrollingOffset_plat = 0;

                    SDL_Color textColor = {255, 255, 255, 255};

                    // In memory text stream
                    std::stringstream ScoreTextLevelOne;
                    std::stringstream LifeTextLevelOne;

                    // While level 1 is running
                    while (!quit_lev1)
                    {
                        if (life_levelOne <= 0)
                        {
                            quit_lev1 = true;
                            
                            level_one_played++;
                            if (score_levelOne >= 1200)
                            {
                                stage = UNLOCKED;
                            }
                            else
                            {
                                stage = LEVEL_ONE_GAME_OVER;
                                // cout << life_levelOne << endl;
                            }
                        }

                        while (SDL_PollEvent(&E_MAIN) != 0) // poll event of level 1
                        {
                            // User requests quit_lev1
                            if (E_MAIN.type == SDL_QUIT)
                            {
                                quit_lev1 = true;
                                closewindow = true;
                                // closewindow = true;
                                //stage = LEVEL_ONE_GAME_OVER;
                            }
                            // Handle input for the sprite
                            sprite.handleEvent(E_MAIN);
                        }

                        // Scroll background
                        scrollingOffset_bg -= 2;
                        if (scrollingOffset_bg < -gBGLevelOne.getWidth())
                        {
                            scrollingOffset_bg = 0;
                        }

                        // Scroll platform
                        scrollingOffset_plat -= 8;
                        if (scrollingOffset_plat < -1402)
                        {
                            scrollingOffset_plat = 0;
                        }

                        // Set text to be rendered
                        ScoreTextLevelOne.str("");
                        ScoreTextLevelOne << score_levelOne;
                        LifeTextLevelOne.str("");
                        LifeTextLevelOne << life_levelOne;

                        // Render text
                        if (!gUpdatedScoreTextureLevelOne.loadFromRenderedText(ScoreTextLevelOne.str().c_str(), textColor))
                        {
                            printf("Unable to render score texture!\n");
                        }
                        if (!gUpdatedLifeTextureLevelOne.loadFromRenderedText(LifeTextLevelOne.str().c_str(), textColor))
                        {
                            printf("Unable to render life texture!\n");
                        }

                        // Clear screen
                        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                        SDL_RenderClear(gRenderer);

                        // Render background
                        gBGLevelOne.render(scrollingOffset_bg, 0, 0, 0, SDL_FLIP_NONE);
                        gBGLevelOne.render(scrollingOffset_bg + gBGLevelOne.getWidth(), 0, 0, 0, SDL_FLIP_NONE);

                        // Render platform
                        gRunning_platformTexture.render(scrollingOffset_plat, 700, 0, 0, SDL_FLIP_NONE);
                        gRunning_platformTexture.render(scrollingOffset_plat + gRunning_platformTexture.getWidth(), 700, 0, 0, SDL_FLIP_NONE);

                        // Render current frame
                        currentClip = &gspriteClip[frame / 8];
                        gSpriteTexture.RenderSprite((SCREEN_WIDTH - currentClip->w) / 2, (SCREEN_HEIGHT - currentClip->h) / 3, currentClip);

                        // Go to next frame
                        ++frame;

                        // Cycle animation
                        if (frame / 8 >= WALKING_ANIMATION_FRAMES)
                        {
                            frame = 0;
                        }

                        // render Collider_LevelOnes
                        Collider_LevelOne.render();

                        sprite.move(score_levelOne, life_levelOne);
                        if (SpriteQuad.y < base) // so that the sprite doesn't get below the platform
                        {
                            SpriteQuad.y += 5;
                        }

                        for (int bullet_number = 0; bullet_number < 5; bullet_number++)
                        {
                            if (LevelOne_Bullet_go[bullet_number] == 1)
                            {
                                // cout << "bullet thrown " << bullet_number << endl;
                                LevelOne_Bullet_pos_x[bullet_number] += 15;
                                LevelOne_Bullet_rect[bullet_number].x += 15;

                                if (LevelOne_Bullet_pos_x[bullet_number] > 1400)
                                {
                                    LevelOne_Bullet_go[bullet_number] = 0;
                                    LevelOne_Bullet_pos_x[bullet_number] = SpriteQuad.x + SpriteQuad.w;
                                    LevelOne_Bullet_rect[bullet_number].x = SpriteQuad.x + SpriteQuad.w;
                                    LevelOne_Bullet_pos_y[bullet_number] = SpriteQuad.y + SpriteQuad.h / 2;
                                    LevelOne_Bullet_rect[bullet_number].y = SpriteQuad.y + SpriteQuad.h / 2;
                                }
                                // LevelOne_Bullet_go[bullet_number] == 1;
                            }
                            else if (LevelOne_Bullet_go[bullet_number] == 0)
                            {
                                LevelOne_Bullet_pos_x[bullet_number] = SpriteQuad.x + SpriteQuad.w;
                                LevelOne_Bullet_rect[bullet_number].x = SpriteQuad.x + SpriteQuad.w;
                                LevelOne_Bullet_pos_y[bullet_number] = SpriteQuad.y + SpriteQuad.h / 2;
                                LevelOne_Bullet_rect[bullet_number].y = SpriteQuad.y + SpriteQuad.h / 2;
                                LevelOne_Bullet_width[bullet_number] = 0;
                                LevelOne_Bullet_height[bullet_number] = 0;
                            }
                        }

                        for (int i = 0; i < 3; i++)
                        {
                            if (LevelOne_FloatingPlatform_pos_x[i] < -300)
                            {
                                LevelOne_FloatingPlatform_pos_x[i] = LevelOne_FloatingPlatform_rect[i].x = 2100;
                            }
                            LevelOne_FloatingPlatform_pos_x[i] -= 8;
                            LevelOne_FloatingPlatform_rect[i].x -= 8;
                        }

                        for (int i = 0; i < 5; i++)
                        {
                            if (LevelOne_Battery_pos_x[i] < -240)
                            {
                                LevelOne_Battery_width[i] = 60;
                                LevelOne_Battery_height[i] = 62;
                                LevelOne_Battery_pos_x[i] = 2100 + 60;
                                LevelOne_Battery_rect[i].x = 2100 + 60;
                            }
                            LevelOne_Battery_pos_x[i] -= 8;
                            LevelOne_Battery_rect[i].x -= 8;
                        }
                        for (int i = 0; i < 1; i++)
                        {
                            if (LevelOne_Barrier_1_pos_x[i] < -240)
                            {
                                LevelOne_Barrier_1_pos_x[i] = 2100 + 60;
                                LevelOne_Barrier_1_rect[i].x = 2100 + 60;
                            }
                            LevelOne_Barrier_1_pos_x[i] -= 8;
                            LevelOne_Barrier_1_rect[i].x -= 8;
                        }
                        for (int i = 0; i < 1; i++)
                        {
                            if (LevelOne_Barrier_2_pos_x[i] < -240)
                            {
                                LevelOne_Barrier_2_pos_x[i] = 2100 + 60;
                                LevelOne_Barrier_2_rect[i].x = 2100 + 60;
                            }
                            LevelOne_Barrier_2_pos_x[i] -= 8;
                            LevelOne_Barrier_2_rect[i].x -= 8;
                        }

                        for (int i = 0; i < 5; i++)
                        {
                            if (LevelOne_Waste_Bag_pos_x[i] < -300)
                            {
                                LevelOne_Waste_Bag_pos_x[i] = 2100;
                                LevelOne_Waste_Bag_rect[i].x = 2100;
                                LevelOne_Waste_Bag_width[i] = 70;
                                LevelOne_Waste_Bag_height[i] = 84;
                            }
                            LevelOne_Waste_Bag_pos_x[i] -= 8;
                            LevelOne_Waste_Bag_rect[i].x -= 8;
                        }

                        for (int i = 0; i < 6; i++)
                        {
                            if (LevelOne_Can_pos_x[i] < -300)
                            {
                                LevelOne_Can_pos_x[i] = 2100;
                                LevelOne_Can_rect[i].x = 2100;
                                LevelOne_Can_width[i] = 85;
                                LevelOne_Can_height[i] = 51;
                            }
                            LevelOne_Can_pos_x[i] -= 8;
                            LevelOne_Can_rect[i].x -= 8;
                        }

                        for (int i = 0; i < 1; i++)
                        {
                            if (LevelOne_Birds_1_pos_x[i] > 1500)
                            {
                                LevelOne_Birds_1_pos_x[i] = -1500;
                                LevelOne_Birds_1_rect[i].x = -1500;
                            }
                            LevelOne_Birds_1_pos_x[i] += 8;
                            LevelOne_Birds_1_rect[i].x += 8;
                        }

                        for (int i = 0; i < 1; i++)
                        {
                            if (LevelOne_Clouds1_pos_x[i] < -800)
                            {
                                LevelOne_Clouds1_pos_x[i] = 2000;
                                LevelOne_Clouds1_rect[i].x = 2000;
                            }
                            LevelOne_Clouds1_pos_x[i] -= 5;
                            LevelOne_Clouds1_rect[i].x -= 5;
                        }

                        for (int i = 0; i < 1; i++)
                        {
                            if (LevelOne_Clouds2_pos_x[i] < -800)
                            {
                                LevelOne_Clouds2_pos_x[i] = 2500;
                                LevelOne_Clouds2_rect[i].x = 2500;
                            }
                            LevelOne_Clouds2_pos_x[i] -= 5;
                            LevelOne_Clouds2_rect[i].x -= 5;
                        }

                        for (int i = 0; i < 1; i++)
                        {
                            if (LevelOne_Clouds3_pos_x[i] < -800)
                            {
                                LevelOne_Clouds3_pos_x[i] = 1500;
                                LevelOne_Clouds3_rect[i].x = 1500;
                            }
                            LevelOne_Clouds3_pos_x[i] -= 5;
                            LevelOne_Clouds3_rect[i].x -= 5;
                        }

                        for (int i = 0; i < 1; i++)
                        {
                            if (LevelOne_Lion_pos_x[i] < -400)
                            {
                                LevelOne_Lion_pos_x[i] = 5500;
                                LevelOne_Lion_rect[i].x = 5500;
                            }
                            LevelOne_Lion_pos_x[i] -= 8;
                            LevelOne_Lion_rect[i].x -= 8;
                        }

                        for (int i = 0; i < 1; i++)
                        {
                            if (LevelOne_Tiger_pos_x[i] < -400)
                            {
                                LevelOne_Tiger_pos_x[i] = 5400;
                                LevelOne_Tiger_rect[i].x = 5400;
                            }
                            LevelOne_Tiger_pos_x[i] -= 8;
                            LevelOne_Tiger_rect[i].x -= 8;
                        }

                        for (int i = 0; i < 1; i++)
                        {
                            if (LevelOne_Life_pos_x[i] < -100)
                            {
                                LevelOne_Life_width[i] = 100;
                                LevelOne_Life_height[i] = 100;
                                LevelOne_Life_pos_x[i] = 6000;
                                LevelOne_Life_rect[i].x = 6000;
                            }
                            LevelOne_Life_pos_x[i] -= 8;
                            LevelOne_Life_rect[i].x -= 8;
                        }

                        LevelOne_Hunter__drawn_rect.x = LevelOne_Hunter_1_pos_x[0];
                        LevelOne_Hunter__drawn_rect.y = LevelOne_Hunter_1_pos_y[0];
                        LevelOne_Hunter__drawn_rect.w = LevelOne_Hunter_1_width[0];
                        LevelOne_Hunter__drawn_rect.h = LevelOne_Hunter_1_height[0];

                        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0x00);
                        // SDL_RenderDrawRect(gRenderer, &LevelOne_Hunter__drawn_rect);

                        for (int i = 0; i < 2; i++)
                        {
                            if (LevelOne_Hunter_1_pos_x[i] < -300)
                            {
                                LevelOne_Hunter_1_width[i] = 170;
                                LevelOne_Hunter_1_height[i] = 180;
                                LevelOne_Hunter_1_pos_x[i] = 2100;
                                LevelOne_Hunter_1_rect[i].x = 2100;
                                // LevelOne_Hunter__drawn_rect.x = 3100;
                            }
                            LevelOne_Hunter_1_pos_x[i] -= 8;
                            LevelOne_Hunter_1_rect[i].x -= 8;
                            // LevelOne_Hunter__drawn_rect.x -= 8;
                        }

                        ShootingSprite_rect.x = SpriteQuad.x;
                        ShootingSprite_rect.y = SpriteQuad.y;

                        // gLevelOne_BulletTexture.render(0, 0, 6, 0, SDL_FLIP_NONE);
                        gShootingSpriteTexture.render(SpriteQuad.x, SpriteQuad.y, 17, 0, SDL_FLIP_NONE);
                        gSymbolScoreTexture.render(0, 0, 24, 0, SDL_FLIP_NONE);
                        gSymbolLifeTexture.render(0, 0, 25, 0, SDL_FLIP_NONE);

                        // Render textures
                        gScore.render(100, 10, 0, 0, SDL_FLIP_NONE);
                        gLife.render(100, 70, 0, 0, SDL_FLIP_NONE);
                        gUpdatedScoreTextureLevelOne.render(100, 36, 0, 0, SDL_FLIP_NONE);
                        gUpdatedLifeTextureLevelOne.render(100, 100, 0, 0, SDL_FLIP_NONE);

                        // cout << LevelOne_Hunter__drawn_rect.x << endl;
                        //  Update screen
                        SDL_RenderPresent(gRenderer);
                        SDL_Delay(10);
                        //}
                    } // end of level one
                }

                if (stage == LEVEL_TWO) // start of level two
                {
                    life_levelTwo = 10;
                    score_levelTwo = 0;
                    Mix_HaltMusic();

                    loadMediaLevel_Two();

                    if (Mix_PlayingMusic() == 0)
                        if (music)
                            Mix_PlayMusic(gMusicLevelTwo, -1);

                    // level two game quitter
                    bool quit_lev2 = false;

                    // level 2 Event handler
                    SDL_Event e_lev2;
                    Car car;
                    Collider_LevelTwo collider;

                    // The background scrolling offset
                    int scrollingOffset_bg = 0;
                    int scrollingOffset_plat = 0;

                    SDL_Color textColor = {255, 255, 255, 255};

                    // Current score and life
                    // score_levelTwo = score_levelOne;
                    // life_levelTwo = life_levelOne;

                    // In memory text stream
                    std::stringstream ScoreTextLevelTwo;
                    std::stringstream LifeTextLevelTwo;

                    while (!quit_lev2)
                    {
                        if (life_levelTwo <= 0)
                        {
                            quit_lev2 = true;
                            ;
                            player.save_previous_name_file();
                            player.save_previous_highest_score_file();
                            player.save_present_highest_score(player.input_name, score_levelTwo);
                            stage = LEVEL_TWO_GAME_OVER;
                            score_levelOne = 0;
                            
                            //cout << life_levelTwo << endl;
                        }
                        while (SDL_PollEvent(&e_lev2) != 0)
                        {
                            // User requests quit_lev1
                            if (e_lev2.type == SDL_QUIT)
                            {                                
                                quit_lev2 = true;
                                
                                player.save_previous_name_file();
                                player.save_previous_highest_score_file();
                                player.save_present_highest_score(player.input_name, score_levelOne + score_levelTwo);
                                //stage = LEVEL_TWO_GAME_OVER;
                                closewindow = true;
                            }
                            // Handle input for the sprite
                            car.handleEvent(e_lev2);
                        }

                        // Scroll background
                        scrollingOffset_bg -= 10;
                        if (scrollingOffset_bg < -gBGLevelTwo.getWidth())
                        {
                            scrollingOffset_bg = 0;
                        }

                        // Scroll platform
                        scrollingOffset_plat -= 8;
                        if (scrollingOffset_plat < -1402)
                        {
                            scrollingOffset_plat = 0;
                        }

                        // Set text to be rendered
                        ScoreTextLevelTwo.str("");
                        ScoreTextLevelTwo << score_levelTwo;
                        LifeTextLevelTwo.str("");
                        LifeTextLevelTwo << life_levelTwo;

                        // Render text
                        if (!gUpdatedScoreTextureLevelTwo.loadFromRenderedText(ScoreTextLevelTwo.str().c_str(), textColor))
                        {
                            printf("Unable to render time texture!\n");
                        }
                        if (!gUpdatedLifeTextureLevelTwo.loadFromRenderedText(LifeTextLevelTwo.str().c_str(), textColor))
                        {
                            printf("Unable to render time texture!\n");
                        }

                        // Clear screen
                        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                        SDL_RenderClear(gRenderer);

                        // Render background
                        gBGLevelTwo.render(scrollingOffset_bg, 0, 0, 0, SDL_FLIP_NONE);
                        gBGLevelTwo.render(scrollingOffset_bg + gBGLevelTwo.getWidth(), 0, 0, 0, SDL_FLIP_NONE);

                        gCarTexture.RenderCar(700, 200, 0);
                        collider.render();

                        // cout << score_levelTwo << endl;

                        car.move(score_levelTwo, life_levelTwo);

                        // cout << score_levelTwo << endl;

                        for (int i = 0; i < 3; i++)
                        {
                            if (LevelTwo_Battery_pos_x[i] < -240)
                            {
                                LevelTwo_Battery_width[i] = 60;
                                LevelTwo_Battery_height[i] = 62;
                                LevelTwo_Battery_pos_x[i] = 2100 + 60;
                                LevelTwo_Battery_rect[i].x = 2100 + 60;
                            }
                            LevelTwo_Battery_pos_x[i] -= 10;
                            LevelTwo_Battery_rect[i].x -= 10;
                        }
                        for (int i = 0; i < 3; i++)
                        {
                            if (LevelTwo_Waste_Bag_pos_x[i] < -300)
                            {
                                LevelTwo_Waste_Bag_width[i] = 70;
                                LevelTwo_Waste_Bag_height[i] = 84;
                                LevelTwo_Waste_Bag_pos_x[i] = 2100;
                                LevelTwo_Waste_Bag_rect[i].x = 2100;
                            }
                            LevelTwo_Waste_Bag_pos_x[i] -= 10;
                            LevelTwo_Waste_Bag_rect[i].x -= 10;
                        }
                        for (int i = 0; i < 3; i++)
                        {
                            if (LevelTwo_Can_pos_x[i] < -300)
                            {
                                LevelTwo_Can_width[i] = 85;
                                LevelTwo_Can_height[i] = 51;
                                LevelTwo_Can_pos_x[i] = 2100;
                                LevelTwo_Can_rect[i].x = 2100;
                            }
                            LevelTwo_Can_pos_x[i] -= 10;
                            LevelTwo_Can_rect[i].x -= 10;
                        }

                        for (int i = 0; i < 3; i++)
                        {
                            if (LevelTwo_EnemyCar_pos_x[i] < -300)
                            {
                                LevelTwo_EnemyCar_pos_x[i] = 7100;
                                LevelTwo_EnemyCar_rect[i].x = 7100;
                            }
                            LevelTwo_EnemyCar_pos_x[i] -= 14;
                            LevelTwo_EnemyCar_rect[i].x -= 14;
                        }
                        for (int i = 0; i < 2; i++)
                        {
                            if (LevelTwo_Traffic_pos_x[i] < -300)
                            {
                                LevelTwo_Traffic_pos_x[i] = 2100;
                                LevelTwo_Traffic_rect[i].x = 2100;
                            }
                            LevelTwo_Traffic_pos_x[i] -= 10;
                            LevelTwo_Traffic_rect[i].x -= 10;
                        }
                        for (int i = 0; i < 2; i++)
                        {
                            if (LevelTwo_Pebble_pos_x[i] < -300)
                            {
                                LevelTwo_Pebble_pos_x[i] = 2100;
                                LevelTwo_Pebble_rect[i].x = 2100;
                            }
                            LevelTwo_Pebble_pos_x[i] -= 10;
                            LevelTwo_Pebble_rect[i].x -= 10;
                        }
                        for (int i = 0; i < 2; i++)
                        {
                            if (LevelTwo_Fuel_pos_x[i] < -300)
                            {
                                LevelTwo_Fuel_width[i] = 90;
                                LevelTwo_Fuel_height[i] = 151;
                                LevelTwo_Fuel_pos_x[i] = 6100;
                                LevelTwo_Fuel_rect[i].x = 6100;
                            }
                            LevelTwo_Fuel_pos_x[i] -= 10;
                            LevelTwo_Fuel_rect[i].x -= 10;
                        }

                        gSymbolScoreTexture.render(0, 0, 24, 0, SDL_FLIP_NONE);
                        gSymbolLifeTexture.render(0, 0, 25, 0, SDL_FLIP_NONE);
                        // Render textures
                        gScore.render(100, 10, 0, 0, SDL_FLIP_NONE);
                        gLife.render(100, 70, 0, 0, SDL_FLIP_NONE);
                        gUpdatedScoreTextureLevelTwo.render(100, 36, 0, 0, SDL_FLIP_NONE);
                        gUpdatedLifeTextureLevelTwo.render(100, 100, 0, 0, SDL_FLIP_NONE);

                        // cout << LevelOne_Hunter__drawn_rect.x << endl;
                        //  Update screen
                        SDL_RenderPresent(gRenderer);
                        SDL_Delay(10);
                    }
                } // end of level two

                else if (stage == LEVEL_CAVE_LOADING)
                {   
                    
                    Mix_HaltMusic();
                    if (!time_counted)
                    {
                        CURRENT_TIME = SDL_GetTicks();
                        time_counted = true;
                    }

                    if (SDL_GetTicks() - CURRENT_TIME < 800)
                    {
                        loadMediaLEVEL_CAVE_LOADING();
                        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                        SDL_RenderClear(gRenderer);

                        // Render background
                        gBGLevelCaveLoading.render(0, 0, 0, 0, SDL_FLIP_NONE);
                        SDL_RenderPresent(gRenderer);
                    }
                    else
                    {
                        time_counted = false;
                        stage = LEVEL_CAVE;
                    }
                }

                else if (stage == LEVEL_CAVE_GAME_OVER)
                {
                    Mix_HaltMusic();
                    if (!time_counted)
                    {
                        CURRENT_TIME = SDL_GetTicks();
                        time_counted = true;
                    }

                    if (SDL_GetTicks() - CURRENT_TIME < 1500)
                    {
                        loadMediaLEVEL_CAVE_GAME_OVER();
                        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                        SDL_RenderClear(gRenderer);

                        // Render background
                        gBGLevelCaveGameOver.render(0, 0, 0, 0, SDL_FLIP_NONE);
                        SDL_RenderPresent(gRenderer);
                    }
                    else
                    {
                        time_counted = false;
                        stage = SELECT_LEVEL;
                    }
                }

                else if(stage == LEVEL_CAVE)
                {
                    life_levelCave=10;
                    Mix_HaltMusic();
                    loadMediaLEVEL_CAVE();

                    if(Mix_PlayingMusic()==0)
                        if(music)Mix_PlayMusic(gMusicLevelCave,-1);
 
                    //cave level quitter
                    bool quit_levcave = false;

                    //sprite and spritequad e ki hochhe bujhte hobe
                    SpriteCave spriteCave;

                    drawn_rectCave.x = SpriteCaveQuad.x + 50;
                    drawn_rectCave.y = SpriteCaveQuad.y;
                    drawn_rectCave.w = 130;
                    drawn_rectCave.h = SpriteCaveQuad.h;

                    // Current animation frame
                    int frameCave = 0;

                    //Collider of cave level

                    // The background scrolling offset
                    int scrollingOffset_bg = 0;
                    //int scrollingOffset_plat = 0;

                    SDL_Color textColor = {255, 255, 255, 255};

                    // ***In memory text stream, score stuff apatoto level two diye korsi. cholle level three er banabo
                    // std::stringstream ScoreTextLevelTwo;
                    // std::stringstream LifeTextLevelTwo;
                    std::stringstream ScoreTextLevelCave;
                    std::stringstream LifeTextLevelCave;

                    
                    //While cave level is running
                    while(!quit_levcave)

                    {   
                                 
                        //life_levelCave=10;
                        while((SDL_PollEvent(&E_MAIN)!=0))
                        {
                            if (E_MAIN.type==SDL_QUIT)
                            {
                                //quit_levcave =true;
                                stage = LEVEL_CAVE_GAME_OVER;
                                //player.save_previous_name_file();
                                //player.save_previous_highest_score_file();
                                //player.save_present_highest_score(player.input_name, score_levelCave);
                                quit_levcave =true;

                                
                                // cout << life_levelOne << endl;
                            }
                            spriteCave.handleEvent(E_MAIN);
                            if(life_levelCave<=0){
                                //quit_levcave =true;
                                stage = LEVEL_CAVE_GAME_OVER;
                                //player.save_previous_name_file();
                                //player.save_previous_highest_score_file();
                                //player.save_present_highest_score(player.input_name, score_levelCave);
                                quit_levcave =true;
                            }
                        }
                        

                        //scroll platform korinai

                        // Set text to be rendered, egulao level two stuff
                        ScoreTextLevelCave.str("");
                        ScoreTextLevelCave << score_levelCave;
                        LifeTextLevelCave.str("");
                        LifeTextLevelCave << life_levelCave;

                        // Render text, level two stuff
                        if (!gUpdatedScoreTextureLevelCave.loadFromRenderedText(ScoreTextLevelCave.str().c_str(), textColor))
                        {
                            printf("Unable to render time texture!\n");
                        }
                        if (!gUpdatedLifeTextureLevelCave.loadFromRenderedText(LifeTextLevelCave.str().c_str(), textColor))
                        {
                            printf("Unable to render time texture!\n");
                        }

                        // Clear screen
                        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                        SDL_RenderClear(gRenderer);

                        //Render background
                        gBGLevelCave.render(scrollingOffset_bg, 0, 0, 0, SDL_FLIP_NONE);
                        gBGLevelCave.render(scrollingOffset_bg+gBGLevelCave.getWidth(), 0, 0, 0, SDL_FLIP_NONE);

                        //running platform korinai

                        // Render current frame, etao bujhinai
                        currentClipCave = &gspriteCaveClip[frameCave / 8];
                        gSpriteCaveTexture.RenderSpriteCave((SCREEN_WIDTH - currentClipCave->w) / 2, (SCREEN_HEIGHT - currentClipCave->h) / 3, currentClipCave);

                        //Go to next frame
                        ++frameCave;

                        // Cycle animation
                        if (frameCave / 8 >= WALKING_ANIMATION_FRAMESCAVE)
                        {
                            frameCave = 0;
                        }

                        //render Collider_cave. collider cpp kaj korena, tai manually rendered
                        gFlyingLevelOne_Birds_1Texture.render(0, 0, 5, 0, SDL_FLIP_NONE);
                        gLevelCave_BulletTexture.render(0, 0, 33, 0, SDL_FLIP_NONE);
                        gLevelCave_Hunter_1Texture.render(0, 0, 30, 0, SDL_FLIP_NONE);
                        gLevelCave_LifeTexture.render(0, 0, 32, 0, SDL_FLIP_NONE);
                        gQuartzTexture.render(0, 0, 27, 0, SDL_FLIP_NONE);
                        gPinkCrystalTexture.render(0,0,28,0,SDL_FLIP_NONE);
                        gGreenCrystalTexture.render(0,0,29,0,SDL_FLIP_NONE);
                        gFireballTexture.render(0, 0, 31, 0, SDL_FLIP_NONE);

                        spriteCave.move(score_levelCave, life_levelCave);
                        if (SpriteCaveQuad.y < base) // so that the sprite doesn't get below the platform
                        {
                            SpriteCaveQuad.y += 5;
                        }

                        for (int bullet_number = 0; bullet_number < 5; bullet_number++)
                        {
                            if (LevelCave_Bullet_go[bullet_number] == 1)
                            {
                                // cout << "bullet thrown " << bullet_number << endl;
                                LevelCave_Bullet_pos_x[bullet_number] += 15;
                                LevelCave_Bullet_rect[bullet_number].x += 15;

                                if (LevelCave_Bullet_pos_x[bullet_number] > 1400)
                                {
                                    LevelCave_Bullet_go[bullet_number] = 0;
                                    LevelCave_Bullet_pos_x[bullet_number] = SpriteCaveQuad.x + SpriteCaveQuad.w;
                                    LevelCave_Bullet_rect[bullet_number].x = SpriteCaveQuad.x + SpriteCaveQuad.w;
                                    LevelCave_Bullet_pos_y[bullet_number] = SpriteCaveQuad.y + SpriteCaveQuad.h / 2;
                                    LevelCave_Bullet_rect[bullet_number].y = SpriteCaveQuad.y + SpriteCaveQuad.h / 2;
                                }
                                // LevelOne_Bullet_go[bullet_number] == 1;
                            }
                            else if (LevelCave_Bullet_go[bullet_number] == 0)
                            {
                                LevelCave_Bullet_pos_x[bullet_number] = SpriteCaveQuad.x + SpriteCaveQuad.w;
                                LevelCave_Bullet_rect[bullet_number].x = SpriteCaveQuad.x + SpriteCaveQuad.w;
                                LevelCave_Bullet_pos_y[bullet_number] = SpriteCaveQuad.y + SpriteCaveQuad.h / 2;
                                LevelCave_Bullet_rect[bullet_number].y = SpriteCaveQuad.y + SpriteCaveQuad.h / 2;
                                LevelCave_Bullet_width[bullet_number] = 0;
                                LevelCave_Bullet_height[bullet_number] = 0;
                            }
                        }

                        // for (int i = 0; i < 4; i++)
                        // {
                        //     if (LevelOne_FloatingPlatform_pos_x[i] < -300)
                        //     {
                        //         LevelOne_FloatingPlatform_pos_x[i] = LevelOne_FloatingPlatform_rect[i].x = 2100;
                        //     }
                        //     LevelOne_FloatingPlatform_pos_x[i] -= 8;
                        //     LevelOne_FloatingPlatform_rect[i].x -= 8;
                        // }

                        for (int i = 0; i < 3; i++)
                        {
                            if (LevelCave_Quartz_pos_x[i] < -300)
                            {
                                LevelCave_Quartz_pos_x[i] = 2100;
                                LevelCave_Quartz_rect[i].x = 2100;
                                LevelCave_Quartz_width[i] = 93;
                                LevelCave_Quartz_height[i] = 124;
                            }
                            LevelCave_Quartz_pos_x[i] -= 8;
                            LevelCave_Quartz_rect[i].x -= 8;
                        }

                        for (int i = 0; i < 3; i++)
                        {
                            if (LevelCave_PinkCrystal_pos_x[i] < -300)
                            {
                                LevelCave_PinkCrystal_pos_x[i] = 2100;
                                LevelCave_PinkCrystal_rect[i].x = 2100;
                                LevelCave_PinkCrystal_width[i] = 83;
                                LevelCave_PinkCrystal_height[i] = 111;
                            }
                            LevelCave_PinkCrystal_pos_x[i] -= 8;
                            LevelCave_PinkCrystal_rect[i].x -= 8;
                        }

                        for (int i = 0; i < 3; i++)
                        {
                            if (LevelCave_GreenCrystal_pos_x[i] < -300)
                            {
                                LevelCave_GreenCrystal_pos_x[i] = 2100;
                                LevelCave_GreenCrystal_rect[i].x = 2100;
                                LevelCave_GreenCrystal_width[i] = 60;
                                LevelCave_GreenCrystal_height[i] = 60;
                            }
                            LevelCave_GreenCrystal_pos_x[i] -= 8;
                            LevelCave_GreenCrystal_rect[i].x -= 8;
                        }

                        for (int i = 0; i < 2; i++)
                        {
                            if (LevelCave_Fireball_pos_x[i] < -300)
                            {
                                LevelCave_Fireball_pos_x[i] = 2100;
                                LevelCave_Fireball_rect[i].x = 2100;
                                LevelCave_Fireball_width[i] = 50;
                                LevelCave_Fireball_height[i] = 47;
                            }
                            LevelCave_Fireball_pos_x[i] -= 8;
                            LevelCave_Fireball_rect[i].x -= 8;
                        }

                        for (int i = 0; i < 1; i++)
                        {
                            if (LevelOne_Birds_1_pos_x[i] > 1500)
                            {
                                LevelOne_Birds_1_pos_x[i] = -1500;
                                LevelOne_Birds_1_rect[i].x = -1500;
                            }
                            LevelOne_Birds_1_pos_x[i] += 8;
                            LevelOne_Birds_1_rect[i].x += 8;
                        }

                        for (int i = 0; i < 1; i++)
                        {
                            if (LevelCave_Life_pos_x[i] < -100)
                            {
                                LevelCave_Life_width[i] = 100;
                                LevelCave_Life_height[i] = 100;
                                LevelCave_Life_pos_x[i] = 6000;
                                LevelCave_Life_rect[i].x = 6000;
                            }
                            LevelCave_Life_pos_x[i] -= 8;
                            LevelCave_Life_rect[i].x -= 8;
                        }
                        LevelCave_Hunter__drawn_rect.x = LevelCave_Hunter_1_pos_x[0];
                        LevelCave_Hunter__drawn_rect.y = LevelCave_Hunter_1_pos_y[0];
                        LevelCave_Hunter__drawn_rect.w = LevelCave_Hunter_1_width[0];
                        LevelCave_Hunter__drawn_rect.h = LevelCave_Hunter_1_height[0];

                        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0x00);
                        // SDL_RenderDrawRect(gRenderer, &LevelOne_Hunter__drawn_rect);

                        for (int i = 0; i < 1; i++)
                        {
                            if (LevelCave_Hunter_1_pos_x[i] < -300)
                            {
                                LevelCave_Hunter_1_width[i] = 170;
                                LevelCave_Hunter_1_height[i] = 180;
                                LevelCave_Hunter_1_pos_x[i] = 2100;
                                LevelCave_Hunter_1_rect[i].x = 2100;
                                // LevelOne_Hunter__drawn_rect.x = 3100;
                            }
                            LevelCave_Hunter_1_pos_x[i] -= 8;
                            LevelCave_Hunter_1_rect[i].x -= 8;
                            // LevelOne_Hunter__drawn_rect.x -= 8;
                        }

                        ShootingSpriteCave_rect.x = SpriteCaveQuad.x;
                        ShootingSpriteCave_rect.y = SpriteCaveQuad.y;

                        // gLevelOne_BulletTexture.render(0, 0, 6, 0, SDL_FLIP_NONE);
                        gShootingSpriteCaveTexture.render(SpriteCaveQuad.x, SpriteCaveQuad.y, 35, 0, SDL_FLIP_NONE);
                        gSymbolScoreTexture.render(0, 0, 24, 0, SDL_FLIP_NONE);
                        gSymbolLifeTexture.render(0, 0, 25, 0, SDL_FLIP_NONE);
                        
                        // Render textures
                        gScore.render(1300, 10, 0, 0, SDL_FLIP_NONE);
                        gLife.render(1320, 70, 0, 0, SDL_FLIP_NONE);
                        gUpdatedScoreTextureLevelCave.render(1350, 36, 0, 0, SDL_FLIP_NONE);
                        gUpdatedLifeTextureLevelCave.render(1350, 100, 0, 0, SDL_FLIP_NONE);

                        SDL_RenderPresent(gRenderer);
                        SDL_Delay(10);//end of cave level, working with game over
                    

                    }
                }
            


        }
    }
}
        
        
    

    
        

