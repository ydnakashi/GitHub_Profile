#ifndef ELEVATORCONTROLLER_H
#define ELEVATORCONTROLLER_H

#include <QObject>
#include <QVector>
#include "elevator.h"
#include "floor.h"
#include "movingstate.h"
#include "holdingstate.h"
#include "idlestate.h"
#include "emergencystate.h"
#include "freezestate.h"

class ElevatorController : public QObject
{
    Q_OBJECT
public:
    explicit ElevatorController(QObject *parent = nullptr);

    // Getters
    int getNumFloors() const {return numFloors;};
    int getNumElevators() const {return numElevators;};
    const QVector<Floor*>& getFloorList() const {return floorList;};
    const QVector<Elevator*>& getElevatorList() const {return elevatorList;};

    // Setters
    void setupNumFloors(int num);
    void setupNumElevators(int num);

    // Other
    void runAll();
    void stopAll();

private:
    int numFloors;
    int numElevators;
    QVector<Elevator*> elevatorList;
    QVector<Floor*> floorList;

public slots:
    void handleFloorButton(int floor, bool up);
    void safetyEventReceived(const QString& type);

signals:
    void engage();
    void stop();
//    void engageSafetyProtocol();
};

#endif // ELEVATORCONTROLLER_H
