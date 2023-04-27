#include "text.h"

void initialiser_texte(texte *txte, int x, int y)
{
    TTF_Init(); //initialiser SDL_ttf
    (*txte).police=TTF_OpenFont("fonts/Lostar.ttf",80); //chargement d'une police et inistialiser la taille
    (*txte).color_txt.r=200;
    (*txte).color_txt.g=74;
    (*txte).color_txt.b=42;
    (*txte).pos_txt.x=x;
    (*txte).pos_txt.y=y;
} 
void initialiser_texte_score(texte *txte, int x, int y)
{
    TTF_Init(); //initialiser SDL_ttf
    (*txte).police=TTF_OpenFont("fonts/Middle.ttf",45); //chargement d'une police et inistialiser la taille
    (*txte).color_txt.r=255;
    (*txte).color_txt.g=255;
    (*txte).color_txt.b=255;
    (*txte).pos_txt.x=x;
    (*txte).pos_txt.y=y;
} 
void afficher_texte_volume_music(SDL_Surface *screen, texte txte)
{
    txte.txt=TTF_RenderText_Blended(txte.police,"Music",txte.color_txt); 
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);  //coller la surface
}
void afficher_texte_volume_chunk(SDL_Surface *screen, texte txte)
{
    txte.txt=TTF_RenderText_Blended(txte.police,"SFX",txte.color_txt); 
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);  //coller la surface
}
void afficher_texte_fullscreen(SDL_Surface *screen, texte txte)
{
    txte.txt=TTF_RenderText_Blended(txte.police,"Fullscreen", txte.color_txt); 
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);  //coller la surface
}
void afficher_texte_windowed(SDL_Surface *screen, texte txte)
{
    txte.txt=TTF_RenderText_Blended(txte.police," Windowed ", txte.color_txt); 
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);  //coller la surface
}
void initialiser_texte_leaderboard(texte *txte, int x, int y)
{
    TTF_Init(); //initialiser SDL_ttf
    (*txte).police=TTF_OpenFont("fonts/Middle.ttf",30); //chargement d'une police et inistialiser la taille
    (*txte).color_txt.r=255;
    (*txte).color_txt.g=255;
    (*txte).color_txt.b=255;
    (*txte).pos_txt.x=x;
    (*txte).pos_txt.y=y;
} 
void afficher_texte_custom(SDL_Surface *screen, texte txte,char string[])
{
    txte.txt=TTF_RenderText_Blended(txte.police,string, txte.color_txt); 
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);  //coller la surface
}
void liberer_texte(texte txte)
{
    TTF_CloseFont(txte.police);//fermer la police
    TTF_Quit(); //arreter la SDL_ttf
}

