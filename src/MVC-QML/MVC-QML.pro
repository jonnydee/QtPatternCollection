QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7

QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++ -mmacosx-version-min=10.7

CONFIG += c++11

TEMPLATE = app

QT += quick qml

SOURCES += main.cpp \
    Controller.cpp \
    Model.cpp \
    View.cpp

HEADERS += \
    Controller.hpp \
    Model.hpp \
    View.hpp \
    IController.hpp \
    IView.hpp

RESOURCES += \
    Resources.qrc
