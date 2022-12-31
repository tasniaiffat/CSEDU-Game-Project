#ifndef global
#define global

#include "all_headers.h"

// Screen dimension constants
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

// select level Button constants
extern const int SELECT_LEVEL_BUTTON_WIDTH;
extern const int SELECT_LEVEL_BUTTON_HEIGHT;
extern const int SELECT_LEVEL_TOTAL_BUTTONS;

// menu page Button constants
extern const int MENU_PAGE_BUTTON_WIDTH;
extern const int MENU_PAGE_BUTTON_HEIGHT;
extern const int MENU_PAGE_TOTAL_BUTTONS;

extern const int BACK_BUTTON_POSX;
extern const int BACK_BUTTON_POSY;
extern const int BACK_BUTTON_WIDTH;
extern const int BACK_BUTTON_HEIGHT;
// int player.save_score[5] = {0, 0, 0, 0, 0};
extern bool sound;
extern bool music;
extern int bullet_number;
extern int flag_music;
// Current score and life
extern Uint32 score_levelOne;
extern Uint32 life_levelOne;
// Current score and life
extern Uint32 score_levelTwo;
extern Uint32 life_levelTwo;

// level one global variable initialization
extern SDL_Rect drawn_rect;                  // level one
extern SDL_Rect LevelOne_Hunter__drawn_rect; // level one

// Set rendering space and render to screen
extern SDL_Rect SpriteQuad; // level one
extern int RESET_SPRITE_X;
extern int RESET_SPRITE_Y;
extern SDL_Rect CarQuad; // level two
extern int RESET_CAR_X;
extern int RESET_CAR_Y;

extern int flag;
extern int base;

// both level

//  The window we'll be rendering to
extern SDL_Window *gWindow;
// The window renderer
extern SDL_Renderer *gRenderer;
// font renderer
extern TTF_Font *gFont;

// The music that will be played
extern Mix_Music *gMusicMenu;
extern Mix_Music *gMusicScoreboard;
extern Mix_Music *gMusicLevelOne;
extern Mix_Music *gMusicLevelTwo;
extern Mix_Chunk *gSoundMouseClick;
extern Mix_Chunk *gSoundTrash;
extern Mix_Chunk *gSoundLife;
extern Mix_Chunk *gSoundShooting;
extern Mix_Chunk *gSoundHit;

// platform 1, platform 2,.....
extern int LevelOne_FloatingPlatform_pos_x[3];
extern int LevelOne_FloatingPlatform_pos_y[3];
extern int LevelOne_FloatingPlatform_width[3];
extern int LevelOne_FloatingPlatform_height[3];

// LevelOne_Battery
extern int LevelOne_Battery_pos_x[6];
extern int LevelOne_Battery_pos_y[6];
extern int LevelOne_Battery_width[6];
extern int LevelOne_Battery_height[6];

// level one Waste bag
extern int LevelOne_Waste_Bag_pos_x[5];
extern int LevelOne_Waste_Bag_pos_y[5];
extern int LevelOne_Waste_Bag_width[5];
extern int LevelOne_Waste_Bag_height[5];

// LevelOne_Cans
extern int LevelOne_Can_pos_x[6];
extern int LevelOne_Can_pos_y[6];
extern int LevelOne_Can_width[6];
extern int LevelOne_Can_height[6];

// LevelOne_Birds_1
extern int LevelOne_Birds_1_pos_x[5];
extern int LevelOne_Birds_1_pos_y[5];
extern int LevelOne_Birds_1_width[5];
extern int LevelOne_Birds_1_height[5];

// LevelOne_barrier 1
extern int LevelOne_Barrier_1_pos_x[1];
extern int LevelOne_Barrier_1_pos_y[1];
extern int LevelOne_Barrier_1_width[1];
extern int LevelOne_Barrier_1_height[1];

// LevelOne_barrier 1
extern int LevelOne_Barrier_2_pos_x[1];
extern int LevelOne_Barrier_2_pos_y[1];
extern int LevelOne_Barrier_2_width[1];
extern int LevelOne_Barrier_2_height[1];

// LevelOne_Clouds1
extern int LevelOne_Clouds1_pos_x[5];
extern int LevelOne_Clouds1_pos_y[5];
extern int LevelOne_Clouds1_width[5];
extern int LevelOne_Clouds1_height[5];

// LevelOne_Clouds2
extern int LevelOne_Clouds2_pos_x[5];
extern int LevelOne_Clouds2_pos_y[5];
extern int LevelOne_Clouds2_width[5];
extern int LevelOne_Clouds2_height[5];

// LevelOne_Clouds3
extern int LevelOne_Clouds3_pos_x[5];
extern int LevelOne_Clouds3_pos_y[5];
extern int LevelOne_Clouds3_width[5];
extern int LevelOne_Clouds3_height[5];

// LevelOne_Bullets
extern int LevelOne_Bullet_pos_x[5];
extern int LevelOne_Bullet_pos_y[5];
extern int LevelOne_Bullet_width[5];
extern int LevelOne_Bullet_height[5];

// LevelOne_Hunter_1
extern int LevelOne_Hunter_1_pos_x[2];
extern int LevelOne_Hunter_1_pos_y[2];
extern int LevelOne_Hunter_1_width[2];
extern int LevelOne_Hunter_1_height[2];

// LevelOne_Lion
extern int LevelOne_Lion_pos_x[1];
extern int LevelOne_Lion_pos_y[1];
extern int LevelOne_Lion_width[1];
extern int LevelOne_Lion_height[1];

// LevelOne_Tiger
extern int LevelOne_Tiger_pos_x[1];
extern int LevelOne_Tiger_pos_y[1];
extern int LevelOne_Tiger_width[1];
extern int LevelOne_Tiger_height[1];

