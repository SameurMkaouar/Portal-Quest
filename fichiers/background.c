#include "background.h"
#include "image.h"

void initBack(background * b)
{
	if (b->fullscreen==0)
	{
		initialiser_image_background(&b->background_ocean, 800 , 16192, "images/backgrounds/ocean_windowed.png");
		initialiser_image_background(&b->background_forest, 800, 1450, "images/backgrounds/forest_windowed.jpg");
		initialiser_image_garbage_moving(&b->garbage_moving,9335, 175, "images/garbage_moving.png");
		initialiser_image_junkpit(&b->image_junkpit, 9550, 635, "images/junkpit.png");
		initialiser_akaros(&b->image_akaros,14800,220, "images/akaros.png");
		initEntity(&b->e);
		//initialiser_image_background(&b->background_city, 800, 1450, "images/backgrounds/city_windowed.png");
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
	(b->background_ocean).pos_img_affiche.y=b->camera.y;
	(b->background_ocean).pos_img_affiche.h=800;
	(b->background_ocean).pos_img_affiche.w=16192;
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
	b->vitesse=5;
	b->akaros_appearance=1;
	b->akaros_is_shown=0;
}

void initEntity(entity *e)
{
	initialiser_image_bouton(&e->vertical1,10,10,"images/projectile1");
	initialiser_image_bouton(&e->vertical2,10,10,"images/projectile1");
	initialiser_image_bouton(&e->vertical3,10,10,"images/projectile1");
	initialiser_image_bouton(&e->vertical4,10,10,"images/projectile1");
	initialiser_image_bouton(&e->vertical5,10,10,"images/projectile1");
	initialiser_image_bouton(&e->vertical6,10,10,"images/projectile1");
	initialiser_image_bouton(&e->horizontal1,10,10,"images/projectile1");
	initialiser_image_bouton(&e->horizontal2,10,10,"images/projectile1");
	initialiser_image_bouton(&e->horizontal3,10,10,"images/projectile1");
	
}
void afficherBack(background b, SDL_Surface * screen)
{
	switch(b.level)
	{
		case 1: 
	SDL_BlitSurface(b.background_ocean.img,&b.background_ocean.pos_img_affiche,screen,&b.background_ocean.pos_img_ecran);
	SDL_BlitSurface(b.tab_frames[b.i].img,&b.tab_frames[b.i].pos_img_affiche,screen,&b.tab_frames[b.i].pos_img_ecran);
	SDL_BlitSurface(b.garbage_moving.img,&b.garbage_moving.pos_img_affiche,screen,&b.garbage_moving.pos_img_ecran);
	SDL_BlitSurface(b.image_junkpit.img,NULL,screen,&b.image_junkpit.pos_img_ecran);
	if (b.akaros_is_shown==1) SDL_BlitSurface(b.image_akaros.img,&b.image_akaros.pos_img_affiche,screen,&b.image_akaros.pos_img_ecran);
break;
		case 2: SDL_BlitSurface(b.background_forest.img,&b.background_forest.pos_img_affiche,screen,&b.background_forest.pos_img_ecran);
 break;
		case 3: SDL_BlitSurface(b.background_city.img,&b.background_city.pos_img_affiche,screen,&b.background_city.pos_img_ecran);
 break;
	}  
	//SDL_BlitSurface(b.animation_sprite,&b.animation_posSprite,screen, &b.animation_posScreen);

	
	
}

void scrolling(background *b, int direction, Uint32 dt) 
{ 	int i;
	Uint32 dx;
	dx=0.5*(b->acceleration)*dt*dt + (b->vitesse)*dt ;
	if (direction ==1) {b->camera.x+=dx; (b->garbage_moving.pos_img_ecran.x)-=dx;(b->image_junkpit.pos_img_ecran.x)-=dx;(b->image_akaros.pos_img_ecran.x)-=dx;}
	else if (direction == -1) {b->camera.x-=dx; (b->garbage_moving.pos_img_ecran.x)+=dx; (b->image_junkpit.pos_img_ecran.x)+=dx;(b->image_akaros.pos_img_ecran.x)+=dx;}
	(b->background_ocean).pos_img_affiche.x=b->camera.x;
	(b->background_ocean).pos_img_affiche.y=b->camera.y;
	(b->tab_frames[b->i]).pos_img_affiche.x=(b->background_ocean).pos_img_affiche.x;
}
void animerBack (background* b)
{
b->i++;
if (b->i==6) b->i=0; 
(b->garbage_moving.pos_img_affiche.x)+=800;
if (b->garbage_moving.pos_img_affiche.x==4800) b->garbage_moving.pos_img_affiche.x=1601;
if (b->garbage_moving.pos_img_affiche.x>5600) b->garbage_moving.pos_img_affiche.x=0;
if (b->akaros_appearance==0) 
{
b->image_akaros.pos_img_affiche.y=200;
b->image_akaros.pos_img_affiche.x+=200;
if (b->image_akaros.pos_img_affiche.x==2000) b->image_akaros.pos_img_affiche.x=1200;
}
}
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
void audio_level1(Mix_Music *music,int volume, int a) //initialiser les fonctions audio et SDL_mixer
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",SDL_GetError());
    }
    switch(a)
{ 
case 1: music=Mix_LoadMUS("audio/level1-1.mp3"); break;
case 2: music=Mix_LoadMUS("audio/level1-2.mp3"); break;
case 3: music=Mix_LoadMUS("audio/level1-3.mp3"); break;
}
//chargement de la musique
    Mix_PlayMusic(music,-1); //jouer la musique
    Mix_VolumeMusic(volume);
}
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

void shake_image(image* img, int intensity, int duration, background b, SDL_Surface* screen) {
    int frame_count = duration / 2; // Shake for half the duration in each direction
    int x_offset = 0;
    int y_offset = 0;
    SDL_Rect original_rect = img->pos_img_ecran;

    for (int i = 0; i < frame_count; i++) {
        x_offset = rand() % (intensity * 2) - intensity;
        y_offset = rand() % (intensity * 2) - intensity;

        SDL_Rect offset_rect = {x_offset, y_offset, 0, 0};
        SDL_Rect shifted_rect = {img->pos_img_ecran.x + x_offset, img->pos_img_ecran.y + y_offset, img->pos_img_affiche.w, img->pos_img_affiche.h};

        // Clear the screen
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

        // Blit the background first
        afficherBack(b, screen);

        // Blit the image on top of the background
        SDL_BlitSurface(img->img, &img->pos_img_affiche, screen, &shifted_rect);

        SDL_Flip(screen);
        SDL_Delay(10); // Adjust delay time as needed
    }

    // Reset image position
    SDL_Rect reset_rect = img->pos_img_ecran;

    // Clear the screen again
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

    // Blit the background
    afficherBack(b, screen);

    // Blit the image in its original position
    SDL_BlitSurface(img->img, &img->pos_img_affiche, screen, &reset_rect);

    SDL_Flip(screen);
}

