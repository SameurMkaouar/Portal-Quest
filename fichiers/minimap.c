/**
* @file minimap.c
* @brief minimap file
* @author Melek
* @version 3.2
* @date May 03, 2023
*
* Ici figure le fichier minimap.c dans lequel il ya minimap
*
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
#include "hero.h"
/**
* @brief To update the minimap
* @param p hero
* @param m minimap stucture
* @param camera ingame camera
* @param redimensionnement resizing factor
* @return Nothing
*/
void MAJMinimap(personne p,  minimap * m, SDL_Rect camera, int redimensionnement)
{
(*m).img_minimap=IMG_Load("images/backgrounds/minimap.png");

 (*m).img_alan=IMG_Load("images/tawfik.png");
SDL_Rect posJoueurABS;
posJoueurABS.x = p.image_perso.pos_img_ecran.x + camera.x;
posJoueurABS.y = p.image_perso.pos_img_ecran.y + camera.y;

m->pos_minimap_ecran.x=850;
m->pos_minimap_ecran.y=610;

m->pos_alan_ecran.x=posJoueurABS.x * redimensionnement/100+m->pos_minimap_ecran.x;
m->pos_alan_ecran.y=posJoueurABS.y * redimensionnement/100+m->pos_minimap_ecran.y;
//printf("%d %d \n",m->pos_alan_ecran.x,m->pos_alan_ecran.x);

}

/**
* @brief To show the minimap
* @param m minimap
* @param screen ingame screen
* @return Nothing
*/
void afficher (minimap m, SDL_Surface * screen)
{
//SDL_BlitSurface(m.img_minimap,NULL,screen,&m.pos_minimap_ecran);
//SDL_BlitSurface(m.img_alan,NULL,screen,&m.pos_alan_ecran);
}
/**
* @brief To free the minimap
* @param m minimap
* @return Nothing
*/
void Liberer (minimap * m)
{SDL_FreeSurface(m->img_alan);
SDL_FreeSurface(m->img_minimap);
}

/**
* @brief To initialize the clock text
* @param txte time text
* @return Nothing
*/
void initialiser_texte_temps(textemelek *txte)
{
    TTF_Init();//initialiser SDL_ttf
    (*txte).police=TTF_OpenFont("fonts/Middle.ttf",45);//chargement d'une police et inistialiser la taille smr
    (*txte).color_txt.r=255; //smr
    (*txte).color_txt.g=255; //smr
    (*txte).color_txt.b=255;
    (*txte).pos_txt.x=570; //smr
    (*txte).pos_txt.y=30;


}

void initialiser_texte_temps1(textemelek *txte)
{
    TTF_Init();//initialiser SDL_ttf
    (*txte).police=TTF_OpenFont("fonts/Middle.ttf",22);//chargement d'une police et inistialiser la taille smr
    (*txte).color_txt.r=255; //smr
    (*txte).color_txt.g=255; //smr
    (*txte).color_txt.b=255;
    (*txte).pos_txt.x=0; //smr
    (*txte).pos_txt.y=778;


}

