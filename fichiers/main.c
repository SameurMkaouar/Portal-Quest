/**  
* @file main.c  
* @brief Testing Program.  
* @author C Team  
* @version 0.1  
* @date Apr 01, 2015  
*  
* notre main important   *  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>  
#include "audio.h"
#include "image.h"
#include "text.h"
#include "hero.h"
#include "background.h"
#include "minimap.h"
#include "ennemi.h"
#include "enigme.h"
#include "fct.h"
#include "sauvegarde.h"	


int main()
{

//declaration des variables
SDL_Surface *screen, *coordinates;
int screen_h=800, screen_w=1450, dte, is_saut=0, air, up;
image_background menu_background;
image_bouton bouton;
image image_leaderboard, image_clock;
Mix_Music *animation_music, *music, *options_music, *play_music, *credits_music; // a changer en enregistrement
Mix_Chunk *mus,*longmus, *blank, *hurt;
texte txte_volume_music, txte_volume_chunk,txte_fullscreen, txte_windowed; // a chnager en enregistrement

    tic t;

    int boucle_tic=1;

    int largecase=232, hautcase=182,coup,x_tic=330,y_tic=175;



int volume_music=100, volume_chunk=100; //64 32
int grace = 0;
SDL_Event event;
int boucle=1, boucle_animation=1, boucle_options,boucle_play;
int delay=45;
animation frog;
int fleche=0;
int flecheforriddle=0;
SDL_Surface *texet, *surfaceforriddle;
int longmus_play=0, longmus_options=0, longmus_credits=0, longmus_quit=0;
int pos=0, posbeforeshelly=0;
int displaymode_counter=0;
bool changement_display = true, changement_volume = false;
int shelly=0, dust_effect=0;
int cpt_mus=1;
Uint32 dx;
//////
    int randforriddle=0;
    int multiplayer=0;
    minimap m;
    background b,b2;
    int redimensionnement=20;
    textemelek txte;
    personne p;
    personne p1;
    int nowtime,last;
    Uint32 dt=1;
    scoreInfo s;
    scoreInfo tab_score[10];
    char score_str[45];
    char score_str1[45];
    char score_str2[45];
    texte rank1, rank2, rank3;
    int cpt=0, salut, cptbee;
    Uint32 now, before = 0, mob=0, cpt2=0;
//////
     Ennemi E;
     int interface;
     int input;
     Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
//////

int limit=7160;
int cpt_garbage_moving=100;
int akaros_animation, background_position_before_akaros, rand_akaros_spot, rand_akaros_step, akaros_stop=0;
int reversed=0, is_reversed=0;
int tpc=0,mx=1;
char char_rose_counter[4];
texte txt_rose_counter,txt_rose_counter_p2;
image image_rose_counter;
int rose_counter=0;
float angle = 0.0f; // current angle of the floating effect	
float amplitude = 10.0f; // maximum distance the item can float
float frequency = 1.0f; // frequency of the floating effect
float speed = 0.07f; // speed of the floating effect
int end=1;
image image_drop_dust,where_am_i, image_you_box, image_bard_box, image_shelly_box, image_snake_box, image_napta_box;
const char* dial_text;


int dial1=2, dial2=2, dial3=2, dial4=2, dial5=2, dial6=2;
int az=0, new_game=0;
int gracing=0;
int i;
int rand_garbage_moving=0;
int a=0;
int ground_y=695;
image image_mutli1, image_mutli2, image_new, image_load;
int old_mx=5;
image head, mini; 
image txtpuzz, txtpuzz1, txtpuzz2,txtpuzzfail1,txtpuzzfail2,txtpuzzwin1,txtpuzzwin2; 
image txtbackwin, txtbacklost;
image xotxt, xotxtwithback, xoback; 
int nade=7, paro_bard=1;

////
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
int snake=1;
int damage_variable=1;
Mix_Chunk *music_damage,*music_jump, *music_score,*music_collect;
int show=0,showrose1=0,showrose2=0,showrose3=0,npcshow=0,npcshownegative=0,showprep=0,showhornet=0,showsam=0;
int showspeed=4;

int pos_att_beex;
int pos_att_beey;
int nah=0;
image quest_box, image_death; 
int tab=0, q1=0,q2=0, did_reach_hornet=0, hornetdamage=0;

int puzzle1time=0, puzzle2time=0, puzzle3time=0;
int puzzle1timestart=0,puzzle2timestart=0,puzzle3timestart=0;

//init_boutton(&boutton);
////maze var
image maze,maze_mask,tawfik,image_shade;
image image_calcscore, image_collected_score ,image_time1, image_lives_left,image_time2,image_time3,image_total, image_khat; 
int welcback=0;
////
//initialisation de la SDL
if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) {
    printf("Failed to initialize SDL: %s\n", SDL_GetError());
    return -1;
}

if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
    printf("Failed to initialize SDL_image: %s\n", IMG_GetError());
    return -1;
}

if (TTF_Init() < 0) {
    printf("Failed to initialize SDL_ttf: %s\n", TTF_GetError());
    return -1;
}
SDL_Color white_color  = { 255, 255, 255 };
TTF_Font* arcade_font = TTF_OpenFont("fonts/arcade.ttf", 20);

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


//boucle du MENU
b.i=0;
 initialiser_image_leaderboard(&image_leaderboard, 357,140, "images/leaderboard.png");
initialiser_image_background(&image_mutli1, 800 , 1450, "images/mutli1.png");
initialiser_image_background(&image_mutli2, 800 , 1450, "images/mutli2.png");
initialiser_image_background(&image_new, 800 , 1450, "images/new.png");
initialiser_image_background(&image_load, 800 , 1450, "images/load.png");
initialiser_image_bouton(&txtpuzz,156, 365 ,"imagess/test.png");
initialiser_image_bouton(&txtpuzz1,156, 365 ,"imagess/welc.png");
initialiser_image_bouton(&txtpuzz2,274, 415 ,"imagess/yourgoal.png");
initialiser_image_bouton(&txtpuzzfail1,252, 280 ,"imagess/fail1.png");
initialiser_image_bouton(&txtpuzzfail2,252, 400 ,"imagess/fail2.png");
initialiser_image_bouton(&txtpuzzwin1,209, 280 ,"imagess/win1.png");
initialiser_image_bouton(&txtpuzzwin2,209, 400 ,"imagess/win2.png");
initialiser_image_bouton(&xotxt,185, 383 ,"images/xotxt.png");
initialiser_image_bouton(&xotxtwithback,185, 383 ,"images/xotxtwithback.png");
initialiser_image_background(&xoback,800, 1450, "imagess/xoback.png");
initialiser_image_background(&txtbackwin,800, 1450, "imagess/backwin.png");
initialiser_image_background(&txtbacklost, 800,1450, "imagess/backlose.png");

initialiser_image_bouton(&image_death,293, 335,"images/death_txt.png");

initialiser_image_bouton(&image_calcscore,317, 55 ,"images/calcscore.png");
initialiser_image_bouton(&image_collected_score,61, 198 ,"images/collected_score.png");
initialiser_image_bouton(&image_lives_left,61, 271 ,"images/lives_left.png");
initialiser_image_bouton(&image_time1,61, 350,"images/time1.png");
initialiser_image_bouton(&image_time2,61, 420 ,"images/time2.png");
initialiser_image_bouton(&image_time3,61, 490 ,"images/time3.png");
initialiser_image_bouton(&image_total,61, 560 ,"images/total.png");
initialiser_image_bouton(&image_khat,940, 635 ,"images/khat.png");

initialiser_image_bouton(&image_shade,860, 320 ,"images/nightshade.png");

//QUESTS
initialiser_image_bouton(&quest_box,1135, 282 ,"images/quest_box.png");
SDL_Color colorquest1 = { 255, 255, 255 };
SDL_Color colorquest2 = { 255, 255, 255 };
SDL_Color colorquest3 = { 255, 255, 255 };
SDL_Color colorquest4 = { 255, 255, 255 };
SDL_Color colorquest5 = { 255, 255, 255 };
SDL_Color colorquest6 = { 255, 255, 255 };
SDL_Color colorwhite={255,255,255};
SDL_Color colorbonus={255,255,255};
SDL_Color colorcompletion={169,169,169};
TTF_Font* questfont = TTF_OpenFont("fonts/arcade.ttf", 14);
TTF_Font* completionfont = TTF_OpenFont("fonts/Middle.ttf", 24);
TTF_Font* bonusfont = TTF_OpenFont("fonts/Middle.ttf", 54);

//BONUS
char bonuschar[5]; 
float bonusint=1;
sprintf(bonuschar, "X%.0f", bonusint);
SDL_Surface* txtbonus = TTF_RenderText_Solid(bonusfont, bonuschar, colorbonus);
SDL_Rect txtbonuspos;
txtbonuspos.x=1339;
txtbonuspos.y=204;

//QUEST1
SDL_Surface* txtquest1 = TTF_RenderText_Solid(questfont, "-collect your first", colorquest1);
char quest60s[20]; 
int secondsforrose=60;
sprintf(quest60s, "Rose within %ds", secondsforrose);
SDL_Surface* txt2quest1 = TTF_RenderText_Solid(questfont, quest60s, colorquest1);
SDL_Rect txtquest1pos;
txtquest1pos.x=1141;
txtquest1pos.y=360;
SDL_Rect txt2quest1pos;
txt2quest1pos.x=1139;
txt2quest1pos.y=380;

//QUEST2
SDL_Surface* txtquest2 = TTF_RenderText_Solid(questfont, "-use your ability", colorquest2);
char quest10times[10];
int ability_counter = 2;
sprintf(quest10times, "%d times", ability_counter);
SDL_Surface* txt2quest2 = TTF_RenderText_Solid(questfont, quest10times, colorquest2);
SDL_Rect txtquest2pos;
txtquest2pos.x=1141;
txtquest2pos.y=424;
SDL_Rect txt2quest2pos;
txt2quest2pos.x=1139;
txt2quest2pos.y=442;

//QUEST3
SDL_Surface* txtquest3 = TTF_RenderText_Solid(questfont, "-talk to all npcs", colorquest3);
SDL_Rect txtquest3pos;
txtquest3pos.x=1141;
txtquest3pos.y=485;

//QUEST4
SDL_Surface* txtquest4 = TTF_RenderText_Solid(questfont, "-explore diverse", colorquest4);
SDL_Surface* txt2quest4 = TTF_RenderText_Solid(questfont, "presepectives", colorquest4);
SDL_Rect txtquest4pos;
txtquest4pos.x=1141;
txtquest4pos.y=530;
SDL_Rect txt2quest4pos;
txt2quest4pos.x=1139;
txt2quest4pos.y=548;
//QUEST5
SDL_Surface* txtquest5 = TTF_RenderText_Solid(questfont, "-unharmed by the", colorquest5);
SDL_Surface* txt2quest5 = TTF_RenderText_Solid(questfont, "vengeful hornet", colorquest5);
SDL_Rect txtquest5pos;
txtquest5pos.x=1141;
txtquest5pos.y=591;
SDL_Rect txt2quest5pos;
txt2quest5pos.x=1139;
txt2quest5pos.y=609;
//QUEST6
SDL_Surface* txtquest6 = TTF_RenderText_Solid(questfont, "-visit the realm", colorquest6);
SDL_Surface* txt2quest6 = TTF_RenderText_Solid(questfont, "of the unliving", colorquest6);
SDL_Rect txtquest6pos;
txtquest6pos.x=1141;
txtquest6pos.y=653;
SDL_Rect txt2quest6pos;
txt2quest6pos.x=1139;
txt2quest6pos.y=671;

//COMPLETION
char completionchar[20]; 
int completioninteger=0;
sprintf(completionchar, "-Completion %d%%-", completioninteger);
SDL_Surface* txtcompletion = TTF_RenderText_Solid(completionfont, completionchar, colorcompletion);
SDL_Rect txtcompletionpos;
txtcompletionpos.x=1178;
txtcompletionpos.y=720;

TTF_Font* tabfont = TTF_OpenFont("fonts/Middle.ttf", 18);
//tabtohide
SDL_Surface* txttabtohide = TTF_RenderText_Solid(tabfont, "tab to hide", colorcompletion);
SDL_Rect txttabtohidepos;
txttabtohidepos.x=1235;
txttabtohidepos.y=282;

//tabtoshow
SDL_Surface* txttabtoshow = TTF_RenderText_Solid(tabfont, "tab to show", colorcompletion);
SDL_Rect txttabtoshowpos;
txttabtoshowpos.x=1235;
txttabtoshowpos.y=282;

SDL_Surface* txttabtoshowquests = TTF_RenderText_Solid(tabfont, "Quests", colorcompletion);
SDL_Rect txttabtoshowquestspos;
txttabtoshowquestspos.x=1262;
txttabtoshowquestspos.y=300;
SDL_EventState(SDL_MOUSEMOTION,SDL_ENABLE);
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
 initialiser_image_bouton(&image_rose_counter, 40, 160, "images/rose_counter.png");

 initialiser_texte_score(&txt_rose_counter,85,160);
 initialiser_texte_score(&txt_rose_counter_p2,725+85,160);
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
  SDL_BlitSurface(image_mutli2.img,NULL,screen,&image_mutli2.pos_img_ecran); SDL_Flip(screen);
  SDL_Delay(100);
while(multiplayer==0)
	{
	//todo 
        //done
	SDL_WaitEvent(&event);
	if (event.motion.y<=800 && event.motion.y>=0 && event.motion.x<=725&& event.motion.x>=0) 
        SDL_BlitSurface(image_mutli1.img,NULL,screen,&image_mutli1.pos_img_ecran); 
else SDL_BlitSurface(image_mutli2.img,NULL,screen,&image_mutli2.pos_img_ecran); 

	if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && event.motion.y<=800 && event.motion.y>=0 && event.motion.x<=725&& event.motion.x>=0) multiplayer=1;
	else if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && event.motion.y<=800 && event.motion.y>=0 && event.motion.x<=1450&& event.motion.x>=725) multiplayer=2;
	SDL_Flip(screen);
	}
   s.score=0;
   strcpy(s.playerName,"player");
   s.time=0;
////////////////************************************************************************debut msayeb
   b.fullscreen=0;
   b.level=1;
if (multiplayer==1)
{
while (1)
{
    SDL_WaitEvent(&event); 
if (event.motion.y<=400 && event.motion.y>=0 && event.motion.x<=725 && event.motion.x>=0){
SDL_BlitSurface(image_new.img,NULL,screen,&image_new.pos_img_ecran); SDL_Flip(screen);}
else {
SDL_BlitSurface(image_load.img,NULL,screen,&image_load.pos_img_ecran); SDL_Flip(screen);}

if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=800 && event.motion.y>=400 && event.motion.x<=725 && event.motion.x>=0)) 
    {
     new_game=1; break;
    }
    else if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=400 && event.motion.y>=0 && event.motion.x<=725 && event.motion.x>=0)) {new_game=0; break;}
}
}
   afficher_imageBMP(screen,menu_background.mainmenu);
   Mix_VolumeMusic(volume_music/4);
   for (i=0; i<20; i++)
   {afficher_imageBMP(screen,frog.frame34); SDL_Flip(screen); SDL_Delay(32);}
    initBack(&b); initBack(&b2);
    initPerso(&p);
    initPerso2(&p1);
    initialiser_texte_temps(&txte);
    initialiser_texte_leaderboard(&rank1, 440, 420);
    initialiser_texte_leaderboard(&rank2, 440, 480);
    initialiser_texte_leaderboard(&rank3, 440, 535);
    initialiser_image_sprite(&b.image_dust, 0 , 0 , 27, 65, "images/dust.png");
    initialiser_image_bouton(&where_am_i, 0,635,"images/where_am_i.png");
    initEnnemi(&E);
    SDL_Color textColor = { 255, 255, 255 };
    TTF_Font* font = TTF_OpenFont("fonts/Middle.ttf", 40);

    SDL_Surface* textSurface = TTF_RenderText_Blended(font, "Darkness  fades,  and  a  world  appears,", textColor);
    fade_in_text(textSurface, screen, 280,200, 2500);

    textSurface = TTF_RenderText_Blended(font, "Mysterious,  fraught  with  doubts  and  fears.", textColor);
    fade_in_text(textSurface, screen, 220,280, 2500);

    textSurface = TTF_RenderText_Blended(font, "Thy  quest  is  to  halt  Akaros'  might,", textColor);
    fade_in_text(textSurface, screen, 300,360, 2500);

    textSurface = TTF_RenderText_Blended(font, "Save  the  realm  from  eternal  night.", textColor);
    fade_in_text(textSurface, screen, 297,440, 2500);
    for (i=0; i<20;i++)
    {
      afficher_imageBMP(screen,frog.frame34); SDL_Flip(screen); SDL_Delay(delay);
    }
    SDL_Delay(800);
  initialiser_image_bouton(&image_drop_dust,680, 680,"images/drop_dust.png");
  initialiser_image_bouton(&image_bard_box,223, 232,"images/bard_box.png");
  initialiser_image_bouton(&image_you_box,223, 232,"images/you_box.png");
  initialiser_image_bouton(&image_shelly_box,223, 232,"images/shelly_box.png");
  initialiser_image_bouton(&image_napta_box,223, 232,"images/image_napta_box.png");
  initialiser_image_bouton(&image_snake_box,223, 232,"images/snake_box.png");
 init_back(&back);init_dos(&e); 
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
if(multiplayer==2)
 {
    audio_level1(b.level1_music,volume_music, cpt_mus);
    initialiser_texte_score(&p.score_text,50,240);
    afficherBack2p(b,screen);
    SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
    SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x+=725;
		SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x-=725;
    sprintf(char_rose_counter, "  %d", rose_counter);
    afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
    afficher_texte_custom(screen, txt_rose_counter_p2,char_rose_counter);
    afficherPerso(p,screen);
    afficherPerso(p1,screen);
    MAJMinimap(p,&m,b.camera,redimensionnement);
    afficher (m,screen);
    SDL_EventState(SDL_MOUSEMOTION,SDL_DISABLE);//**A REMOVER** SI POSSIBLE
    SDL_Flip(screen);
///////////////********************************************************************************fin msayeb
  last=SDL_GetTicks();
  while(boucle_play)
  { 	 


 	 if(event.motion.y<=150 && event.motion.y>=50 && event.motion.x<=305 && event.motion.x>=50)
         {
   	 afficher_imageBTN(screen,bouton.clicked_back);
  	 }
  	 else afficher_imageBTN(screen,bouton.unclicked_back);
	if (gracing>400) gracing=0;
	gracing++;
	if(p.image_perso.pos_img_ecran.y<695 && reversed==0) p.image_perso.pos_img_ecran.y+=5;
	else if(p.image_perso.pos_img_ecran.y>50 && reversed==1) p.image_perso.pos_img_ecran.y-=5;
	grace++;
	if (collision(b.e.vertical1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical3.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical4.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical5.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical6.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal3.pos_img_ecran, p.image_perso.pos_img_ecran))
        {
		if(grace>50) {p.nb_vies--; grace=0;}
        }
	if(grace<50) 
	{
		if (gracing%4==0) p.image_perso.img=IMG_Load("images/marioplayer.png");
		else if (gracing%4==1) p.image_perso.img=IMG_Load("images/idlegrace30.png");
		else if (gracing%4==2) p.image_perso.img=IMG_Load("images/idlegrace60.png");
		else if (gracing%4==3) p.image_perso.img=IMG_Load("images/idlegrace30.png");
	}	
	else if (grace<55) {p.sprite=IMG_Load("images/spritefinal.png"); p.image_perso.img=IMG_Load("images/marioplayer.png");}
        nowtime=SDL_GetTicks();
        nowtime-=last;
        mob=(SDL_GetTicks())%250;
	if (mob>210) mob=0;
	else if (mob>100 && mob<150)
	{
	b.image_shelly.pos_img_affiche.x+=72;
	if (b.image_shelly.pos_img_affiche.x>800) b.image_shelly.pos_img_affiche.x=0;
	}
        if (mob==0)
        {
            animerBack(&b);
	    (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
	}
	cpt2++;
	if (cpt2>8) cpt2=0; 
	if (cpt2==0) {animerPerso(&p); animerPerso(&p1);}

	if(p.image_perso.pos_img_ecran.y<560 && reversed==0) p.image_perso.pos_img_ecran.y+=5;
	else if( p.image_perso.pos_img_ecran.y>50 && reversed==1) p.image_perso.pos_img_ecran.y-=5;
	if (!(b.garbage_moving.pos_img_affiche.x==0 || b.garbage_moving.pos_img_affiche.x==800))
	{
	rand_garbage_moving = rand() % 5 - 2;
	if (cpt_garbage_moving>0) {b.garbage_moving.pos_img_ecran.x+=(4 + rand_garbage_moving); cpt_garbage_moving--;}
	else if (cpt_garbage_moving<=0) {b.garbage_moving.pos_img_ecran.x+=(-4 + rand_garbage_moving);cpt_garbage_moving--; }
	if (cpt_garbage_moving<-100) cpt_garbage_moving=100;
	}
 	projectiles_movement(&b,p.direction,0);
	if (akaros_stop==0) float_items(&b, &angle,frequency,amplitude,speed);
	else if (akaros_stop==1)
	{
	if ((b.image_akaros.pos_img_ecran.x+b.image_akaros.pos_img_ecran.h/2)<p.image_perso.pos_img_ecran.x)
		{		
			b.akaros_direction=-1;
		}
	}
pos=p.image_perso.pos_img_ecran.x+(b.background_ocean).pos_img_affiche.x;

 if (pos>6760 && pos<6860 && shelly==0)
{
    dte=0;
    SDL_EventState(SDL_MOUSEMOTION,SDL_DISABLE);
    shelly=1;
    posbeforeshelly=pos;
    float qsd=10;
    int dan=1;
    int cpt_fall=0;
  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame34); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame35); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame36); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame37); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame38); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame39); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame40); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame41); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame42); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame43); SDL_Flip(screen); SDL_Delay(delay);
  SDL_Delay(250); b.level=3;
  p.image_perso.pos_img_ecran.y=-70;
  p.image_perso.pos_img_ecran.x=710;
  p.image_perso.pos_img_affiche.x=0;
  p.image_perso.pos_img_affiche.y=168;    
  image_drop_dust.pos_img_affiche.h=65;
  image_drop_dust.pos_img_affiche.w=160;
  b.image_bard.pos_img_ecran.x=200;
  b.image_bard.pos_img_ecran.y=2495;
  b.image_bard.pos_img_affiche.y=66;
  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame43); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame42); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame41); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame40); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame39); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame38); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame37); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame36); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame35); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame34); SDL_Flip(screen); SDL_Delay(delay);
  audio_level2(b.level2_music,volume_music);
  afficherBack2p(b,screen);										 	 SDL_BlitSurface(b.background_forest.img,&b.background_forest.pos_img_affiche,screen,&b.background_forest.pos_img_ecran);
afficherPerso(p,screen);
afficherPerso(p1,screen);
SDL_Flip(screen);
while (dan)
{
 	dte=0;
	if (p.image_perso.pos_img_ecran.y<400) { p.image_perso.pos_img_ecran.y+=qsd/2;}
	else if (b.background_fall.pos_img_affiche.y<1824) { b.background_fall.pos_img_affiche.y+=qsd; b.image_bard.pos_img_ecran.y-=qsd;}
	else if (p.image_perso.pos_img_ecran.y<660) {p.image_perso.pos_img_ecran.y+=qsd;}
	else if (p.image_perso.pos_img_affiche.x<1080) 
	     {
		dan+=qsd;
		if (cpt_fall%20==0) p.image_perso.pos_img_affiche.x+=60;
		cpt_fall++;
		if (cpt_fall%20==0) image_drop_dust.pos_img_affiche.x+=160;
	     }
	else {p.image_perso.pos_img_affiche.x=0; p.image_perso.pos_img_affiche.y=0; dan=0;}

afficherBack2p(b,screen);										SDL_BlitSurface(b.background_forest.img,&b.background_forest.pos_img_affiche,screen,&b.background_forest.pos_img_ecran);
if (cpt_fall>0) SDL_BlitSurface(image_drop_dust.img,&image_drop_dust.pos_img_affiche,screen,&image_drop_dust.pos_img_ecran);
afficherPerso(p,screen);
afficherPerso(p1,screen);
SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x+=725;
		SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x-=725;
sprintf(char_rose_counter, "  %d", rose_counter);
afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
afficher_texte_custom(screen, txt_rose_counter_p2,char_rose_counter);
nowtime=SDL_GetTicks();nowtime-=last;
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
SDL_Delay(2);
}
}
else if (p.image_perso.pos_img_ecran.x>1000 && b.level==3)
{
    int second_level_transition=0;
    float c=8;
    while(second_level_transition<800)
    {
	if (b.background_forest.pos_img_ecran.y<640 && p.image_perso.pos_img_ecran.y>100)
	p.image_perso.pos_img_ecran.y-=c;
        b.background_forest.pos_img_ecran.y-=c;
        b.background_fall.pos_img_affiche.y+=c*1.1;
	b.image_bard.pos_img_ecran.y-=c;
	b.image_shelly.pos_img_ecran.y-=c;
afficherBack2p(b,screen);									SDL_BlitSurface(b.background_forest.img,&b.background_forest.pos_img_affiche,screen,&b.background_forest.pos_img_ecran);
afficherPerso(p,screen);
afficherPerso(p1,screen);
SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x+=725;
		SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x-=725;
sprintf(char_rose_counter, "  %d", rose_counter);
afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
afficher_texte_custom(screen, txt_rose_counter_p2,char_rose_counter);
nowtime=SDL_GetTicks();nowtime-=last;
afficher_texte_temps(screen,txte,nowtime);
SDL_BlitSurface(b.image_shelly.img,&b.image_shelly.pos_img_affiche,screen,&b.image_shelly.pos_img_ecran);
        SDL_Flip(screen);
	second_level_transition+=c;
	if (c>20) c--;
	else if (c>10) c-=0.75;
	else if (c>5) c-=0.5;
    }
    b.level=2;
    b.background_ocean.pos_img_ecran.y=0;
    (b.tab_frames[b.i]).pos_img_ecran.y=0;
    audio_level2(b.level2_music,volume_music);
  b.image_bard.pos_img_ecran.x=5200;
  b.image_bard.pos_img_ecran.y=520;
  b.image_bard.pos_img_affiche.y=0;
}
        afficherBack2p(b,screen);
    if (pos>1600 && pos<2400)  
    {
        where_am_i.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+40;
	SDL_BlitSurface(where_am_i.img,NULL,screen,&where_am_i.pos_img_ecran);
    }	
	SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
	SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x+=725;
		SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x-=725;
	sprintf(char_rose_counter, "  %d", rose_counter);
	afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
	afficher_texte_custom(screen, txt_rose_counter_p2,char_rose_counter);
        afficherPerso(p,screen);
	afficherPerso(p1,screen);
	MAJMinimap(p,&m,b.camera,redimensionnement);
        afficher (m,screen);
        afficher_texte_temps(screen,txte,nowtime);
	SDL_Flip(screen);
	if(p.mana<3) p.mana+=0.003;
        if(p.acceleration > 0 ) p.acceleration-=0.1;
	if (b.level==2 || b.level==3) SDL_Delay(12);
   while(SDL_PollEvent(&event))
    {
air=0;
//debut new player

if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_RIGHT )
{
    if (reversed==0) p1.direction=1;
    else p1.direction=2;
    dte=1;
    while(dte)
    {

	grace++;
	if (grace>50 && (collision(b.e.vertical1.pos_img_ecran, p1.image_perso.pos_img_ecran) || collision(b.e.vertical2.pos_img_ecran, p1.image_perso.pos_img_ecran) || collision(b.e.vertical3.pos_img_ecran, p1.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal1.pos_img_ecran, p1.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal2.pos_img_ecran, p1.image_perso.pos_img_ecran)|| collision_horizontal(b.e.horizontal3.pos_img_ecran, p1.image_perso.pos_img_ecran) || collision(b.e.vertical4.pos_img_ecran, p1.image_perso.pos_img_ecran)|| collision(b.e.vertical5.pos_img_ecran, p1.image_perso.pos_img_ecran)|| collision(b.e.vertical6.pos_img_ecran, p1.image_perso.pos_img_ecran)))
        {
		  p1.nb_vies--; grace=0;
        }
		if(grace<50)
	   {     
		if (a%4==0) p1.sprite=IMG_Load("images/spritefinal.png");
		else if (a%4==1) p1.sprite=IMG_Load("images/gracesprite30.png");
		else if (a%4==2) p1.sprite=IMG_Load("images/gracesprite60.png");
		else if (a%4==3) p1.sprite=IMG_Load("images/gracesprite30.png");
	   }
	   else if (grace<55) {p1.sprite=IMG_Load("images/spritefinal.png"); p1.image_perso.img=IMG_Load("images/marioplayer.png");}
       a++;
    //event
    SDL_PollEvent(&event);
if(event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_RIGHT )
{
    dte=0;
}
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LSHIFT && p1.acceleration<1)
{
    p1.acceleration=15;
    dust_effect=1;
    b.image_dust.pos_img_ecran.x=p1.image_perso.pos_img_ecran.x;
    b.image_dust.pos_img_ecran.y=p1.image_perso.pos_img_ecran.y+70-27;
}

//pos
pos=p1.image_perso.pos_img_ecran.x+(b.background_ocean).pos_img_affiche.x;

dx=0.5*(b.acceleration)*dt*dt + 5*dt;
if(pos<limit && pos>1087 && p1.image_perso.pos_img_ecran.x>1087 && b.level==1)
{
    b.acceleration=p1.acceleration;
    b.back2.pos_img_affiche.x+=dx;
    //scrollBackground(&b, screen, p.image_perso.pos_img_ecran.x, p1.image_perso.pos_img_ecran.x);
}
else if(!(b.level==2 && p1.image_perso.pos_img_ecran.x>1350))
{
    movePerso(&p1,dt);
}
if (pos>9743 && is_reversed==0)
{
    p1.direction=2;
    reversed=1;
    is_reversed=1;
    p1.image_perso.pos_img_ecran.x+=50;
    p1.image_perso.pos_img_ecran.y=50;
}
else if (pos>11300)
{
    reversed=0;
    p1.direction=1;
}
if (pos>6760 && pos<6860 && shelly==0) dte=0;
else if (pos>16050 && end==1)
{
    p1.direction=0;
    end_game(&b.background_ocean,&b.image_akaros, 1, 300, b, screen,p);
    end=0;
}
else if (pos>13086 && b.akaros_appearance==1)
{
    background_position_before_akaros=(b.background_ocean).pos_img_affiche.x;
    while(b.image_akaros.pos_img_ecran.x>1450)
    {
        (b.background_ocean).pos_img_affiche.x+=35;
        b.image_akaros.pos_img_ecran.x-=35;
        b.camera.x-=35;
        b.e.vertical1.pos_img_ecran.x-=35;
        b.e.vertical2.pos_img_ecran.x-=35;
        b.e.vertical3.pos_img_ecran.x-=35;
        b.e.vertical4.pos_img_ecran.x-=35;
        b.e.vertical5.pos_img_ecran.x-=35;
        b.e.vertical6.pos_img_ecran.x-=35;
        b.e.horizontal1.pos_img_ecran.x-=35;
        b.e.horizontal2.pos_img_ecran.x-=35;
        b.e.horizontal3.pos_img_ecran.x-=35;
        mob=(SDL_GetTicks())%250;
        if (mob>230)
        {
            mob=0;
            animerBack(&b);
        }
        (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        afficherBack2p(b,screen);
        SDL_Flip(screen);
    }
    SDL_Delay(500);
    shake_image(&b.background_ocean, 10, 250,b,screen);
    b.akaros_is_shown=1;
    mob=(SDL_GetTicks())%250;
    if (mob>230)
    {
        mob=0;
        animerBack(&b);
    }
    (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
    afficherBack2p(b,screen);
    SDL_Flip(screen);
    SDL_Delay(500);
    akaros_animation=0;
    while( b.image_akaros.pos_img_ecran.x>650)
    {
        if (akaros_animation>28)
        {
            if (akaros_animation%2==0)
            {
                akaros_animation=1;
                b.image_akaros.pos_img_affiche.x=800;
            }
            else
            {
                akaros_animation=0;
                b.image_akaros.pos_img_affiche.x=1000;
            }
        }
        b.image_akaros.pos_img_ecran.x-=15;
        mob=(SDL_GetTicks())%250;
        if (mob>230)
        {
            mob=0;
            animerBack(&b);
        }
        (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        afficherBack2p(b,screen);
        SDL_Flip(screen);
        akaros_animation+=2;
    }
    for (i=0; i<=2; i++)
    {
        b.image_akaros.pos_img_affiche.x-=200;
        mob=(SDL_GetTicks())%250;
        if (mob>230)
        {
            mob=0;
            animerBack(&b);
        }
        (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        afficherBack2p(b,screen);
        SDL_Flip(screen);
        SDL_Delay(80);
    }
    b.image_akaros.pos_img_affiche.x=0;
    b.image_akaros.pos_img_affiche.y=0;
    afficherBack2p(b,screen);
    SDL_Flip(screen);
    shake_image(&b.image_akaros, 5, 30,b,screen);
    b.akaros_shake=1;
    shake_image(&b.image_akaros, 5, 150,b,screen);
    akaros_animation=0;
    b.image_akaros.pos_img_affiche.x=200;
    b.image_akaros.pos_img_affiche.y=400;
    while ((b.background_ocean).pos_img_affiche.x>background_position_before_akaros+15)
    {
        if (i!=-1)
        {
            for (i=0; i<9; i++)
            {
                if ((i%3)==0)
                {
                    b.image_akaros.pos_img_affiche.x+=200;
                }
                if (i<4)
                {
                    (b.background_ocean).pos_img_affiche.x-=10;
                    b.camera.x+=10;
                    b.e.vertical1.pos_img_ecran.x+=10;
                    b.e.vertical2.pos_img_ecran.x+=10;
                    b.e.vertical3.pos_img_ecran.x+=10;
                    b.e.vertical4.pos_img_ecran.x+=10;
                    b.e.vertical5.pos_img_ecran.x+=10;
                    b.e.vertical6.pos_img_ecran.x+=10;
                    b.e.horizontal1.pos_img_ecran.x+=10;
                    b.e.horizontal2.pos_img_ecran.x+=10;
                    b.e.horizontal3.pos_img_ecran.x+=10;
                }
                else
                {
                    (b.background_ocean).pos_img_affiche.x-=15;
                    b.e.vertical1.pos_img_ecran.x+=15;
                    b.e.vertical2.pos_img_ecran.x+=15;
                    b.e.vertical3.pos_img_ecran.x+=15;
                    b.e.vertical4.pos_img_ecran.x+=15;
                    b.e.vertical5.pos_img_ecran.x+=15;
                    b.e.vertical6.pos_img_ecran.x+=15;
                    b.e.horizontal1.pos_img_ecran.x+=15;
                    b.e.horizontal2.pos_img_ecran.x+=15;
                    b.e.horizontal3.pos_img_ecran.x+=15;
                    b.camera.x+=15;
                }
                mob=(SDL_GetTicks())%250;
                if (mob>230)
                {
                    mob=0;
                    animerBack(&b);
                }
                (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
                afficherBack2p(b,screen);
                projectiles_movement(&b, p1.direction,0);
                SDL_Flip(screen);
            }
        }
        i=-1;
        if (akaros_animation>28)
        {
            if (akaros_animation%2==0)
            {
                akaros_animation=1;
                b.image_akaros.pos_img_affiche.x=800;
            }
            else
            {
                akaros_animation=0;
                b.image_akaros.pos_img_affiche.x=1000;
            }
        }
        akaros_animation+=2;
        (b.background_ocean).pos_img_affiche.x-=20;
        b.e.vertical1.pos_img_ecran.x+=20;
        b.e.vertical2.pos_img_ecran.x+=20;
        b.e.vertical3.pos_img_ecran.x+=20;
        b.e.vertical4.pos_img_ecran.x+=20;
        b.e.vertical5.pos_img_ecran.x+=20;
        b.e.vertical6.pos_img_ecran.x+=20;
        b.e.horizontal1.pos_img_ecran.x+=20;
        b.e.horizontal2.pos_img_ecran.x+=20;
        b.e.horizontal3.pos_img_ecran.x+=20;
        b.camera.x+=20;
        mob=(SDL_GetTicks())%250;
        projectiles_movement(&b, p1.direction,0);
        if (mob>230)
        {
            mob=0;
            animerBack(&b);
        }
        (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        afficherBack2p(b,screen);
        SDL_Flip(screen);
        if ((b.background_ocean).pos_img_affiche.x<background_position_before_akaros+600)
        {
            b.image_akaros.pos_img_ecran.x+=15;
        }
    }
    for (i=0; i<=9; i++)
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
        if (mob>230)
        {
            mob=0;
            animerBack(&b);
        }
        (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        afficherBack2p(b,screen);
        projectiles_movement(&b, p1.direction,0);
        SDL_Flip(screen);
        SDL_Delay(80);
    }

    rand_akaros_spot= rand() % 400+100;
    b.akaros_appearance=0;
    //to fix the position of the first three vertical projectiles after akaros aniamtion's end
    /*b.e.vertical1.pos_img_ecran.x=14331;
    b.e.vertical2.pos_img_ecran.x=14493;
    b.e.vertical3.pos_img_ecran.x=14623;*/
}
if (b.akaros_appearance==0)
{
    if (pos<15060 && akaros_stop==0)  b.image_akaros.pos_img_ecran.x=p1.image_perso.pos_img_ecran.x+600;
    else
    {
        akaros_stop=1;
    }
    if (akaros_stop==1)
    {
        if ((b.image_akaros.pos_img_ecran.x+b.image_akaros.pos_img_ecran.h/2)<p1.image_perso.pos_img_ecran.x /*&& b.akaros_direction==-1*/)
        {
            b.akaros_direction=-1;
        }
    }
}
if (collision_item(b.rose2.pos_img_ecran, p1.image_perso.pos_img_ecran) && b.rose2_is_collected==0)
{
    b.rose2_is_collected=1;
    rose_counter++;
}
else if (collision_item(b.heart1.pos_img_ecran, p1.image_perso.pos_img_ecran) && b.heart1_is_collected==0)
{
    b.heart1_is_collected=1;
    p1.nb_vies++;
		initialiser_audio_score(music_collect);
}
else if (collision_item(b.heart2.pos_img_ecran, p1.image_perso.pos_img_ecran) && b.heart2_is_collected==0)
{
    b.heart2_is_collected=1;
    p1.nb_vies++;
		initialiser_audio_score(music_collect);
}
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack2p(b,screen);
if (pos>1600 && pos<2400)
{
    where_am_i.pos_img_ecran.x=p1.image_perso.pos_img_ecran.x+40;
    SDL_BlitSurface(where_am_i.img,NULL,screen,&where_am_i.pos_img_ecran);
}
animerPerso(&p1); if (cpt2%8==0) animerPerso(&p); cpt2++;
now = SDL_GetTicks();
projectiles_movement(&b, p1.direction,0);
if (now - before >=250)
{
    animerBack (&b);
    before = now;
    (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
}
SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x+=725;
		SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x-=725;
sprintf(char_rose_counter, "  %d", rose_counter);
afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
	afficher_texte_custom(screen, txt_rose_counter_p2,char_rose_counter);
afficherPerso(p1,screen);
afficherPerso(p,screen);
MAJMinimap(p1,&m,b.camera,redimensionnement);
nowtime=SDL_GetTicks();
nowtime-=last;
afficher (m,screen);
afficher_texte_temps(screen,txte,nowtime);
cpt++;
if(cpt==10)
{
    p1.posSprite.x+=80;
    if(p1.posSprite.x==640) p1.posSprite.x=0;
    cpt=0;
}
float_items(&b, &angle,frequency,amplitude,speed/2);
SDL_Flip(screen);
SDL_EnableKeyRepeat(0,0);
if (!(b.garbage_moving.pos_img_affiche.x==0 || b.garbage_moving.pos_img_affiche.x==800))
{
    int rand_garbage_moving = rand() % 5 - 2;
    if (cpt_garbage_moving>0)
    {
        b.garbage_moving.pos_img_ecran.x+=(4 + rand_garbage_moving);
        cpt_garbage_moving--;
    }
    else if (cpt_garbage_moving<=0)
    {
        b.garbage_moving.pos_img_ecran.x+=(-4 + rand_garbage_moving);
        cpt_garbage_moving--;
    }
    if (cpt_garbage_moving<-100) cpt_garbage_moving=100;
}
if(p1.acceleration > 0 )
{
    p1.acceleration-=0.1;
}
if (reversed==0)
{
    if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && up==0 )
    {
        p1.image_perso.pos_img_ecran.y-=5;
    }
    else if(p1.image_perso.pos_img_ecran.y<695)
    {
        p1.image_perso.pos_img_ecran.y+=5;
    }
    if(p1.image_perso.pos_img_ecran.y<635) up=1;
    else if(p1.image_perso.pos_img_ecran.y>685) up=0;
    if(p1.image_perso.pos_img_ecran.y<695) air =1;
    else air=0;
}
else if (reversed==1)
{
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE && up == 0)
    {
        p1.image_perso.pos_img_ecran.y += 5;
    }
    else if (p1.image_perso.pos_img_ecran.y > 50)
    {
        p1.image_perso.pos_img_ecran.y -= 5;
    }
    if (p1.image_perso.pos_img_ecran.y > 110) up = 1;
    else if (p1.image_perso.pos_img_ecran.y < 60) up = 0;
    if (p1.image_perso.pos_img_ecran.y > 50) air = 1;
    else air = 0;
}
if(p1.mana<3) p1.mana+=0.003;
if(p1.acceleration > 0 ) p1.acceleration-=0.1;
//
if(dust_effect!=0)
{

    SDL_BlitSurface(b.image_dust.img,&b.image_dust.pos_img_affiche,screen,&b.image_dust.pos_img_ecran);
    SDL_Flip(screen);
    if(cpt%3==0)
    {
        if (p1.image_perso.pos_img_ecran.x>640 && b.level==1) b.image_dust.pos_img_ecran.x-=15;
        b.image_dust.pos_img_affiche.y=0;
        b.image_dust.pos_img_affiche.x+=65;
        dust_effect++;
    }
    if(dust_effect>10)
    {
        dust_effect=0;
        b.image_dust.pos_img_affiche.x=0;
    }
}
//
}

}

