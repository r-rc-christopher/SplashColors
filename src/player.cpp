#include "player.h"

using namespace std;

Player::Player(string pseudo, ResourceID txtId ) : Entity(PLAYER_ID), m_pseudo(pseudo){

    m_sprite = new sf::Sprite(ResourcesManager::getInstance().getTxtHolder()[txtId]);
    m_sprite->setTextureRect(sf::IntRect(32,110,32,55));

    delete m_hitbox;
    m_hitbox = new sf::FloatRect(0,53,32,2);
    generateAnimation();
}

Player::~Player(){
}

void Player::update(sf::Time dt){

    animator.update(dt);
    animator.animate(*m_sprite);

    std::cout << "x: " << m_velocity->x << " y: " << m_velocity->y << std::endl;

    if(m_velocity->x == 0 && m_velocity->y == 0)
        return;

        if (!animator.isPlayingAnimation()) {
            do {
                animator.playAnimation(dirAnim);
            } while (!(animator.getPlayingAnimation() == dirAnim));
        }

        if(dirAnim != animator.getPlayingAnimation())
            animator.stopAnimation();

    this->setPosition(
        m_position->x + m_velocity->x * dt.asMilliseconds(),
        m_position->y + m_velocity->y * dt.asMilliseconds()
    );

    m_velocity->x = 0;
    m_velocity->y = 0;
}

void Player::setPosition(float x, float y){
    m_hitbox->left = x;
    m_hitbox->top = y + 53;
    Entity::setPosition(x, y);
    m_sprite->setPosition(*m_position);
}

void Player::generateAnimation()
{
    // Haut
    sf::IntRect rect1(0, 0, 32, 55);
    sf::IntRect rect2(32, 0, 32, 55);
    sf::IntRect rect3(64, 0, 32, 55);

    // Droit
    sf::IntRect rect4(0, 55, 32, 55);
    sf::IntRect rect5(32, 55, 32, 55);
    sf::IntRect rect6(64, 55, 32, 55);

    // Bas
    sf::IntRect rect7(0, 110, 32, 55);
    sf::IntRect rect8(32, 110, 32, 55);
    sf::IntRect rect9(64, 110, 32, 55);

    // Gauche
    sf::IntRect rect10(0, 165, 32, 55);
    sf::IntRect rect11(32, 165, 32, 55);
    sf::IntRect rect12(64, 165, 32, 55);

    thor::FrameAnimation walkUp;
    walkUp.addFrame(1.f, rect2);
    walkUp.addFrame(1.f, rect3);
    walkUp.addFrame(1.f, rect1);
    // Gauche
    thor::FrameAnimation walkRight;
    walkRight.addFrame(1.f, rect5);
    walkRight.addFrame(1.f, rect6);
    walkRight.addFrame(1.f, rect4);

    // Droite
    thor::FrameAnimation walkDown;
    walkDown.addFrame(1.f, rect8);
    walkDown.addFrame(1.f, rect9);
    walkDown.addFrame(1.f, rect7);

    // Haut
    thor::FrameAnimation walkLeft;
    walkLeft.addFrame(1.f, rect11);
    walkLeft.addFrame(1.f, rect12);
    walkLeft.addFrame(1.f, rect10);

	animator.addAnimation(Up, walkUp, sf::seconds(0.4f));
	animator.addAnimation(Right, walkRight, sf::seconds(0.4f));
	animator.addAnimation(Donw, walkDown, sf::seconds(0.4f));
	animator.addAnimation(Left, walkLeft, sf::seconds(0.4f));


    m_sprite->setTextureRect(rect8);
}

void Player::onLeft(){

    m_velocity->x = -0.2;

    // Ajuste la vitesse quand on marche
    // en diagonal
    ajustSpeed();
    if(CollisionManager::getInstance().isInCollision(this, HITBOX, DECOR)
            || CollisionManager::getInstance().isInCollision(this, BOUDINGBOX, BORD)){
        m_velocity->x = 0;
    }

    dirAnim = Left;

}

void Player::onRight(){

    m_velocity->x = 0.2;
    ajustSpeed();
    if(CollisionManager::getInstance().isInCollision(this, HITBOX, DECOR)
            || CollisionManager::getInstance().isInCollision(this, BOUDINGBOX, BORD)){
        m_velocity->x = 0;
    }
    dirAnim = Right;
}

void Player::onUp(){

    m_velocity->y = -0.2;
    ajustSpeed();
    if(CollisionManager::getInstance().isInCollision(this, HITBOX, DECOR)
            || CollisionManager::getInstance().isInCollision(this, BOUDINGBOX, BORD)){
        m_velocity->y = 0;
    }
    dirAnim = Up;
}

void Player::onDown()
{
    m_velocity->y = 0.2;
    ajustSpeed();
    if(CollisionManager::getInstance().isInCollision(this, HITBOX, DECOR)
            || CollisionManager::getInstance().isInCollision(this, BOUDINGBOX, BORD)){
        m_velocity->y = 0;
    }
    dirAnim = Donw;
}
