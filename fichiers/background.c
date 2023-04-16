#include "background.h"
#include "image.h"

void initBack(background * b)
{
	if (b->fullscreen==0)
	{
		initialiser_image_background(&b->background_ocean, 800 , 16192, "images/backgrounds/ocean_windowed.png");
		initialiser_image_background(&b->background_forest, 800, 1450, "images/backgrounds/forest_windowed.jpg");
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
	
	initialiser_image_bouton(&b->clock, 500, 30, "images/clock.png");
}


void afficherBack(background b, SDL_Surface * screen)
{
	switch(b.level)
	{
		case 1: SDL_BlitSurface(b.background_ocean.img,&b.background_ocean.pos_img_affiche,screen,&b.background_ocean.pos_img_ecran);
	SDL_BlitSurface(b.tab_frames[b.i].img,&b.tab_frames[b.i].pos_img_affiche,screen,&b.tab_frames[b.i].pos_img_ecran);
break;
		case 2: SDL_BlitSurface(b.background_forest.img,&b.background_forest.pos_img_affiche,screen,&b.background_forest.pos_img_ecran);
 break;
		case 3: SDL_BlitSurface(b.background_city.img,&b.background_city.pos_img_affiche,screen,&b.background_city.pos_img_ecran);
 break;
	}  
	//SDL_BlitSurface(b.animation_sprite,&b.animation_posSprite,screen, &b.animation_posScreen);
	//clock
	SDL_BlitSurface(b.clock.img,NULL,screen,&b.clock.pos_img_ecran);
	
}

void scrolling(background *b, int direction, Uint32 dt) 
{ int i;
	Uint32 dx;
	dx=0.5*(b->acceleration)*dt*dt + (b->vitesse)*dt ;
	if (direction ==1) {b->camera.x+=dx; (b->animation_posScreen.x)-=dx; }
	else if (direction == -1) {b->camera.x-=dx; (b->animation_posScreen.x)+=dx; }
	(b->background_ocean).pos_img_affiche.x=b->camera.x;
	(b->background_ocean).pos_img_affiche.y=b->camera.y;
	(b->tab_frames[b->i]).pos_img_affiche.x=(b->background_ocean).pos_img_affiche.x;
//(b->tab_frames[b->i+1]).pos_img_affiche.x=(b->background_ocean).pos_img_affiche.x;
//(b->tab_frames[b->i+2]).pos_img_affiche.x=(b->background_ocean).pos_img_affiche.x;
	(b->tab_frames[b->i]).pos_img_affiche.y=b->camera.y;
}
void animerBack (background* b)
{
b->i++;
if (b->i==6) b->i=0; 
/*
b->animation_posSprite.x+=120;
if (b->animation_posSprite.x==480) b->animation_posSprite.x=0;*/
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
