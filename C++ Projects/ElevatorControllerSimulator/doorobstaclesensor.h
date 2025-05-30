#ifndef DOOROBSTACLESENSOR_H
#define DOOROBSTACLESENSOR_H

#include "sensor.h"
#include <QDebug>

class DoorObstacleSensor : public Sensor
{
public:
    explicit DoorObstacleSensor(QObject *parent = nullptr);

public slots:
    void triggered() override;
};

#endif // DOOROBSTACLESENSOR_H
