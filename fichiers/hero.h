/**
* @file hero.h
* @brief hero file
* @author Sameur Mkaouar
* @version 3.2
* @date May 03, 2023
*
* Ici figure le fichier hero.c dans lequel il ya le personnage principal
*
*/
#ifndef HERO_H
#define HERO_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdbool.h>
#include "image.h"
#include "text.h"

typedef struct
{
 image image_perso, image_vies, image_mana;
 int nb_vies, score, saut, direction;
 double vitesse, acceleration;
 SDL_Surface *sprite;
 SDL_Rect posScreen, posSprite;
 texte score_text;
 float mana;
}personne;
void initPerso(personne *p);
void initPerso2(personne *p);
void afficherPerso(personne p, SDL_Surface * screen);
void movePerso(personne *p,Uint32 dt);
void animerPerso(personne *p);
void saut(personne *p,Uint32 dt);
#endif 
