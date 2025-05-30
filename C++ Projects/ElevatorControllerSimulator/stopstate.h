#ifndef STOPSTATE_H
#define STOPSTATE_H

#include <QDebug>
#include "simulationstate.h"
#include "simulationcontroller.h"

class StopState : public SimulationState
{
public:
    StopState();
    void handleRequest(SimulationController*) override;
};

#endif // STOPSTATE_H