//fin new player
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_d )
{
    if (reversed==0) p.direction=1;
    else p.direction=2;
    dte=1;
    while(dte)
    {
    
	grace++;
	if (grace>50 && (collision(b.e.vertical1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical3.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal2.pos_img_ecran, p.image_perso.pos_img_ecran)|| collision_horizontal(b.e.horizontal3.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical4.pos_img_ecran, p.image_perso.pos_img_ecran)|| collision(b.e.vertical5.pos_img_ecran, p.image_perso.pos_img_ecran)|| collision(b.e.vertical6.pos_img_ecran, p.image_perso.pos_img_ecran)))
        {
		  p.nb_vies--; grace=0;
        }
		if(grace<50) 
	   {     
		if (a%4==0) p.sprite=IMG_Load("images/spritefinal.png");
		else if (a%4==1) p.sprite=IMG_Load("images/gracesprite30.png");
		else if (a%4==2) p.sprite=IMG_Load("images/gracesprite60.png");
		else if (a%4==3) p.sprite=IMG_Load("images/gracesprite30.png");
	   }	
	   else if (grace<55) {p.sprite=IMG_Load("images/spritefinal.png"); p.image_perso.img=IMG_Load("images/marioplayer.png");}
       a++;
    //event
    SDL_PollEvent(&event);
    if(event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_d )
    {
            dte=0;
    }

	else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LSHIFT && p.acceleration<1)
	{
	p.acceleration=15; dust_effect=1; b.image_dust.pos_img_ecran.x=p.image_perso.pos_img_ecran.x;b.image_dust.pos_img_ecran.y=p.image_perso.pos_img_ecran.y+70-27;
	}
    
//pos
    pos=p.image_perso.pos_img_ecran.x+(b.background_ocean).pos_img_affiche.x;
    
    if(pos<limit && pos>362 && p.image_perso.pos_img_ecran.x>362 && b.level==1)
    { 
	b.acceleration=p.acceleration;
    	scrolling(&b, 1, dt);
    }
    else if(!(b.level==2 && p.image_perso.pos_img_ecran.x>1350))
    {
         movePerso(&p,dt);
    }
    if (pos>9743 && is_reversed==0)
    {
        p.direction=2;
        reversed=1;
        is_reversed=1;
        p.image_perso.pos_img_ecran.x+=50;
        p.image_perso.pos_img_ecran.y=50;
    }
    else if (pos>11300){reversed=0; p.direction=1;}
    if (pos>6760 && pos<6860 && shelly==0) dte=0;  
    else if (pos>16050 && end==1) 
	{
	p.direction=0;
	
	end_game(&b.background_ocean,&b.image_akaros, 1, 300, b, screen,p);
	end=0;
	}
    else if (pos>13086 && b.akaros_appearance==1)
	{
	background_position_before_akaros=(b.background_ocean).pos_img_affiche.x;
		while(b.image_akaros.pos_img_ecran.x>1450)
		{
            		(b.background_ocean).pos_img_affiche.x+=35;
			b.image_akaros.pos_img_ecran.x-=35;
        		b.camera.x-=35;
			b.e.vertical1.pos_img_ecran.x-=35;
			b.e.vertical2.pos_img_ecran.x-=35;
			b.e.vertical3.pos_img_ecran.x-=35;
			b.e.vertical4.pos_img_ecran.x-=35;
			b.e.vertical5.pos_img_ecran.x-=35;
			b.e.vertical6.pos_img_ecran.x-=35;
			b.e.horizontal1.pos_img_ecran.x-=35;
			b.e.horizontal2.pos_img_ecran.x-=35;
			b.e.horizontal3.pos_img_ecran.x-=35;
           	 mob=(SDL_GetTicks())%250;
        	if (mob>230) {mob=0; animerBack(&b);}
			(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        	afficherBack2p(b,screen);
        	SDL_Flip(screen);
		}
		SDL_Delay(500);
		shake_image(&b.background_ocean, 10, 250,b,screen);
		b.akaros_is_shown=1;
       	mob=(SDL_GetTicks())%250;
        if (mob>230) {mob=0; animerBack(&b);}
		(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        afficherBack2p(b,screen);
        SDL_Flip(screen);
		SDL_Delay(500);
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
        	if (mob>230) {mob=0; animerBack(&b);}
			(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
            afficherBack2p(b,screen);
        	SDL_Flip(screen);
			akaros_animation+=2;
		}
		for (i=0;i<=2;i++)
		{
			b.image_akaros.pos_img_affiche.x-=200;
			mob=(SDL_GetTicks())%250;
            if (mob>230) {mob=0; animerBack(&b);}
			(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        	afficherBack2p(b,screen);
        	SDL_Flip(screen);
			SDL_Delay(80);
		}
		b.image_akaros.pos_img_affiche.x=0;
		b.image_akaros.pos_img_affiche.y=0;
        afficherBack2p(b,screen);
        SDL_Flip(screen);
		shake_image(&b.image_akaros, 5, 30,b,screen);
		b.akaros_shake=1;
		shake_image(&b.image_akaros, 5, 150,b,screen);
		akaros_animation=0;
		b.image_akaros.pos_img_affiche.x=200;
		b.image_akaros.pos_img_affiche.y=400;
		while ((b.background_ocean).pos_img_affiche.x>background_position_before_akaros+15)
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
						b.camera.x+=10;
						b.e.vertical1.pos_img_ecran.x+=10;
						b.e.vertical2.pos_img_ecran.x+=10;
						b.e.vertical3.pos_img_ecran.x+=10;
						b.e.vertical4.pos_img_ecran.x+=10;
						b.e.vertical5.pos_img_ecran.x+=10;
						b.e.vertical6.pos_img_ecran.x+=10;
						b.e.horizontal1.pos_img_ecran.x+=10;
						b.e.horizontal2.pos_img_ecran.x+=10;
						b.e.horizontal3.pos_img_ecran.x+=10;
					}
					else
					{
						(b.background_ocean).pos_img_affiche.x-=15;
						b.e.vertical1.pos_img_ecran.x+=15;
						b.e.vertical2.pos_img_ecran.x+=15;
						b.e.vertical3.pos_img_ecran.x+=15;
						b.e.vertical4.pos_img_ecran.x+=15;
						b.e.vertical5.pos_img_ecran.x+=15;
						b.e.vertical6.pos_img_ecran.x+=15;
						b.e.horizontal1.pos_img_ecran.x+=15;
						b.e.horizontal2.pos_img_ecran.x+=15;
						b.e.horizontal3.pos_img_ecran.x+=15;
						b.camera.x+=15;
					}
                   			mob=(SDL_GetTicks())%250;
					if (mob>230) {mob=0; animerBack(&b);}
					(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
					afficherBack2p(b,screen);
				 	projectiles_movement(&b, p.direction,0);
					SDL_Flip(screen);
				}
			}
			i=-1;
			if (akaros_animation>28)
			{
				if (akaros_animation%2==0) {akaros_animation=1; b.image_akaros.pos_img_affiche.x=800;}
				else {akaros_animation=0; b.image_akaros.pos_img_affiche.x=1000; }
			}
			akaros_animation+=2;
			(b.background_ocean).pos_img_affiche.x-=20;
			b.e.vertical1.pos_img_ecran.x+=20;
			b.e.vertical2.pos_img_ecran.x+=20;
			b.e.vertical3.pos_img_ecran.x+=20;
			b.e.vertical4.pos_img_ecran.x+=20;
			b.e.vertical5.pos_img_ecran.x+=20;
			b.e.vertical6.pos_img_ecran.x+=20;
			b.e.horizontal1.pos_img_ecran.x+=20;
			b.e.horizontal2.pos_img_ecran.x+=20;
			b.e.horizontal3.pos_img_ecran.x+=20;
            b.camera.x+=20;
            mob=(SDL_GetTicks())%250;
			projectiles_movement(&b, p.direction,0);
            if (mob>230) {mob=0; animerBack(&b);}
			(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
            afficherBack2p(b,screen);
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
                if (mob>230) {mob=0; animerBack(&b);}
				(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
				afficherBack2p(b,screen);
				projectiles_movement(&b, p.direction,0);
				SDL_Flip(screen);
				SDL_Delay(80);
			}
		
		rand_akaros_spot= rand() % 400+100;
		b.akaros_appearance=0;
    //to fix the position of the first three vertical projectiles after akaros aniamtion's end
	/*b.e.vertical1.pos_img_ecran.x=14331;
	b.e.vertical2.pos_img_ecran.x=14493;
	b.e.vertical3.pos_img_ecran.x=14623;*/
	}
	if (b.akaros_appearance==0)
	{
	if (pos<15060 && akaros_stop==0)  b.image_akaros.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+600;
	else 
	{	
		akaros_stop=1;	
	}
	if (akaros_stop==1){
	if ((b.image_akaros.pos_img_ecran.x+b.image_akaros.pos_img_ecran.h/2)<p.image_perso.pos_img_ecran.x /*&& b.akaros_direction==-1*/)
		{		
			b.akaros_direction=-1;
		}}
	}
	if (collision_item(b.rose2.pos_img_ecran, p.image_perso.pos_img_ecran) && b.rose2_is_collected==0) 
	{
		b.rose2_is_collected=1;
		rose_counter++;
	}
	else if (collision_item(b.heart1.pos_img_ecran, p.image_perso.pos_img_ecran) && b.heart1_is_collected==0) 
	{
		b.heart1_is_collected=1;
		p.nb_vies++;
		initialiser_audio_score(music_collect);
	}
	else if (collision_item(b.heart2.pos_img_ecran, p.image_perso.pos_img_ecran) && b.heart2_is_collected==0) 
	{
		b.heart2_is_collected=1;
		p.nb_vies++;
		initialiser_audio_score(music_collect);
	}
	(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
    afficherBack2p(b,screen);
    if (pos>1600 && pos<2400)  
    {
        where_am_i.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+40;
	SDL_BlitSurface(where_am_i.img,NULL,screen,&where_am_i.pos_img_ecran);
    }
    animerPerso(&p); if (cpt2%8==0) animerPerso(&p1); cpt2++;
	now = SDL_GetTicks();
 	projectiles_movement(&b, p.direction,0);
    if (now - before >=250)
    {
    animerBack (&b);
    before = now; (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
    }
	SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
	SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x+=725;
		SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x-=725;
	sprintf(char_rose_counter, "  %d", rose_counter);
	afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
	afficher_texte_custom(screen, txt_rose_counter_p2,char_rose_counter);
    afficherPerso(p,screen);
	afficherPerso(p1,screen);
    MAJMinimap(p,&m,b.camera,redimensionnement);
	nowtime=SDL_GetTicks();nowtime-=last;
    afficher (m,screen);
    afficher_texte_temps(screen,txte,nowtime);
    cpt++;
    if(cpt==10)
        {
            p.posSprite.x+=80;
            if(p.posSprite.x==640) p.posSprite.x=0;
            cpt=0;
        }
	float_items(&b, &angle,frequency,amplitude,speed/2);
    SDL_Flip(screen);
    SDL_EnableKeyRepeat(0,0);
	if (!(b.garbage_moving.pos_img_affiche.x==0 || b.garbage_moving.pos_img_affiche.x==800))
	{
		int rand_garbage_moving = rand() % 5 - 2;
		if (cpt_garbage_moving>0) {b.garbage_moving.pos_img_ecran.x+=(4 + rand_garbage_moving); cpt_garbage_moving--;}
		else if (cpt_garbage_moving<=0) {b.garbage_moving.pos_img_ecran.x+=(-4 + rand_garbage_moving);cpt_garbage_moving--; }
		if (cpt_garbage_moving<-100) cpt_garbage_moving=100;
	}
	if(p.acceleration > 0 ) {p.acceleration-=0.1;}
	if (reversed==0)
    {
        if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && up==0 )
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
    }
    else if (reversed==1)
    {
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE && up == 0)
    {
        p.image_perso.pos_img_ecran.y += 5;  
    }
    else if (p.image_perso.pos_img_ecran.y > 50)  
    {
        p.image_perso.pos_img_ecran.y -= 5;  
    }
    if (p.image_perso.pos_img_ecran.y > 110) up = 1;  
    else if (p.image_perso.pos_img_ecran.y < 60) up = 0; 
    if (p.image_perso.pos_img_ecran.y > 50) air = 1; 
    else air = 0;
    }
     if(p.mana<3) p.mana+=0.003;
     if(p.acceleration > 0 ) p.acceleration-=0.1;
	//
	if(dust_effect!=0)
	{
	
	SDL_BlitSurface(b.image_dust.img,&b.image_dust.pos_img_affiche,screen,&b.image_dust.pos_img_ecran);SDL_Flip(screen);
	if(cpt%3==0)
	{
	if (p.image_perso.pos_img_ecran.x>640 && b.level==1) b.image_dust.pos_img_ecran.x-=15;
	b.image_dust.pos_img_affiche.y=0;
	b.image_dust.pos_img_affiche.x+=65;
	dust_effect++;
	}
	if(dust_effect>10){dust_effect=0; b.image_dust.pos_img_affiche.x=0;}
	}
	//     
	}
     
}
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_q/*&& p.image_perso.pos_img_ecran.x<1300*/)//MOVE RIGHT
{
    if (reversed==0) p.direction=-1;
    else p.direction=3;
    dte=1;
    while(dte)
    {

    grace++;
	if (collision_item(b.rose1.pos_img_ecran, p.image_perso.pos_img_ecran) && b.rose1_is_collected==0)
	{
		b.rose1_is_collected=1;
		rose_counter++;
		show=1;
 		
	}
	else if (collision_item(b.rose2.pos_img_ecran, p.image_perso.pos_img_ecran) && b.rose2_is_collected==0)
	{
		b.rose2_is_collected=1;
		rose_counter++;
	}
	else if (collision_item(b.rose3.pos_img_ecran, p.image_perso.pos_img_ecran) && b.rose3_is_collected==0)
	{
		b.rose3_is_collected=1;
		rose_counter++;
	}
	else if (collision_item(b.heart1.pos_img_ecran, p.image_perso.pos_img_ecran) && b.heart1_is_collected==0)
	{
		b.heart1_is_collected=1;
		p.nb_vies++;
		initialiser_audio_score(music_collect);
	}
	else if (collision_item(b.heart2.pos_img_ecran, p.image_perso.pos_img_ecran) && b.heart2_is_collected==0)
	{
		b.heart2_is_collected=1;
		p.nb_vies++;
		initialiser_audio_score(music_collect);
	}
		if (grace>50 && (collision(b.e.vertical1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical3.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal3.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical4.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical5.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical6.pos_img_ecran, p.image_perso.pos_img_ecran) ))
    {
	if(grace>50) {p.nb_vies--; grace=0;}
    }
	if(grace<50)
	{
		if (a%4==0) p.sprite=IMG_Load("images/spritefinal.png");
		else if (a%4==1) p.sprite=IMG_Load("images/gracesprite30.png");
		else if (a%4==2) p.sprite=IMG_Load("images/gracesprite60.png");
		else if (a%4==3) p.sprite=IMG_Load("images/gracesprite30.png");
	}
	 else if (grace<55) {p.sprite=IMG_Load("images/spritefinal.png"); p.image_perso.img=IMG_Load("images/marioplayer.png");}
	a++;
	SDL_PollEvent(&event);
	if(event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_q )
        {
            dte=0;
        }
	else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LSHIFT && p.acceleration<1) {p.acceleration=15; dust_effect=1;b.image_dust.pos_img_ecran.x=p.image_perso.pos_img_ecran.x;b.image_dust.pos_img_ecran.y=p.image_perso.pos_img_ecran.y+70-27;}
	if (b.akaros_appearance==0)
	{
		if (akaros_stop==0)
		{
		b.image_akaros.pos_img_affiche.y=400;
		b.image_akaros.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+600;
		if (akaros_animation>20) b.image_akaros.pos_img_affiche.x=800;
		else  b.image_akaros.pos_img_affiche.x=1000;
		akaros_animation+=2;
		if (akaros_animation>40) akaros_animation=0;
		}

	}
	
        cpt++;
        if(cpt==10)
        {
            p.posSprite.x+=80;
            if(p.posSprite.x==640) p.posSprite.x=0;
            cpt=0;
        }
        SDL_EnableKeyRepeat(0,0);
        if(p.image_perso.pos_img_ecran.x<= 50 && (b.background_ocean).pos_img_affiche.x>0  && b.level !=2)
        {
        b.acceleration=p.acceleration;
	    scrolling(&b, -1, dt);
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
        if (akaros_stop==1)
        {
        if ((b.image_akaros.pos_img_ecran.x+b.image_akaros.pos_img_ecran.h/2)>p.image_perso.pos_img_ecran.x /*&& b.akaros_direction==-1*/)
            {
                b.akaros_direction=1;
            }
        }
if(p.acceleration > 0 ) {p.acceleration-=0.1;}
if (reversed==0)
    {
        if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && up==0 )
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
    }
        else if (reversed==1)
    {
   if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE && up == 0)
    {
        p.image_perso.pos_img_ecran.y += 5;  
    }
    else if (p.image_perso.pos_img_ecran.y > 50)  
    {
        p.image_perso.pos_img_ecran.y -= 5;  
    }
    if (p.image_perso.pos_img_ecran.y > 110) up = 1;  
    else if (p.image_perso.pos_img_ecran.y < 60) up = 0; 
    if (p.image_perso.pos_img_ecran.y > 50) air = 1; 
    else air = 0;
    }
        (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        now = SDL_GetTicks();
        if (now - before >=250)
        {
         animerBack (&b);
         before = now; (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        }
        afficherBack2p(b,screen);
        pos=p.image_perso.pos_img_ecran.x+(b.background_ocean).pos_img_affiche.x;
        if (pos>1600 && pos<2400)
        {
            where_am_i.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+40;
            SDL_BlitSurface(where_am_i.img,NULL,screen,&where_am_i.pos_img_ecran);
        }        
	animerPerso(&p); if (cpt2%8==0) animerPerso(&p1); cpt2++;
        projectiles_movement(&b, p.direction,0);
        float_items(&b, &angle,frequency,amplitude,speed/2);
        SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran);
        SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x+=725;
		SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x-=725;
        sprintf(char_rose_counter, "  %d", rose_counter);
        afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
	afficher_texte_custom(screen, txt_rose_counter_p2,char_rose_counter);
        afficherPerso(p,screen);
	afficherPerso(p1,screen);
        MAJMinimap(p,&m,b.camera,redimensionnement);
        nowtime=SDL_GetTicks();nowtime-=last;
        afficher (m,screen);
        afficher_texte_temps(screen,txte,nowtime);
        SDL_Flip(screen);
	if(p.mana<3) p.mana+=0.003;
        if(p.acceleration > 0 ) p.acceleration-=0.1;
	//
	if(dust_effect!=0)
	{
	
	SDL_BlitSurface(b.image_dust.img,&b.image_dust.pos_img_affiche,screen,&b.image_dust.pos_img_ecran);SDL_Flip(screen);
	if(cpt%3==0)
	{
	if (p.image_perso.pos_img_ecran.x<60 && b.level==1) b.image_dust.pos_img_ecran.x+=15;
	b.image_dust.pos_img_affiche.y=27;
	b.image_dust.pos_img_affiche.x+=65;
	dust_effect++;
	}
	if(dust_effect>10){dust_effect=0; b.image_dust.pos_img_affiche.x=0;}
	}
	//    
    }

}
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LEFT/*&& p1.image_perso.pos_img_ecran.x<1300*/)//MOVE RIGHT
{
    if (reversed==0) p1.direction=-1;
    else p1.direction=3;
    dte=1;
    while(dte)
    {
        grace++;
        if (collision_item(b.rose1.pos_img_ecran, p1.image_perso.pos_img_ecran) && b.rose1_is_collected==0)
        {
            b.rose1_is_collected=1;
            rose_counter++;
        }
        else if (collision_item(b.rose2.pos_img_ecran, p1.image_perso.pos_img_ecran) && b.rose2_is_collected==0)
        {
            b.rose2_is_collected=1;
            rose_counter++;
        }
        else if (collision_item(b.rose3.pos_img_ecran, p1.image_perso.pos_img_ecran) && b.rose3_is_collected==0)
        {
            b.rose3_is_collected=1;
            rose_counter++;
        }
        else if (collision_item(b.heart1.pos_img_ecran, p1.image_perso.pos_img_ecran) && b.heart1_is_collected==0)
        {
            b.heart1_is_collected=1;
            p1.nb_vies++;
		initialiser_audio_score(music_collect);
        }
        else if (collision_item(b.heart2.pos_img_ecran, p1.image_perso.pos_img_ecran) && b.heart2_is_collected==0)
        {
            b.heart2_is_collected=1;
            p1.nb_vies++;
		initialiser_audio_score(music_collect);
        }
        if (grace>50 && (collision(b.e.vertical1.pos_img_ecran, p1.image_perso.pos_img_ecran) || collision(b.e.vertical2.pos_img_ecran, p1.image_perso.pos_img_ecran) || collision(b.e.vertical3.pos_img_ecran, p1.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal1.pos_img_ecran, p1.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal2.pos_img_ecran, p1.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal3.pos_img_ecran, p1.image_perso.pos_img_ecran) || collision(b.e.vertical4.pos_img_ecran, p1.image_perso.pos_img_ecran)  || collision(b.e.vertical5.pos_img_ecran, p1.image_perso.pos_img_ecran)  || collision(b.e.vertical6.pos_img_ecran, p1.image_perso.pos_img_ecran) ))
        {
            if(grace>50)
            {
                p1.nb_vies--;
                grace=0;
              
            }
        }
        if(grace<50)
        {
            if (a%4==0) p1.sprite=IMG_Load("images/spritefinal.png");
            else if (a%4==1) p1.sprite=IMG_Load("images/gracesprite30.png");
            else if (a%4==2) p1.sprite=IMG_Load("images/gracesprite60.png");
            else if (a%4==3) p1.sprite=IMG_Load("images/gracesprite30.png");
        }
        else if (grace<55)
        {
            p1.sprite=IMG_Load("images/spritefinal.png");
            p1.image_perso.img=IMG_Load("images/marioplayer.png");
        }
        a++;
        SDL_PollEvent(&event);
        if(event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_LEFT )
        {
            dte=0;
        }
        else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LSHIFT && p1.acceleration<1)
        {
            p1.acceleration=15;
            dust_effect=1;
            b.image_dust.pos_img_ecran.x=p1.image_perso.pos_img_ecran.x;
            b.image_dust.pos_img_ecran.y=p1.image_perso.pos_img_ecran.y+70-27;
        }
        if (b.akaros_appearance==0)
        {
            if (akaros_stop==0)
            {
                b.image_akaros.pos_img_affiche.y=400;
                b.image_akaros.pos_img_ecran.x=p1.image_perso.pos_img_ecran.x+600;
                if (akaros_animation>20) b.image_akaros.pos_img_affiche.x=800;
                else  b.image_akaros.pos_img_affiche.x=1000;
                akaros_animation+=2;
                if (akaros_animation>40) akaros_animation=0;
            }

        }

        cpt++;
        if(cpt==10)
        {
            p1.posSprite.x+=80;
            if(p1.posSprite.x==640) p1.posSprite.x=0;
            cpt=0;
        }
        SDL_EnableKeyRepeat(0,0);
	dx=0.5*(b.acceleration)*dt*dt + 5*dt;
        if(p1.image_perso.pos_img_ecran.x<= 800 && (b.background_ocean).pos_img_affiche.x>0  && b.level !=2)
        {
            b.acceleration=p1.acceleration;
            if (b.back2.pos_img_affiche.x>0)b.back2.pos_img_affiche.x-=dx;
        }
        else if (p1.image_perso.pos_img_ecran.x>782)
        {
            movePerso(&p1,dt);
        }
        if (!(b.garbage_moving.pos_img_affiche.x==0 || b.garbage_moving.pos_img_affiche.x==800))
        {
            int rand_garbage_moving = rand() % 5 - 2;
            if (cpt_garbage_moving>0)
            {
                b.garbage_moving.pos_img_ecran.x+=(4 + rand_garbage_moving);
                cpt_garbage_moving--;
            }
            else if (cpt_garbage_moving<=0)
            {
                b.garbage_moving.pos_img_ecran.x+=(-4 + rand_garbage_moving);
                cpt_garbage_moving--;
            }
            if (cpt_garbage_moving<-100) cpt_garbage_moving=100;	
        }
        if (akaros_stop==1)
        {
            if ((b.image_akaros.pos_img_ecran.x+b.image_akaros.pos_img_ecran.h/2)>p1.image_perso.pos_img_ecran.x /*&& b.akaros_direction==-1*/)
            {
                b.akaros_direction=1;
            }
        }
        if(p1.acceleration > 0 )
        {
            p1.acceleration-=0.1;
        }
        if (reversed==0)
        {
            if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && up==0 )
            {
                p1.image_perso.pos_img_ecran.y-=5;
            }
            else if(p1.image_perso.pos_img_ecran.y<695)
            {
                p1.image_perso.pos_img_ecran.y+=5;
            }
            if(p1.image_perso.pos_img_ecran.y<635) up=1;
            else if(p1.image_perso.pos_img_ecran.y>685) up=0;
            if(p1.image_perso.pos_img_ecran.y<695) air =1;
            else air=0;
        }
        else if (reversed==1)
        {
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE && up == 0)
            {
                p1.image_perso.pos_img_ecran.y += 5;
            }
            else if (p1.image_perso.pos_img_ecran.y > 50)
            {
                p1.image_perso.pos_img_ecran.y -= 5;
            }
            if (p1.image_perso.pos_img_ecran.y > 110) up = 1;
            else if (p1.image_perso.pos_img_ecran.y < 60) up = 0;
            if (p1.image_perso.pos_img_ecran.y > 50) air = 1;
            else air = 0;
        }
        (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        now = SDL_GetTicks();
        if (now - before >=250)
        {
            animerBack (&b);
            before = now;
            (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        }
        afficherBack2p(b,screen);
        pos=p1.image_perso.pos_img_ecran.x+(b.background_ocean).pos_img_affiche.x;
        if (pos>1600 && pos<2400)
        {
            where_am_i.pos_img_ecran.x=p1.image_perso.pos_img_ecran.x+40;
            SDL_BlitSurface(where_am_i.img,NULL,screen,&where_am_i.pos_img_ecran);
        } 
        animerPerso(&p1); if (cpt2%8==0) animerPerso(&p); cpt2++;
        projectiles_movement(&b, p1.direction,0);
        float_items(&b, &angle,frequency,amplitude,speed/2);
        SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran);
        SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x+=725;
		SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x-=725;
        sprintf(char_rose_counter, "  %d", rose_counter);
        afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
afficher_texte_custom(screen, txt_rose_counter_p2,char_rose_counter);
        afficherPerso(p,screen);
        afficherPerso(p1,screen);
        MAJMinimap(p1,&m,b.camera,redimensionnement);
        nowtime=SDL_GetTicks();
        nowtime-=last;
        afficher (m,screen);
        afficher_texte_temps(screen,txte,nowtime);
        SDL_Flip(screen);
        if(p1.mana<3) p1.mana+=0.003;
        if(p1.acceleration > 0 ) p1.acceleration-=0.1;
        //
        if(dust_effect!=0)
        {

            SDL_BlitSurface(b.image_dust.img,&b.image_dust.pos_img_affiche,screen,&b.image_dust.pos_img_ecran);
            SDL_Flip(screen);
            if(cpt%3==0)
            {
                if (p1.image_perso.pos_img_ecran.x<60 && b.level==1) b.image_dust.pos_img_ecran.x+=15;
                b.image_dust.pos_img_affiche.y=27;
                b.image_dust.pos_img_affiche.x+=65;
                dust_effect++;
            }
            if(dust_effect>10)
            {
                dust_effect=0;
                b.image_dust.pos_img_affiche.x=0;
            }
        }
        //
    }

}

