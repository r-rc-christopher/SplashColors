#ifndef RESOURCESMANAGER
#define RESOURCESMANAGER
#define SPRITESHEETS_PATH "media/spritesheets/"

#include <Thor/Resources.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

enum ResourceID{
    MARINA_TXT,
    CHRIST_TXT,
    DIMITR_TXT,
    JEFFER_TXT,
    GUI_TXT,
    MAIN_TITLE_TXT,
    GAME_FONT,
};

class ResourcesManager{

private:

    thor::ResourceHolder<sf::Texture, ResourceID>* m_txtHolder;
    thor::ResourceHolder<sf::Font, ResourceID>* m_fontsHolder;

    ResourcesManager();
    ResourcesManager(ResourcesManager const&) = delete;
    virtual ~ResourcesManager();

    void operator=(ResourcesManager const&) = delete;

public:

    static ResourcesManager& getInstance(){
        // Guaranteed to be destroyed
        // Instantiated on first use
        static ResourcesManager instance;
        return instance;
    }

    thor::ResourceHolder<sf::Texture, ResourceID>& getTxtHolder() const;
    thor::ResourceHolder<sf::Font, ResourceID>& getFontsHolder() const;

    bool loadTextures();
    bool loadFonts();

    // Editable paths
    static std::string TexturesPath;
    static std::string MapsPath;
    static std::string FontsPath;

};

#endif // RESOURCESMANAGER

