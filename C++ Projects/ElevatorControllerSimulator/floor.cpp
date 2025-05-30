#include "floor.h"

Floor::Floor(int floor, QObject* parent):QObject(parent), floorNum(floor)
{
    connect(&upButton, &Button::pressed, this, &Floor::handleUpButtonPress);
    connect(&downButton, &Button::pressed, this, &Floor::handleDownButtonPress);
}

void Floor::handleUpButtonPress() {
    emit floorButtonPressed(floorNum, true);
}

void Floor::handleDownButtonPress() {
    emit floorButtonPressed(floorNum, false);
}

void Floor::handleElevatorArrival() {
    upButton.darken();
    downButton.darken();
}
