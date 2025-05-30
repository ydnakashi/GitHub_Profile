#ifndef RUNNINGSTATE_H
#define RUNNINGSTATE_H

#include <QDebug>
#include <QTimer>
#include "simulationstate.h"
#include "simulationcontroller.h"

class RunningState : public SimulationState
{
public:
    RunningState();
    void handleRequest(SimulationController*) override;
};

#endif // RUNNINGSTATE_H
