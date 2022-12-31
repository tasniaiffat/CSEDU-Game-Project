#pragma once

#include "headers.h"

enum stages
{
    TITLE,
    MENU,
    HELP,
    SELECT_LEVEL,
    NAME_INPUT,
    SCOREBOARD,
    LEVEL_ONE_LOADING,
    LEVEL_ONE,
    LEVEL_ONE_GAME_OVER,
    LEVEL_TWO_LOADING,
    LEVEL_TWO,
    LEVEL_TWO_GAME_OVER,
    LOCKED,
    UNLOCKED,
    SORRY,
    LEVEL_CAVE,
    LEVEL_CAVE_LOADING,
    LEVEL_CAVE_GAME_OVER,
} stage;

extern int level_one_played;
extern int level_two_played;
extern int flag_music_2;