QT       += core gui widgets

TARGET = cube
TEMPLATE = app

SOURCES += main.cpp \
    geometryengine.cpp

SOURCES += \
    mainwidget.cpp \


HEADERS += \
    geometryengine.h \
    mainwidget.h \


RESOURCES += \
    shaders.qrc \
    shaders.qrc \
    textures.qrc \
    textures.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/cube
INSTALLS += target

DISTFILES += \
    fshader.glsl \
    vshader.glsl
