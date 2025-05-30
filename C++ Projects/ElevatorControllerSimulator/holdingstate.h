#ifndef HOLDINGSTATE_H
#define HOLDINGSTATE_H

#include <QDebug>
#include "elevatorstate.h"
#include "elevator.h"

class HoldingState : public ElevatorState
{
public:
    HoldingState();
    void handleRequest(Elevator*) override;
};

#endif // HOLDINGSTATE_H
