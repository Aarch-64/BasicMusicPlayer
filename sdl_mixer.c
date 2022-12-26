// Basic Music reproductor for Linux, using terminal arguments

#include "include/SDL.h"
#include "include/SDL_mixer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 3)
    { 
        /* if (argument cmd 1) == argv_help */
        if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) // || if (argument cmd 1) == argv_hel...
        { 
            puts("argument 1: music.mp3\t\t\tPlay music");
            puts("argument 2: 2\t\t\t\tNumber of reproduction music");
            puts("argument 1: --version\t\t\tProgram version");
            puts("argument 1: -v\t\t\t\tProgram version");
            exit(EXIT_SUCCESS);
        } 
        
        /* else if (argument cmd 1) == argv_version */
        else if (!strcmp(argv[1], "--version") || !strcmp(argv[1], "-v")) // || if (argument cmd 1) == argv_hel...
        { 
            puts("version 0.0.1");
            exit(EXIT_SUCCESS);
        }
        else
        {
            puts("version: invalid argument");
            exit(EXIT_FAILURE);
        }
    }
    if (argc > 3)
    {
        puts("argument invalid");
        exit(1);
    }
    else if (argc > 1)
    {
        // Inicializa SDL y la biblioteca SDL_mixer
        SDL_Init(SDL_INIT_AUDIO);
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 100);

        // Carga un archivo de música
          Mix_Music* music = Mix_LoadMUS(argv[1]);

        // Reproduce la música
        if (!strcmp(argv[2], "-1"))
            Mix_PlayMusic(music, -1);
        else if (!strcmp(argv[2], "1"))
            Mix_PlayMusic(music, 1);
        else if (!strcmp(argv[2], "2"))
            Mix_PlayMusic(music, 2);
        else if (!strcmp(argv[2], "3"))
            Mix_PlayMusic(music, 3);
        else if (!strcmp(argv[2], "4"))
            Mix_PlayMusic(music, 4);
        else if (!strcmp(argv[2], "5"))
            Mix_PlayMusic(music, 5);
        else
        {
            Mix_PlayMusic(music, -1);
            puts("main: argument invalid, Use default '-1'\n\n");
        }
         
        printf("Music: %s\n",argv[1]);
        printf("while reproduction: %s\n",argv[2]);
        // Espera a que el usuario pulse una tecla
        printf("\n\nPress any key for exit...");
        getchar();

        // Detiene la reproducción de la música
        Mix_HaltMusic();

        // Libera la memoria asociada a la música
        Mix_FreeMusic(music);

        // Cierra SDL y la biblioteca SDL_mixer
        Mix_CloseAudio();
        SDL_Quit();
    }
    return 0;
}

