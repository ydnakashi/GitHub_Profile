#ifndef MOVINGSTATE_H
#define MOVINGSTATE_H

#include <QDebug>
#include <QTimer>
#include "elevatorstate.h"
#include "elevator.h"

class MovingState : public ElevatorState
{
public:
    MovingState();
    void handleRequest(Elevator*) override;
private:
    void processNextTargetFloor(Elevator*);
    void moveOneFloor(Elevator*);;
};

#endif // MOVINGSTATE_H
