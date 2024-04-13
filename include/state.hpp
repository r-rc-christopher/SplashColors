#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>
#include "statemanager.hpp"
#include "resourcesmanager.h"
#include "gui/gui.hpp"

class StateManager;
class Gui;

class State : public sf::Drawable {

    public:

        // Default Constructor
        State(StateManager* manager) :
            m_manager(manager){}

        // Destructor
        virtual ~State(){}

        virtual void update(sf::Time dt) =0;
        virtual void onStart() = 0;
        virtual void onEnd() =0;
        virtual void connect() =0;

        inline StateManager* getManager() const {
            return m_manager;
        }

    protected:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const = 0;

        StateManager* m_manager;

};

#endif // STATE_HPP

