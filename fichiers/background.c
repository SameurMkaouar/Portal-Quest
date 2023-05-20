/**
* @file background.c
* @brief background file
* @author Yassine Kharrat
* @version 3.2
* @date May 03, 2023
*
* Ici figure le fichier background.c dans lequel il y'a les fonctions du background
*
*/
#include "background.h"
#include "image.h"
#include "hero.h"
/**
* @brief To initialize the background b .
* @param b  background
* @return Nothing
*/
void initBack(background * b)
{
	initialiser_image_background(&b->back2, 800 , 16192, "images/backgrounds/ocean_windowed.png");
	if (b->fullscreen==0)
	{
		initialiser_image_background(&b->mask,800,16192,"images/mask.png");
		initialiser_image_background(&b->mask2,800,1450,"images/mask2.png");
		initialiser_image_background(&b->background_ocean, 800 , 16192, "images/backgrounds/ocean_windowed.png");
		initialiser_image_background(&b->background_forest, 800, 1450, "images/backgrounds/forest_windowed.jpg");
		initialiser_image_garbage_moving(&b->garbage_moving,9335, 175, "images/garbage_moving.png");
		initialiser_image_junkpit(&b->image_junkpit, 9550, 635, "images/junkpit.png");
		initialiser_akaros(&b->image_akaros,14800,220, "images/akaros.png");
		initEntity(&b->e);
		initialiser_image_bouton(&b->rose1, 3933,0,"images/rose1.png");
		initialiser_image_bouton(&b->image_pt, 6810,0,"images/pt.png");

		initialiser_image_bouton(&b->image_bee, 12460,80,"images/nahla.png");

		initialiser_image_bouton(&b->rose2, 5827 ,0,"images/rose2.png");
		initialiser_image_bouton(&b->rose3, 8150,0,"images/rose3.png");
		initialiser_image_bouton(&b->heart1, 10516 ,0,"images/potion_flipped.png");
		initialiser_image_bouton(&b->heart2, 13275 ,0,"images/potion.png");
		initialiser_image_background(&b->background_fall, 5000, 1450, "images/fall.png");
	
		initialiser_image_bouton(&b->image_snake, 7600,164,"images/snake.png");
		initialiser_image_bouton(&b->image_bard, 2880,705,"images/bard.png");
		initialiser_image_bouton(&b->image_shelly, 120,1510,"images/shelly.png");
		initialiser_image_bouton(&b->image_napta, 12359,134,"images/napta.png");

		initialiser_image_background(&b->image_white100, 800, 1450, "images/white/op100.png");
		initialiser_image_background(&b->image_white05, 800 , 1450, "images/white/op5.png");

 		initialiser_image_bouton(&b->head, 1100, 150, "images/tawfik.png");
 		initialiser_image_bouton(&b->mini, 1090, 0, "images/mini.png");
	}
	//FULLSCREEN
	else 
	{
		//initialiser_image_background(&b->background_ocean, 1080, 1920, "images/backgrounds/ocean_fullscreen.png");
		//initialiser_image_background(&b->background_forest, 1080, 1920, "images/backgrounds/forest_fullscreen.png");
		//initialiser_image_background(&b->background_city, 1080, 1920, "images/backgrounds/city_fullscreen.png");
	}
	b->camera.x=0;
	b->camera.y=0;// to change each time jump changes 
	(b->background_ocean).pos_img_affiche.x=b->camera.x;
	(b->background_ocean).pos_img_affiche.h=800;
	(b->background_ocean).pos_img_affiche.w=16192;
	(b->mask).pos_img_affiche.x=b->camera.x;
	(b->mask).pos_img_affiche.h=800;
	(b->mask).pos_img_affiche.w=16192;
	(b->mask2).pos_img_affiche.w=1450;
	(b->mask2).pos_img_ecran.x=0;
	(b->mask2).pos_img_ecran.y=0;
	b->background_forest.pos_img_ecran.y=800;
	b->background_forest.pos_img_ecran.x=0;
	b->background_fall.pos_img_ecran.y=0;
	b->background_fall.pos_img_ecran.x=0;
	(b->background_fall).pos_img_affiche.h=2624;
	(b->background_fall).pos_img_affiche.w=1450;
	int i; 
	char c[30];
	for (i=0;i<7;i++)
	{
		sprintf(c,"images/frames/frame%d.png",i);
		initialiser_image_background(&b->tab_frames[i], 800 , 16192, c);
	}
	/*b->animation_posScreen.x= 500;
	b->animation_posScreen.y= 500;
        b->animation_posSprite.x= 0;
	b->animation_posSprite.y= 0;
	b->animation_posSprite.w= 480/4;
	b->animation_posSprite.h= 340;
	b->animation_sprite=IMG_Load("images/SpriteBubbles.png");*/
	
	//initialiser_image_bouton(&b->clock, 500, 30, "images/clock.png");
	b->akaros_appearance=1;
	b->akaros_is_shown=0;
	b->akaros_shake=0;
	b->h=0;
	b->h1=0;
	b->v4=0; b->v5=0; b->v6=0;
	b->akaros_direction=1;

	b->rose1_is_collected=0;
	b->rose2_is_collected=0;
	b->rose3_is_collected=0;
	b->heart1_is_collected=0;
	b->heart2_is_collected=0;
	b->pt=0;
	b->image_snake.pos_img_affiche.w=135;
	b->image_snake.pos_img_affiche.h=64;

	b->image_napta.pos_img_affiche.w=138;
	b->image_napta.pos_img_affiche.h=90;

	b->image_bee.pos_img_affiche.w=140;
	b->image_bee.pos_img_affiche.h=130;

	b->image_bard.pos_img_affiche.w=284/4;
	b->image_bard.pos_img_affiche.h=66;

	b->image_shelly.pos_img_affiche.w=72;
	b->image_shelly.pos_img_affiche.h=40;

	b->mini.pos_img_affiche.w=362;
	b->mini.pos_img_affiche.h=200;
	/*b->e.vertical1.pos_img_affiche.w=35;
	b->e.vertical1.pos_img_affiche.h=60;
	b->e.vertical2.pos_img_affiche.w=35;
	b->e.vertical2.pos_img_affiche.h=60;
	b->e.vertical3.pos_img_affiche.w=35;
	b->e.vertical3.pos_img_affiche.h=60;
	b->e.horizontal1.pos_img_affiche.w=60;
	b->e.horizontal1.pos_img_affiche.h=35;
	b->e.horizontal2.pos_img_affiche.w=60;
	b->e.horizontal2.pos_img_affiche.h=35;
	b->e.horizontal3.pos_img_affiche.w=60;
	b->e.horizontal3.pos_img_affiche.h=35;*/

	b->m=0;
	b->back2.pos_img_ecran.x=725;
}
/**
* @brief To initialize entities
* @param entity e
* @return Nothing
*/
void initEntity(entity *e)
{
	initialiser_image_bouton(&e->vertical1,/*14318*/14331,750,"images/waterflipped.png");
	initialiser_image_bouton(&e->vertical2,/*14474*/14493,750,"images/waterflipped.png");
	initialiser_image_bouton(&e->vertical3,/*14623*/14623,750,"images/waterflipped.png");
	initialiser_image_bouton(&e->vertical4,15172+32,60,"images/stone1.png");
	initialiser_image_bouton(&e->vertical5,15268+32,0,"images/stone2.png");
	initialiser_image_bouton(&e->vertical6,15361+32,-60,"images/stone2.png");
	initialiser_image_bouton(&e->horizontal1,14100,544,"images/water.png");
	initialiser_image_bouton(&e->horizontal2,14141,611,"images/canflipped.png");
	initialiser_image_bouton(&e->horizontal3,14766,611,"images/can.png");
	
}
/**
* @brief To show the background .
* @param b the background
* @param surface screen 
* @return Nothing
*/
void afficherBack2p(background b, SDL_Surface * screen)
{
    // Split the screen in half
    SDL_Rect screen_left = {0, 0, screen->w / 2, screen->h};
    SDL_Rect screen_right = {screen->w / 2, 0, screen->w / 2, screen->h};

    switch(b.level)
    {
            case 1: 
            // Render the left half of the screen
            SDL_BlitSurface(b.background_ocean.img, &b.background_ocean.pos_img_affiche, screen, &screen_left);
            SDL_BlitSurface(b.tab_frames[b.i].img, &b.tab_frames[b.i].pos_img_affiche, screen, &screen_left);
            SDL_BlitSurface(b.garbage_moving.img, &b.garbage_moving.pos_img_affiche, screen, &b.garbage_moving.pos_img_ecran);
            SDL_BlitSurface(b.image_junkpit.img, NULL, screen, &b.image_junkpit.pos_img_ecran);
            SDL_BlitSurface(b.image_snake.img, &b.image_snake.pos_img_affiche, screen, &b.image_snake.pos_img_ecran);
            SDL_BlitSurface(b.image_bard.img, &b.image_bard.pos_img_affiche, screen, &b.image_bard.pos_img_ecran);
            if (b.akaros_shake)
            {
                SDL_BlitSurface(b.e.vertical1.img, NULL, screen, &b.e.vertical1.pos_img_ecran);
                SDL_BlitSurface(b.e.vertical2.img, NULL, screen, &b.e.vertical2.pos_img_ecran);
                SDL_BlitSurface(b.e.vertical3.img, NULL, screen, &b.e.vertical3.pos_img_ecran);
                SDL_BlitSurface(b.e.vertical4.img, NULL, screen, &b.e.vertical4.pos_img_ecran);
                SDL_BlitSurface(b.e.vertical5.img, NULL, screen, &b.e.vertical5.pos_img_ecran);
                SDL_BlitSurface(b.e.vertical6.img, NULL, screen, &b.e.vertical6.pos_img_ecran);    
                SDL_BlitSurface(b.e.horizontal1.img, NULL, screen, &b.e.horizontal1.pos_img_ecran);
                SDL_BlitSurface(b.e.horizontal2.img, NULL, screen, &b.e.horizontal2.pos_img_ecran);
                SDL_BlitSurface(b.e.horizontal3.img, NULL, screen, &b.e.horizontal3.pos_img_ecran);
            }
	    
            if (b.akaros_is_shown == 1) SDL_BlitSurface(b.image_akaros.img, &b.image_akaros.pos_img_affiche, screen, &b.image_akaros.pos_img_ecran);
            if (b.rose1_is_collected == 0) SDL_BlitSurface(b.rose1.img, NULL, screen, &b.rose1.pos_img_ecran);
            if (b.rose2_is_collected == 0) SDL_BlitSurface(b.rose2.img, NULL, screen, &b.rose2.pos_img_ecran);
            if (b.rose3_is_collected == 0) SDL_BlitSurface(b.rose3.img, NULL, screen, &b.rose3.pos_img_ecran);
            if (b.heart1_is_collected == 0) SDL_BlitSurface(b.heart1.img, NULL, screen, &b.heart1.pos_img_ecran);
            if (b.heart2_is_collected == 0 && b.akaros_appearance == 0) SDL_BlitSurface(b.heart2.img, NULL, screen, &b.heart2.pos_img_ecran);

            // Render the right half of the screen
SDL_BlitSurface(b.back2.img,&b.back2.pos_img_affiche,screen,&screen_right);
            //SDL_BlitSurface(b.background_ocean.img, &b.background_ocean.pos_img_affiche, screen, &screen_right);
            SDL_BlitSurface(b.tab_frames[b.i].img, &b.back2.pos_img_affiche, screen, &screen_right);
            b.garbage_moving.pos_img_ecran.x+=725;
            SDL_BlitSurface(b.garbage_moving.img, &b.garbage_moving.pos_img_affiche, screen, &b.garbage_moving.pos_img_ecran);
	    	b.garbage_moving.pos_img_ecran.x-=725;
            b.image_junkpit.pos_img_ecran.x+=725;SDL_BlitSurface(b.image_junkpit.img, NULL, screen, &b.image_junkpit.pos_img_ecran);b.image_junkpit.pos_img_ecran.x-=725;
            b.image_snake.pos_img_ecran.x+=725;SDL_BlitSurface(b.image_snake.img, &b.image_snake.pos_img_affiche, screen, &b.image_snake.pos_img_ecran);b.image_snake.pos_img_ecran.x-=725;
            b.image_bard.pos_img_ecran.x+=725;SDL_BlitSurface(b.image_bard.img, &b.image_bard.pos_img_affiche, screen, &b.image_bard.pos_img_ecran);b.image_bard.pos_img_ecran.x-=725;
            if (b.akaros_shake)
            {
                b.e.vertical1.pos_img_ecran.x+=725; SDL_BlitSurface(b.e.vertical1.img, NULL, screen, &b.e.vertical1.pos_img_ecran); b.e.vertical1.pos_img_ecran.x-=725;
                b.e.vertical2.pos_img_ecran.x+=725; SDL_BlitSurface(b.e.vertical2.img, NULL, screen, &b.e.vertical2.pos_img_ecran); b.e.vertical2.pos_img_ecran.x-=725;
                b.e.vertical3.pos_img_ecran.x+=725; SDL_BlitSurface(b.e.vertical3.img, NULL, screen, &b.e.vertical3.pos_img_ecran); b.e.vertical3.pos_img_ecran.x-=725;
                b.e.vertical4.pos_img_ecran.x+=725; SDL_BlitSurface(b.e.vertical4.img, NULL, screen, &b.e.vertical4.pos_img_ecran); b.e.vertical4.pos_img_ecran.x-=725;
                b.e.vertical5.pos_img_ecran.x+=725; SDL_BlitSurface(b.e.vertical5.img, NULL, screen, &b.e.vertical5.pos_img_ecran); b.e.vertical5.pos_img_ecran.x-=725;
                b.e.vertical6.pos_img_ecran.x+=725; SDL_BlitSurface(b.e.vertical6.img, NULL, screen, &b.e.vertical6.pos_img_ecran); b.e.vertical6.pos_img_ecran.x-=725;
                b.e.horizontal1.pos_img_ecran.x+=725; SDL_BlitSurface(b.e.horizontal1.img, NULL, screen, &b.e.horizontal1.pos_img_ecran); b.e.horizontal1.pos_img_ecran.x-=725;
                b.e.horizontal2.pos_img_ecran.x+=725; SDL_BlitSurface(b.e.horizontal2.img, NULL, screen, &b.e.horizontal2.pos_img_ecran); b.e.horizontal2.pos_img_ecran.x-=725;
                b.e.horizontal3.pos_img_ecran.x+=725; SDL_BlitSurface(b.e.horizontal3.img, NULL, screen, &b.e.horizontal3.pos_img_ecran); b.e.horizontal3.pos_img_ecran.x-=725;
            }
	    b.image_akaros.pos_img_ecran.x+=725;
            b.rose1.pos_img_ecran.x+=725;
            b.rose2.pos_img_ecran.x+=725;
            b.rose3.pos_img_ecran.x+=725;
            b.heart1.pos_img_ecran.x+=725;
            b.heart2.pos_img_ecran.x+=725;
            if (b.akaros_is_shown == 1) SDL_BlitSurface(b.image_akaros.img, &b.image_akaros.pos_img_affiche, screen, &b.image_akaros.pos_img_ecran);
            if (b.rose1_is_collected == 0) SDL_BlitSurface(b.rose1.img, NULL, screen, &b.rose1.pos_img_ecran);
            if (b.rose2_is_collected == 0) SDL_BlitSurface(b.rose2.img, NULL, screen, &b.rose2.pos_img_ecran);
            if (b.rose3_is_collected == 0) SDL_BlitSurface(b.rose3.img, NULL, screen, &b.rose3.pos_img_ecran);
            if (b.heart1_is_collected == 0) SDL_BlitSurface(b.heart1.img, NULL, screen, &b.heart1.pos_img_ecran);
            if (b.heart2_is_collected == 0 && b.akaros_appearance == 0) SDL_BlitSurface(b.heart2.img, NULL, screen, &b.heart1.pos_img_ecran);
	    b.image_akaros.pos_img_ecran.x-=725;
            b.rose1.pos_img_ecran.x-=725;
            b.rose2.pos_img_ecran.x-=725;
            b.rose3.pos_img_ecran.x-=725;
            b.heart1.pos_img_ecran.x-=725;
            b.heart2.pos_img_ecran.x-=725;
        break;
    }
            
}

