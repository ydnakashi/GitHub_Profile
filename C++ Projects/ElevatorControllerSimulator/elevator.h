#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QDebug>
#include <QQueue>
#include <QTimer>
#include <QThread>
#include "door.h"
#include "display.h"
#include "speaker.h"
#include "destinationpanel.h"
#include "helpbutton.h"
#include "firebutton.h"
#include "openbutton.h"
#include "closebutton.h"
#include "weightsensor.h"
#include "doorobstaclesensor.h"
#include "elevatorstate.h"
#include "idlestate.h"
#include "holdingstate.h"
#include "movingstate.h"
#include "emergencystate.h"
#include "freezestate.h"

#define TRAVEL_TIME 3000
#define OPEN_TIME 5000

class Elevator: public QObject
{
    Q_OBJECT
    friend class MovingState;
    friend class IdleState;
    friend class HoldingState;
    friend class EmergencyState;

public:
    explicit Elevator(int elevatorID, QObject *parent = nullptr);
    ~Elevator();
    void setState(ElevatorState* state);
    const DestinationPanel& getDestinationPanel() const {return panel;};
    QQueue<int>& getFloorQueue() {return floorQueue;};
    void addToQueue(int floorNum) {floorQueue.enqueue(floorNum);};
    void notifyFloorChange();

private:
    ElevatorState* state;
    int elevatorID;
    int currentFloor;
    int targetFloor;
    QQueue<int> floorQueue;
//    Door door;
//    Display display;
//    Speaker speaker;
    DestinationPanel panel;
//    HelpButton helpButton;
//    FireButton fireButton;
//    OpenButton openButton;
//    CloseButton closeButton;
//    WeightSensor sensor;
//    DoorObstacleSensor doorObstacle;

public slots:
//    void handleFloorArrival(int floorNum);
    void handleFloorSelection(int floorNum);
    void emergencySignalReceived();
    void engage();
    void stop();

signals:
    void elevatorFloorChange(int elevatorID, int floor);

};

#endif // ELEVATOR_H
