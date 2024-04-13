#include "resourcesmanager.h"

std::string ResourcesManager::TexturesPath = "media/textures/";
std::string ResourcesManager::MapsPath = "media/maps";
std::string ResourcesManager::FontsPath = "media/fonts/";

ResourcesManager::ResourcesManager()
    : m_txtHolder(new thor::ResourceHolder<sf::Texture, ResourceID>()),
      m_fontsHolder(new thor::ResourceHolder<sf::Font, ResourceID>()){
}

ResourcesManager::~ResourcesManager(){
    delete m_txtHolder;
    delete m_fontsHolder;
}

thor::ResourceHolder<sf::Texture, ResourceID>& ResourcesManager::getTxtHolder() const{
    return *m_txtHolder;
}

thor::ResourceHolder<sf::Font, ResourceID>& ResourcesManager::getFontsHolder() const{
    return *m_fontsHolder;
}

bool ResourcesManager::loadTextures(){

    try{
        m_txtHolder->acquire(DIMITR_TXT,
            thor::Resources::fromFile<sf::Texture>(TexturesPath + "dim.png"));

        m_txtHolder->acquire(MARINA_TXT,
            thor::Resources::fromFile<sf::Texture>(TexturesPath +"marina.png"));

        m_txtHolder->acquire(CHRIST_TXT,
            thor::Resources::fromFile<sf::Texture>(TexturesPath +"christopher.png"));

        m_txtHolder->acquire(JEFFER_TXT,
            thor::Resources::fromFile<sf::Texture>(TexturesPath +"jefferson.png"));

        m_txtHolder->acquire(GUI_TXT,
            thor::Resources::fromFile<sf::Texture>(TexturesPath +"gui.png"));

        m_txtHolder->acquire(MAIN_TITLE_TXT,
            thor::Resources::fromFile<sf::Texture>(TexturesPath +"main_title.png"));

        return true;
    }
    catch(thor::ResourceLoadingException& e){
        return false;
    }
}

bool ResourcesManager::loadFonts(){
    try{
        m_fontsHolder->acquire(GAME_FONT,
            thor::Resources::fromFile<sf::Font>(FontsPath +"font.ttf"));
    }
    catch(thor::ResourceLoadingException& e){
        return false;
    }
}