/**
* @brief scrolling function.
* @param b the background
* @param integer direction
* @param uint 32dt
* @return Nothing
*/


void scrolling(background *b, int direction, Uint32 dt) 

{ 	int i;
	Uint32 dx;
	dx=0.5*(b->acceleration)*dt*dt + (5)*dt;
	if (direction ==1) 
	{
	b->camera.x+=dx; 
	(b->garbage_moving.pos_img_ecran.x)-=dx;
	(b->image_junkpit.pos_img_ecran.x)-=dx;
	(b->image_akaros.pos_img_ecran.x)-=dx;
	b->e.vertical1.pos_img_ecran.x-=dx;
	b->e.vertical2.pos_img_ecran.x-=dx;
	b->e.vertical3.pos_img_ecran.x-=dx;
	b->e.vertical4.pos_img_ecran.x-=dx;
	b->e.vertical5.pos_img_ecran.x-=dx;
	b->e.vertical6.pos_img_ecran.x-=dx;
	b->e.horizontal1.pos_img_ecran.x-=dx;
	b->e.horizontal2.pos_img_ecran.x-=dx;
	b->e.horizontal3.pos_img_ecran.x-=dx;

	b->image_pt.pos_img_ecran.x-=dx;

b->image_bee.pos_img_ecran.x-=dx;

	b->rose1.pos_img_ecran.x-=dx;
	b->rose2.pos_img_ecran.x-=dx;
	b->rose3.pos_img_ecran.x-=dx;
	b->heart1.pos_img_ecran.x-=dx;
	b->heart2.pos_img_ecran.x-=dx;

	b->image_snake.pos_img_ecran.x-=dx;
	b->image_bard.pos_img_ecran.x-=dx;
	b->image_napta.pos_img_ecran.x-=dx;

	(b->mask).pos_img_ecran.x-=dx;
	b->mini.pos_img_affiche.x+=dx/3.8;
	}

	else if (direction == -1)
	 {
	  b->camera.x-=dx; 
	  (b->garbage_moving.pos_img_ecran.x)+=dx; 
	  (b->image_junkpit.pos_img_ecran.x)+=dx;
	  (b->image_akaros.pos_img_ecran.x)+=dx;
	b->e.vertical1.pos_img_ecran.x+=dx;
	b->e.vertical2.pos_img_ecran.x+=dx;
	b->e.vertical3.pos_img_ecran.x+=dx;
	b->e.vertical4.pos_img_ecran.x+=dx;
	b->e.vertical5.pos_img_ecran.x+=dx;
	b->e.vertical6.pos_img_ecran.x+=dx;
	b->e.horizontal1.pos_img_ecran.x+=dx;
	b->e.horizontal2.pos_img_ecran.x+=dx;
	b->e.horizontal3.pos_img_ecran.x+=dx;

	b->image_pt.pos_img_ecran.x+=dx;

b->image_bee.pos_img_ecran.x+=dx;

	b->rose1.pos_img_ecran.x+=dx;
	b->rose2.pos_img_ecran.x+=dx;
	b->rose3.pos_img_ecran.x+=dx;
	b->heart1.pos_img_ecran.x+=dx;
	b->heart2.pos_img_ecran.x+=dx;

	b->image_snake.pos_img_ecran.x+=dx;
	b->image_bard.pos_img_ecran.x+=dx;
	b->image_napta.pos_img_ecran.x+=dx;

(b->mask).pos_img_ecran.x+=dx;

b->mini.pos_img_affiche.x-=dx/3.8;
	}
	 (b->background_ocean).pos_img_affiche.x=b->camera.x;
	 (b->background_ocean).pos_img_affiche.y=b->camera.y;
	//(b->mask).pos_img_affiche.x=b->camera.x;
	 //(b->mask).pos_img_affiche.y=b->camera.y;
	 (b->tab_frames[b->i]).pos_img_affiche.x=(b->background_ocean).pos_img_affiche.x;
	
}