if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && air ==0)
{
   is_saut=1;
   while(is_saut)
	{
	if (collision_item(b.rose2.pos_img_ecran, p.image_perso.pos_img_ecran) && b.rose2_is_collected==0) 
	{
		b.rose2_is_collected=1;
		rose_counter++;
	}
	else if (collision_item(b.heart1.pos_img_ecran, p.image_perso.pos_img_ecran) && b.heart1_is_collected==0) 
	{
		b.heart1_is_collected=1;
		p.nb_vies++;
		initialiser_audio_score(music_collect);
	}
else if (grace>50 && (collision(b.e.vertical1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical3.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal3.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical4.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical5.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical6.pos_img_ecran, p.image_perso.pos_img_ecran) ))
        {
		if(grace>50) {p.nb_vies--; grace=0;}
        }
	if(grace<50) 
	{
		if (a%4==0) p.sprite=IMG_Load("images/spritefinal.png");
		else if (a%4==1) p.sprite=IMG_Load("images/gracesprite30.png");
		else if (a%4==2) p.sprite=IMG_Load("images/gracesprite60.png");
		else if (a%4==3) p.sprite=IMG_Load("images/gracesprite30.png");
	}	
	else if (grace<60) p.sprite=IMG_Load("images/spritefinal.png");
	a++;
    if (reversed==0) p.image_perso.pos_img_ecran.y-=5;
    else if (reversed==1) p.image_perso.pos_img_ecran.y+=5;
     (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
     afficherBack2p(b,screen);
     projectiles_movement(&b,p.direction,1);
     SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
     SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x+=725;
		SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x-=725;
     sprintf(char_rose_counter, "  %d", rose_counter);
     afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
afficher_texte_custom(screen, txt_rose_counter_p2,char_rose_counter);
     afficherPerso(p,screen);
     afficherPerso(p1,screen);
     MAJMinimap(p,&m,b.camera,redimensionnement);
     nowtime=SDL_GetTicks();nowtime-=last;
     afficher(m,screen);
     afficher_texte_temps(screen,txte,nowtime);
	     if (pos>1600 && pos<2400)  
   	 {
        where_am_i.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+40;
	SDL_BlitSurface(where_am_i.img,NULL,screen,&where_am_i.pos_img_ecran);
   	 }
     SDL_Flip(screen);
    SDL_PollEvent(&event);
    if((event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_SPACE ) || (p.image_perso.pos_img_ecran.y<635 && reversed==0) || (p.image_perso.pos_img_ecran.y>120 && reversed==1) ) {is_saut=0;}
    else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_d) p.image_perso.pos_img_ecran.x+=5;
    else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_q) p.image_perso.pos_img_ecran.x-=5;
	}
}
 else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_m)
{
	cpt_mus++;
	if (cpt_mus==4) cpt_mus=1;
	audio_level1(b.level1_music,volume_music, cpt_mus);
}

/*
if (pos>6755 && pos<6855 && shelly==0)
 {SDL_EventState(SDL_MOUSEMOTION,SDL_DISABLE);
shelly=1;
 posbeforeshelly=pos;
audio_level1(b.level2_music,0, cpt_mus);
 afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame34); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame35); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame36); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame37); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame38); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame39); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame40); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame41); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame42); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame43); SDL_Flip(screen); SDL_Delay(delay);
  SDL_Delay(550);b.level=2;
  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame43); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame42); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame41); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame40); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame39); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame38); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame37); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame36); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame35); SDL_Flip(screen); SDL_Delay(delay);  afficherBack2p(b,screen);
  afficher_imageBMP(screen,frog.frame34); SDL_Flip(screen); SDL_Delay(delay);
  p.image_perso.pos_img_ecran.x=1300;
  p.image_perso.pos_img_ecran.y=80; 
  audio_level2(b.level2_music,volume_music);
} */
else if((event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=150 && event.motion.y>=50 && event.motion.x<=305 && event.motion.x>=50)) || (SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE))
{
    initialiser_audiobref(mus);
    multiplayer=0;
    fleche=0;
    boucle_play=0;//quitter play
    initialiser_audio_mainmenu(music,volume_music);
    break;
}

else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_UP)
{
 p.image_perso.pos_img_ecran.y-=120;
}
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_DOWN)
{
  p.image_perso.pos_img_ecran.y+=120;
}
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_RIGHT)
{
p.image_perso.pos_img_ecran.x+=120;
}
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LEFT)
{
p.image_perso.pos_img_ecran.x-=120;
}
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_h)
            {
		p.score+=10; p1.score+=10;
		p.nb_vies--; p1.nb_vies--;
		//shake_image(&p.image_vies,5,5,b,screen); shake_image(&p1.image_vies,5,5,b,screen);
		if(p.mana>1)p.mana--; if(p.mana>1)p1.mana--;
                SDL_Delay(100);

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
	b.e.vertical1.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical2.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical3.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical4.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical5.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical6.pos_img_ecran.x-=thirdleveltransition;
	b.e.horizontal1.pos_img_ecran.x-=thirdleveltransition;
	b.e.horizontal2.pos_img_ecran.x-=thirdleveltransition;
	b.e.horizontal3.pos_img_ecran.x-=thirdleveltransition;
	
	b.rose1.pos_img_ecran.x-=thirdleveltransition;
	b.rose2.pos_img_ecran.x-=thirdleveltransition;
	b.rose3.pos_img_ecran.x-=thirdleveltransition;
	b.heart1.pos_img_ecran.x-=thirdleveltransition;
	b.heart2.pos_img_ecran.x-=thirdleveltransition;

	b.image_snake.pos_img_ecran.x-=thirdleveltransition; 
        mob=(SDL_GetTicks())%250;
        if (mob>230) mob=0;
        if (mob==0)
        {
            animerBack(&b);
        }(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        afficherBack2p(b,screen);
        SDL_Flip(screen);
	if (thirdleveltransition>30) thirdleveltransition-=2;
	if (thirdleveltransition>20) thirdleveltransition--;
	else if (thirdleveltransition>10) thirdleveltransition-=0.75;
	else if (thirdleveltransition>5) thirdleveltransition-=0.5;
    }
    limit=15378;
}	
if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e)
{
    SDL_EnableKeyRepeat(0,0);
    az=2;
    pos=p.image_perso.pos_img_ecran.x+b.background_ocean.pos_img_affiche.x;
    if (pos>2800 && pos<2990)
    {
        if (dial1==-1)
        {
            dial1=1;
            SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
            dial_text = "sss...";
            typewriter(dial_text,screen,280,event);
            while (dial1==1)
            {
                SDL_PollEvent(&event);
                if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e) dial1=-1;
            }
        }
        else
        {
            while (dial1!=0)
            {
                if (az>2) 
		{  
		SDL_WaitEvent(&event);
		if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e)
                {
                    az++;
                    dial1=az;
                }
		}
		else az++;
                switch(dial1)
                {
                case 1:
                    break;
                case 2:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "Excuse me, sir. Where am I?";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 3:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "IN Terravale, A KINGDOM LOST IN TIME,";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "A land of beauty and grace, now laid to grime,";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 4:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "What happened here?";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 5:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "A tragedy befell this once-great place, ";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "Leaving ruins and sorrow, and a somber space.";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 6:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "Do you know what caused the fall?";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 7:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "Alas, the tales of old are faded and worn, ";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "And the reason for the ruin remains forlorn.";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 8:
                    dial1=0;
                    break;
                }
                afficherBack2p(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x+=725;
		SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x-=725;
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
	afficher_texte_custom(screen, txt_rose_counter_p2,char_rose_counter);
                afficherPerso(p,screen); afficherPerso(p1,screen);
                if (dial1!=0) dial1=1;

            }
        }
        dial1=-1;
    }
    else if (p.image_perso.pos_img_ecran.x>100 && p.image_perso.pos_img_ecran.x<300 && b.level==3)
    {
        if (dial2==-1)
        {
            dial2=1;
            SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
            dial_text = "Go, Hurry...";
            typewriter(dial_text,screen,280,event);
            while (dial2==1)
            {
                SDL_WaitEvent(&event);
                if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e) dial2=-1;
            }
        }
        else
        {
            while (dial2!=0)
            {
		if (az>2) 
		{  
		SDL_WaitEvent(&event);
		if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e)
                {
                    az++;
                    dial2=az;
                }
		}
		else az++;
                switch(dial2)
                {
                case 1:
                    break;
                case 2:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "Adventurer, we cross paths once more,";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 3:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "What happened?" ;
                    typewriter(dial_text,screen,280,event);
                    break;
                case 4:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "Amidst uncharted realms, I dared to tread,";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "But with one misstep, I plummeted instead.";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 6:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "Why did you come down here?";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 7:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "I heard a cry of anguish, a sound so dire, ";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "My heart swelled with the weight of someone's dire";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 8:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "Wilt thou venture to the caverns deep, ";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "And seek the source of these tears to keep?";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 9:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "Fear not for me, I shall manage alone. ";
                    typewriter(dial_text,screen,280,event);
                case 10:
                    dial2=0;
                    break;
                }
                afficherBack2p(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x+=725;
		SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x-=725;
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
		afficher_texte_custom(screen, txt_rose_counter_p2,char_rose_counter);
                afficherPerso(p,screen); afficherPerso(p1,screen);
                if (dial2!=0) dial2=1;
            }
        }
        dial2=-1;
    }
    else if (p.image_perso.pos_img_ecran.x>50 && p.image_perso.pos_img_ecran.x<250 && b.level==2)
    {
	if (mob>100 && mob<150)
	{
	b.image_shelly.pos_img_affiche.x+=72;
	if (b.image_shelly.pos_img_affiche.x>800) b.image_shelly.pos_img_affiche.x=0;
	}
        if (dial3==-1)
        {
            dial3=1;
            SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
            dial_text = "Please...";
            typewriter(dial_text,screen,280,event);
            while (dial3==1)
            {
                SDL_PollEvent(&event);
                if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e) dial3=-1;
            }
        }else
        {
            while (dial3!=0)
            {
		if (az>2) 
		{  
		SDL_WaitEvent(&event);
		if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e)
                {
                    az++;
                    dial3=az;
                }
		}
		else az++;
                switch(dial3)
                {
                case 1:
                    break;
                case 2:
                    SDL_BlitSurface(image_shelly_box.img,NULL,screen,&image_shelly_box.pos_img_ecran);
                    dial_text =  "Help! Please, someone, help me!";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 3:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "Hey, are you okay?" ;
                    typewriter(dial_text,screen,280,event);
                    break;
                case 4:
                    SDL_BlitSurface(image_shelly_box.img,NULL,screen,&image_shelly_box.pos_img_ecran);
                    dial_text = "Who...who are you?";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 6:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "I'm here to save you. What happened?";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 7:
                    SDL_BlitSurface(image_shelly_box.img,NULL,screen,&image_shelly_box.pos_img_ecran);
                    dial_text ="No time to explain,";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "I don't know how much longer I can hold on.";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 8:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "Don't worry, I'll get you out of there. ";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "Hmm, this looks like some kind of puzzle.";
                    typewriter(dial_text,screen,340,event);
                    dial_text = "I'll have to solve it to release you.";
                    typewriter(dial_text,screen,400,event);
                    break;
                case 9:
                    SDL_BlitSurface(image_shelly_box.img,NULL,screen,&image_shelly_box.pos_img_ecran);
                    dial_text = "Please hurry,";
                    typewriter(dial_text,screen,280,event);
                case 10:
                    dial3=0;
                    break;
                }
                afficherBack2p(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x+=725;
		SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x-=725;
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
		afficher_texte_custom(screen, txt_rose_counter_p2,char_rose_counter);
                afficherPerso(p,screen); afficherPerso(p1,screen);
                if (dial3!=0) dial3=1;
            }
        }
        dial3=-1;
    }
    else if (pos>7555 && pos<7700)
    {
		image_snake_box.pos_img_ecran.y=300;
		image_you_box.pos_img_ecran.y=300;
                while (dial4!=0)
                {  
                if (az>2) 
		{  
		SDL_WaitEvent(&event);
		if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e)
                {
                    az++;
                    dial4=az;
                }
		}
		else az++;
                switch(dial4)
                {
                case 1:
                    break;
                case 2:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text =  "My path seems to have led me astray.";
                    typewriter(dial_text,screen,348,event);
                    dial_text = "I am seeking a way to save the world";
                    typewriter(dial_text,screen,408,event);
		    dial_text = "from an impending doom.";
                    typewriter(dial_text,screen,468,event);
                    break;
                case 3:
                    SDL_BlitSurface(image_snake_box.img,NULL,screen,&image_snake_box.pos_img_ecran);
                    dial_text = "Greetingsss... wanderer." ;
                    typewriter(dial_text,screen,348,event);
		    dial_text = "It seems you have ssstumbled upon";
                    typewriter(dial_text,screen,408,event);
		    dial_text = "a riddle in your journey.";
                    typewriter(dial_text,screen,468,event);
                    break;
                case 4:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = " A riddle?";
                    typewriter(dial_text,screen,348,event);
                    break;
                case 6:
                    SDL_BlitSurface(image_snake_box.img,NULL,screen,&image_snake_box.pos_img_ecran);
                    dial_text = "Indeed. I am the keeper of thisss ancient forest,";
                    typewriter(dial_text,screen,348,event);
		    dial_text = "and only those who can solve my puzzle may passs...";
                    typewriter(dial_text,screen,408,event);
                    break;
                case 7:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text ="I accept your challenge. ";
                    typewriter(dial_text,screen,348,event);
                    dial_text = "What is this puzzle you speak of?";
                    typewriter(dial_text,screen,408,event);
                    break;
                case 8:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "My puzzle is sssimple, yet complex.";
                    typewriter(dial_text,screen,348,event);
                    dial_text = "You must tell me the answer to this riddle:";
                    typewriter(dial_text,screen,408,event);
                    break;
	        case 9:   
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);     
		    dial_text ="riddle ici";
                    typewriter(dial_text,screen,348,event);	
		    SDL_Delay(250);
		    dial_text ="      fire            ice             water";
                    typewriter(dial_text,screen,458,event);
		    break;
                case 10:
                    dial4=0;
                    break;
                }
                afficherBack2p(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x+=725;
		SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		image_rose_counter.pos_img_ecran.x-=725;
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
		afficher_texte_custom(screen, txt_rose_counter_p2,char_rose_counter);
                afficherPerso(p,screen); afficherPerso(p1,screen);
                if (dial4!=0) dial4=1;
            }
        }
        dial4=-1;image_you_box.pos_img_ecran.y=232;
    }


else if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_l)
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

else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LSHIFT && p.acceleration<1 && p.mana>1) {if(ability_counter>0) ability_counter--;
if(ability_counter==0)
{
colorquest2.r=56;
colorquest2.g=168;
colorquest2.b=74;
q2=1;
}
sprintf(quest10times, "%d times", ability_counter);
txt2quest2 = TTF_RenderText_Solid(questfont, quest10times, colorquest2);
txtquest2 = TTF_RenderText_Solid(questfont, "-use your ability", colorquest2);
p.mana--;p.acceleration=15;dust_effect=1;b.image_dust.pos_img_ecran.x=p.image_perso.pos_img_ecran.x;b.image_dust.pos_img_ecran.y=p.image_perso.pos_img_ecran.y+70-27;}
else if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_j){p.image_perso.pos_img_ecran.x+=150;p.image_perso.pos_img_ecran.y-=150;}
    }
    if (reversed==0) {p.direction=0;p1.direction=0;}
    else if (reversed==1) {p.direction=4;p1.direction=4;}
   }
 }//mtaa multiplayer
