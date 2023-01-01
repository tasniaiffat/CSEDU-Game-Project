#include "headers.h"

// Screen dimension constants
const int SCREEN_WIDTH = 1402;
const int SCREEN_HEIGHT = 878;

// select level Button constants
const int SELECT_LEVEL_BUTTON_WIDTH = 400;
const int SELECT_LEVEL_BUTTON_HEIGHT = 120;
const int SELECT_LEVEL_TOTAL_BUTTONS = 3;

// menu page Button constants
const int MENU_PAGE_BUTTON_WIDTH = 506;
const int MENU_PAGE_BUTTON_HEIGHT = 79;
const int MENU_PAGE_TOTAL_BUTTONS = 8;

const int BACK_BUTTON_POSX = 66;
const int BACK_BUTTON_POSY = 703;
const int BACK_BUTTON_WIDTH = 114;
const int BACK_BUTTON_HEIGHT = 114;
// int player.save_score[5] = {0, 0, 0, 0, 0};
bool sound = true;
bool music = true;
Uint32 score_levelOne = 0;
Uint32 life_levelOne = 10;
// Current score and life
Uint32 score_levelTwo = 0;
Uint32 life_levelTwo = 10;
// Current score and life
Uint32 score_levelCave = 0;
Uint32 life_levelCave = 10;
int bullet_number = 0;
int flag_music = 0;
// level one global variable initialization
SDL_Rect drawn_rect;                  // level one
SDL_Rect LevelOne_Hunter__drawn_rect; // level one

// Set rendering space and render to screen
SDL_Rect SpriteQuad = {100, 579, 213, 180}; // level one
int RESET_SPRITE_X = 601;
int RESET_SPRITE_Y = 201;
SDL_Rect CarQuad = {100, 300, 300, 150}; // level two
int RESET_CAR_X = 200;
int RESET_CAR_Y = 570;
int flag = 1;
int base = 579;

// both level
//  The window we'll be rendering to
SDL_Window *gWindow = NULL;
// The window renderer
SDL_Renderer *gRenderer = NULL;
// font renderer
TTF_Font *gFont = NULL;

// The music that will be played
Mix_Music *gMusicMenu = NULL;
Mix_Music *gMusicScoreboard = NULL;
Mix_Music *gMusicLevelOne = NULL;
Mix_Music *gMusicLevelTwo = NULL;
Mix_Music *gMusicLevelCave = NULL;
Mix_Chunk *gSoundMouseClick = NULL;
Mix_Chunk *gSoundTrash = NULL;
Mix_Chunk *gSoundLife = NULL;
Mix_Chunk *gSoundShooting = NULL;
Mix_Chunk *gSoundHit = NULL;

// platform 1, platform 2,.....
int LevelOne_FloatingPlatform_pos_x[3] = {200, 1760, 3000};
int LevelOne_FloatingPlatform_pos_y[3] = {420, 350, 385};
int LevelOne_FloatingPlatform_width[3] = {270, 270, 270};
int LevelOne_FloatingPlatform_height[3] = {156, 156, 156};

// LevelOne_Battery
int LevelOne_Battery_pos_x[6] = {1490, 1380, 1490, 1600, 1160};
int LevelOne_Battery_pos_y[6] = {220, 385, 270, 385, 150};
int LevelOne_Battery_width[6] = {60, 60, 60, 60, 60, 60};
int LevelOne_Battery_height[6] = {62, 62, 62, 62, 62, 62};

// level one Waste bag
int LevelOne_Waste_Bag_pos_x[5] = {250, 2350, 2350, 2350, 3050};
int LevelOne_Waste_Bag_pos_y[5] = {320, 150, 270, 365, 285};
int LevelOne_Waste_Bag_width[5] = {70, 70, 70, 70, 70};
int LevelOne_Waste_Bag_height[5] = {84, 84, 84, 84, 84};

// LevelOne_Cans
int LevelOne_Can_pos_x[6] = {330, 2430, 2230, 2230, 3120, 2430};
int LevelOne_Can_pos_y[6] = {350, 180, 200, 395, 315, 395};
int LevelOne_Can_width[6] = {85, 85, 85, 85, 85, 85};
int LevelOne_Can_height[6] = {51, 51, 51, 51, 51, 51};

// LevelOne_Birds_1
int LevelOne_Birds_1_pos_x[5] = {-400};
int LevelOne_Birds_1_pos_y[5] = {50};
int LevelOne_Birds_1_width[5] = {205};
int LevelOne_Birds_1_height[5] = {154};

