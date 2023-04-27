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
    music=Mix_LoadMUS("audio/menu_music.mp3"); //chargement de la musique
    Mix_PlayMusic(music,-1); //jouer la musique
    Mix_VolumeMusic(volume);
}
void initialiser_audio_options(Mix_Music *music,int volume) //initialiser les fnctions audio et SDL_mixer
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",SDL_GetError());
    }
    music=Mix_LoadMUS("audio/options_music.mp3");//chargement de la musique
    Mix_PlayMusic(music,-1);//jouer la musique
    Mix_VolumeMusic(volume);
}
void initialiser_audio_play(Mix_Music *music,int volume) //initialiser les fnctions audio et SDL_mixer
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",SDL_GetError());
    }
    music=Mix_LoadMUS("audio/play_music.mp3"); //chargement de la musique
    Mix_PlayMusic(music,-1); //jouer la musique
    Mix_VolumeMusic(volume);
}
void initialiser_audio_credits(Mix_Music *music,int volume) //initialiser les fonctions audio et SDL_mixer
{
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",SDL_GetError());
    }
    music=Mix_LoadMUS("audio/creditsmusic.mp3"); //chargement de la musique
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
    music = Mix_LoadWAV("audio/longchuck.wav");
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


