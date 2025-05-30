QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bell.cpp \
    button.cpp \
    closebutton.cpp \
    destinationpanel.cpp \
    display.cpp \
    door.cpp \
    doorobstaclesensor.cpp \
    elevator.cpp \
    elevatorcontroller.cpp \
    elevatorstate.cpp \
    emergencystate.cpp \
    event.cpp \
    firebutton.cpp \
    floor.cpp \
    freezestate.cpp \
    helpbutton.cpp \
    holdingstate.cpp \
    idlestate.cpp \
    main.cpp \
    mainwindow.cpp \
    movingstate.cpp \
    openbutton.cpp \
    passenger.cpp \
    passengeraction.cpp \
    pausestate.cpp \
    runningstate.cpp \
    safetyevent.cpp \
    sensor.cpp \
    setupstate.cpp \
    simulationcontroller.cpp \
    simulationstate.cpp \
    speaker.cpp \
    stopstate.cpp \
    weightsensor.cpp

HEADERS += \
    bell.h \
    button.h \
    closebutton.h \
    destinationpanel.h \
    display.h \
    door.h \
    doorobstaclesensor.h \
    elevator.h \
    elevatorcontroller.h \
    elevatorstate.h \
    emergencystate.h \
    event.h \
    firebutton.h \
    floor.h \
    freezestate.h \
    helpbutton.h \
    holdingstate.h \
    idlestate.h \
    mainwindow.h \
    movingstate.h \
    openbutton.h \
    passenger.h \
    passengeraction.h \
    pausestate.h \
    runningstate.h \
    safetyevent.h \
    sensor.h \
    setupstate.h \
    simulationcontroller.h \
    simulationstate.h \
    speaker.h \
    stopstate.h \
    weightsensor.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
