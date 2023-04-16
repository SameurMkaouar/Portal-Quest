#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"
#include "audio.h"

typedef struct{
	image background_ocean, background_forest, background_city, clock;
	int direction, level; 
	Mix_Music *level1_music, *level2_music, *level3_music;
	int fullscreen; 
	SDL_Rect camera;  
	double vitesse, acceleration; 
	SDL_Rect animation_posScreen, animation_posSprite; 
	SDL_Surface *animation_sprite;
	image tab_frames[9];
	int i;
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
#endif



