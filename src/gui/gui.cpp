#include "gui/gui.hpp"

Gui::Gui(State* state) : m_state(state),
    m_sprite(new sf::Sprite(ResourcesManager::getInstance().getTxtHolder()[GUI_TXT])),
    m_baseRect(new sf::FloatRect()), m_overRect(new sf::FloatRect()), m_selectedRect(new sf::FloatRect()),
    m_vcenter(false), m_hcenter(false), m_opacity(255)
{}

Gui::~Gui(){
    delete m_sprite;
    delete m_baseRect;
    delete m_overRect;
    delete m_selectedRect;
}

bool Gui::isOver(){

    sf::Vector2i mousePosition = sf::Mouse::getPosition
            (*(m_state->getManager()->getGame()->getWindow()));

    return m_sprite->getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y));
}

int Gui::getOpacity(){
    return m_opacity;
}

void Gui::onClick(std::function<void()> func)
{
    if(isOver())
        func();
}

void Gui::setVCenter(bool center){
    m_vcenter = center;
}

void Gui::setHCenter(bool center){
    m_hcenter = center;
}

void Gui::setOpcacity(int opacity){
    m_opacity = opacity;
}

void Gui::setPosition(float x, float y){
    m_sprite->setPosition(x, y);
}

const sf::Sprite& Gui::getSprite() const{
    return *m_sprite;
}

const sf::FloatRect& Gui::getBaseRect() const{
    return *m_baseRect;
}

const sf::FloatRect& Gui::getOverRect() const{
    return *m_overRect;
}

const sf::FloatRect& Gui::getSelectedRect() const{
    return *m_selectedRect;
}

void Gui::setSprite(sf::Sprite* sprite){
    m_sprite = sprite;
}

void Gui::setBaseRect(sf::FloatRect* rect){
    m_baseRect = rect;
}

void Gui::setOverRect(sf::FloatRect* rect){
    m_overRect = rect;
}

void Gui::setSelectedRect(sf::FloatRect* rect){
    m_selectedRect = rect;
}
