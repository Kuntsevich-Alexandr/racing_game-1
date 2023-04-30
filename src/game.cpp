#include <iostream>

#include "game.h"
#include "map.h"
#include "define.h"
#include "car.h"

//--------------------------------------------------------------------------
// Constructor
//--------------------------------------------------------------------------
Game::Game()
{
    // Surf_Test = NULL; //тестовая поверхность
    Surf_Display                = NULL;
    Running                     = true;
    SDL_Window *window          = nullptr;
    SDL_Renderer *renderer      = nullptr;
    SDL_Surface *screen_surface = nullptr;
}
//--------------------------------------------------------------------------
// Обработка событий, происходящих во время игры (Нажатие кнопки выход из игры, ...)
//--------------------------------------------------------------------------
void Game::OnEvent(SDL_Event* Event) 
{
    // spdlog::info("OnEvent::{} {}", static_cast<Uint8>(Event->type), SDL_QUIT);

    if(static_cast<Uint8>(Event->type) == SDL_QUIT) //4196274163 243 256
    {
        Running = false;
        spdlog::info("!!! \n");
        SDL_Quit();
    }
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void Game::Render()
{
    // Surface::Draw(Surf_Display, Surf_Test, 0, 0);

    // ------------Картинка машинки-------------------------------------------------------
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // car_t car_;
    // coordinates_t car_coordinates = car_.get_coordinates();
    // SDL_Rect car;
    // // car.x = car_coordinates.get_x();
    // // car.y = car_coordinates.get_y();
    // car.x = 150; //test "car"
    // car.y = 50;
    // car.w = 70;
    // car.h = 40;

    // spdlog::info("{}{}", car.x, car.y);

    // SDL_RenderFillRect(renderer, &car);
    // SDL_RenderPresent(renderer);
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
    //-----------Инициализация SDL------------------------------------------
    if(SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        return false;
    }

    SDL_Window *window          = nullptr;
    SDL_Renderer *renderer      = nullptr;
    SDL_Surface *screen_surface = nullptr;
    //-----------Создание и отображение окна---------------------------------
    if (SDL_CreateWindowAndRenderer(1024, 768, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS, &window, &renderer)) 
    {
        std::cerr << "Failed to create window and renderer: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    SDL_SetWindowTitle(window, "Races");
    //---------Создание поверхности, связанной с окном и раскрашивание окна--
    screen_surface = SDL_GetWindowSurface(window);

    if (!screen_surface) 
    {
        std::cerr << "Screen surface could not be created: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0, 0, 0)); // отвечает за цвет окна
    SDL_UpdateWindowSurface(window);
    //-------------------------------------------------------------------------
    car_t car_;
    car_.init(0, 0, 0, 0, 10, 10, 20);
    coordinates_t car_coordinates = car_.get_coordinates();
    SDL_Rect car;
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    car.x = car_coordinates.get_x();
    car.y = car_coordinates.get_y();
    car.w = 70;
    car.h = 40;

    SDL_RenderFillRect(renderer, &car);
    SDL_RenderPresent(renderer);

    return true;
}
//--------------------------------------------------------------------------
void Game::Loop()
{
    // ------------Карта-------------------------------------------------------
}

