#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "statemanager.hpp"
#include "actionmanager.hpp"

class StateManager;
class ActionManager;

class Game{

    private:

        sf::RenderWindow* m_window;
        StateManager* m_stateManager;

    public:

        Game();
        virtual ~Game();
        void onStart();
        void onQuit();


        sf::RenderWindow* getWindow() const;

};



#endif // GAME_HPP

