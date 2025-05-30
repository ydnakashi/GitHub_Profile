#ifndef SETUPSTATE_H
#define SETUPSTATE_H

#include <QDebug>
#include "simulationstate.h"
#include "simulationcontroller.h"

class SetupState : public SimulationState
{
public:
    SetupState();
    void handleRequest(SimulationController*) override;
};

#endif // SETUPSTATE_H
