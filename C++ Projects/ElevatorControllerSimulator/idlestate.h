#ifndef IDLESTATE_H
#define IDLESTATE_H

#include <QDebug>
#include "elevatorstate.h"
#include "elevator.h"

class IdleState : public ElevatorState
{
public:
    IdleState();
    void handleRequest(Elevator*) override;
};

#endif // IDLESTATE_H
