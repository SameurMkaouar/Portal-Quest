/**
* @file background.h
* @brief background file
* @author Yassine Kharrat
* @version 3.2
* @date May 03, 2023
*
* Ici figure le fichier background.h dans lequel il y'a les fonctions du background
*
*/
#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include "image.h"
#include "audio.h"
#include "hero.h"
typedef struct{
	image vertical1, /*!<  entité vertical 1*/ vertical2, /*!<  entité vertical 2*/ vertical3,  /*!<  entité vertical 4*/vertical4, /*!< entité vertical 4*/ vertical5,  /*!< entité vertical 5*/vertical6, horizontal1,  /*!< entité horizontal 1*/horizontal2,  /*!< entité horizontal2*/horizontal3; /*!<entité horizontal3*/ 
}entity; 
typedef struct{
	image background_ocean,/*!<  image du level 1*/ background_forest, /*!<  image du level2*/background_fall,/*!<  image du level 3*/ garbage_moving,/*!<  image de garbage*/ image_junkpit, /*!< image de junkpit*/image_akaros;/*!<image akaros*/

	image rose1,/*!<  item 1*/ rose2,/*!<  item 2*/ rose3,/*!<  item 3*/ heart1,/*!<  item 4*/ heart2,/*!<  item 4*/ image_snake,/*!<  npc1*/ image_bard,/*!<  npc2*/ image_shelly; /*!< npc3*/
	int direction,/*!<  direction du scrolling*/ level; /*!<  current level*/
	Mix_Music *level1_music,/*!<  music level 1*/ *level2_music,/*!< music level 2*/ *level3_music;/*!<  music level 3*/
	int fullscreen; /*!< fullscreen variable*/
	SDL_Rect camera;  /*!< rect du camera*/
	double acceleration; /*!<variable double pour acceleration*/ 
	SDL_Rect animation_posScreen/*!< rect pour pos de l'animation screen*/, animation_posSprite; /*!< rect pour pos de l'ainmation sprite*/
	SDL_Surface *animation_sprite; /*!< surface pour sprite animation*/
	image tab_frames[9];/*!< tableau de 9 images pour l'animation du background*/
	int i/*!< variable i compteur pour animation background*/ , akaros_appearance, /*!<variable de control pour akaros*/akaros_is_shown,/*!< variable de control pour akaros*/ akaros_shake, /*!< variable de control pour shake de akaros*/  akaros_direction;/*!< variable pour la direction de akaros*/
	entity e; /*!< les entitées*/
	int h,/*!< compteur pour les entitées horizontal*/h1,/*!< comptuer pour une autre horizontal*/v4; /*!< comptuer pour les entitées vertical*/
	int rose1_is_collected,/*!<  variable de control pour item 1*/ rose2_is_collected, /*!<  variable de control pour item 2*/rose3_is_collected, /*!< variable de control item 3*/heart1_is_collected,/*!<  variable de control item 4*/ heart2_is_collected;/*!<  variable de control pour item 5*/	
	image image_white05, image_white100, image_dust;
	int v5, v6;
	image back2;
	image mask, mask2;
	image mini, head;
	int m,pt;
	image image_bee;
	image image_napta, image_pt; 

}background;

typedef struct 
{
	int score,/*!< score qui va etre sauvgarder dans un fichier*/ time; /*!<  le temps qui va etre sauvgarder dans un fichier*/
	char playerName[20];/*!<  le nom du joueur qui va etre sauvgarder dans un fichier*/
}scoreInfo; 

void initBack(background * b);
void afficherBack2p(background b, SDL_Surface * screen);
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
void projectiles_movement(background *b, int direction, int saut);
void end_game(image* img1, image* img2, int intensite, int duree, background b, SDL_Surface* screen,personne p);
void float_items(background *b, float *angle_ptr, float frequency, float amplitude, float speed);
void circular_motion(image *img1, image *img2, image *img3, float *angle, float radius, float angular_speed, float center_x, float center_y);
#endif



