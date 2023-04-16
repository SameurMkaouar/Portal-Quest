#include "ennemi.h"


void initEnnemi(Ennemi *e) {
    e->sprite=IMG_Load("images/enemie.png");
    e->pos.y=600;
    e->pos.x=600;
    
    e->direction=0;
    e->pos_sp.x=0;
    e->pos_sp.y=0;
    e->pos_sp.h=100;
    e->pos_sp.w=100;
    e->collisionSound = Mix_LoadWAV("audio/collision.wav");
    e->vie=0;
    e->vitesse=1;
    e->pos_max=600;
    e->pos_min=300;
}



void afficherEnnemi(Ennemi e, SDL_Surface * screen){
    SDL_BlitSurface(e.sprite , &e.pos_sp , screen , &e.pos) ;  
}

void animerEnnemi( Ennemi * e)
{
    e->pos_sp.x += 100; // += e->pos_sp.w
    if (e->pos_sp.x==400)
    {
        e->pos_sp.x=0;
    }
    e->pos_sp.y = e->direction * 100 ; //   e->pos_sp.y = e->direction * e->pos_sp.h
    SDL_Delay(e->vitesse);
}

void deplacer( Ennemi * e)
{

    if (e->direction==0)
    {
        e->pos.x += e->vitesse;
    }
    else if (e->direction==1)
    {
        e->pos.x -= e->vitesse;
    }



    if (e->pos.x < e->pos_min)
    {
        e->direction = 0;
    }
    if (e->pos.x > e->pos_max)
    {
        e->direction = 1;
    }
    
 
    
}

int collision(SDL_Rect E, SDL_Rect p)
{

  int collision;

  if (((p.x + 60) < E.x) || (p.x > (E.x + E.w)) || ((p.y + 90) < E.y) || (p.y > (E.y + E.h))) 
  {
    collision = 0;
  }
   else 
  {
    collision = 1;
  }

  return collision;
}


