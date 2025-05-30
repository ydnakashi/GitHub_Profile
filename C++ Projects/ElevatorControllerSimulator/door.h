#ifndef DOOR_H
#define DOOR_H

#include <QDebug>
#include "bell.h"

class Door
{
public:
    Door();
    void ringBell() {bell.ring(); qInfo() <<"Bell rung";};

private:
    Bell bell;
};

#endif // DOOR_H
