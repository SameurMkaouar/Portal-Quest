#ifndef MINIMAP_H
#define MINIMAP_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 1600
#define SCREEN_W 800
#include "hero.h"
typedef struct
{
	SDL_Surface *txt;
	SDL_Rect pos_txt;
	SDL_Colour color_txt;
	TTF_Font *police;
}textemelek;
typedef struct
{
	char *url;
	SDL_Rect pos_img_affiche;
	SDL_Rect pos_img_ecran; 
	SDL_Surface *img;
int level;
}imagemelek;
/*typedef struct
{
    SDL_Rect posMarioRel;
    imagemelek imge;
int up;
int direction;
} personnage;*/
typedef struct
{
SDL_Surface *img_minimap;
SDL_Rect pos_minimap_ecran;
SDL_Surface *img_alan;
SDL_Rect pos_alan_ecran;
int level;
}minimap;
void MAJMinimap(personne p,  minimap * m, SDL_Rect camera, int redimensionnement);
void afficher (minimap m, SDL_Surface * screen);
void Liberer (minimap * m);
void MAJobject(imagemelek imge,minimap * m, SDL_Rect camera, int redimensionnement,SDL_Surface *screen);
void afficher_texte_temps(SDL_Surface *screen, textemelek txte,int time);
void initialiser_texte_temps(textemelek *txte);
#endif
