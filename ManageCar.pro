QT += core gui multimedia multimediawidgets
QT += widgets
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
charge.cpp \
chargedetail.cpp \
chargedia.cpp \
countdia.cpp \
datetimedialog.cpp \
main.cpp \
mainwindow.cpp \
qhmaskwidget.cpp



HEADERS += \
    charge.h \
    chargedetail.h \
    chargedia.h \
    connectionData.h \
    countdia.h \
    datetimedialog.h \
    mainwindow.h \
    qhmaskwidget.h

FORMS += \
    charge.ui \
    chargedetail.ui \
    chargedia.ui \
    countdia.ui \
    mainwindow.ui \
    qhmaskwidget.ui

TRANSLATIONS += \
    ManageCar_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations
CONFIG += link_pkgconfig
PKGCONFIG += opencv4

INCLUDEPATH += /usr/local/ssl/include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    test1.py

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../usr/lib/python3.10/config-3.10-x86_64-linux-gnu/release/ -lpython3.10
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../usr/lib/python3.10/config-3.10-x86_64-linux-gnu/debug/ -lpython3.10
else:unix: LIBS += -L$$PWD/../../../usr/lib/python3.10/config-3.10-x86_64-linux-gnu/ -lpython3.10

INCLUDEPATH += $$PWD/../../../usr/include/python3.10
DEPENDPATH += $$PWD/../../../usr/include/python3.10

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/lib/python3.10/config-3.10-x86_64-linux-gnu/release/libpython3.10.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/lib/python3.10/config-3.10-x86_64-linux-gnu/debug/libpython3.10.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/lib/python3.10/config-3.10-x86_64-linux-gnu/release/python3.10.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../usr/lib/python3.10/config-3.10-x86_64-linux-gnu/debug/python3.10.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../usr/lib/python3.10/config-3.10-x86_64-linux-gnu/libpython3.10.a