// LevelOne_Life
extern int LevelOne_Life_pos_x[1];
extern int LevelOne_Life_pos_y[1];
extern int LevelOne_Life_width[1];
extern int LevelOne_Life_height[1];

// level two
// Leveltwo_Battery
extern int LevelTwo_Battery_pos_x[3];
extern int LevelTwo_Battery_pos_y[3];
extern int LevelTwo_Battery_width[3];
extern int LevelTwo_Battery_height[3];

// level two Waste bag
extern int LevelTwo_Waste_Bag_pos_x[3];
extern int LevelTwo_Waste_Bag_pos_y[3];
extern int LevelTwo_Waste_Bag_width[3];
extern int LevelTwo_Waste_Bag_height[3];

// LevelTwo_Cans
extern int LevelTwo_Can_pos_x[3];
extern int LevelTwo_Can_pos_y[3];
extern int LevelTwo_Can_width[3];
extern int LevelTwo_Can_height[3];

// levelTwoTraffic
extern int LevelTwo_Traffic_pos_x[2];
extern int LevelTwo_Traffic_pos_y[2];
extern int LevelTwo_Traffic_width[2];
extern int LevelTwo_Traffic_height[2];

// level two enemy car
extern int LevelTwo_EnemyCar_pos_x[3];
extern int LevelTwo_EnemyCar_pos_y[3];
extern int LevelTwo_EnemyCar_width[3];
extern int LevelTwo_EnemyCar_height[3];

// levelTwoPebble
extern int LevelTwo_Pebble_pos_x[2];
extern int LevelTwo_Pebble_pos_y[2];
extern int LevelTwo_Pebble_width[2];
extern int LevelTwo_Pebble_height[2];

// levelTwoFuel
extern int LevelTwo_Fuel_pos_x[2];
extern int LevelTwo_Fuel_pos_y[2];
extern int LevelTwo_Fuel_width[2];
extern int LevelTwo_Fuel_height[2];

//cave level

//Quartz
extern int LevelCave_Quartz_pos_x[3];
extern int LevelCave_Quartz_pos_y[3];
extern int LevelCave_Quartz_width[3];
extern int LevelCave_Quartz_height[3];

//Pink Crystal
extern int LevelCave_PinkCrystal_pos_x[3];
extern int LevelCave_PinkCrystal_pos_y[3];
extern int LevelCave_PinkCrystal_width[3];
extern int LevelCave_PinkCrystal_height[3];

//Green Crystal
extern int LevelCave_GreenCrystal_pos_x[3];
extern int LevelCave_GreenCrystal_pos_y[3];
extern int LevelCave_GreenCrystal_width[3];
extern int LevelCave_GreenCrystal_height[3];

//Fireball
extern int LevelCave_Fireball_pos_x[2];
extern int LevelCave_Fireball_pos_y[2];
extern int LevelCave_Fireball_width[2];
extern int LevelCave_Fireball_height[2];

// LevelCave_Hunter_1
extern int LevelCave_Hunter_1_pos_x[1];
extern int LevelCave_Hunter_1_pos_y[1];
extern int LevelCave_Hunter_1_width[1];
extern int LevelCave_Hunter_1_height[1];

// The velocity of the sprite
extern int sprite_VelX, sprite_VelY;

// for LevelOne_Bullet
extern int LevelOne_Bullet_go[5];

// Walking animation
extern const int WALKING_ANIMATION_FRAMES;
extern SDL_Rect gspriteClip[8];

extern SDL_Rect SymbolScore_rect;
extern SDL_Rect SymbolLife_rect;

// level one globally declaring the rectangle where the obstacle will be rendered
extern SDL_Rect ShootingSprite_rect;
extern SDL_Rect LevelOne_FloatingPlatform_rect[3];
extern SDL_Rect LevelOne_Battery_rect[6];
extern SDL_Rect LevelOne_Waste_Bag_rect[6];
extern SDL_Rect LevelOne_Can_rect[6];
extern SDL_Rect LevelOne_Birds_1_rect[5];
extern SDL_Rect LevelOne_Barrier_1_rect[1];
extern SDL_Rect LevelOne_Barrier_2_rect[1];
extern SDL_Rect LevelOne_Bullet_rect[5];
extern SDL_Rect LevelOne_Hunter_1_rect[5];
extern SDL_Rect LevelOne_Lion_rect[1];
extern SDL_Rect LevelOne_Tiger_rect[1];
extern SDL_Rect LevelOne_Life_rect[1];
extern SDL_Rect LevelOne_Clouds1_rect[1];
extern SDL_Rect LevelOne_Clouds2_rect[1];
extern SDL_Rect LevelOne_Clouds3_rect[1];

// level two
extern SDL_Rect LevelTwo_Battery_rect[6];
extern SDL_Rect LevelTwo_Waste_Bag_rect[6];
extern SDL_Rect LevelTwo_Can_rect[6];
extern SDL_Rect LevelTwo_EnemyCar_rect[3];
extern SDL_Rect LevelTwo_Cone_rect[3];
extern SDL_Rect LevelTwo_Block_rect[3];
extern SDL_Rect LevelTwo_Traffic_rect[2];
extern SDL_Rect LevelTwo_EnemyCar_rect[3];
extern SDL_Rect LevelTwo_Pebble_rect[2];
extern SDL_Rect LevelTwo_Fuel_rect[3];

//cave level
extern SDL_Rect LevelCave_Quartz_rect[3];
extern SDL_Rect LevelCave_PinkCrystal_rect[3];
extern SDL_Rect LevelCave_GreenCrystal_rect[3];
extern SDL_Rect LevelCave_Hunter_1_rect[1];
extern SDL_Rect LevelCave_Fireball_rect[2];



// current sprite clip
extern SDL_Rect *currentClip;

#endif
