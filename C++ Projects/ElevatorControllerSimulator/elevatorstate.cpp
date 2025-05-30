#include "elevatorstate.h"
#include "elevator.h"

ElevatorState::ElevatorState()
{

}

void ElevatorState::setState(Elevator *elevator, ElevatorState *elevatorState) {
    elevator->setState(elevatorState);
}
