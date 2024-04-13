#include "statemanager.hpp"
#include "introstate.hpp"

using namespace std;

StateManager::StateManager(Game* game) : m_states(new stack<State*>()), m_game(game){
}

// Destructor
StateManager::~StateManager(){
    delete m_states;
}

/* METHODS */

void StateManager::popState(){
    // cleanup the current state
    if(m_states->size() > 1){
        // Signal the state that
        this->topState()->onEnd();
        m_states->pop();
    }
}

void StateManager::pushState(State* state){

    // pause current state
    m_states->push(state);

    // Signal the state that it's the current state
    state->onStart();
}

State* StateManager::topState(){

    if(m_states->empty())
        this->pushState(new IntroState(this));

    return m_states->top();
}

Game* StateManager::getGame() const{
    return m_game;
}
