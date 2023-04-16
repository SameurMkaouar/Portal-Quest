#ifndef AUDIO_H
#define AUDIO_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

void initialiser_audio_animation(Mix_Music *music, int volume);
void initialiser_audio_mainmenu(Mix_Music *music, int volume);
void initialiser_audio_options(Mix_Music *music,int volume);
void initialiser_audio_play(Mix_Music *music,int volume);
void initialiser_audio_credits(Mix_Music *music,int volume);
void liberer_musique(Mix_Music *music);
void initialiser_audiobref(Mix_Chunk *music);
void initialiser_long_audiobref(Mix_Chunk *music, int chunkvolume);
void initialiser_blank(Mix_Chunk *music);
void liberer_musiquebref(Mix_Chunk *music);
void initialiser_audio_background(Mix_Music *music,int volume, char nomMusic[]);
#endif
