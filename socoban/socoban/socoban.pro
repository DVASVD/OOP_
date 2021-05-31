QT       += core gui openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x0600000   # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appsettings.cpp \
    drawer.cpp \
    level.cpp \
    main.cpp \
    socoban.cpp

HEADERS += \
    appsettings.hpp \
    drawer.hpp \
    level.hpp \
    socoban.hpp

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
