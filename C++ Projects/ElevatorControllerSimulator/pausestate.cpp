#include "pausestate.h"

PauseState::PauseState() { qInfo() <<"Pause State Created."; }

void PauseState::handleRequest(SimulationController *sim) {
    qInfo() <<"Pause state running.";
    emit sim->enableResumeButton();
    sim->elevatorController->stopAll();
}
