#ifndef FLOORBUTTON_H
#define FLOORBUTTON_H

#include "button.h"

class FloorButton : public Button
{
public:
    explicit FloorButton(QObject *parent = nullptr);
    bool getDirection() const {return up;};
    void setDirection(bool up) {this->up = up;};

private:
    bool up; //Up = true, Down = false
    bool illuminated;

public slots:
    void pressed();
};

#endif // FLOORBUTTON_H
