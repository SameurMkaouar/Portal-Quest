#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"
#include "audio.h"
typedef struct{
	image vertical1, vertical2, vertical3, vertical4, vertical5, vertical6, horizontal1, horizontal2, horizontal3; 
}entity; 
typedef struct{
	image background_ocean, background_forest, background_city, clock, garbage_moving, image_junkpit, image_akaros;
	int direction, level; 
	Mix_Music *level1_music, *level2_music, *level3_music;
	int fullscreen; 
	SDL_Rect camera;  
	double vitesse, acceleration; 
	SDL_Rect animation_posScreen, animation_posSprite; 
	SDL_Surface *animation_sprite;
	image tab_frames[9];
	int i, akaros_appearance, akaros_is_shown;
	entity e; 
}background;

typedef struct 
{
	int score, time; 
	char playerName[20];
}scoreInfo; 

void initBack(background * b);
void afficherBack(background b, SDL_Surface * screen);
void scrolling (background * b, int direction, Uint32 dt);
void animerBack (background* b);
void saveScore(scoreInfo s, char *fileName);
void bestScore(char *fileName, scoreInfo t[]);
void audio_level1(Mix_Music *music,int volume, int a);
void audio_level2(Mix_Music *music,int volume);
void initialiser_image_leaderboard(image *imgbtn, int x, int y, char nomImage[]);
void initialiser_image_garbage_moving(image *imgbtn, int x, int y, char nomImage[]);
void initialiser_image_junkpit(image *imgbtn, int x, int y, char nomImage[]);
void initialiser_akaros(image *imgbtn, int x, int y, char nomImage[]);
void initEntity(entity *e);
void shake_screen(SDL_Surface* screen, int intensity, int duration);
void shake_image(image* img, int intensity, int duration,background b, SDL_Surface * screen);
#endif



