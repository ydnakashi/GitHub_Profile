#ifndef FLOOR_H
#define FLOOR_H

#include "button.h"
#include <QObject>
#include <QDebug>

class Floor: public QObject
{
    Q_OBJECT
public:
    Floor(int floor, QObject *parent = nullptr);
    const Button* getUpButton() const {return &upButton;};
    const Button* getDownButton() const {return &downButton;};

private:
    int floorNum;
    Button upButton;
    Button downButton;

public slots:
    void handleUpButtonPress();
    void handleDownButtonPress();
    void handleElevatorArrival();

signals:
    void floorButtonPressed(int floorNum, bool up);
};

#endif // FLOOR_H
