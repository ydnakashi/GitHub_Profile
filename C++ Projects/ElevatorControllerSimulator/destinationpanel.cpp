#include "destinationpanel.h"

DestinationPanel::DestinationPanel(int numFloors, QObject *parent)
    : Button(parent), numFloors(numFloors)
{

}

void DestinationPanel::addFloorRequest(int floor) {
    qInfo() <<"Floor " + QString::number(floor) + " Requested";
    if (floor < 1 || floor >= numFloors) {
        qInfo() <<"Floor request number invalid";
        return;
    }
    emit addFloorToQueue(floor);
}
