#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
#include "hero.h"
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
void afficher (minimap m, SDL_Surface * screen)
{
SDL_BlitSurface(m.img_minimap,NULL,screen,&m.pos_minimap_ecran);
SDL_BlitSurface(m.img_alan,NULL,screen,&m.pos_alan_ecran);
}
void Liberer (minimap * m)
{SDL_FreeSurface(m->img_alan);
SDL_FreeSurface(m->img_minimap);
}
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
//sprintf(temps,"%d",time);
    txte.txt=TTF_RenderText_Blended(txte.police,temps, txte.color_txt);
    SDL_BlitSurface(txte.txt, NULL, screen, &txte.pos_txt);  //coller la surface

}
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






