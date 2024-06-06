QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/fibonachi.cpp \
    src/main.cpp \
    src/tools/Drawtool.cpp \
    src/tools/Ellipsetool.cpp \
    src/tools/Linetool.cpp \
    src/tools/RectTool.cpp \
    src/workspace.cpp \

HEADERS += \
    src/fibonachi.h \
    src/tools/Drawtool.h \
    src/tools/Ellipsetool.h \
    src/tools/Linetool.h \
    src/tools/RectTool.h \
   src/workspace.h \

FORMS += \
    workspace.ui \

INCLUDEPATH += \
    src\
    src/tools

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
