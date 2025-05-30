#include "idlestate.h"

IdleState::IdleState()
{

}

void IdleState::handleRequest(Elevator *elevator) {
    qInfo() <<"Idle state behaviour running";
    if (!elevator->getFloorQueue().isEmpty())
        elevator->setState(new MovingState());
}
