#ifndef ACTIONMANAGER_HPP
#define ACTIONMANAGER_HPP

#include <Thor/Input.hpp>

enum Input
{
    UP_J1,
    LEFT_J1,
    DOWN_J1,
    RIGHT_J1,
    SHOOT_J1,
    UP_J2,
    LEFT_J2,
    DOWN_J2,
    RIGHT_J2,
    SHOOT_J2,
    CLICK_LEFT,
    CLICK_RIGHT,
    ESC,
    QUIT,
};

class ActionManager{

private:

    // For Singleton
    ActionManager();
    virtual ~ActionManager();
    ActionManager(ActionManager const&) = delete;
    void operator=(ActionManager const&) = delete;

    // Attributes
    thor::ActionMap<Input>* m_actionMap;
    thor::ActionMap<Input>::CallbackSystem* m_callbackSystem;


public:

    static ActionManager& getInstance(){
        // Guaranteed to be destroyed
        // Instantiated on first use
        static ActionManager instance;
        return instance;
    }

    thor::ActionMap<Input>& map();
    thor::ActionMap<Input>::CallbackSystem& system();

};

#endif // ACTIONMANAGER_HPP

