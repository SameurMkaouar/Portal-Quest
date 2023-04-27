prog : image.o audio.o text.o hero.o background.o minimap.o ennemi.o main.o  serie.o
	gcc image.o audio.o text.o hero.o background.o minimap.o ennemi.o main.o  serie.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lm -o prog -g
main.o : main.c
	gcc -c main.c -g
image.o : image.c
	gcc -c image.c -g
audio.o : audio.c
	gcc -c audio.c -g
text.o : text.c
	gcc -c text.c -g
hero.o : hero.c
	gcc -c hero.c -g
background.o: background.c
	gcc -c background.c -g 
minimap.o: minimap.c
	gcc -c minimap.c -g
ennemi.o: ennemi.c 
	gcc -c ennemi.c -g
serie.o: serie.c 
	gcc -c serie.c -g
