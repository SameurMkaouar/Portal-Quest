prog: image.o audio.o text.o fct.o hero.o background.o minimap.o ennemi.o enigme.o sauvegarde.o main.o
	gcc image.o audio.o text.o fct.o hero.o background.o minimap.o ennemi.o enigme.o sauvegarde.o main.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lm -o prog -g -pg

main.o: fichiers/main.c
	gcc -c fichiers/main.c -g -pg

image.o: fichiers/image.c
	gcc -c fichiers/image.c -g -pg

audio.o: fichiers/audio.c
	gcc -c fichiers/audio.c -g -pg

text.o: fichiers/text.c
	gcc -c fichiers/text.c -g -pg

hero.o: fichiers/hero.c
	gcc -c fichiers/hero.c -g -pg

background.o: fichiers/background.c
	gcc -c fichiers/background.c -g -pg

minimap.o: fichiers/minimap.c
	gcc -c fichiers/minimap.c -g -pg

ennemi.o: fichiers/ennemi.c 
	gcc -c fichiers/ennemi.c -g -pg
enigme.o: fichiers/enigme.c 
	gcc -c fichiers/enigme.c -g -pg
fct.o: fichiers/fct.c 
	gcc -c fichiers/fct.c -g -pg
sauvegarde.o: fichiers/sauvegarde.c 
	gcc -c fichiers/sauvegarde.c -g -pg