else // debut 1p 
{
if(new_game==1)
{
	chargement(&p,&b,&rose_counter);	
     	b.camera.x=b.background_ocean.pos_img_affiche.x;
	if (b.background_ocean.pos_img_affiche.x>8200) {limit=15378; b.m=2;}
     	(b.garbage_moving.pos_img_ecran.x)-=b.background_ocean.pos_img_affiche.x;
	(b.image_junkpit.pos_img_ecran.x)-=b.background_ocean.pos_img_affiche.x;
	(b.image_akaros.pos_img_ecran.x)-=b.background_ocean.pos_img_affiche.x;
	b.e.vertical1.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.e.vertical2.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.e.vertical3.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.e.vertical4.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.e.vertical5.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.e.vertical6.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.e.horizontal1.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.e.horizontal2.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.e.horizontal3.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;

	b.rose1.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.rose2.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.rose3.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.heart1.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.heart2.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;

	b.image_snake.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.image_napta.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.image_bard.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
b.image_bee.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
b.image_pt.pos_img_ecran.x-=b.background_ocean.pos_img_affiche.x;
	b.mini.pos_img_affiche.x+=b.background_ocean.pos_img_affiche.x/4;
}
    audio_level1(b.level1_music,volume_music, mx);
    afficherBack(b,screen);
    SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
    SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
    sprintf(char_rose_counter, "  %d", rose_counter);
    afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
    afficherPerso(p,screen);
    MAJMinimap(p,&m,b.camera,redimensionnement);
    afficher (m,screen);
    SDL_EventState(SDL_MOUSEMOTION,SDL_DISABLE);//**A REMOVER** SI POSSIBLE
    SDL_Flip(screen);
///////////////********************************************************************************fin msayeb
  last=SDL_GetTicks();
  while(boucle_play)
  {    
 	 if(event.motion.y<=150 && event.motion.y>=50 && event.motion.x<=305 && event.motion.x>=50)
         {
   	 afficher_imageBTN(screen,bouton.clicked_back);
  	 }
  	 else afficher_imageBTN(screen,bouton.unclicked_back);
	if (gracing>400) gracing=0;
	gracing++;
	//if(p.image_perso.pos_img_ecran.y<695 && reversed==0) p.image_perso.pos_img_ecran.y+=5;
	//else if(p.image_perso.pos_img_ecran.y>50 && reversed==1) p.image_perso.pos_img_ecran.y-=5;
	grace++;
	if (collision(b.e.vertical1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical3.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical4.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical5.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical6.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal3.pos_img_ecran, p.image_perso.pos_img_ecran))
        {
		if(grace>50) {p.nb_vies--;		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10) damage_variable=1; grace=0;}
        }
	if(grace<50) 
	{
		if (gracing%4==0) p.image_perso.img=IMG_Load("images/marioplayer.png");
		else if (gracing%4==1) p.image_perso.img=IMG_Load("images/idlegrace30.png");
		else if (gracing%4==2) p.image_perso.img=IMG_Load("images/idlegrace60.png");
		else if (gracing%4==3) p.image_perso.img=IMG_Load("images/idlegrace30.png");
	}	
	else if (grace<55) {p.sprite=IMG_Load("images/spritefinal.png"); p.image_perso.img=IMG_Load("images/marioplayer.png");}
        nowtime=SDL_GetTicks();
        nowtime-=last;
        mob=(SDL_GetTicks())%250;
	if (mob>230) mob=0;
	else if (mob>100 && mob<150)
	{
	b.image_shelly.pos_img_affiche.x+=72;
	if (b.image_shelly.pos_img_affiche.x>800) b.image_shelly.pos_img_affiche.x=0;
	}
        if (mob==0)
        {
            animerBack(&b);
	    (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
	}
	cpt2++;
	if (cpt2>8) cpt2=0; 
	if (cpt2==0) animerPerso(&p);

	//if(p.image_perso.pos_img_ecran.y<560 && reversed==0) p.image_perso.pos_img_ecran.y+=5;
	 if( p.image_perso.pos_img_ecran.y>50 && reversed==1) p.image_perso.pos_img_ecran.y-=5;
	if (!(b.garbage_moving.pos_img_affiche.x==0 || b.garbage_moving.pos_img_affiche.x==800))
	{
	rand_garbage_moving = rand() % 5 - 2;
	if (cpt_garbage_moving>0) {b.garbage_moving.pos_img_ecran.x+=(4 + rand_garbage_moving); cpt_garbage_moving--;}
	else if (cpt_garbage_moving<=0) {b.garbage_moving.pos_img_ecran.x+=(-4 + rand_garbage_moving);cpt_garbage_moving--; }
	if (cpt_garbage_moving<-100) cpt_garbage_moving=100;
	}
 	projectiles_movement(&b,p.direction,0);
	if (akaros_stop==0) float_items(&b, &angle,frequency,amplitude,speed);
	else if (akaros_stop==1)
	{
	if ((b.image_akaros.pos_img_ecran.x+b.image_akaros.pos_img_ecran.h/2)<p.image_perso.pos_img_ecran.x)
		{		
			b.akaros_direction=-1;
		}
	}
pos=p.image_perso.pos_img_ecran.x+(b.background_ocean).pos_img_affiche.x;

 if (pos>6760 && pos<6860 && shelly==0)
{
    dte=0;
    SDL_EventState(SDL_MOUSEMOTION,SDL_DISABLE);
    shelly=1;
    posbeforeshelly=pos;
    float qsd=10;
    int dan=1;
    int cpt_fall=0;
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
  SDL_Delay(250); b.level=3;
  p.image_perso.pos_img_ecran.y=-70;
  p.image_perso.pos_img_ecran.x=710;
  p.image_perso.pos_img_affiche.x=0;
  p.image_perso.pos_img_affiche.y=168;    
  image_drop_dust.pos_img_affiche.h=65;
  image_drop_dust.pos_img_affiche.w=160;
  b.image_bard.pos_img_ecran.x=200;
  b.image_bard.pos_img_ecran.y=2495;
  b.image_bard.pos_img_affiche.y=66;
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
  afficherBack(b,screen);										 	 SDL_BlitSurface(b.background_forest.img,&b.background_forest.pos_img_affiche,screen,&b.background_forest.pos_img_ecran);
afficherPerso(p,screen);
SDL_Flip(screen);
mx=2;
audio_level1(b.level1_music,volume_music, mx);
while (dan)
{
 	dte=0;
	if (p.image_perso.pos_img_ecran.y<400) { p.image_perso.pos_img_ecran.y+=qsd/2;}
	else if (b.background_fall.pos_img_affiche.y<1824) { b.background_fall.pos_img_affiche.y+=qsd; b.image_bard.pos_img_ecran.y-=qsd;}
	else if (p.image_perso.pos_img_ecran.y<660) {p.image_perso.pos_img_ecran.y+=qsd;}
	else if (p.image_perso.pos_img_affiche.x<1080) 
	     {
		dan+=qsd;
		if (cpt_fall%20==0) p.image_perso.pos_img_affiche.x+=60;
		cpt_fall++;
		if (cpt_fall%20==0) image_drop_dust.pos_img_affiche.x+=160;
	     }
	else {p.image_perso.pos_img_affiche.x=0; p.image_perso.pos_img_affiche.y=0; dan=0;}

afficherBack(b,screen);										SDL_BlitSurface(b.background_forest.img,&b.background_forest.pos_img_affiche,screen,&b.background_forest.pos_img_ecran);
if (cpt_fall>0) SDL_BlitSurface(image_drop_dust.img,&image_drop_dust.pos_img_affiche,screen,&image_drop_dust.pos_img_ecran);
afficherPerso(p,screen);
SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
sprintf(char_rose_counter, "  %d", rose_counter);
afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
nowtime=SDL_GetTicks();nowtime-=last;
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
SDL_Delay(2);
}
}
else if (p.image_perso.pos_img_ecran.x>1100 && b.level==3)
{
    int second_level_transition=0;
    float c=8;
    while(second_level_transition<800)
    {
	if (b.background_forest.pos_img_ecran.y<750 && p.image_perso.pos_img_ecran.y>-50)
	p.image_perso.pos_img_ecran.y-=c;
        b.background_forest.pos_img_ecran.y-=c;
        b.background_fall.pos_img_affiche.y+=c*1.1;
	b.image_bard.pos_img_ecran.y-=c;
	b.image_shelly.pos_img_ecran.y-=c;
afficherBack(b,screen);									SDL_BlitSurface(b.background_forest.img,&b.background_forest.pos_img_affiche,screen,&b.background_forest.pos_img_ecran);
afficherPerso(p,screen);
SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
sprintf(char_rose_counter, "  %d", rose_counter);
afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
nowtime=SDL_GetTicks();nowtime-=last;
afficher_texte_temps(screen,txte,nowtime);
SDL_BlitSurface(b.image_shelly.img,&b.image_shelly.pos_img_affiche,screen,&b.image_shelly.pos_img_ecran);
        SDL_Flip(screen);
	second_level_transition+=c;
	if (c>20) c--;
	else if (c>10) c-=0.75;
	else if (c>5) c-=0.5;
    }
    b.level=2;
    b.background_ocean.pos_img_ecran.y=0;
    (b.tab_frames[b.i]).pos_img_ecran.y=0;
  b.image_bard.pos_img_ecran.x=5120;
  b.image_bard.pos_img_ecran.y=520;
  b.image_bard.pos_img_affiche.y=0;
}
        afficherBack(b,screen);
if(tab==1)
{
SDL_BlitSurface(quest_box.img,NULL,screen,&quest_box.pos_img_ecran);
SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
SDL_BlitSurface(txtquest1, NULL, screen, &txtquest1pos);
SDL_BlitSurface(txt2quest1, NULL, screen, &txt2quest1pos);
SDL_BlitSurface(txtquest2, NULL, screen, &txtquest2pos);
SDL_BlitSurface(txt2quest2, NULL, screen, &txt2quest2pos);
SDL_BlitSurface(txtquest3, NULL, screen, &txtquest3pos);
SDL_BlitSurface(txtquest4, NULL, screen, &txtquest4pos);
SDL_BlitSurface(txt2quest4, NULL, screen, &txt2quest4pos);
SDL_BlitSurface(txtquest5, NULL, screen, &txtquest5pos);

SDL_BlitSurface(txt2quest5, NULL, screen, &txt2quest5pos);
SDL_BlitSurface(txtquest6, NULL, screen, &txtquest6pos);
SDL_BlitSurface(txt2quest6, NULL, screen, &txt2quest6pos);
SDL_BlitSurface(txtcompletion, NULL, screen, &txtcompletionpos);
SDL_BlitSurface(txttabtohide, NULL, screen, &txttabtohidepos);
}
else {
SDL_BlitSurface(txttabtoshow, NULL, screen, &txttabtoshowpos);
SDL_BlitSurface(txttabtoshowquests, NULL, screen, &txttabtoshowquestspos);}

    if (pos>1600 && pos<2400)  
    {
        where_am_i.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+40;
        where_am_i.pos_img_ecran.y=p.image_perso.pos_img_ecran.y-60;
	SDL_BlitSurface(where_am_i.img,NULL,screen,&where_am_i.pos_img_ecran);
    }	
	SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
	SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
	sprintf(char_rose_counter, "  %d", rose_counter);
	afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
        afficherPerso(p,screen);
	MAJMinimap(p,&m,b.camera,redimensionnement);
        afficher (m,screen);
        afficher_texte_temps(screen,txte,nowtime);
	SDL_Flip(screen);
	if(p.mana<3) p.mana+=0.003;
        if(p.acceleration > 0 ) p.acceleration-=0.1;
	if (b.level==2 || b.level==3) SDL_Delay(50);
if (b.level==1)
{
       	if (collision_ground(&b.mask,p.image_perso.pos_img_ecran, b)==0 && collision_ladder(&b.mask,p.image_perso.pos_img_ecran, b)==0)        
	{ 
	    int bla;
	    bla++;            
	    p.image_perso.pos_img_ecran.y+=5;
        }
	else if (collision_ground(&b.mask,p.image_perso.pos_img_ecran, b)==1) 
	{ground_y=p.image_perso.pos_img_ecran.y;}
}
else if(b.level==2)
{
if (collision_ground(&b.mask2,p.image_perso.pos_img_ecran, b)==0 && collision_ladder(&b.mask2,p.image_perso.pos_img_ecran, b)==0)        
	{ 
	    int bla;
	    bla++;            
	    p.image_perso.pos_img_ecran.y+=5;
        }
	else if (collision_ground(&b.mask2,p.image_perso.pos_img_ecran, b)==1) 
	{ground_y=p.image_perso.pos_img_ecran.y;}
}
	if(p.image_perso.pos_img_ecran.y<ground_y-60) up=1; //635
        else if(p.image_perso.pos_img_ecran.y>ground_y-10) up=0;
        if(p.image_perso.pos_img_ecran.y<ground_y) air =1;
        else air=0;
	if (pos>7100 && b.m==0) b.m=1;
pos=p.image_perso.pos_img_ecran.x+(b.background_ocean).pos_img_affiche.x;
if(pos>8808 && pos<8867 && p.image_perso.pos_img_ecran.y>690)
{
dte=0;
p.direction=0;
p.image_perso.pos_img_ecran.y-=8;
while(p.image_perso.pos_img_affiche.h>0)
{
p.image_perso.pos_img_affiche.h--;
p.image_perso.pos_img_ecran.y++;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
}
p.image_perso.pos_img_ecran.y=418;
(b.background_ocean).pos_img_affiche.x-=120;
p.image_perso.pos_img_ecran.x=50;
 
	b.mini.pos_img_affiche.x-=120/3.9;
	b.mask.pos_img_affiche.x-=120; 
        b.camera.x-=120;
	b.e.vertical1.pos_img_ecran.x+=120;
	b.e.vertical2.pos_img_ecran.x+=120;
	b.e.vertical3.pos_img_ecran.x+=120;
	b.e.vertical4.pos_img_ecran.x+=120;
	b.e.vertical5.pos_img_ecran.x+=120;
	b.e.vertical6.pos_img_ecran.x+=120;
	b.e.horizontal1.pos_img_ecran.x+=120;
	b.e.horizontal2.pos_img_ecran.x+=120;
	b.e.horizontal3.pos_img_ecran.x+=120;
	
	b.rose1.pos_img_ecran.x+=120;
	b.rose2.pos_img_ecran.x+=120;
	b.rose3.pos_img_ecran.x+=120;
	b.heart1.pos_img_ecran.x+=120;
	b.heart2.pos_img_ecran.x+=120;

	b.image_snake.pos_img_ecran.x+=120; 
	b.image_napta.pos_img_ecran.x+=120;
while(p.image_perso.pos_img_affiche.h<90)
{
p.image_perso.pos_img_affiche.h++;
p.image_perso.pos_img_ecran.y--;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
}
}
else if(pos>8455 && pos<8500 && p.image_perso.pos_img_ecran.y<160 && p.image_perso.pos_img_ecran.y>150)
{
dte=0;
p.direction=0;
p.image_perso.pos_img_ecran.y-=16;
while(p.image_perso.pos_img_affiche.h>0)
{
p.image_perso.pos_img_affiche.h--;
p.image_perso.pos_img_ecran.y++;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
}	
p.image_perso.pos_img_ecran.y=-30;
p.image_perso.pos_img_affiche.h=90;
p.image_perso.pos_img_ecran.x=650;
(b.background_ocean).pos_img_affiche.x+=140;
 
	b.mini.pos_img_affiche.x+=140/3.9;
	b.mask.pos_img_affiche.x+=140; 
        b.camera.x+=140;
	b.e.vertical1.pos_img_ecran.x-=140;
	b.e.vertical2.pos_img_ecran.x-=140;
	b.e.vertical3.pos_img_ecran.x-=140;
	b.e.vertical4.pos_img_ecran.x-=140;
	b.e.vertical5.pos_img_ecran.x-=140;
	b.e.vertical6.pos_img_ecran.x-=140;
	b.e.horizontal1.pos_img_ecran.x-=140;
	b.e.horizontal2.pos_img_ecran.x-=140;
	b.e.horizontal3.pos_img_ecran.x-=140;
	(b.garbage_moving.pos_img_ecran.x)-=10;
	(b.image_junkpit.pos_img_ecran.x)-=10;
	
	b.rose1.pos_img_ecran.x-=140;
	b.rose2.pos_img_ecran.x-=140;
	b.rose3.pos_img_ecran.x-=140;
	b.heart1.pos_img_ecran.x-=140;
	b.heart2.pos_img_ecran.x-=140;

	b.image_snake.pos_img_ecran.x-=140; 
	b.image_napta.pos_img_ecran.x-=140;

}
else if(pos>9715 && pos< 9765 && p.image_perso.pos_img_ecran.y<415 && p.image_perso.pos_img_ecran.y>405)
{
dte=0;
p.direction=0;
p.image_perso.pos_img_ecran.y-=16;
while(p.image_perso.pos_img_affiche.h>0)
{
p.image_perso.pos_img_affiche.h--;
p.image_perso.pos_img_ecran.y++;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
}
p.direction=4;
reversed=1;
is_reversed=1;
p.image_perso.pos_img_ecran.x+=130;	
p.image_perso.pos_img_ecran.y=55;
animerPerso(&p);
p.image_perso.pos_img_affiche.y+=90;
while(p.image_perso.pos_img_affiche.h<90)
{
p.image_perso.pos_img_affiche.h+=2;
p.image_perso.pos_img_affiche.y-=2;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
}
}
if (pos>11315 && pos<11350 && p.image_perso.pos_img_ecran.y<400) {
reversed=0;
p.direction=4;
animerPerso(&p);
while(p.image_perso.pos_img_affiche.h>0)
{
p.image_perso.pos_img_affiche.h-=2;
p.image_perso.pos_img_affiche.y+=2;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
}
p.direction=0;
reversed=0;
is_reversed=0;
p.image_perso.pos_img_ecran.y=700;
p.image_perso.pos_img_ecran.x=740;

	(b.background_ocean).pos_img_affiche.x+=304;
 
	b.mini.pos_img_affiche.x+=304/3.9;
	b.mask.pos_img_affiche.x+=304; 
        b.camera.x+=304;
	b.e.vertical1.pos_img_ecran.x-=304;
	b.e.vertical2.pos_img_ecran.x-=304;
	b.e.vertical3.pos_img_ecran.x-=304;
	b.e.vertical4.pos_img_ecran.x-=304;
	b.e.vertical5.pos_img_ecran.x-=304;
	b.e.vertical6.pos_img_ecran.x-=304;
	b.e.horizontal1.pos_img_ecran.x-=304;
	b.e.horizontal2.pos_img_ecran.x-=304;
	b.e.horizontal3.pos_img_ecran.x-=304;
	(b.garbage_moving.pos_img_ecran.x)-=304;
	(b.image_junkpit.pos_img_ecran.x)-=304;
	b.rose1.pos_img_ecran.x-=304;
	b.rose2.pos_img_ecran.x-=304;
	b.rose3.pos_img_ecran.x-=304;
	b.heart1.pos_img_ecran.x-=304;
	b.heart2.pos_img_ecran.x-=304;

	b.image_snake.pos_img_ecran.x-=304; 
	b.image_napta.pos_img_ecran.x-=304;

animerPerso(&p);
while(p.image_perso.pos_img_affiche.h<90)
{
p.image_perso.pos_img_affiche.h++;
p.image_perso.pos_img_ecran.y--;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
}
}
cptbee+=2;
if (sqrt(pow((b.image_bee.pos_img_ecran.x-p.image_perso.pos_img_ecran.x),2)+pow((b.image_bee.pos_img_ecran.y-p.image_perso.pos_img_ecran.y),2))<400)
{
if (cptbee>=495 && cptbee<=496)
  {
    pos_att_beex=p.image_perso.pos_img_ecran.x;
    if(p.image_perso.pos_img_ecran.x>645) pos_att_beex-=20;
    pos_att_beey=p.image_perso.pos_img_ecran.y+p.image_perso.pos_img_ecran.h;
  }
else if (cptbee>500)
  {
    nah=1;
    cptbee=0;
b.image_bee.pos_img_affiche.x=0;
b.image_bee.pos_img_affiche.y=130;
  }
if (nah==1)
{
if(b.image_bee.pos_img_ecran.x+120<pos_att_beex)
    b.image_bee.pos_img_ecran.x+=10;
if(b.image_bee.pos_img_ecran.y+p.image_perso.pos_img_ecran.h<pos_att_beey)
    b.image_bee.pos_img_ecran.y+=5;
if (b.image_bee.pos_img_ecran.y+p.image_perso.pos_img_ecran.h>=pos_att_beey)  
{
if (abs(b.image_bee.pos_img_ecran.x+120-p.image_perso.pos_img_ecran.x)<30) {p.nb_vies--;		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10)damage_variable=1; hornetdamage=1;}
nah=0;
}
}
else 
{
b.image_bee.pos_img_affiche.y=0;
	if (b.image_bee.pos_img_ecran.x-p.image_perso.pos_img_ecran.x<-160)
	{
		b.image_bee.pos_img_ecran.x+=2;
	}
	if (b.image_bee.pos_img_ecran.x-p.image_perso.pos_img_ecran.x>-160)
	{
		b.image_bee.pos_img_ecran.x-=2;
	}
	if ((b.image_bee.pos_img_ecran.y-p.image_perso.pos_img_ecran.y)>-80-130)
	{
		b.image_bee.pos_img_ecran.y-=2;
	}
}
}
else if (cptbee>495) cptbee=495;

if ((nowtime/1000)<61)
{
secondsforrose=60-(nowtime/1000);
sprintf(quest60s, "Rose within %ds", secondsforrose);
if (b.rose1_is_collected==1) 
	{
		colorquest1.r=56;
		colorquest1.g=168;
		colorquest1.b=74;
		q1=1;
	} 
txtquest1 = TTF_RenderText_Solid(questfont, "-collect your first", colorquest1);
txt2quest1 = TTF_RenderText_Solid(questfont, quest60s, colorquest1);
}
else if((nowtime/1000<=62))
{
	if (b.rose1_is_collected==0) 
	{
		colorquest1.r=228;
		colorquest1.g=63;
		colorquest1.b=63;
	}
	else
	{
		colorquest1.r=56;
		colorquest1.g=168;
		colorquest1.b=74;
		q1=1;
	} 
txtquest1 = TTF_RenderText_Solid(questfont, "-collect your first", colorquest1);
txt2quest1 = TTF_RenderText_Solid(questfont, quest60s, colorquest1);
}
if (q1==1 && q2==1 && bonusint!=3)
{
bonusint=3;
sprintf(bonuschar, "X%.0f", bonusint);
colorbonus.r=255;
colorbonus.g=121;
colorbonus.b=0;
bonusfont = TTF_OpenFont("fonts/Middle.ttf", 64);
txtbonuspos.x=1339;
txtbonuspos.y=196;
txtbonus = TTF_RenderText_Solid(bonusfont, bonuschar, colorbonus);
}
else if (q1==1 && q2==0 && bonusint==1)
{
bonusint=1.5;
sprintf(bonuschar, "X%.1f", bonusint);
colorbonus.r=255;
colorbonus.g=201;
colorbonus.b=14;
txtbonuspos.x=1300;
txtbonus = TTF_RenderText_Solid(bonusfont, bonuschar, colorbonus);
}
else if (q2==1 && q1==0 && bonusint==1)
{
bonusint=1.5;
sprintf(bonuschar, "X%.1f", bonusint);
colorbonus.r=255;
colorbonus.g=201;
colorbonus.b=14;
txtbonuspos.x=1300;
txtbonus = TTF_RenderText_Solid(bonusfont, bonuschar, colorbonus);
}
if (hornetdamage==1 && pos<14384)
{
colorquest5.r=228;
colorquest5.g=63;
colorquest5.b=63;
txtquest5 = TTF_RenderText_Solid(questfont, "-unharmed by the", colorquest5);
txt2quest5 = TTF_RenderText_Solid(questfont, "vengeful hornet", colorquest5);
}
//labyrinth
if(p.nb_vies<=0 )//mazesamer
{
old_mx=mx;
   mx=6;
audio_level1(b.level1_music,volume_music, mx);
     //lfouk image maze,maze_mask,tawfik;
    SDL_EnableKeyRepeat(1,1);
    int mazecpt=1;  float sam=8;
    int col=1;
    float ag=0.0f;
    //fade in image white
    //fade in text welcome to realm between life and death etc
    initialiser_image_background(&maze_mask,750,1300,"images/maze_mask.png");
    initialiser_image_background(&maze,600,1150,"images/maze.png");
    initialiser_image_bouton(&tawfik, 200,200,"images/tawfik_maze.png");
    int j;
    for(j=0;j<25;j++)
     {SDL_BlitSurface(b.image_white05.img,NULL, screen,&b.image_white05.pos_img_ecran); SDL_Flip(screen); SDL_Delay(5);}
    fade_in3(image_death.img,b.image_white100,screen,image_death.pos_img_ecran);
    SDL_Delay(500);
if (welcback==0)
{
    while(image_death.pos_img_ecran.y>11)
    {
	image_death.pos_img_ecran.y-=sam;
	SDL_BlitSurface(b.image_white100.img,NULL, screen,&b.image_white100.pos_img_ecran); 
	SDL_BlitSurface(image_death.img,NULL,screen,&image_death.pos_img_ecran);
	SDL_Flip(screen);SDL_Delay(10);
	if (image_death.pos_img_ecran.y<200 && sam>1) sam-=0.25;
    }
}
    while(mazecpt)
    {
        SDL_PollEvent(&event);
        if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_d && collision_maze_right(&maze_mask,tawfik.pos_img_ecran)==0) tawfik.pos_img_ecran.x+=3;
        else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_s && collision_maze_down(&maze_mask,tawfik.pos_img_ecran)==0) tawfik.pos_img_ecran.y+=3;
        else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_q && collision_maze_left(&maze_mask,tawfik.pos_img_ecran)==0) tawfik.pos_img_ecran.x-=3;
        else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_z && collision_maze_up(&maze_mask,tawfik.pos_img_ecran)==0) tawfik.pos_img_ecran.y-=3;
        SDL_BlitSurface(maze.img, NULL, screen, &maze.pos_img_ecran);        
        SDL_BlitSurface(tawfik.img, NULL, screen, &tawfik.pos_img_ecran);   
	SDL_BlitSurface(image_death.img,NULL,screen,&image_death.pos_img_ecran);   
	if (welcback==0) image_shade.pos_img_ecran.y = 320 + sin(ag) * 8;
	else image_shade.pos_img_ecran.x = 625 + sin(ag) * 8;
	ag += 0.07;
	if (ag > 2 * M_PI) {
        ag -= 2 * M_PI;
    	}
if(collision_shade(image_shade.pos_img_ecran, tawfik.pos_img_ecran)==1)
{
col=0;
}
if(col==1) SDL_BlitSurface(image_shade.img, NULL, screen, &image_shade.pos_img_ecran);             
        SDL_Flip(screen); 
        if(tawfik.pos_img_ecran.x>1180 && tawfik.pos_img_ecran.y>710) {
if (showsam!=-1) {showsam=1;initialiser_audio_score(music_score);}
p.score-=500; p.nb_vies=3; SDL_EnableKeyRepeat(0,0); mazecpt=0;}
    
    }//while maze end
image_shade.pos_img_ecran.x=555;
if (welcback==0) image_death.img=IMG_Load("images/death_txt2.png");
image_death.pos_img_ecran.x=94;
image_death.pos_img_ecran.y=29;
welcback=1;
mx=old_mx;
audio_level1(b.level1_music,volume_music, mx);
image_shade.pos_img_ecran.y-=10;
}


//lenashow
if (showrose1!=0 && showrose1<200)
{
showrose1+=showspeed;
p.score+=showspeed;
if (showrose1>=200) showrose1=0;
}

if (showrose2!=0 && showrose2<200*bonusint)
{
showrose2+=4;
p.score+=4;
if (showrose2>=200*bonusint) showrose2=0;
}

if (showrose3!=0 && showrose3<200*bonusint)
{
showrose3+=4;
p.score+=4;
if (showrose3>=200*bonusint) showrose3=0;
}

if (npcshow!=0 && npcshow<600*bonusint)
{
npcshow+=4;
p.score+=4;
if (npcshow>=200*bonusint) npcshow=0;
}

if (npcshownegative!=0 && npcshow<300)
{
npcshownegative+=4;
p.score-=4;
if (npcshownegative>=300) npcshownegative=0;
}


if (showprep!=0 && showprep<50*bonusint)
{
showprep+=4;
p.score+=4;
if (showprep>=50*bonusint) showprep=0;
}

if (showhornet!=0 && showhornet<100*bonusint)
{
showhornet+=4;
p.score+=4;
if (showhornet>=100*bonusint) showhornet=0;
}

if (showsam!=-1)
{
if (showsam!=0 && showsam<450)
{
showsam+=4;
p.score+=4;
if (showsam>=450*bonusint) showsam=-1;
}
}
 //beforepoll
if(b.level==1 && collision_lava(&b.mask,p.image_perso.pos_img_ecran, b)==1 && grace>50)
{
p.nb_vies--;		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10) damage_variable=1;
grace=0;
} 
else if (b.level==2 && collision_lava(&b.mask2,p.image_perso.pos_img_ecran, b)==1 && grace>50)
{
p.nb_vies--; 		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10) damage_variable=1;
grace=0;
} 
   while(SDL_PollEvent(&event))
    {
air=0;
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_d)
{
    if (reversed==0) p.direction=1;
    else p.direction=2;
    dte=1;
    while(dte)
    {
if(b.level==1 && collision_lava(&b.mask,p.image_perso.pos_img_ecran, b)==1 && grace>50)
{
p.nb_vies--; 		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10)damage_variable=1;
grace=0;
} 
else if (b.level==2 && collision_lava(&b.mask2,p.image_perso.pos_img_ecran, b)==1 && grace>50)
{
p.nb_vies--; 		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10) damage_variable=1;
grace=0;
} 
    b.head.pos_img_ecran.x=1100+p.image_perso.pos_img_ecran.x*25/100 + b.background_ocean.pos_img_ecran.x;
    b.head.pos_img_ecran.y=p.image_perso.pos_img_ecran.y*25/100-25;
    if (pos>7100 && b.m==0) b.m=1;
	grace++;
	if (grace>50 && (collision(b.e.vertical1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical3.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical4.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical5.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical6.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal3.pos_img_ecran, p.image_perso.pos_img_ecran)))
        {
		  p.nb_vies--; 		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10) damage_variable=1;grace=0;
        }
		if(grace<50) 
	   {     
		if (a%4==0) p.sprite=IMG_Load("images/spritefinal.png");
		else if (a%4==1) p.sprite=IMG_Load("images/gracesprite30.png");
		else if (a%4==2) p.sprite=IMG_Load("images/gracesprite60.png");
		else if (a%4==3) p.sprite=IMG_Load("images/gracesprite30.png");
	   }	
	   else if (grace<55) {p.sprite=IMG_Load("images/spritefinal.png"); p.image_perso.img=IMG_Load("images/marioplayer.png");}
       a++;
    //event
    SDL_PollEvent(&event);

 if(event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_d || p.nb_vies<=0)
    {
            dte=0;
    }
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LSHIFT && p.acceleration<1 && p.mana>1)
{
if(ability_counter>0) ability_counter--;
if(ability_counter==0)
{
colorquest2.r=56;
colorquest2.g=168;
colorquest2.b=74;
q2=1;
}
sprintf(quest10times, "%d times", ability_counter);
txt2quest2 = TTF_RenderText_Solid(questfont, quest10times, colorquest2);
txtquest2 = TTF_RenderText_Solid(questfont, "-use your ability", colorquest2);
    p.mana--;
    p.acceleration=15;
    dust_effect=1;
    b.image_dust.pos_img_ecran.x=p.image_perso.pos_img_ecran.x;
    b.image_dust.pos_img_ecran.y=p.image_perso.pos_img_ecran.y+70-27;
}
    