// LevelOne_barrier 1
int LevelOne_Barrier_1_pos_x[1] = {1490};
int LevelOne_Barrier_1_pos_y[1] = {553};
int LevelOne_Barrier_1_width[1] = {93};
int LevelOne_Barrier_1_height[1] = {206};

// LevelOne_barrier 1
int LevelOne_Barrier_2_pos_x[1] = {1060};
int LevelOne_Barrier_2_pos_y[1] = {528};
int LevelOne_Barrier_2_width[1] = {120};
int LevelOne_Barrier_2_height[1] = {231};

// LevelOne_Clouds1
int LevelOne_Clouds1_pos_x[5] = {1500};
int LevelOne_Clouds1_pos_y[5] = {50};
int LevelOne_Clouds1_width[5] = {290};
int LevelOne_Clouds1_height[5] = {154};

// LevelOne_Clouds2
int LevelOne_Clouds2_pos_x[5] = {2000};
int LevelOne_Clouds2_pos_y[5] = {150};
int LevelOne_Clouds2_width[5] = {260};
int LevelOne_Clouds2_height[5] = {154};

// LevelOne_Clouds3
int LevelOne_Clouds3_pos_x[5] = {3000};
int LevelOne_Clouds3_pos_y[5] = {100};
int LevelOne_Clouds3_width[5] = {300};
int LevelOne_Clouds3_height[5] = {154};

// LevelOne_Bullets
int LevelOne_Bullet_pos_x[5] = {SpriteQuad.x + SpriteQuad.w, SpriteQuad.x + SpriteQuad.w, SpriteQuad.x + SpriteQuad.w, SpriteQuad.x + SpriteQuad.w, SpriteQuad.x + SpriteQuad.w};
int LevelOne_Bullet_pos_y[5] = {SpriteQuad.y + SpriteQuad.h / 2, SpriteQuad.y + SpriteQuad.h / 2, SpriteQuad.y + SpriteQuad.h / 2, SpriteQuad.y + SpriteQuad.h / 2, SpriteQuad.y + SpriteQuad.h / 2};
int LevelOne_Bullet_width[5] = {0, 0, 0, 0, 0};
int LevelOne_Bullet_height[5] = {0, 0, 0, 0, 0};

// LevelOne_Hunter_1
int LevelOne_Hunter_1_pos_x[2] = {2500, 1830};
int LevelOne_Hunter_1_pos_y[2] = {579, 170};
int LevelOne_Hunter_1_width[2] = {170, 170};
int LevelOne_Hunter_1_height[2] = {180, 180};

// LevelOne_Lion
int LevelOne_Lion_pos_x[1] = {1000};
int LevelOne_Lion_pos_y[1] = {579};
int LevelOne_Lion_width[1] = {300};
int LevelOne_Lion_height[1] = {214};

// LevelOne_Tiger
int LevelOne_Tiger_pos_x[1] = {3300};
int LevelOne_Tiger_pos_y[1] = {620};
int LevelOne_Tiger_width[1] = {380};
int LevelOne_Tiger_height[1] = {164};

// LevelOne_Life
int LevelOne_Life_pos_x[1] = {1300};
int LevelOne_Life_pos_y[1] = {100};
int LevelOne_Life_width[1] = {100};
int LevelOne_Life_height[1] = {100};

// level two

// Leveltwo_Battery
int LevelTwo_Battery_pos_x[3] = {450, 550, 650};
int LevelTwo_Battery_pos_y[3] = {240, 240, 240};
int LevelTwo_Battery_width[3] = {60, 60, 60};
int LevelTwo_Battery_height[3] = {62, 62, 62};

// level two Waste bag
int LevelTwo_Waste_Bag_pos_x[3] = {2080, 2130, 2220};
int LevelTwo_Waste_Bag_pos_y[3] = {580, 580, 580};
int LevelTwo_Waste_Bag_width[3] = {70, 70, 70};
int LevelTwo_Waste_Bag_height[3] = {84, 84, 84};

// LevelTwo_Cans
int LevelTwo_Can_pos_x[3] = {2280, 2380, 2490};
int LevelTwo_Can_pos_y[3] = {400, 400, 400};
int LevelTwo_Can_width[3] = {85, 85, 85};
int LevelTwo_Can_height[3] = {51, 51, 51};

// levelTwoTraffic
int LevelTwo_Traffic_pos_x[2] = {700, 800};
int LevelTwo_Traffic_pos_y[2] = {400, 400};
int LevelTwo_Traffic_width[2] = {60, 60};
int LevelTwo_Traffic_height[2] = {80, 80};

