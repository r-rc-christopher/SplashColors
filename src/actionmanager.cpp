#include "actionmanager.hpp"

ActionManager::ActionManager() : m_actionMap(new thor::ActionMap<Input>()),
    m_callbackSystem(new thor::ActionMap<Input>::CallbackSystem()){

    // Configuration of player 1's inputs
    (*m_actionMap)[UP_J1] = thor::Action(sf::Keyboard::Z, thor::Action::Hold);
    (*m_actionMap)[DOWN_J1] = thor::Action(sf::Keyboard::S, thor::Action::Hold);
    (*m_actionMap)[LEFT_J1] = thor::Action(sf::Keyboard::Q, thor::Action::Hold);
    (*m_actionMap)[RIGHT_J1] = thor::Action(sf::Keyboard::D, thor::Action::Hold);
    (*m_actionMap)[SHOOT_J1] = thor::Action(sf::Keyboard::Space, thor::Action::PressOnce);

    // Configuration of player 2's inputs
    (*m_actionMap)[UP_J2] = thor::Action(sf::Keyboard::Up, thor::Action::Hold);
    (*m_actionMap)[DOWN_J2] = thor::Action(sf::Keyboard::Down, thor::Action::Hold);
    (*m_actionMap)[LEFT_J2] = thor::Action(sf::Keyboard::Left, thor::Action::Hold);
    (*m_actionMap)[RIGHT_J2] = thor::Action(sf::Keyboard::Right, thor::Action::Hold);
    (*m_actionMap)[SHOOT_J2] = thor::Action(sf::Keyboard::Return, thor::Action::PressOnce);

    // Configuration of mouse click and other
    (*m_actionMap)[CLICK_LEFT] = thor::Action(sf::Mouse::Left, thor::Action::PressOnce);
    (*m_actionMap)[CLICK_RIGHT] = thor::Action(sf::Mouse::Right, thor::Action::PressOnce);
    (*m_actionMap)[ESC] = thor::Action(sf::Keyboard::Escape, thor::Action::PressOnce);
    (*m_actionMap)[QUIT] = thor::Action(sf::Event::Closed);
}

ActionManager::~ActionManager(){
    delete m_callbackSystem;
    delete m_actionMap;
}

thor::ActionMap<Input>& ActionManager::map(){
    return *m_actionMap;
}

thor::ActionMap<Input>::CallbackSystem& ActionManager::system(){
    return *m_callbackSystem;
}