//pos
pos = p.image_perso.pos_img_ecran.x + b.background_ocean.pos_img_affiche.x;
int completioninteger2 = (int)round((float)pos / b.background_ocean.pos_img_affiche.w * 100);
if (completioninteger2>completioninteger) completioninteger=completioninteger2;
sprintf(completionchar, "-Completion %d%%-", completioninteger);
txtcompletion = TTF_RenderText_Solid(completionfont, completionchar, colorcompletion);
if(pos>8808 && pos<8867 && p.image_perso.pos_img_ecran.y>690)
{
dte=0;
p.direction=0;
p.image_perso.pos_img_ecran.y-=8;
while(p.image_perso.pos_img_affiche.h>0)
{
p.image_perso.pos_img_affiche.h--;
p.image_perso.pos_img_ecran.y++;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
}
p.image_perso.pos_img_ecran.y=418;
(b.background_ocean).pos_img_affiche.x-=120;
p.image_perso.pos_img_ecran.x=50;
 
	b.mini.pos_img_affiche.x-=120/3.9;
	b.mask.pos_img_affiche.x-=120; 
        b.camera.x-=120;
	b.e.vertical1.pos_img_ecran.x+=120;
	b.e.vertical2.pos_img_ecran.x+=120;
	b.e.vertical3.pos_img_ecran.x+=120;
	b.e.vertical4.pos_img_ecran.x+=120;
	b.e.vertical5.pos_img_ecran.x+=120;
	b.e.vertical6.pos_img_ecran.x+=120;
	b.e.horizontal1.pos_img_ecran.x+=120;
	b.e.horizontal2.pos_img_ecran.x+=120;
	b.e.horizontal3.pos_img_ecran.x+=120;
	
	b.rose1.pos_img_ecran.x+=120;
	b.rose2.pos_img_ecran.x+=120;
	b.rose3.pos_img_ecran.x+=120;
	b.heart1.pos_img_ecran.x+=120;
	b.heart2.pos_img_ecran.x+=120;

	b.image_snake.pos_img_ecran.x+=120; 
	b.image_napta.pos_img_ecran.x+=120;
while(p.image_perso.pos_img_affiche.h<90)
{
p.image_perso.pos_img_affiche.h++;
p.image_perso.pos_img_ecran.y--;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
}
}
else if(pos>8455 && pos<8500 && p.image_perso.pos_img_ecran.y<160 && p.image_perso.pos_img_ecran.y>150)
{
dte=0;
p.direction=0;
p.image_perso.pos_img_ecran.y-=16;
while(p.image_perso.pos_img_affiche.h>0)
{
p.image_perso.pos_img_affiche.h--;
p.image_perso.pos_img_ecran.y++;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
}	
p.image_perso.pos_img_ecran.y=-30;
p.image_perso.pos_img_affiche.h=90;
p.image_perso.pos_img_ecran.x=650;
(b.background_ocean).pos_img_affiche.x+=140;
 
	b.mini.pos_img_affiche.x+=140/3.9;
	b.mask.pos_img_affiche.x+=140; 
        b.camera.x+=140;
	b.e.vertical1.pos_img_ecran.x-=140;
	b.e.vertical2.pos_img_ecran.x-=140;
	b.e.vertical3.pos_img_ecran.x-=140;
	b.e.vertical4.pos_img_ecran.x-=140;
	b.e.vertical5.pos_img_ecran.x-=140;
	b.e.vertical6.pos_img_ecran.x-=140;
	b.e.horizontal1.pos_img_ecran.x-=140;
	b.e.horizontal2.pos_img_ecran.x-=140;
	b.e.horizontal3.pos_img_ecran.x-=140;
	(b.garbage_moving.pos_img_ecran.x)-=10;
	(b.image_junkpit.pos_img_ecran.x)-=10;
	
	b.rose1.pos_img_ecran.x-=140;
	b.rose2.pos_img_ecran.x-=140;
	b.rose3.pos_img_ecran.x-=140;
	b.heart1.pos_img_ecran.x-=140;
	b.heart2.pos_img_ecran.x-=140;

	b.image_snake.pos_img_ecran.x-=140; 
	b.image_napta.pos_img_ecran.x-=140;

}
else if(pos>9715 && pos< 9765 && p.image_perso.pos_img_ecran.y<415 && p.image_perso.pos_img_ecran.y>405)
{
dte=0;
p.direction=0;
p.image_perso.pos_img_ecran.y-=16;
while(p.image_perso.pos_img_affiche.h>0)
{
p.image_perso.pos_img_affiche.h--;
p.image_perso.pos_img_ecran.y++;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
}
p.direction=4;
reversed=1;
is_reversed=1;
p.image_perso.pos_img_ecran.x+=130;	
p.image_perso.pos_img_ecran.y=55;
animerPerso(&p);
p.image_perso.pos_img_affiche.y+=90;
while(p.image_perso.pos_img_affiche.h<90)
{
p.image_perso.pos_img_affiche.h+=2;
p.image_perso.pos_img_affiche.y-=2;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
//lena
}
}
if (pos>11315 && pos<11350 && p.image_perso.pos_img_ecran.y<400) {
reversed=0;
p.direction=4;
animerPerso(&p);
while(p.image_perso.pos_img_affiche.h>0)
{
p.image_perso.pos_img_affiche.h-=2;
p.image_perso.pos_img_affiche.y+=2;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
}
p.direction=0;
reversed=0;
is_reversed=0;
p.image_perso.pos_img_ecran.y=700;
p.image_perso.pos_img_ecran.x=740;

	(b.background_ocean).pos_img_affiche.x+=304;
 
	b.mini.pos_img_affiche.x+=304/3.9;
	b.mask.pos_img_affiche.x+=304; 
        b.camera.x+=304;
	b.e.vertical1.pos_img_ecran.x-=304;
	b.e.vertical2.pos_img_ecran.x-=304;
	b.e.vertical3.pos_img_ecran.x-=304;
	b.e.vertical4.pos_img_ecran.x-=304;
	b.e.vertical5.pos_img_ecran.x-=304;
	b.e.vertical6.pos_img_ecran.x-=304;
	b.e.horizontal1.pos_img_ecran.x-=304;
	b.e.horizontal2.pos_img_ecran.x-=304;
	b.e.horizontal3.pos_img_ecran.x-=304;
	(b.garbage_moving.pos_img_ecran.x)-=304;
	(b.image_junkpit.pos_img_ecran.x)-=304;
	b.rose1.pos_img_ecran.x-=304;
	b.rose2.pos_img_ecran.x-=304;
	b.rose3.pos_img_ecran.x-=304;
	b.heart1.pos_img_ecran.x-=304;
	b.heart2.pos_img_ecran.x-=304;

	b.image_snake.pos_img_ecran.x-=304; 
	b.image_napta.pos_img_ecran.x-=304;
colorquest4.r=56;
colorquest4.g=168;
colorquest4.b=74;
txtquest4 = TTF_RenderText_Solid(questfont, "-explore diverse", colorquest4);
txt2quest4 = TTF_RenderText_Solid(questfont, "presepectives", colorquest4);
showprep=1;
initialiser_audio_score(music_score);
animerPerso(&p);
while(p.image_perso.pos_img_affiche.h<90)
{
p.image_perso.pos_img_affiche.h++;
p.image_perso.pos_img_ecran.y--;
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
afficherBack(b,screen);
afficherPerso(p,screen);
afficher_texte_temps(screen,txte,nowtime);
SDL_Flip(screen);
}
}
if (b.level==1)
{
if((pos<limit && pos>650 && p.image_perso.pos_img_ecran.x>650 && b.level==1 && collision_wall(&b.mask,p.image_perso.pos_img_ecran, b)!=2 ))
    { 
	b.acceleration=p.acceleration;
    	scrolling(&b, 1, dt);
    }
    else if((!(b.level==2 && p.image_perso.pos_img_ecran.x>1350)&& collision_wall(&b.mask,p.image_perso.pos_img_ecran, b)!=2) || b.level==2 && collision_wall(&b.mask,p.image_perso.pos_img_ecran, b)!=2)
    {
         movePerso(&p,dt);
    }
}
else if (b.level==2)
{ 
    if(collision_wall(&b.mask2,p.image_perso.pos_img_ecran, b)!=2)
    {
         movePerso(&p,dt);
    }
}
    if (pos>6760 && pos<6860 && shelly==0) dte=0;  
    else if (pos>16050 && end==1) 
	{
	p.direction=0;
	mx=5;
	audio_level1(b.level1_music,volume_music, mx);
	end_game(&b.background_ocean,&b.image_akaros, 1, 300, b, screen,p);
	end=0;
	TTF_Font* fontend = TTF_OpenFont("fonts/Middle.ttf", 48);
	int delayend=200;
		SDL_BlitSurface(b.image_white100.img,NULL, screen,&b.image_white100.pos_img_ecran);
		fade_in4(image_calcscore.img,b.image_white100,screen,image_calcscore.pos_img_ecran);

		//BONUS
		if (bonusint!=1.5) txtbonuspos.x=1361;			
		else txtbonuspos.x=1330;
		txtbonuspos.y=24;
		SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
		//SCORE
		fade_in4(image_collected_score.img,b.image_white100,screen,image_collected_score.pos_img_ecran);
		SDL_Delay(delayend);
		p.score_text.pos_txt.x=1050;
		p.score_text.pos_txt.y=183;
		char score_value_string[10];
		p.score_text.color_txt.r=0;
		p.score_text.color_txt.g=0;
		p.score_text.color_txt.b=0;
		sprintf(score_value_string, "%d", p.score);
		p.score_text.txt=TTF_RenderText_Blended(p.score_text.police,score_value_string, p.score_text.color_txt);
		int animscore=p.score;
		int animspeed=32;
		p.score=0;
		for(show=0; show<animscore; show+=animspeed)
		{
		  p.score+=animspeed;
		  SDL_BlitSurface(b.image_white100.img,NULL, screen,&b.image_white100.pos_img_ecran);
		  SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
		  SDL_BlitSurface(image_calcscore.img, NULL, screen, &image_calcscore.pos_img_ecran);
		  SDL_BlitSurface(image_collected_score.img, NULL, screen, &image_collected_score.pos_img_ecran);
		  sprintf(score_value_string, "%d", p.score);
		  p.score_text.txt=TTF_RenderText_Blended(p.score_text.police,score_value_string, p.score_text.color_txt);
		  SDL_BlitSurface(p.score_text.txt, NULL, screen, &p.score_text.pos_txt);
		  SDL_Flip(screen);
		} 
		//VIES
		fade_in4(image_lives_left.img,b.image_white100,screen,image_lives_left.pos_img_ecran);
		SDL_Delay(delayend);
		p.image_vies.pos_img_ecran.x=675;
		p.image_vies.pos_img_ecran.y=266;
		SDL_BlitSurface(p.image_vies.img,&p.image_vies.pos_img_affiche,screen, &p.image_vies.pos_img_ecran);
		SDL_Flip(screen);		
		SDL_Delay(delayend);
		int animvies=p.nb_vies*50*bonusint; 
		p.nb_vies=0;
		char nbviestxt[6];
		sprintf(nbviestxt, "%d", p.nb_vies);
    		SDL_Surface* vieSurface = TTF_RenderText_Solid(fontend, nbviestxt,  p.score_text.color_txt);
		SDL_Rect rectvies;
    		rectvies.x = 1050;
    		rectvies.y = 251;
		SDL_BlitSurface(vieSurface, NULL, screen, &rectvies);

		for(show=0; show< animvies; show+=animspeed)
		{
		  p.nb_vies+=animspeed;
		  SDL_BlitSurface(b.image_white100.img,NULL, screen,&b.image_white100.pos_img_ecran);
		  sprintf(nbviestxt, "%d", p.nb_vies);
		  SDL_BlitSurface(vieSurface, NULL, screen, &rectvies);
		  vieSurface = TTF_RenderText_Solid(fontend, nbviestxt,  p.score_text.color_txt);
		  SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
		  SDL_BlitSurface(image_calcscore.img, NULL, screen, &image_calcscore.pos_img_ecran);
		  SDL_BlitSurface(image_collected_score.img, NULL, screen, &image_collected_score.pos_img_ecran);
		  SDL_BlitSurface(p.score_text.txt, NULL, screen, &p.score_text.pos_txt);
		  SDL_BlitSurface(image_lives_left.img,NULL,screen, &image_lives_left.pos_img_ecran);
		  SDL_BlitSurface(p.image_vies.img,&p.image_vies.pos_img_affiche,screen, &p.image_vies.pos_img_ecran);
		  SDL_Flip(screen);
		} 
		//COLORFORPUZZLE
		SDL_Color textColor1 = { 255, 255, 255 }; 
		SDL_Color textColor2 = { 255, 255, 255 }; 
		SDL_Color textColor3 = { 255, 255, 255 }; 
		SDL_Color textColor4 = { 255, 255, 255 };
		//PUZZLE1TIME
		fade_in4(image_time1.img,b.image_white100,screen,image_time1.pos_img_ecran);
		SDL_Delay(20);
		float percentage1 = (puzzle1time - 20000) / (float)(40000 - 20000);
		percentage1 = fmaxf(0, fminf(1, percentage1));
		textColor1.r = (int)(percentage1 * 255);
		textColor1.g = (int)((1 - percentage1) * 255);
		textColor1.b = 0;
		char time1[16];
    		sprintf(time1, "%02d:%02d", (puzzle1time / 1000) / 60, (puzzle1time / 1000) % 60);
		SDL_Surface* time1Surface = TTF_RenderText_Solid(fontend, time1, textColor1);
		SDL_Rect time1Rect;
		time1Rect.x = 687;
		time1Rect.y = 335;
		SDL_BlitSurface(time1Surface, NULL, screen, &time1Rect);SDL_Flip(screen);
		SDL_Delay(delayend);

		int animetime1=((220000-puzzle1time)/1000)*bonusint+6; 
		int scoredetime1=0;
		char scoredetime1char[6];
		sprintf(scoredetime1char, "%d", scoredetime1);
    		SDL_Surface* surfacedetime1 = TTF_RenderText_Solid(fontend, scoredetime1char, p.score_text.color_txt);
		SDL_Rect rectdetime1;
    		rectdetime1.x = 1050;
    		rectdetime1.y = 330;
		SDL_BlitSurface(surfacedetime1, NULL, screen, &rectdetime1);

		for(show=0; show<animetime1; show+=animspeed)
		{
		  scoredetime1+=animspeed;
		  SDL_BlitSurface(b.image_white100.img,NULL, screen,&b.image_white100.pos_img_ecran);
  		  sprintf(scoredetime1char, "%d", scoredetime1);
		  surfacedetime1 = TTF_RenderText_Solid(fontend, scoredetime1char, p.score_text.color_txt);
		  SDL_BlitSurface(surfacedetime1, NULL, screen, &rectdetime1);
	          SDL_BlitSurface(image_time1.img,NULL,screen,&image_time1.pos_img_ecran);
		  SDL_BlitSurface(vieSurface, NULL, screen, &rectvies);	  
		  SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
		  SDL_BlitSurface(image_calcscore.img, NULL, screen, &image_calcscore.pos_img_ecran);
		  SDL_BlitSurface(image_collected_score.img, NULL, screen, &image_collected_score.pos_img_ecran);
		  SDL_BlitSurface(p.score_text.txt, NULL, screen, &p.score_text.pos_txt);
		  SDL_BlitSurface(image_lives_left.img,NULL,screen, &image_lives_left.pos_img_ecran);
		  SDL_BlitSurface(p.image_vies.img,&p.image_vies.pos_img_affiche,screen, &p.image_vies.pos_img_ecran);
		  SDL_BlitSurface(time1Surface, NULL, screen, &time1Rect);
		  SDL_Flip(screen);
		} 




		//PUZZLE2TIME	
		fade_in4(image_time2.img,b.image_white100,screen,image_time2.pos_img_ecran);	
		SDL_Delay(delayend);
		float percentage2 = (puzzle2time - 0) / (float)(7000 - 0);
		percentage2 = fmaxf(0, fminf(1, percentage2));
		textColor2.r = (int)(percentage2* 255);
		textColor2.g = (int)((1 - percentage2) * 255);
		textColor2.b = 0;
		char time2[16];
    		sprintf(time2, "%02d:%02d", (puzzle2time / 1000) / 60, (puzzle2time / 1000) % 60);
		SDL_Surface* time2Surface = TTF_RenderText_Solid(fontend, time2, textColor2);
		SDL_Rect time2Rect;
		time2Rect.x = 687;
		time2Rect.y = 405;
		SDL_BlitSurface(time2Surface, NULL, screen, &time2Rect);SDL_Flip(screen);
		SDL_Delay(delayend);



		int animetime2=((20000-puzzle2time)/1000)*bonusint; 
		int scoredetime2=0;
		char scoredetime2char[6];
		sprintf(scoredetime2char, "%d", scoredetime2);
    		SDL_Surface* surfacedetime2 = TTF_RenderText_Solid(fontend, scoredetime2char, p.score_text.color_txt);
		SDL_Rect rectdetime2;
    		rectdetime2.x = 1050;
    		rectdetime2.y = 400;
		SDL_BlitSurface(surfacedetime2, NULL, screen, &rectdetime2);

		for(show=0; show<animetime2; show+=animspeed)
		{
		  scoredetime2+=animspeed/4;
		  SDL_BlitSurface(b.image_white100.img,NULL, screen,&b.image_white100.pos_img_ecran);

  		  sprintf(scoredetime2char, "%d", scoredetime2);
		  surfacedetime2 = TTF_RenderText_Solid(fontend, scoredetime2char, p.score_text.color_txt);
		  SDL_BlitSurface(surfacedetime2, NULL, screen, &rectdetime2);
		  SDL_BlitSurface(image_time2.img, NULL, screen, &image_time2.pos_img_ecran);
		  SDL_BlitSurface(surfacedetime1, NULL, screen, &rectdetime1);
	          SDL_BlitSurface(image_time1.img,NULL,screen,&image_time1.pos_img_ecran);
		  SDL_BlitSurface(vieSurface, NULL, screen, &rectvies);	  
		  SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
		  SDL_BlitSurface(image_calcscore.img, NULL, screen, &image_calcscore.pos_img_ecran);
		  SDL_BlitSurface(image_collected_score.img, NULL, screen, &image_collected_score.pos_img_ecran);
		  SDL_BlitSurface(p.score_text.txt, NULL, screen, &p.score_text.pos_txt);
		  SDL_BlitSurface(image_lives_left.img,NULL,screen, &image_lives_left.pos_img_ecran);
		  SDL_BlitSurface(p.image_vies.img,&p.image_vies.pos_img_affiche,screen, &p.image_vies.pos_img_ecran);
		  SDL_BlitSurface(time1Surface, NULL, screen, &time1Rect);
		  SDL_BlitSurface(time2Surface, NULL, screen, &time2Rect);
		  SDL_Flip(screen);
		} 






		//PUZZLE3TIME		
		fade_in4(image_time3.img,b.image_white100,screen,image_time3.pos_img_ecran);SDL_Delay(delayend);
		float percentage3 = (puzzle3time - 3000) / (float)(13000 - 3000);
		percentage3= fmaxf(0, fminf(1, percentage3));
		textColor3.r = (int)(percentage3* 255);
		textColor3.g = (int)((1 - percentage3) * 255);
		textColor3.b = 0;
		char time3[16];
    		sprintf(time3, "%02d:%02d", (puzzle3time / 1000) / 60, (puzzle3time / 1000) % 60);
		SDL_Surface* time3Surface = TTF_RenderText_Solid(fontend, time3, textColor3);
		SDL_Rect time3Rect;
		time3Rect.x = 687;
		time3Rect.y = 475;
		SDL_BlitSurface(time3Surface, NULL, screen, &time3Rect);SDL_Flip(screen);
		SDL_Delay(delayend);

		int animetime3=((180000-puzzle1time)/1000)*bonusint+2; 
		int scoredetime3=0;
		char scoredetime3char[6];
		sprintf(scoredetime3char, "%d", scoredetime3);
    		SDL_Surface* surfacedetime3 = TTF_RenderText_Solid(fontend, scoredetime3char, p.score_text.color_txt);
		SDL_Rect rectdetime3;
    		rectdetime3.x = 1050;
    		rectdetime3.y = 470;
		SDL_BlitSurface(surfacedetime3, NULL, screen, &rectdetime3);

		for(show=0; show<animetime3; show+=animspeed)
		{
		  scoredetime3+=animspeed;
		  SDL_BlitSurface(b.image_white100.img,NULL, screen,&b.image_white100.pos_img_ecran);

  		  sprintf(scoredetime3char, "%d", scoredetime3);
		  surfacedetime3= TTF_RenderText_Solid(fontend, scoredetime3char, p.score_text.color_txt);
		  SDL_BlitSurface(surfacedetime3, NULL, screen, &rectdetime3);
		  SDL_BlitSurface(surfacedetime2, NULL, screen, &rectdetime2);
		  SDL_BlitSurface(image_time2.img, NULL, screen, &image_time2.pos_img_ecran);
		  SDL_BlitSurface(image_time3.img, NULL, screen, &image_time3.pos_img_ecran);
		  SDL_BlitSurface(surfacedetime1, NULL, screen, &rectdetime1);
	          SDL_BlitSurface(image_time1.img,NULL,screen,&image_time1.pos_img_ecran);
		  SDL_BlitSurface(vieSurface, NULL, screen, &rectvies);	  
		  SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
		  SDL_BlitSurface(image_calcscore.img, NULL, screen, &image_calcscore.pos_img_ecran);
		  SDL_BlitSurface(image_collected_score.img, NULL, screen, &image_collected_score.pos_img_ecran);
		  SDL_BlitSurface(p.score_text.txt, NULL, screen, &p.score_text.pos_txt);
		  SDL_BlitSurface(image_lives_left.img,NULL,screen, &image_lives_left.pos_img_ecran);
		  SDL_BlitSurface(p.image_vies.img,&p.image_vies.pos_img_affiche,screen, &p.image_vies.pos_img_ecran);
		  SDL_BlitSurface(time1Surface, NULL, screen, &time1Rect);
		  SDL_BlitSurface(time2Surface, NULL, screen, &time2Rect);
		  SDL_BlitSurface(time3Surface, NULL, screen, &time3Rect);
		  SDL_Flip(screen);
		} 







		//PUZZLE4TIME	
		fade_in4(image_total.img,b.image_white100,screen,image_total.pos_img_ecran);SDL_Delay(delayend);	
		float percentage4 = (nowtime - 420000) / (float)(720000 - 420000);
		percentage4= fmaxf(0, fminf(1, percentage4));
		textColor4.r = (int)(percentage4* 255);
		textColor4.g = (int)((1 - percentage4) * 255);
		textColor4.b = 0;
		char time4[16];
    		sprintf(time4, "%02d:%02d", (nowtime / 1000) / 60, (nowtime / 1000) % 60);
		SDL_Surface* time4Surface = TTF_RenderText_Solid(fontend, time4, textColor4);
		SDL_Rect time4Rect;
		time4Rect.x = 687;
		time4Rect.y = 545;
		SDL_BlitSurface(time4Surface, NULL, screen, &time4Rect);SDL_Flip(screen);
		SDL_Delay(delayend);


		int animetime4=((2000000-nowtime)/1000)*bonusint; 
		int scoredetime4=0;
		char scoredetime4char[6];
		sprintf(scoredetime4char, "%d", scoredetime4);
    		SDL_Surface* surfacedetime4= TTF_RenderText_Solid(fontend, scoredetime4char, p.score_text.color_txt);
		SDL_Rect rectdetime4;
    		rectdetime4.x = 1050;
    		rectdetime4.y = 545;
		SDL_BlitSurface(surfacedetime4, NULL, screen, &rectdetime4);

		for(show=0; show<animetime4; show+=animspeed)
		{
		  scoredetime4+=animspeed;
		  SDL_BlitSurface(b.image_white100.img,NULL, screen,&b.image_white100.pos_img_ecran);

  		  sprintf(scoredetime4char, "%d", scoredetime4);
		  surfacedetime4= TTF_RenderText_Solid(fontend, scoredetime4char, p.score_text.color_txt);
		  SDL_BlitSurface(surfacedetime3, NULL, screen, &rectdetime3);
		  SDL_BlitSurface(surfacedetime2, NULL, screen, &rectdetime2);
		  SDL_BlitSurface(surfacedetime4, NULL, screen, &rectdetime4);
		  SDL_BlitSurface(image_time2.img, NULL, screen, &image_time2.pos_img_ecran);
		  SDL_BlitSurface(image_time3.img, NULL, screen, &image_time3.pos_img_ecran);
		  SDL_BlitSurface(surfacedetime1, NULL, screen, &rectdetime1);
	          SDL_BlitSurface(image_time1.img,NULL,screen,&image_time1.pos_img_ecran);
		  SDL_BlitSurface(vieSurface, NULL, screen, &rectvies);	  
		  SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
		  SDL_BlitSurface(image_calcscore.img, NULL, screen, &image_calcscore.pos_img_ecran);
		  SDL_BlitSurface(image_collected_score.img, NULL, screen, &image_collected_score.pos_img_ecran);
		  SDL_BlitSurface(p.score_text.txt, NULL, screen, &p.score_text.pos_txt);
		  SDL_BlitSurface(image_lives_left.img,NULL,screen, &image_lives_left.pos_img_ecran);
		  SDL_BlitSurface(p.image_vies.img,&p.image_vies.pos_img_affiche,screen, &p.image_vies.pos_img_ecran);
		  SDL_BlitSurface(image_total.img,NULL,screen, &image_total.pos_img_ecran);
		  SDL_BlitSurface(time1Surface, NULL, screen, &time1Rect);
		  SDL_BlitSurface(time2Surface, NULL, screen, &time2Rect);
		  SDL_BlitSurface(time3Surface, NULL, screen, &time3Rect);
		  SDL_BlitSurface(time3Surface, NULL, screen, &time4Rect);
		  SDL_Flip(screen);
		} 
		fade_in4(image_khat.img,b.image_white100,screen,image_khat.pos_img_ecran);
		SDL_Delay(delayend);

		int animetimef= animscore+animvies+animetime1 +animetime2+animetime3+animetime4;
		int scoredetimef=0;
		char scoredetimefchar[6];
		sprintf(scoredetimefchar, "%d", scoredetimef);
    		SDL_Surface* surfacedetimef= TTF_RenderText_Solid(fontend, scoredetimefchar, p.score_text.color_txt);
		SDL_Rect rectdetimef;
		if (animetimef<10000) rectdetimef.x = 1040;
		else rectdetimef.x=1030;
    		rectdetimef.y = 666;
		SDL_BlitSurface(surfacedetimef,NULL, screen, &rectdetimef);
		
		for(show=0; show<animetimef; show+=animspeed)
		{
		  scoredetimef+=animspeed;
		  SDL_BlitSurface(b.image_white100.img,NULL, screen,&b.image_white100.pos_img_ecran);

  		  sprintf(scoredetimefchar, "%d", scoredetimef);
		  surfacedetimef= TTF_RenderText_Solid(fontend, scoredetimefchar, p.score_text.color_txt);
		  SDL_BlitSurface(surfacedetime3, NULL, screen, &rectdetime3);
		  SDL_BlitSurface(surfacedetime2, NULL, screen, &rectdetime2);
		  SDL_BlitSurface(surfacedetime4, NULL, screen, &rectdetime4);
		  SDL_BlitSurface(surfacedetimef, NULL, screen, &rectdetimef);
		  SDL_BlitSurface(image_time2.img, NULL, screen, &image_time2.pos_img_ecran);
		  SDL_BlitSurface(image_time3.img, NULL, screen, &image_time3.pos_img_ecran);
		  SDL_BlitSurface(surfacedetime1, NULL, screen, &rectdetime1);
	          SDL_BlitSurface(image_time1.img,NULL,screen,&image_time1.pos_img_ecran);
		  SDL_BlitSurface(vieSurface, NULL, screen, &rectvies);	  
		  SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
		  SDL_BlitSurface(image_calcscore.img, NULL, screen, &image_calcscore.pos_img_ecran);
		  SDL_BlitSurface(image_collected_score.img, NULL, screen, &image_collected_score.pos_img_ecran);
		  SDL_BlitSurface(p.score_text.txt, NULL, screen, &p.score_text.pos_txt);
		  SDL_BlitSurface(image_lives_left.img,NULL,screen, &image_lives_left.pos_img_ecran);
		  SDL_BlitSurface(p.image_vies.img,&p.image_vies.pos_img_affiche,screen, &p.image_vies.pos_img_ecran);
		  SDL_BlitSurface(image_total.img,NULL,screen, &image_total.pos_img_ecran);
		  SDL_BlitSurface(time1Surface, NULL, screen, &time1Rect);
		  SDL_BlitSurface(time2Surface, NULL, screen, &time2Rect);
		  SDL_BlitSurface(time3Surface, NULL, screen, &time3Rect);
		  SDL_BlitSurface(time4Surface, NULL, screen, &time4Rect);
		  SDL_BlitSurface(image_khat.img,NULL,screen,&image_khat.pos_img_ecran);
		  SDL_Flip(screen);
		}


            	dial_text = "Thank you for playing !";
            	typewriterend(dial_text,screen,755,event);
		SDL_Flip(screen);
		while(1)
		{
			SDL_EventState(SDL_MOUSEMOTION,SDL_DISABLE);
			SDL_WaitEvent(&event);
			boucle_play=0;
			SDL_EventState(SDL_MOUSEMOTION,SDL_ENABLE);
			break;
		}
	break;
	}
    else if (pos>13086 && b.akaros_appearance==1)
	{
        mx=4;
        audio_level1(b.level1_music,volume_music, mx);
	b.m=3;
	background_position_before_akaros=(b.background_ocean).pos_img_affiche.x;
		while(b.image_akaros.pos_img_ecran.x>1450)
		{
            		(b.background_ocean).pos_img_affiche.x+=35;
			b.image_akaros.pos_img_ecran.x-=35;
        		b.camera.x-=35;
			b.image_bee.pos_img_ecran.x-=35;
			b.e.vertical1.pos_img_ecran.x-=35;
			b.e.vertical2.pos_img_ecran.x-=35;
			b.e.vertical3.pos_img_ecran.x-=35;
			b.e.vertical4.pos_img_ecran.x-=35;
			b.e.vertical5.pos_img_ecran.x-=35;
			b.e.vertical6.pos_img_ecran.x-=35;
			b.e.horizontal1.pos_img_ecran.x-=35;
			b.e.horizontal2.pos_img_ecran.x-=35;
			b.e.horizontal3.pos_img_ecran.x-=35;
           	 mob=(SDL_GetTicks())%250;
        	if (mob>230) {mob=0; animerBack(&b);}
			(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        	afficherBack(b,screen);
        	SDL_Flip(screen);
		}
		SDL_Delay(500);
		shake_image(&b.background_ocean, 10, 250,b,screen);
		b.akaros_is_shown=1;
       	mob=(SDL_GetTicks())%250;
        if (mob>230) {mob=0; animerBack(&b);}
		(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        afficherBack(b,screen);
        SDL_Flip(screen);
		SDL_Delay(500);
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
        	if (mob>230) {mob=0; animerBack(&b);}
			(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
            afficherBack(b,screen);
        	SDL_Flip(screen);
			akaros_animation+=2;
		}
		for (i=0;i<=2;i++)
		{
			b.image_akaros.pos_img_affiche.x-=200;
			mob=(SDL_GetTicks())%250;
            if (mob>230) {mob=0; animerBack(&b);}
			(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        	afficherBack(b,screen);
        	SDL_Flip(screen);
			SDL_Delay(80);
		}
		b.image_akaros.pos_img_affiche.x=0;
		b.image_akaros.pos_img_affiche.y=0;
        afficherBack(b,screen);
        SDL_Flip(screen);
		shake_image(&b.image_akaros, 5, 30,b,screen);
		b.akaros_shake=1;
		shake_image(&b.image_akaros, 5, 150,b,screen);
		akaros_animation=0;
		b.image_akaros.pos_img_affiche.x=200;
		b.image_akaros.pos_img_affiche.y=400;
		while ((b.background_ocean).pos_img_affiche.x>background_position_before_akaros+15)
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
						b.image_bee.pos_img_ecran.x+=10;
						(b.background_ocean).pos_img_affiche.x-=10;
						b.camera.x+=10;
						b.e.vertical1.pos_img_ecran.x+=10;
						b.e.vertical2.pos_img_ecran.x+=10;
						b.e.vertical3.pos_img_ecran.x+=10;
						b.e.vertical4.pos_img_ecran.x+=10;
						b.e.vertical5.pos_img_ecran.x+=10;
						b.e.vertical6.pos_img_ecran.x+=10;
						b.e.horizontal1.pos_img_ecran.x+=10;
						b.e.horizontal2.pos_img_ecran.x+=10;
						b.e.horizontal3.pos_img_ecran.x+=10;
					}
					else
					{
						b.image_bee.pos_img_ecran.x-=15;
						(b.background_ocean).pos_img_affiche.x-=15;
						b.e.vertical1.pos_img_ecran.x+=15;
						b.e.vertical2.pos_img_ecran.x+=15;
						b.e.vertical3.pos_img_ecran.x+=15;
						b.e.vertical4.pos_img_ecran.x+=15;
						b.e.vertical5.pos_img_ecran.x+=15;
						b.e.vertical6.pos_img_ecran.x+=15;
						b.e.horizontal1.pos_img_ecran.x+=15;
						b.e.horizontal2.pos_img_ecran.x+=15;
						b.e.horizontal3.pos_img_ecran.x+=15;
						b.camera.x+=15;
					}
                   			mob=(SDL_GetTicks())%250;
					if (mob>230) {mob=0; animerBack(&b);}
					(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
					afficherBack(b,screen);
				 	projectiles_movement(&b, p.direction,0);
					SDL_Flip(screen);
				}
			}
			i=-1;
			if (akaros_animation>28)
			{
				if (akaros_animation%2==0) {akaros_animation=1; b.image_akaros.pos_img_affiche.x=800;}
				else {akaros_animation=0; b.image_akaros.pos_img_affiche.x=1000; }
			}
			akaros_animation+=2;
			b.image_bee.pos_img_ecran.x+=20;
			(b.background_ocean).pos_img_affiche.x-=20;
			b.e.vertical1.pos_img_ecran.x+=20;
			b.e.vertical2.pos_img_ecran.x+=20;
			b.e.vertical3.pos_img_ecran.x+=20;
			b.e.vertical4.pos_img_ecran.x+=20;
			b.e.vertical5.pos_img_ecran.x+=20;
			b.e.vertical6.pos_img_ecran.x+=20;
			b.e.horizontal1.pos_img_ecran.x+=20;
			b.e.horizontal2.pos_img_ecran.x+=20;
			b.e.horizontal3.pos_img_ecran.x+=20;
            b.camera.x+=20;
            mob=(SDL_GetTicks())%250;
			projectiles_movement(&b, p.direction,0);
            if (mob>230) {mob=0; animerBack(&b);}
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
                if (mob>230) {mob=0; animerBack(&b);}
				(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
				afficherBack(b,screen);
				projectiles_movement(&b, p.direction,0);
				SDL_Flip(screen);
				SDL_Delay(80);
			}
		
		rand_akaros_spot= rand() % 400+100;
		b.akaros_appearance=0;
		b.m=4;
		b.mini.pos_img_affiche.x+=50;
    //to fix the position of the first three vertical projectiles after akaros aniamtion's end
	/*b.e.vertical1.pos_img_ecran.x=14331;
	b.e.vertical2.pos_img_ecran.x=14493;
	b.e.vertical3.pos_img_ecran.x=14623;*/
	}
	if (b.akaros_appearance==0)
	{
	if (pos<15060 && akaros_stop==0)  b.image_akaros.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+600;
	else 
	{	
		akaros_stop=1;	
	}
	if (akaros_stop==1){
	if ((b.image_akaros.pos_img_ecran.x+b.image_akaros.pos_img_ecran.h/2)<p.image_perso.pos_img_ecran.x /*&& b.akaros_direction==-1*/)
		{		
			b.akaros_direction=-1;
		}}
	}
	if (collision_item(b.rose2.pos_img_ecran, p.image_perso.pos_img_ecran) && b.rose2_is_collected==0) 
	{
		b.rose2_is_collected=1;
		rose_counter++;	
		showrose2=1;
		initialiser_audio_score(music_score);
	}
	else if (collision_item(b.heart1.pos_img_ecran, p.image_perso.pos_img_ecran) && b.heart1_is_collected==0) 
	{
		b.heart1_is_collected=1;
		p.nb_vies++;
		initialiser_audio_score(music_collect);
	}
	else if (collision_item(b.heart2.pos_img_ecran, p.image_perso.pos_img_ecran) && b.heart2_is_collected==0) 
	{
		b.heart2_is_collected=1;
		p.nb_vies++;
		initialiser_audio_score(music_collect);
	}
	(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
    afficherBack(b,screen);
if(tab==1)
{
SDL_BlitSurface(quest_box.img,NULL,screen,&quest_box.pos_img_ecran);
SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
SDL_BlitSurface(txtquest1, NULL, screen, &txtquest1pos);
SDL_BlitSurface(txt2quest1, NULL, screen, &txt2quest1pos);
SDL_BlitSurface(txtquest2, NULL, screen, &txtquest2pos);
SDL_BlitSurface(txt2quest2, NULL, screen, &txt2quest2pos);
SDL_BlitSurface(txtquest3, NULL, screen, &txtquest3pos);
SDL_BlitSurface(txtquest4, NULL, screen, &txtquest4pos);
SDL_BlitSurface(txt2quest4, NULL, screen, &txt2quest4pos);
SDL_BlitSurface(txtquest5, NULL, screen, &txtquest5pos);

SDL_BlitSurface(txt2quest5, NULL, screen, &txt2quest5pos);
SDL_BlitSurface(txtquest6, NULL, screen, &txtquest6pos);
SDL_BlitSurface(txt2quest6, NULL, screen, &txt2quest6pos);
SDL_BlitSurface(txtcompletion, NULL, screen, &txtcompletionpos);
SDL_BlitSurface(txttabtohide, NULL, screen, &txttabtohidepos);
}
else {
SDL_BlitSurface(txttabtoshow, NULL, screen, &txttabtoshowpos);
SDL_BlitSurface(txttabtoshowquests, NULL, screen, &txttabtoshowquestspos);}
    if (pos>1600 && pos<2400)  
    {
        where_am_i.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+40;
        where_am_i.pos_img_ecran.y=p.image_perso.pos_img_ecran.y-60;
	SDL_BlitSurface(where_am_i.img,NULL,screen,&where_am_i.pos_img_ecran);
    }
    animerPerso(&p);
	now = SDL_GetTicks();
 	projectiles_movement(&b, p.direction,0);
    if (now - before >=250)
    {
    animerBack (&b);
    before = now; (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
    }
	SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
	SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
	sprintf(char_rose_counter, "  %d", rose_counter);
	afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
    afficherPerso(p,screen);
    MAJMinimap(p,&m,b.camera,redimensionnement);
	nowtime=SDL_GetTicks();nowtime-=last;
    afficher (m,screen);
    afficher_texte_temps(screen,txte,nowtime);
    cpt++;
    if(cpt==10)
        {
            p.posSprite.x+=80;
            if(p.posSprite.x==640) p.posSprite.x=0;
            cpt=0;
        }
	float_items(&b, &angle,frequency,amplitude,speed/2);
    SDL_Flip(screen);
    SDL_EnableKeyRepeat(0,0);
    if (!(b.garbage_moving.pos_img_affiche.x==0 || b.garbage_moving.pos_img_affiche.x==800))  
    {
		int rand_garbage_moving = rand() % 5 - 2;
		if (cpt_garbage_moving>0) {b.garbage_moving.pos_img_ecran.x+=(4 + rand_garbage_moving); cpt_garbage_moving--;}
		else if (cpt_garbage_moving<=0) {b.garbage_moving.pos_img_ecran.x+=(-4 + rand_garbage_moving);cpt_garbage_moving--; }
		if (cpt_garbage_moving<-100) cpt_garbage_moving=100;
    }
    if(p.acceleration > 0 ) {p.acceleration-=0.1;}
    if (reversed==0)
    {
if (b.level==1)
{

      tpc++;  
      if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && up==0 && collision_perfect(&b.mask,p.image_perso.pos_img_ecran, b)==0)
        {
	if(tpc>25)
	    {initialiser_audio_jump(music_jump); tpc=0;}
            p.image_perso.pos_img_ecran.y-=5;
        }
       	else if (collision_ground(&b.mask,p.image_perso.pos_img_ecran, b)==0)        
	{ int bla;
	    bla++;            
	    p.image_perso.pos_img_ecran.y+=5;
        }
	else if (collision_ground(&b.mask,p.image_perso.pos_img_ecran, b)==1) 
	{ ground_y=p.image_perso.pos_img_ecran.y;}
}
else if (b.level==2)
{
	SDL_Delay(2);
	 if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && up==0 && collision_perfect(&b.mask2,p.image_perso.pos_img_ecran, b)==0)
        {
	    if(tpc>25)
	    {initialiser_audio_jump(music_jump); tpc=0;}
            p.image_perso.pos_img_ecran.y-=5;
        }
       	else if (collision_ground(&b.mask2,p.image_perso.pos_img_ecran, b)==0)        
	{ int bla;

	    bla++;            
	    p.image_perso.pos_img_ecran.y+=5;
        }
	else if (collision_ground(&b.mask2,p.image_perso.pos_img_ecran, b)==1) 
	{ground_y=p.image_perso.pos_img_ecran.y;}
}
else if (b.level==3)
{
   SDL_Delay(6);
   movePerso(&p,dt); 
}
        if(p.image_perso.pos_img_ecran.y<ground_y-60) up=1; //635
        else if(p.image_perso.pos_img_ecran.y>ground_y-10) up=0;
        if(p.image_perso.pos_img_ecran.y<ground_y) air =1;
        else air=0;
    }
    else if (reversed==1)
    {
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE && up == 0)
    {
        if(tpc>25)
	    {initialiser_audio_jump(music_jump); tpc=0;}
        p.image_perso.pos_img_ecran.y += 5;  
    }
    else if (p.image_perso.pos_img_ecran.y > 50)  
    {
        p.image_perso.pos_img_ecran.y -= 5;  
    }
    if (p.image_perso.pos_img_ecran.y > 110) up = 1;  
    else if (p.image_perso.pos_img_ecran.y < 60) up = 0; 
    if (p.image_perso.pos_img_ecran.y > 50) air = 1; 
    else air = 0;
    }
     if(p.mana<3) p.mana+=0.003;
     if(p.acceleration > 0 ) p.acceleration-=0.1;
