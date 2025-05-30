#include "movingstate.h"

MovingState::MovingState()
{

}

void MovingState::handleRequest(Elevator* elevator) {
    qInfo() <<"Moving State behaviour running";
    processNextTargetFloor(elevator);
}

void MovingState::processNextTargetFloor(Elevator* elevator) {
    if (elevator->getFloorQueue().isEmpty()) {
        elevator->setState(new IdleState());
        return;
    }

    elevator->targetFloor = elevator->getFloorQueue().dequeue();
    moveOneFloor(elevator);
}

void MovingState::moveOneFloor(Elevator* elevator) {
    if (elevator->currentFloor == elevator->targetFloor) {
        // Arrived at target floor, hold, then process next
        elevator->setState(new HoldingState());
        return;
    }

    // Simulate floor-by-floor movement
    QTimer::singleShot(TRAVEL_TIME, elevator, [this, elevator]() {
        if (elevator->currentFloor < elevator->targetFloor)
            ++elevator->currentFloor;
        else
            --elevator->currentFloor;

        elevator->notifyFloorChange();
        moveOneFloor(elevator);
    });
}
