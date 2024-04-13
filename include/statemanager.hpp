#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include "state.hpp"
#include "game.hpp"
#include <stack>
#include <iostream>

class Game;
class State;

class StateManager{

private:

    std::stack<State*>* m_states;
    Game* m_game;

public:

    // Default Constructor
    StateManager(Game* game);

    // Destructor
    virtual ~StateManager();

    /* METHODS */

    void popState();
    void pushState(State* state);
    State* topState();

    Game* getGame() const;
};

#endif // STATEMANAGER_HPP

