/**
* @file text.h
* @brief text file
* @author Team Shelly Studios
* @version 3.2
* @date May 03, 2023
*
* Ici figure le fichier text.c dans lequel on a traitement de texte
*
*/

#ifndef TEXT_H
#define TEXT_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
    SDL_Surface *txt; /*!< text surface*/
    SDL_Rect pos_txt; /*!< text position*/
    SDL_Colour color_txt; /*!< text color */
    TTF_Font *police; /*!< text font*/
}texte;

void initialiser_texte(texte *txte, int x, int y);
void initialiser_texte_score(texte *txte, int x, int y);
void afficher_texte_volume_music(SDL_Surface *screen, texte txte);
void afficher_texte_volume_chunk(SDL_Surface *screen, texte txte);
void afficher_texte_fullscreen(SDL_Surface *screen, texte txte);
void afficher_texte_windowed(SDL_Surface *screen, texte txte);
void afficher_texte_custom(SDL_Surface *screen, texte txte,char string[]);
void liberer_texte(texte txte);
void initialiser_texte_leaderboard(texte *txte, int x, int y);
void fade_in_text(SDL_Surface* textSurface, SDL_Surface* screen, int x, int y, int duration_ms);
void typewriter(const char* text, SDL_Surface *screen, int y, SDL_Event event);
void typewriterend(const char* text, SDL_Surface *screen, int y, SDL_Event event);
#endif
