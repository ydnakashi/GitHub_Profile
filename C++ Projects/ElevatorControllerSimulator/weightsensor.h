#ifndef WEIGHTSENSOR_H
#define WEIGHTSENSOR_H

#include "sensor.h"
#include <QDebug>

class WeightSensor : public Sensor
{
public:
    explicit WeightSensor(QObject *parent = nullptr);

public slots:
    void triggered() override;
};

#endif // WEIGHTSENSOR_H
