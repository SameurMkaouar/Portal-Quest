#ifndef ENIGME_H
#define ENIGME_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



struct enigme
{
	char *url;
	SDL_Rect pos1,pos0;
	SDL_Rect pos2, pos3, pos4, pos5, pos6, pos7, pos8;
	SDL_Surface *img;
};
typedef struct enigme enigme;

typedef struct
{
	SDL_Surface *img;
	char *url;
}images;


void init_dos(enigme *e);
void init_back(enigme *back);
void liberer_dos(enigme e);
void afficherEnigme(enigme e, SDL_Surface * screen);
void afficher_back(enigme back,SDL_Surface *screen);
int recherche(int value, int tab[], int n);
void liberer_back(enigme back);
int rech(SDL_Rect poss,SDL_Rect randi[]);
int check(char first[],char second[]);
 
#endif
