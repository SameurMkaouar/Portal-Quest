#include "sauvegarde.h"


void sauvegarde(personne p, background b, int rose_counter)
{
    FILE *outfile;
    outfile = fopen("perso.txt", "w");

    fprintf(outfile, "image_perso.x: %hd\n", p.image_perso.pos_img_ecran.x);
    fprintf(outfile, "image_perso.y: %hd\n", p.image_perso.pos_img_ecran.y);
    fprintf(outfile, "nb_vies: %d\n", p.nb_vies);
    fprintf(outfile, "score: %d\n", p.score);
    fprintf(outfile, "rose: %d\n", rose_counter); 


    fclose(outfile);

    outfile = fopen("bg.txt", "w");
    fprintf(outfile, "bg.x %hd\n",b.background_ocean.pos_img_affiche.x);
    fprintf(outfile, "b.rose1_is_collected : %d\n", b.rose1_is_collected );
    fprintf(outfile, "b.rose2_is_collected : %d\n", b.rose2_is_collected );
    fprintf(outfile, "b.rose3_is_collected : %d\n", b.rose3_is_collected );
    fprintf(outfile, "b.heart1_is_collected : %d\n", b.heart1_is_collected );
    fprintf(outfile, "b.heart2_is_collected : %d\n", b.heart2_is_collected );
    fclose(outfile);
}


void chargement(personne *p, background *b, int *rose_counter)
{
    FILE *infile;
    infile = fopen("perso.txt", "r");

    fscanf(infile, "image_perso.x: %hd\n", &p->image_perso.pos_img_ecran.x);
    fscanf(infile, "image_perso.y: %hd\n", &p->image_perso.pos_img_ecran.y);
	
    fscanf(infile, "nb_vies: %d\n", &(p->nb_vies));
    fscanf(infile, "score: %d\n", &(p->score));

    fscanf(infile,"rose: %d\n", rose_counter);

    fclose(infile);

    infile = fopen("bg.txt", "r");
    fscanf(infile, "bg.x %hd\n", &(b->background_ocean.pos_img_affiche.x));
fscanf(infile, "b.rose1_is_collected : %d\n", &(b->rose1_is_collected));
fscanf(infile, "b.rose2_is_collected : %d\n", &(b->rose2_is_collected));
fscanf(infile, "b.rose3_is_collected : %d\n", &(b->rose3_is_collected));
fscanf(infile, "b.heart1_is_collected : %d\n", &(b->heart1_is_collected));
fscanf(infile, "b.heart2_is_collected : %d\n", &(b->heart2_is_collected));

    fclose(infile);
}








