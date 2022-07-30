QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    formproducto.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    formproducto.h \
    mainwindow.h

FORMS += \
    formproducto.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-Tarea-4-Desktop_Qt_6_2_4_MinGW_64_bit-Debug/Tienda/release/ -lTienda
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-Tarea-4-Desktop_Qt_6_2_4_MinGW_64_bit-Debug/Tienda/debug/ -lTienda
else:unix: LIBS += -L$$PWD/../../build-Tarea-4-Desktop_Qt_6_2_4_MinGW_64_bit-Debug/Tienda/ -lTienda

INCLUDEPATH += $$PWD/../Tienda
DEPENDPATH += $$PWD/../Tienda

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../build-Tarea-4-Desktop_Qt_6_2_4_MinGW_64_bit-Debug/Tienda/release/libTienda.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../build-Tarea-4-Desktop_Qt_6_2_4_MinGW_64_bit-Debug/Tienda/debug/libTienda.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../build-Tarea-4-Desktop_Qt_6_2_4_MinGW_64_bit-Debug/Tienda/release/Tienda.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../build-Tarea-4-Desktop_Qt_6_2_4_MinGW_64_bit-Debug/Tienda/debug/Tienda.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../build-Tarea-4-Desktop_Qt_6_2_4_MinGW_64_bit-Debug/Tienda/libTienda.a
