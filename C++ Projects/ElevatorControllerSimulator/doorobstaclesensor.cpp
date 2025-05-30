#include "doorobstaclesensor.h"

DoorObstacleSensor::DoorObstacleSensor(QObject *parent)
    : Sensor{parent}
{

}

void DoorObstacleSensor::triggered() {
    qInfo()<< "Door Obstacle Detected.";
}
