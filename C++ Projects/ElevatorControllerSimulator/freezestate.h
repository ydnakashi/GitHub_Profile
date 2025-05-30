#ifndef FREEZESTATE_H
#define FREEZESTATE_H

#include "elevatorstate.h"
#include "elevator.h"
#include <QDebug>

class FreezeState : public ElevatorState
{
public:
    FreezeState();
    void handleRequest(Elevator*) override;
};

#endif // FREEZESTATE_H
