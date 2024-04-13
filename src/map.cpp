#include "map.hpp"

Map::Map(GameState* state, Player *player1, Player *player2):
    m_state(state), m_tmxMap(new tmx::MapLoader(ResourcesManager::MapsPath))
        ,m_player1(player1), m_player2(player2){}

Map::~Map(){
    delete m_tmxMap;
}

void Map::draw(sf::RenderTarget& target,sf::RenderStates state) const
{
    //faire le setCenter sur le joueur1
    sf::View view = target.getView();

    view.setSize(m_tmxMap->GetMapSize().x /2,m_tmxMap->GetMapSize().y);
    view.setViewport(sf::FloatRect(0,0,0.499f,1));


    sf::Vector2f player1Center(m_player1->getPosition().x + 16,
                               m_player1->getPosition().y + 27.5);

    view.setCenter(player1Center);
    viewOnMap(m_player1,&view);

    target.setView(view);

    m_tmxMap->Draw(target,0);
    m_tmxMap->Draw(target,1);
    m_tmxMap->Draw(target,2);
    target.draw(m_player2->getSprite());
    target.draw(m_player1->getSprite());
    m_tmxMap->Draw(target,3);
    m_tmxMap->Draw(target,4);
    //faire le setCenter sur le joueur2
    view.setViewport(sf::FloatRect(0.5f,0,0.499f,1));

    view.setCenter(m_player2->getPosition().x + 16,
                   m_player2->getPosition().y + 27.5);
    viewOnMap(m_player2,&view);
    target.setView(view);

    m_tmxMap->Draw(target,0);
    m_tmxMap->Draw(target,1);
    m_tmxMap->Draw(target,2);
    target.draw(m_player1->getSprite());
    target.draw(m_player2->getSprite());
    m_tmxMap->Draw(target,3);
    m_tmxMap->Draw(target,4);
}

void Map::update(sf::Time dt)
{
    m_player1->update(dt);
    m_player2->update(dt);
}

void Map::load(std::string mapName){
    std::cout << "Chargement ..." << std::endl;
    m_tmxMap->Load(mapName);
    CollisionManager::getInstance().setDecorLayer(&m_tmxMap->GetLayers()[5]);
    CollisionManager::getInstance().setBordLayer(&m_tmxMap->GetLayers()[6]);
    std::cout << "Chargement termine" << std::endl;
}

void Map::viewOnMap(Player* player1, sf::View* view)const
{
    //view coin supérieur gauche
    if(player1->getPosition().x + 16 < (m_tmxMap->GetMapSize().x /4) && player1->getPosition().y < m_tmxMap->GetMapSize().y / 2)
    {
        view->setCenter(m_tmxMap->GetMapSize().x /4,m_tmxMap->GetMapSize().y /2);
    }

    //view coin Inferieur gauche
    if(player1->getPosition().x + 16 < (m_tmxMap->GetMapSize().x /4) && player1->getPosition().y > m_tmxMap->GetMapSize().y / 2)
    {
        view->setCenter(m_tmxMap->GetMapSize().x /4,m_tmxMap->GetMapSize().y /2);
    }

    //view coin supérieur droit
    if(player1->getPosition().x + 16 > ((m_tmxMap->GetMapSize().x /4)*3) && player1->getPosition().y < m_tmxMap->GetMapSize().y / 2)
    {
        view->setCenter((m_tmxMap->GetMapSize().x /4)*3,m_tmxMap->GetMapSize().y /2);
    }

    //view coin Inferieur droit
    if(player1->getPosition().x + 16 > ((m_tmxMap->GetMapSize().x /4)*3) && player1->getPosition().y > m_tmxMap->GetMapSize().y / 2)
    {
        view->setCenter((m_tmxMap->GetMapSize().x /4)*3,m_tmxMap->GetMapSize().y /2);
    }

    //view reste de la carte
    if(player1->getPosition().x + 16 > (m_tmxMap->GetMapSize().x /4)&& player1->getPosition().x + 16 < ((m_tmxMap->GetMapSize().x /4)*3))
    {
        view->setCenter(player1->getPosition().x + 16 ,m_tmxMap->GetMapSize().y /2);
    }

}
