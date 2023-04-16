#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "audio.h"
#include "image.h"
#include "text.h"
#include "hero.h"
#include "background.h"
#include "minimap.h"
#include "ennemi.h"



int main()
{

//declaration des variables
SDL_Surface *screen, *coordinates;
int screen_h=800, screen_w=1450; 
image_background menu_background; 
image_bouton bouton; 
image image_leaderboard;
Mix_Music *animation_music, *music, *options_music, *play_music, *credits_music; // a changer en enregistrement
Mix_Chunk *mus,*longmus, *blank, *hurt;
texte txte_volume_music, txte_volume_chunk,txte_fullscreen, txte_windowed; // a chnager en enregistrement

int volume_music=64, volume_chunk=32;
int grace = 0;
SDL_Event event;
int boucle=1, boucle_animation=1, boucle_options,boucle_play;
int delay=45;
animation frog;
int fleche=0;
int longmus_play=0, longmus_options=0, longmus_credits=0, longmus_quit=0;
int pos=0, posbeforeshelly=0;
int displaymode_counter=0;
bool changement_display=true, changement_volume=false;
int shelly=0;
int cpt_mus=1;
Uint32 dx;
//////
    minimap m;
    background b;
    int redimensionnement=20;
    textemelek txte;
    personne p;
    int nowtime,last;
    Uint32 dt=1, t_prev;
    scoreInfo s;
    scoreInfo tab_score[10];
    char score_str[45];
    char score_str1[45];
    char score_str2[45];
    texte rank1, rank2, rank3;
    int cpt=0, salut;
    Uint32 now, before = 0, mob=0, cpt2=0;
//////
     Ennemi E;
     int interface;
     int input;
     Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
//////

//initialisation de la SDL
if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)==-1)
{
	printf("could not initialize SDL : %s. \n",SDL_GetError());
	return -1;
}

//reglage de la fenetre
screen=SDL_SetVideoMode(screen_w,screen_h,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
//boucle animation
initialiser_image_background(&(menu_background).loading1, screen_h, screen_w, "images/loading1.png");
initialiser_image_background(&(menu_background).loading2, screen_h, screen_w, "images/loading2.png");
initialiser_image_background(&(menu_background).loading3, screen_h, screen_w, "images/loading3.png");
initialiser_animation_frog(&frog,screen_h,screen_w,&(menu_background).loading1,&(menu_background).loading2,&(menu_background).loading3, screen);
initialiser_audio_animation(animation_music,volume_music);
SDL_EventState(SDL_MOUSEMOTION,SDL_DISABLE);
do{
 afficher_imageBMP(screen,frog.frame3); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame4); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame5); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame6); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame7); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame8); SDL_Flip(screen); SDL_Delay(delay);
  SDL_PollEvent(&event); if (event.type==SDL_KEYDOWN) break;
 afficher_imageBMP(screen,frog.frame9); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame10); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame11); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame12); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame13); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame14); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame15); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame16); SDL_Flip(screen); SDL_Delay(delay);
  SDL_PollEvent(&event); if (event.type==SDL_KEYDOWN) break;
 afficher_imageBMP(screen,frog.frame17); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame18); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame19); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame20); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame21); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame22); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame23); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame24); SDL_Flip(screen); SDL_Delay(delay);
  SDL_PollEvent(&event); if (event.type==SDL_KEYDOWN) break;
 afficher_imageBMP(screen,frog.frame25); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame26); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame27); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame28); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame29); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame30); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame31); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame32); SDL_Flip(screen); SDL_Delay(delay);
 afficher_imageBMP(screen,frog.frame33); SDL_Flip(screen); SDL_Delay(delay);
 SDL_PollEvent(&event);
}while(event.type!=SDL_KEYDOWN);
SDL_EventState(SDL_MOUSEMOTION,SDL_ENABLE);
 