void initialiser_texte_temps2(textemelek *txte)
{
    TTF_Init();//initialiser SDL_ttf
    (*txte).police=TTF_OpenFont("fonts/Middle.ttf",22);//chargement d'une police et inistialiser la taille smr
    (*txte).color_txt.r=255; //smr
    (*txte).color_txt.g=255; //smr
    (*txte).color_txt.b=255;
    (*txte).pos_txt.x=0; //smr
    (*txte).pos_txt.y=778;


}
void initialiser_texte_temps3(textemelek *txte)
{
    TTF_Init();//initialiser SDL_ttf
    (*txte).police=TTF_OpenFont("fonts/Middle.ttf",22);//chargement d'une police et inistialiser la taille smr
    (*txte).color_txt.r=255; //smr
    (*txte).color_txt.g=255; //smr
    (*txte).color_txt.b=255;
    (*txte).pos_txt.x=0; //smr
    (*txte).pos_txt.y=778;


}
/**
* @brief To show the time text
* @param screen ingame screen
* @param txte time in str form
* @param time time in int form
* @return Nothing
*/
void afficher_texte_temps(SDL_Surface *screen, textemelek txte,int time)
{char temps[10];
time=time/1000;

int min=time/60;
time=time%60;
if((time<=9)&&(min<=9))
sprintf(temps,"0%d:0%d",min,time);
else if(time<=9)
sprintf(temps,"%d:0%d",min,time);
else if(min<=9)
sprintf(temps,"0%d:%d",min,time);
else sprintf(temps,"%d:%d",min,time);
//sprintf(temps,"%d",time);
    txte.txt=TTF_RenderText_Blended(txte.police,temps, txte.color_txt);
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);  //coller la surface

}
/**
* @brief To update the objects
* @param image objects image
* @param camera ingame camera
* @param redimensionnement object resizing factor
* @param screen ingame screen
* @return Nothing
*/
void MAJobject(imagemelek imge,minimap * m, SDL_Rect camera, int redimensionnement,SDL_Surface *screen)
{SDL_Rect posobjetABS;
char temps[30];
   imagemelek img1;
posobjetABS.x = imge.pos_img_ecran.x*redimensionnement/100 + camera.x;
posobjetABS.y = imge.pos_img_ecran.y*redimensionnement/100 + camera.y;

posobjetABS.x=posobjetABS.x+m->pos_minimap_ecran.x;
posobjetABS.y=posobjetABS.y+m->pos_minimap_ecran.y;

sprintf(temps,"%sminimap.png",imge.url);
img1.url=temps;
   img1.img=IMG_Load(img1.url);

    img1.pos_img_ecran.x=posobjetABS.x;
    img1.pos_img_ecran.y=posobjetABS.y;
    (img1).pos_img_affiche.x=0;
    (img1).pos_img_affiche.y=0;
    (img1).pos_img_affiche.h=0;
    (img1).pos_img_affiche.w=0;

    SDL_BlitSurface(img1.img,NULL,screen,&img1.pos_img_ecran);

}


