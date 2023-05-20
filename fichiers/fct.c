#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fct.h"
#include "image.h"
#include "text.h"

void initialiserTic (tic *t)
{

    int i ;
    t->back.url="images/tictactoe.png";
    t->back.img=IMG_Load(t->back.url);
    if(t->back.img==NULL)
    {
        printf("ERRORRRR :%s\n",SDL_GetError());
        return ;
    }
    t->back.pos_img_ecran.x=0;
    t->back.pos_img_ecran.y=0;
    t->back.pos_img_affiche.x=0;
    t->back.pos_img_affiche.y=0;
    t->back.pos_img_affiche.h=800;
    t->back.pos_img_affiche.w=1450;

//////////////////////////
    t->x.url="images/x.png";
    t->x.img=IMG_Load(t->x.url);
    if(t->x.img==NULL)
    {
        printf("ERRORRRR :%s\n",SDL_GetError());
        return ;
    }
    t->x.pos_img_ecran.x=0;
    t->x.pos_img_ecran.y=0;
    t->x.pos_img_affiche.x=0;
    t->x.pos_img_affiche.y=0;
    t->x.pos_img_affiche.h=800;
    t->x.pos_img_affiche.w=1450;

/////////////////////////////
    t->o.url="images/o.png";
    t->o.img=IMG_Load(t->o.url);
    if(t->o.img==NULL)
    {
        printf("ERRORRRR :%s\n",SDL_GetError());
        return ;
    }
    t->o.pos_img_ecran.x=0;
    t->o.pos_img_ecran.y=0;
    t->o.pos_img_affiche.x=0;
    t->o.pos_img_affiche.y=0;
    t->o.pos_img_affiche.h=800;
    t->o.pos_img_affiche.w=1450;

///////////////////


    for (i=0; i<9; i++)
    {
        t->tabsuivi[i]=0;
    }



////////////////////////
    t->pos_pre_case.x=382;
    t->pos_pre_case.y=210;
    t->joueur=1;
    t->tour=0;

///////////////////texte
    TTF_Init();
    t->txte.police=TTF_OpenFont("fonts/Ubuntu-B.ttf",60);
    t->txte.color_txt.r=0;
    t->txte.color_txt.g=0;
    t->txte.color_txt.b=0;
    t->txte.pos_txt.x=0;
    t->txte.pos_txt.y=68;
}




void afficherTic(tic t,SDL_Surface* ecran)
{
    int i, largecase=260, hautcase=210;
    SDL_BlitSurface(t.back.img,NULL,ecran,&t.back.pos_img_ecran);
         

    for (i=0; i<9; i++)
    {
        if (t.tabsuivi[i]==-1)
        {
            t.x.pos_img_ecran.x=t.pos_pre_case.x+(largecase*(i%3));
            t.x.pos_img_ecran.y=t.pos_pre_case.y+(hautcase*(i/3));   
		SDL_BlitSurface(t.x.img,NULL,ecran,&t.x.pos_img_ecran);

        }
        else if (t.tabsuivi[i]==1)
        {
            t.o.pos_img_ecran.x=t.pos_pre_case.x+(largecase*(i%3));
            t.o.pos_img_ecran.y=t.pos_pre_case.y+(hautcase*(i/3));
            SDL_BlitSurface(t.o.img,NULL,ecran,&t.o.pos_img_ecran);
        }

    }

}



int atilganer(int tabsuivi[])
{

 
    if ((tabsuivi[0]==tabsuivi[2])&&(tabsuivi[2]==tabsuivi[1])&&(tabsuivi[0]==tabsuivi[1]))
   {     return(tabsuivi[0]);
}
     if ((tabsuivi[3]==tabsuivi[4])&&(tabsuivi[3]==tabsuivi[5])&&(tabsuivi[4]==tabsuivi[5]))
        {return(tabsuivi[3]);
}
     if  ((tabsuivi[8]==tabsuivi[7])&&(tabsuivi[6]==tabsuivi[7])&&(tabsuivi[6]==tabsuivi[8]))
        return(tabsuivi[6]);

     if  ((tabsuivi[0]==tabsuivi[3])&&(tabsuivi[6]==tabsuivi[0])&&(tabsuivi[6]==tabsuivi[3]))
        return(tabsuivi[0]);

     if  ((tabsuivi[1]==tabsuivi[4])&&(tabsuivi[1]==tabsuivi[7])&&(tabsuivi[4]==tabsuivi[7]))
        return(tabsuivi[1]);

     if  ((tabsuivi[2]==tabsuivi[5])&&(tabsuivi[8]==tabsuivi[2])&&(tabsuivi[5]==tabsuivi[8]))
        return(tabsuivi[2]);

     if  ((tabsuivi[0]==tabsuivi[4])&&(tabsuivi[8]==tabsuivi[0])&&(tabsuivi[4]==tabsuivi[8]))
        return(tabsuivi[0]);

     if  ((tabsuivi[2]==tabsuivi[4])&&(tabsuivi[6]==tabsuivi[2])&&(tabsuivi[6]==tabsuivi[4]))
        return(tabsuivi[2]);
 
return 0;
}



int minmax(int tabsuivi[], int joueur)
{
    int gagnant=atilganer(tabsuivi);
    if (gagnant!=0)
        return (gagnant*joueur);

    int coup=-1;
    int score=-2;
    int i ;
    for (i=0; i<9; i++)
    {
        if (tabsuivi[i]==0)
        {
            tabsuivi[i]=joueur;
            int mmscore=minmax(tabsuivi,joueur*-1);
            if(mmscore>score)
            {
                score=mmscore;
                coup=i;
            }
            tabsuivi[i]=0;
        }
    }
    if(coup==-1)
        return(0);
    return (score);
}



void calcul_coup(int tabsuivi[])
{
    int coup=-1;
    int score=-2;
    int i ;
    for (i=0; i<9; i++)
    {
        if (tabsuivi[i]==0)
        {
            tabsuivi[i]=1;
            int mmscore=-minmax(tabsuivi,-1);
            tabsuivi[i]=0;
            if(mmscore>score)
            {
                score=mmscore;
                coup=i;
            }
        }
    }
    tabsuivi[coup]=1;
}




void Resultat (int tabsuivi[],SDL_Surface* ecran,tic t)
{
/*
int resultat = atilganer(tabsuivi);



  switch (resultat)
    {
    case 1:
	t.txte.txt=TTF_RenderText_Blended(t.txte.police,"Victoire de la machine !", t.txte.color_txt);
      
        break;
    case -1:
        t.txte.txt=TTF_RenderText_Blended(t.txte.police,"Victoire joueur !", t.txte.color_txt);

        break;
    default:
        t.txte.txt=TTF_RenderText_Blended(t.txte.police,"NULL", t.txte.color_txt);
        break;
    }
    SDL_BlitSurface(t.txte.txt, NULL, ecran, &t.txte.pos_txt);


*/

}




void liberer_tic( tic *t)

{
 //TTF_CloseFont(t->txte.police);
 //TTF_Quit();
   //SDL_FreeSurface(t->back.img);
 //SDL_FreeSurface(t->x.img);
    //SDL_FreeSurface(t->o.img);
}