if(dust_effect!=0)
{

    SDL_BlitSurface(b.image_dust.img,&b.image_dust.pos_img_affiche,screen,&b.image_dust.pos_img_ecran);
    SDL_Flip(screen);
    if(cpt%3==0)
    {
        if (p.image_perso.pos_img_ecran.x>640 && b.level==1) b.image_dust.pos_img_ecran.x-=15;
        b.image_dust.pos_img_affiche.y=0;
        b.image_dust.pos_img_affiche.x+=65;
        dust_effect++;
    }
    if(dust_effect>10)
    {
        dust_effect=0;
        b.image_dust.pos_img_affiche.x=0;
    }
}
//
cptbee+=2;
if (sqrt(pow((b.image_bee.pos_img_ecran.x-p.image_perso.pos_img_ecran.x),2)+pow((b.image_bee.pos_img_ecran.y-p.image_perso.pos_img_ecran.y),2))<400)
{
if (cptbee>=495 && cptbee<=496)
  {
    pos_att_beex=p.image_perso.pos_img_ecran.x;
    if(p.image_perso.pos_img_ecran.x>645) pos_att_beex-=20;
    pos_att_beey=p.image_perso.pos_img_ecran.y+p.image_perso.pos_img_ecran.h;
  }
else if (cptbee>500)
  {
    nah=1;
    cptbee=0;
b.image_bee.pos_img_affiche.x=0;
b.image_bee.pos_img_affiche.y=130;
  }
if (nah==1)
{
if(b.image_bee.pos_img_ecran.x+120<pos_att_beex)
    b.image_bee.pos_img_ecran.x+=10;
if(b.image_bee.pos_img_ecran.y+p.image_perso.pos_img_ecran.h<pos_att_beey)
    b.image_bee.pos_img_ecran.y+=5;
if (b.image_bee.pos_img_ecran.y+p.image_perso.pos_img_ecran.h>=pos_att_beey)  
{
nah=0;
if (abs(b.image_bee.pos_img_ecran.x+120-p.image_perso.pos_img_ecran.x)<30) {p.nb_vies--; 
		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10)damage_variable=1;
hornetdamage=1;}
}
}
else 
{
b.image_bee.pos_img_affiche.y=0;
	if (b.image_bee.pos_img_ecran.x-p.image_perso.pos_img_ecran.x<-160)
	{
		b.image_bee.pos_img_ecran.x+=2;
	}
	if (b.image_bee.pos_img_ecran.x-p.image_perso.pos_img_ecran.x>-160)
	{
		b.image_bee.pos_img_ecran.x-=2;
	}
	if ((b.image_bee.pos_img_ecran.y-p.image_perso.pos_img_ecran.y)>-80-130)
	{
		b.image_bee.pos_img_ecran.y-=2;
	}
}
}
else if (cptbee>495) cptbee=495;
if ((nowtime/1000)<61)
{
secondsforrose=60-(nowtime/1000);
sprintf(quest60s, "Rose within %ds", secondsforrose);
if (b.rose1_is_collected==1) 
	{
		colorquest1.r=56;
		colorquest1.g=168;
		colorquest1.b=74;
		q1=1;
	} 
txtquest1 = TTF_RenderText_Solid(questfont, "-collect your first", colorquest1);
txt2quest1 = TTF_RenderText_Solid(questfont, quest60s, colorquest1);
}
else if((nowtime/1000<=62))
{
	if (b.rose1_is_collected==0) 
	{
		colorquest1.r=228;
		colorquest1.g=63;
		colorquest1.b=63;
	}
	else
	{
		colorquest1.r=56;
		colorquest1.g=168;
		colorquest1.b=74;
		q1=1;
	} 
txtquest1 = TTF_RenderText_Solid(questfont, "-collect your first", colorquest1);
txt2quest1 = TTF_RenderText_Solid(questfont, quest60s, colorquest1);
 }    
if (q1==1 && q2==1 && bonusint!=3)
{
bonusint=3;
sprintf(bonuschar, "X%.0f", bonusint);
colorbonus.r=255;
colorbonus.g=121;
colorbonus.b=0;
bonusfont = TTF_OpenFont("fonts/Middle.ttf", 64);
txtbonuspos.x=1339;
txtbonuspos.y=196;
txtbonus = TTF_RenderText_Solid(bonusfont, bonuschar, colorbonus);
}
else if (q1==1 && q2==0 && bonusint==1)
{
bonusint=1.5;
sprintf(bonuschar, "X%.1f", bonusint);
colorbonus.r=255;
colorbonus.g=201;
colorbonus.b=14;
txtbonuspos.x=1300;
txtbonus = TTF_RenderText_Solid(bonusfont, bonuschar, colorbonus);
}
else if (q2==1 && q1==0 && bonusint==1)
{
bonusint=1.5;
sprintf(bonuschar, "X%.1f", bonusint);
colorbonus.r=255;
colorbonus.g=201;
colorbonus.b=14;
txtbonuspos.x=1300;
txtbonus = TTF_RenderText_Solid(bonusfont, bonuschar, colorbonus);
}
if (hornetdamage==1 && pos<14384)
{
colorquest5.r=228;
colorquest5.g=63;
colorquest5.b=63;
txtquest5 = TTF_RenderText_Solid(questfont, "-unharmed by the", colorquest5);
txt2quest5 = TTF_RenderText_Solid(questfont, "vengeful hornet", colorquest5);
}
if (pos>14384 && pos<14450)
{
	if (did_reach_hornet==1 && hornetdamage==0)
	{
		colorquest5.r=56;
		colorquest5.g=168;
		colorquest5.b=74;
		showhornet=1;
		initialiser_audio_score(music_score);
	}
	else if (did_reach_hornet==1 && hornetdamage==1)
	{
		colorquest5.r=228;
		colorquest5.g=63;
		colorquest5.b=63;		
	}
	if (did_reach_hornet==0)
	{
		colorquest5.r=56;
		colorquest5.g=168;
		colorquest5.b=74;
	}
txtquest5 = TTF_RenderText_Solid(questfont, "-unharmed by the", colorquest5);
txt2quest5 = TTF_RenderText_Solid(questfont, "vengeful hornet", colorquest5);
}



//showlena
if (showrose1!=0 && showrose1<200)
{
showrose1+=showspeed;
p.score+=showspeed;
if (showrose1>=200) showrose1=0;
}
if (showrose2!=0 && showrose2<200*bonusint)
{
showrose2+=4;
p.score+=4;
if (showrose2>=200*bonusint) showrose2=0;
}
if (showrose3!=0 && showrose3<200*bonusint)
{
showrose3+=4;
p.score+=4;
if (showrose2>=200*bonusint) showrose3=0;
}
if (npcshow!=0 && npcshow<600*bonusint)
{
npcshow+=4;
p.score+=4;
if (npcshow>=200*bonusint) npcshow=0;
}

if (npcshownegative!=0 && npcshow<300)
{
npcshownegative+=4;
p.score-=4;
if (npcshownegative>=300) npcshownegative=0;
}


if (showprep!=0 && showprep<50*bonusint)
{
showprep+=4;
p.score+=4;
if (showprep>=50*bonusint) showprep=0;
}

if (showhornet!=0 && showhornet<100*bonusint)
{
showhornet+=4;
p.score+=4;
if (showhornet>=100*bonusint) showhornet=0;
}

if (showsam!=-1)
{
if (showsam!=0 && showsam<450)
{
showsam+=4;
p.score+=4;
if (showsam>=450*bonusint) showsam=-1;
}
}

//fin while(dte)
}
     
}
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_q/*&& p.image_perso.pos_img_ecran.x<1300*/)//MOVE RIGHT
{
    if (reversed==0) p.direction=-1;
    else p.direction=3;
    dte=1;
    while(dte)
    {
tpc++;
if(b.level==1 && collision_lava(&b.mask,p.image_perso.pos_img_ecran, b)==1 && grace>50)
{
p.nb_vies--; 		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10) damage_variable=1;
grace=0;
} 
else if (b.level==2 && collision_lava(&b.mask2,p.image_perso.pos_img_ecran, b)==1 && grace>50)
{
p.nb_vies--; 		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10) damage_variable=1;
grace=0;
} 
if (pos>13100 && pos<13500 && p.image_perso.pos_img_ecran.y<300) did_reach_hornet=1;
if (hornetdamage==1 && pos<14384)
{
colorquest5.r=228;
colorquest5.g=63;
colorquest5.b=63;
txtquest5 = TTF_RenderText_Solid(questfont, "-unharmed by the", colorquest5);
txt2quest5 = TTF_RenderText_Solid(questfont, "vengeful hornet", colorquest5);
}
if (q1==1 && q2==1 && bonusint!=3)
{
bonusint=3;
sprintf(bonuschar, "X%.0f", bonusint);
colorbonus.r=255;
colorbonus.g=121;
colorbonus.b=0;
bonusfont = TTF_OpenFont("fonts/Middle.ttf", 64);
txtbonuspos.x=1339;
txtbonuspos.y=196;
txtbonus = TTF_RenderText_Solid(bonusfont, bonuschar, colorbonus);
}
else if (q1==1 && q2==0 && bonusint==1)
{
bonusint=1.5;
sprintf(bonuschar, "X%.1f", bonusint);
colorbonus.r=255;
colorbonus.g=201;
colorbonus.b=14;
txtbonuspos.x=1300;
txtbonus = TTF_RenderText_Solid(bonusfont, bonuschar, colorbonus);
}
else if (q2==1 && q1==0 && bonusint==1)
{
bonusint=1.5;
sprintf(bonuschar, "X%.1f", bonusint);
colorbonus.r=255;
colorbonus.g=201;
colorbonus.b=14;
txtbonuspos.x=1300;
txtbonus = TTF_RenderText_Solid(bonusfont, bonuschar, colorbonus);
}
if ((nowtime/1000)<61)
{
secondsforrose=60-(nowtime/1000);
sprintf(quest60s, "Rose within %ds", secondsforrose);
if (b.rose1_is_collected==1) 
	{
		colorquest1.r=56;
		colorquest1.g=168;
		colorquest1.b=74;
		q1=1;
	} 
txtquest1 = TTF_RenderText_Solid(questfont, "-collect your first", colorquest1);
txt2quest1 = TTF_RenderText_Solid(questfont, quest60s, colorquest1);
}
else if((nowtime/1000<=62))
{
	if (b.rose1_is_collected==0) 
	{
		colorquest1.r=228;
		colorquest1.g=63;
		colorquest1.b=63;
	}
	else
	{
		colorquest1.r=56;
		colorquest1.g=168;
		colorquest1.b=74;
		q1=1;
	} 
txtquest1 = TTF_RenderText_Solid(questfont, "-collect your first", colorquest1);
txt2quest1 = TTF_RenderText_Solid(questfont, quest60s, colorquest1);
}
cptbee+=2;
if (sqrt(pow((b.image_bee.pos_img_ecran.x-p.image_perso.pos_img_ecran.x),2)+pow((b.image_bee.pos_img_ecran.y-p.image_perso.pos_img_ecran.y),2))<400)
{
if (cptbee>=495 && cptbee<=496)
  {
    pos_att_beex=p.image_perso.pos_img_ecran.x;
    if(p.image_perso.pos_img_ecran.x>645) pos_att_beex-=20;
    pos_att_beey=p.image_perso.pos_img_ecran.y+p.image_perso.pos_img_ecran.h;
  }
else if (cptbee>500)
  {
    nah=1;
    cptbee=0;
b.image_bee.pos_img_affiche.x=0;
b.image_bee.pos_img_affiche.y=130;
  }
if (nah==1)
{
if(b.image_bee.pos_img_ecran.x+120<pos_att_beex)
    b.image_bee.pos_img_ecran.x+=10;
if(b.image_bee.pos_img_ecran.y+p.image_perso.pos_img_ecran.h<pos_att_beey)
    b.image_bee.pos_img_ecran.y+=5;
if (b.image_bee.pos_img_ecran.y+p.image_perso.pos_img_ecran.h>=pos_att_beey)  
{
nah=0;
if (abs(b.image_bee.pos_img_ecran.x+120-p.image_perso.pos_img_ecran.x)<30) {p.nb_vies--; 		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10) damage_variable=1;hornetdamage=1;}
}
}
else 
{
b.image_bee.pos_img_affiche.y=0;
	if (b.image_bee.pos_img_ecran.x-p.image_perso.pos_img_ecran.x<-160)
	{
		b.image_bee.pos_img_ecran.x+=2;
	}
	if (b.image_bee.pos_img_ecran.x-p.image_perso.pos_img_ecran.x>-160)
	{
		b.image_bee.pos_img_ecran.x-=2;
	}
	if ((b.image_bee.pos_img_ecran.y-p.image_perso.pos_img_ecran.y)>-80-130)
	{
		b.image_bee.pos_img_ecran.y-=2;
	}
}
}
else if (cptbee>495) cptbee=495;
b.head.pos_img_ecran.x=1100+p.image_perso.pos_img_ecran.x*25/100 + b.background_ocean.pos_img_ecran.x;
    b.head.pos_img_ecran.y=p.image_perso.pos_img_ecran.y*25/100-25;
    grace++;


//showlena
if (showrose1!=0 && showrose1<200)
{
showrose1+=showspeed;
p.score+=showspeed;
if (showrose1>=200) showrose1=0;
}
if (showrose2!=0 && showrose2<200*bonusint)
{
showrose2+=4;
p.score+=4;
if (showrose2>=200*bonusint) showrose2=0;
}
if (showrose3!=0 && showrose2<200*bonusint)
{
showrose3+=4;
p.score+=4;
if (showrose3>=200*bonusint) showrose3=0;
}

if (npcshow!=0 && npcshow<600*bonusint)
{
npcshow+=4;
p.score+=4;
if (npcshow>=200*bonusint) npcshow=0;
}

if (npcshownegative!=0 && npcshow<300)
{
npcshownegative+=4;
p.score-=4;
if (npcshownegative>=300) npcshownegative=0;
}


if (showprep!=0 && showprep<50*bonusint)
{
showprep+=4;
p.score+=4;
if (showprep>=50*bonusint) showprep=0;
}

if (showhornet!=0 && showhornet<100*bonusint)
{
showhornet+=4;
p.score+=4;
if (showhornet>=100*bonusint) showhornet=0;
}

if (showsam!=-1)
{
if (showsam!=0 && showsam<450)
{
showsam+=4;
p.score+=4;
if (showsam>=450*bonusint) showsam=-1;
}
}
	if (collision_item(b.rose1.pos_img_ecran, p.image_perso.pos_img_ecran) && b.rose1_is_collected==0)
	{
		b.rose1_is_collected=1;
		rose_counter++;
		showrose1=1;
		initialiser_audio_score(music_score);
	}
	else if (collision_item(b.rose2.pos_img_ecran, p.image_perso.pos_img_ecran) && b.rose2_is_collected==0)
	{
		b.rose2_is_collected=1;
		rose_counter++;
		showrose2=1;
		initialiser_audio_score(music_score);
	}
	else if (collision_item(b.rose3.pos_img_ecran, p.image_perso.pos_img_ecran) && b.rose3_is_collected==0)
	{
		b.rose3_is_collected=1;
		rose_counter++;
		showrose3=1;
		initialiser_audio_score(music_score);
	}
	else if (collision_item(b.heart1.pos_img_ecran, p.image_perso.pos_img_ecran) && b.heart1_is_collected==0)
	{
		b.heart1_is_collected=1;
		p.nb_vies++;
		initialiser_audio_score(music_collect);
	}
	else if (collision_item(b.heart2.pos_img_ecran, p.image_perso.pos_img_ecran) && b.heart2_is_collected==0)
	{
		b.heart2_is_collected=1;
		p.nb_vies++;
		initialiser_audio_score(music_collect);
	}
		if (grace>50 && (collision(b.e.vertical1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical3.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical4.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical5.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical6.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal3.pos_img_ecran, p.image_perso.pos_img_ecran)))
    {
	if(grace>50) {p.nb_vies--;		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10) damage_variable=1; grace=0;}
    }
	if(grace<50)
	{
		if (a%4==0) p.sprite=IMG_Load("images/spritefinal.png");
		else if (a%4==1) p.sprite=IMG_Load("images/gracesprite30.png");
		else if (a%4==2) p.sprite=IMG_Load("images/gracesprite60.png");
		else if (a%4==3) p.sprite=IMG_Load("images/gracesprite30.png");
	}
	 else if (grace<55) {p.sprite=IMG_Load("images/spritefinal.png"); p.image_perso.img=IMG_Load("images/marioplayer.png");}
	a++;
	SDL_PollEvent(&event);
	if(event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_q || p.nb_vies<=0)
        {
            dte=0;
        }
	else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LSHIFT && p.acceleration<1 && p.mana>1) {
if(ability_counter>0) ability_counter--;
if(ability_counter==0)
{
colorquest2.r=56;
colorquest2.g=168;
colorquest2.b=74;
q2=1;
}
sprintf(quest10times, "%d times", ability_counter);
txt2quest2 = TTF_RenderText_Solid(questfont, quest10times, colorquest2);
txtquest2 = TTF_RenderText_Solid(questfont, "-use your ability", colorquest2);
p.mana--;p.acceleration=15;b.acceleration=p.acceleration; dust_effect=1;b.image_dust.pos_img_ecran.x=p.image_perso.pos_img_ecran.x;b.image_dust.pos_img_ecran.y=p.image_perso.pos_img_ecran.y+70-27;}
	if (b.akaros_appearance==0)
	{
		if (akaros_stop==0)
		{
		b.image_akaros.pos_img_affiche.y=400;
		b.image_akaros.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+600;
		if (akaros_animation>20) b.image_akaros.pos_img_affiche.x=800;
		else  b.image_akaros.pos_img_affiche.x=1000;
		akaros_animation+=2;
		if (akaros_animation>40) akaros_animation=0;
		}

	}
        cpt++;
        if(cpt==10)
        {
            p.posSprite.x+=80;
            if(p.posSprite.x==640) p.posSprite.x=0;
            cpt=0;
        }
        SDL_EnableKeyRepeat(0,0);
if(b.level==1)
{
        if(p.image_perso.pos_img_ecran.x<= 50 && (b.background_ocean).pos_img_affiche.x>0  && b.level !=2 && collision_wall(&b.mask,p.image_perso.pos_img_ecran, b)!=1)
        {
        b.acceleration=p.acceleration;
	    scrolling(&b, -1, dt);
        }
        else if (p.image_perso.pos_img_ecran.x>32 && collision_wall(&b.mask,p.image_perso.pos_img_ecran, b)!=1)
        {
            movePerso(&p,dt);
        }
}
else if(b.level==2)
{
        SDL_Delay(2);
        if( collision_wall(&b.mask2,p.image_perso.pos_img_ecran, b)!=1)
            movePerso(&p,dt);
}
else if (b.level==3)
{
	SDL_Delay(6);
    if (p.image_perso.pos_img_ecran.x>50) movePerso(&p,dt); 
}
        if (!(b.garbage_moving.pos_img_affiche.x==0 || b.garbage_moving.pos_img_affiche.x==800))
        {
            int rand_garbage_moving = rand() % 5 - 2;
            if (cpt_garbage_moving>0) {b.garbage_moving.pos_img_ecran.x+=(4 + rand_garbage_moving); cpt_garbage_moving--;}
            else if (cpt_garbage_moving<=0) {b.garbage_moving.pos_img_ecran.x+=(-4 + rand_garbage_moving);cpt_garbage_moving--; }
            if (cpt_garbage_moving<-100) cpt_garbage_moving=100;
        }
        if (akaros_stop==1)
        {
        if ((b.image_akaros.pos_img_ecran.x+b.image_akaros.pos_img_ecran.h/2)>p.image_perso.pos_img_ecran.x /*&& b.akaros_direction==-1*/)
            {
                b.akaros_direction=1;
            }
        }
