TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

include($$PWD/extlibs/tmxloader/tmxloader.pri)

# list of path to include files
INCLUDEPATH += include \
               $$PWD/extlibs/sfml/include \
               $$PWD/extlibs/thor/include \

# list of dependences
DEPENDPATH += include \
               $$PWD/extlibs/sfml/include \
               $$PWD/extlibs/thor/include \

# list of libraries
LIBS += -L$$PWD/extlibs/sfml/lib \
        -L$$PWD/extlibs/thor/lib \

# configuration of SFML
CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-main -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-graphics-d -lsfml-main-d -lsfml-window-d -lsfml-system-d

# configuration of Thor
CONFIG(release, debug|release): LIBS += -lthor
CONFIG(debug, debug|release): LIBS += -lthor-d


HEADERS += \
    include/game.hpp \
    include/actionmanager.hpp \
    include/state.hpp \
    include/statemanager.hpp \
    include/entity.hpp \
    include/introstate.hpp \
    include/gamestate.h \
    include/player.h \
    include/map.hpp \
    include/gamestate.hpp \
    include/collisionmanager.hpp \
    include/resourcesmanager.h \
    include/gui/gui.hpp

SOURCES += \
    src/main.cpp \
    src/game.cpp \
    src/actionmanager.cpp \
    src/statemanager.cpp \
    src/gamestate.cpp \
    src/entity.cpp \
    src/introstate.cpp \
    src/player.cpp \
    src/map.cpp \
    src/collisionmanager.cpp \
    src/resourcesmanager.cpp \
    src/gui/gui.cpp


