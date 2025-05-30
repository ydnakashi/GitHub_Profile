#include "elevatorcontroller.h"

ElevatorController::ElevatorController(QObject *parent)
    : QObject(parent)
{}

void ElevatorController::setupNumFloors(int num) {
    numFloors = num;
    for (int i = 0; i < numFloors; ++i) {
        Floor* floor = new Floor(i+1, this);
        floorList.append(floor);
        connect(floor, &Floor::floorButtonPressed, this, &ElevatorController::handleFloorButton);
    }
}

void ElevatorController::setupNumElevators(int num) {
    numElevators = num;
    for (int i = 0; i < numElevators; ++i) {
        Elevator* elevator  = new Elevator(i);
        elevatorList.append(elevator);
        connect(this, &ElevatorController::engage, elevator, &Elevator::engage);
        connect(this, &ElevatorController::stop, elevator,  &Elevator::stop);
        // connect for safety events
    }
}

void ElevatorController::handleFloorButton(int floor, bool up) {
    qInfo() <<"Floor button pressed at floor: " << floor << (up ? "Up":"Down");
    // Find available elevator with shortest queue to add floor or if floor iis already within a queue of an elevator
    Elevator* minElevator = elevatorList.first();
    for (Elevator* elevator: elevatorList) {
        if (elevator->getFloorQueue().contains(floor))
            return;
        else if (elevator->getFloorQueue().size() < minElevator->getFloorQueue().size())
            minElevator = elevator;
    }
    minElevator->addToQueue(floor);
}

void ElevatorController::runAll() {
    emit engage();
}

void ElevatorController::stopAll() {
    emit stop();
}

void ElevatorController::safetyEventReceived(const QString& type) {
    // safetyEvent executed
}

