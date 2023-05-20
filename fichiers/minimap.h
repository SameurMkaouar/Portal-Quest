/**
* @file minimap.h
* @brief minimap file
* @author (yassine && sameur)  
* @version 3.2
* @date May 03, 2023
*
* Ici figure le fichier minimap.h dans lequel il ya minimap
*
*/

#ifndef MINIMAP_H
#define MINIMAP_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 1600
#define SCREEN_W 800
#include "hero.h"
#include "background.h"
typedef struct
{
    SDL_Surface *txt; /*!< text surface*/
    SDL_Rect pos_txt; /*!< text position*/
    SDL_Colour color_txt; /*!< text color*/
    TTF_Font *police; /*!< text font*/
}textemelek;
typedef struct
{
    char *url; /*!< level url*/
    SDL_Rect pos_img_affiche; /*!< the part to show from the rect*/
    SDL_Rect pos_img_ecran; /*!< position of the rect*/
    SDL_Surface *img; /*!< image surface*/
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
SDL_Surface *img_minimap; /*!< minimap surface*/
SDL_Rect pos_minimap_ecran; /*!< minimap position*/
SDL_Surface *img_alan; /*!< hero head's surface*/
SDL_Rect pos_alan_ecran; /*!< hero head's position*/
int level;
}minimap;
typedef struct
{
int x, y;
}position;
void MAJMinimap(personne p,  minimap * m, SDL_Rect camera, int redimensionnement);
void afficher (minimap m, SDL_Surface * screen);
void Liberer (minimap * m);
void MAJobject(imagemelek imge,minimap * m, SDL_Rect camera, int redimensionnement,SDL_Surface *screen);
void afficher_texte_temps(SDL_Surface *screen, textemelek txte,int time);
void initialiser_texte_temps(textemelek *txte);
int collision_perfect(image *mask,SDL_Rect p, background b);
int collision_ground(image *mask,SDL_Rect p, background b);
int collision_wall(image *mask,SDL_Rect p, background b);
int collision_ladder(image *mask,SDL_Rect p, background b);
int collision_maze_right(image *mask,SDL_Rect p);
int collision_maze_up(image *mask,SDL_Rect p);
int collision_maze_down(image *mask,SDL_Rect p);
int collision_maze_left(image *mask,SDL_Rect p);
int collision_lava(image *mask,SDL_Rect p, background b);
#endif
