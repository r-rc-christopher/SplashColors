#include "introstate.hpp"
#include "windows.h"

IntroState::IntroState(StateManager* manager): State(manager), m_continue_opacity(0),
    m_player1(nullptr), m_player2(nullptr), m_gameState(nullptr){

    // Récupération de la texture du titre
    m_title = new sf::Sprite(ResourcesManager::getInstance().getTxtHolder()[MAIN_TITLE_TXT]);
    m_title->setScale(0.6f, 0.6f);
    m_title->setPosition(
        m_manager->getGame()->getWindow()->getSize().x / 2. - m_title->getGlobalBounds().width / 2.,
        m_manager->getGame()->getWindow()->getSize().y / 2. - m_title->getGlobalBounds().height / 2.);


    std::wstring str =
        std::wstring(L"Réalisé par \nRichard Christopher\nWaillez Jefferson\nTworowski Dimitri\nFeincoeur Marina\n") +
        std::wstring(L"étudiant de la HELHa Campus Mons dans le cadre du cours de M. Altares");

    m_sous = new sf::Text(str
       ,ResourcesManager::getInstance().getFontsHolder()[GAME_FONT], 18);

    m_sous->setColor(sf::Color::White);
    m_sous->setPosition(m_title->getPosition().x, m_title->getPosition().y + m_title->getGlobalBounds().height);

    m_continue = new sf::Text("Appuyez sur ESC pour continuer"
       ,ResourcesManager::getInstance().getFontsHolder()[GAME_FONT], 18);

    m_continue->setPosition(
        m_manager->getGame()->getWindow()->getSize().x / 2. - m_continue->getGlobalBounds().width / 2.,
        m_title->getPosition().y + m_title->getGlobalBounds().height
    );

    m_continue->setColor(sf::Color(255,255,255,0));
}

IntroState::~IntroState(){
    delete m_title;
    delete m_sous;
    delete m_continue;
}

void IntroState::update(sf::Time dt){
    m_continue_opacity += 0.2 * dt.asMilliseconds();
    m_continue->setColor(sf::Color(255,225,255,m_continue_opacity));
}

void IntroState::onStart(){
    connect();
}

void IntroState::onEnd(){

    if(m_gameState == nullptr)
    {
        m_player1 = new Player("Christopher", CHRIST_TXT);
        m_player2 = new Player("Jefferson", JEFFER_TXT);
        m_gameState = new GameState(m_manager, "map_ludi.tmx", m_player1, m_player2);
        m_manager->pushState(m_gameState);
    }
}

void IntroState::connect(){
    ActionManager::getInstance().system().connect(ESC, std::bind(&IntroState::onEnd, this));
}

void IntroState::draw(sf::RenderTarget& target, sf::RenderStates state) const
{   
    target.clear(sf::Color(58,58,60));
    target.draw(*m_title);
    target.draw(*m_sous);
    target.draw(*m_continue);
}

sf::Text& IntroState::getContinue(){
    return *m_continue;
}
