TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    repositoryfactory.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += libgit2

HEADERS += \
    repositoryfactory.h
