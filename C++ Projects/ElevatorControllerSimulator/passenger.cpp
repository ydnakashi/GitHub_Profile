#include "passenger.h"

Passenger::Passenger(const QString& name, int startingFloor, int targetFloor, QObject *parent)
    : QObject(parent), name(name), startingFloor(startingFloor), targetFloor(targetFloor), currentFloor(startingFloor)
{
    elevatorID = -1;
//    currentFloor = startingFloor;
}

Passenger::~Passenger() {
}

const QString& Passenger::getName() const {
    return name;
}

int Passenger::getCurrentFloor() const {
    qDebug() << currentFloor;
    return currentFloor;
}

int Passenger::getElevatorID() const {
    return elevatorID;
}

//void Passenger::setName(const QString& id) {
//    this->id = &id;
//}

void Passenger::setCurrentFloor(int floor) {
    currentFloor = floor;
}

void Passenger::display() const {
    qInfo() <<"Name: " + name + " Starting Floor: " + startingFloor + " Target Floor: " + targetFloor;
}

void Passenger::enterElevator(int elevatorID) {
    this->elevatorID = elevatorID;
    emit passengerEnteredElevator(this, elevatorID);
}

void Passenger::exitElevator(){
    emit passengerExitedElevator(this, elevatorID);
    elevatorID = -1;
}

void Passenger::requestFloor() {
    emit floorButtonPress(targetFloor);
}
