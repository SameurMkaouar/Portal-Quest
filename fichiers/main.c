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
#include "enigme.h"
#include <unistd.h>  
#include <fcntl.h>  
#include <errno.h>   
#include <termios.h>  
#include <sys/ioctl.h>
#include <stdint.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_gfxPrimitives.h> 
#include "serie.h"



int main()
{
 
 int fd = serialport_init("/dev/ttyUSB0", 9600);  
//declaration des variables
SDL_Surface *screen, *coordinates;
int screen_h=800, screen_w=1450, dte, is_saut=0, air, up; 
image_background menu_background; 
image_bouton bouton; 
image image_leaderboard, image_dust, image_clock;
Mix_Music *animation_music, *music, *options_music, *play_music, *credits_music; // a changer en enregistrement
Mix_Chunk *mus,*longmus, *blank, *hurt;
texte txte_volume_music, txte_volume_chunk,txte_fullscreen, txte_windowed; // a chnager en enregistrement

int volume_music=0, volume_chunk=0; //64 32
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
int shelly=0, dust_effect=0;
int cpt_mus=1;
Uint32 dx;
////////

int continuer = 1;
int win_condition=0,lose_condition=0;
int rando;
int rand_pris[10];
image carte[8];
image carte_alea[8];
SDL_Surface* comp;
int last_pos,kol;
SDL_Rect position[8],poss;
SDL_Rect randi[8];
enigme e,back;
int o,po,cont=0;


//////
    char buffer[100];                   // un buffer
    int manet;


    
//////
    minimap m;
    background b;
    int redimensionnement=20;
    textemelek txte;
    personne p;
    int nowtime,last;
    Uint32 dt=1;
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

int limit=7160;
int cpt_garbage_moving=100;
int akaros_animation, background_position_before_akaros, rand_akaros_spot, rand_akaros_step;
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
 initialiser_image_bouton(&image_clock, 500, 30, "images/clock.png");


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
///////
    // boucle
    

    
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

    //if (fd==-1) return -1;

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
  afficher_imageBMP(screen,frog.frame35); SDL_Flip(screen); SDL_Delay(delay); afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame36); SDL_Flip(screen); SDL_Delay(delay); afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame37); SDL_Flip(screen); SDL_Delay(delay); afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame38); SDL_Flip(screen); SDL_Delay(delay); afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame39); SDL_Flip(screen); SDL_Delay(delay); afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame40); SDL_Flip(screen); SDL_Delay(delay); afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame41); SDL_Flip(screen); SDL_Delay(delay); afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame42); SDL_Flip(screen); SDL_Delay(delay); afficher_imageBMP(screen,menu_background.mainmenu);
  afficher_imageBMP(screen,frog.frame43); SDL_Flip(screen); SDL_Delay(delay);
    initBack(&b);
    initPerso(&p);
    initialiser_texte_temps(&txte);
    initialiser_texte_leaderboard(&rank1, 440, 420);
    initialiser_texte_leaderboard(&rank2, 440, 480);
    initialiser_texte_leaderboard(&rank3, 440, 535);
    initialiser_image_sprite(&image_dust, 0 , 0 , 40, 70, "images/dust.png"); 
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
    SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
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
      
       for ( ; ; ){
        //  lecture d'une ligne
        serialport_read_until(fd, buffer, '\r', 99, 10000);

        // suppression de la fin de ligne
        for (manet=0 ; buffer[manet]!='\r' && manet<100 ; manet++);
        buffer[manet] = 0;

        // écriture du résultat
        printf("%s", buffer);
    
    

	if(p.image_perso.pos_img_ecran.y<695) {p.image_perso.pos_img_ecran.y+=5;}	
	/*printf("p.image_perso.pos_img_ecran.x: %d\n",p.image_perso.pos_img_ecran.x);
        printf("(b.background_ocean).pos_img_affiche.x: %d\n",(b.background_ocean).pos_img_affiche.x);
        printf("pos: %d\n",pos); //SDL_Delay(500);*/	
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
            animerBack(&b);(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;}
            afficherBack(b,screen);
	    SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
            afficherPerso(p,screen);
            	deplacer(&E);
        animerEnnemi(&E);
        afficherEnnemi(E, screen);
cpt2++;
	if (cpt2>8) cpt2=0; //printf("%d\n", cpt2);
	if (cpt2==0) {
		animerPerso(&p);
		} 
	    MAJMinimap(p,&m,b.camera,redimensionnement);
            afficher (m,screen);
            afficher_texte_temps(screen,txte,nowtime);
	deplacer(&E);
        animerEnnemi(&E);
        afficherEnnemi(E, screen);
            SDL_Flip(screen);
	if(p.image_perso.pos_img_ecran.y<560) 
		{
		p.image_perso.pos_img_ecran.y+=5; afficherBack(b,screen);
		SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
    		afficherPerso(p,screen); SDL_Flip(screen);
		}
	if (!(b.garbage_moving.pos_img_affiche.x==0 || b.garbage_moving.pos_img_affiche.x==800))	
	{	
	int rand_garbage_moving = rand() % 5 - 2; 
	if (cpt_garbage_moving>0) {b.garbage_moving.pos_img_ecran.x+=(4 + rand_garbage_moving); cpt_garbage_moving--;}
	else if (cpt_garbage_moving<=0) {b.garbage_moving.pos_img_ecran.x+=(-4 + rand_garbage_moving);cpt_garbage_moving--; }
	if (cpt_garbage_moving<-100) cpt_garbage_moving=100;
	}
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
        pos=p.image_perso.pos_img_ecran.x+(b.background_ocean).pos_img_affiche.x;
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
            b.acceleration=p.acceleration;
     if((event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=150 && event.motion.y>=50 && event.motion.x<=305 && event.motion.x>=50)) || (SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE))
     {
      initialiser_audiobref(mus);
      fleche=0;
      boucle_play=0;//quitter play
      initialiser_audio_mainmenu(music,volume_music);
      break;
     } 
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_d || strstr(buffer,"Marche avant") /*&& p.image_perso.pos_img_ecran.x<1300*/)//MOVE RIGHT
{
    p.direction=1;
    dte=1;
    while(dte)
    {
	if (collision(E.pos, p.image_perso.pos_img_ecran)) 
        {
	    if(grace>50) {p.nb_vies--; grace=0; Mix_PlayChannel(-1, E.collisionSound, 0);printf("collision\n");} 
        }  
        SDL_PollEvent(&event);
	if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e && p.acceleration<1) 
	{
	p.acceleration=15;
	dust_effect=1;
	SDL_Flip(screen);
	}
	if(p.acceleration > 0 ) {p.acceleration-=0.1;printf("acc_inside: %f\n",p.acceleration);}
        if(event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_d || strstr(buffer,"Marche avant") )
        {
            dte=0;
            printf("on est dans if2\n");
        }
        else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && up==0 )
        {
            p.image_perso.pos_img_ecran.y-=5;
        }
        else if(p.image_perso.pos_img_ecran.y<695)
        {
            p.image_perso.pos_img_ecran.y+=5; 
        }
        if(p.image_perso.pos_img_ecran.y<635) up=1;
        else if(p.image_perso.pos_img_ecran.y>685) up=0;
        if(p.image_perso.pos_img_ecran.y<695) air =1;
        else air=0;
        (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        afficherBack(b,screen);
        animerPerso(&p);
	now = SDL_GetTicks();
        if (now - before >=250)
        {
           animerBack (&b);
           before = now; (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        }
	SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
        afficherPerso(p,screen);
        MAJMinimap(p,&m,b.camera,redimensionnement);
	nowtime=SDL_GetTicks();nowtime-=last;
        afficher (m,screen);
        afficher_texte_temps(screen,txte,nowtime);
        deplacer(&E);
        animerEnnemi(&E);
        afficherEnnemi(E, screen);
        cpt++;
        if(cpt==10)
        {
            p.posSprite.x+=80;
            if(p.posSprite.x==640) p.posSprite.x=0;
            cpt=0;
	    if(dust_effect>0)
		{
       		image_dust.pos_img_ecran.x=p.image_perso.pos_img_ecran.x-15;
       		image_dust.pos_img_ecran.y=p.image_perso.pos_img_ecran.y+30;
		SDL_BlitSurface(image_dust.img,&image_dust.pos_img_affiche,screen,&image_dust.pos_img_ecran);
		dust_effect++;
		image_dust.pos_img_affiche.x+=70; 
		if(image_dust.pos_img_affiche.x>700) {image_dust.pos_img_affiche.x=-1;}
		if(dust_effect==3){}
		}

        }
        SDL_Flip(screen);
        SDL_EnableKeyRepeat(0,0);
	pos=p.image_perso.pos_img_ecran.x+(b.background_ocean).pos_img_affiche.x;
	printf("b.image_akaros.pos_img_ecran.x %d\n", b.image_akaros.pos_img_ecran.x); 
	if (!(b.garbage_moving.pos_img_affiche.x==0 || b.garbage_moving.pos_img_affiche.x==800))	
	{	
		int rand_garbage_moving = rand() % 5 - 2; 
		if (cpt_garbage_moving>0) {b.garbage_moving.pos_img_ecran.x+=(4 + rand_garbage_moving); cpt_garbage_moving--;}
		else if (cpt_garbage_moving<=0) {b.garbage_moving.pos_img_ecran.x+=(-4 + rand_garbage_moving);cpt_garbage_moving--; }
		if (cpt_garbage_moving<-100) cpt_garbage_moving=100;
	}
	if (pos>13086 && b.akaros_appearance==1)
	{
	background_position_before_akaros=(b.background_ocean).pos_img_affiche.x;
	SDL_Delay(400);
		while(b.image_akaros.pos_img_ecran.x>1450)
		{
	 		(b.background_ocean).pos_img_affiche.x+=35; printf("b.image_akaros.pos_img_ecran.x %d\n", b.image_akaros.pos_img_ecran.x);
			b.image_akaros.pos_img_ecran.x-=35;  
        		b.camera.x-=35;
       			mob=(SDL_GetTicks())%250;
        		if (mob>230) mob=0;
        		if (mob==0)
        		 {
        		    animerBack(&b);
       			 }
			(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        		afficherBack(b,screen);
        		SDL_Flip(screen);
		}
		SDL_Delay(500);
		shake_image(&b.background_ocean, 10, 250,b,screen);	
		b.akaros_is_shown=1;
       		mob=(SDL_GetTicks())%250;
        	if (mob>230) mob=0;
        	if (mob==0)
        	 {
        	    animerBack(&b);
       		 }
		(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        	afficherBack(b,screen);
        	SDL_Flip(screen);
		SDL_Delay(500);
		printf("\n\n(b.background_ocean).pos_img_affiche.x %d \n\n", (b.background_ocean).pos_img_affiche.x);
		printf(" b.image_akaros.pos_img_ecran.x %d\n\n", b.image_akaros.pos_img_ecran.x);
		printf("p.image_perso.pos_img_ecran.x %d\n\n",p.image_perso.pos_img_ecran.x);
		printf("pos %d \n\n", pos);
		akaros_animation=0; 
		while( b.image_akaros.pos_img_ecran.x>650)
		{
			if (akaros_animation>28)
			{
				if (akaros_animation%2==0) {akaros_animation=1; b.image_akaros.pos_img_affiche.x=800;}
				else { akaros_animation=0; b.image_akaros.pos_img_affiche.x=1000; }
			}
			b.image_akaros.pos_img_ecran.x-=15; 
			mob=(SDL_GetTicks())%250;
        		if (mob>230) mob=0;
        		if (mob==0)
        	 	{
        	    		animerBack(&b);
       		 	}
			(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        		afficherBack(b,screen);
        		SDL_Flip(screen);
			akaros_animation+=2;
		}
		int i;
		for (i=0;i<=2;i++)
		{	
			b.image_akaros.pos_img_affiche.x-=200;
			mob=(SDL_GetTicks())%250;
        		if (mob>230) mob=0;
        		if (mob==0)
        	 	{
        	    		animerBack(&b);
       		 	}
			(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        		afficherBack(b,screen);
        		SDL_Flip(screen);
			SDL_Delay(80);
		}
		b.image_akaros.pos_img_affiche.x=0;
		b.image_akaros.pos_img_affiche.y=0;
        	afficherBack(b,screen);
        	SDL_Flip(screen);
		shake_image(&b.image_akaros, 5, 150,b,screen);
		akaros_animation=0;
		b.image_akaros.pos_img_affiche.x=200;
		b.image_akaros.pos_img_affiche.y=400;
		while ((b.background_ocean).pos_img_affiche.x>background_position_before_akaros)
		{
			if (i!=-1)
			{
				for (i=0;i<9;i++)
				{
					if ((i%3)==0)
					{
						b.image_akaros.pos_img_affiche.x+=200;
					}
					if (i<4)
					{
						(b.background_ocean).pos_img_affiche.x-=10;
						b.camera.x+=5;
					}
					else 
					{
						(b.background_ocean).pos_img_affiche.x-=15;
						b.camera.x+=10;
					}
	       				mob=(SDL_GetTicks())%250;
					if (mob>230) mob=0;
					if (mob==0)
			 		{
			    			animerBack(&b);
	       		 		}
					(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
					afficherBack(b,screen);
					SDL_Flip(screen);
				}
			}
			i=-1;
			if (akaros_animation>28)
			{
				if (akaros_animation%2==0) {akaros_animation=1; b.image_akaros.pos_img_affiche.x=800;}
				else { akaros_animation=0; b.image_akaros.pos_img_affiche.x=1000; }
			}
			akaros_animation+=2;
			(b.background_ocean).pos_img_affiche.x-=20;
        		b.camera.x+=20;
       			mob=(SDL_GetTicks())%250;
        		if (mob>230) mob=0;
        		if (mob==0)
        	 	{
        	    		animerBack(&b);
       		 	}
			(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        		afficherBack(b,screen);
        		SDL_Flip(screen);
			if ((b.background_ocean).pos_img_affiche.x<background_position_before_akaros+600)
			{b.image_akaros.pos_img_ecran.x+=15;}
			}
			for (i=0;i<=9;i++)
			{	
				if(i<4) 				
				{	
					b.image_akaros.pos_img_affiche.x-=200;
				}
				else if (i==4)
				{
					b.image_akaros.pos_img_affiche.y=200;
					b.image_akaros.pos_img_affiche.x=0;
					SDL_Delay(80);
				}
				else if (i>4) b.image_akaros.pos_img_affiche.x+=200;
				mob=(SDL_GetTicks())%250;
				if (mob>230) mob=0;
				if (mob==0)
				 {
				    	animerBack(&b);
		       		 }
				(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
				afficherBack(b,screen);
				SDL_Flip(screen);
				SDL_Delay(80);
				printf("i %d\n", i);
				printf("b.image_akaros.pos_img_affiche.x %d\n", b.image_akaros.pos_img_affiche.x);
			}
		rand_akaros_spot= rand() % 400+100;
		b.akaros_appearance=0;
		
	}
	
	if (b.akaros_appearance==0)
	{b.image_akaros.pos_img_affiche.y=200;
	b.image_akaros.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+600;


	/*rand_akaros_step= rand() % 10;
	if (b.image_akaros.pos_img_ecran.x>rand_akaros_spot-10 && b.image_akaros.pos_img_ecran.x<rand_akaros_spot+10) 
	rand_akaros_spot = rand() % 600 - 300 + p.image_perso.pos_img_ecran.x+50; 
	else if (b.image_akaros.pos_img_ecran.x<rand_akaros_spot)
		{b.image_akaros.pos_img_ecran.x+=rand_akaros_step;
		b.image_akaros.pos_img_ecran.y+=rand_akaros_step;}
	else if (b.image_akaros.pos_img_ecran.x>rand_akaros_spot)
		 {b.image_akaros.pos_img_ecran.x-=rand_akaros_step;
		b.image_akaros.pos_img_ecran.y-=rand_akaros_step;}
	*/
	
		

/*	if (p.image_perso.pos_img_ecran.x+rand_akaros_movement!=b.image_akaros.pos_img_ecran.x)
	b.image_akaros.pos_img_ecran.x+=rand_aka_movement;*/
	}
        if(pos<limit && pos>650 && p.image_perso.pos_img_ecran.x>640 && b.level !=2)
        {
	    b.acceleration=p.acceleration;
            scrolling(&b, p.direction, dt);
            if (p.direction ==1)
            {
                (E.pos.x)-=5;
            }
            else if (p.direction == -1)
            {
                (E.pos.x)+=5;
            }
        }
        else if(!(b.level==2 && p.image_perso.pos_img_ecran.x>1350))
        {
            movePerso(&p,dt);
        }
    }
}
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_q || strstr(buffer,"marche arriere")/*&& p.image_perso.pos_img_ecran.x<1300*/)//MOVE RIGHT
{
    p.direction=-1;
    dte=1;
    while(dte)
    {
	pos=p.image_perso.pos_img_ecran.x+(b.background_ocean).pos_img_affiche.x;    
	if (collision(E.pos, p.image_perso.pos_img_ecran)) 
        {
	    if(grace>50) {p.nb_vies--; grace=0; Mix_PlayChannel(-1, E.collisionSound, 0);printf("collision\n");} 
        }    
	SDL_PollEvent(&event);
	if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e && p.acceleration<1) p.acceleration=15;//speed boost intensity a expliquer a la prof
	if(p.acceleration > 0 ) {p.acceleration-=0.1;printf("acc_inside: %f\n",p.acceleration);}
        if(event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_q || strstr(buffer,"marche arriere"))
        {
            dte=0;
            printf("on est dans if2\n");
        }
        else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && up==0 )
        {
            p.image_perso.pos_img_ecran.y-=5;
        }
        else if(p.image_perso.pos_img_ecran.y<695)
        {
            p.image_perso.pos_img_ecran.y+=5; 
        }
        if(p.image_perso.pos_img_ecran.y<635) up=1;
        else if(p.image_perso.pos_img_ecran.y>685) up=0;
        if(p.image_perso.pos_img_ecran.y<695) air =1;
        else air=0;
        (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
	b.image_akaros.pos_img_affiche.y=400;
	if (b.akaros_appearance==0)
	{	
		b.image_akaros.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+600;
		if (akaros_animation>20) b.image_akaros.pos_img_affiche.x=800;
		else  b.image_akaros.pos_img_affiche.x=1000; 
		akaros_animation+=2;
		if (akaros_animation>40) akaros_animation=0;
	}
        afficherBack(b,screen);
        animerPerso(&p);
	now = SDL_GetTicks();
        if (now - before >=250)
        {
           animerBack (&b);
           before = now; (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        }
	b.image_akaros.pos_img_affiche.y=400;
	SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
        afficherPerso(p,screen);
        MAJMinimap(p,&m,b.camera,redimensionnement);
	nowtime=SDL_GetTicks();nowtime-=last;
        afficher (m,screen);
        afficher_texte_temps(screen,txte,nowtime);
        deplacer(&E);
        animerEnnemi(&E);
        afficherEnnemi(E, screen);
        cpt++;
        if(cpt==10)
        {
            p.posSprite.x+=80;
            if(p.posSprite.x==640) p.posSprite.x=0;
            cpt=0;
        }
        SDL_Flip(screen);
        SDL_EnableKeyRepeat(0,0);
        
        if(p.image_perso.pos_img_ecran.x<= 50 && (b.background_ocean).pos_img_affiche.x>0  && b.level !=2)
        {
            b.acceleration=p.acceleration;
	    scrolling(&b, p.direction, dt);
            if (p.direction ==1)
            {
                (E.pos.x)-=5;
            }
            else if (p.direction == -1)
            {
                (E.pos.x)+=5;
            }
        }
        else if (p.image_perso.pos_img_ecran.x>32)
        {
            movePerso(&p,dt);
        }
	if (!(b.garbage_moving.pos_img_affiche.x==0 || b.garbage_moving.pos_img_affiche.x==800))	
	{	
		int rand_garbage_moving = rand() % 5 - 2; 
		if (cpt_garbage_moving>0) {b.garbage_moving.pos_img_ecran.x+=(4 + rand_garbage_moving); cpt_garbage_moving--;}
		else if (cpt_garbage_moving<=0) {b.garbage_moving.pos_img_ecran.x+=(-4 + rand_garbage_moving);cpt_garbage_moving--; }
		if (cpt_garbage_moving<-100) cpt_garbage_moving=100;
	}
    }
}
air=0;
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && air ==0)
{
   is_saut=1;
   //printf("on est dans saut horitonzal\n");
   while(is_saut)
	{
    
    p.image_perso.pos_img_ecran.y-=5;
    //printf("on est dans boucle de saut horitonzal\n");
     (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
     afficherBack(b,screen);
     //animerPerso(&p);
     SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
     afficherPerso(p,screen);
     MAJMinimap(p,&m,b.camera,redimensionnement);
     nowtime=SDL_GetTicks();nowtime-=last;
     afficher(m,screen);
     afficher_texte_temps(screen,txte,nowtime);
     deplacer(&E);
     animerEnnemi(&E);
     afficherEnnemi(E, screen);
     SDL_Flip(screen);
    SDL_PollEvent(&event);
    if(event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_SPACE || p.image_perso.pos_img_ecran.y<635) {is_saut=0;printf("on a relacher z\n");}
    else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_d) p.image_perso.pos_img_ecran.x+=5;
    else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_q) p.image_perso.pos_img_ecran.x-=5;
    
	}
	
}
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_h)
            {		
		p.score+=10;                
		p.nb_vies--;
		if(p.mana>1)p.mana--;
                SDL_Delay(100);

            }
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_y)
{
init_back(&back);
afficher_back(back,screen);
init_dos(&e);
afficherEnigme(e,screen);
SDL_Flip(screen);


 

SDL_Flip(screen);
srand(time(NULL));
    carte[1].img = IMG_Load("carte/black.png"); 
    carte[2].img = IMG_Load("carte/red.png");
    carte[3].img = IMG_Load("carte/blue.png");
    carte[4].img = IMG_Load("carte/ocean.png"); 
    carte[5].img = IMG_Load("carte/black.png1.png");
    carte[6].img = IMG_Load("carte/red.png1.png");
    carte[7].img = IMG_Load("carte/blue.png1.png");
    carte[8].img = IMG_Load("carte/ocean.png1.png");
    carte[1].url = "carte/black.png"; 
    carte[2].url ="carte/red.png";
    carte[3].url = "carte/blue.png";
    carte[4].url = "carte/ocean.png"; 
    carte[5].url = "carte/black.png1.png";
    carte[6].url = "carte/red.png1.png";
    carte[7].url = "carte/blue.png1.png";
    carte[8].url ="carte/ocean.png1.png";
int j;
for(j=1;j<9;j++)
 {do
		{

rando = rand() % 8; 

		}
	while(recherche(rando, rand_pris, 8));
		rand_pris[j-1]=rando;
carte_alea[j]=carte[rando+1];
}
   position[1].x = 700; 
    position[1].y = 50;
    position[2].x = 900;
    position[2].y = 50;
    position[3].x = 1100;
    position[3].y = 50;
    position[4].x = 1300;
    position[4].y = 50;
    position[5].x = 700;
    position[5].y = 350;
    position[6].x = 900;
    position[6].y = 350;
    position[7].x = 1100;
    position[7].y = 350;
    position[8].x = 1300;
    position[8].y = 350;


while (continuer) 
    {delay=SDL_GetTicks();
        while(SDL_PollEvent(&event)); 
	{
        switch (event.type)
        {
            case SDL_QUIT: 
                continuer = 0;
                break;

            case SDL_MOUSEBUTTONDOWN: 
		printf("click detected\n");
	while((win_condition!=4)&&(lose_condition!=-3))
    {
for(po=1;po<9;po++)
{if((event.type==SDL_MOUSEBUTTONDOWN) && ( event.button.button==SDL_BUTTON_LEFT && event.motion.y>=position[po].y && event.motion.y<=position[po].y+250 && event.motion.x>=position[po].x && event.motion.x<=position[po].x+150))
{o=po;
cont++;

}
}


if(cont==1)
{
last_pos=o;
}
	SDL_BlitSurface(carte_alea[o].img, NULL, screen, &position[o]);
	
if(cont==2)
{	
SDL_BlitSurface(carte_alea[last_pos].img, NULL, screen, &position[last_pos]);

SDL_BlitSurface(carte_alea[o].img,NULL,screen,&position[o]); 

SDL_Flip(screen);

SDL_Delay(100);


if(check(carte_alea[o].url,carte_alea[last_pos].url)!=1)
{		
SDL_BlitSurface(e.img,NULL,screen,&position[last_pos]);

SDL_BlitSurface(e.img,NULL,screen,&position[o]);

 
lose_condition--;
}
else
win_condition++;
cont=0;
}

		SDL_Delay(100);
                SDL_Flip(screen);
                break;}
if(lose_condition==-3)
{
 
    TTF_Font* font1 =  TTF_OpenFont("pixelated_arial_regular_11.ttf", 150);

    
    SDL_Surface* text = TTF_RenderText_Solid(font1, "hard luck", (SDL_Color) {0, 0, 128});

    
    SDL_Surface* rotatedText = rotozoomSurface(text, 0, 1.0, 1.0);

    
    SDL_Rect destRect = { screen->w/2 - rotatedText->w/2, screen->h/2 - rotatedText->h/2, 0, 0 };
    SDL_BlitSurface(rotatedText, NULL, screen, &destRect);

    SDL_Flip(screen);
    SDL_Delay(1000);

   
    
SDL_FreeSurface(text);
    SDL_FreeSurface(rotatedText);
    TTF_CloseFont(font1);

SDL_Quit();

}
if(win_condition==4)
{


    TTF_Font* font1 =  TTF_OpenFont("pixelated_arial_regular_11.ttf", 150);


    SDL_Surface* text = TTF_RenderText_Solid(font1, "you win", (SDL_Color) {0, 0, 128});


    SDL_Surface* rotatedText = rotozoomSurface(text, 0, 1.0, 1.0);


    SDL_Rect destRect = { screen->w/2 - rotatedText->w/2, screen->h/2 - rotatedText->h/2, 0, 0 };
    SDL_BlitSurface(rotatedText, NULL, screen, &destRect);

    SDL_Flip(screen);
    SDL_Delay(1000);


	SDL_FreeSurface(text);
    	SDL_FreeSurface(rotatedText);
    	TTF_CloseFont(font1);


}

}

	}//

    }
	liberer_dos(e);
    SDL_FreeSurface(carte[1].img);
    SDL_FreeSurface(carte[2].img);
    SDL_FreeSurface(carte[3].img);
    SDL_FreeSurface(carte[4].img);
    SDL_FreeSurface(carte[5].img);
    SDL_FreeSurface(carte[6].img);
    SDL_FreeSurface(carte[7].img);
    SDL_FreeSurface(carte[8].img);
    SDL_free;
   
}
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_w)
{
    float thirdleveltransition=40;
    p.image_perso.pos_img_ecran.x=1350;	
    while(p.image_perso.pos_img_ecran.x>650)
    {
        (b.background_ocean).pos_img_affiche.x+=thirdleveltransition;
        b.camera.x+=thirdleveltransition;
        p.image_perso.pos_img_ecran.x-=thirdleveltransition;
        mob=(SDL_GetTicks())%250;
        if (mob>230) mob=0;
        if (mob==0)
        {
            animerBack(&b);
        }(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        afficherBack(b,screen);
        SDL_Flip(screen);
	if (thirdleveltransition>30) thirdleveltransition-=2;
	if (thirdleveltransition>20) thirdleveltransition--;
	else if (thirdleveltransition>10) thirdleveltransition-=0.75;
	else if (thirdleveltransition>5) thirdleveltransition-=0.5;
    }
    limit=15378;
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

if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e && p.acceleration<1) p.acceleration=115;//speed boost intensity a expliquer a la prof
if(p.acceleration > 0 ) {p.acceleration-=0.3;printf("acc_inside: %f\n",p.acceleration);}
now = SDL_GetTicks();
if(p.mana<3) {p.mana+=0.006; /*printf("mana_inside: %f\n",p.mana);*/}

    }
    p.direction=0;
	if(p.mana<3){ p.mana+=0.003; /*printf("mana_outside: %f\n",p.mana);*/ }
        if(p.acceleration > 0 ) {p.acceleration-=0.1;printf("acc_outside: %f\n",p.acceleration);}//speed boost duration
        afficher_texte_temps(screen,txte,nowtime);
    ///ici ajouter les trucs du jeu
     SDL_Flip(screen);
   }}
    serialport_flush(fd);
    serialport_close(fd); 
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
