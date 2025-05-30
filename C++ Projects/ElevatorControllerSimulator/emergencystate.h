#ifndef EMERGENCYSTATE_H
#define EMERGENCYSTATE_H

#include <QDebug>
#include "elevatorstate.h"
#include "elevator.h"

class EmergencyState : public ElevatorState
{
public:
    EmergencyState();
    void handleRequest(Elevator*) override;
};

#endif // EMERGENCYSTATE_H
