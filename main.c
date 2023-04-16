#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "ennemi.h"

int main() 
{
     //Declaration des variables

     int boucle = 1;
     SDL_Event event;
     Ennemi E;
     int interface;
     int input;
     

     /*----------------------------------------------------------Initialisation----------------------------------------------------------*/
    //Initialiser SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Ennemi", NULL); // Set window title
    SDL_Surface* screen = SDL_SetVideoMode(1000, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF );
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    //initialisation des resources

    initEnnemi(&E);

    // Creation des surfaces backg et perso
    SDL_Surface* background = IMG_Load("background.jpg"); // temporaire
    SDL_Surface* playerImage = IMG_Load("personne.png"); // temporaire

    // positions du perso
    SDL_Rect posperso = {150, 400, 100, 100}; // temporaire

    /*---------------------------------------------------------- Boucle du jeu ----------------------------------------------------------*/
    while (boucle) 
    {
    /*---------------------------------------------------------- Affichage ----------------------------------------------------------*/

        SDL_BlitSurface(background, NULL, screen, NULL);
        SDL_BlitSurface(playerImage, NULL, screen, &posperso);
    /*---------------------------------------------------------- Lecture-Entree ----------------------------------------------------------*/
        while (SDL_PollEvent(&event)) // temporaire
        {
            switch (event.type) 
            {
                case SDL_QUIT:
                    boucle = 0;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) 
                    {
                        case SDLK_LEFT:
                            posperso.x -= 100;
                            break;
                        case SDLK_RIGHT:
                            posperso.x += 100;
                            break;
                        case SDLK_UP:
                            posperso.y -= 50;
                            break;
                        case SDLK_DOWN:
                            posperso.y += 50;
                            break;
                    }
                    break;
            }
        }

      

      /*----------------------------------------------------------Mise à jour----------------------------------------------------------*/
        deplacer(&E);
        animerEnnemi(&E);
        afficherEnnemi(E, screen);
   

        // verifier la collision
        if (collision(E.pos, posperso)) 
        {
            Mix_PlayChannel(-1, E.collisionSound, 0);
        }

        // refraichir l'ecran
        SDL_Flip(screen);

 
    }

    /*----------------------------------------------------------Libération Espace Mémoire----------------------------------------------------------*/
    Mix_FreeChunk(E.collisionSound);
    Mix_CloseAudio();
    SDL_FreeSurface(background);
    SDL_FreeSurface(playerImage);
    SDL_Quit();

    return 0;
}

