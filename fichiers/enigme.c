#include "enigme.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"
void init_dos(enigme *e)
{

	e->img =IMG_Load("imagess/dos.png");
		if(e->img==NULL)
{
	return ;
}

	e->pos1.x=320;
	e->pos1.y=125;
	e->pos1.w=0;
	e->pos1.h=e->img->h;

	e->img =IMG_Load("imagess/dos.png");
		if(e->img==NULL)
{
	return ;
}

	e->pos2.x=540;
	e->pos2.y=125;
	e->pos2.w=0;
	e->pos2.h=e->img->h;

	

	e->img =IMG_Load("imagess/dos.png");
		if(e->img==NULL)
{
	return ;
}

	e->pos3.x=760;
	e->pos3.y=125;
	e->pos3.w=0;
	e->pos3.h=e->img->h;

	
	

	
	e->img =IMG_Load("imagess/dos.png");
		if(e->img==NULL)
{
	return ;
}

	e->pos4.x=980;
	e->pos4.y=125;
	e->pos4.w=0;
	e->pos4.h=e->img->h;

	
	

	e->img =IMG_Load("imagess/dos.png");
		if(e->img==NULL)
{
	return ;
}

	e->pos5.x=320;
	e->pos5.y=425;
	e->pos5.w=0;
	e->pos5.h=e->img->h;

	
	

	
	e->img =IMG_Load("imagess/dos.png");
		if(e->img==NULL)
{
	return ;
}

	e->pos6.x=540;
	e->pos6.y=425;
	e->pos6.w=0;
	e->pos6.h=e->img->h;

	
	

	e->img =IMG_Load("imagess/dos.png");
		if(e->img==NULL)
{
	return ;
}

	e->pos7.x=760;
	e->pos7.y=425;
	e->pos7.w=0;
	e->pos7.h=e->img->h;

	
	

	
	e->img =IMG_Load("imagess/dos.png");
		if(e->img==NULL)
{
	return ;
}

	e->pos8.x=980;
	e->pos8.y=425;
	e->pos8.w=0;
	e->pos8.h=e->img->h;	
	
}
void init_back(enigme *back)
{int screen_w=1450,screen_h=800;
back->img =IMG_Load("imagess/back.png");
		if(back->img==NULL){
			printf("unable to load background: %s\n",SDL_GetError());
			return;
}
		back->pos1.x=0;
		back->pos1.y=0;
		back->pos2.x=0;
		back->pos2.y=0;
		back->pos2.w=(screen_w);
		back->pos2.h=screen_h;
}

