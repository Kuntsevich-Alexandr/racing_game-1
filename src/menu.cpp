#include "Menu.h"
#include <SDL_ttf.h>
Menu::Menu(SDL_Renderer* renderer)
    : m_renderer(renderer), m_currentMenuOption(MenuOption::START_GAME), m_exit(false) {}

Menu::~Menu() {}

void Menu::handleInput(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                // Move up in the menu
                m_currentMenuOption = static_cast<MenuOption>(static_cast<int>(m_currentMenuOption) - 1);
                if (m_currentMenuOption < MenuOption::START_GAME) {
                    m_currentMenuOption = MenuOption::EXIT_GAME;
                }
                break;
            case SDLK_DOWN:
                // Move down in the menu
                m_currentMenuOption = static_cast<MenuOption>(static_cast<int>(m_currentMenuOption) + 1);
                if (m_currentMenuOption > MenuOption::EXIT_GAME) {
                    m_currentMenuOption = MenuOption::START_GAME;
                }
                break;
            case SDLK_RETURN:
                // Select a menu option
                switch (m_currentMenuOption) {
                    case MenuOption::START_GAME:
                        // (initialise the game process in game loop)
                        break;
                    case MenuOption::LEADERBOARD:
                        // (load the leaderboard)
                        break;
                    case MenuOption::EXIT_GAME:
                        m_exit = true;
                        break;
                }
                break;
        }
    }
}

void Menu::renderMenuOption(const char* text, int x, int y, bool isSelected) {
    SDL_Color color;
        if (isSelected) {
            // If it is selected, make it white
            color = {255, 255, 255, 255};
        } else {
            // If it is not selected, make it grey
            color = {128, 128, 128, 255};
        }
}
//menu::render should be in game loop cuz it changes on each key press
void Menu::render() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
    SDL_RenderClear(m_renderer); //clearing renderer before making the menu options 

    renderMenuOption("Start Game", 100, 100, m_currentMenuOption == MenuOption::START_GAME);
    renderMenuOption("Leaderboard", 100, 200, m_currentMenuOption == MenuOption::LEADERBOARD);
    renderMenuOption("Exit Game", 100, 300, m_currentMenuOption == MenuOption::EXIT_GAME);
    // render all 3 buttons (selected is white, rest is grey)
}
// getter for m_exit, should have a function in game loop that closes the game as soon as m_exit is true
bool Menu::shouldExit() const {
    return m_exit;
}