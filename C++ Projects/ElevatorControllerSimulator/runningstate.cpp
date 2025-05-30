#include "runningstate.h"

RunningState::RunningState() { qInfo() << "Running State Created";}

void RunningState::handleRequest(SimulationController *sim) {
    qInfo() <<"Simulation running smoothly.";
    sim->elevatorController->runAll();
    emit sim->disableResumeButton();
    sim->processNextEvent();
}
