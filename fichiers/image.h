#ifndef IMAGE_H
#define IMAGE_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct
{
	char *url;
	SDL_Rect pos_img_affiche;//partie de l'image qui doit etre affichée
	SDL_Rect pos_img_ecran; //position de l'image par rapport l'ecran
	SDL_Surface *img;
}image;
////ANIMATION
typedef struct
{
	image frame1,frame2,frame3,frame4,frame5,frame6,frame7,frame8,frame9,frame10,frame11,frame12,frame13,frame14,frame15,frame16,frame17,frame18,frame19,frame20,frame21,frame22,frame23,frame24,frame25,frame26,frame27,frame28,frame29,frame30,frame31,frame32,frame33;
image frame34, frame35, frame36, frame37, frame38, frame39, frame40, frame41, frame42, frame43;
}animation;

void initialiser_animation_frog_frames(image *imge, int screen_h, int screen_w, char nomImage[]);
void initialiser_animation_frog(animation *frog, int screen_h, int screen_w, image *imge1, image *imge2, image *imge3, SDL_Surface *screen);
void liberer_animation(animation frog);


////BACKGROUND
typedef struct
{
//LOADING	
	image loading1, loading2, loading3;
//WINDOWED
	image mainmenu, play , options; 
//FULLSCREEN
  	image mainmenu_fullscreen, play_fullscreen, options_fullscreen;
}image_background;

void initialiser_image_background(image *imge, int screen_h, int screen_w, char nomImage[]) ;
void initialiser_image_background_finale(image_background *background, int screen_h, int screen_w);//to be called in the main.c
void liberer_background(image_background background);

////BOUTON
typedef struct
{
//CLICKED
 	image clicked_play, clicked_options, clicked_credits, clicked_quit, clicked_back, clicked_right_arrow, clicked_left_arrow, clicked_tick;
//UNCLICKED
	image /*unclicked_play, unclicked_options, unclicked_credits, unclicked_quit,*/ unclicked_back, unclicked_right_arrow, unclicked_left_arrow, unclicked_tick;
//IMAGES
	image options_title, black_70opacity, groupnames, slider_music, slider_button_music, slider_chunk, slider_button_chunk, displaymode_box; 
}image_bouton; 
void initialiser_image_bouton(image *imgbtn, int x, int y, char nomImage[]);
void liberer_bouton(image_bouton bouton);


void afficher_imageBMP(SDL_Surface *screen, image imge);
void afficher_imageBTN(SDL_Surface *screen,image imge);
void liberer_image(image imge); 
#endif
