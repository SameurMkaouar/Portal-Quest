#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "image.h"
#include "text.h"




typedef struct 
{
	image back,x,o; 
	int tabsuivi[9];
	SDL_Rect pos_pre_case;
 	int joueur ; 
	int tour; 
	texte txte; 
}tic;

	

void initialiserTic (tic * t) ;

void afficherTic(tic t,SDL_Surface* ecran);

int atilganer(int tabsuivi[]);

void Resultat (int tabsuivi[],SDL_Surface* ecran,tic t );

void liberer_tic( tic *t);

int minmax(int tabsuivi[], int joueur);

void calcul_coup(int tabsuivi[]);



































#endif
