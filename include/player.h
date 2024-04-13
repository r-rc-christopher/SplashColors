#ifndef PLAYER
#define PLAYER

#include "entity.hpp"
#include <string>
#include <Thor/Animations.hpp>
#include <iostream>
#include "collisionmanager.hpp"
#include "resourcesmanager.h"

class Player : public Entity{

    private:

        std::string m_pseudo;
        thor::Animator<sf::Sprite, Dir> animator;

    public:

        Player(std::string pseudo, ResourceID txtId);
        virtual ~Player();

        void update(sf::Time dt);
        void generateAnimation();
        void onKeyPress();
        void setPosition(float x, float y);

        void onLeft();
        void onRight();
        void onUp();
        void onDown();
};





#endif // PLAYER