//boucle du MENU
b.i=0;
while (boucle==1)
{ 
 if (changement_display){ 
 initialiser_image_background_finale(&menu_background, screen_h, screen_w);
 //CLICKED
 initialiser_image_bouton(&bouton.clicked_play,785, 268 ,"images/clicked_play_button.png"); 
 initialiser_image_bouton(&bouton.clicked_options,707, 394 ,"images/clicked_options_button.png");
 initialiser_image_bouton(&bouton.clicked_credits,696, 522 ,"images/clicked_credits_button.png");
 initialiser_image_bouton(&bouton.clicked_quit,798, 650 ,"images/clicked_quit_button.png");
 initialiser_image_bouton(&bouton.clicked_back,50, 50 ,"images/clicked_quit_button.png");
 initialiser_image_bouton(&bouton.clicked_right_arrow, screen_w/2+300, 560 ,"images/clicked_right_arrow.png");
 initialiser_image_bouton(&bouton.clicked_left_arrow, screen_w/2-400, 560 ,"images/clicked_left_arrow.png");
 //Unclicked 
 //initialiser_image_bouton(&bouton.unclicked_play,50, screen_h-600 ,"images/unclicked_play_button.png");
 //initialiser_image_bouton(&bouton.unclicked_options,50, screen_h-450 ,"images/unclicked_options_button.png");
 //initialiser_image_bouton(&bouton.unclicked_credits,50, screen_h-300 ,"images/unclicked_credits_button.png");
 //initialiser_image_bouton(&bouton.unclicked_quit,50, screen_h-150 ,"images/unclicked_quit_button.png");
 initialiser_image_bouton(&bouton.unclicked_back,50, 50 ,"images/unclicked_quit_button.png");
 initialiser_image_bouton(&bouton.unclicked_right_arrow, screen_w/2+300, 560 ,"images/unclicked_right_arrow.png");
 initialiser_image_bouton(&bouton.unclicked_left_arrow, screen_w/2-400, 560 ,"images/unclicked_left_arrow.png");
 //image
 initialiser_image_bouton(&bouton.black_70opacity, screen_w/2-300, 0 ,"images/black_70opacity.png");
 initialiser_image_bouton(&bouton.options_title, screen_w/2-200, 75 ,"images/options_title.png");
 initialiser_image_bouton(&bouton.groupnames, screen_w/2-200, screen_h ,"images/groupnames.png");
 initialiser_image_bouton(&bouton.slider_music, 2*screen_w/3-300, 235,"images/slider.png");
 initialiser_image_bouton(&bouton.slider_button_music, (2*screen_w/3-300)+3*volume_music-50, 265,"images/slider_button.png");
 initialiser_image_bouton(&bouton.slider_chunk, 2*screen_w/3-300, 385 ,"images/slider.png");
 initialiser_image_bouton(&bouton.slider_button_chunk,(2*screen_w/3-300)+3*volume_chunk-50, 415 ,"images/slider_button.png");
 initialiser_image_bouton(&bouton.displaymode_box, screen_w/2-295, 535 ,"images/displaymode_box.png");
//Music
 initialiser_audio_mainmenu(music,volume_music);
 Mix_Volume(5,volume_chunk);
//texte
 initialiser_texte(&txte_volume_music, screen_w/2-450,235);
 initialiser_texte(&txte_volume_chunk, screen_w/2-450,385);
 initialiser_texte(&txte_fullscreen, screen_w/2-240,545);
 initialiser_texte(&txte_windowed, screen_w/2-240,545);
 changement_display=!(changement_display);
}
 initialiser_image_leaderboard(&image_leaderboard, 357,140, "images/leaderboard.png");
 if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_DOWN)
	{ fleche++; SDL_Delay(150);}
 if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_UP )
	{fleche--; SDL_Delay(150);}
 if (fleche<0) fleche=fleche+5;
 fleche=fleche%5;

 if (screen_h==800) afficher_imageBMP(screen,menu_background.mainmenu); //pour afficher l'image du background
 else if (screen_h==1080) afficher_imageBMP(screen,menu_background.mainmenu_fullscreen);
 if((event.motion.y<=268+81 && event.motion.y>=268 && event.motion.x<=838+207&& event.motion.x>=838) ||fleche==1)
 {
  if(longmus_play==0) {initialiser_long_audiobref(longmus,volume_chunk); longmus_play=1;}
  afficher_imageBTN(screen,bouton.clicked_play); //afficher le bouton play clické

 }
