/**
* @file image.c
* @brief image file
* @author Team Shelly Studios
* @version 3.2
* @date May 03, 2023
*
* Ici figure le fichier image.c dans lequel on a le traitement des images
*
*/
#include "image.h"

/**
* @brief show image
* @param screen 
* @param image
* @return Nothing
*/
void afficher_imageBMP(SDL_Surface *screen, image imge)  //coller et afficher l'image du back dans screen
{
    SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
/**
* @brief show an image
* @param screen 
* @param texte 
* @return Nothing
*/
void afficher_imageBTN(SDL_Surface *screen,image imge)   //coller et afficher l'image du btn dans screen
{
    SDL_BlitSurface(imge.img,NULL,screen, &imge.pos_img_ecran);
}
/**
* @brief to free a memory allocated by a variable of type image
* @param screen 
* @param texte 
* @return Nothing
*/
void liberer_image(image imge)
{
    SDL_FreeSurface(imge.img);
}
/**
* @brief an image
* @param screen 
* @param the height of the image
* @param the width of the image
* @param the url of the image
* @return Nothing
*/
void initialiser_animation_frog_frames(image *imge, int screen_h, int screen_w, char nomImage[]) 
{   
	(*imge).url=nomImage;
	(*imge).img=IMG_Load((*imge).url);
	if((*imge).img == NULL)
	{
	    printf("unable to load background image %s \n",SDL_GetError());
	    return;
	}
	(*imge).pos_img_ecran.x=0;
	(*imge).pos_img_ecran.y=0;
	(*imge).pos_img_affiche.x=0;
	(*imge).pos_img_affiche.y=0;
	(*imge).pos_img_affiche.h=screen_h;
	(*imge).pos_img_affiche.w=screen_w;
}
/**
* @brief To the images of the animation
* @param animation
* @param the height of the image
* @param the width of the image
* @param image 1
* @param image 2
* @param image 3
* @return Nothing
*/
void initialiser_animation_frog(animation *frog, int screen_h, int screen_w, image *imge1, image *imge2, image *imge3, SDL_Surface *screen)
{

	afficher_imageBMP(screen, *imge1);
 	SDL_Flip(screen);
 	initialiser_animation_frog_frames(&frog->frame1, screen_h, screen_w, "images/frogframes/frame1.png");
	initialiser_animation_frog_frames(&frog->frame2, screen_h, screen_w, "images/frogframes/frame2.png");
	initialiser_animation_frog_frames(&frog->frame3, screen_h, screen_w, "images/frogframes/frame3.png");
	initialiser_animation_frog_frames(&frog->frame4, screen_h, screen_w, "images/frogframes/frame4.png");
	initialiser_animation_frog_frames(&frog->frame5, screen_h, screen_w, "images/frogframes/frame5.png");
	initialiser_animation_frog_frames(&frog->frame6, screen_h, screen_w, "images/frogframes/frame6.png");
	initialiser_animation_frog_frames(&frog->frame7, screen_h, screen_w, "images/frogframes/frame7.png");
	initialiser_animation_frog_frames(&frog->frame8, screen_h, screen_w, "images/frogframes/frame8.png");
	initialiser_animation_frog_frames(&frog->frame9, screen_h, screen_w, "images/frogframes/frame9.png");
	initialiser_animation_frog_frames(&frog->frame10, screen_h, screen_w, "images/frogframes/frame10.png");
	initialiser_animation_frog_frames(&frog->frame11, screen_h, screen_w, "images/frogframes/frame11.png");
	//BLACK SCREEN
	initialiser_animation_frog_frames(&frog->frame34, screen_h, screen_w, "images/frogframes/frame35.png");
	initialiser_animation_frog_frames(&frog->frame35, screen_h, screen_w, "images/frogframes/frame36.png");
	initialiser_animation_frog_frames(&frog->frame36, screen_h, screen_w, "images/frogframes/frame37.png");
	afficher_imageBMP(screen, *imge2); //liberer_image(imge1);
	SDL_Flip(screen);
	initialiser_animation_frog_frames(&frog->frame12, screen_h, screen_w, "images/frogframes/frame12.png");
	initialiser_animation_frog_frames(&frog->frame13, screen_h, screen_w, "images/frogframes/frame13.png");
	initialiser_animation_frog_frames(&frog->frame14, screen_h, screen_w, "images/frogframes/frame14.png");
	initialiser_animation_frog_frames(&frog->frame15, screen_h, screen_w, "images/frogframes/frame15.png");
	initialiser_animation_frog_frames(&frog->frame16, screen_h, screen_w, "images/frogframes/frame16.png");
	initialiser_animation_frog_frames(&frog->frame17, screen_h, screen_w, "images/frogframes/frame17.png");
	initialiser_animation_frog_frames(&frog->frame18, screen_h, screen_w, "images/frogframes/frame18.png");
	initialiser_animation_frog_frames(&frog->frame19, screen_h, screen_w, "images/frogframes/frame19.png");
	initialiser_animation_frog_frames(&frog->frame20, screen_h, screen_w, "images/frogframes/frame20.png");
	initialiser_animation_frog_frames(&frog->frame21, screen_h, screen_w, "images/frogframes/frame21.png");
	initialiser_animation_frog_frames(&frog->frame22, screen_h, screen_w, "images/frogframes/frame22.png");
	//BLACK SCREEN
	initialiser_animation_frog_frames(&frog->frame37, screen_h, screen_w, "images/frogframes/frame37.png");
	initialiser_animation_frog_frames(&frog->frame38, screen_h, screen_w, "images/frogframes/frame38.png");
	initialiser_animation_frog_frames(&frog->frame39, screen_h, screen_w, "images/frogframes/frame39.png");
	afficher_imageBMP(screen, *imge3); //liberer_image(imge2);
	SDL_Flip(screen);
	initialiser_animation_frog_frames(&frog->frame23, screen_h, screen_w, "images/frogframes/frame23.png");
	initialiser_animation_frog_frames(&frog->frame24, screen_h, screen_w, "images/frogframes/frame24.png");
	initialiser_animation_frog_frames(&frog->frame25, screen_h, screen_w, "images/frogframes/frame25.png");
	initialiser_animation_frog_frames(&frog->frame26, screen_h, screen_w, "images/frogframes/frame26.png");
	initialiser_animation_frog_frames(&frog->frame27, screen_h, screen_w, "images/frogframes/frame27.png");
	initialiser_animation_frog_frames(&frog->frame28, screen_h, screen_w, "images/frogframes/frame28.png");
	initialiser_animation_frog_frames(&frog->frame29, screen_h, screen_w, "images/frogframes/frame29.png");
	initialiser_animation_frog_frames(&frog->frame30, screen_h, screen_w, "images/frogframes/frame30.png");
	initialiser_animation_frog_frames(&frog->frame31, screen_h, screen_w, "images/frogframes/frame31.png");
	initialiser_animation_frog_frames(&frog->frame32, screen_h, screen_w, "images/frogframes/frame32.png");
	initialiser_animation_frog_frames(&frog->frame33, screen_h, screen_w, "images/frogframes/frame33.png");
	//BLACK SCREEN 
	initialiser_animation_frog_frames(&frog->frame40, screen_h, screen_w, "images/frogframes/frame40.png");
	initialiser_animation_frog_frames(&frog->frame41, screen_h, screen_w, "images/frogframes/frame41.png");
	initialiser_animation_frog_frames(&frog->frame42, screen_h, screen_w, "images/frogframes/frame42.png");
	initialiser_animation_frog_frames(&frog->frame43, screen_h, screen_w, "images/frogframes/frame43.png");
	initialiser_animation_frog_frames(&frog->frame05, screen_h, screen_w, "images/frogframes/frame05.png");
	//liberer_image(imge3);
}
/**
* @brief To free the images of the animation 
* @param animation
* @param the height of the image
* @param the width of the image
* @param image 1
* @param image 2
* @param image 3
* @return Nothing
*/
void liberer_animation(animation frog)
{
	SDL_FreeSurface(frog.frame1.img); SDL_FreeSurface(frog.frame2.img); SDL_FreeSurface(frog.frame3.img);	
	SDL_FreeSurface(frog.frame4.img); SDL_FreeSurface(frog.frame5.img); SDL_FreeSurface(frog.frame6.img);
	SDL_FreeSurface(frog.frame7.img); SDL_FreeSurface(frog.frame8.img); SDL_FreeSurface(frog.frame9.img);
	SDL_FreeSurface(frog.frame10.img); SDL_FreeSurface(frog.frame11.img); SDL_FreeSurface(frog.frame12.img);
	SDL_FreeSurface(frog.frame13.img); SDL_FreeSurface(frog.frame14.img); SDL_FreeSurface(frog.frame15.img); 
 	SDL_FreeSurface(frog.frame16.img); SDL_FreeSurface(frog.frame17.img); SDL_FreeSurface(frog.frame18.img);
	SDL_FreeSurface(frog.frame19.img); SDL_FreeSurface(frog.frame20.img); SDL_FreeSurface(frog.frame21.img);	
	SDL_FreeSurface(frog.frame22.img); SDL_FreeSurface(frog.frame23.img); SDL_FreeSurface(frog.frame24.img);	
	SDL_FreeSurface(frog.frame25.img); SDL_FreeSurface(frog.frame26.img); SDL_FreeSurface(frog.frame27.img);
	SDL_FreeSurface(frog.frame28.img); SDL_FreeSurface(frog.frame29.img); SDL_FreeSurface(frog.frame30.img);	
	SDL_FreeSurface(frog.frame31.img); SDL_FreeSurface(frog.frame32.img); SDL_FreeSurface(frog.frame33.img);

}
//**************************************BACKGROUND********************
/**
* @brief To initialize the image of the background
* @param image 
* @param screen height 
* @param screen width
* @param the url of the image
* @return Nothing
*/
void initialiser_image_background(image *imge, int screen_h, int screen_w, char nomImage[]) //chargement des images background
{   
	(*imge).url=nomImage;
	(*imge).img=IMG_Load((*imge).url);
	if((*imge).img == NULL)
	{
	    printf("unable to load background image %s \n",SDL_GetError());
	    return;
	}
	(*imge).pos_img_ecran.x=0;
	(*imge).pos_img_ecran.y=0;
	(*imge).pos_img_affiche.x=0;
	(*imge).pos_img_affiche.y=0;
	(*imge).pos_img_affiche.h=screen_h;
	(*imge).pos_img_affiche.w=screen_w;
}/**
* @brief To initialize the image of the background
* @param image 
* @param screen height 
* @param screen width
* @return Nothing
*/
void initialiser_image_background_finale(image_background *background, int screen_h, int screen_w)
{
 initialiser_image_background(&background->mainmenu, screen_h, screen_w, "images/background_mainmenu.bmp");
 initialiser_image_background(&background->play, screen_h, screen_w, "images/background_play.bmp");
 initialiser_image_background(&background->options, screen_h, screen_w, "images/background_options.bmp");            		
 //FULL SCREEN
 initialiser_image_background(&background->mainmenu_fullscreen, screen_h, screen_w, "images/background_mainmenu_fullscreen.bmp");
 initialiser_image_background(&background->play_fullscreen, screen_h, screen_w, "images/background_play_fullscreen.bmp");
 initialiser_image_background(&background->options_fullscreen,screen_h,screen_w,"images/background_options_fullscreen.bmp");            
}
/**
* @brief To free the images of the background of the main menu
* @param image 
* @param screen height 
* @param screen width
* @param the url of the image
* @return Nothing
*/
void liberer_background(image_background background)
{
//LOADING
	SDL_FreeSurface(background.loading1.img); SDL_FreeSurface(background.loading2.img); SDL_FreeSurface(background.loading3.img);
//WINDOWED
	SDL_FreeSurface(background.mainmenu.img); SDL_FreeSurface(background.options.img); SDL_FreeSurface(background.play.img);
//FULLSCREEN
	SDL_FreeSurface(background.mainmenu_fullscreen.img); SDL_FreeSurface(background.options_fullscreen.img); SDL_FreeSurface(background.play_fullscreen.img);
}

//**************************************BOUTON*******************************
/**
* @brief To initialize an image 
* @param x coordinates
* @param y coordinates
* @param url image 
* @return Nothing
*/
void initialiser_image_bouton(image *imgbtn, int x, int y, char nomImage[]) //chargement des images background
{   
	(*imgbtn).url=nomImage;
	(*imgbtn).img=IMG_Load((*imgbtn).url);
	if((*imgbtn).img == NULL)
	{
	    printf("unable to load background image %s \n",SDL_GetError());
	    return;
	}
       (*imgbtn).pos_img_affiche.x=0;
       (*imgbtn).pos_img_affiche.y=0;
       (*imgbtn).pos_img_affiche.w=0;
       (*imgbtn).pos_img_affiche.h=0;
       (*imgbtn).pos_img_ecran.x=x;
       (*imgbtn).pos_img_ecran.y=y;
}
/**
* @brief To initialize an image 
* @param x coordinates
* @param y coordinates
* @param height
* @param width
* @param url image 
* @return Nothing
*/
void initialiser_image_sprite(image *imgbtn, int x, int y,int h, int w, char nomImage[]) //chargement des images background
{   
	(*imgbtn).url=nomImage;
	(*imgbtn).img=IMG_Load((*imgbtn).url);
	if((*imgbtn).img == NULL)
	{
	    printf("unable to load background image %s \n",SDL_GetError());
	    return;
	}
       (*imgbtn).pos_img_affiche.x=0;
       (*imgbtn).pos_img_affiche.y=0;
       (*imgbtn).pos_img_affiche.w=w;
       (*imgbtn).pos_img_affiche.h=h;
       (*imgbtn).pos_img_ecran.x=x;
       (*imgbtn).pos_img_ecran.y=y;
}
/**
* @brief To free the memory of image bouton
* @param the image 
* @return Nothing
*/
void liberer_bouton(image_bouton bouton)
{
//CLICKED
	SDL_FreeSurface(bouton.clicked_play.img); SDL_FreeSurface(bouton.clicked_options.img); SDL_FreeSurface(bouton.clicked_credits.img);
	SDL_FreeSurface(bouton.clicked_quit.img); SDL_FreeSurface(bouton.clicked_back.img); SDL_FreeSurface(bouton.clicked_right_arrow.img);
	SDL_FreeSurface(bouton.clicked_left_arrow.img);  
//UNCLICKED
 	/*SDL_FreeSurface(bouton.unclicked_play.img); SDL_FreeSurface(bouton.unclicked_options.img); SDL_FreeSurface(bouton.unclicked_credits.img);
	SDL_FreeSurface(bouton.unclicked_quit.img);*/ SDL_FreeSurface(bouton.unclicked_back.img); SDL_FreeSurface(bouton.unclicked_right_arrow.img);
	SDL_FreeSurface(bouton.unclicked_left_arrow.img);
//images
	SDL_FreeSurface(bouton.black_70opacity.img); SDL_FreeSurface(bouton.options_title.img); SDL_FreeSurface(bouton.groupnames.img);
	SDL_FreeSurface(bouton.slider_music.img); SDL_FreeSurface(bouton.slider_button_music.img); SDL_FreeSurface(bouton.slider_chunk.img);
	SDL_FreeSurface(bouton.slider_button_chunk.img); SDL_FreeSurface(bouton.displaymode_box.img);
}


