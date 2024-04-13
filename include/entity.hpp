#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

enum TypeID
{
    PLAYER_ID,
    PAINTBALL_ID,
};
enum Dir
{
    Up,
    Donw,
    Right,
    Left

};

class State;

class Entity {

protected:

    TypeID m_typeid;
    State* m_state;
    sf::Vector2f* m_position;
    sf::Vector2f* m_velocity;
    sf::Vector2f* m_direction;
    sf::FloatRect* m_hitbox;
    sf::Sprite* m_sprite;
    int m_life;
    int m_hitpoint;
    Dir dirAnim;


public:

    Entity(TypeID typeId);
    virtual ~Entity();

    int getLife() const;
    int getHitpoint() const;
    TypeID getTypeID() const;

    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getVelocity() const;
    const sf::FloatRect& getHitbox() const;
    const sf::Sprite& getSprite() const;

    void setState(State* state);
    void setPosition(float x, float y);
    void setVelocity(float x, float y);
    void setHitBox(float x, float y, float w, float h);
    void ajustSpeed();
    virtual void generateAnimation() = 0;
    virtual void update(sf::Time dt) = 0;
};

#endif // ENTITY_HPP

