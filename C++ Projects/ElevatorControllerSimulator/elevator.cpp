#include "elevator.h"

Elevator::Elevator(int elevatorID, QObject* parent):
    QObject(parent), elevatorID(elevatorID)
{
    state = new IdleState();
    currentFloor = 0;
    targetFloor = 0;
    connect(&panel, &DestinationPanel::addFloorToQueue, this, &Elevator::handleFloorSelection);
}

Elevator::~Elevator() {
    delete state;
}

void Elevator::setState(ElevatorState *newState) {
    if (state) delete state;
    state = newState;
    state->handleRequest(this);
}

void Elevator::notifyFloorChange() {
    emit elevatorFloorChange(elevatorID, currentFloor);
}

void Elevator::handleFloorSelection(int floorNum){
    floorQueue.enqueue(floorNum);
}

void Elevator::engage() {
    setState(new MovingState());
}

void Elevator::stop() {
    setState(new FreezeState());
}

void Elevator::emergencySignalReceived() {
    setState(new EmergencyState());
}
