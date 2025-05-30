#include "stopstate.h"

StopState::StopState() {qInfo() << "Stop State Created";}

void StopState::handleRequest(SimulationController *sim) {
    qInfo() << "Simulation was stopped successfully.";
}
