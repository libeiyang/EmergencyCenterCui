QT -= gui

TEMPLATE = lib
DEFINES += MP20-TEAM-C6_LIBRARY
CONFIG += c++14 console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ActExtinction.cpp \
        Alarm.cpp \
        CoSensor.cpp \
        ControlCenter.cpp \
        GasSensor.cpp \
        Location.cpp \
        MotionSensor.cpp \
        SendEmail.cpp \
        SendMessage.cpp \
        Sensor.cpp \
        SmokeSensor.cpp \
        TurnOn.cpp \
        Warn.cpp \
        Sprinkle.cpp

HEADERS += \
    Actextinction.h \
    Action.h \
    Alarm.h \
    CoSensor.h \
    Component.h \
    ControlCenter.h \
    GasSensor.h \
    Location.h \
    MotionSensor.h \
    SendEmail.h \
    SendMessage.h \
    Sensor.h \
    SensorType.h \
    SmokeSensor.h \
    TurnOn.h \
    Warn.h \
    Sprinkle.h
    
# Default rules for deployment.
unix {
    target.path = /home/francisliu/Desktop/gitlab/mp20-team-c6
}
!isEmpty(target.path): INSTALLS += target