// LevelTwoEnemycar
int LevelTwo_EnemyCar_pos_x[3] = {1000, 2300, 2800};
int LevelTwo_EnemyCar_pos_y[3] = {190, 350, 230};
int LevelTwo_EnemyCar_width[3] = {346, 346, 346};
int LevelTwo_EnemyCar_height[3] = {178, 178, 178};

// levelTwoPebble
int LevelTwo_Pebble_pos_x[2] = {900, 1000};
int LevelTwo_Pebble_pos_y[2] = {400, 400};
int LevelTwo_Pebble_width[2] = {100, 100};
int LevelTwo_Pebble_height[2] = {80, 80};

//levelTwoFuel
int LevelTwo_Fuel_pos_x[2] = {1050, 5860};
int LevelTwo_Fuel_pos_y[2] = {60, 700};
int LevelTwo_Fuel_width[2] = {90, 90};
int LevelTwo_Fuel_height[2] = {151, 151};

//cave level

//Quartz
int LevelCave_Quartz_pos_x[3]={600,800,1000};
int LevelCave_Quartz_pos_y[3]={350,180,200};
int LevelCave_Quartz_width[3]={42,42,42};//331
int LevelCave_Quartz_height[3]={94,94,94};//754

//Pink Crystal
int LevelCave_PinkCrystal_pos_x[3]={2000,2100,2200};
int LevelCave_PinkCrystal_pos_y[3]={580,480,580};
int LevelCave_PinkCrystal_width[3]={58,58,58};//289
int LevelCave_PinkCrystal_height[3]={97,97,97};//483

//Green Crystal
int LevelCave_GreenCrystal_pos_x[3]={1500,1600,1700};
int LevelCave_GreenCrystal_pos_y[3]={400,320,400};
int LevelCave_GreenCrystal_width[3]={55,55,55};//220
int LevelCave_GreenCrystal_height[3]={77,77,77};//308

//Level cave Hunter
int LevelCave_Hunter_1_pos_x[1] = {2500};
int LevelCave_Hunter_1_pos_y[1] = {579};
int LevelCave_Hunter_1_width[1] = {170};
int LevelCave_Hunter_1_height[1] = {180};

//Fireball
int LevelCave_Fireball_pos_x[2]={2600,1600};
int LevelCave_Fireball_pos_y[2]={579,110};
int LevelCave_Fireball_width[2]={50,50};//415
int LevelCave_Fireball_height[2]={47,47};//382

// The velocity of the sprite
int sprite_VelX, sprite_VelY;

// for LevelOne_Bullet
int LevelOne_Bullet_go[5] = {0, 0, 0, 0, 0};

// Walking animation
const int WALKING_ANIMATION_FRAMES = 8;
SDL_Rect gspriteClip[WALKING_ANIMATION_FRAMES];

// level one globally declaring the rectangle where the obstacle will be rendered
SDL_Rect SymbolScore_rect;
SDL_Rect SymbolLife_rect;
SDL_Rect ShootingSprite_rect;
SDL_Rect LevelOne_FloatingPlatform_rect[3];
SDL_Rect LevelOne_Battery_rect[6];
SDL_Rect LevelOne_Waste_Bag_rect[6];
SDL_Rect LevelOne_Can_rect[6];
SDL_Rect LevelOne_Birds_1_rect[5];
SDL_Rect LevelOne_Barrier_1_rect[1];
SDL_Rect LevelOne_Barrier_2_rect[1];
SDL_Rect LevelOne_Bullet_rect[5];
SDL_Rect LevelOne_Hunter_1_rect[5];
SDL_Rect LevelOne_Lion_rect[1];
SDL_Rect LevelOne_Tiger_rect[1];
SDL_Rect LevelOne_Life_rect[1];
SDL_Rect LevelOne_Clouds1_rect[1];
SDL_Rect LevelOne_Clouds2_rect[1];
SDL_Rect LevelOne_Clouds3_rect[1];

// level two
SDL_Rect LevelTwo_Battery_rect[6];
SDL_Rect LevelTwo_Waste_Bag_rect[6];
SDL_Rect LevelTwo_Can_rect[6];
SDL_Rect LevelTwo_Traffic_rect[2];
SDL_Rect LevelTwo_EnemyCar_rect[3];
SDL_Rect LevelTwo_Pebble_rect[2];
SDL_Rect LevelTwo_Fuel_rect[3];

//cave level
SDL_Rect LevelCave_Quartz_rect[3];
SDL_Rect LevelCave_PinkCrystal_rect[3];
SDL_Rect LevelCave_GreenCrystal_rect[3];
SDL_Rect LevelCave_Hunter_1_rect[1];
SDL_Rect LevelCave_Fireball_rect[2];

// current sprite clip
SDL_Rect *currentClip;

