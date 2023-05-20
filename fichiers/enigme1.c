
#include "enigme1.h"

void genererEnigme(enigmee *ee,char *nomfichier)
{
   srand(time(NULL));
   FILE *fquestions=NULL;
   FILE *freponses=NULL;
   FILE *freponsesjustes=NULL;
   
  ee->pos_selected=0;
 ee->background=IMG_Load("back.png");
 ee->button= IMG_Load("button.png");
	ee->button1= IMG_Load("button1.png");
   TTF_Init();
   SDL_Color couleur;//noir
   couleur.r=0;
   couleur.g=0;
   couleur.b=0;
  ee->police=TTF_OpenFont("Lostar.ttf",50);
  ee->police1=TTF_OpenFont("Lostar.ttf",100);

 char question[500];//bch nhot feha les questions
  ee->num_questions=rand()%4;
  while(ee->num_questions==0)
  {
      ee->num_questions=rand()%4;//0ll -1

   }
   fquestions=fopen(nomfichier,"r");
   if(fquestions!=NULL)
  {
  int test=0;
 //nodkhol beha bch ncompari blibch yaatihouli alea//(stock fvar,taille,mlfich)
   while(fscanf(fquestions,"%s",question)&&(test!=ee->num_questions))//supp dkhalet b1 alea mahouch diff al 1 yokhrej snn yincrimenti yaffichi kima liaati flalea
    {
       test++;

    }
  fclose(fquestions);


   }
  char reponses[20];
  int min,max;
  switch(ee->num_questions)//hasb num souel
  {
    case 1:
    {

      min=0;//gmarat chneya mnhezch
      max=2;
     break;
   }
   case 2:
  {
     min=3;
      max=5;
     break;


  }
  case 3:
  {
  min=6;
   max=8;
     break;

   }
  }
   freponses=fopen("reponses.txt","r");
  if(freponses!=NULL)
  {
       int test=0;
       while(fgets((reponses),15,freponses)&&(test<max))
         {
           if(test>=min)
           {
            ee->reponses[test-min]=TTF_RenderText_Blended(ee->police1,reponses,couleur);//bch nahsser bih les reps liena manhewhomch lhouma ghaltin
           }
             test++;
         }
 fclose(freponses); 



  }
    freponsesjustes=fopen("reponsesjustes.txt","r+");
 if(freponsesjustes!=NULL)
    {
        int test=1;
         while(fgets((reponses),15,freponsesjustes))
          {
               if(test==ee->num_questions)
              {
                  printf("%s\n",reponses);
                  ee->reponses[2]=TTF_RenderText_Blended(ee->police1,reponses,couleur);//case 3 heya bch nhot feha khtr khrjt mfonc lkbalha bdeux reponses ghaltion
            
              }
                  test++;


          }fclose(freponses);


    }
    ee->positionreponsesjustes=rand() %4;//aleatoire
  while(ee->positionreponsesjustes==0)//nhb dima nbdllha blastha rep vrai
     {
         ee->positionreponsesjustes=rand() %4;

    }printf("%d \n",ee->positionreponsesjustes);
      ee->questions=TTF_RenderText_Blended(ee->police,question,couleur);
    ee->pos_questions.x=100;
     ee->pos_questions.y=100;

     ee->pos_reponses1.x=10;
       ee->pos_reponses1.y=300;

     ee->pos_reponses2.x=1100;
     ee->pos_reponses2.y=300;
  
     ee->pos_reponses3.x=500;
     ee->pos_reponses3.y=500; 

     ee->pos_reponses1txt.x=ee->pos_reponses1.x+150;
     ee->pos_reponses1txt.y=ee->pos_reponses1.y+70;


     ee->pos_reponses2txt.x= ee->pos_reponses2.x+150;
      ee->pos_reponses2txt.y= ee->pos_reponses2.y+70;
   
    ee->pos_reponses3txt.x=ee->pos_reponses3.x+150;
     ee->pos_reponses3txt.y=ee->pos_reponses3.y+70;
   





}
void aafficherEnigme(enigmee ee,SDL_Surface *ecran)
{	SDL_Rect pos_img_ecran,pos_img_affiche; 
pos_img_ecran.x=0;
pos_img_ecran.y=0;
pos_img_affiche.h=800;
pos_img_affiche.w=1800;
  SDL_BlitSurface(ee.background, &pos_img_affiche, ecran, &pos_img_ecran);
  SDL_BlitSurface(ee.questions, NULL, ecran, &ee.pos_questions);
switch(ee.positionreponsesjustes){
		case 1:{

			switch(ee.pos_selected){
			case 1:
			{
				SDL_BlitSurface(ee.button1, NULL, ecran, &ee.pos_reponses1);
				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses2);
				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses3);


				SDL_BlitSurface(ee.reponses[2], NULL, ecran, &ee.pos_reponses1txt);

				SDL_BlitSurface(ee.reponses[0], NULL, ecran, &ee.pos_reponses2txt);

				SDL_BlitSurface(ee.reponses[1], NULL, ecran, &ee.pos_reponses3txt);


			}
			break;
			case 2:
			{
				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses1);

				SDL_BlitSurface(ee.button1, NULL, ecran, &ee.pos_reponses2);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses3);


				SDL_BlitSurface(ee.reponses[2], NULL, ecran, &ee.pos_reponses1txt);

				SDL_BlitSurface(ee.reponses[0], NULL, ecran, &ee.pos_reponses2txt);

				SDL_BlitSurface(ee.reponses[1], NULL, ecran, &ee.pos_reponses3txt);

			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses1);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses2);

				SDL_BlitSurface(ee.button1, NULL, ecran, &ee.pos_reponses3);


				SDL_BlitSurface(ee.reponses[2], NULL, ecran, &ee.pos_reponses1txt);

				SDL_BlitSurface(ee.reponses[0], NULL, ecran, &ee.pos_reponses2txt);

				SDL_BlitSurface(ee.reponses[1], NULL, ecran, &ee.pos_reponses3txt);

	
			}
			break;
			default:
			{
				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses1);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses2);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses3);


				SDL_BlitSurface(ee.reponses[2], NULL, ecran, &ee.pos_reponses1txt);

				SDL_BlitSurface(ee.reponses[0], NULL, ecran, &ee.pos_reponses2txt);

				SDL_BlitSurface(ee.reponses[1], NULL, ecran, &ee.pos_reponses3txt);

				}
			}	
			break;
		}
		case 2:{
			switch(ee.pos_selected){
			case 1:
			{
				SDL_BlitSurface(ee.button1, NULL, ecran, &ee.pos_reponses1);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses2);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses3);


				SDL_BlitSurface(ee.reponses[0], NULL, ecran, &ee.pos_reponses1txt);

				SDL_BlitSurface(ee.reponses[2], NULL, ecran, &ee.pos_reponses2txt);

				SDL_BlitSurface(ee.reponses[1], NULL, ecran, &ee.pos_reponses3txt);


			}
			break;
			case 2:
			{
				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses1);

				SDL_BlitSurface(ee.button1, NULL, ecran, &ee.pos_reponses2);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses3);


				SDL_BlitSurface(ee.reponses[0], NULL, ecran, &ee.pos_reponses1txt);

				SDL_BlitSurface(ee.reponses[2], NULL, ecran, &ee.pos_reponses2txt);

				SDL_BlitSurface(ee.reponses[1], NULL, ecran, &ee.pos_reponses3txt);

			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses1);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses2);

				SDL_BlitSurface(ee.button1, NULL, ecran, &ee.pos_reponses3);


				SDL_BlitSurface(ee.reponses[0], NULL, ecran, &ee.pos_reponses1txt);

				SDL_BlitSurface(ee.reponses[2], NULL, ecran, &ee.pos_reponses2txt);

				SDL_BlitSurface(ee.reponses[1], NULL, ecran, &ee.pos_reponses3txt);

	
			}
			break;
			default:
			{
				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses1);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses2);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses3);


				SDL_BlitSurface(ee.reponses[0], NULL, ecran, &ee.pos_reponses1txt);

				SDL_BlitSurface(ee.reponses[2], NULL, ecran, &ee.pos_reponses2txt);

				SDL_BlitSurface(ee.reponses[1], NULL, ecran, &ee.pos_reponses3txt);

				}
			}
			break;
		}
		case 3:{
			switch(ee.pos_selected){
			case 1:
			{
				SDL_BlitSurface(ee.button1, NULL, ecran, &ee.pos_reponses1);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses2);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses3);


				SDL_BlitSurface(ee.reponses[0], NULL, ecran, &ee.pos_reponses1txt);

				SDL_BlitSurface(ee.reponses[1], NULL, ecran, &ee.pos_reponses2txt);

				SDL_BlitSurface(ee.reponses[2], NULL, ecran, &ee.pos_reponses3txt);


			}
			break;
			case 2:                       
			{
				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses1);

				SDL_BlitSurface(ee.button1, NULL, ecran, &ee.pos_reponses2);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses3);


				SDL_BlitSurface(ee.reponses[0], NULL, ecran, &ee.pos_reponses1txt);

				SDL_BlitSurface(ee.reponses[1], NULL, ecran, &ee.pos_reponses2txt);

				SDL_BlitSurface(ee.reponses[2], NULL, ecran, &ee.pos_reponses3txt);

			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses1);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses2);

				SDL_BlitSurface(ee.button1, NULL, ecran, &ee.pos_reponses3);


				SDL_BlitSurface(ee.reponses[0], NULL, ecran, &ee.pos_reponses1txt);

				SDL_BlitSurface(ee.reponses[1], NULL, ecran, &ee.pos_reponses2txt);

				SDL_BlitSurface(ee.reponses[2], NULL, ecran, &ee.pos_reponses3txt);

	
			}
			break;
			default:
			{
				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses1);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses2);

				SDL_BlitSurface(ee.button, NULL, ecran, &ee.pos_reponses3);


				SDL_BlitSurface(ee.reponses[0], NULL, ecran, &ee.pos_reponses1txt);

				SDL_BlitSurface(ee.reponses[1], NULL, ecran, &ee.pos_reponses2txt);

				SDL_BlitSurface(ee.reponses[2], NULL, ecran, &ee.pos_reponses3txt);

				}
			}

			break;
		}
	}
		SDL_Flip(ecran);
	SDL_Delay(100);

}
































