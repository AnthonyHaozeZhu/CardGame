QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    card.cpp \
    photopass.cpp

HEADERS += \
    card.h \
    photopass.h

FORMS += \
    card.ui \
    photopass.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    myimage.qrc

DISTFILES += \
    ../测试实况足球所用文件夹/1.jpg \
    ../测试实况足球所用文件夹/10.jpg \
    ../测试实况足球所用文件夹/11.jpg \
    ../测试实况足球所用文件夹/12.jpg \
    ../测试实况足球所用文件夹/13.jpg \
    ../测试实况足球所用文件夹/14.jpg \
    ../测试实况足球所用文件夹/15.jpg \
    ../测试实况足球所用文件夹/16.jpg \
    ../测试实况足球所用文件夹/17.jpg \
    ../测试实况足球所用文件夹/18.jpg \
    ../测试实况足球所用文件夹/19.jpg \
    ../测试实况足球所用文件夹/2.jpg \
    ../测试实况足球所用文件夹/20.jpg \
    ../测试实况足球所用文件夹/21.jpg \
    ../测试实况足球所用文件夹/22.jpg \
    ../测试实况足球所用文件夹/23.jpg \
    ../测试实况足球所用文件夹/24.jpg \
    ../测试实况足球所用文件夹/3.jpg \
    ../测试实况足球所用文件夹/4.jpg \
    ../测试实况足球所用文件夹/5.jpg \
    ../测试实况足球所用文件夹/6.jpg \
    ../测试实况足球所用文件夹/7.jpg \
    ../测试实况足球所用文件夹/8.jpg \
    ../测试实况足球所用文件夹/9.jpg