/* else 
  {afficher_imageBTN(screen,bouton.unclicked_play); if(longmus_play==1) initialiser_blank(blank); longmus_play=0;}*/ //afficher le bouton play non clické
 if((event.motion.y<=394+83 && event.motion.y>=394 && event.motion.x<=753+381 && event.motion.x>=753) || fleche==2)
 {
  if(longmus_options==0){initialiser_long_audiobref(longmus,volume_chunk); longmus_options=1;}
  afficher_imageBTN(screen,bouton.clicked_options); //afficher le bouton options  clické

 }
 /*else 
  {afficher_imageBTN(screen,bouton.unclicked_options);if(longmus_options==1)initialiser_blank(blank); longmus_options=0;}*/ //afficher le bouton options non clické
 if((event.motion.y<=507+83 && event.motion.y>=507 && event.motion.x<=743+397 && event.motion.x>=743) || fleche==3)
 {
  if(longmus_credits==0){initialiser_long_audiobref(longmus,volume_chunk);longmus_credits=1;}
  afficher_imageBTN(screen,bouton.clicked_credits); //afficher le button credits clické

 }
  /*else 
  {afficher_imageBTN(screen,bouton.unclicked_credits);if(longmus_credits==1)initialiser_blank(blank); longmus_credits=0;}*/ //afficher le bouton credits non clické        
 if((event.motion.y<=650+83 && event.motion.y>=650 && event.motion.x<=847+192 && event.motion.x>=847) || fleche==4)
 {
  if(longmus_quit==0){initialiser_long_audiobref(longmus,volume_chunk);longmus_quit=1;}
  afficher_imageBTN(screen,bouton.clicked_quit);//afficher le bouton quit clické
    
 }
 //else 
  //{afficher_imageBTN(screen,bouton.unclicked_quit);if(longmus_quit==1)initialiser_blank(blank); longmus_quit=0;} //afficher le bouton quit non clické
 SDL_Flip(screen);	
 while(SDL_PollEvent(&event))
{
//*******************************TAP "i" TO KNOW THE COORDINATES OF THE MOUSE CURSOR******************************
 if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_i) 
 {
  while (SDL_WaitEvent(&event))
  {
   if (event.type==SDL_MOUSEMOTION)
    {	
      printf("x: %d,y: %d\n",event.motion.x,event.motion.y);
      break;
    }
  }
 }
//***********************************************ICI QUIT*********************************************************
 else if ((event.type==SDL_QUIT) || (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_q) || ((event.type==SDL_MOUSEBUTTONDOWN) && ( event.button.button==SDL_BUTTON_LEFT && event.motion.y<=650+83 && event.motion.y>=650 && event.motion.x<=847+192 && event.motion.x>=847))||  (fleche==4 && event.type==SDL_KEYDOWN && (event.key.keysym.sym==SDLK_RETURN || event.key.keysym.sym==SDLK_KP_ENTER)))
 {
  boucle=0;
  break;
 }
//************************************************ICI PLAY*********************************************************
else if((event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_p) || (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && event.motion.y<=268+81 && event.motion.y>=268 && event.motion.x<=838+207&& event.motion.x>=838) ||  (fleche==1 && event.type==SDL_KEYDOWN && (event.key.keysym.sym==SDLK_RETURN || event.key.keysym.sym==SDLK_KP_ENTER)))
 {
  boucle_play=1;//ON EST DANS PLAY			
  initialiser_audiobref(mus);
   s.score=0;
   strcpy(s.playerName,"player");
   s.time=0;
// Set scaling mode

  /*if (screen_h==800) afficher_imageBMP(screen,menu_background.play);
  else if (screen_h==1080) afficher_imageBMP(screen,menu_background.play)*/
////////////////************************************************************************debut msayeb
b.fullscreen=0;
    b.level=1;
    
    
//
  audio_level1(b.level2_music,0, cpt_mus);
  afficher_imageBMP(screen,frog.frame34); SDL_Flip(screen); SDL_Delay(delay); afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame35); SDL_Flip(screen); SDL_Delay(delay);  afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame36); SDL_Flip(screen); SDL_Delay(delay);  afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame37); SDL_Flip(screen); SDL_Delay(delay);  afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame38); SDL_Flip(screen); SDL_Delay(delay); afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame39); SDL_Flip(screen); SDL_Delay(delay);  afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame40); SDL_Flip(screen); SDL_Delay(delay);  afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame41); SDL_Flip(screen); SDL_Delay(delay); afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame42); SDL_Flip(screen); SDL_Delay(delay);  afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame43); SDL_Flip(screen); SDL_Delay(delay);
    initBack(&b);
    initPerso(&p);
    initialiser_texte_temps(&txte);
    initialiser_texte_leaderboard(&rank1, 440, 420);
    initialiser_texte_leaderboard(&rank2, 440, 480);
    initialiser_texte_leaderboard(&rank3, 440, 535);
    initEnnemi(&E);
  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame43); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame42); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame41); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame40); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame39); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame38); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame37); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame36); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame35); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame34); SDL_Flip(screen); SDL_Delay(delay);