if(p.acceleration > 0 ) {p.acceleration-=0.1;}
if (reversed==0)
    {
if (b.level==1)
{
        if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && up==0 && collision_perfect(&b.mask,p.image_perso.pos_img_ecran, b)==0 )
        {
	    if(tpc>25)
	    {initialiser_audio_jump(music_jump); tpc=0;}
            p.image_perso.pos_img_ecran.y-=5;
        }
       	else if (collision_ground(&b.mask,p.image_perso.pos_img_ecran, b)==0)        
	{ int bla;
	    bla++;            
	    p.image_perso.pos_img_ecran.y+=5;
        }
	else if (collision_ground(&b.mask,p.image_perso.pos_img_ecran, b)==1) 
	{ ground_y=p.image_perso.pos_img_ecran.y;}
}
else if (b.level==2)
{
        if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && up==0 && collision_perfect(&b.mask2,p.image_perso.pos_img_ecran, b)==0 )
        {
	if(tpc>25)
	    {initialiser_audio_jump(music_jump); tpc=0;}
            p.image_perso.pos_img_ecran.y-=5;
        }
       	else if (collision_ground(&b.mask2,p.image_perso.pos_img_ecran, b)==0)        
	{   int bla;
	    bla++;            
	    p.image_perso.pos_img_ecran.y+=5;
        }
	else if (collision_ground(&b.mask2,p.image_perso.pos_img_ecran, b)==1) 
	{ ground_y=p.image_perso.pos_img_ecran.y;}
}
        if(p.image_perso.pos_img_ecran.y<ground_y-60) up=1; //635
        else if(p.image_perso.pos_img_ecran.y>ground_y-10) up=0;
        if(p.image_perso.pos_img_ecran.y<ground_y) air =1;
        else air=0;
    }
        else if (reversed==1)
    {
   if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE && up == 0)
    {
	if(tpc>25)
	    {initialiser_audio_jump(music_jump); tpc=0;}
        p.image_perso.pos_img_ecran.y += 5;  
    }
    else if (p.image_perso.pos_img_ecran.y > 50)  
    {
        p.image_perso.pos_img_ecran.y -= 5;  
    }
    if (p.image_perso.pos_img_ecran.y > 110) up = 1;  
    else if (p.image_perso.pos_img_ecran.y < 60) up = 0; 
    if (p.image_perso.pos_img_ecran.y > 50) air = 1; 
    else air = 0;
    }
        (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        now = SDL_GetTicks();
        if (now - before >=250)
        {
         animerBack (&b);
         before = now; (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
        }
        afficherBack(b,screen);
if(tab==1)
{
SDL_BlitSurface(quest_box.img,NULL,screen,&quest_box.pos_img_ecran);
SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
SDL_BlitSurface(txtquest1, NULL, screen, &txtquest1pos);
SDL_BlitSurface(txt2quest1, NULL, screen, &txt2quest1pos);
SDL_BlitSurface(txtquest2, NULL, screen, &txtquest2pos);
SDL_BlitSurface(txt2quest2, NULL, screen, &txt2quest2pos);
SDL_BlitSurface(txtquest3, NULL, screen, &txtquest3pos);
SDL_BlitSurface(txtquest4, NULL, screen, &txtquest4pos);
SDL_BlitSurface(txt2quest4, NULL, screen, &txt2quest4pos);
SDL_BlitSurface(txtquest5, NULL, screen, &txtquest5pos);

SDL_BlitSurface(txt2quest5, NULL, screen, &txt2quest5pos);
SDL_BlitSurface(txtquest6, NULL, screen, &txtquest6pos);
SDL_BlitSurface(txt2quest6, NULL, screen, &txt2quest6pos);
SDL_BlitSurface(txtcompletion, NULL, screen, &txtcompletionpos);
SDL_BlitSurface(txttabtohide, NULL, screen, &txttabtohidepos);
}
else {
SDL_BlitSurface(txttabtoshow, NULL, screen, &txttabtoshowpos);
SDL_BlitSurface(txttabtoshowquests, NULL, screen, &txttabtoshowquestspos);}

        pos=p.image_perso.pos_img_ecran.x+(b.background_ocean).pos_img_affiche.x;
        if (pos>1600 && pos<2400)
        {
            where_am_i.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+40;
       	    where_am_i.pos_img_ecran.y=p.image_perso.pos_img_ecran.y-60;
            SDL_BlitSurface(where_am_i.img,NULL,screen,&where_am_i.pos_img_ecran);
        }        
	animerPerso(&p);
        projectiles_movement(&b, p.direction,0);
        float_items(&b, &angle,frequency,amplitude,speed/2);
        SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran);
        SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
        sprintf(char_rose_counter, "  %d", rose_counter);
        afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
        afficherPerso(p,screen);
        MAJMinimap(p,&m,b.camera,redimensionnement);
        nowtime=SDL_GetTicks();nowtime-=last;
        afficher (m,screen);
        afficher_texte_temps(screen,txte,nowtime);
        SDL_Flip(screen);
	if(p.mana<3) p.mana+=0.003;
        if(p.acceleration > 0 ) p.acceleration-=0.1;
	 //
        if(dust_effect!=0)
        {

            SDL_BlitSurface(b.image_dust.img,&b.image_dust.pos_img_affiche,screen,&b.image_dust.pos_img_ecran);
            SDL_Flip(screen);
            if(cpt%3==0)
            {
                if (p.image_perso.pos_img_ecran.x<60 && b.level==1) b.image_dust.pos_img_ecran.x+=15;
                b.image_dust.pos_img_affiche.y=27;
                b.image_dust.pos_img_affiche.x+=65;
                dust_effect++;
            }
            if(dust_effect>10)
            {
                dust_effect=0;
                b.image_dust.pos_img_affiche.x=0;
            }
        }
        //
    }

}//icispace
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_z && collision_ladder(&b.mask,p.image_perso.pos_img_ecran,b)==1 && b.level==1)
{
	int dtt=1;
	while(dtt==1)
	{
	p.image_perso.pos_img_ecran.y-=5;
	SDL_PollEvent(&event);
	if (event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_z || collision_ladder(&b.mask,p.image_perso.pos_img_ecran,b)==0)  {dtt=0;}
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
     afficherBack(b,screen);
if(tab==1)
{
SDL_BlitSurface(quest_box.img,NULL,screen,&quest_box.pos_img_ecran);
SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
SDL_BlitSurface(txtquest1, NULL, screen, &txtquest1pos);
SDL_BlitSurface(txt2quest1, NULL, screen, &txt2quest1pos);
SDL_BlitSurface(txtquest2, NULL, screen, &txtquest2pos);
SDL_BlitSurface(txt2quest2, NULL, screen, &txt2quest2pos);
SDL_BlitSurface(txtquest3, NULL, screen, &txtquest3pos);
SDL_BlitSurface(txtquest4, NULL, screen, &txtquest4pos);
SDL_BlitSurface(txt2quest4, NULL, screen, &txt2quest4pos);
SDL_BlitSurface(txtquest5, NULL, screen, &txtquest5pos);

SDL_BlitSurface(txt2quest5, NULL, screen, &txt2quest5pos);
SDL_BlitSurface(txtquest6, NULL, screen, &txtquest6pos);
SDL_BlitSurface(txt2quest6, NULL, screen, &txt2quest6pos);
SDL_BlitSurface(txtcompletion, NULL, screen, &txtcompletionpos);
SDL_BlitSurface(txttabtohide, NULL, screen, &txttabtohidepos);
}
else {
SDL_BlitSurface(txttabtoshow, NULL, screen, &txttabtoshowpos);
SDL_BlitSurface(txttabtoshowquests, NULL, screen, &txttabtoshowquestspos);}
     projectiles_movement(&b,p.direction,1);
     SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
     SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
     sprintf(char_rose_counter, "  %d", rose_counter);
     afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
     afficherPerso(p,screen);
     MAJMinimap(p,&m,b.camera,redimensionnement);
     nowtime=SDL_GetTicks();nowtime-=last;
     afficher(m,screen);
     afficher_texte_temps(screen,txte,nowtime);
	SDL_Flip(screen);
	}
}
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_z && collision_ladder(&b.mask2,p.image_perso.pos_img_ecran,b)==1 && b.level==2)
{
	int dtt=1;
	while(dtt==1)
	{
	p.image_perso.pos_img_ecran.y-=5;
	SDL_PollEvent(&event);
	if (event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_z || collision_ladder(&b.mask2,p.image_perso.pos_img_ecran,b)==0)  {dtt=0;}
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
     afficherBack(b,screen);
if(tab==1)
{
SDL_BlitSurface(quest_box.img,NULL,screen,&quest_box.pos_img_ecran);
SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
SDL_BlitSurface(txtquest1, NULL, screen, &txtquest1pos);
SDL_BlitSurface(txt2quest1, NULL, screen, &txt2quest1pos);
SDL_BlitSurface(txtquest2, NULL, screen, &txtquest2pos);
SDL_BlitSurface(txt2quest2, NULL, screen, &txt2quest2pos);
SDL_BlitSurface(txtquest3, NULL, screen, &txtquest3pos);
SDL_BlitSurface(txtquest4, NULL, screen, &txtquest4pos);
SDL_BlitSurface(txt2quest4, NULL, screen, &txt2quest4pos);
SDL_BlitSurface(txtquest5, NULL, screen, &txtquest5pos);

SDL_BlitSurface(txt2quest5, NULL, screen, &txt2quest5pos);
SDL_BlitSurface(txtquest6, NULL, screen, &txtquest6pos);
SDL_BlitSurface(txt2quest6, NULL, screen, &txt2quest6pos);
SDL_BlitSurface(txtcompletion, NULL, screen, &txtcompletionpos);
SDL_BlitSurface(txttabtohide, NULL, screen, &txttabtohidepos);
}
else {
SDL_BlitSurface(txttabtoshow, NULL, screen, &txttabtoshowpos);
SDL_BlitSurface(txttabtoshowquests, NULL, screen, &txttabtoshowquestspos);}
     projectiles_movement(&b,p.direction,1);
     SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
     SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
     sprintf(char_rose_counter, "  %d", rose_counter);
     afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
     afficherPerso(p,screen);
     MAJMinimap(p,&m,b.camera,redimensionnement);
     nowtime=SDL_GetTicks();nowtime-=last;
     afficher(m,screen);
     afficher_texte_temps(screen,txte,nowtime);
	SDL_Flip(screen);
	}
}
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_s && collision_ladder(&b.mask,p.image_perso.pos_img_ecran,b)==1 && b.level==1)
{
	int dtt=1;
	while(dtt==1)
	{
	p.image_perso.pos_img_ecran.y+=5;
	SDL_PollEvent(&event);
	if (event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_s || collision_ladder(&b.mask,p.image_perso.pos_img_ecran,b)==0)  {dtt=0;}
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
     afficherBack(b,screen);
if(tab==1)
{
SDL_BlitSurface(quest_box.img,NULL,screen,&quest_box.pos_img_ecran);
SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
SDL_BlitSurface(txtquest1, NULL, screen, &txtquest1pos);
SDL_BlitSurface(txt2quest1, NULL, screen, &txt2quest1pos);
SDL_BlitSurface(txtquest2, NULL, screen, &txtquest2pos);
SDL_BlitSurface(txt2quest2, NULL, screen, &txt2quest2pos);
SDL_BlitSurface(txtquest3, NULL, screen, &txtquest3pos);
SDL_BlitSurface(txtquest4, NULL, screen, &txtquest4pos);
SDL_BlitSurface(txt2quest4, NULL, screen, &txt2quest4pos);
SDL_BlitSurface(txtquest5, NULL, screen, &txtquest5pos);

SDL_BlitSurface(txt2quest5, NULL, screen, &txt2quest5pos);
SDL_BlitSurface(txtquest6, NULL, screen, &txtquest6pos);
SDL_BlitSurface(txt2quest6, NULL, screen, &txt2quest6pos);
SDL_BlitSurface(txtcompletion, NULL, screen, &txtcompletionpos);
SDL_BlitSurface(txttabtohide, NULL, screen, &txttabtohidepos);
}
else {
SDL_BlitSurface(txttabtoshow, NULL, screen, &txttabtoshowpos);
SDL_BlitSurface(txttabtoshowquests, NULL, screen, &txttabtoshowquestspos);}
     projectiles_movement(&b,p.direction,1);
     SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
     SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
     sprintf(char_rose_counter, "  %d", rose_counter);
     afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
     afficherPerso(p,screen);
     MAJMinimap(p,&m,b.camera,redimensionnement);
     nowtime=SDL_GetTicks();nowtime-=last;
     afficher(m,screen);
     afficher_texte_temps(screen,txte,nowtime);
	SDL_Flip(screen);
	}
}
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_s && collision_ladder(&b.mask2,p.image_perso.pos_img_ecran,b)==1 && b.level==2)
{
	int dtt=1;
	while(dtt==1)
	{
	p.image_perso.pos_img_ecran.y+=5;
	SDL_PollEvent(&event);
	if (event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_s || collision_ladder(&b.mask2,p.image_perso.pos_img_ecran,b)==0)  {dtt=0;}
(b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
     afficherBack(b,screen);
if(tab==1)
{
SDL_BlitSurface(quest_box.img,NULL,screen,&quest_box.pos_img_ecran);
SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
SDL_BlitSurface(txtquest1, NULL, screen, &txtquest1pos);
SDL_BlitSurface(txt2quest1, NULL, screen, &txt2quest1pos);
SDL_BlitSurface(txtquest2, NULL, screen, &txtquest2pos);
SDL_BlitSurface(txt2quest2, NULL, screen, &txt2quest2pos);
SDL_BlitSurface(txtquest3, NULL, screen, &txtquest3pos);
SDL_BlitSurface(txtquest4, NULL, screen, &txtquest4pos);
SDL_BlitSurface(txt2quest4, NULL, screen, &txt2quest4pos);
SDL_BlitSurface(txtquest5, NULL, screen, &txtquest5pos);

SDL_BlitSurface(txt2quest5, NULL, screen, &txt2quest5pos);
SDL_BlitSurface(txtquest6, NULL, screen, &txtquest6pos);
SDL_BlitSurface(txt2quest6, NULL, screen, &txt2quest6pos);
SDL_BlitSurface(txtcompletion, NULL, screen, &txtcompletionpos);
SDL_BlitSurface(txttabtohide, NULL, screen, &txttabtohidepos);
}
else {
SDL_BlitSurface(txttabtoshow, NULL, screen, &txttabtoshowpos);
SDL_BlitSurface(txttabtoshowquests, NULL, screen, &txttabtoshowquestspos);}
     projectiles_movement(&b,p.direction,1);
     SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
     SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
     sprintf(char_rose_counter, "  %d", rose_counter);
     afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
     afficherPerso(p,screen);
     MAJMinimap(p,&m,b.camera,redimensionnement);
     nowtime=SDL_GetTicks();nowtime-=last;
     afficher(m,screen);
     afficher_texte_temps(screen,txte,nowtime);
	SDL_Flip(screen);
	}
}
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE && air ==0)
{initialiser_audio_jump(music_jump);
   is_saut=1;
   while(is_saut)
	{
	if (collision_item(b.rose2.pos_img_ecran, p.image_perso.pos_img_ecran) && b.rose2_is_collected==0) 
	{
		b.rose2_is_collected=1;
		rose_counter++;	
		showrose2=1;
		initialiser_audio_score(music_score);
	}
	else if (collision_item(b.heart1.pos_img_ecran, p.image_perso.pos_img_ecran) && b.heart1_is_collected==0) 
	{
		b.heart1_is_collected=1;
		p.nb_vies++;
		initialiser_audio_score(music_collect);
	}
else if (grace>50 && (collision(b.e.vertical1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision(b.e.vertical3.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical4.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical5.pos_img_ecran, p.image_perso.pos_img_ecran)  || collision(b.e.vertical6.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal1.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal2.pos_img_ecran, p.image_perso.pos_img_ecran) || collision_horizontal(b.e.horizontal3.pos_img_ecran, p.image_perso.pos_img_ecran)))
        {
		if(grace>50) {p.nb_vies--; 		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10) damage_variable=1;grace=0;}
        }
	if(grace<50) 
	{
		if (a%4==0) p.sprite=IMG_Load("images/spritefinal.png");
		else if (a%4==1) p.sprite=IMG_Load("images/gracesprite30.png");
		else if (a%4==2) p.sprite=IMG_Load("images/gracesprite60.png");
		else if (a%4==3) p.sprite=IMG_Load("images/gracesprite30.png");
	}	
	else if (grace<60) p.sprite=IMG_Load("images/spritefinal.png");
	a++;
    if (reversed==0) 
{ 
        p.image_perso.pos_img_ecran.y-=5;
        //if(p.image_perso.pos_img_ecran.y<ground_y-60) up=1; //635
        //else if(p.image_perso.pos_img_ecran.y>ground_y-10) up=0;
        //if(p.image_perso.pos_img_ecran.y<ground_y) air =1;
        //else air=0;
}

    //else if (reversed==1) p.image_perso.pos_img_ecran.y+=5;
     (b.tab_frames[b.i]).pos_img_affiche.x=(b.background_ocean).pos_img_affiche.x;
     afficherBack(b,screen);
if(tab==1)
{
SDL_BlitSurface(quest_box.img,NULL,screen,&quest_box.pos_img_ecran);
SDL_BlitSurface(txtbonus, NULL, screen, &txtbonuspos);
SDL_BlitSurface(txtquest1, NULL, screen, &txtquest1pos);
SDL_BlitSurface(txt2quest1, NULL, screen, &txt2quest1pos);
SDL_BlitSurface(txtquest2, NULL, screen, &txtquest2pos);
SDL_BlitSurface(txt2quest2, NULL, screen, &txt2quest2pos);
SDL_BlitSurface(txtquest3, NULL, screen, &txtquest3pos);
SDL_BlitSurface(txtquest4, NULL, screen, &txtquest4pos);
SDL_BlitSurface(txt2quest4, NULL, screen, &txt2quest4pos);
SDL_BlitSurface(txtquest5, NULL, screen, &txtquest5pos);

SDL_BlitSurface(txt2quest5, NULL, screen, &txt2quest5pos);
SDL_BlitSurface(txtquest6, NULL, screen, &txtquest6pos);
SDL_BlitSurface(txt2quest6, NULL, screen, &txt2quest6pos);
SDL_BlitSurface(txtcompletion, NULL, screen, &txtcompletionpos);
SDL_BlitSurface(txttabtohide, NULL, screen, &txttabtohidepos);
}
else {
SDL_BlitSurface(txttabtoshow, NULL, screen, &txttabtoshowpos);
SDL_BlitSurface(txttabtoshowquests, NULL, screen, &txttabtoshowquestspos);}
     projectiles_movement(&b,p.direction,1);
     SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
     SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
     sprintf(char_rose_counter, "  %d", rose_counter);
     afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
     afficherPerso(p,screen);
     MAJMinimap(p,&m,b.camera,redimensionnement);
     nowtime=SDL_GetTicks();nowtime-=last;
     afficher(m,screen);
     afficher_texte_temps(screen,txte,nowtime);
	     if (pos>1600 && pos<2400)  
   	 {
        where_am_i.pos_img_ecran.x=p.image_perso.pos_img_ecran.x+40;
        where_am_i.pos_img_ecran.y=p.image_perso.pos_img_ecran.y-60;
	SDL_BlitSurface(where_am_i.img,NULL,screen,&where_am_i.pos_img_ecran);
   	 }
     SDL_Flip(screen);
    SDL_PollEvent(&event);
    if(collision_perfect(&b.mask,p.image_perso.pos_img_ecran, b)!=0 ||(event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_SPACE ) || (p.image_perso.pos_img_ecran.y<ground_y-60 && reversed==0) || (p.image_perso.pos_img_ecran.y>120 && reversed==1) ) {is_saut=0;}
    else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_d) p.image_perso.pos_img_ecran.x+=5;
    else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_q) p.image_perso.pos_img_ecran.x-=5;
	}
}
 else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_m)
{
	cpt_mus++;
	if (cpt_mus==4) cpt_mus=1;
	audio_level1(b.level1_music,volume_music, cpt_mus);
}

if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_f)
{

}
/*
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
} */

else if((event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT && (event.motion.y<=150 && event.motion.y>=50 && event.motion.x<=305 && event.motion.x>=50)) || (SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE))
{
    initialiser_audiobref(mus);
    multiplayer=0;
    fleche=0;
    boucle_play=0;//quitter play
    initialiser_audio_mainmenu(music,volume_music);
    break;
}

else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_UP)
{
 p.image_perso.pos_img_ecran.y-=120;
}
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_DOWN)
{
  p.image_perso.pos_img_ecran.y+=120;
}
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_RIGHT)
{
p.image_perso.pos_img_ecran.x+=120;
}
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LEFT)
{
p.image_perso.pos_img_ecran.x-=120;
}
else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_h)
            {
		p.score+=10;
		p.nb_vies--;
		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10) damage_variable=1;
		shake_image(&p.image_vies,5,5,b,screen);
		if(p.mana>1)p.mana--;
                SDL_Delay(100);

            }
if(event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_TAB) 
{
if (tab==0) tab=1;
else tab=0;
}/*
if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_w)
{
    float thirdleveltransition=40;
    p.image_perso.pos_img_ecran.x=1350;
    while(p.image_perso.pos_img_ecran.x>650)
    {
        (b.background_ocean).pos_img_affiche.x+=thirdleveltransition;
	b.mini.pos_img_affiche.x+=thirdleveltransition/3.9;
	b.mask.pos_img_affiche.x+=thirdleveltransition; 
        b.camera.x+=thirdleveltransition;
        p.image_perso.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical1.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical2.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical3.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical4.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical5.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical6.pos_img_ecran.x-=thirdleveltransition;
	b.e.horizontal1.pos_img_ecran.x-=thirdleveltransition;
	b.e.horizontal2.pos_img_ecran.x-=thirdleveltransition;
	b.e.horizontal3.pos_img_ecran.x-=thirdleveltransition;
	
	b.rose1.pos_img_ecran.x-=thirdleveltransition;
	b.rose2.pos_img_ecran.x-=thirdleveltransition;
	b.rose3.pos_img_ecran.x-=thirdleveltransition;
	b.heart1.pos_img_ecran.x-=thirdleveltransition;
	b.heart2.pos_img_ecran.x-=thirdleveltransition;

	b.image_snake.pos_img_ecran.x-=thirdleveltransition; 
	b.image_napta.pos_img_ecran.x-=thirdleveltransition;

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
    limit=15378; b.m=2;
    p.image_perso.pos_img_ecran.y=650;
} 	*/
if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e)
{
    SDL_EnableKeyRepeat(0,0);
    az=2;
    pos=p.image_perso.pos_img_ecran.x+b.background_ocean.pos_img_affiche.x;
    if (pos>2800 && pos<2990)
    {
        if (dial1==-1)
        {
            dial1=1;
            SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
            dial_text = "May the winds of fate guide you in your journey!";
            typewriter(dial_text,screen,280,event);
            while (dial1==1)
            {
                SDL_PollEvent(&event);
                if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e) dial1=-1;
            }
        }
        else
        {
            while (dial1!=0)
            {
                if (az>2) 
		{  
		SDL_WaitEvent(&event);
		if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e)
                {
                    az++;
                    dial1=az;
                }
		}
		else az++;
                switch(dial1)
                {
                case 1:
                    break;
                case 2:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "Excuse me, sir. Where am I?";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 3:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "IN Terravale, A KINGDOM LOST IN TIME,";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "A land of beauty and grace, now laid to grime,";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 4:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "What happened here?";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 5:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "A tragedy befell this once-great place, ";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "Leaving ruins and sorrow, and a somber space.";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 6:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "Do you know what caused the fall?";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 7:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "Alas, the tales of old are faded and worn, ";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "And the reason for the ruin remains forlorn.";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 8:
                    dial1=0;
                    break;
                }
                afficherBack(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                afficherPerso(p,screen);
                if (dial1!=0) dial1=1;

            }
        }
        dial1=-1;
    }
    else if (p.image_perso.pos_img_ecran.x>100 && p.image_perso.pos_img_ecran.x<300 && b.level==3)
    {
	p.image_perso.pos_img_affiche.x=0;
	p.image_perso.pos_img_affiche.y=263;
               afficherBack(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                afficherPerso(p,screen);
SDL_Flip(screen);
        if (dial2==-1)
        {
            dial2=1;
            SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
            dial_text = "Go, Hurry...";
            typewriter(dial_text,screen,280,event);
            while (dial2==1)
            {
                SDL_WaitEvent(&event);
                if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e) dial2=-1;
            }
        }
        else
        {
            while (dial2!=0)
            {
		if (az>2) 
		{  
		SDL_WaitEvent(&event);
		if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e)
                {
                    az++;
                    dial2=az;
                }
		}
		else az++;
                switch(dial2)
                {
                case 1:
                    break;
                case 2:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "Adventurer, we cross paths once more,";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 3:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "What happened?" ;
                    typewriter(dial_text,screen,280,event);
                    break;
                case 4:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "Amidst uncharted realms, I dared to tread,";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "But with one misstep, I plummeted instead.";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 6:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "Why did you come down here?";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 7:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "I heard a cry of anguish, a sound so dire, ";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "My heart swelled with the weight of someone's mire.";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 8:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "Wilt thou venture to the caverns deep, ";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "And seek the source of these tears to keep?";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 9:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "Fear not for me, I shall manage alone. ";
                    typewriter(dial_text,screen,280,event);
                case 10:
                    dial2=0;
                    break;
                }
                afficherBack(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                afficherPerso(p,screen);
                if (dial2!=0) dial2=1;
            }
        }
        dial2=-1;
    }
    else if (p.image_perso.pos_img_ecran.x>50 && p.image_perso.pos_img_ecran.x<250 && b.level==2)
    {
	p.image_perso.pos_img_affiche.x=0;
	p.image_perso.pos_img_affiche.y=263;
               afficherBack(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                afficherPerso(p,screen);
SDL_Flip(screen);
	if (mob>100 && mob<150)
	{
	b.image_shelly.pos_img_affiche.x+=72;
	if (b.image_shelly.pos_img_affiche.x>800) b.image_shelly.pos_img_affiche.x=0;
	}
        if (dial3==-1)
        {
            dial3=1;
            SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
            dial_text = "Please...";
            typewriter(dial_text,screen,280,event);
            while (dial3==1)
            {
                SDL_PollEvent(&event);
                if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e) dial3=-1;
            }
        }else
        {
            while (dial3!=0)
            {
		if (az>2) 
		{  
		SDL_WaitEvent(&event);
		if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e)
                {
                    az++;
                    dial3=az;
                }
		}
		else az++;
                switch(dial3)
                {
                case 1:
                    break;
                case 2:
                    SDL_BlitSurface(image_shelly_box.img,NULL,screen,&image_shelly_box.pos_img_ecran);
                    dial_text =  "Help! Please, someone, help me!";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 3:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "Hey, are you okay?" ;
                    typewriter(dial_text,screen,280,event);
                    break;
                case 4:
                    SDL_BlitSurface(image_shelly_box.img,NULL,screen,&image_shelly_box.pos_img_ecran);
                    dial_text = "Who...who are you?";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 6:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "I'm here to save you. What happened?";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 7:
                    SDL_BlitSurface(image_shelly_box.img,NULL,screen,&image_shelly_box.pos_img_ecran);
                    dial_text ="No time to explain,";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "I don't know how much longer I can hold on.";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 8:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "Don't worry, I'll get you out of there. ";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "Hmm, this looks like some kind of puzzle.";
                    typewriter(dial_text,screen,340,event);
                    dial_text = "I'll have to solve it to release you.";
                    typewriter(dial_text,screen,400,event);
                    break;
                case 9:
                    SDL_BlitSurface(image_shelly_box.img,NULL,screen,&image_shelly_box.pos_img_ecran);
                    dial_text = "Please hurry,";
                    typewriter(dial_text,screen,280,event);
                case 10:
                    dial3=0;
                    break;
                }
                afficherBack(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                afficherPerso(p,screen);
                if (dial3!=0) dial3=1;
            }
        }
        dial3=-1;float nad=8;
    init_back(&back);
    afficher_back(back,screen);
    fade_in(txtpuzz.img,back,screen,txtpuzz.pos_img_ecran);
    SDL_Delay(500);
    init_dos(&e);
    while(txtpuzz1.pos_img_ecran.y>50)
    {
	txtpuzz1.pos_img_ecran.y-=nad;
	txtpuzz2.pos_img_ecran.y+=nad;
	afficher_back(back,screen);
	SDL_BlitSurface(txtpuzz1.img,NULL,screen,&txtpuzz1.pos_img_ecran);
	SDL_BlitSurface(txtpuzz2.img,NULL,screen,&txtpuzz2.pos_img_ecran);
	SDL_Flip(screen);
	if (txtpuzz1.pos_img_ecran.y<200 && nad>1) nad-=0.25;
    }
    afficherEnigme(e,screen);
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
    for(j=1; j<9; j++)
    {
        do
        {
            rando = rand() % 8;
        }
        while(recherche(rando, rand_pris, 8));
        rand_pris[j-1]=rando;
        carte_alea[j]=carte[rando+1];
    }
    position[1].x = 320;
    position[1].y = 125;

    position[2].x = 540;
    position[2].y = 125;

    position[3].x = 760;
    position[3].y = 125;

    position[4].x = 980;
    position[4].y = 125;

    position[5].x = 320;
    position[5].y = 425;

    position[6].x = 540;
    position[6].y = 425;

    position[7].x = 760;
    position[7].y = 425;

    position[8].x = 980;
    position[8].y = 425;
 nowtime=SDL_GetTicks();nowtime-=last;
 puzzle1timestart=nowtime; 
    while (continuer)
    {
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
                    for(po=1; po<9; po++)
                    {
			SDL_PollEvent(&event);
                        if((event.type==SDL_MOUSEBUTTONDOWN) && ( event.button.button==SDL_BUTTON_LEFT && event.motion.y>=position[po].y && event.motion.y<=position[po].y+250 && event.motion.x>=position[po].x && event.motion.x<=position[po].x+150))
                        {
                            o=po;
                            cont++;
                        }
                    }
                    if(cont==1)
                    {
                        last_pos=o;
                    }
                    SDL_BlitSurface(carte_alea[o].img, NULL, screen, &position[o]);
                    SDL_Flip(screen);
                    SDL_Delay(100);
                    if(cont==2)
                    {
                        SDL_BlitSurface(carte_alea[last_pos].img, NULL, screen, &position[last_pos]);
                        SDL_Flip(screen);
                        SDL_Delay(100);
                        SDL_BlitSurface(carte_alea[o].img,NULL,screen,&position[o]);
                        SDL_Flip(screen);
                        SDL_Delay(100);
                        if(check(carte_alea[o].url,carte_alea[last_pos].url)!=1)
                        {
                            SDL_BlitSurface(e.img,NULL,screen,&position[last_pos]);
                            SDL_BlitSurface(e.img,NULL,screen,&position[o]);
                            SDL_Delay(1000);
                            lose_condition--;
                        }
                        else
                            win_condition++;
                        cont=0;
                    }
                    SDL_Delay(100);
                    SDL_Flip(screen);
                    break;
                }
                if(lose_condition==-3)
                {
 nowtime=SDL_GetTicks();nowtime-=last;
 puzzle1time=nowtime-puzzle1timestart;
                    afficher_back(back,screen);
    		    fade_in(txtpuzzfail1.img,back,screen,txtpuzzfail1.pos_img_ecran);
		    SDL_Delay(250);
		    afficher_back(back,screen);
    		    fade_in2(txtpuzzfail2.img,back,screen,txtpuzzfail2.pos_img_ecran,txtbacklost);
		    SDL_Delay(2500);
                    continuer=0;
                }
                if(win_condition==4)
                {       
 nowtime=SDL_GetTicks();nowtime-=last;
 puzzle1time=nowtime-puzzle1timestart;          
		    afficher_back(back,screen);
    		    fade_in(txtpuzzwin1.img,back,screen,txtpuzzwin1.pos_img_ecran);
		    SDL_Delay(250);
		    afficher_back(back,screen);
    		    fade_in2(txtpuzzwin2.img,back,screen,txtpuzzwin2.pos_img_ecran,txtbackwin);
		    SDL_Delay(4500);
                    continuer=0;
                }
            }
        }
    }
b.level=1;
mx=3;
b.pt=1;
p.image_perso.pos_img_ecran.x=500;
p.image_perso.pos_img_ecran.y=100;
audio_level1(b.level1_music,volume_music, mx);

SDL_FreeSurface(b.background_forest.img);
SDL_FreeSurface(b.image_shelly.img);
SDL_FreeSurface(b.background_fall.img);
SDL_FreeSurface(image_shelly_box.img);
/*SDL_FreeSurface(txtpuzzwin1.img);
SDL_FreeSurface(txtpuzzwin2.img);
SDL_FreeSurface(txtpuzzwin2.img);
SDL_FreeSurface(txtpuzzfail1.img);
SDL_FreeSurface(txtpuzzfail2.img);
SDL_FreeSurface(txtbackwin.img);
SDL_FreeSurface(txtbacklost.img);*/
SDL_FreeSurface(e.img);
    }
