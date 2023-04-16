#ifndef TEXT_H
#define TEXT_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
	SDL_Surface *txt;
	SDL_Rect pos_txt;
	SDL_Colour color_txt;
	TTF_Font *police;
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
#endif
