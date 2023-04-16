#include <iostream>

#include "game.h"
#include "define.h"
//--------------------------------------------------------------------------
Game::Game()
{
    Surf_Test = NULL; //тестовая поверхность
    Surf_Display = NULL;
    Running = true;
}
//--------------------------------------------------------------------------
void Game::OnEvent(SDL_Event* Event) 
{
    if(Event->type == SDL_QUIT) 
    {
        Running = false;
    }
}
//--------------------------------------------------------------------------
void Game::Loop()
{

}
//--------------------------------------------------------------------------
void Game::Render()
{
    Surface::Draw(Surf_Display, Surf_Test, 0, 0);
 
    // SDL_RendererFlip(Surf_Display); // ??????? мб не верно сделала, т к изменился стандарт библиотеки
}
//--------------------------------------------------------------------------
void Game::Cleanup()
{
    SDL_FreeSurface(Surf_Test);
    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}
//--------------------------------------------------------------------------
int Game::Execute()
{
    if(Init() == false) 
    {
        return INIT_ERROR;
    }
 
    SDL_Event Event;
 
    while(Running) 
    {
        while(SDL_PollEvent(&Event)) //проверяем события и передаем их по одному в OnEvent
        {
            OnEvent(&Event);
        }
 
        Loop();
        Render();
    }
 
    Cleanup();
 
    exit(EXIT_SUCCESS);
}
//--------------------------------------------------------------------------
bool Game::Init()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        return false;
    }

    SDL_Window *window          = nullptr;
    SDL_Renderer *renderer      = nullptr;
    SDL_Surface *screen_surface = nullptr;

    if (SDL_CreateWindowAndRenderer(1024, 768, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &window, &renderer)) 
    {
        std::cerr << "Failed to create window and renderer: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    SDL_SetWindowTitle(window, "Races");
    SDL_SetRenderDrawColor(renderer, 210, 255, 179, 255);

    screen_surface = SDL_GetWindowSurface(window);

    if (!screen_surface) 
    {
        std::cerr << "Screen surface could not be created: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // if((Surf_Test = Surface::OnLoad("roadmarkings-14.jpg", window)) == NULL) //тестовая загрузка поверхности
    // {
    //     return false;
    // }
    return true;
}

