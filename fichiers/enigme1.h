#ifndef ENIGMETF_H_INCLUDED
#define ENIGMETF_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <time.h>

typedef struct{ 

	SDL_Surface *background;//backf naffichi fiha qsts ou reps;
	SDL_Surface *questions;//surface bch naffichi feha qsts; 
	SDL_Surface *reponses[4];// hatitou ftab bch nafichoi txt mtaa lles reps;
	SDL_Surface *button;//button libch nselectionnih;
	SDL_Surface *button1;

	int pos_selected;//ken nezel al 1.2.3;
	SDL_Rect pos_questions;//kol wahda andha pos;
	SDL_Rect pos_reponses1;
	SDL_Rect pos_reponses2; 
	SDL_Rect pos_reponses3; 
	int num_questions;
	
	SDL_Rect pos_reponses1txt;//pos mta texte libch nhotou fouk image mta button;
	SDL_Rect pos_reponses2txt;
	SDL_Rect pos_reponses3txt;
	int reponsesjustes;
	int positionreponsesjustes;//pos reponse juste liheya lpos mta image wtexte; 
	TTF_Font *police; 
	TTF_Font *police1;
	
		
	

}enigmee;
void aafficherEnigme(enigmee ee,SDL_Surface *ecran);
void genererEnigme(enigmee *ee,char *nomfichier);
#endif
