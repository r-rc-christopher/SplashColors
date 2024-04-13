#include "gamestate.hpp"

GameState::GameState(StateManager* manager, std::string mapName, Player* player1, Player* player2):
    State(manager), m_mapName(mapName), m_player1(player1), m_player2(player2){}

void GameState::update(sf::Time dt){
    m_mapGameState->update(dt);
}

void GameState::onStart()
{
    m_player1->setPosition(150,150);
    m_player2->setPosition(250,250);
    m_mapGameState = new Map(this,m_player1, m_player2);
    m_mapGameState->load(m_mapName);

    connect();
}

void GameState::onEnd()
{

}

void GameState::draw(sf::RenderTarget& target,sf::RenderStates state) const{
    target.draw(*m_mapGameState, state);
}

void GameState::connect()
{
    ActionManager& manager = ActionManager::getInstance();

    manager.system().connect(LEFT_J1, std::bind(&Player::onLeft, m_player1));
    manager.system().connect(RIGHT_J1, std::bind(&Player::onRight, m_player1));
    manager.system().connect(UP_J1, std::bind(&Player::onUp, m_player1));
    manager.system().connect(DOWN_J1, std::bind(&Player::onDown, m_player1));
    manager.system().connect(LEFT_J2, std::bind(&Player::onLeft, m_player2));
    manager.system().connect(RIGHT_J2, std::bind(&Player::onRight, m_player2));
    manager.system().connect(UP_J2, std::bind(&Player::onUp, m_player2));
    manager.system().connect(DOWN_J2, std::bind(&Player::onDown, m_player2));
}
