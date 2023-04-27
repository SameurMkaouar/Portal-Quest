#include "hero.h"
#include "minimap.h"
#include "image.h"

void initPerso(personne *p)
{	

	p->image_perso.url="images/marioplayer.png";
	p->image_perso.img=IMG_Load(p->image_perso.url);
	if(p->image_perso.img == NULL)
	{
	    printf("unable to load character image %s \n",SDL_GetError());
	    return;
	}
        p->image_perso.pos_img_affiche.x=0;
        p->image_perso.pos_img_affiche.y=0;
        p->image_perso.pos_img_affiche.w=60;
        p->image_perso.pos_img_affiche.h=90;
        p->image_perso.pos_img_ecran.x=50;
        p->image_perso.pos_img_ecran.y=695;
	//nb vies
	p->nb_vies=3;
	//nb mana
	p->mana=3;
	//image vies
	p->image_vies.url="images/HeartsFinal.png";
	p->image_vies.img=IMG_Load(p->image_vies.url);
	if(p->image_vies.img == NULL)
	{
	    printf("unable to load hearts image %s \n",SDL_GetError());
	}
        p->image_vies.pos_img_affiche.x=0;
        p->image_vies.pos_img_affiche.y=0;//copier dans main et ajouter valeur +100
        p->image_vies.pos_img_affiche.w=240;
        p->image_vies.pos_img_affiche.h=68;//toujours height du coeur
        p->image_vies.pos_img_ecran.x=40;
        p->image_vies.pos_img_ecran.y=35;
	//image vies
	p->image_mana.url="images/ManaFinal.png";
	p->image_mana.img=IMG_Load(p->image_mana.url);
	if(p->image_mana.img == NULL)
	{
	    printf("unable to load hearts image %s \n",SDL_GetError());
	}
        p->image_mana.pos_img_affiche.x=0;
        p->image_mana.pos_img_affiche.y=0;//copier dans main et ajouter valeur +100
        p->image_mana.pos_img_affiche.w=240;
        p->image_mana.pos_img_affiche.h=68;//toujours height du coeur
        p->image_mana.pos_img_ecran.x=40;
        p->image_mana.pos_img_ecran.y=90;
	//score
	p->score=0;
	initialiser_texte_score(&p->score_text,700,30);//a changer position texte
	//mvt
	p->saut=0;
        p->vitesse=5;
	p->acceleration=0;
	//bool
	/*p->danger=false;
	p->diminution_score=false;
	p->diminution_nb_vies=false;*/
	p->direction=0;
	p->posScreen.x= 50;
	p->posScreen.y= 800;
        p->posSprite.x= 0;
	p->posSprite.y= 0;
	p->posSprite.w= 606/8;
	p->posSprite.h= 135/2;
	p->sprite=IMG_Load("images/spritefinal.png");
	//clock
	
	

}

void afficherPerso(personne p, SDL_Surface * screen)
{
	//perso
	if(p.direction !=0) SDL_BlitSurface(p.sprite,&p.posSprite,screen, &p.posScreen);
	else SDL_BlitSurface(p.image_perso.img,&p.image_perso.pos_img_affiche,screen, &p.image_perso.pos_img_ecran);
	//vies
	SDL_BlitSurface(p.image_vies.img,&p.image_vies.pos_img_affiche,screen, &p.image_vies.pos_img_ecran);
	//vies
	SDL_BlitSurface(p.image_mana.img,&p.image_mana.pos_img_affiche,screen, &p.image_mana.pos_img_ecran);
	//score
	char score_value_string[10];
	sprintf(score_value_string, "| %d", p.score);
    	p.score_text.txt=TTF_RenderText_Blended(p.score_text.police,score_value_string, p.score_text.color_txt); 
    	SDL_BlitSurface(p.score_text.txt, NULL, screen, &p.score_text.pos_txt);  //coller la surface
	//clock
	
	
}

void movePerso(personne *p,Uint32 dt)
{
 Uint32 dx;
 dx=0.5*(p->acceleration)*dt*dt + (p->vitesse)*dt ;
 if(p->direction==1)p->image_perso.pos_img_ecran.x+=dx;
 else if(p->direction==-1) p->image_perso.pos_img_ecran.x-=dx;
}

void animerPerso(personne *p)
{		
	switch(p->direction)
	{
	case 1:
				
		p->posSprite.y=0; p->image_perso.pos_img_affiche.x=0;
		break;
	case -1:
				
		p->posSprite.y=69; p->image_perso.pos_img_affiche.x=0;
		break;
	case 0:
		p->image_perso.pos_img_affiche.x+=60;
		if (p->image_perso.pos_img_affiche.x>1880) p->image_perso.pos_img_affiche.x=0;
		break;
	}
	p->posScreen.x= p->image_perso.pos_img_ecran.x;
	p->posScreen.y= p->image_perso.pos_img_ecran.y;
	switch(p->nb_vies)
	{
	case 3:
		p->image_vies.pos_img_affiche.y=0;
		break;
	case 2:
		p->image_vies.pos_img_affiche.y=68;
		break;
	case 1: 
		p->image_vies.pos_img_affiche.y=137;
		break;
	case 0:
		p->image_vies.pos_img_affiche.y=206;
		break;
	}
	if(p->mana>2.9) p->image_mana.pos_img_affiche.y=0;
	else if(p->mana>1.9) p->image_mana.pos_img_affiche.y=68;
	else if(p->mana>0.9) p->image_mana.pos_img_affiche.y=137;
	else p->image_mana.pos_img_affiche.y=206;
}
void saut(personne *p, Uint32 dt)
{
Uint32 dx;
dx=(p->acceleration)*dt*dt+(p->vitesse)*dt;
p->image_perso.pos_img_ecran.y-=dx;
}