SDL_Color GetPixel(SDL_Surface *pSurface,position pos)
{
	SDL_Color color;
	Uint32 col=0;
	char* pPosition=(char*)pSurface->pixels;
	pPosition+=(pSurface->pitch*pos.y);
	pPosition+=(pSurface->format->BytesPerPixel*pos.x);
	memcpy(&col,pPosition,pSurface->format->BytesPerPixel);
	SDL_GetRGB(col,pSurface->format,&color.r,&color.g,&color.b);
return (color);
}
int collision_perfect(image *mask,SDL_Rect p, background b)
{
	SDL_Color object;
	int i,collision=0;
	SDL_Color poscolor;
	position pos[4];
	object.r=0;
	object.b=0;
	object.g=0;
	//1: top left
if (b.level==1)
{	
	pos[1].x=p.x+b.background_ocean.pos_img_affiche.x; 
	pos[1].y=p.y; 
	//:2 top middle
	pos[2].x=p.x+b.background_ocean.pos_img_affiche.x+22;
	pos[2].y=p.y;
	//3: top right
	pos[3].x=p.x+b.background_ocean.pos_img_affiche.x+45;
	pos[3].y=p.y;
}
else if(b.level==2)
{
	pos[1].x=p.x; 
	pos[1].y=p.y; 
	//:2 top middle
	pos[2].x=p.x+22;
	pos[2].y=p.y;
	//3: top right
	pos[3].x=p.x+45;
	pos[3].y=p.y;
}
	/*//4: middle left
	pos[4].x=p.x+b.background_ocean.pos_img_affiche.x;
	pos[4].y=p.y+(70/2)+5;
	//8: middle right
	pos[5].x=p.x+b.background_ocean.pos_img_affiche.x+45;
	pos[5].y=p.y+(70/2)+5;*/
	//5: bottom left
	//pos[5].x=p.x;
	//pos[5].y=p.y+70;
	//6: bottom
	//pos[6].x=p.x+45/2;
	//pos[6].y=p.y+70;
	//7: bottom right
	//pos[7].x=p.x+45;
	//pos[7].y=p.y+70;
	
	for (i=1;i<4 && collision==0;i++)
	{
	    poscolor=GetPixel(mask->img,pos[i]);
	    if (poscolor.r==object.r && poscolor.g==object.g && poscolor.b==object.b)
		collision=i;
	}
return collision;
}
int collision_ground(image *mask,SDL_Rect p, background b)
{
	int a; 
	SDL_Color object;
	int i,collision=0;
	SDL_Color poscolor;
	position pos[4];
	object.r=0;
	object.b=0;
	object.g=0;
	
	//6: bottom
if (b.level==1)
{
	pos[1].x=p.x+b.background_ocean.pos_img_affiche.x+22;
	pos[1].y=p.y+70;
	//5: bottom left
	pos[2].x=p.x+b.background_ocean.pos_img_affiche.x+5;
	pos[2].y=p.y+70;
	//7: bottom right
	pos[3].x=p.x+b.background_ocean.pos_img_affiche.x+45-5;
	pos[3].y=p.y+70;
}
else if (b.level==2)
{
	pos[1].x=p.x+22;
	pos[1].y=p.y+70;
	//5: bottom left
	pos[2].x=p.x+5;
	pos[2].y=p.y+70;
	//7: bottom right
	pos[3].x=p.x+45-5;
	pos[3].y=p.y+70;
}
	/*printf("%d\n", a);
	printf("poscolor.r %d\n", poscolor.r);
	printf("poscolor.g %d\n", poscolor.g);
	printf("poscolor.b %d\n", poscolor.b);
	printf("object.r %d\n", object.r);
	printf("object.g %d\n", object.g);
	printf("object.b %d\n", object.b);
	printf("*******\n mask.pos_img_affiche %d \n",mask->pos_img_affiche.x); */
	for (i=1;i<4 && collision==0;i++)
	{
	    poscolor=GetPixel(mask->img,pos[i]);
	    if (poscolor.r==object.r && poscolor.g==object.g && poscolor.b==object.b)
		collision=1;
	}
return collision;
}
int collision_wall(image *mask,SDL_Rect p, background b)
{
	int a; 
	SDL_Color object;
	int i,collision=0;
	SDL_Color poscolor;
	position pos[3];
	object.r=0;
	object.b=0;
	object.g=0;
	
	//4: middle left
if (b.level==1)
{
	pos[1].x=p.x+b.background_ocean.pos_img_affiche.x;
	pos[1].y=p.y+(70/2)+5;
	//8: middle right
	pos[2].x=p.x+b.background_ocean.pos_img_affiche.x+45;
	pos[2].y=p.y+(70/2)+5;
}
else if (b.level==2)
{
	pos[1].x=p.x;
	pos[1].y=p.y+(70/2)+5;
	//8: middle right
	pos[2].x=p.x+45;
	pos[2].y=p.y+(70/2)+5;
}
	/*printf("%d\n", a);
	printf("poscolor.r %d\n", poscolor.r);
	printf("poscolor.g %d\n", poscolor.g);
	printf("poscolor.b %d\n", poscolor.b);
	printf("object.r %d\n", object.r);
	printf("object.g %d\n", object.g);
	printf("object.b %d\n", object.b);
	printf("*******\n mask.pos_img_affiche %d \n",mask->pos_img_affiche.x); */
	for (i=1;i<3 && collision==0;i++)
	{
	    poscolor=GetPixel(mask->img,pos[i]);
	    if (poscolor.r==object.r && poscolor.g==object.g && poscolor.b==object.b)
		collision=i;
	}
return collision;
}
int collision_ladder(image *mask,SDL_Rect p, background b)
{
	int a; 
	SDL_Color object;
	int i,collision=0;
	SDL_Color poscolor;
	position pos;
	object.r=207;
	object.b=94;
	object.g=128;
	/*//1: top left
	pos[1].x=p.x+b.background_ocean.pos_img_affiche.x; 
	pos[1].y=p.y; 
	//:2 top middle
	pos[2].x=p.x+b.background_ocean.pos_img_affiche.x+22;
	pos[2].y=p.y;
	//3: top right
	pos[3].x=p.x+b.background_ocean.pos_img_affiche.x+45;
	pos[3].y=p.y;*/
	//6: bottom
if (b.level==1)
{
	pos.x=p.x+b.background_ocean.pos_img_affiche.x+22;
	pos.y=p.y+70;
}
else if (b.level==2)
{
	pos.x=p.x+22;
	pos.y=p.y+70;
}
	//5: bottom left
	/*pos[2].x=p.x+b.background_ocean.pos_img_affiche.x+5;
	pos[2].y=p.y+70;
	//7: bottom right
	pos[3].x=p.x+b.background_ocean.pos_img_affiche.x+45-5;
	pos[3].y=p.y+70;*/

	/*printf("%d\n", a);
	printf("poscolor.r %d\n", poscolor.r);
	printf("poscolor.g %d\n", poscolor.g);
	printf("poscolor.b %d\n", poscolor.b);
	printf("object.r %d\n", object.r);
	printf("object.g %d\n", object.g);
	printf("object.b %d\n", object.b);
	printf("*******\n mask.pos_img_affiche %d \n",mask->pos_img_affiche.x); */
	for (i=1;i<4 && collision==0;i++)
	{
	    poscolor=GetPixel(mask->img,pos);
	    if (poscolor.r==object.r && poscolor.g==object.g && poscolor.b==object.b)
		collision=1;
	}
return collision;
}	

