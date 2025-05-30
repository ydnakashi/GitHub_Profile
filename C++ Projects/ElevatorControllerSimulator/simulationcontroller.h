#ifndef SIMULATIONCONTROLLER_H
#define SIMULATIONCONTROLLER_H

#include <QObject>
#include <QVector>
#include <QTimer>
#include <QTime>
#include <QThread>
#include <iostream>
#include <algorithm>
#include "simulationstate.h"
#include "setupstate.h"
#include "runningstate.h"
#include "pausestate.h"
#include "stopstate.h"
#include "elevatorcontroller.h"
#include "passenger.h"
#include "safetyevent.h"
#include "passengeraction.h"
#include "floorbutton.h"

#define TIME_DELAY 2000

class SimulationController : public QObject
{
    Q_OBJECT
    friend class SetupState;
    friend class RunningState;
    friend class PauseState;
    friend class StopState;
public:
    explicit SimulationController(ElevatorController* eleControl, QObject *parent = nullptr);
    ~SimulationController();
    void setState(SimulationState*);

    // Getters
    const QStringList& getBehaviourList() const {return behaviourList;};
    const QVector<Passenger*>& getPassengerList() const {return passengerList;};
    int getNumFloors() const {return numFloors;};
    int getNumElevators() const {return numElevators;};
    const ElevatorController* getElevatorController() const {return elevatorController;};

    //  Setters
    void setName(const QString& name) {this->name = name;};
    void setNumFloors(int numFloors) {this->numFloors = numFloors;};
    void setNumPassengers(int numPassengers) {this->numPassengers = numPassengers;};
    void setNumElevators(int numElevators) {this->numElevators = numElevators;};
    void setBehaviourList(const QStringList& list) {behaviourList = list;};
    void setPassengerList(const QVector<Passenger*>& list);
    void setEventList(const QVector<Event*>& list);

    void logSystemEvent(const QString&, const  QString&);
    void processNextEvent();

private:
    QString name;
    int numPassengers;
    int numFloors;
    int numElevators;
    int currentEventIndex;
    SimulationState* state;
    QTime timeStep;
    ElevatorController* elevatorController;
    QVector<Passenger*> passengerList;
    QVector<Event*> eventList;
    QStringList behaviourList;

public slots:
    void start();
    void pause();
    void stop();
    void resume();
    void passengerEnteredElevator(Passenger* passenger, int elevatorID);
    void passengerExitedElevator(Passenger* passenger, int elevatorID);
    void elevatorFloorChangeReceived(int elevatorID, int floorNum);

signals:
//    void floorButtonPressed(int floor, bool up);
//    void elevatorButtonPressed(int elevatorID, int targetFloor);
    void enableResumeButton();
    void disableResumeButton();
    void updateTimeStep(const QTime& timeStep);
//    void doorButtonPressed(int elevatorID, bool open);
//    void helpButtonPressed(int elevatorID);
//    void safetyEventOccured(const QString& eventType);
    void updateElevatorFloor(int elevatorID, int floor);
    void sendSystemLog(const QString& log, const QString& response);
};

#endif // SIMULATIONCONTROLLER_H
