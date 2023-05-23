#include "Menu.h"
//#include <SDL_ttf.h>
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
                        // (initialise the game process)
                        break;
                    case MenuOption::LEADERBOARD:
                        // (show the leaderboard)
                        break;
                    case MenuOption::EXIT_GAME:
                        m_exit = true;
                        break;
                }
                break;
        }
    }
}

void Menu::render() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
    SDL_RenderClear(m_renderer);
}

/*bool Menu::shouldExit() const {
    return m_exit
}*/