#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include <tmx/MapLayer.h>
#include <tmx/MapObject.h>
#include "entity.hpp"

enum LayerID{
    DECOR,
    BORD
};

enum TypeCollision{
    HITBOX,
    BOUDINGBOX,
};

class CollisionManager{

private:

    tmx::MapLayer* m_decorLayer;
    tmx::MapLayer* m_bordLayer;

    CollisionManager();
    CollisionManager(CollisionManager const&) = delete;
    void operator=(CollisionManager const&) = delete;

public:

    static CollisionManager& getInstance(){
        static CollisionManager instance;
        return instance;
    }

    void setDecorLayer(tmx::MapLayer* layer);
    void setBordLayer(tmx::MapLayer* layer);
    bool isInCollision(Entity* entity, TypeCollision type, LayerID layerId);
};

#endif // COLLISIONMANAGER_HPP

