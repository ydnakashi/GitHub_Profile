#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>
#include <QDebug>

class Sensor : public QObject
{
    Q_OBJECT
public:
    explicit Sensor(QObject *parent = nullptr);  

public slots:
    virtual void triggered() = 0;

};

#endif // SENSOR_H
