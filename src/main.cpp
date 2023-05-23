#include <iostream>

#include "game.h"
#include "car.h"
extern "C"
//--------------------------------------------------------------------------
int main(int argc, char* argv[]) 
{
    Game Races;
    SDL_SetMainReady();

    return Races.Execute();
}
//--------------------------------------------------------------------------