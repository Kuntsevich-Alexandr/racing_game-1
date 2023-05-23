#include <iostream>

#include "game.h"
#include "car.h"
extern "C"
#define SDL_MAIN_HANDLED
//--------------------------------------------------------------------------
int main(int argc, char* argv[]) 
{
    Game Races;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_SetMainReady();

    return Races.Execute();
}
//--------------------------------------------------------------------------