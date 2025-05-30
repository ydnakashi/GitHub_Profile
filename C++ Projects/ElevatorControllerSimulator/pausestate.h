#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include <QDebug>
#include "simulationstate.h"
#include "simulationcontroller.h"

class PauseState : public SimulationState
{
public:
    PauseState();
    void handleRequest(SimulationController*) override;
};

#endif // PAUSESTATE_H
