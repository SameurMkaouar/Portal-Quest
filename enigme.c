#include "enigme.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void init_dos(enigme *e)
{

	e->img =IMG_Load("imagess/dos1.bmp");
		if(e->img==NULL)
{
	return ;
}

	e->pos1.x=700;
	e->pos1.y=50;
	e->pos1.w=0;
	e->pos1.h=e->img->h;

	e->img =IMG_Load("imagess/dos2.bmp");
		if(e->img==NULL)
{
	return ;
}

	e->pos2.x=900;
	e->pos2.y=50;
	e->pos2.w=0;
	e->pos2.h=e->img->h;

	

	e->img =IMG_Load("imagess/dos3.bmp");
		if(e->img==NULL)
{
	return ;
}

	e->pos3.x=1100;
	e->pos3.y=50;
	e->pos3.w=0;
	e->pos3.h=e->img->h;

	
	

	
	e->img =IMG_Load("imagess/dos4.bmp");
		if(e->img==NULL)
{
	return ;
}

	e->pos4.x=1300;
	e->pos4.y=50;
	e->pos4.w=0;
	e->pos4.h=e->img->h;

	
	

	e->img =IMG_Load("imagess/dos5.bmp");
		if(e->img==NULL)
{
	return ;
}

	e->pos5.x=700;
	e->pos5.y=350;
	e->pos5.w=0;
	e->pos5.h=e->img->h;

	
	

	
	e->img =IMG_Load("imagess/dos6.bmp");
		if(e->img==NULL)
{
	return ;
}

	e->pos6.x=900;
	e->pos6.y=350;
	e->pos6.w=0;
	e->pos6.h=e->img->h;

	
	

	e->img =IMG_Load("imagess/dos7.bmp");
		if(e->img==NULL)
{
	return ;
}

	e->pos7.x=1100;
	e->pos7.y=350;
	e->pos7.w=0;
	e->pos7.h=e->img->h;

	
	

	
	e->img =IMG_Load("imagess/dos8.bmp");
		if(e->img==NULL)
{
	return ;
}

	e->pos8.x=1300;
	e->pos8.y=350;
	e->pos8.w=0;
	e->pos8.h=e->img->h;

	


	
	
}
void init_back(enigme *back)
{int screen_w=1450,screen_h=800;
back->img =IMG_Load("imagess/back.bmp");
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
