/**
* @file ennemi.c
* @brief enemy file
* @author Roua 
* @version 3.2
* @date May 03, 2023
*
* Ici figure le fichier ennemi.c dans lequel on a le traitement des entitées secondaires :)
*
*/

#include "ennemi.h"

/**
* @brief To initialize the enemy
* @param e enemy entity
* @return Nothing
*/
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

/**
* @brief To show the enemy
* @param e enemy entity
* @param screen ingame screen
* @return Nothing
*/

void afficherEnnemi(Ennemi e, SDL_Surface * screen){
    SDL_BlitSurface(e.sprite , &e.pos_sp , screen , &e.pos) ;  
}
/**
* @brief To animate the enemy
* @param e enemy entity
* @return Nothing
*/
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
/**
* @brief To move the enemy
* @param e enemy entity
* @return Nothing
*/
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
/**
* @brief To detect collison the enemy
* @param e enemy's position
* @param p player's position
* @return 1 if collision else 0
*/
int collision(SDL_Rect E, SDL_Rect p)
{

  int collision;

  if (((p.x + 25 ) < E.x) || ((p.x-20) > (E.x + 20)) || ((p.y + 90) < E.y) || (p.y > (E.y + 60))) 
  {
    collision = 0;
  }
   else 
  {
    collision = 1;
  }

  return collision;
}
int collision_horizontal(SDL_Rect E, SDL_Rect p)
{

  int collision;

  if (((p.x + 40) < E.x) || ((p.x-20) > (E.x + 60)) || ((p.y + 90) < E.y) || (p.y > (E.y + 35-20))) 
  {
    collision = 0;
  }
   else 
  {
    collision = 1;
  }

  return collision;
}
/**
* @brief To detect collision with other entities (objects)
* @param e object position
* @param p player position
* @return 1 if collision else 0
*/
int collision_item(SDL_Rect E, SDL_Rect p)
{

  int collision;

  if (((p.x + 40) < E.x) || ((p.x-20) > (E.x + 40)) || ((p.y + 90) < E.y) || (p.y > (E.y + 45))) 
  {
    collision = 0;
  }
   else 
  {
    collision = 1;
  }

  return collision;
}
int collision_shade(SDL_Rect E, SDL_Rect p)
{

  int collision;

  if (((p.x + 36) < E.x) || ((p.x-36) > (E.x + 36)) || ((p.y + 45) < E.y) || (p.y > (E.y + 45))) 
  {
    collision = 0;
  }
   else 
  {
    collision = 1;
  }

  return collision;
}
