#include "holdingstate.h"

HoldingState::HoldingState()
{

}

void HoldingState::handleRequest(Elevator *elevator) {
    qInfo() <<"Holding State behaviour running";
//    elevator->openDoor();
    QThread::sleep(OPEN_TIME);
//    elevator->closeDoor();
    elevator->setState(new MovingState());
}
