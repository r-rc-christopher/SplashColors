INCLUDEPATH += $$PWD/include \
               $$PWD/include/tmx \
               $$PWD/include/pugixml

DEPENDPATH +=  $$PWD/include \
               $$PWD/include/tmx \
               $$PWD/include/pugixml

HEADERS += \
    $$PWD/include/pugixml/pugiconfig.hpp \
    $$PWD/include/pugixml/pugixml.hpp \
    $$PWD/include/tmx/DebugShape.h \
    $$PWD/include/tmx/Helpers.h \
    $$PWD/include/tmx/Log.h \
    $$PWD/include/tmx/MapLayer.h \
    $$PWD/include/tmx/MapLoader.h \
    $$PWD/include/tmx/MapObject.h \
    $$PWD/include/tmx/QuadTreeNode.h

SOURCES += \
    $$PWD/src/pugixml/pugixml.cpp \
    $$PWD/src/DebugShape.cpp \
    $$PWD/src/MapLayer.cpp \
    $$PWD/src/MapLoaderPrivate.cpp \
    $$PWD/src/MapLoaderPublic.cpp \
    $$PWD/src/MapObject.cpp \
    $$PWD/src/QuadTreeNode.cpp