void liberer_dos(enigme e)
{
	SDL_FreeSurface(e.img);

}
void fade_in(SDL_Surface *surface1,enigme back, SDL_Surface *screen, SDL_Rect re)
{
    Uint32 *pixels1 = (Uint32 *)surface1->pixels;
    int pixelCount1 = surface1->w * surface1->h;
    int alpha = 0;
    while (alpha < 255)
    {
        for (int i = 0; i < pixelCount1; i++)
        {
            Uint8 r, g, b, a;
            SDL_GetRGBA(pixels1[i], surface1->format, &r, &g, &b, &a);
            pixels1[i] = SDL_MapRGBA(surface1->format, r, g, b, alpha);
        }
        SDL_FillRect(SDL_GetVideoSurface(), NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));
	SDL_BlitSurface(back.img,NULL,screen,&back.pos1);
	SDL_BlitSurface(back.img,NULL,screen,&back.pos2);
	
        SDL_BlitSurface(surface1, NULL, screen, &re);
	SDL_Flip(screen);
        SDL_Flip(SDL_GetVideoSurface());
        SDL_Delay(15); 
        alpha += 5; 
    }
}
void fade_in2(SDL_Surface *surface1,enigme back, SDL_Surface *screen, SDL_Rect re, image iemg)
{
    Uint32 *pixels1 = (Uint32 *)surface1->pixels;
    int pixelCount1 = surface1->w * surface1->h;
    int alpha = 0;
    while (alpha < 255)
    {
        for (int i = 0; i < pixelCount1; i++)
        {
            Uint8 r, g, b, a;
            SDL_GetRGBA(pixels1[i], surface1->format, &r, &g, &b, &a);
            pixels1[i] = SDL_MapRGBA(surface1->format, r, g, b, alpha);
        }
        SDL_FillRect(SDL_GetVideoSurface(), NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));
	SDL_BlitSurface(back.img,NULL,screen,&back.pos1);
	SDL_BlitSurface(back.img,NULL,screen,&back.pos2);
	SDL_BlitSurface(iemg.img,NULL,screen,&iemg.pos_img_ecran);
        SDL_BlitSurface(surface1, NULL, screen, &re);
	SDL_Flip(screen);
        SDL_Flip(SDL_GetVideoSurface());
        SDL_Delay(15); 
        alpha += 5; 
    }
}
void fade_in3(SDL_Surface *surface1,image back, SDL_Surface *screen, SDL_Rect re)
{
    Uint32 *pixels1 = (Uint32 *)surface1->pixels;
    int pixelCount1 = surface1->w * surface1->h;
    int alpha = 0;
    while (alpha < 255)
    {
        for (int i = 0; i < pixelCount1; i++)
        {
            Uint8 r, g, b, a;
            SDL_GetRGBA(pixels1[i], surface1->format, &r, &g, &b, &a);
            pixels1[i] = SDL_MapRGBA(surface1->format, r, g, b, alpha);
        }
        SDL_FillRect(SDL_GetVideoSurface(), NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));
	SDL_BlitSurface(back.img,NULL,screen,&back.pos_img_ecran);
	
        SDL_BlitSurface(surface1, NULL, screen, &re);
	SDL_Flip(screen);
        SDL_Flip(SDL_GetVideoSurface());
        SDL_Delay(15); 
        alpha += 5; 
    }
}
void fade_in4(SDL_Surface *surface1,image back, SDL_Surface *screen, SDL_Rect re)
{
    Uint32 *pixels1 = (Uint32 *)surface1->pixels;
    int pixelCount1 = surface1->w * surface1->h;
    int alpha = 0;
    while (alpha < 255)
    {
        for (int i = 0; i < pixelCount1; i++)
        {
            Uint8 r, g, b, a;
            SDL_GetRGBA(pixels1[i], surface1->format, &r, &g, &b, &a);
            pixels1[i] = SDL_MapRGBA(surface1->format, r, g, b, alpha);
        }
        //SDL_FillRect(SDL_GetVideoSurface(), NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));
	//SDL_BlitSurface(back.img,NULL,screen,&back.pos_img_ecran);
	
        SDL_BlitSurface(surface1, NULL, screen, &re);
	SDL_Flip(screen);
        SDL_Flip(SDL_GetVideoSurface());
        SDL_Delay(15); 
        alpha += 5; 
    }
}
void afficherEnigme(enigme e, SDL_Surface * screen)
{	
	SDL_BlitSurface(e.img,NULL,screen,&e.pos1);
	SDL_BlitSurface(e.img,NULL,screen,&e.pos2);
	SDL_BlitSurface(e.img,NULL,screen,&e.pos3);
	SDL_BlitSurface(e.img,NULL,screen,&e.pos4);
	SDL_BlitSurface(e.img,NULL,screen,&e.pos5);
	SDL_BlitSurface(e.img,NULL,screen,&e.pos6);
	SDL_BlitSurface(e.img,NULL,screen,&e.pos7);
	SDL_BlitSurface(e.img,NULL,screen,&e.pos8);
}
void afficher_back(enigme back,SDL_Surface *screen) 
{
	SDL_BlitSurface(back.img,NULL,screen,&back.pos1);
	SDL_BlitSurface(back.img,NULL,screen,&back.pos2);
}
void liberer_back(enigme back) 
{
	SDL_FreeSurface(back.img);

}
void liberer_boutton(enigme boutton) 
{
	
	SDL_FreeSurface(boutton.img);
}

int recherche(int value, int tab[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (tab[i] == value)
        {
            return 1;
        }
    }
    return 0;
}
int rech(SDL_Rect pos,SDL_Rect randi[])
{
int i;
for(i=1;i<9;i++)
{
	if((randi[i].x==pos.x)&&(randi[i].y==pos.y))
return 1;
}
return 0;
}


int check(char first[],char second[])
{
char ch[30];
char ch1[30];
sprintf(ch,"%s1.png",first);
sprintf(ch1,"%s1.png",second);
if(strcmp(second,ch)==0)
return 1; 
if(strcmp(first,ch1)==0)
return 1; 
else return 0;



}