//
    afficherBack(b,screen);
    afficherPerso(p,screen);
    audio_level1(b.level1_music,volume_music, cpt_mus);
    MAJMinimap(p,&m,b.camera,redimensionnement);
    afficher (m,screen);
    SDL_EnableKeyRepeat(25,5);
    SDL_EventState(SDL_MOUSEMOTION,SDL_DISABLE);//**A REMOVER** SI POSSIBLE
    SDL_Flip(screen);
///////////////********************************************************************************fin msayeb
  
  last=SDL_GetTicks();
  while(boucle_play)
  {
	grace++;
	deplacer(&E);
        animerEnnemi(&E);
        afficherEnnemi(E, screen);
	if (collision(E.pos, p.image_perso.pos_img_ecran)) 
        {
            
		if(grace>50) {p.nb_vies--; grace=0; Mix_PlayChannel(-1, E.collisionSound, 0);printf("collision\n");} 
	    
        }
	SDL_Flip(screen);
   if(event.motion.y<=150 && event.motion.y>=50 && event.motion.x<=305 && event.motion.x>=50)
   {
    afficher_imageBTN(screen,bouton.clicked_back);
   }
   else afficher_imageBTN(screen,bouton.unclicked_back);
   nowtime=SDL_GetTicks();
        nowtime-=last;
        mob=(SDL_GetTicks())%250;
	if (mob>230) mob=0;
        if (mob==0)
        {
            animerBack(&b);(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;(b.tab_frames[b.i+1]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;}
            afficherBack(b,screen);
            afficherPerso(p,screen);
            	deplacer(&E);
        animerEnnemi(&E);
        afficherEnnemi(E, screen);
cpt2++;
	if (cpt2>8) cpt2=0; printf("%d\n", cpt2);
	if (cpt2==0) animerPerso(&p); 
	    MAJMinimap(p,&m,b.camera,redimensionnement);
            afficher (m,screen);
            afficher_texte_temps(screen,txte,nowtime);
	deplacer(&E);
        animerEnnemi(&E);
        afficherEnnemi(E, screen);
            SDL_Flip(screen);
   while(SDL_PollEvent(&event))
    {
 	if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_m)
	{
		
		cpt_mus++;
		if (cpt_mus==4) cpt_mus=1;
		audio_level1(b.level1_music,volume_music, cpt_mus);
	}
grace++;
		if (collision(E.pos, p.image_perso.pos_img_ecran)) 
        {
            
		if(grace>50) {p.nb_vies--; grace=0; Mix_PlayChannel(-1, E.collisionSound, 0);printf("collision\n");} 
        }
        pos=b.camera.x+p.image_perso.pos_img_ecran.x;
	if (pos>6755 && pos<6855 && shelly==0)
 {SDL_EventState(SDL_MOUSEMOTION,SDL_DISABLE);
shelly=1;
 posbeforeshelly=pos;
audio_level1(b.level2_music,0, cpt_mus);
 afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame34); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame35); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame36); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame37); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame38); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame39); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame40); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame41); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame42); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame43); SDL_Flip(screen); SDL_Delay(delay);
  SDL_Delay(550);b.level=2;
  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame43); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame42); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame41); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame40); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame39); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame38); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame37); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame36); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame35); SDL_Flip(screen); SDL_Delay(delay);  afficherBack(b,screen);
  afficher_imageBMP(screen,frog.frame34); SDL_Flip(screen); SDL_Delay(delay);
  p.image_perso.pos_img_ecran.x=1300;
  p.image_perso.pos_img_ecran.y=80; 
  audio_level2(b.level2_music,volume_music);
} 
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_n && shelly==1) 
{
b.level=1;
shelly=0;
p.image_perso.pos_img_ecran.x=600;
p.image_perso.pos_img_ecran.y=695; 
audio_level1(b.level1_music,volume_music, cpt_mus);
}
nowtime=SDL_GetTicks();nowtime-=last;(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
            t_prev=SDL_GetTicks(); //au début de la boucle de jeu
            b.acceleration=p.acceleration;
            b.vitesse=p.vitesse;
     if((event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=150 && event.motion.y>=50 && event.motion.x<=305 && event.motion.x>=50)) || (SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE))
     {
      initialiser_audiobref(mus);
      fleche=0;
      boucle_play=0;//quitter play
      initialiser_audio_mainmenu(music,volume_music);
      break;
     } 
     else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_d /*&& p.image_perso.pos_img_ecran.x<1300*/)//MOVE RIGHT 
            {   p.direction=1;
                cpt++;


                if (p.image_perso.pos_img_ecran.x<650) {movePerso(&p,dt); (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;}//(b.tab_frames[b.i+1]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;}(b.tab_frames[b.i+2]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;}
                else if(b.camera.x<6510) {scrolling(&b,p.direction,dt);//15467
	
	dx=0.5*(b.acceleration)*dt*dt + (b.vitesse)*dt ;
	if (p.direction ==1) { (E.pos.x)-=dx; }
	else if (p.direction == -1) {(E.pos.x)+=dx; }}
                else {movePerso(&p,dt);(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;}//(b.tab_frames[b.i+1]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;(b.tab_frames[b.i+2]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;}

                if(cpt==10)
                {
                    p.posSprite.x+=80;
                    if(p.posSprite.x==640) p.posSprite.x=0;
                    cpt=0;
                }

            }
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_q /*&& p.image_perso.pos_img_ecran.x>0*/)//MOVE LEFT //mouvementzebla
            {   p.direction=-1;
                cpt++;
	

                if (p.image_perso.pos_img_ecran.x<= 50 && b.camera.x>0) {scrolling(&b,p.direction,dt);dx=0.5*(b.acceleration)*dt*dt + (b.vitesse)*dt ;
	if (p.direction ==1) { (E.pos.x)-=dx; }
	else if (p.direction == -1) {(E.pos.x)+=dx; }}
                else if (p.image_perso.pos_img_ecran.x>0) {movePerso(&p,dt);(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;}//(b.tab_frames[b.i+1]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;(b.tab_frames[b.i+2]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;}

                if(cpt==10)
                {
                    p.posSprite.x+=80;
                    if(p.posSprite.x==640) p.posSprite.x=0;
                    cpt=0;
                }
            }
else if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_z) //mouvement zebla
	    {
//printf("%d\n", p.direction);
//printf("%d\n",p.image_perso.pos_img_ecran.y);
        

            while (p.image_perso.pos_img_ecran.y>550 && p.image_perso.pos_img_ecran.x>0 && p.image_perso.pos_img_ecran.x<1300)
              {(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;    afficher (m,screen);
       afficher_texte_temps(screen,txte,nowtime);
		if (collision(E.pos, p.image_perso.pos_img_ecran)) 
        		{
			if(grace>50) {p.nb_vies--; grace=0; Mix_PlayChannel(-1, E.collisionSound, 0);printf("collision\n");} 
        		}
		switch (p.direction)
		{
		case 0: saut(&p,dt); 
		break;
		case 1: saut(&p,dt);if (p.image_perso.pos_img_ecran.x<650) movePerso(&p,dt); 
                else if(b.camera.x<6510) scrolling(&b,p.direction,dt);
                else movePerso(&p,dt);
		//saut(&p,dt);
				//saut(&p,dt); movePerso(&p, dt);
		case -1: saut(&p,dt);if (p.image_perso.pos_img_ecran.x<= 50 && b.camera.x>0) scrolling(&b,p.direction,dt);
                else if (p.image_perso.pos_img_ecran.x>0) movePerso(&p,dt);	
		saut(&p,dt);	
		break;
		}
	    afficherBack(b,screen);
            animerPerso(&p);
            afficherPerso(p,screen);
            MAJMinimap(p,&m,b.camera,redimensionnement);
            afficher (m,screen);
        afficher_texte_temps(screen,txte,nowtime);
	deplacer(&E);
        animerEnnemi(&E);
        afficherEnnemi(E, screen);
	    SDL_Flip(screen);
	      }
	     }
while (p.image_perso.pos_img_ecran.y<690 && p.image_perso.pos_img_ecran.x>0 && p.image_perso.pos_img_ecran.x<1300)
	 	{switch (p.direction)
		{
		case 0: p.image_perso.pos_img_ecran.y+=15;
		break;

		case 1: p.image_perso.pos_img_ecran.y+=15;if (p.image_perso.pos_img_ecran.x<650) movePerso(&p,dt); 
                else if(b.camera.x<6510) scrolling(&b,p.direction,dt);
                else movePerso(&p,dt);
				//saut(&p,dt); movePerso(&p, dt);
		case -1: p.image_perso.pos_img_ecran.y+=15;if (p.image_perso.pos_img_ecran.x<= 50 && b.camera.x>0) {scrolling(&b,p.direction,dt); movePerso(&p,dt);}
                else if (p.image_perso.pos_img_ecran.x>0) movePerso(&p,dt);		
		break;
		}
	    afficherBack(b,screen);
            animerPerso(&p);
            afficherPerso(p,screen);
           MAJMinimap(p,&m,b.camera,redimensionnement);
            afficher (m,screen);
       afficher_texte_temps(screen,txte,nowtime);
	deplacer(&E);
        animerEnnemi(&E);
        afficherEnnemi(E, screen);
	    SDL_Flip(screen);
		}
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_h)
            {		
		p.score+=10;                
		p.nb_vies--;
		if(p.mana>1)p.mana--;
                SDL_Delay(100);
                if(p.nb_vies==-1) p.nb_vies=3;
		//if(p.mana==-1) p.mana=3;
            }
if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_l)
			{
			
			SDL_Delay(200);
			while(1){
			//A AJOUTER SCORE STP SVP***************
			bestScore("scores.txt",tab_score);
			afficher_imageBTN(screen,image_leaderboard);
			sprintf(score_str,"Name:%s | Score:%d | Time:%d",tab_score[0].playerName,tab_score[0].score,tab_score[0].time);
			afficher_texte_custom(screen,rank1,score_str);
			sprintf(score_str1,"Name:%s | Score:%d | Time:%d",tab_score[1].playerName,tab_score[1].score,tab_score[1].time);
			afficher_texte_custom(screen,rank2,score_str1);
			sprintf(score_str2,"Name:%s | Score:%d | Time:%d",tab_score[2].playerName,tab_score[2].score,tab_score[2].time);
			afficher_texte_custom(screen,rank3,score_str2);
			SDL_Flip(screen);
			SDL_WaitEvent(&event);
			if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_l) {SDL_Delay(100);  break;}
			
			}
		}