void afficherBack(background b, SDL_Surface * screen)
{
	switch(b.level)
	{
		case 1: 
	SDL_BlitSurface(b.background_ocean.img,&b.background_ocean.pos_img_affiche,screen,&b.background_ocean.pos_img_ecran);
	SDL_BlitSurface(b.tab_frames[b.i].img,&b.tab_frames[b.i].pos_img_affiche,screen,&b.tab_frames[b.i].pos_img_ecran);
if (b.m==0 || b.m==2 || b.m==4)
{	
	SDL_BlitSurface(b.mini.img,&b.mini.pos_img_affiche,screen,&b.mini.pos_img_ecran);
	SDL_BlitSurface(b.head.img,NULL,screen,&b.head.pos_img_ecran);
}
SDL_BlitSurface(b.image_napta.img,&b.image_napta.pos_img_affiche,screen,&b.image_napta.pos_img_ecran); 	SDL_BlitSurface(b.garbage_moving.img,&b.garbage_moving.pos_img_affiche,screen,&b.garbage_moving.pos_img_ecran);
	SDL_BlitSurface(b.image_junkpit.img,NULL,screen,&b.image_junkpit.pos_img_ecran);
	SDL_BlitSurface(b.image_snake.img,&b.image_snake.pos_img_affiche,screen,&b.image_snake.pos_img_ecran);
	SDL_BlitSurface(b.image_bard.img,&b.image_bard.pos_img_affiche,screen,&b.image_bard.pos_img_ecran);
	

if (b.akaros_shake)
{
	SDL_BlitSurface(b.e.vertical1.img,NULL,screen,&b.e.vertical1.pos_img_ecran);
	SDL_BlitSurface(b.e.vertical2.img,NULL,screen,&b.e.vertical2.pos_img_ecran);
	SDL_BlitSurface(b.e.vertical3.img,NULL,screen,&b.e.vertical3.pos_img_ecran);
	SDL_BlitSurface(b.e.vertical4.img,NULL,screen,&b.e.vertical4.pos_img_ecran);
	SDL_BlitSurface(b.e.vertical5.img,NULL,screen,&b.e.vertical5.pos_img_ecran);
	SDL_BlitSurface(b.e.vertical6.img,NULL,screen,&b.e.vertical6.pos_img_ecran);	
	SDL_BlitSurface(b.e.horizontal1.img,NULL,screen,&b.e.horizontal1.pos_img_ecran);
	SDL_BlitSurface(b.e.horizontal2.img,NULL,screen,&b.e.horizontal2.pos_img_ecran);
	SDL_BlitSurface(b.e.horizontal3.img,NULL,screen,&b.e.horizontal3.pos_img_ecran);
}
if (b.pt==0 )SDL_BlitSurface(b.image_pt.img, NULL, screen, &b.image_pt.pos_img_ecran);
SDL_BlitSurface(b.image_bee.img, &b.image_bee.pos_img_affiche, screen, &b.image_bee.pos_img_ecran);


if (b.akaros_is_shown==1) SDL_BlitSurface(b.image_akaros.img,&b.image_akaros.pos_img_affiche,screen,&b.image_akaros.pos_img_ecran);
if (b.rose1_is_collected==0) SDL_BlitSurface(b.rose1.img, NULL, screen, &b.rose1.pos_img_ecran);
if (b.rose2_is_collected==0) SDL_BlitSurface(b.rose2.img, NULL, screen, &b.rose2.pos_img_ecran);
if (b.rose3_is_collected==0) SDL_BlitSurface(b.rose3.img, NULL, screen, &b.rose3.pos_img_ecran);
if (b.heart1_is_collected==0) SDL_BlitSurface(b.heart1.img, NULL, screen, &b.heart1.pos_img_ecran);
if (b.heart2_is_collected==0 && b.akaros_appearance==0) SDL_BlitSurface(b.heart2.img, NULL, screen, &b.heart2.pos_img_ecran);
break;
		case 2: SDL_BlitSurface(b.background_forest.img,&b.background_forest.pos_img_affiche,screen,&b.background_forest.pos_img_ecran);
//SDL_BlitSurface(b.mask2.img,NULL,screen,&b.mask2.pos_img_ecran);
SDL_BlitSurface(b.image_shelly.img,&b.image_shelly.pos_img_affiche,screen,&b.image_shelly.pos_img_ecran); 
break;
		case 3: 
	SDL_BlitSurface(b.background_fall.img,&b.background_fall.pos_img_affiche,screen,&b.background_fall.pos_img_ecran);
SDL_BlitSurface(b.image_bard.img,&b.image_bard.pos_img_affiche,screen,&b.image_bard.pos_img_ecran);
 break;
	}
	
	
}
/**
* @brief animate the background.
* @param b the background 
* @return Nothing
*/
void animerBack (background* b)
{
(b->tab_frames[b->i]).pos_img_ecran.y=0;
b->i++;
if (b->i==6) b->i=0; 
(b->garbage_moving.pos_img_affiche.x)+=800;
if (b->garbage_moving.pos_img_affiche.x==4800) b->garbage_moving.pos_img_affiche.x=1601;
if (b->garbage_moving.pos_img_affiche.x>5600) b->garbage_moving.pos_img_affiche.x=0;

b->image_snake.pos_img_affiche.x+=135;
if (b->image_snake.pos_img_affiche.x>405) b->image_snake.pos_img_affiche.x=0;

b->image_bard.pos_img_affiche.x+=76;
if (b->image_bard.pos_img_affiche.x>228) b->image_bard.pos_img_affiche.x=0;

b->image_bee.pos_img_affiche.x+=140;
if (b->image_bee.pos_img_affiche.x>360) b->image_bee.pos_img_affiche.x=0;

b->image_napta.pos_img_affiche.x+=138;
if (b->image_napta.pos_img_affiche.x>430) b->image_napta.pos_img_affiche.x=0;

b->image_shelly.pos_img_affiche.x+=72;
if (b->image_shelly.pos_img_affiche.x>800) b->image_shelly.pos_img_affiche.x=0;

if (b->akaros_appearance==0) 
{
		b->image_akaros.pos_img_affiche.x+=200;
		if (b->image_akaros.pos_img_affiche.x==2000) b->image_akaros.pos_img_affiche.x=1200;
		if (b->akaros_direction==1) b->image_akaros.pos_img_affiche.y=200;
		else b->image_akaros.pos_img_affiche.y=968;
}
}
/**
* @brief save the player's score.
* @param s de type enregistrement scoreinfo 
* @param file fichier de sauvgarde
* @return Nothing
*/
void saveScore(scoreInfo s, char *fileName)
{
	FILE *f;
	f=fopen(fileName, "a+");
	if (f==NULL) printf("Failed to open file\n");
	else 
	{
	fprintf(f,"%s %d %d\n",  s.playerName, s.score, s.time); 	
	fclose(f); 	
	}

}
/**
* @brief tri des scores
* @param file fichier de sauvgarde 
* @param *t tableau pour tri
* @return Nothing
*/
void bestScore(char *fileName, scoreInfo t[]) 
{
	FILE *f; 
	int i=0,j,k,max;
	scoreInfo tampon; 
	f=fopen(fileName, "r+"); 
	if (f==NULL) printf("Failed to open file\n");
	else 
	{
		while(fscanf(f, "%s %d %d\n", t[i].playerName , &t[i].score, &t[i].time)!=EOF)
		{	
			i++;
		}
	for (k=0;k<i-1;k++)
	{
		max=k ;
		for (j=k+1;j<i;j++)
		{
			if (t[j].score>t[max].score)
				max=j;
			else if(t[j].score==t[max].score)
			{
			if (t[j].time>t[max].score)
				max=j;
			}
		}
		tampon=t[k];
		t[k]=t[max];
		t[max]=tampon;
	}
	}
}
/**
* @brief To initialize the leaderboard image
* @param image image de leaderboard
* @param x position sur l'axe x
* @param y position sur l'axe y
* @param char le url de l'image 
* @return Nothing
*/
void initialiser_image_leaderboard(image *imgbtn, int x, int y, char nomImage[]) //chargement des images background
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
* @brief To initialize the garbage image
* @param image de garbage
* @param x position sur l'axe x
* @param y position sur l'axe y
* @param char le url de l'image 
* @return Nothing
*/
void initialiser_image_garbage_moving(image *imgbtn, int x, int y, char nomImage[]) //chargement des images background
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
       (*imgbtn).pos_img_affiche.w=800;
       (*imgbtn).pos_img_affiche.h=800;
       (*imgbtn).pos_img_ecran.x=x;
       (*imgbtn).pos_img_ecran.y=y;
}
/**
* @brief To initialize the junkpit image
* @param image de junkpit
* @param x position sur l'axe x
* @param y position sur l'axe y
* @param char le url de l'image 
* @return Nothing
*/
void initialiser_image_junkpit(image *imgbtn, int x, int y, char nomImage[]) //chargement des images background
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
* @brief To initialize Akaros image
* @param image d'akaros
* @param x position sur l'axe x
* @param y position sur l'axe y
* @param char le url de l'image 
* @return Nothing
*/
void initialiser_akaros(image *imgbtn, int x, int y, char nomImage[]) //chargement des images background
{   
	(*imgbtn).url=nomImage;
	(*imgbtn).img=IMG_Load((*imgbtn).url);
	if((*imgbtn).img == NULL)
	{
	    printf("unable to load background image %s \n",SDL_GetError());
	    return;
	}
       (*imgbtn).pos_img_affiche.x=800;
       (*imgbtn).pos_img_affiche.y=400;
       (*imgbtn).pos_img_affiche.w=200;
       (*imgbtn).pos_img_affiche.h=200;
       (*imgbtn).pos_img_ecran.x=x;
       (*imgbtn).pos_img_ecran.y=y;
}
/**
* @brief To handle the level1 music
* @param image 
* @param music
* @param volume
* @param a is a control variable which decides which music to play 
* @return Nothing
*/
void audio_level1(Mix_Music *music,int volume, int a) //initialiser les fonctions audio et SDL_mixer
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",SDL_GetError());
    }
    switch(a)
{ 
case 1: music=Mix_LoadMUS("audio/music02.mp3"); break;
case 2: music=Mix_LoadMUS("audio/music08.mp3"); break;
case 3: music=Mix_LoadMUS("audio/music07.mp3"); break;
case 4: music=Mix_LoadMUS("audio/music09.mp3"); break;
case 5: music=Mix_LoadMUS("audio/music10.mp3"); break;
case 6: music=Mix_LoadMUS("audio/death.mp3"); break;
}
//chargement de la musique
    Mix_PlayMusic(music,-1); //jouer la musique
    Mix_VolumeMusic(volume);
}
/**
* @brief To handle the seconde level music
* @param image 
* @param music
* @param volume
* @param a is a control variable which decides which music to play 
* @return Nothing
*/
void audio_level2(Mix_Music *music,int volume) //initialiser les fonctions audio et SDL_mixer
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",SDL_GetError());
    }
    music=Mix_LoadMUS("audio/level2.mp3"); //chargement de la musique
    Mix_PlayMusic(music,-1); //jouer la musique
    Mix_VolumeMusic(volume);
}
/**
* @brief A function that shakes the screen
* @param image a shaker 
* @param integer intensity 
* @param integer duration
* @param background b
* @param surface screen
* @return Nothing
*/
void shake_image(image* img, int intensity, int duration, background b, SDL_Surface* screen) {
    int frame_count = duration / 2; 
    int x_offset = 0;
    int y_offset = 0;
    SDL_Rect original_rect = img->pos_img_ecran;

    for (int i = 0; i < frame_count; i++) {
        x_offset = rand() % (intensity * 2) - intensity;
        y_offset = rand() % (intensity * 2) - intensity;

        SDL_Rect offset_rect = {x_offset, y_offset, 0, 0};
        SDL_Rect shifted_rect = {img->pos_img_ecran.x + x_offset, img->pos_img_ecran.y + y_offset, img->pos_img_affiche.w, img->pos_img_affiche.h};

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        afficherBack(b, screen);

        SDL_BlitSurface(img->img, &img->pos_img_affiche, screen, &shifted_rect);
	
	projectiles_movement(&b,1,0);
        SDL_Flip(screen);
        SDL_Delay(10); 
    }
 
    SDL_Rect reset_rect = img->pos_img_ecran;

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

    afficherBack(b, screen);
    SDL_BlitSurface(img->img, &img->pos_img_affiche, screen, &reset_rect);

    SDL_Flip(screen);
}
/**
* @brief To handle the movements of the projectiles
* @param backgroud b
* @param integer direction
* @param saut to type int
* @return Nothing
*/
void projectiles_movement(background *b, int direction, int saut)
{
int speed1, speed2, speed3;
if (b->akaros_shake)
	{
	//if (direction!=0 || saut==1) {speed1=12; speed2=16; speed3=20;}  24 32 40
	/*else {*/speed1=8; speed2=12; speed3=15;//}
		b->e.vertical1.pos_img_ecran.y-=speed1; if (b->e.vertical1.pos_img_ecran.y<-35) b->e.vertical1.pos_img_ecran.y=750;
		b->e.vertical2.pos_img_ecran.y-=speed2; if (b->e.vertical2.pos_img_ecran.y<-35) b->e.vertical2.pos_img_ecran.y=750;	
		b->e.vertical3.pos_img_ecran.y-=speed3; if (b->e.vertical3.pos_img_ecran.y<-35) b->e.vertical3.pos_img_ecran.y=750;
		b->h+=speed1/4;		
		b->e.horizontal2.pos_img_ecran.x+=speed1/4; if (b->h>=570) b->e.horizontal2.pos_img_ecran.x-=570;
		b->e.horizontal3.pos_img_ecran.x-=speed1/4; if (b->h>=570) b->e.horizontal3.pos_img_ecran.x+=570;	
	        if(b->h>=570) b->h=0;
		b->h1+=speed1/2;
		b->e.horizontal1.pos_img_ecran.x-=speed1/2; if (b->h1>=1008) b->e.horizontal1.pos_img_ecran.x+=1008;
		if (b->h1>=1008) b->h1=0;
		b->v4+=speed1;
		b->v5+=speed2;		
		b->v6+=speed3;
		b->e.vertical4.pos_img_ecran.y+=speed1; if (b->v4>=536) b->e.vertical4.pos_img_ecran.y-=536;
		b->e.vertical5.pos_img_ecran.y+=speed2; if (b->v5>=612) b->e.vertical5.pos_img_ecran.y-=612;	
		b->e.vertical6.pos_img_ecran.y+=speed3; if (b->v6>=675) b->e.vertical6.pos_img_ecran.y-=675;
		if (b->v4>=536) b->v4=0;
		if (b->v5>=612) b->v5=0;
		if (b->v6>=675) b->v6=0;



	}

}
/**
* @brief the animation of the game ending
* @param image img1
* @param a second image
* @param integer intensity
* @param integer duration
* @param background b
* @param surface screen
* @param tableau tab 
* @param personne p
* @return Nothing
*/
void end_game(image* img1, image* img2, int intensite, int duree, background b, SDL_Surface* screen,personne p) {
    int frame_count = duree / 2;
    int decalage_x1 = 0, decalage_y1 = 0, decalage_x2 = 0, decalage_y2 = 0;
    SDL_Rect original_rect1 = img1->pos_img_ecran;
    SDL_Rect original_rect2 = img2->pos_img_ecran;
    int a=0,j=0,m=1;
    int f=0; 
    img2->pos_img_affiche.x=1600; 
    img2->pos_img_affiche.y=600;
    float anglle=0; 
    float x= p.image_perso.pos_img_ecran.x;
    float y= p.image_perso.pos_img_ecran.y;
    int rayon=0;
    int cpt=0;
    float vitesse_rose=1, vitesse_rose_y=1;
    for (int i = 0; i < frame_count; i++) {
        decalage_x1 = (rand() % (intensite * 2) - intensite)/2;
        decalage_y1 = (rand() % (intensite * 2) - intensite)/2;
        decalage_x2 = rand() % (intensite * 2) - intensite;
        decalage_y2 = rand() % (intensite * 2) - intensite;

        SDL_Rect decalage_rect1 = {decalage_x1, decalage_y1, 0, 0};
        SDL_Rect decal_rect1 = {img1->pos_img_ecran.x + decalage_x1, img1->pos_img_ecran.y + decalage_y1, img1->pos_img_affiche.w, img1->pos_img_affiche.h};

        SDL_Rect decalage_rect2 = {decalage_x2, decalage_y2, 0, 0};
        SDL_Rect shifted_rect2 = {img2->pos_img_ecran.x + decalage_x2, img2->pos_img_ecran.y + decalage_y2, img2->pos_img_affiche.w, img2->pos_img_affiche.h};

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

        afficherBack(b, screen);
	(b.tab_frames[b.i]).pos_img_ecran.y=0;
	b.i++;
	if (b.i==6) b.i=0;
        SDL_BlitSurface(img1->img, &img1->pos_img_affiche, screen, &decal_rect1);
        SDL_BlitSurface(img2->img, &img2->pos_img_affiche, screen, &shifted_rect2);
        projectiles_movement(&b,1,0);
	circular_motion(&b.rose1, &b.rose2, &b.rose3, &anglle , rayon , 0.1 , x,y);
	SDL_BlitSurface(b.tab_frames[b.i].img,&b.tab_frames[b.i].pos_img_affiche,screen,&b.tab_frames[b.i].pos_img_ecran);
	SDL_BlitSurface(b.rose1.img, NULL, screen, &b.rose1.pos_img_ecran);
	SDL_BlitSurface(b.rose2.img, NULL, screen, &b.rose2.pos_img_ecran);
	SDL_BlitSurface(b.rose3.img, NULL, screen, &b.rose3.pos_img_ecran);
	if (cpt%15==0) intensite++;
	if (cpt%5==0) animerPerso(&p);
	cpt++;
	afficherPerso(p,screen);
	if (f<=10)
	{
	rayon+=10;
	}
	if( f>40) 
	{
	x-=vitesse_rose;
	y-=vitesse_rose_y;
	rayon-=vitesse_rose/4;
	vitesse_rose_y+=0.3;
	vitesse_rose+=0.5;
	}
	if (a>2 && f%4==0 && img2->pos_img_affiche.x>0) img2->pos_img_affiche.x-=200; 
	if (f>64 && f%4==0 && a<20) {a++; intensite++; img2->pos_img_ecran.y+=15;}
        SDL_Flip(screen);
        SDL_Delay(20);
	f++;
	if (a>=14)  {break;}
    }
	for(j=0;j<25;j++)
	{SDL_BlitSurface(b.image_white05.img,NULL, screen,&b.image_white05.pos_img_ecran); SDL_Flip(screen);  SDL_Delay(50);}
	SDL_BlitSurface(b.image_white100.img,NULL, screen,&b.image_white100.pos_img_ecran);

}

