#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP

#include "state.hpp"
#include "gamestate.hpp"
#include <string>

class IntroState : public State{

public:

    IntroState(StateManager* manager);
    virtual ~IntroState();

    void update(sf::Time dt);
    void onStart();
    void onEnd();
    void connect();
    sf::Text& getContinue();

private:

    void draw(sf::RenderTarget& target, sf::RenderStates state) const;
    sf::Sprite* m_title;
    sf::Text* m_sous;
    sf::Text* m_continue;

    Player* m_player1;
    Player* m_player2;
    GameState* m_gameState;

    int m_continue_opacity;

};

#endif // TESTSTATE_HPP

