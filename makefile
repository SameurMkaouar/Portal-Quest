prog : image.o audio.o text.o hero.o background.o minimap.o ennemi.o main.o  serie.o  enigme.o
	gcc image.o audio.o text.o hero.o background.o minimap.o ennemi.o main.o  serie.o  enigme.o -lSDL_gfx -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lm -o prog -g
main.o : fichiers/main.c
	gcc -c fichiers/main.c -g
image.o : fichiers/image.c
	gcc -c fichiers/image.c -g
audio.o : fichiers/audio.c
	gcc -c fichiers/audio.c -g
text.o : fichiers/text.c
	gcc -c fichiers/text.c -g
hero.o : fichiers/hero.c
	gcc -c fichiers/hero.c -g
background.o: fichiers/background.c
	gcc -c fichiers/background.c -g 
minimap.o: fichiers/minimap.c
	gcc -c fichiers/minimap.c -g
ennemi.o: fichiers/ennemi.c 
	gcc -c fichiers/ennemi.c -g
serie.o: fichiers/serie.c 
	gcc -c fichiers/serie.c -g
enigme.o: enigme.c 
	gcc -c fichiers/enigme.c -g
