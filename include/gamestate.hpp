#ifndef GAMESTATE
#define GAMESTATE

#include <string>
#include "state.hpp"
#include "map.hpp"
#include "player.h"

class Map;

class GameState : public State
{
    private:

        Map* m_mapGameState;
        std::string m_mapName;
        Player* m_player1;
        Player* m_player2;

        void draw(sf::RenderTarget& target,sf::RenderStates state) const;

    public:

        GameState(StateManager* manager, std::string map, Player* player1, Player* player2);
        ~GameState(){}

        void update(sf::Time dt);
        void onStart();
        void onEnd();
        void connect();
};




#endif // GAMESTATE
