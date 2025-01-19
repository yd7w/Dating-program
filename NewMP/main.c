#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <SDL2/SDL_mixer.h>
#include <stdlib.h>
#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_mixer.h>

void playSound(const char* filePath) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer Error: %s\n", Mix_GetError());
        SDL_Quit();
        return;
    }

    // Load the sound
    Mix_Chunk* sound = Mix_LoadWAV(filePath);
    if (!sound) {
        printf("Mix_LoadWAV Error: %s\n", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }

    // Play the sound on the first available channel
    int channel = Mix_PlayChannel(-1, sound, 0);
    if (channel == -1) {
        printf("Mix_PlayChannel Error: %s\n", Mix_GetError());
        Mix_FreeChunk(sound);
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }

    // Wait until the sound has finished playing
    while (Mix_Playing(channel) != 0) {
        SDL_Delay(100); // Poll every 100ms to avoid blocking the CPU
    }

    // Free the sound and clean up
    Mix_FreeChunk(sound);
    Mix_CloseAudio();
    SDL_Quit();
}


void displayimage(const char* filePath) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0 || IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
        printf("SDL or IMG_Init Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Window* window = SDL_CreateWindow("SDL2 Image Display", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 550, 600, SDL_WINDOW_SHOWN);
    if (!window) { printf("SDL_CreateWindow Error: %s\n", SDL_GetError()); return; }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) { printf("SDL_CreateRenderer Error: %s\n", SDL_GetError()); return; }

    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);
    if (!texture) { printf("IMG_LoadTexture Error: %s\n", IMG_GetError()); return; }

    SDL_RenderClear(renderer);  // Clear screen
    SDL_RenderCopy(renderer, texture, NULL, NULL);  // Render texture
    SDL_RenderPresent(renderer);  // Present renderer

    SDL_Delay(12000);  // Wait for 5 seconds

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void playbg1(const char* filePath) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0 || Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        //printf("SDL or SDL_mixer Error: %s\n", SDL_GetError());
        return;
    }

    Mix_Music* music = Mix_LoadMUS(filePath);
    if (!music) {
        //printf("Mix_LoadMUS Error: %s\n", Mix_GetError());
        return;
    }

    if (Mix_PlayMusic(music, -1) == -1) {
        //printf("Mix_PlayMusic Error: %s\n", Mix_GetError());
        return;
    }

    SDL_Event e;
    //printf("\033[44m");
    while (SDL_PollEvent(&e) && e.type != SDL_QUIT) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t___  ___  ________  ___       ________  ___\n");
        printf("\t\t\t\t\t\t\t|\\  \\|\\  \\|\\   __  \\|\\  \\     |\\   __  \\|\\  \\\n");
        printf("\t\t\t\t\t\t\t\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\|\\  \\ \\  \\\n");
        printf("\t\t\t\t\t\t\t \\ \\   __  \\ \\   __  \\ \\  \\    \\ \\   __  \\ \\  \\\n");
        printf("\t\t\t\t\t\t\t  \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\____\\ \\  \\ \\  \\ \\  \\____\n");
        printf("\t\t\t\t\t\t\t   \\ \\__\\ \\__\\ \\__\\ \\__\\ \\_______\\ \\__\\ \\__\\ \\_______\\\n");
        printf("\t\t\t\t\t\t\t    \\|__|\\|__|\\|__|\\|__|\\|_______|\\|__|\\|__|\\|_______|\n");
        printf("\t\t\t\t\t\t\t ________  ________  _________  ___  ________   ________\n");
        printf("\t\t\t\t\t\t\t|\\   ___ \\|\\   __  \\|\\___   ___\\\\  \\|\\   ___  \\|\\   ____\\\n");
        printf("\t\t\t\t\t\t\t\\ \\  \\_|\\ \\ \\  \\|\\  \\|___ \\  \\_\\ \\  \\ \\  \\\\ \\  \\ \\  \\___|\n");
        printf("\t\t\t\t\t\t\t \\ \\  \\ \\\\ \\ \\   __  \\   \\ \\  \\ \\ \\  \\ \\  \\\\ \\  \\ \\  \\  ___\n");
        printf("\t\t\t\t\t\t\t  \\ \\  \\_\\\\ \\ \\  \\ \\  \\   \\ \\  \\ \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\\n");
        printf("\t\t\t\t\t\t\t   \\ \\_______\\ \\__\\ \\__\\   \\ \\__\\ \\ \\__\\ \\__\\\\ \\__\\ \\_______\\\n");
        printf("\t\t\t\t\t\t\t    \\|_______|\\|__|\\|__|    \\|__|  \\|__|\\|__| \\|__|\\|_______|\n");
        printf("\n\n\t\t\t\t\t\t\t\t\tThe program is Loading: ");
        for (int i = 9; i >= 0; i--) {
            printf("%d", i);
            printf("\b");
            SDL_Delay(1500);
        }
        break;
    }

    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
}

void playbg3(const char* filePath) {
    // Initialisation SDL et SDL_mixer
    if (SDL_Init(SDL_INIT_AUDIO) < 0 || Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        // printf("SDL or SDL_mixer Error: %s\n", SDL_GetError());
        return;
    }

    // Charger la musique
    Mix_Music* music = Mix_LoadMUS(filePath);
    if (!music) {
        // printf("Mix_LoadMUS Error: %s\n", Mix_GetError());
        return;
    }

    // Lire la musique en boucle
    if (Mix_PlayMusic(music, -1) == -1) {
        // printf("Mix_PlayMusic Error: %s\n", Mix_GetError());
        return;
    }

    // Boucle d'événements SDL
    SDL_Event e;
    int quit = 0;

    while (!quit) {
        // Vérifier les événements SDL
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Affichage du motif
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t    ******       ******\n");
        printf("\t\t\t\t\t\t\t\t\t  **********   **********\n");
        printf("\t\t\t\t\t\t\t\t\t ************* *************\n");
        printf("\t\t\t\t\t\t\t\t\t*****************************\n");
        printf("\t\t\t\t\t\t\t\t\t ***************************\n");
        printf("\t\t\t\t\t\t\t\t\t   ***********************\n");
        printf("\t\t\t\t\t\t\t\t\t    *********************\n");
        printf("\t\t\t\t\t\t\t\t\t      *****************\n");
        printf("\t\t\t\t\t\t\t\t\t        *************\n");
        printf("\t\t\t\t\t\t\t\t\t          *********\n");
        printf("\t\t\t\t\t\t\t\t\t            *****\n");
        printf("\t\t\t\t\t\t\t\t\t              *\n");

        // Attendre pendant 7 secondes
        SDL_Delay(7000);
        quit = 1;  // Quitter après avoir joué la musique et affiché la forme une fois
    }

    // Libérer la musique et fermer SDL
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
}



void playbg2(const char* filePath) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0 || Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        //printf("SDL or SDL_mixer Error: %s\n", SDL_GetError());
        return;
    }

    Mix_Music* music = Mix_LoadMUS(filePath);
    if (!music) {
        //printf("Mix_LoadMUS Error: %s\n", Mix_GetError());
        return;
    }

    if (Mix_PlayMusic(music, -1) == -1) {
        //printf("Mix_PlayMusic Error: %s\n", Mix_GetError());
        return;
    }

    SDL_Event e;
    while (SDL_PollEvent(&e) && e.type != SDL_QUIT) {
        //displayimage("C:\\Users\\dell\\Downloads\\casablanca.jpg")
        SDL_Delay(1000);
        break;
    }
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
}

struct profile
{
    char name[100];
    int age;
    int gender;
};