int collision_lava(image *mask,SDL_Rect p, background b)
{
	int a; 
	SDL_Color object;
	int i,collision=0;
	SDL_Color poscolor;
	position pos;
	object.r=255;
	object.b=0;
	object.g=0;
	/*//1: top left
	pos[1].x=p.x+b.background_ocean.pos_img_affiche.x; 
	pos[1].y=p.y; 
	//:2 top middle
	pos[2].x=p.x+b.background_ocean.pos_img_affiche.x+22;
	pos[2].y=p.y;
	//3: top right
	pos[3].x=p.x+b.background_ocean.pos_img_affiche.x+45;
	pos[3].y=p.y;*/
	//6: bottom
if (b.level==1)
{	
	pos.x=p.x+b.background_ocean.pos_img_affiche.x+22;
	pos.y=p.y+60;
}
else if (b.level==2)
{
	pos.x=p.x+22;
	pos.y=p.y+60;
}
	//5: bottom left
	/*pos[2].x=p.x+b.background_ocean.pos_img_affiche.x+5;
	pos[2].y=p.y+70;
	//7: bottom right
	pos[3].x=p.x+b.background_ocean.pos_img_affiche.x+45-5;
	pos[3].y=p.y+70;*/

	/*printf("%d\n", a);
	printf("poscolor.r %d\n", poscolor.r);
	printf("poscolor.g %d\n", poscolor.g);
	printf("poscolor.b %d\n", poscolor.b);
	printf("object.r %d\n", object.r);
	printf("object.g %d\n", object.g);
	printf("object.b %d\n", object.b);
	printf("*******\n mask.pos_img_affiche %d \n",mask->pos_img_affiche.x); */
	for (i=1;i<4 && collision==0;i++)
	{
	    poscolor=GetPixel(mask->img,pos);
	    if (poscolor.r==object.r && poscolor.g==object.g && poscolor.b==object.b)
		collision=1;
	}
return collision;
}

int collision_maze_up(image *mask,SDL_Rect p)
{
    SDL_Color object;
    int collision=0;
    SDL_Color poscolor;
    position pos;
    object.r=0;
    object.b=0;
    object.g=0;
    //1: lfouk
    pos.x=p.x+(21/2); 
    pos.y=p.y; 
    
    
   poscolor=GetPixel(mask->img,pos);
        if (poscolor.r==object.r && poscolor.g==object.g && poscolor.b==object.b)
        collision=1;

return collision;
}

int collision_maze_left(image *mask,SDL_Rect p)
{
    SDL_Color object;
    int collision=0;
    SDL_Color poscolor;
    position pos;
    object.r=0;
    object.b=0;
    object.g=0;
    //:2 ysar
    pos.x=p.x;
    pos.y=p.y+(26/2);
        poscolor=GetPixel(mask->img,pos);
        if (poscolor.r==object.r && poscolor.g==object.g && poscolor.b==object.b)
        collision=1;

return collision;
}

int collision_maze_down(image *mask,SDL_Rect p)
{
    SDL_Color object;
    int collision=0;
    SDL_Color poscolor;
    position pos;
    object.r=0;
    object.b=0;
    object.g=0;
    //3: louta
    pos.x=p.x+(21/2);
    pos.y=p.y+40;
    
    poscolor=GetPixel(mask->img,pos);
    if (poscolor.r==object.r && poscolor.g==object.g && poscolor.b==object.b)
        collision=1;
    
return collision;
}

int collision_maze_right(image *mask,SDL_Rect p)
{
    SDL_Color object;
    int collision=0;
    SDL_Color poscolor;
    position pos;
    object.r=0;
    object.b=0;
    object.g=0;
    //4: ymin
    pos.x=p.x+40;
    pos.y=p.y+(26/2);
    poscolor=GetPixel(mask->img,pos);
    if (poscolor.r==object.r && poscolor.g==object.g && poscolor.b==object.b)
        collision=1;
    
return collision;
}