else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e && p.acceleration<0.1) p.acceleration+=0.075;//speed boost intensity a expliquer a la prof
            else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_a && p.acceleration>0 ) p.acceleration-=0.005;
now = SDL_GetTicks();
            if (now - before >=250)
            {//(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;//(b.tab_frames[b.i+1]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
                animerBack (&b);
                before = now; (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
            }
	afficherBack(b,screen);
        animerPerso(&p);
        afficherPerso(p,screen);
	MAJMinimap(p,&m,b.camera,redimensionnement);
        afficher (m,screen);
        afficher_texte_temps(screen,txte,nowtime);
	deplacer(&E);
        animerEnnemi(&E);
        afficherEnnemi(E, screen);
            SDL_Flip(screen);
            
            dt=SDL_GetTicks()-t_prev; //à la fin de la boucle de jeu
            //printf("%d\n", dt);
if(p.mana<3) {p.mana+=0.006; printf("mana_inside: %f\n",p.mana);}
if(p.acceleration > 0 ) p.acceleration-=0.003;
    }
    p.direction=0;
	if(p.mana<3){ p.mana+=0.003; printf("mana_outside: %f\n",p.mana); }
        if(p.acceleration > 0 ) p.acceleration-=0.000001;//speed boost duration
        afficher_texte_temps(screen,txte,nowtime);
    ///ici ajouter les trucs du jeu
     SDL_Flip(screen);
   }

