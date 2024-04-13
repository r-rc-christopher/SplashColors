#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include "state.hpp"


class State;

class Gui : public sf::Drawable {

private:

    State* m_state;
    sf::Sprite* m_sprite;
    sf::FloatRect* m_baseRect;
    sf::FloatRect* m_overRect;
    sf::FloatRect* m_selectedRect;
    bool m_vcenter;
    bool m_hcenter;
    int m_opacity;
    void draw(sf::RenderTarget& target, sf::RenderStates state) const = 0;

public:

    Gui(State* state);
    virtual ~Gui();

    void onClick(std::function<void()> func);
    bool isOver();
    int getOpacity();

    const sf::Sprite& getSprite() const;
    const sf::FloatRect& getBaseRect() const;
    const sf::FloatRect& getOverRect() const;
    const sf::FloatRect& getSelectedRect() const;

    void setSprite(sf::Sprite* sprite);
    void setBaseRect(sf::FloatRect* rect);
    void setOverRect(sf::FloatRect* rect);
    void setSelectedRect(sf::FloatRect* rect);

    void setVCenter(bool center);
    void setHCenter(bool center);
    void setOpcacity(int opacity);
    void setPosition(float x, float y);

    virtual void addGui(Gui* gui) = 0;
    void update(sf::Time dt);
};

#endif
