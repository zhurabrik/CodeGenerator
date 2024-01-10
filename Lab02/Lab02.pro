QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    class_unit.h \
    cpp/class_unit.h \
    cpp/method_unit.h \
    cpp/print_operator_unit.h \
    cs/class_unit.h \
    cs/method_unit.h \
    cs/print_operator_unit.h \
    java/class_unit.h \
    java/method_unit.h \
    java/print_operator_unit.h \
    language_factory.h \
    method_unit.h \
    print_operator_unit.h \
    unit.h
