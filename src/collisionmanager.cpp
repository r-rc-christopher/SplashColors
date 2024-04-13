#include "collisionmanager.hpp"
#include "player.h"
CollisionManager::CollisionManager(){
}

void CollisionManager::setDecorLayer(tmx::MapLayer *layer){
    m_decorLayer = layer;
}

void CollisionManager::setBordLayer(tmx::MapLayer* layer){
    m_bordLayer = layer;
}

bool CollisionManager::isInCollision(Entity* entity, TypeCollision type, LayerID layerId){

    if(m_decorLayer == nullptr || m_bordLayer == nullptr)
        return false;

    sf::FloatRect* box = new sf::FloatRect();

    // Type de collison
    switch(type){

        case HITBOX:
            delete box;
            box = new sf::FloatRect(entity->getHitbox());
        break;

        default:
            delete box;
            box = new sf::FloatRect(entity->getSprite().getGlobalBounds());
    }

    // Choix du layer
    tmx::MapLayer* layer;
    switch(layerId){
        case DECOR: layer = m_decorLayer;
        break;

        default:
            layer = m_bordLayer;
    }

    tmx::MapObject mo;
    // Positionnement de la boite de collision
    mo.SetPosition(
        box->left + entity->getVelocity().x * (entity->getSprite().getGlobalBounds().width / 2.),
        box->top + entity->getVelocity().y * (entity->getSprite().getGlobalBounds().height / 2.));

    mo.AddPoint(sf::Vector2f());
    mo.AddPoint(sf::Vector2f(box->width, 0.f));
    mo.AddPoint(sf::Vector2f(box->width, box->height));
    mo.AddPoint(sf::Vector2f(0.f, box->height));
    mo.CreateDebugShape(sf::Color::Magenta);


    for(auto object = layer->objects.begin(); object!=layer->objects.end(); object++){
        if(object->Intersects(mo)){
            return 1;
        }
    }

    return false;
}
