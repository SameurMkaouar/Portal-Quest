
/**
* @file audio.c
* @brief audio file.
* @author Team Shelly Studios
* @version 3.2
* @date May 03, 2023
*
* Ici figure le fichier audio.c dans lequel il y'a tout ce qui est audio
*
*/
#include "audio.h"

//ici: traitement du son 
void initialiser_audio_animation(Mix_Music *music,int volume) //initialiser les fonctions audio et SDL_mixer
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",SDL_GetError());
    }
    music=Mix_LoadMUS("audio/animation_music.mp3"); //chargement de la musique
    Mix_PlayMusic(music,-1); //jouer la musique
    Mix_VolumeMusic(volume);
}
void initialiser_audio_mainmenu(Mix_Music *music,int volume) //initialiser les fonctions audio et SDL_mixer
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",SDL_GetError());
    }
    music=Mix_LoadMUS("audio/music01.mp3"); //chargement de la musique
    Mix_PlayMusic(music,-1); //jouer la musique
    Mix_VolumeMusic(volume);
}
void initialiser_audio_options(Mix_Music *music,int volume) //initialiser les fnctions audio et SDL_mixer
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",SDL_GetError());
    }
    music=Mix_LoadMUS("audio/music01.mp3");//chargement de la musique
    Mix_PlayMusic(music,-1);//jouer la musique
    Mix_VolumeMusic(volume);
}
void initialiser_audio_play(Mix_Music *music,int volume) //initialiser les fnctions audio et SDL_mixer
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",SDL_GetError());
    }
    music=Mix_LoadMUS("audio/music02.mp3"); //chargement de la musique
    Mix_PlayMusic(music,-1); //jouer la musique
    Mix_VolumeMusic(volume);
}
void initialiser_audio_credits(Mix_Music *music,int volume) //initialiser les fonctions audio et SDL_mixer
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",SDL_GetError());
    }
    music=Mix_LoadMUS("audio/music01.mp3"); //chargement de la musique
    Mix_PlayMusic(music,-1); //jouer la musique
    Mix_VolumeMusic(volume);
}
void initialiser_audiobref(Mix_Chunk *music)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,0);
    music = Mix_LoadWAV("audio/chuck.wav");
    Mix_PlayChannel(5,music,0);
    if (music==NULL) printf("%s",SDL_GetError());
}
void liberer_musique(Mix_Music *music)
{
    Mix_FreeMusic(music);
}
void liberer_musiquebref(Mix_Chunk *music)
{
    Mix_FreeChunk(music);
}
void initialiser_long_audiobref(Mix_Chunk *music, int chunkvolume)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,0);
    music = Mix_LoadWAV("audio/blank.wav");
    Mix_PlayChannel(4,music,0);
    if (music==NULL) printf("%s",SDL_GetError());
    Mix_VolumeChunk(music, chunkvolume);
}

void initialiser_blank(Mix_Chunk *music)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,0);
    music = Mix_LoadWAV("audio/blank.wav");
    Mix_PlayChannel(4,music,0);
    if (music==NULL) printf("%s",SDL_GetError());
}

void initialiser_audio_background(Mix_Music *music,int volume, char nomMusic[]) //initialiser les fnctions audio et SDL_mixer
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",SDL_GetError());
    }
    music=Mix_LoadMUS(nomMusic); //chargement de la musique
    Mix_PlayMusic(music,-1); //jouer la musique
    Mix_VolumeMusic(volume);
}


void initialiser_audiobref_damage(Mix_Chunk *music, int a)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,1024);
    switch(a)
    {
    case 1: music = Mix_LoadWAV("audio/meghan/damage1.wav"); break;
    case 2: music = Mix_LoadWAV("audio/meghan/damage2.wav");break;
    case 3: music = Mix_LoadWAV("audio/meghan/damage3.wav");break;
    case 4: music = Mix_LoadWAV("audio/meghan/damage4.wav");break;
    case 5: music = Mix_LoadWAV("audio/meghan/damage5.wav");break;
    case 6: music = Mix_LoadWAV("audio/meghan/damage6.wav");break;
    case 7: music = Mix_LoadWAV("audio/meghan/damage7.wav");break;
    case 8: music = Mix_LoadWAV("audio/meghan/damage8.wav");break;
    case 9: music = Mix_LoadWAV("audio/meghan/damage9.wav");break;
    case 10: music = Mix_LoadWAV("audio/meghan/damage10.wav"); break;
    }
    Mix_PlayChannel(5,music,0);
    if (music==NULL) printf("%s",SDL_GetError());
    Mix_VolumeChunk(music, 128);
}
void initialiser_audio_jump(Mix_Chunk *music)
{
int num = rand() % 8 + 1;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,0);
switch(num)
{
 case 1:  music = Mix_LoadWAV("audio/jump.wav");break;
 case 2:  music = Mix_LoadWAV("audio/jump2.wav");break;
 case 3:  music = Mix_LoadWAV("audio/jump3.wav");break;
 case 4:  music = Mix_LoadWAV("audio/jump4.wav");break;
 case 5:  music = Mix_LoadWAV("audio/jump5.wav");break;
 case 6:  music = Mix_LoadWAV("audio/jump6.wav");break;
 case 7:  music = Mix_LoadWAV("audio/jump7.wav");break;
 case 8:  music = Mix_LoadWAV("audio/jump8.wav");break;
}
    Mix_PlayChannel(4,music,0);
    if (music==NULL) printf("%s",SDL_GetError());
 if (num==1) Mix_VolumeChunk(music, 80);
else Mix_VolumeChunk(music, 128);
}
void initialiser_audio_score(Mix_Chunk *music)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,0);
    music = Mix_LoadWAV("audio/score.wav");
    Mix_PlayChannel(4,music,0);
    if (music==NULL) printf("%s",SDL_GetError());
    Mix_VolumeChunk(music, 128);
}
void initialiser_audio_collect(Mix_Chunk *music)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,0);
    music = Mix_LoadWAV("audio/collect.wav");
    Mix_PlayChannel(4,music,0);
    if (music==NULL) printf("%s",SDL_GetError());
    Mix_VolumeChunk(music, 128);
}