else if (pos>7555 && pos<7700)
    {
        image_snake_box.pos_img_ecran.y=300;
        image_you_box.pos_img_ecran.y=300;
        if (dial4==-1)
        {
            dial4=1;
            SDL_BlitSurface(image_snake_box.img,NULL,screen,&image_snake_box.pos_img_ecran);
            dial_text = "sss...";
            typewriter(dial_text,screen,280,event);
            while (dial4==1)
            {
                SDL_PollEvent(&event);
                if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e) dial4=-1;
            }
        }
        else
        {
            while (dial4!=0)
            {
                if (az>2)
                {
                    SDL_WaitEvent(&event);
                    if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e)
                    {
                        az++;
                        dial4=az;
                    }
                }
                else az++;
                switch(dial4)
{
case 1:
    break;
case 2:
    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
    dial_text =  "My path seems to have led me astray.";
    typewriter(dial_text,screen,348,event);
    dial_text = "I am seeking a way to save the world";
    typewriter(dial_text,screen,408,event);
    dial_text = "from an impending doom.";
    typewriter(dial_text,screen,468,event);
    break;
case 4:
    SDL_BlitSurface(image_snake_box.img,NULL,screen,&image_snake_box.pos_img_ecran);
    dial_text = "Greetingsss... wanderer." ;
    typewriter(dial_text,screen,348,event);
    dial_text = "It seems you have ssstumbled upon";
    typewriter(dial_text,screen,408,event);
    dial_text = "a riddle in your journey.";
    typewriter(dial_text,screen,468,event);
    break;
case 5:
    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
    dial_text = " A riddle?";
    typewriter(dial_text,screen,348,event);
    break;
case 7:
    SDL_BlitSurface(image_snake_box.img,NULL,screen,&image_snake_box.pos_img_ecran);
    dial_text = "Indeed. I am the keeper of thisss ancient forest,";
    typewriter(dial_text,screen,348,event);
    dial_text = "and only those who can solve my puzzle may passs...";
    typewriter(dial_text,screen,408,event);
    break;
case 8:
    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
    dial_text ="I accept your challenge. ";
    typewriter(dial_text,screen,348,event);
    dial_text = "What is this puzzle you speak of?";
    typewriter(dial_text,screen,408,event);
    break;
case 9:
    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
    dial_text = "My puzzle is sssimple, yet complex.";
    typewriter(dial_text,screen,348,event);
    dial_text = "You must tell me the answer to this riddle:";
    typewriter(dial_text,screen,408,event);
    break;
case 10:
    randforriddle= rand() % 3;
    if (randforriddle==0)
    {
        SDL_BlitSurface(image_snake_box.img,NULL,screen,&image_snake_box.pos_img_ecran);
        dial_text ="What has roots as nobody sees, Is taller than trees,";
        typewriter(dial_text,screen,348,event);
        dial_text = "Up, up it goes, And yet never grows?";
        typewriter(dial_text,screen,408,event);
        SDL_Delay(250);
        dial_text ="    mountain            tree            hair";
        typewriter(dial_text,screen,480,event);
    }
    else if (randforriddle==1)
    {
        SDL_BlitSurface(image_snake_box.img,NULL,screen,&image_snake_box.pos_img_ecran);
        dial_text ="Large as a mountain, small as a pea,";
        typewriter(dial_text,screen,348,event);
        dial_text = "Endlessly swimming in a waterless sea.";
        typewriter(dial_text,screen,400,event);
        SDL_Delay(250);
        dial_text ="    Asteroids            Atoms           Fly";
        typewriter(dial_text,screen,480,event);
    }
    else
    {
        SDL_BlitSurface(image_snake_box.img,NULL,screen,&image_snake_box.pos_img_ecran);
        dial_text ="I touch your face, I'm in your words,";
        typewriter(dial_text,screen,348,event);
        dial_text = "I'm lack of space and beloved by birds.";
        typewriter(dial_text,screen,400,event);
        SDL_Delay(250);
        dial_text ="      air            sound             water";
        typewriter(dial_text,screen,480,event);
    }
    SDL_EventState(SDL_MOUSEMOTION,SDL_ENABLE);
nowtime=SDL_GetTicks(); nowtime-=last;
puzzle2timestart=nowtime;
    while (snake)
    {
nowtime=SDL_GetTicks(); nowtime-=last;
puzzle2time=nowtime-puzzle2timestart;
        SDL_PollEvent(&event);
	if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_RIGHT) {flecheforriddle++; SDL_Delay(100);}
	else if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LEFT) {flecheforriddle--; SDL_Delay(100);}
	flecheforriddle=flecheforriddle%4;
        if  (event.motion.y<=495 && event.motion.y>=445 && event.motion.x<=500 && event.motion.x>=320 || flecheforriddle==1 || flecheforriddle==-3)
        {
            afficherBack(b,screen);
            afficher_texte_temps(screen,txte,nowtime);
            SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
            SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
            sprintf(char_rose_counter, "  %d", rose_counter);
            afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
            afficherPerso(p,screen);
            SDL_BlitSurface(image_snake_box.img,NULL,screen,&image_snake_box.pos_img_ecran);

            switch (randforriddle)
            {
            case 0:
                texet=TTF_RenderText_Solid(arcade_font, "What has roots as nobody sees, Is taller than trees,", white_color);
                SDL_Rect recet= {235,332,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet);
                texet=TTF_RenderText_Solid(arcade_font, "Up, up it goes, And yet never grows?", white_color);
                SDL_Rect recet2= {235,385,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet2);
                surfaceforriddle = TTF_RenderText_Solid(arcade_font, "   >mountain<           tree            hair", white_color);
                break;
            case 1:
                texet=TTF_RenderText_Solid(arcade_font, "Large as a mountain, small as a pea,", white_color);
                SDL_Rect recet3= {235,332,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet3);
                texet=TTF_RenderText_Solid(arcade_font, "Endlessly swimming in a waterless sea.", white_color);
                SDL_Rect recet4= {235,385,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet4);
                surfaceforriddle = TTF_RenderText_Solid(arcade_font, "   >Asteroids<           Atoms           Fly", white_color);
                break;
            default:
                texet=TTF_RenderText_Solid(arcade_font, "I touch your face, I'm in your words,", white_color);
                SDL_Rect recet5= {235,332,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet5);
                texet=TTF_RenderText_Solid(arcade_font, "I'm lack of space and beloved by birds.", white_color);
                SDL_Rect recet6= {235,385,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet6);
                surfaceforriddle = TTF_RenderText_Solid(arcade_font, "     >air<            sound             water", white_color);
                break;
            }
            SDL_Rect rectforriddle = { 235, 460, 0, 0 };
            SDL_BlitSurface(surfaceforriddle, NULL, screen, &rectforriddle);
        }
        else if  (event.motion.y<=495 && event.motion.y>=445 && event.motion.x<=840 && event.motion.x>=640 ||flecheforriddle==2 || flecheforriddle==-2)
        {
            afficherBack(b,screen);
            afficher_texte_temps(screen,txte,nowtime);
            SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
            SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
            sprintf(char_rose_counter, "  %d", rose_counter);
            afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
            afficherPerso(p,screen);
            SDL_BlitSurface(image_snake_box.img,NULL,screen,&image_snake_box.pos_img_ecran);

            switch (randforriddle)
            {
            case 0:
                texet=TTF_RenderText_Solid(arcade_font, "What has roots as nobody sees, Is taller than trees,", white_color);
                SDL_Rect recet= {235,332,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet);
                texet=TTF_RenderText_Solid(arcade_font, "Up, up it goes, And yet never grows?", white_color);
                SDL_Rect recet2= {235,385,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet2);
                surfaceforriddle = TTF_RenderText_Solid(arcade_font, "    mountain           >tree<           hair", white_color);
                break;
            case 1:
                texet=TTF_RenderText_Solid(arcade_font, "Large as a mountain, small as a pea,", white_color);
                SDL_Rect recet3= {235,332,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet3);
                texet=TTF_RenderText_Solid(arcade_font, "Endlessly swimming in a waterless sea.", white_color);
                SDL_Rect recet4= {235,385,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet4);

                surfaceforriddle = TTF_RenderText_Solid(arcade_font, "    Asteroids           >Atoms<          Fly", white_color);
                break;
            default:
                texet=TTF_RenderText_Solid(arcade_font, "I touch your face, I'm in your words,", white_color);
                SDL_Rect recet5= {235,332,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet5);
                texet=TTF_RenderText_Solid(arcade_font, "I'm lack of space and beloved by birds.", white_color);
                SDL_Rect recet6= {235,385,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet6);
                surfaceforriddle = TTF_RenderText_Solid(arcade_font, "      air            >sound<            water", white_color);
                break;
            }
            SDL_Rect rectforriddle = { 235, 460, 0, 0 };
            SDL_BlitSurface(surfaceforriddle, NULL, screen, &rectforriddle);
        }
else if  (event.motion.y<=495 && event.motion.y>=445 && event.motion.x<=1140 && event.motion.x>=940|| flecheforriddle==3 || flecheforriddle==-1)
        {
            afficherBack(b,screen);
            afficher_texte_temps(screen,txte,nowtime);
            SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
            SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
            sprintf(char_rose_counter, "  %d", rose_counter);
            afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
            afficherPerso(p,screen);
            SDL_BlitSurface(image_snake_box.img,NULL,screen,&image_snake_box.pos_img_ecran);

            switch (randforriddle)
            {
            case 0:
                texet=TTF_RenderText_Solid(arcade_font, "What has roots as nobody sees, Is taller than trees,", white_color);
                SDL_Rect recet= {235,332,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet);
                texet=TTF_RenderText_Solid(arcade_font, "Up, up it goes, And yet never grows?", white_color);
                SDL_Rect recet2= {235,385,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet2);
                surfaceforriddle = TTF_RenderText_Solid(arcade_font, "    mountain            tree           >hair<", white_color);
                break;
            case 1:
                texet=TTF_RenderText_Solid(arcade_font, "Large as a mountain, small as a pea,", white_color);
                SDL_Rect recet3= {235,332,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet3);
                texet=TTF_RenderText_Solid(arcade_font, "Endlessly swimming in a waterless sea.", white_color);
                SDL_Rect recet4= {235,385,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet4);

                surfaceforriddle = TTF_RenderText_Solid(arcade_font, "    Asteroids            Atoms          >Fly<", white_color);
                break;
            default:
                texet=TTF_RenderText_Solid(arcade_font, "I touch your face, I'm in your words,", white_color);
                SDL_Rect recet5= {235,332,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet5);
                texet=TTF_RenderText_Solid(arcade_font, "I'm lack of space and beloved by birds.", white_color);
                SDL_Rect recet6= {235,385,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet6);
                surfaceforriddle = TTF_RenderText_Solid(arcade_font, "      air             sound            >water<", white_color);
                break;
            }
            SDL_Rect rectforriddle = { 235, 460, 0, 0 };
            SDL_BlitSurface(surfaceforriddle, NULL, screen, &rectforriddle);
        }
        else
        {
            afficherBack(b,screen);
            afficher_texte_temps(screen,txte,nowtime);
            SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
            SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
            sprintf(char_rose_counter, "  %d", rose_counter);
            afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
            afficherPerso(p,screen);
            SDL_BlitSurface(image_snake_box.img,NULL,screen,&image_snake_box.pos_img_ecran);
            switch (randforriddle)
            {
            case 0:
                texet=TTF_RenderText_Solid(arcade_font, "What has roots as nobody sees, Is taller than trees,", white_color);
                SDL_Rect recet= {235,332,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet);
                texet=TTF_RenderText_Solid(arcade_font, "Up, up it goes, And yet never grows?", white_color);
                SDL_Rect recet2= {235,385,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet2);
                surfaceforriddle = TTF_RenderText_Solid(arcade_font, "    mountain            tree            hair", white_color);
                break;
            case 1:
                texet=TTF_RenderText_Solid(arcade_font, "Large as a mountain, small as a pea,", white_color);
                SDL_Rect recet3= {235,332,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet3);
                texet=TTF_RenderText_Solid(arcade_font, "Endlessly swimming in a waterless sea.", white_color);
                SDL_Rect recet4= {235,385,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet4);
                surfaceforriddle = TTF_RenderText_Solid(arcade_font, "    Asteroids            Atoms           Fly", white_color);
                break;
            default:
                texet=TTF_RenderText_Solid(arcade_font, "I touch your face, I'm in your words,", white_color);
                SDL_Rect recet5= {235,332,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet5);
                texet=TTF_RenderText_Solid(arcade_font, "I'm lack of space and beloved by birds.", white_color);
                SDL_Rect recet6= {235,385,0,0};
                SDL_BlitSurface(texet, NULL, screen, &recet6);
                surfaceforriddle = TTF_RenderText_Solid(arcade_font, "    mountain            tree            hair", white_color);
                SDL_Rect rectforriddle = { 235, 460, 0, 0 };
                surfaceforriddle = TTF_RenderText_Solid(arcade_font, "      air             sound             water", white_color);
                break;
            }
            SDL_Rect rectforriddle = { 235, 460, 0, 0 };
            SDL_BlitSurface(surfaceforriddle, NULL, screen, &rectforriddle);
        }
        SDL_Flip(screen);
        if (((event.type==SDL_MOUSEBUTTONDOWN) && (event.motion.y<=485 && event.motion.y>=455 && event.motion.x<=500 && event.motion.x>=320))||((event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_RETURN) && (flecheforriddle==1|| flecheforriddle==-3)))
        {
            afficherBack(b,screen);
            afficher_texte_temps(screen,txte,nowtime);
            SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
            SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
            sprintf(char_rose_counter, "  %d", rose_counter);
            afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
            afficherPerso(p,screen);
            SDL_BlitSurface(image_snake_box.img,NULL,screen,&image_snake_box.pos_img_ecran);
            dial_text ="Well done, traveller.";
            typewriter(dial_text,screen,348,event);
            dial_text = "You have proven yourself worthy.";
            typewriter(dial_text,screen,400,event);
            dial_text = "Proceed with caution, for the road ahead is treacherous.";
            typewriter(dial_text,screen,452,event);
            while(1)
            {
                SDL_WaitEvent(&event);
                if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e)
                {
                    dial4=0;
	SDL_Delay(400);
    float thirdleveltransition=40;
    p.image_perso.pos_img_ecran.x=1350;
    while(p.image_perso.pos_img_ecran.x>650)
    {
	b.image_napta.pos_img_ecran.x-=thirdleveltransition; 
        (b.background_ocean).pos_img_affiche.x+=thirdleveltransition;
	b.mini.pos_img_affiche.x+=thirdleveltransition/3.9;
	b.mask.pos_img_affiche.x+=thirdleveltransition; 
        b.camera.x+=thirdleveltransition;
        p.image_perso.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical1.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical2.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical3.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical4.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical5.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical6.pos_img_ecran.x-=thirdleveltransition;
	b.e.horizontal1.pos_img_ecran.x-=thirdleveltransition;
	b.e.horizontal2.pos_img_ecran.x-=thirdleveltransition;
	b.e.horizontal3.pos_img_ecran.x-=thirdleveltransition;
	
	b.rose1.pos_img_ecran.x-=thirdleveltransition;
	b.rose2.pos_img_ecran.x-=thirdleveltransition;
	b.rose3.pos_img_ecran.x-=thirdleveltransition;
	b.heart1.pos_img_ecran.x-=thirdleveltransition;
	b.heart2.pos_img_ecran.x-=thirdleveltransition;

	
	b.image_snake.pos_img_ecran.x-=thirdleveltransition;

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
    limit=15350; b.m=2;
    p.image_perso.pos_img_ecran.y=650;
    p.image_perso.pos_img_ecran.x-=40;
                    break;
                }
            }
            break;
        }
        else if (((event.type==SDL_MOUSEBUTTONDOWN) && (event.motion.y<=485 && event.motion.y>=455 && event.motion.x>600 && event.motion.x<1200))||((event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_RETURN) && (flecheforriddle!=-3 || flecheforriddle!=1 || flecheforriddle!=0)))
        {
            afficherBack(b,screen);
            afficher_texte_temps(screen,txte,nowtime);
            SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
            SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
            sprintf(char_rose_counter, "  %d", rose_counter);
            afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
            afficherPerso(p,screen);
	    b.image_snake.pos_img_affiche.y=94;
            do
	    {
		    afficherBack(b,screen);
		    afficher_texte_temps(screen,txte,nowtime);
		    SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
		    SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
		    sprintf(char_rose_counter, "  %d", rose_counter);
		    afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
		    afficherPerso(p,screen);
	            b.image_snake.pos_img_affiche.x+=135;
		    SDL_Delay(200);
		    SDL_Flip(screen);
	
	    }while (b.image_snake.pos_img_affiche.x < 750);
	   p.nb_vies--; 		initialiser_audiobref_damage(music_damage,damage_variable);
		damage_variable++; if(damage_variable>=10) damage_variable=1;
	   b.image_snake.pos_img_affiche.y=0; snake=0; dial4=0;
    SDL_Delay(400);
    float thirdleveltransition=40;
    p.image_perso.pos_img_ecran.x=1350;
    while(p.image_perso.pos_img_ecran.x>650)
    {
        (b.background_ocean).pos_img_affiche.x+=thirdleveltransition;
	b.mini.pos_img_affiche.x+=thirdleveltransition/3.9;
	b.mask.pos_img_affiche.x+=thirdleveltransition; 
        b.camera.x+=thirdleveltransition;
        p.image_perso.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical1.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical2.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical3.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical4.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical5.pos_img_ecran.x-=thirdleveltransition;
	b.e.vertical6.pos_img_ecran.x-=thirdleveltransition;
	b.e.horizontal1.pos_img_ecran.x-=thirdleveltransition;
	b.e.horizontal2.pos_img_ecran.x-=thirdleveltransition;
	b.e.horizontal3.pos_img_ecran.x-=thirdleveltransition;
	
	b.rose1.pos_img_ecran.x-=thirdleveltransition;
	b.rose2.pos_img_ecran.x-=thirdleveltransition;
	b.rose3.pos_img_ecran.x-=thirdleveltransition;
	b.heart1.pos_img_ecran.x-=thirdleveltransition;
	b.heart2.pos_img_ecran.x-=thirdleveltransition;

	b.image_snake.pos_img_ecran.x-=thirdleveltransition; 
	b.image_napta.pos_img_ecran.x-=thirdleveltransition;

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
    limit=15378; b.m=2;
    p.image_perso.pos_img_ecran.y=650;
    p.image_perso.pos_img_ecran.x-=40;
        }
    }
    break;
case 11:
    dial4=0;
    break;
}
                    afficherBack(b,screen);
                    afficher_texte_temps(screen,txte,nowtime);
                    SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                    SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                    sprintf(char_rose_counter, "  %d", rose_counter);
                    afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                    afficherPerso(p,screen);
                    if (dial4!=0) dial4=1;
            }
            dial4=-1; image_you_box.pos_img_ecran.y=232;
        }
    }
    else      if (pos>12420 && pos<12520)
    {
	int flecheforriddle=0;
        if (dial5==-1)
        {
            dial5=1;
            SDL_BlitSurface(image_napta_box.img,NULL,screen,&image_napta_box.pos_img_ecran);
            dial_text = "Ho..Ho..";
            typewriter(dial_text,screen,280,event);
            while (dial5==1)
            {
                SDL_PollEvent(&event);
                if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e) dial5=-1;
            }
        }
        else
        {
            while (dial5!=0)
            {
                if (az>2) 
		{  
		SDL_WaitEvent(&event);
		if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e)
                {
                    az++;
                    dial5=az;
                }
		}
		else az++;
                switch(dial5)
                {
                case 1:
                    break;
                case 2:
                    SDL_BlitSurface(image_napta_box.img,NULL,screen,&image_napta_box.pos_img_ecran);
                    dial_text = "Hello there, little traveler. You seem lost.";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 3:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "I'm not lost, I'm on a quest.";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 4:
                    SDL_BlitSurface(image_napta_box.img,NULL,screen,&image_napta_box.pos_img_ecran);
                    dial_text = "Oh, a quest, you say? Interesting. ";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "I can help you, if you like.";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 5:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "How can you help me? ";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 6:
                    SDL_BlitSurface(image_napta_box.img,NULL,screen,&image_napta_box.pos_img_ecran);
                    dial_text = "Riddle or flower? Choose to pass.";
                    typewriter(dial_text,screen,280,event);
                    break;
		 case 7:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "    Solve the Riddle         Give the Flower";
                    typewriter(dial_text,screen,360,event);
	SDL_EventState(SDL_MOUSEMOTION,SDL_ENABLE);	    
while (1)
{
    SDL_PollEvent(&event);
    if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_RIGHT)
    {
        flecheforriddle++;
        SDL_Delay(100);
    }
    else if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LEFT)
    {
        flecheforriddle--;
        SDL_Delay(100);
    }
    flecheforriddle=flecheforriddle%3;
    if  ((event.motion.y<=380 && event.motion.y>=340 && event.motion.x<=650 && event.motion.x>=290 )|| flecheforriddle==1 || flecheforriddle==-2)
    {
        afficherBack(b,screen);
        afficher_texte_temps(screen,txte,nowtime);
        SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
        SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
        sprintf(char_rose_counter, "  %d", rose_counter);
        afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
        afficherPerso(p,screen);
        SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
        texet=TTF_RenderText_Solid(arcade_font, "   >Solve the Riddle<        Give the Flower", white_color);
        SDL_Rect recet= {240,340,0,0};
        SDL_BlitSurface(texet, NULL, screen, &recet);

    }
    else if  ((event.motion.y<=380 && event.motion.y>=340 && event.motion.x<=1140 && event.motion.x>=800) ||flecheforriddle==2 || flecheforriddle==-1)
    {
        afficherBack(b,screen);
        afficher_texte_temps(screen,txte,nowtime);
        SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
        SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
        sprintf(char_rose_counter, "  %d", rose_counter);
        afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
        afficherPerso(p,screen);
        SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
        texet=TTF_RenderText_Solid(arcade_font, "    Solve the Riddle        >Give the Flower<", white_color);
        SDL_Rect recet= {240,340,0,0};
        SDL_BlitSurface(texet, NULL, screen, &recet);
}
        else
        {
            afficherBack(b,screen);
            afficher_texte_temps(screen,txte,nowtime);
            SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
            SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
            sprintf(char_rose_counter, "  %d", rose_counter);
            afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
            afficherPerso(p,screen);
            SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);

            texet=TTF_RenderText_Solid(arcade_font, "    Solve the Riddle         Give the Flower", white_color);
            SDL_Rect recet= {240,340,0,0};
            SDL_BlitSurface(texet, NULL, screen, &recet);
            
}SDL_Flip(screen);	
            if (((event.type==SDL_MOUSEBUTTONDOWN) && (event.motion.y<=380 && event.motion.y>=340 && event.motion.x<=650 && event.motion.x>=290))||((event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_RETURN) && ( flecheforriddle==1 || flecheforriddle==-2)))
            {
                afficherBack(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                afficherPerso(p,screen);
                SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                dial_text ="Alright, I'll try to solve your riddle.";
		typewriter(dial_text,screen,280,event);
                 nade=7; 
initialiserTic(&t);
fade_in3(xotxtwithback.img,xoback,screen,xotxtwithback.pos_img_ecran);
SDL_Delay(800);
while(xotxt.pos_img_ecran.y>80)
{
	xotxt.pos_img_ecran.y-=nade;
	SDL_BlitSurface(xoback.img,NULL,screen,&xoback.pos_img_ecran);
	SDL_BlitSurface(xotxt.img,NULL,screen,&xotxt.pos_img_ecran);
	SDL_Flip(screen);
	if (xotxt.pos_img_ecran.y<150 && nade>2) nade-=0.25;
}
nowtime=SDL_GetTicks(); nowtime-=last;
puzzle3timestart=nowtime;
while(boucle_tic)
    {
nowtime=SDL_GetTicks(); nowtime-=last;
puzzle3time=nowtime-puzzle3timestart;	
        afficherTic(t,screen);SDL_BlitSurface(xotxt.img,NULL,screen,&xotxt.pos_img_ecran);
        if(t.tour<9 && atilganer(t.tabsuivi)==0)
        {

            if ((t.tour+t.joueur)%2==0)
            {
                calcul_coup(t.tabsuivi);
                t.tour++; afficherTic(t,screen); SDL_BlitSurface(xotxt.img,NULL,screen,&xotxt.pos_img_ecran);SDL_Flip(screen);
            }
            else
            {
                SDL_WaitEvent(&event);
                if( event.type==SDL_MOUSEBUTTONUP)
                {
                    x_tic=(event.button.x- t.pos_pre_case.x) /largecase;
                    y_tic=(event.button.y- t.pos_pre_case.y)/hautcase;
                    coup=3*y_tic+x_tic;
                    t.tabsuivi[coup]=-1;
                    t.tour++; afficherTic(t,screen);SDL_BlitSurface(xotxt.img,NULL,screen,&xotxt.pos_img_ecran); SDL_Flip(screen); SDL_Delay(300);
                }
                else if( event.type==SDL_QUIT)
                    boucle_tic=0;
            }}
            else
            {
		
                boucle_tic = 0;
            }
            SDL_Flip(screen);
        }
                afficherBack(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                afficherPerso(p,screen);
 		SDL_BlitSurface(image_napta_box.img,NULL,screen,&image_napta_box.pos_img_ecran);
                dial_text = "You may pass, little traveler.";
                typewriter(dial_text,screen,280,event);
		b.background_ocean.img=IMG_Load("images/backgrounds/ocean_windowed2.png");
		b.mask.img=IMG_Load("images/mask_with_door_open.png");
		az=15;dial5=15;
		break;
            }
            else if (((event.type==SDL_MOUSEBUTTONDOWN) && (event.motion.y<=380 && event.motion.y>=340 && event.motion.x<=1140 && event.motion.x>=800))||((event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_RETURN) && (flecheforriddle==2 || flecheforriddle==-1)))
            {      
 		afficherBack(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                afficherPerso(p,screen);
 		SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran); 
                dial_text = "What's the catch?";
                typewriter(dial_text,screen,280,event);
                dial5=11; az=11; break;
            }

        
    }
break;
		case 11:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "What's the catch?";
                    typewriter(dial_text,screen,280,event);
                    break;
                case 12:
                    SDL_BlitSurface(image_napta_box.img,NULL,screen,&image_napta_box.pos_img_ecran);
                    dial_text = "No catch at all.";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "Just one flower, and you'll be on your way.";
                    typewriter(dial_text,screen,340,event);
                    break;
                case 13:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    dial_text = "Alright, here's a flower.";
                    typewriter(dial_text,screen,280,event);
		    rose_counter--;
                    break; 
		 case 14:
                    SDL_BlitSurface(image_napta_box.img,NULL,screen,&image_napta_box.pos_img_ecran);
                    dial_text = "Mhm Delicious. Thank you for the snack.";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "Oh,you still need to solve the riddle,";
                    typewriter(dial_text,screen,340,event);
                    dial_text = "if you want to pass";
                    typewriter(dial_text,screen,400,event);
		    break;
case 15: 
nade=7; 
initialiserTic(&t);
fade_in3(xotxtwithback.img,xoback,screen,xotxtwithback.pos_img_ecran);
SDL_Delay(800);
while(xotxt.pos_img_ecran.y>80)
{
	xotxt.pos_img_ecran.y-=nade;
	SDL_BlitSurface(xoback.img,NULL,screen,&xoback.pos_img_ecran);
	SDL_BlitSurface(xotxt.img,NULL,screen,&xotxt.pos_img_ecran);
	SDL_Flip(screen);
	if (xotxt.pos_img_ecran.y<150 && nade>2) nade-=0.25;
}
nowtime=SDL_GetTicks(); nowtime-=last;
puzzle3timestart=nowtime;
while(boucle_tic)
    {
nowtime=SDL_GetTicks(); nowtime-=last;
puzzle3time=nowtime-puzzle3timestart;
	
        afficherTic(t,screen);SDL_BlitSurface(xotxt.img,NULL,screen,&xotxt.pos_img_ecran);
        if(t.tour<9 && atilganer(t.tabsuivi)==0)
        {
            if ((t.tour+t.joueur)%2==0)
            {
                calcul_coup(t.tabsuivi);
                t.tour++; afficherTic(t,screen); SDL_BlitSurface(xotxt.img,NULL,screen,&xotxt.pos_img_ecran);SDL_Flip(screen);
            }
            else
            {
                SDL_WaitEvent(&event);
                if( event.type==SDL_MOUSEBUTTONUP)
                {
                    x_tic=(event.button.x- t.pos_pre_case.x) /largecase;
                    y_tic=(event.button.y- t.pos_pre_case.y)/hautcase;
                    coup=3*y_tic+x_tic;
                    t.tabsuivi[coup]=-1;
                    t.tour++; afficherTic(t,screen);SDL_BlitSurface(xotxt.img,NULL,screen,&xotxt.pos_img_ecran); SDL_Flip(screen); SDL_Delay(300);
                }
                else if( event.type==SDL_QUIT)
                    boucle_tic=0;
            }}
            else
            {
		
                boucle_tic = 0;
            }
            SDL_Flip(screen);
        }
		 afficherBack(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                afficherPerso(p,screen);
		SDL_BlitSurface(image_napta_box.img,NULL,screen,&image_napta_box.pos_img_ecran);
                    dial_text = "You may pass, little traveler,";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "here's your flower, it tasted awful anyways.";
                    typewriter(dial_text,screen,340,event);
                    dial_text = "But next time, be careful who you trust.";
                    typewriter(dial_text,screen,400,event);
		rose_counter++;
		b.background_ocean.img=IMG_Load("images/backgrounds/ocean_windowed2.png");
		b.mask.img=IMG_Load("images/mask_with_door_open.png");
		break;
                case 16:
                    dial5=0;
                    break;
                }
                afficherBack(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                afficherPerso(p,screen);
                if (dial5!=0) dial5=1;

            }
        }
        dial5=-1;
    }
else if (pos>11700 && pos<12360)
{SDL_EventState(SDL_MOUSEMOTION,SDL_ENABLE);
    int di6al=0;
    if (dial6==-1)
    {
        dial6=1;
        SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
        dial_text = "Beware Terravale's depths, my friend.";
        typewriter(dial_text,screen,280,event);
        while (dial6==1)
        {
            SDL_WaitEvent(&event);
            if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e) dial6=-1;
        }
    }
    else
    {
        while (dial6!=0)
        {
            if (az>2)
            {
                SDL_WaitEvent(&event);
                if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_e)
                {
                    az++;
                    dial6=az;
                }
            }
            else az++;
            switch(dial6)
            {
            case 1:
                break;
            case 2:
                SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                dial_text = "Good morrow, friend, on this journey we share,";
                typewriter(dial_text,screen,280,event);
                dial_text ="Tell me, hast thou aided the soul in despair(Shelly)";
                typewriter(dial_text,screen,340,event);
                break;
            case 4:
		SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                dial_text = "            >Yes(lie)<        No";
 		typewriter(dial_text,screen,340,event);
                flecheforriddle=0;
                while (paro_bard)
                {
                    SDL_PollEvent(&event);
                    if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_RIGHT)
                    {
                        flecheforriddle++;
                        SDL_Delay(100);
                    }
                    else if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LEFT)
                    {
                        flecheforriddle--;
                        SDL_Delay(100);
                    }
                    flecheforriddle=flecheforriddle%3;
                    if  ((event.motion.y<=380 && event.motion.y>=340 && event.motion.x<=650 && event.motion.x>=290 )|| flecheforriddle==1 || flecheforriddle==-2)
                    {
                        afficherBack(b,screen);
                        afficher_texte_temps(screen,txte,nowtime);
                        SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                        SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                        sprintf(char_rose_counter, "  %d", rose_counter);
                        afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                        afficherPerso(p,screen);
                        SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                        texet=TTF_RenderText_Solid(arcade_font, "            >Yes(lie)<        No", white_color);
                        SDL_Rect recet= {240,340,0,0};
                        SDL_BlitSurface(texet, NULL, screen, &recet);

                    }
                    else if  ((event.motion.y<=380 && event.motion.y>=340 && event.motion.x<=1140 && event.motion.x>=800) ||flecheforriddle==2 || flecheforriddle==-1)
                    {
                        afficherBack(b,screen);
                        afficher_texte_temps(screen,txte,nowtime);
                        SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                        SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                        sprintf(char_rose_counter, "  %d", rose_counter);
                        afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                        afficherPerso(p,screen);
                        SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                        texet=TTF_RenderText_Solid(arcade_font, "             Yes(lie)        >No<", white_color);
                        SDL_Rect recet= {240,340,0,0};
                        SDL_BlitSurface(texet, NULL, screen, &recet);
                    }
                    else
                    {
                        afficherBack(b,screen);
                        afficher_texte_temps(screen,txte,nowtime);
                        SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                        SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                        sprintf(char_rose_counter, "  %d", rose_counter);
                        afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                        afficherPerso(p,screen);
                        SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);

                        texet=TTF_RenderText_Solid(arcade_font, "             Yes(lie)         No", white_color);
                        SDL_Rect recet= {240,340,0,0};
                        SDL_BlitSurface(texet, NULL, screen, &recet);

                    }
                    if (((event.type==SDL_MOUSEBUTTONDOWN) &&(event.motion.y<=380 && event.motion.y>=340 && event.motion.x<=650 && event.motion.x>=290 )) ||((event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_RETURN) && ( flecheforriddle==1 || flecheforriddle==-2)))
                    {
                        az++; dial6++; di6al=1;
                        paro_bard=0;
  afficherBack(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                afficherPerso(p,screen);
		SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    if (di6al==1) dial_text = "Yes, Bard, I saved her! She's safe now.";
                    else dial_text="I'm sorry, Bard, but I couldn't save her.";
                    typewriter(dial_text,screen,280,event);
                    if (di6al==2)
                    {
                        dial_text="Her fate was sealed before I arrived.";
                        typewriter(dial_text,screen,340,event);
                    }

                    }
                    else if (((event.type==SDL_MOUSEBUTTONDOWN) && (event.motion.y<=380 && event.motion.y>=340 && event.motion.x<=1140 && event.motion.x>=800))||((event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_RETURN) && (flecheforriddle==2 || flecheforriddle==-1)))
                    {
                        az++; dial6++; di6al=2;
  afficherBack(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                afficherPerso(p,screen);
SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    if (di6al==1) dial_text = "Yes, Bard, I saved her! She's safe now.";
                    else dial_text="I'm sorry, Bard, but I couldn't save her.";
                    typewriter(dial_text,screen,280,event);
                    if (di6al==2)
                    {
                        dial_text="Her fate was sealed before I arrived.";
                        typewriter(dial_text,screen,340,event);
                    }
                    break;
                        paro_bard=0;
                    }
                    SDL_Flip(screen);
}
                    break;
                case 5:
                    SDL_BlitSurface(image_you_box.img,NULL,screen,&image_you_box.pos_img_ecran);
                    if (di6al==1) dial_text = "Yes, Bard, I saved her! She's safe now.";
                    else dial_text="I'm sorry, Bard, but I couldn't save her.";
                    typewriter(dial_text,screen,280,event);
                    if (di6al==2)
                    {
                        dial_text="Her fate was sealed before I arrived.";
                        typewriter(dial_text,screen,340,event);
                    }
                    break;
                case 6:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    if (di6al==1)
                    dial_text = "Well done, thou noble hero, valiant and bright,";
                    else dial_text = " Ah, the fragility of life, a somber truth,";
                    typewriter(dial_text,screen,280,event);
                    if (di6al==1)
                    dial_text = "Yet, beware the depths of Terravale's ominous night.";
                    else dial_text="In face of destiny's decree, we find little ruth.";
                    typewriter(dial_text,screen,340,event);
                    break;
                       
                case 7:
                    SDL_BlitSurface(image_bard_box.img,NULL,screen,&image_bard_box.pos_img_ecran);
                    dial_text = "I caution thee, my kindred spirit, ";
                    typewriter(dial_text,screen,280,event);
                    dial_text = "venture not deeper into Terravale's embrace,";
                    typewriter(dial_text,screen,340,event);
                    dial_text = "for peril awaits, a treacherous plight. ";
                    typewriter(dial_text,screen,400,event);
                    break;
                case 8:
                    dial6=0;
                    break;
                }
                afficherBack(b,screen);
                afficher_texte_temps(screen,txte,nowtime);
                SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
                SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
                sprintf(char_rose_counter, "  %d", rose_counter);
                afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
                afficherPerso(p,screen);
                if (dial6!=0) dial6=1;

            }
        }
        dial6=-1;
	if (di6al==1)
	{ 
	while(show<100)
	{
	show++;
	p.score--;
	afficherBack(b,screen);
	afficher_texte_temps(screen,txte,nowtime);
	SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
	SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
	sprintf(char_rose_counter, "  %d", rose_counter);
	afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
	afficherPerso(p,screen);
	SDL_Flip(screen);
	SDL_Delay(1);
	}
	show=0;
	}
	else if(di6al==2)
	{
	while(show<50*bonusint)
	{
	show++;
	p.score++;
	afficherBack(b,screen);
	afficher_texte_temps(screen,txte,nowtime);
	SDL_BlitSurface(image_clock.img,NULL,screen,&image_clock.pos_img_ecran); // afficher clock
	SDL_BlitSurface(image_rose_counter.img,NULL,screen,&image_rose_counter.pos_img_ecran);
	sprintf(char_rose_counter, "  %d", rose_counter);
	afficher_texte_custom(screen, txt_rose_counter,char_rose_counter);
	afficherPerso(p,screen);
	SDL_Flip(screen);
	SDL_Delay(1);
	}
	show=0;
	} 

    }
if (dial5==-1)
{
if(dial1==-1 && dial2==-1 && dial3==-1 && dial4==-1 && dial6==-1)
	{
		colorquest3.r=56;
		colorquest3.g=168;
		colorquest3.b=74;
		txtquest3 = TTF_RenderText_Solid(questfont, "-talk to all npcs", colorquest3);
		npcshow=1;
		initialiser_audio_score(music_score);
	}
else 
	{
		colorquest3.r=228;
		colorquest3.g=63;
		colorquest3.b=63;
		txtquest3 = TTF_RenderText_Solid(questfont, "-talk to all npcs", colorquest3);
		npcshownegative=1;
	}
}
SDL_EventState(SDL_MOUSEMOTION,SDL_DISABLE);
}

else if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_l)
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

else if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_LSHIFT && p.acceleration<1 && p.mana>1) {if(ability_counter>0) ability_counter--;
if(ability_counter==0)
{
colorquest2.r=56;
colorquest2.g=168;
colorquest2.b=74;
q2=1;
}
sprintf(quest10times, "%d times", ability_counter);
txt2quest2 = TTF_RenderText_Solid(questfont, quest10times, colorquest2);
txtquest2 = TTF_RenderText_Solid(questfont, "-use your ability", colorquest2);
p.mana--;p.acceleration=15;dust_effect=1;b.image_dust.pos_img_ecran.x=p.image_perso.pos_img_ecran.x;b.image_dust.pos_img_ecran.y=p.image_perso.pos_img_ecran.y+70-27;}//speed boost intensity a expliquer a la prof
else if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_j){p.image_perso.pos_img_ecran.x+=150;p.image_perso.pos_img_ecran.y-=150;}
    }
    if (reversed==0) p.direction=0;
    else if (reversed==1) p.direction=4;
   }
sauvegarde(p,b,rose_counter);
}

//**A REMOVER** SI POSSIBLE
  }//mtaa ici play
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
        liberer_tic(&t);
return 0;
}

