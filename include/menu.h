#include <SDL.h>

enum class MenuOption {
    START_GAME,
    LEADERBOARD,
    EXIT_GAME
}; //possible menu options but enum class cuz apparently its better than normal enum

class Menu {
public:
    Menu(SDL_Renderer* renderer);
    ~Menu();
    void handleInput(SDL_Event event);
    void render(); // method to conviniently render all options
    void renderMenuOption(const char* text, int x, int y, bool isSelected); /*render a specific option based on
    wether it is selected*/
    bool shouldExit() const; // getter for m_exit

private:
    SDL_Renderer* m_renderer;
    MenuOption m_currentMenuOption; //currently selected menu option 
    bool m_exit;

    //void renderMenuOption(const char* text, int x, int y, bool isSelected);
};