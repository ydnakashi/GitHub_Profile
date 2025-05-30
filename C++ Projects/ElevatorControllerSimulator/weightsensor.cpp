#include "weightsensor.h"

WeightSensor::WeightSensor(QObject *parent)
    : Sensor{parent}
{

}

void WeightSensor::triggered() {
    qInfo() <<"Weight Overload detected.";
}
