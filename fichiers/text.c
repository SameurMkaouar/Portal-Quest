/**
* @file text.c
* @brief text file
* @author Team Shelly Studios
* @version 3.2
* @date May 03, 2023
*
* Ici figure le fichier text.c dans lequel on a traitement de texte
*
*/
#include "text.h"
/**
* @brief To initialize text
* @param x coordinates
* @param y coordinates 
* @return Nothing
*/
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
/**
* @brief To initialize text
* @param x coordinates
* @param y coordinates 
* @return Nothing
*/
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
/**
* @brief To show the text which represents the volume of the music
* @param screen 
* @param texte 
* @return Nothing
*/
void afficher_texte_volume_music(SDL_Surface *screen, texte txte)
{
    txte.txt=TTF_RenderText_Blended(txte.police,"Music",txte.color_txt); 
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);  //coller la surface
}
/**
* @brief To show the text which represents the volume of chunk
* @param screen 
* @param texte 
* @return Nothing
*/
void afficher_texte_volume_chunk(SDL_Surface *screen, texte txte)
{
    txte.txt=TTF_RenderText_Blended(txte.police,"SFX",txte.color_txt); 
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);  //coller la surface
}
/**
* @brief To show the text which of the display mode
* @param screen 
* @param texte 
* @return Nothing
*/
void afficher_texte_fullscreen(SDL_Surface *screen, texte txte)
{
    txte.txt=TTF_RenderText_Blended(txte.police,"Fullscreen", txte.color_txt); 
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);  //coller la surface
}
/**
* @brief To show the text which of the display mode
* @param screen 
* @param texte 
* @return Nothing
*/
void afficher_texte_windowed(SDL_Surface *screen, texte txte)
{
    txte.txt=TTF_RenderText_Blended(txte.police," Windowed ", txte.color_txt); 
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);  //coller la surface
}
/**
* @brief To initialize the text which of the leaderboard
* @param screen 
* @param texte 
* @return Nothing
*/
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
/**
* @brief To show a text 
* @param screen 
* @param texte 
* @return Nothing
*/
void afficher_texte_custom(SDL_Surface *screen, texte txte,char string[])
{
    txte.txt=TTF_RenderText_Blended(txte.police,string, txte.color_txt); 
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);  //coller la surface
}
/**
* @brief To free a memory allocated by a variable of type texte
* @param screen 
* @param texte 
* @return Nothing
*/
void liberer_texte(texte txte)
{
    TTF_CloseFont(txte.police);//fermer la police
    TTF_Quit(); //arreter la SDL_ttf
}
/**
* @brief a simple fade in effect used for showing a text slowly
* @param screen 
* @param texte 
* @return Nothing
*/
void fade_in_text(SDL_Surface* textSurface, SDL_Surface* screen, int x, int y, int duration_ms) {
    int alpha = 0;
    int start_time = SDL_GetTicks();

    while (alpha < 255) {
        Uint32 elapsed_time = SDL_GetTicks() - start_time;
        alpha = (int) (255.0 * elapsed_time / duration_ms);

        if (alpha > 255) {
            alpha = 255;
        }

        SDL_Surface* tempSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, textSurface->w, textSurface->h, 32, 0, 0, 0, 0);
        SDL_BlitSurface(textSurface, NULL, tempSurface, NULL);
        SDL_SetAlpha(tempSurface, SDL_SRCALPHA, alpha);
        SDL_Rect textRect = { x, y, 0, 0 };
        SDL_BlitSurface(tempSurface, NULL, screen, &textRect);
        SDL_Flip(screen);

        SDL_FreeSurface(tempSurface);
        SDL_Delay(80);
    }
}
/**
* @brief a simple typewriting effect 
* @param screen 
* @param texte 
* @return Nothing
*/
void typewriter(const char* text, SDL_Surface *screen, int y, SDL_Event event)
{
    TTF_Init();
    SDL_Color color= {255, 255, 255};
    int delay =50;
    TTF_Font* font = TTF_OpenFont("fonts/arcade.ttf", 20);

    SDL_Surface* textSurface = NULL;
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        char c = text[i];
        textSurface = TTF_RenderGlyph_Solid(font, c, color);
        SDL_Rect destRect = {235+ i * 20, y, 0, 0};
        int miny, maxy;
        TTF_GlyphMetrics(font, c, NULL, NULL, &miny, &maxy, NULL);
        destRect.y -= maxy;        
        SDL_BlitSurface(textSurface, NULL, screen, &destRect);
        SDL_Flip(screen);
	SDL_PollEvent(&event);
	if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE) delay=0;
        else delay=60;
	SDL_Delay(delay);
        SDL_FreeSurface(textSurface);
    }

    SDL_Delay(400);

    TTF_CloseFont(font);
}
void typewriterend(const char* text, SDL_Surface *screen, int y, SDL_Event event)
{
    TTF_Init();
    SDL_Color color= {0, 0, 0};
    int delay =50;
    TTF_Font* font = TTF_OpenFont("fonts/Middle.ttf", 24);

    SDL_Surface* textSurface = NULL;
    int i;
    delay=140;
    for (i = 0; i < strlen(text); i++)
    {
        char c = text[i];
        textSurface = TTF_RenderGlyph_Solid(font, c, color);
        SDL_Rect destRect = {520+ i * 14, y, 0, 0};
        int miny, maxy;
        TTF_GlyphMetrics(font, c, NULL, NULL, &miny, &maxy, NULL);
        destRect.y -= maxy;        
        SDL_BlitSurface(textSurface, NULL, screen, &destRect);
        SDL_Flip(screen);
	SDL_PollEvent(&event);
	/*if (i>18) delay=450;
	else if (i>15) delay=210;
	else if (i>10) delay=110;*/
	if (i>16) delay+=50;
	SDL_Delay(delay);
        SDL_FreeSurface(textSurface);
    }

    SDL_Delay(400);

    TTF_CloseFont(font);
}