void displaysafi(const char* filePath) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0 || IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
        printf("SDL or IMG_Init Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Window* window = SDL_CreateWindow("SDL2 Image Display", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 250, SDL_WINDOW_SHOWN);
    if (!window) { printf("SDL_CreateWindow Error: %s\n", SDL_GetError()); return; }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) { printf("SDL_CreateRenderer Error: %s\n", SDL_GetError()); return; }

    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);
    if (!texture) { printf("IMG_LoadTexture Error: %s\n", IMG_GetError()); return; }

    SDL_RenderClear(renderer);  // Clear screen
    SDL_RenderCopy(renderer, texture, NULL, NULL);  // Render texture
    SDL_RenderPresent(renderer);  // Present renderer

    SDL_Delay(12000);  // Wait for 5 seconds

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
int main(int argc, char* argv[]) {
    restart :
    system("cls");
    printf("\033[48;2;255;182;193m\033[30m");
    struct profile profile;
    //printf("\033[44;37m\033[0m\n");
    system("cls");
    int needed, choix,back, QT, ready, sh, kh;
    char traits[200];
    playbg1("C:\\Users\\dell\\Downloads\\clock2.mp3");
    system("cls");
    playbg2("C:\\Users\\dell\\Downloads\\twinkle2.mp3");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                            ________  ___  _______   ________   ___      ___ _______   ________   ___  ___  _______           \n");
    printf("                                           |\\   __  \\|\\  \\|\\  ___ \\ |\\   ___  \\|\\  \\    /  /|\\  ___ \\ |\\   ___  \\|\\  \\|\\  \\|\\  ___ \\          \n");
    printf("                                           \\ \\  \\|\\ /\\ \\  \\ \\   __/|\\ \\  \\\\ \\  \\ \\  \\  /  / | \\   __/|\\ \\  \\\\ \\  \\ \\  \\\\\\  \\ \\   __/|         \n");
    printf("                                            \\ \\   __  \\ \\  \\ \\  \\_|/_\\ \\  \\\\ \\  \\ \\  \\/  / / \\ \\  \\_|/_\\ \\  \\\\ \\  \\ \\  \\\\\\  \\ \\  \\_|/__       \n");
    printf("                                             \\ \\  \\|\\  \\ \\  \\ \\  \\_|\\ \\ \\  \\\\ \\  \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\ \\  \\ \\  \\\\\\  \\ \\  \\_|\\ \\      \n");
    printf("                                              \\ \\_______\\ \\__\\ \\_______\\ \\__\\\\ \\__\\ \\__/ /     \\ \\_______\\ \\__\\\\ \\__\\ \\_______\\ \\_______\\     \n");
    printf("                                               \\|_______|\\|__|\\|_______|\\|__| \\|__|\\|__|/       \\|_______|\\|__| \\|__|\\|_______|\\|_______|     \n");
    SDL_Delay(6000);
    //playbg2("C:\\Users\\dell\\Downloads\\twinkle.mp3");
    system("cls");
    //printf("\033[31m\033[40m");
    //system("espeak -v fr -s 100 -p 40 \"Trouvez votre partenaire ideal en toute confiance!\"");
    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t*************************************************************************\n");
    printf("\t\t\t\t\t\t*                                                                       *\n");
    printf("\t\t\t\t\t\t*       Trouvez votre partenaire ideal en toute confiance               *\n");
    printf("\t\t\t\t\t\t*                                                                       *\n");
    printf("\t\t\t\t\t\t*     avec notre programme |Halal Dating|. Dediee aux relations         *\n");
    printf("\t\t\t\t\t\t*                                                                       *\n");
    printf("\t\t\t\t\t\t*        serieuses dans le respect des valeurs islamiques \3             *\n");
    printf("\t\t\t\t\t\t*                                                                       *\n");
    printf("\t\t\t\t\t\t*************************************************************************\n\n");
    playSound("C:\\Users\\dell\\Downloads\\sound1.mp3");
    //char command[100];
    //sprintf(command, "espeak -v fr -s 100 -p 40 \"Trouvez votre partenaire ideal en toute confiance avec notre programme Halal Dating. Dediee aux relations!\"");
    //system(command);
    SDL_Delay(4000);
    system("cls");
    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t***************************************************************************************************************************\n");
    printf("\t\t\t*                                                                                                                         *\n");
    printf("\t\t\t*   PS: Avant commencez, Notre programme vous donne les cles et conseils necessaire pour trouvez votre future partenaire  *\n");
    printf("\t\t\t*                                                                                                                         *\n");
    printf("\t\t\t*                                 mais c'est a vous de prendre la decision finale!!                                       *\n");
    printf("\t\t\t*                                                                                                                         *\n");
    printf("\t\t\t***************************************************************************************************************************\n");
    playSound("C:\\Users\\dell\\Downloads\\sound2.mp3");
    SDL_Delay(4000);
    system("cls");
    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t                      ,---.           ,---.\n");
    printf("\t\t\t\t\t\t\t                    / /\"`.\\.--\"\"\"--./,'\"\\ \\\n");
    printf("\t\t\t\t\t\t\t                    \\ \\    _       _    / /\n");
    printf("\t\t\t\t\t\t\t                     `./  / __   __ \\  \\,'\n");
    printf("\t\t\t\t\t\t\t                      /    /_O)_(_O\\    \\\n");
    printf("\t\t\t\t\t\t\t                      |  .-'  ___  `-.  |\n");
    printf("\t\t\t\t\t\t\t                   .--|       \\_/       |--.\n");
    printf("\t\t\t\t\t\t\t                 ,'    \\   \\   |   /   /    `.\n");
    printf("\t\t\t\t\t\t\t                /       `.  `--^--'  ,'       \\\n");
    printf("\t\t\t\t\t\t\t             .-\"\"\"\"\"\"-.    `--.___.--'     .-\"\"\"\"\"\"-.\n");
    printf("\t\t\t\t\t\t\t.-----------/         \\------------------/         \\--------------.\n");
    printf("\t\t\t\t\t\t\t| .---------\\         /----------------- \\         /------------. |\n");
    printf("\t\t\t\t\t\t\t| |          `-`--`--'                    `--'--'-'             | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                     COMMENCONS PAR CREE                     | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                            VOTRE                            | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                           PROFIL !!                         | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |_____________________________________________________________| |\n");
    printf("\t\t\t\t\t\t\t|_________________________________________________________________|\n");
    printf("\t\t\t\t\t\t\t                   )__________|__|__________(\n");
    printf("\t\t\t\t\t\t\t                  |            ||            |\n");
    printf("\t\t\t\t\t\t\t                  |____________||____________|\n");
    printf("\t\t\t\t\t\t\t                    ),-----.(      ),-----. (\n");
    printf("\t\t\t\t\t\t\t                  ,'   ==.   \\    /  .==    `.\n");
    printf("\t\t\t\t\t\t\t                 /            )  (            \\\n");
    printf("\t\t\t\t\t\t\t                 `==========='    `==========='\n");
    playSound("C:\\Users\\dell\\Downloads\\sound3.mp3");
    system("cls");
    while(1)
    {
        system("cls");
        playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t  ________  ________  _______           ___  ___                       \n");
        printf("\t\t\t\t\t\t\t|\\   __  \\|\\   __  \\|\\  ___ \\         |\\  \\|\\  \\                      \n");
        printf("\t\t\t\t\t\t\t\\ \\  \\|\\  \\ \\  \\|\\  \\ \\   __/|        \\ \\  \\\\  \\                      \n");
        printf("\t\t\t\t\t\t\t \\ \\   __  \\ \\   _  _\\ \\  \\_|/__       \\ \\  \\\\  \\                     \n");
        printf("\t\t\t\t\t\t\t  \\ \\  \\ \\  \\ \\  \\\\  \\\\ \\  \\_|\\ \\       \\ \\  \\\\  \\                    \n");
        printf("\t\t\t\t\t\t\t   \\ \\__\\ \\__\\ \\__\\\\ _\\\\ \\_______\\       \\ \\_______\\                   \n");
        printf("\t\t\t\t\t\t\t    \\|__|\\|__|\\|__|\\|__|\\|_______|        \\|_______|                   \n\n\n\n");
        printf("\t\t\t\t\t\t\t ________  _______   ________  ________      ___    ___ ________      \n");
        printf("\t\t\t\t\t\t\t|\\   __  \\|\\  ___ \\ |\\   __  \\|\\   ___ \\    |\\  \\  /  /|\\_____  \\     \n");
        printf("\t\t\t\t\t\t\t\\ \\  \\|\\  \\ \\   __/|\\ \\  \\|\\  \\ \\  \\_|\ \   \\ \\  \\/  / ||____|\\  \\    \n");
        printf("\t\t\t\t\t\t\t \\ \\   _  _\\ \\  \\_|/_\\ \\   __  \\ \\  \\ \\\\ \\   \\ \\    / /      \\ \\__\\   \n");
        printf("\t\t\t\t\t\t\t  \\ \\  \\\\  \\\\ \\  \\_|\\ \\ \\  \\ \\  \\ \\  \\_\\\\ \\   \\/  /  /        \\|__|   \n");
        printf("\t\t\t\t\t\t\t   \\ \\__\\\\ _\\\\ \\_______\\ \\__\\ \\__\\ \\_______\\__/  / /              ___  \n");
        printf("\t\t\t\t\t\t\t    \\|__|\\|__|\\|_______|\\|__|\\|__|\\|_______|\\___/ /              |\\__\\  \n");
        printf("\t\t\t\t\t\t\t                                           \\|___|/               \\|__|  \n\n\n");
        printf("\t\t\t\t\t\t\t\tOUI : |TAPEZ 1|     ||       NON: |TAPEZ2|\n");
        printf("\n\t\t\t\t\t\t\t\t\tVotre choix est : ");
        //getchar();
        scanf("%d", &ready);
        getchar();
        system("cls");
        switch(ready)
        {
            case 1:
                break;
            case 2:
                while(1)
                {
                    system("cls");
                    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Quitter : |TAPEZ1|   ||   Recommencer : |TAPEZ2|   ||   Continuer : |TAPEZ3|\n\n");
                    printf("\t\t\t\t\t\t\t\t\t\t");
                    scanf("%d", &QT);
                    getchar();
                    system("cls");
                    switch(QT)
                    {
                        case 1:
                            playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                            printf("\n\n\n\n\n\n\n\n\n");
                            printf("\t\t\t\t\t\t\t\t\t________      ___    ___ _______   ___       \n");
                            printf("\t\t\t\t\t\t\t\t\t|\\   __  \\    |\\  \\  /  /|\\  ___ \\ |\\  \\      \n");
                            printf("\t\t\t\t\t\t\t\t\t\\ \\  \\\\ /_   \\ \\  \\/  / | \\   __/|\\ \\  \\     \n");
                            printf("\t\t\t\t\t\t\t\t\t \\ \\   __  \\   \\ \\    / / \\ \\  \\_|/_\\ \\  \\    \n");
                            printf("\t\t\t\t\t\t\t\t\t  \\ \\  \\\\  \\   \\/  /  /   \\ \\  \\_|\\ \\ \\__\\   \n");
                            printf("\t\t\t\t\t\t\t\t\t   \\ \\_______\\__/  / /      \\ \\_______\\|__|   \n");
                            printf("\t\t\t\t\t\t\t\t\t    \\|_______|\\___/ /        \\|_______|   ___ \n");
                            printf("\t\t\t\t\t\t\t\t\t             \\|___|/                     |\\__\\\n");
                            printf("\t\t\t\t\t\t\t\t\t                                         \\|__| \n");
                            return 0;
                        case 2:
                            goto restart;
                            break;
                        case 3:
                            goto firstqst;
                        default:
                            playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                            system("cls");
                            continue;
                    }
                    break;
                }
            default:
                playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                system("cls");
                continue;
        }
        break;
        system("cls");
    }
    firstqst :
    system("cls");
    //firstqst :
    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t                      ,---.           ,---.\n");
    printf("\t\t\t\t\t\t\t                    / /\"`.\\.--\"\"\"--./,'\"\\ \\\n");
    printf("\t\t\t\t\t\t\t                    \\ \\    _       _    / /\n");
    printf("\t\t\t\t\t\t\t                     `./  / __   __ \\  \\,'\n");
    printf("\t\t\t\t\t\t\t                      /    /_O)_(_O\\    \\\n");
    printf("\t\t\t\t\t\t\t                      |  .-'  ___  `-.  |\n");
    printf("\t\t\t\t\t\t\t                   .--|       \\_/       |--.\n");
    printf("\t\t\t\t\t\t\t                 ,'    \\   \\   |   /   /    `.\n");
    printf("\t\t\t\t\t\t\t                /       `.  `--^--'  ,'       \\\n");
    printf("\t\t\t\t\t\t\t             .-\"\"\"\"\"\"-.    `--.___.--'     .-\"\"\"\"\"\"-.\n");
    printf("\t\t\t\t\t\t\t.-----------/         \\------------------/         \\--------------.\n");
    printf("\t\t\t\t\t\t\t| .---------\\         /----------------- \\         /------------. |\n");
    printf("\t\t\t\t\t\t\t| |          `-`--`--'                    `--'--'-'             | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                     Dabord SVP inserez                      | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                           Votre                             | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                            nom \3                            | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |                                                             | |\n");
    printf("\t\t\t\t\t\t\t| |_____________________________________________________________| |\n");
    printf("\t\t\t\t\t\t\t|_________________________________________________________________|\n");
    printf("\t\t\t\t\t\t\t                   )__________|__|__________(\n");
    printf("\t\t\t\t\t\t\t                  |            ||            |\n");
    printf("\t\t\t\t\t\t\t                  |____________||____________|\n");
    printf("\t\t\t\t\t\t\t                    ),-----.(      ),-----. (\n");
    printf("\t\t\t\t\t\t\t                  ,'   ==.   \\    /  .==    `.\n");
    printf("\t\t\t\t\t\t\t                 /            )  (            \\\n");
    printf("\t\t\t\t\t\t\t                 `==========='    `==========='\n");
    playSound("C:\\Users\\dell\\Downloads\\nom.mp3");
    printf("\n\t\t\t\t\t\t\t\tVotre nom est : ");
    gets(profile.name);
    system("cls");
    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Bonjour %s , Nous sommes ravis de vous voir ici \3\3\n", profile.name);
    playSound("C:\\Users\\dell\\Downloads\\ravi.mp3");
    SDL_Delay(2500);
    secondqst :
    system("cls");
    while(1)
    {
        playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t                      ,---.           ,---.\n");
        printf("\t\t\t\t\t\t\t                    / /\"`.\\.--\"\"\"--./,'\"\\ \\\n");
        printf("\t\t\t\t\t\t\t                    \\ \\    _       _    / /\n");
        printf("\t\t\t\t\t\t\t                     `./  / __   __ \\  \\,'\n");
        printf("\t\t\t\t\t\t\t                      /    /_O)_(_O\\    \\\n");
        printf("\t\t\t\t\t\t\t                      |  .-'  ___  `-.  |\n");
        printf("\t\t\t\t\t\t\t                   .--|       \\_/       |--.\n");
        printf("\t\t\t\t\t\t\t                 ,'    \\   \\   |   /   /    `.\n");
        printf("\t\t\t\t\t\t\t                /       `.  `--^--'  ,'       \\\n");
        printf("\t\t\t\t\t\t\t             .-\"\"\"\"\"\"-.    `--.___.--'     .-\"\"\"\"\"\"-.\n");
        printf("\t\t\t\t\t\t\t.-----------/         \\------------------/         \\--------------.\n");
        printf("\t\t\t\t\t\t\t| .---------\\         /----------------- \\         /------------. |\n");
        printf("\t\t\t\t\t\t\t| |          `-`--`--'                    `--'--'-'             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                      Choisissez votre                       | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                           genre                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |          MALE : |TAPEZ 1|  ||  FEMELLE : |TAPEZ 2|          | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |_____________________________________________________________| |\n");
        printf("\t\t\t\t\t\t\t|_________________________________________________________________|\n");
        printf("\t\t\t\t\t\t\t                   )__________|__|__________(\n");
        printf("\t\t\t\t\t\t\t                  |            ||            |\n");
        printf("\t\t\t\t\t\t\t                  |____________||____________|\n");
        printf("\t\t\t\t\t\t\t                    ),-----.(      ),-----. (\n");
        printf("\t\t\t\t\t\t\t                  ,'   ==.   \\    /  .==    `.\n");
        printf("\t\t\t\t\t\t\t                 /            )  (            \\\n");
        printf("\t\t\t\t\t\t\t                 `==========='    `==========='\n");
        playSound("C:\\Users\\dell\\Downloads\\genre.mp3");
        printf("\n\t\t\t\t\t\t\t\tVotre choix est : ");
        //getchar();
        scanf("%d", &profile.gender);
        getchar();
        system("cls");
        switch(profile.gender)
        {
            case 1:
                break;
            case 2:
                break;
            default:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                system("cls");
                continue;
        }
        break;
    }
    system("cls");
    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t    ******       ******\n");
    printf("\t\t\t\t\t\t\t\t\t  **********   **********\n");
    printf("\t\t\t\t\t\t\t\t\t ************* *************\n");
    printf("\t\t\t\t\t\t\t\t\t*****************************\n");
    printf("\t\t\t\t\t\t\t\t\t ***************************\n");
    printf("\t\t\t\t\t\t\t\t\t   ***********************\n");
    printf("\t\t\t\t\t\t\t\t\t    *********************\n");
    printf("\t\t\t\t\t\t\t\t\t      *****************\n");
    printf("\t\t\t\t\t\t\t\t\t        *************\n");
    printf("\t\t\t\t\t\t\t\t\t          *********\n");
    printf("\t\t\t\t\t\t\t\t\t            *****\n");
    printf("\t\t\t\t\t\t\t\t\t              *\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\tl'age n'est qu'un chiffre , c'est votre esprit qui vous definit");
    playSound("C:\\Users\\dell\\Downloads\\age1.mp3");
    SDL_Delay(2500);
    thirdqst :
    system("cls");
    needed = 0;
    while(needed != 1)
    {
        system("cls");
        playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t                      ,---.           ,---.\n");
        printf("\t\t\t\t\t\t\t                    / /\"`.\\.--\"\"\"--./,'\"\\ \\\n");
        printf("\t\t\t\t\t\t\t                    \\ \\    _       _    / /\n");
        printf("\t\t\t\t\t\t\t                     `./  / __   __ \\  \\,'\n");
        printf("\t\t\t\t\t\t\t                      /    /_O)_(_O\\    \\\n");
        printf("\t\t\t\t\t\t\t                      |  .-'  ___  `-.  |\n");
        printf("\t\t\t\t\t\t\t                   .--|       \\_/       |--.\n");
        printf("\t\t\t\t\t\t\t                 ,'    \\   \\   |   /   /    `.\n");
        printf("\t\t\t\t\t\t\t                /       `.  `--^--'  ,'       \\\n");
        printf("\t\t\t\t\t\t\t             .-\"\"\"\"\"\"-.    `--.___.--'     .-\"\"\"\"\"\"-.\n");
        printf("\t\t\t\t\t\t\t.-----------/         \\------------------/         \\--------------.\n");
        printf("\t\t\t\t\t\t\t| .---------\\         /----------------- \\         /------------. |\n");
        printf("\t\t\t\t\t\t\t| |          `-`--`--'                    `--'--'-'             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                     Et puis SVP inserez                     | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                           Votre                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                            age \3                            | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |_____________________________________________________________| |\n");
        printf("\t\t\t\t\t\t\t|_________________________________________________________________|\n");
        printf("\t\t\t\t\t\t\t                   )__________|__|__________(\n");
        printf("\t\t\t\t\t\t\t                  |            ||            |\n");
        printf("\t\t\t\t\t\t\t                  |____________||____________|\n");
        printf("\t\t\t\t\t\t\t                    ),-----.(      ),-----. (\n");
        printf("\t\t\t\t\t\t\t                  ,'   ==.   \\    /  .==    `.\n");
        printf("\t\t\t\t\t\t\t                 /            )  (            \\\n");
        printf("\t\t\t\t\t\t\t                 `==========='    `==========='\n");
        playSound("C:\\Users\\dell\\Downloads\\age2.mp3");
        printf("\n\n\t\t\t\t\t\t\t\tVotre age est : ");
        //getchar();
        scanf("%d", &profile.age);
        getchar();
        if(profile.age >= 20)
        {
            system("cls");
            needed = 1;
            playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
            switch(profile.gender)
            {
                case 1:
                    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ______________________________\n");
                    printf("\t\t\t\t\t\t\t\t\t / \\                             \\.\n");
                    printf("\t\t\t\t\t\t\t\t\t|   |         1. CONSEIL           |.\n");
                    printf("\t\t\t\t\t\t\t\t\t \\_  |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |       Pour votre cas       |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |    L'age de votre future   |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |       partenaire doit      |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |         preferement        |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |     etre entre %d et %d.   |.\n", profile.age-2,profile.age);
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |   _________________________|___\n");
                    printf("\t\t\t\t\t\t\t\t\t    |  /                            /.\n");
                    printf("\t\t\t\t\t\t\t\t\t    \\_/____________________________/.\n");
                    SDL_Delay(5500);
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ______________________________\n");
                    printf("\t\t\t\t\t\t\t\t\t / \\                             \\.\n");
                    printf("\t\t\t\t\t\t\t\t\t|   |         1. CONSEIL           |.\n");
                    printf("\t\t\t\t\t\t\t\t\t \\_  |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |       Pour votre cas       |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |    L'age de votre future   |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |       partenaire doit      |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |         preferement        |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |     etre entre %d et %d.   |.\n", profile.age+2,profile.age);
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |   _________________________|___\n");
                    printf("\t\t\t\t\t\t\t\t\t    |  /                            /.\n");
                    printf("\t\t\t\t\t\t\t\t\t    \\_/____________________________/.\n");
                    SDL_Delay(5500);
                    break;
                default:
                    break;
            }
        }
        else if(profile.age>=18 && profile.age<20)
        {
            system("cls");
            needed = 1;
            playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
            switch(profile.gender)
            {
                case 1:
                    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ______________________________\n");
                    printf("\t\t\t\t\t\t\t\t\t / \\                             \\.\n");
                    printf("\t\t\t\t\t\t\t\t\t|   |         1. CONSEIL           |.\n");
                    printf("\t\t\t\t\t\t\t\t\t \\_   |                           |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |       Pour votre cas       |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |    L'age de votre future   |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |       partenaire doit      |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |         preferement        |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |            etre %d .       |.\n", profile.age);
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |   _________________________|___\n");
                    printf("\t\t\t\t\t\t\t\t\t    |  /                            /.\n");
                    printf("\t\t\t\t\t\t\t\t\t    \\_/____________________________/.\n");
                    SDL_Delay(5500);
                    break;
                case 2:
                    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ______________________________\n");
                    printf("\t\t\t\t\t\t\t\t\t / \\                             \\.\n");
                    printf("\t\t\t\t\t\t\t\t\t|   |         1. CONSEIL           |.\n");
                    printf("\t\t\t\t\t\t\t\t\t \\_  |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |       Pour votre cas       |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |    L'age de votre future   |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |       partenaire doit      |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |         preferement        |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |     etre entre %d et %d.   |.\n", profile.age+2,profile.age);
                    printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                    printf("\t\t\t\t\t\t\t\t\t    |   _________________________|___\n");
                    printf("\t\t\t\t\t\t\t\t\t    |  /                            /.\n");
                    printf("\t\t\t\t\t\t\t\t\t    \\_/____________________________/.\n");
                    SDL_Delay(5500);
                    break;
                default:
                    break;
            }
        }
        else if(profile.age<18 && profile.age>0)
        {
            system("cls");
            playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tDesolee, notre programme est reserve aux personnes majeurs\n");
            printf("\n\n\t\t\t\t\t\t\t\tnous vous encourageons a revenir des que vous aurez 18 ans\n");
            printf("\n\n\t\t\t\t\t\t\t\tMerci, pour votre comprehension \3\n");
            playSound("C:\\Users\\dell\\Downloads\\khroj.mp3");
            SDL_Delay(2500);
            system("cls");
            playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
            printf("\n\n\n\n\n\n\n\n\n\n\n");
            printf("\t\t\t\t\t\t\t\t\t________      ___    ___ _______   ___       \n");
            printf("\t\t\t\t\t\t\t\t\t|\\   __  \\    |\\  \\  /  /|\\  ___ \\ |\\  \\      \n");
            printf("\t\t\t\t\t\t\t\t\t\\ \\  \\\\ /_   \\ \\  \\/  / | \\   __/|\\ \\  \\     \n");
            printf("\t\t\t\t\t\t\t\t\t \\ \\   __  \\   \\ \\    / / \\ \\  \\_|/_\\ \\  \\    \n");
            printf("\t\t\t\t\t\t\t\t\t  \\ \\  \\\\  \\   \\/  /  /   \\ \\  \\_|\\ \\ \\__\\   \n");
            printf("\t\t\t\t\t\t\t\t\t   \\ \\_______\\__/  / /      \\ \\_______\\|__|   \n");
            printf("\t\t\t\t\t\t\t\t\t    \\|_______|\\___/ /        \\|_______|   ___ \n");
            printf("\t\t\t\t\t\t\t\t\t             \\|___|/                     |\\__\\\n");
            printf("\t\t\t\t\t\t\t\t\t                                         \\|__| \n");
            SDL_Delay(2500);
            return 0;
        }
        else
        {
            system("cls");
            playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
        }
    }
    system("cls");
    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t******************************************************\n");
    printf("\t\t\t\t\t\t\t*     Maintenant, nous allons vous poser des         *\n");
    printf("\t\t\t\t\t\t\t*     questions personnelles. Si une question        *\n");
    printf("\t\t\t\t\t\t\t*     vous derange, vous pouvez toujours la sauter.  *\n");
    printf("\t\t\t\t\t\t\t******************************************************\n");
    playSound("C:\\Users\\dell\\Downloads\\sautez.mp3");
    fourthqst :
    system("cls");
    while(1)
    {
        playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t                      ,---.           ,---.\n");
        printf("\t\t\t\t\t\t\t                    / /\"`.\\.--\"\"\"--./,'\"\\ \\\n");
        printf("\t\t\t\t\t\t\t                    \\ \\    _       _    / /\n");
        printf("\t\t\t\t\t\t\t                     `./  / __   __ \\  \\,'\n");
        printf("\t\t\t\t\t\t\t                      /    /_O)_(_O\\    \\\n");
        printf("\t\t\t\t\t\t\t                      |  .-'  ___  `-.  |\n");
        printf("\t\t\t\t\t\t\t                   .--|       \\_/       |--.\n");
        printf("\t\t\t\t\t\t\t                 ,'    \\   \\   |   /   /    `.\n");
        printf("\t\t\t\t\t\t\t                /       `.  `--^--'  ,'       \\\n");
        printf("\t\t\t\t\t\t\t             .-\"\"\"\"\"\"-.    `--.___.--'     .-\"\"\"\"\"\"-.\n");
        printf("\t\t\t\t\t\t\t.-----------/         \\------------------/         \\--------------.\n");
        printf("\t\t\t\t\t\t\t| .---------\\         /----------------- \\         /------------. |\n");
        printf("\t\t\t\t\t\t\t| |          `-`--`--'                    `--'--'-'             | |\n");
        printf("\t\t\t\t\t\t\t| |      Quelle est l'importance de la religion pour vous?      | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                  1- Tres importante.                        | |\n");
        printf("\t\t\t\t\t\t\t| |                  2- Moyennement importante.                 | |\n");
        printf("\t\t\t\t\t\t\t| |                  3- Pas tres importante.                    | |\n");
        printf("\t\t\t\t\t\t\t| |                  4- Sautez la quesion.                      | |\n");
        printf("\t\t\t\t\t\t\t| |                  5- MENU                                    | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |              TAPEZ LE NUMERO DE VOTRE CHOIX                 | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |_____________________________________________________________| |\n");
        printf("\t\t\t\t\t\t\t|_________________________________________________________________|\n");
        printf("\t\t\t\t\t\t\t                   )__________|__|__________(\n");
        printf("\t\t\t\t\t\t\t                  |            ||            |\n");
        printf("\t\t\t\t\t\t\t                  |____________||____________|\n");
        printf("\t\t\t\t\t\t\t                    ),-----.(      ),-----. (\n");
        printf("\t\t\t\t\t\t\t                  ,'   ==.   \\    /  .==    `.\n");
        printf("\t\t\t\t\t\t\t                 /            )  (            \\\n");
        printf("\t\t\t\t\t\t\t                 `==========='    `==========='\n");
        playSound("C:\\Users\\dell\\Downloads\\religion.mp3");
        printf("\n\t\t\t\t\t\t\t\tVotre choix est : ");
        //getchar();
        scanf("%d", &choix);
        getchar();
        system("cls");
        switch(choix)
        {
            case 1:
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ______________________________\n");
                printf("\t\t\t\t\t\t\t\t\t / \\                             \\.\n");
                printf("\t\t\t\t\t\t\t\t\t|   |         2. CONSEIL           |.\n");
                printf("\t\t\t\t\t\t\t\t\t \\_  |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |     Cherche quelqu'un qui  |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |  t'encourage a vivre selon |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |       tes principes        |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |         religieux .        |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |   _________________________|___\n");
                printf("\t\t\t\t\t\t\t\t\t    |  /                            /.\n");
                printf("\t\t\t\t\t\t\t\t\t    \\_/____________________________/.\n");
                SDL_Delay(5500);
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ______________________________\n");
                printf("\t\t\t\t\t\t\t\t\t / \\                             \\.\n");
                printf("\t\t\t\t\t\t\t\t\t|   |         2. CONSEIL           |.\n");
                printf("\t\t\t\t\t\t\t\t\t \\_  |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |     Cherche quelqu'un dont |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |   les valeurs spirituelles |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |       et religieux         |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |         correspondent      |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |          aux tiens .       |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |   _________________________|___\n");
                printf("\t\t\t\t\t\t\t\t\t    |  /                            /.\n");
                printf("\t\t\t\t\t\t\t\t\t    \\_/____________________________/.\n");
                SDL_Delay(5500);
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ______________________________\n");
                printf("\t\t\t\t\t\t\t\t\t / \\                             \\.\n");
                printf("\t\t\t\t\t\t\t\t\t|   |         2. CONSEIL           |.\n");
                printf("\t\t\t\t\t\t\t\t\t \\_  |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |       Cherche quelqu'un    |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |         qui a aussi        |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |          un esprit         |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |            ouvert .        |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |   _________________________|___\n");
                printf("\t\t\t\t\t\t\t\t\t    |  /                            /.\n");
                printf("\t\t\t\t\t\t\t\t\t    \\_/____________________________/.\n");
                SDL_Delay(5500);
                break;
            case 4:
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tOn est tres desolee pour vous derange \3\n");
                break;
            case 5:
                while(1)
                {
                    system("cls");
                    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t Quitter : |TAPEZ1|   ||   Recommencer : |TAPEZ2|   ||   Retourner : |TAPEZ3|   || Retourner a la question precedente : |TAPEZ4|\n\n");
                    printf("\t\t\t\t\t\t\t\t\t\t");
                    scanf("%d", &QT);
                    getchar();
                    switch(QT)
                    {
                        case 1:
                            system("cls");
                            playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                            printf("\n\n\n\n\n\n\n\n\n\n\n");
                            printf("\t\t\t\t\t\t\t\t\t________      ___    ___ _______   ___       \n");
                            printf("\t\t\t\t\t\t\t\t\t|\\   __  \\    |\\  \\  /  /|\\  ___ \\ |\\  \\      \n");
                            printf("\t\t\t\t\t\t\t\t\t\\ \\  \\\\ /_   \\ \\  \\/  / | \\   __/|\\ \\  \\     \n");
                            printf("\t\t\t\t\t\t\t\t\t \\ \\   __  \\   \\ \\    / / \\ \\  \\_|/_\\ \\  \\    \n");
                            printf("\t\t\t\t\t\t\t\t\t  \\ \\  \\\\  \\   \\/  /  /   \\ \\  \\_|\\ \\ \\__\\   \n");
                            printf("\t\t\t\t\t\t\t\t\t   \\ \\_______\\__/  / /      \\ \\_______\\|__|   \n");
                            printf("\t\t\t\t\t\t\t\t\t    \\|_______|\\___/ /        \\|_______|   ___ \n");
                            printf("\t\t\t\t\t\t\t\t\t             \\|___|/                     |\\__\\\n");
                            printf("\t\t\t\t\t\t\t\t\t                                         \\|__| \n");
                            return 0;
                        case 2:
                            goto restart;
                            break;
                        case 3:
                            goto fourthqst;
                            break;
                        case 4:
                            goto thirdqst;
                        default:
                            system("cls");
                            playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                            system("cls");
                            continue;
                    }
                    break;
                }
            default:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                system("cls");
                continue;
        }
        break;
    }
    fifthqst :
    system("cls");
    while(1)
    {
        playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t                      ,---.           ,---.\n");
        printf("\t\t\t\t\t\t\t                    / /\"`.\\.--\"\"\"--./,'\"\\ \\\n");
        printf("\t\t\t\t\t\t\t                    \\ \\    _       _    / /\n");
        printf("\t\t\t\t\t\t\t                     `./  / __   __ \\  \\,'\n");
        printf("\t\t\t\t\t\t\t                      /    /_O)_(_O\\    \\\n");
        printf("\t\t\t\t\t\t\t                      |  .-'  ___  `-.  |\n");
        printf("\t\t\t\t\t\t\t                   .--|       \\_/       |--.\n");
        printf("\t\t\t\t\t\t\t                 ,'    \\   \\   |   /   /    `.\n");
        printf("\t\t\t\t\t\t\t                /       `.  `--^--'  ,'       \\\n");
        printf("\t\t\t\t\t\t\t             .-\"\"\"\"\"\"-.    `--.___.--'     .-\"\"\"\"\"\"-.\n");
        printf("\t\t\t\t\t\t\t.-----------/         \\------------------/         \\--------------.\n");
        printf("\t\t\t\t\t\t\t| .---------\\         /----------------- \\         /------------. |\n");
        printf("\t\t\t\t\t\t\t| |          `-`--`--'                    `--'--'-'             | |\n");
        printf("\t\t\t\t\t\t\t| |       Quelle est l'importance de la famille pour vous?      | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                  1- Tres importante.                        | |\n");
        printf("\t\t\t\t\t\t\t| |                  2- Moyennement importante.                 | |\n");
        printf("\t\t\t\t\t\t\t| |                  3- Pas tres importante.                    | |\n");
        printf("\t\t\t\t\t\t\t| |                  4- Sautez la question.                     | |\n");
        printf("\t\t\t\t\t\t\t| |                  5- MENU                                    | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |              TAPEZ LE NUMERO DE VOTRE CHOIX                 | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |_____________________________________________________________| |\n");
        printf("\t\t\t\t\t\t\t|_________________________________________________________________|\n");
        printf("\t\t\t\t\t\t\t                   )__________|__|__________(\n");
        printf("\t\t\t\t\t\t\t                  |            ||            |\n");
        printf("\t\t\t\t\t\t\t                  |____________||____________|\n");
        printf("\t\t\t\t\t\t\t                    ),-----.(      ),-----. (\n");
        printf("\t\t\t\t\t\t\t                  ,'   ==.   \\    /  .==    `.\n");
        printf("\t\t\t\t\t\t\t                 /            )  (            \\\n");
        printf("\t\t\t\t\t\t\t                 `==========='    `==========='\n");
        playSound("C:\\Users\\dell\\Downloads\\famille.mp3");
        printf("\n\t\t\t\t\t\t\t\tVotre choix est : ");
        //getchar();
        scanf("%d", &choix);
        getchar();
        system("cls");
        playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
        switch(choix)
        {
            case 1:
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ______________________________\n");
                printf("\t\t\t\t\t\t\t\t\t / \\                             \\.\n");
                printf("\t\t\t\t\t\t\t\t\t|   |         3. CONSEIL           |.\n");
                printf("\t\t\t\t\t\t\t\t\t \\_  |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |     Cherche quelqu'un qui  |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");//Cherche quelqu'un qui valorise les liens familiaux
                printf("\t\t\t\t\t\t\t\t\t    |        valorise les        |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |           liens            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |         familiaux .        |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |   _________________________|___\n");
                printf("\t\t\t\t\t\t\t\t\t    |  /                            /.\n");
                printf("\t\t\t\t\t\t\t\t\t    \\_/____________________________/.\n");
                SDL_Delay(5500);
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ______________________________\n");
                printf("\t\t\t\t\t\t\t\t\t / \\                             \\.\n");
                printf("\t\t\t\t\t\t\t\t\t|   |         3. CONSEIL           |.\n");
                printf("\t\t\t\t\t\t\t\t\t \\_  |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |     Cherche quelqu'un qui  |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |     respecte l'importance  |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");//Cherche quelqu'un qui respecte l'importance de la famille dans ta vie
                printf("\t\t\t\t\t\t\t\t\t    |        de la famille       |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |         dans ta vie .      |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |   _________________________|___\n");
                printf("\t\t\t\t\t\t\t\t\t    |  /                            /.\n");
                printf("\t\t\t\t\t\t\t\t\t    \\_/____________________________/.\n");
                SDL_Delay(5500);
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ______________________________\n");
                printf("\t\t\t\t\t\t\t\t\t / \\                             \\.\n");
                printf("\t\t\t\t\t\t\t\t\t|   |         3. CONSEIL           |.\n");
                printf("\t\t\t\t\t\t\t\t\t \\_  |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |       Cherche quelqu'un    |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");//Cherche quelqu'un qui respect votre derangement de la vie familiale
                printf("\t\t\t\t\t\t\t\t\t    |       qui respect votre    |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |       derangement de la    |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |        vie familiale .     |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |   _________________________|___\n");
                printf("\t\t\t\t\t\t\t\t\t    |  /                            /.\n");
                printf("\t\t\t\t\t\t\t\t\t    \\_/____________________________/.\n");
                SDL_Delay(5500);
                break;
            case 4:
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tOn est tres desolee pour vous derange \3\n");
                break;
            case 5:
                while(1)
                {
                    system("cls");
                    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t Quitter : |TAPEZ1|   ||   Recommencer : |TAPEZ2|   ||   Retourner : |TAPEZ3|   || Retourner a la question precedente : |TAPEZ4|\n\n");
                    printf("\t\t\t\t\t\t\t\t\t\t");
                    scanf("%d", &QT);
                    getchar();
                    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                    switch(QT)
                    {
                        case 1:
                            system("cls");
                            playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                            printf("\n\n\n\n\n\n\n\n\n\n");
                            printf("\t\t\t\t\t\t\t\t\t________      ___    ___ _______   ___       \n");
                            printf("\t\t\t\t\t\t\t\t\t|\\   __  \\    |\\  \\  /  /|\\  ___ \\ |\\  \\      \n");
                            printf("\t\t\t\t\t\t\t\t\t\\ \\  \\\\ /_   \\ \\  \\/  / | \\   __/|\\ \\  \\     \n");
                            printf("\t\t\t\t\t\t\t\t\t \\ \\   __  \\   \\ \\    / / \\ \\  \\_|/_\\ \\  \\    \n");
                            printf("\t\t\t\t\t\t\t\t\t  \\ \\  \\\\  \\   \\/  /  /   \\ \\  \\_|\\ \\ \\__\\   \n");
                            printf("\t\t\t\t\t\t\t\t\t   \\ \\_______\\__/  / /      \\ \\_______\\|__|   \n");
                            printf("\t\t\t\t\t\t\t\t\t    \\|_______|\\___/ /        \\|_______|   ___ \n");
                            printf("\t\t\t\t\t\t\t\t\t             \\|___|/                     |\\__\\\n");
                            printf("\t\t\t\t\t\t\t\t\t                                         \\|__| \n");
                            return 0;
                        case 2:
                            goto restart;
                            break;
                        case 3:
                            goto fifthqst;
                            break;
                        case 4:
                            goto fourthqst;
                        default:
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                            system("cls");
                            continue;
                    }
                    break;
                }
            default:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                system("cls");
                continue;
        }
        break;
    }
    sixthqst :
    system("cls");
    while(1)
    {
        playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t                      ,---.           ,---.\n");
        printf("\t\t\t\t\t\t\t                    / /\"`.\\.--\"\"\"--./,'\"\\ \\\n");
        printf("\t\t\t\t\t\t\t                    \\ \\    _       _    / /\n");
        printf("\t\t\t\t\t\t\t                     `./  / __   __ \\  \\,'\n");
        printf("\t\t\t\t\t\t\t                      /    /_O)_(_O\\    \\\n");
        printf("\t\t\t\t\t\t\t                      |  .-'  ___  `-.  |\n");
        printf("\t\t\t\t\t\t\t                   .--|       \\_/       |--.\n");
        printf("\t\t\t\t\t\t\t                 ,'    \\   \\   |   /   /    `.\n");
        printf("\t\t\t\t\t\t\t                /       `.  `--^--'  ,'       \\\n");
        printf("\t\t\t\t\t\t\t             .-\"\"\"\"\"\"-.    `--.___.--'     .-\"\"\"\"\"\"-.\n");
        printf("\t\t\t\t\t\t\t.-----------/         \\------------------/         \\--------------.\n");
        printf("\t\t\t\t\t\t\t| .---------\\         /----------------- \\         /------------. |\n");
        printf("\t\t\t\t\t\t\t| |          `-`--`--'                    `--'--'-'             | |\n");
        printf("\t\t\t\t\t\t\t| |                 Comment vous decriez vous?                  | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                  1- introverti(e).                          | |\n");
        printf("\t\t\t\t\t\t\t| |                  2- extraverti(e).                          | |\n");
        printf("\t\t\t\t\t\t\t| |                  3- Un peu des deux..                       | |\n");
        printf("\t\t\t\t\t\t\t| |                  4- Sautez la quesion.                      | |\n");
        printf("\t\t\t\t\t\t\t| |                  5- MENU                                    | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |              TAPEZ LE NUMERO DE VOTRE CHOIX                 | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |_____________________________________________________________| |\n");
        printf("\t\t\t\t\t\t\t|_________________________________________________________________|\n");
        printf("\t\t\t\t\t\t\t                   )__________|__|__________(\n");
        printf("\t\t\t\t\t\t\t                  |            ||            |\n");
        printf("\t\t\t\t\t\t\t                  |____________||____________|\n");
        printf("\t\t\t\t\t\t\t                    ),-----.(      ),-----. (\n");
        printf("\t\t\t\t\t\t\t                  ,'   ==.   \\    /  .==    `.\n");
        printf("\t\t\t\t\t\t\t                 /            )  (            \\\n");
        printf("\t\t\t\t\t\t\t                 `==========='    `==========='\n");
        playSound("C:\\Users\\dell\\Downloads\\introvert.mp3");
        printf("\n\t\t\t\t\t\t\t\tVotre choix est : ");
        //getchar();
        scanf("%d", &choix);
        getchar();
        system("cls");
        playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
        switch(choix)
        {
            case 1:
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ______________________________\n");
                printf("\t\t\t\t\t\t\t\t\t / \\                             \\.\n");
                printf("\t\t\t\t\t\t\t\t\t|   |         4. CONSEIL           |.\n");
                printf("\t\t\t\t\t\t\t\t\t \\_  |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |     Cherche quelqu'un qui  |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");//Cherche quelqu'un qui comprend l'importance de ton espace personel .
                printf("\t\t\t\t\t\t\t\t\t    |     comprend l'importance  |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |         de ton espace      |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |          personel .        |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |   _________________________|___\n");
                printf("\t\t\t\t\t\t\t\t\t    |  /                            /.\n");
                printf("\t\t\t\t\t\t\t\t\t    \\_/____________________________/.\n");
                SDL_Delay(5500);
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ______________________________\n");
                printf("\t\t\t\t\t\t\t\t\t / \\                             \\.\n");
                printf("\t\t\t\t\t\t\t\t\t|   |         4. CONSEIL           |.\n");
                printf("\t\t\t\t\t\t\t\t\t \\_  |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |     Cherche quelqu'un qui  |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |          partage           |.\n");//Cherche quelqu'un qui partage ton energie
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |        ton energie .       |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |   _________________________|___\n");
                printf("\t\t\t\t\t\t\t\t\t    |  /                            /.\n");
                printf("\t\t\t\t\t\t\t\t\t    \\_/____________________________/.\n");
                SDL_Delay(5500);
                break;
            case 3:
                printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ______________________________\n");
                printf("\t\t\t\t\t\t\t\t\t / \\                             \\.\n");
                printf("\t\t\t\t\t\t\t\t\t|   |         4. CONSEIL           |.\n");
                printf("\t\t\t\t\t\t\t\t\t \\_  |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |       Cherche quelqu'un    |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");//Cherche quelqu'un qui te comprend , et soit toujours ouvert pour communiquer
                printf("\t\t\t\t\t\t\t\t\t    |        qui te comprend     |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |        et soit toujours    |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |   ouvert pour communiquer. |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |                            |.\n");
                printf("\t\t\t\t\t\t\t\t\t    |   _________________________|___\n");
                printf("\t\t\t\t\t\t\t\t\t    |  /                            /.\n");
                printf("\t\t\t\t\t\t\t\t\t    \\_/____________________________/.\n");
                SDL_Delay(5500);
                break;
            case 4:
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tOn est tres desolee pour vous derange \3\n");
                break;
            case 5:
                while(1)
                {
                    system("cls");
                    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t Quitter : |TAPEZ1|   ||   Recommencer : |TAPEZ2|   ||   Retourner : |TAPEZ3|   || Retourner a la question precedente : |TAPEZ4|\n\n");
                    printf("\t\t\t\t\t\t\t\t\t\t");
                    scanf("%d", &QT);
                    getchar();
                    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                    switch(QT)
                    {
                        case 1:
                            system("cls");
                            playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                            printf("\n\n\n\n\n\n\n\n\n");
                            printf("\t\t\t\t\t\t\t\t\t________      ___    ___ _______   ___       \n");
                            printf("\t\t\t\t\t\t\t\t\t|\\   __  \\    |\\  \\  /  /|\\  ___ \\ |\\  \\      \n");
                            printf("\t\t\t\t\t\t\t\t\t\\ \\  \\\\ /_   \\ \\  \\/  / | \\   __/|\\ \\  \\     \n");
                            printf("\t\t\t\t\t\t\t\t\t \\ \\   __  \\   \\ \\    / / \\ \\  \\_|/_\\ \\  \\    \n");
                            printf("\t\t\t\t\t\t\t\t\t  \\ \\  \\\\  \\   \\/  /  /   \\ \\  \\_|\\ \\ \\__\\   \n");
                            printf("\t\t\t\t\t\t\t\t\t   \\ \\_______\\__/  / /      \\ \\_______\\|__|   \n");
                            printf("\t\t\t\t\t\t\t\t\t    \\|_______|\\___/ /        \\|_______|   ___ \n");
                            printf("\t\t\t\t\t\t\t\t\t             \\|___|/                     |\\__\\\n");
                            printf("\t\t\t\t\t\t\t\t\t                                         \\|__| \n");
                            return 0;
                        case 2:
                            goto restart;
                            break;
                        case 3:
                            goto sixthqst;
                            break;
                        case 4:
                            goto fifthqst;
                        default:
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                            system("cls");
                            continue;
                    }
                    break;
                }
            default:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                system("cls");
                continue;
        }
        break;
    }
    system("cls");
    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t***************************************************************\n");
    printf("\t\t\t\t\t\t\t*             Enfin, nous allons vous fournir des             *\n");
    printf("\t\t\t\t\t\t\t*         informations sur quelques villes du Maroc           *\n");
    printf("\t\t\t\t\t\t\t*                et leur population.                          *\n");
    printf("\t\t\t\t\t\t\t***************************************************************\n");
    playSound("C:\\Users\\dell\\Downloads\\enfin.mp3");
    seventhqst :
    system("cls");
    while(1)
    {
        playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t                      ,---.           ,---.\n");
        printf("\t\t\t\t\t\t\t                    / /\"`.\\.--\"\"\"--./,'\"\\ \\\n");
        printf("\t\t\t\t\t\t\t                    \\ \\    _       _    / /\n");
        printf("\t\t\t\t\t\t\t                     `./  / __   __ \\  \\,'\n");
        printf("\t\t\t\t\t\t\t                      /    /_O)_(_O\\    \\\n");
        printf("\t\t\t\t\t\t\t                      |  .-'  ___  `-.  |\n");
        printf("\t\t\t\t\t\t\t                   .--|       \\_/       |--.\n");
        printf("\t\t\t\t\t\t\t                 ,'    \\   \\   |   /   /    `.\n");
        printf("\t\t\t\t\t\t\t                /       `.  `--^--'  ,'       \\\n");
        printf("\t\t\t\t\t\t\t             .-\"\"\"\"\"\"-.    `--.___.--'     .-\"\"\"\"\"\"-.\n");
        printf("\t\t\t\t\t\t\t.-----------/         \\------------------/         \\--------------.\n");
        printf("\t\t\t\t\t\t\t| .---------\\         /----------------- \\         /------------. |\n");
        printf("\t\t\t\t\t\t\t| |          `-`--`--'                    `--'--'-'             | |\n");
        printf("\t\t\t\t\t\t\t| |     Veuillez saisir le numero de la ville pour laquelle     | |\n");
        printf("\t\t\t\t\t\t\t| |            vous souhaitez obtenir des informations.         | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |        1- CASABLANCA                 2-SAFI                 | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |        3- TANGIER                    4- AGADIR              | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |        5- LAAYOUNE                   6-MARRAKECH            | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |        7- RABAT                      8- MENU                | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |                                                             | |\n");
        printf("\t\t\t\t\t\t\t| |_____________________________________________________________| |\n");
        printf("\t\t\t\t\t\t\t|_________________________________________________________________|\n");
        printf("\t\t\t\t\t\t\t                   )__________|__|__________(\n");
        printf("\t\t\t\t\t\t\t                  |            ||            |\n");
        printf("\t\t\t\t\t\t\t                  |____________||____________|\n");
        printf("\t\t\t\t\t\t\t                    ),-----.(      ),-----. (\n");
        printf("\t\t\t\t\t\t\t                  ,'   ==.   \\    /  .==    `.\n");
        printf("\t\t\t\t\t\t\t                 /            )  (            \\\n");
        printf("\t\t\t\t\t\t\t                 `==========='    `==========='\n");
        playSound("C:\\Users\\dell\\Downloads\\ville.mp3");
        printf("\n\t\t\t\t\t\t\t\tVotre choix est : ");
        //getchar();
        scanf("%d", &choix);
        getchar();
        system("cls");
        playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
        switch(choix)
        {
            case 1:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\TOUR VIDEO : |TAPEZ 1|    || INFOS SUR LA VILLE : |TAPEZ 2|");
                printf("\t\t\t\t\t\t\t\t\t\t");
                scanf("%d", &sh);
                getchar();
                playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                switch(sh)
                {
                    case 1:
                        system("C:\\Users\\dell\\Downloads\\casablanca.mp4");
                        break;
                    case 2:
                        displayimage("C:\\Users\\dell\\Downloads\\casa.jpg");
                        break;
                    default:
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                        continue;
                }
                break;
            case 2:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\TOUR VIDEO : |TAPEZ 1|    || INFOS SUR LA VILLE : |TAPEZ 2|");
                printf("\t\t\t\t\t\t\t\t\t\t");
                scanf("%d", &sh);
                getchar();
                playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                switch(sh)
                {
                    case 1:
                        system("C:\\Users\\dell\\Downloads\\safi.mp4");
                        break;
                    case 2:
                        displayimage("C:\\Users\\dell\\Downloads\\safi.jpg");
                        break;
                    default:
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                        continue;
                }
                break;
            case 3:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\TOUR VIDEO : |TAPEZ 1|    || INFOS SUR LA VILLE : |TAPEZ 2|");
                printf("\t\t\t\t\t\t\t\t\t\t");
                scanf("%d", &sh);
                getchar();
                playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                switch(sh)
                {
                    case 1:
                        system("C:\\Users\\dell\\Downloads\\tanger.mp4");
                        break;
                    case 2:
                        displayimage("C:\\Users\\dell\\Downloads\\tanger.jpg");
                        break;
                    default:
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                        continue;
                }
                break;
            case 4:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\TOUR VIDEO : |TAPEZ 1|    || INFOS SUR LA VILLE : |TAPEZ 2|");
                printf("\t\t\t\t\t\t\t\t\t\t");
                scanf("%d", &sh);
                getchar();
                playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                switch(sh)
                {
                    case 1:
                        system("C:\\Users\\dell\\Downloads\\agadir.mp4");
                        break;
                    case 2:
                        displayimage("C:\\Users\\dell\\Downloads\\agadir.jpg");
                        break;
                    default:
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                        continue;
                }
                break;
            case 5:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\TOUR VIDEO : |TAPEZ 1|    || INFOS SUR LA VILLE : |TAPEZ 2|");
                printf("\t\t\t\t\t\t\t\t\t\t");
                scanf("%d", &sh);
                getchar();
                playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                switch(sh)
                {
                    case 1:
                        system("C:\\Users\\dell\\Downloads\\laayoune.mp4");
                        break;
                    case 2:
                        displayimage("C:\\Users\\dell\\Downloads\\laayoune.jpg");
                        break;
                    default:
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                        continue;
                }
                break;
            case 6:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\TOUR VIDEO : |TAPEZ 1|    || INFOS SUR LA VILLE : |TAPEZ 2|");
                printf("\t\t\t\t\t\t\t\t\t\t");
                scanf("%d", &sh);
                getchar();
                playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                switch(sh)
                {
                    case 1:
                        system("C:\\Users\\dell\\Downloads\\marrakech.mp4");
                        break;
                    case 2:
                        displayimage("C:\\Users\\dell\\Downloads\\marrakech.jpg");
                        break;
                    default:
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                        continue;
                }
                break;
            case 7:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\TOUR VIDEO : |TAPEZ 1|    || INFOS SUR LA VILLE : |TAPEZ 2|");
                printf("\t\t\t\t\t\t\t\t\t\t");
                scanf("%d", &sh);
                getchar();
                playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                switch(sh)
                {
                    case 1:
                        system("C:\\Users\\dell\\Downloads\\rabat.mp4");
                        break;
                    case 2:
                        displayimage("C:\\Users\\dell\\Downloads\\rabat.jpg");
                        break;
                    default:
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                        continue;
                }
                break ;
            case 8:
                 while(1)
                {
                    system("cls");
                    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t Quitter : |TAPEZ1|   ||   Recommencer : |TAPEZ2|   ||   Retourner : |TAPEZ3|   || Retourner a la question precedente : |TAPEZ4|\n\n");
                    printf("\t\t\t\t\t\t\t\t\t\t");
                    scanf("%d", &QT);
                    getchar();
                    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                    switch(QT)
                    {
                        case 1:
                            system("cls");
                            playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
                            printf("\n\n\n\n\n\n\n\n\n");
                            printf("\t\t\t\t\t\t\t\t\t________      ___    ___ _______   ___       \n");
                            printf("\t\t\t\t\t\t\t\t\t|\\   __  \\    |\\  \\  /  /|\\  ___ \\ |\\  \\      \n");
                            printf("\t\t\t\t\t\t\t\t\t\\ \\  \\\\ /_   \\ \\  \\/  / | \\   __/|\\ \\  \\     \n");
                            printf("\t\t\t\t\t\t\t\t\t \\ \\   __  \\   \\ \\    / / \\ \\  \\_|/_\\ \\  \\    \n");
                            printf("\t\t\t\t\t\t\t\t\t  \\ \\  \\\\  \\   \\/  /  /   \\ \\  \\_|\\ \\ \\__\\   \n");
                            printf("\t\t\t\t\t\t\t\t\t   \\ \\_______\\__/  / /      \\ \\_______\\|__|   \n");
                            printf("\t\t\t\t\t\t\t\t\t    \\|_______|\\___/ /        \\|_______|   ___ \n");
                            printf("\t\t\t\t\t\t\t\t\t             \\|___|/                     |\\__\\\n");
                            printf("\t\t\t\t\t\t\t\t\t                                         \\|__| \n");
                            return 0;
                        case 2:
                            goto restart;
                            break;
                        case 3:
                            goto seventhqst;
                            break;
                        case 4:
                            goto sixthqst;
                        default:
                            system("cls");
                            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                            system("cls");
                            continue;
                    }
                    break;
                }
            default:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                system("cls");
                continue;
        }
        while(1)
        {
            system("cls");
            playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPour abondonner : |TAPEZ 1| || Explorer une autre ville : |TAPEZ 2|\n");
            printf("\t\t\t\t\t\t\t\t\t\t");
            scanf("%d", &kh);
            getchar();
            switch(kh)
            {
                case 1:
                    goto skip;
                    break;
                case 2:
                    goto seventhqst;
                    break;
                default:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLa valeur que vous avez saisis est incorrecte!\n");
                    system("cls");
                    continue;
            }
        }
       break;
    }
    skip :
    system("cls");
    playSound("C:\\Users\\dell\\Downloads\\pop.mp3");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t   _.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._\n");
    printf("\t\t\t\t\t\t .-'---      - ---     --     ---   -----   - --       ----  ----   -     ---`-.\n");
    printf("\t\t\t\t\t\t )         Nous esperons que ces conseils vous aideront a trouver un(e)      (\n");
    printf("\t\t\t\t\t\t(                                                                             )\n");
    printf("\t\t\t\t\t\t )    partenaire qui partage vos valeurs et votre foi. Que votre chemin soit (\n");
    printf("\t\t\t\t\t\t(                                                                             )\n");
    printf("\t\t\t\t\t\t ) eclaire par la sagesse, la patience et la benediction d Allah. Qu Il vous(\n");
    printf("\t\t\t\t\t\t(                                                                             )\n");
    printf("\t\t\t\t\t\t )        accorde une union remplie de bonheur et de serenite. Ameen.        (\n");
    printf("\t\t\t\t\t\t(                                                                             )\n");
    printf("\t\t\t\t\t\t )                                 \3\3\3                                       (\n");
    printf("\t\t\t\t\t\t(                                                                             )\n");
    printf("\t\t\t\t\t\t )                  Assalamu Alaikum wa Rahmatullahi wa Barakatuh.           (\n");
    printf("\t\t\t\t\t\t(                                                                             )\n");
    printf("\t\t\t\t\t\t(___       _       _       _       _       _       _       _       _       ___)\n");
    printf("\t\t\t\t\t\t    `-._.-' (___ _) (__ _ ) (_   _) (__  _) ( __ _) (__  _) (__ _ ) `-._.-'\n");
    printf("\t\t\t\t\t\t            `-._.-' (  ___) ( _  _) ( _ __) (_  __) (__ __) `-._.-'\n");
    printf("\t\t\t\t\t\t                    `-._.-' (__  _) (__  _) (_ _ _) `-._.-'\n");
    printf("\t\t\t\t\t\t                            `-._.-' (_ ___) `-._.-'\n");
    printf("\t\t\t\t\t\t                                    `-._.-'\n");
    playSound("C:\\Users\\dell\\Downloads\\ending.mp3");
    system("cls");
    playbg3("C:\\Users\\dell\\Downloads\\piano.mp3");

}
