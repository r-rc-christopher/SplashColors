#ifndef MAP_HPP
#define MAP_HPP

#include <tmx/MapLoader.h>
#include <string>
#include <SFML/Graphics.hpp>
#include "gamestate.hpp"
#include "player.h"
#include "collisionmanager.hpp"
#include "resourcesmanager.h"

class GameState;

class Map : public sf::Drawable
{
    private:

        //attrib
        GameState* m_state;
        sf::RenderTexture m_renderTexture;
        tmx::MapLoader* m_tmxMap;
        sf::View m_player1View ;
        sf::View m_player2View ;
        Player* m_player1;
        Player* m_player2;
        std::string map;

        //Methode
        void draw(sf::RenderTarget& target,sf::RenderStates state) const;

    public:

        Map(GameState* state, Player* player1, Player* player2);

        void update(sf::Time dt);
        void load(std::string mapName);
        void viewOnMap(Player* player1, sf::View* view)const;
        virtual ~Map();

};

#endif // MAP