/**
* @brief controls the motion of certain objects using sin funciton 
* @param background b
* @param angle de type float
* @param integer  frequency 
* @param float amplitude
* @param float speed
* @return Nothing
*/
void float_items(background *b, float *angle, float frequency, float amplitude, float speed)
{
	b->rose1.pos_img_ecran.y = 687 + sin(*angle) * amplitude;
	b->rose2.pos_img_ecran.y = 80 + sin(*angle) * amplitude;
	b->rose3.pos_img_ecran.y = 160 + sin(*angle) * amplitude;
	b->heart1.pos_img_ecran.y = 160 + sin(*angle) * amplitude;
	b->heart2.pos_img_ecran.y = 248 + sin(*angle) * amplitude;
	b->image_pt.pos_img_ecran.y = 730 + sin(*angle) * amplitude;
	//b->image_bee.pos_img_ecran.y=80+sin(*angle)*amplitude*2;
    *angle += frequency * speed;
    if (*angle > 2 * M_PI) {
        *angle -= 2 * M_PI;
    }
}
/**
* @brief contorls the motion of certain objects in the game that follows a circular path 
* @param image img 1
* @param image img2
* @param image img 3 
* @param float angle
* @param float radius
* @param angular_speed
* @param centre de x
* @param centre de y 
* @return Nothing
*/
void circular_motion(image *img1, image *img2, image *img3, float *angle_ptr, float radius, float angular_speed, float center_x, float center_y) {
    float x1 = center_x + radius * cos(*angle_ptr);
    float y1 = center_y + radius * sin(*angle_ptr);
    float x2 = center_x + radius * cos(*angle_ptr + 2 * M_PI / 3);
    float y2 = center_y + radius * sin(*angle_ptr + 2 * M_PI / 3);
    float x3 = center_x + radius * cos(*angle_ptr + 4 * M_PI / 3);
    float y3 = center_y + radius * sin(*angle_ptr + 4 * M_PI / 3);

    img1->pos_img_ecran.x = x1;
    img1->pos_img_ecran.y = y1;
    img2->pos_img_ecran.x = x2;
    img2->pos_img_ecran.y = y2;
    img3->pos_img_ecran.x = x3;
    img3->pos_img_ecran.y = y3;

    *angle_ptr += angular_speed;

    if (*angle_ptr > 2 * M_PI) {
        *angle_ptr -= 2 * M_PI;
    }
}


