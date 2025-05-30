#include "simulationstate.h"
#include "simulationcontroller.h"

SimulationState::SimulationState() {}

void SimulationState::setState(SimulationController* simControl, SimulationState* simState) {
    simControl->setState(simState);
}