SDL_EventState(SDL_MOUSEMOTION,SDL_ENABLE);//**A REMOVER** SI POSSIBLE
  }
//**********************************************ICI OPTIONS*******************************************************
 else if((event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_o) || ((event.type==SDL_MOUSEBUTTONDOWN) && (event.motion.y<=394+83 && event.motion.y>=394 && event.motion.x<=753+381 && event.motion.x>=753)) ||  (fleche==2 && event.type==SDL_KEYDOWN && (event.key.keysym.sym==SDLK_RETURN || event.key.keysym.sym==SDLK_KP_ENTER)))
 {
 initialiser_audiobref(mus);
 if (screen_h==800) afficher_imageBMP(screen,menu_background.options);
 else if (screen_h==1080) afficher_imageBMP(screen,menu_background.options_fullscreen);
 boucle_options=1;//ON EST DANS OPTIONS
 initialiser_audio_options(options_music,volume_music);
 afficher_imageBTN(screen,bouton.options_title);
 afficher_texte_volume_music(screen,txte_volume_music);
 afficher_texte_volume_chunk(screen,txte_volume_chunk);
 afficher_imageBTN(screen,bouton.slider_music);
 afficher_imageBTN(screen,bouton.slider_button_music);
 afficher_imageBTN(screen,bouton.slider_chunk);
 afficher_imageBTN(screen,bouton.slider_button_chunk);
 afficher_imageBTN(screen,bouton.displaymode_box);
 afficher_imageBTN(screen,bouton.unclicked_right_arrow);
 afficher_imageBTN(screen,bouton.unclicked_left_arrow);
 if (screen_h==800) afficher_texte_windowed(screen,txte_windowed);
 else if (screen_h==1080) afficher_texte_fullscreen(screen,txte_fullscreen);
 SDL_Flip(screen);
 while(boucle_options)
 {
  if(event.motion.y<=150 && event.motion.y>=50 &&(event.motion.x<=305 && event.motion.x>=50))
  {
  afficher_imageBTN(screen,bouton.clicked_back);
  }
  else afficher_imageBTN(screen,bouton.unclicked_back);
  if(event.motion.y<=615 && event.motion.y>=535 && event.motion.x<=screen_w/2+375 && event.motion.x>=screen_w/2+300)
  {
   afficher_imageBTN(screen,bouton.clicked_right_arrow);
  }
  else afficher_imageBTN(screen,bouton.unclicked_right_arrow);
if(event.motion.y<=615 && event.motion.y>=535 && event.motion.x<=screen_w/2-325 && event.motion.x>=screen_w/2-400)
  {
   afficher_imageBTN(screen,bouton.clicked_left_arrow);
  }
  else afficher_imageBTN(screen,bouton.unclicked_left_arrow);
  afficher_imageBTN(screen,bouton.displaymode_box);
  if (screen_h==800) afficher_texte_windowed(screen,txte_windowed);
  else if (screen_h==1080) afficher_texte_fullscreen(screen,txte_fullscreen);
  SDL_Flip(screen);
  while(SDL_PollEvent(&event))
  {
   if((event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE) || ((event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT) && (event.motion.y<=150 && event.motion.y>=50 && event.motion.x<=305 && event.motion.x>=50)))	
   {
    initialiser_audiobref(mus);
    fleche=0;
    boucle_options=0;//quitter options
    initialiser_audio_mainmenu(music,volume_music);
   }
//*********************************VOLUME**********************************
   if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && event.motion.y<=335 && event.motion.y>=235 && event.motion.x<=2*screen_w/3+62 && event.motion.x>=2*screen_w/3-295)
   { 
      volume_music=(event.motion.x-(2*screen_w/3-300))/3;
      initialiser_image_bouton(&bouton.slider_button_music, event.button.x-50, 265,"images/slider_button.png");
      changement_volume=!(changement_volume);
	              
   } 
   else if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && event.motion.y<=485 && event.motion.y>=385 && event.motion.x<=2*screen_w/3+62 && event.motion.x>=2*screen_w/3-295)
   {
      volume_chunk=(event.motion.x-(2*screen_w/3-300))/3; 
      initialiser_image_bouton(&bouton.slider_button_chunk, event.button.x-50, 415,"images/slider_button.png");
      changement_volume=!(changement_volume);		              
   } 
   if (changement_volume)
    {SDL_UpdateRect(screen, 0, 0, 0, 0);
    initialiser_audiobref(mus);
    if (screen_h==800) afficher_imageBMP(screen,menu_background.options);
    else if (screen_h==1080) afficher_imageBMP(screen,menu_background.options_fullscreen);
    afficher_imageBTN(screen,bouton.options_title);
    afficher_texte_volume_music(screen,txte_volume_music);
    afficher_texte_volume_chunk(screen,txte_volume_chunk);
    afficher_imageBTN(screen,bouton.slider_music);
    afficher_imageBTN(screen,bouton.slider_button_music);
    afficher_imageBTN(screen,bouton.slider_chunk);
    afficher_imageBTN(screen,bouton.slider_button_chunk);
    Mix_VolumeMusic(volume_music);
    Mix_Volume(5,volume_chunk);	
    changement_volume=!(changement_volume);
    s.time=nowtime;
    }
//********************************************FULL SCREEN*****************************************
   if ((event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_f) || ((event.type==SDL_MOUSEBUTTONDOWN  && event.button.button ==SDL_BUTTON_LEFT) && ((event.motion.y<=635 && event.motion.y>=535 && event.motion.x<=screen_w/2-325 && event.motion.x>=screen_w/2-400) || (event.motion.y<=635 && event.motion.y>=535 && event.motion.x<=screen_w/2+375 && event.motion.x>=screen_w/2+300))))
    {
    displaymode_counter++;
    changement_display=!(changement_display);
    if ((displaymode_counter%2)==1) 
    {
     screen_h=1080;
     screen_w=1920;
     screen=SDL_SetVideoMode(screen_w,screen_h,32,SDL_SWSURFACE|SDL_FULLSCREEN);
     boucle_options=0;
    }
    else 
    {
     screen_h=800;
     screen_w=1450;
     screen=SDL_SetVideoMode(screen_w,screen_h,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
     boucle_options=0;
    }
    break;
    }
   }
 }
}
//****************************ICI CREDITS********************************
else if((event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_c) || ((event.type==SDL_MOUSEBUTTONDOWN) && (event.motion.y<=507+83 && event.motion.y>=507 && event.motion.x<=743+397 && event.motion.x>=743))||  (fleche==3 && event.type==SDL_KEYDOWN && (event.key.keysym.sym==SDLK_RETURN || event.key.keysym.sym==SDLK_KP_ENTER)))
  {		
   initialiser_audiobref(mus);
   bouton.groupnames.pos_img_ecran.y=1080;
   if (screen_h==800) afficher_imageBMP(screen,menu_background.options);
   else if (screen_h==1080) afficher_imageBMP(screen,menu_background.options_fullscreen);
   initialiser_audio_credits(credits_music,volume_music);
   while(bouton.groupnames.pos_img_ecran.y>-460)
   {
   if (screen_h==800) afficher_imageBMP(screen,menu_background.options);
   else if (screen_h==1080) afficher_imageBMP(screen,menu_background.options_fullscreen);
   afficher_imageBTN(screen,bouton.black_70opacity);
   afficher_imageBTN(screen,bouton.groupnames);
   SDL_Flip(screen);
   bouton.groupnames.pos_img_ecran.y-=10;
   SDL_Delay(25);  
   fleche=0;
   }
  initialiser_audio_mainmenu(music,volume_music);
  }
}
} 
//saveScore(s,"scores.txt");
//Liberer les surfaces
liberer_animation(frog);
liberer_bouton(bouton);
liberer_background(menu_background);

//liberer les sons
//liberer_musiquebref(mus);

//liberer les textes
liberer_texte(txte_volume_music);
liberer_texte(txte_volume_chunk);
liberer_texte(txte_fullscreen);
liberer_texte(txte_windowed); 
return 0;
}
