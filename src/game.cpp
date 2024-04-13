#include "game.hpp"
#include <iostream>
#include "gamestate.hpp"
#include "resourcesmanager.h"

Game::Game() : m_stateManager(new StateManager(this)){

    // Creation of the window
    m_window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(),
            "SplashColor v0.1(Alpha)");

    m_window->setVerticalSyncEnabled(true);
}

Game::~Game(){
    delete m_stateManager;
    delete m_window;
}

void Game::onStart(){

    ResourcesManager::getInstance().loadTextures();
    ResourcesManager::getInstance().loadFonts();

    ActionManager& actionManager = ActionManager::getInstance();
    sf::Clock clock;

    while(m_window->isOpen()){

        actionManager.map().update(*m_window);

        if(actionManager.map().isActive(QUIT))
            this->onQuit();

        actionManager.map().invokeCallbacks(actionManager.system(), m_window);

        m_window->clear(sf::Color::Black);
        m_stateManager->topState()->update(clock.restart());
        m_window->draw(*m_stateManager->topState());
        m_window->display();
    }

}

void Game::onQuit(){
    m_window->close();
}

sf::RenderWindow* Game::getWindow() const{
    return m_window;
}
