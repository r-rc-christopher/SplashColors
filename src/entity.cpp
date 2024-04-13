#include "entity.hpp"
#include <iostream>

Entity::Entity(TypeID typeId) : m_typeid(typeId) ,m_position(new sf::Vector2f()),
    m_velocity(new sf::Vector2f()),m_hitbox(new sf::FloatRect()), m_life(0)
        ,m_hitpoint(0), m_direction(new sf::Vector2f()),
        m_sprite(new sf::Sprite()){}

Entity::~Entity(){
    delete m_position;
    delete m_velocity;
    delete m_hitbox;
    delete m_direction;
    delete m_sprite;
}

TypeID Entity::getTypeID() const {
    return m_typeid;
}

int Entity::getLife() const{
    return m_life;
}

int Entity::getHitpoint() const{
    return m_hitpoint;
}

const sf::Vector2f& Entity::getPosition() const{
    return *m_position;
}

const sf::Vector2f& Entity::getVelocity() const{
    return *m_velocity;
}

const sf::Sprite& Entity::getSprite() const{
    return *m_sprite;
}

const sf::FloatRect& Entity::getHitbox() const{
    return *m_hitbox;
}

void Entity::setState(State* state){
    m_state = state;
}

void Entity::setPosition(float x, float y){
    m_position->x = x;
    m_position->y = y;
}

void Entity::setVelocity(float x, float y){
    m_velocity->x = x;
    m_velocity->y = y;
}

void Entity::setHitBox(float x, float y, float w, float h){
    m_hitbox->left = x;
    m_hitbox->top = y;
    m_hitbox->width = w;
    m_hitbox->height = h;
}

void Entity::ajustSpeed(){

    if(m_velocity->x != 0 && m_velocity->y != 0){
        m_velocity->x /= 1.5;
        m_velocity->y /= 1.5;
    }
}


