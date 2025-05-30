#include "floorbutton.h"

FloorButton::FloorButton(QObject *parent)
    : Button(parent)
{

}

void FloorButton::pressed() {
    illuminated = true;
    emit notifyFloor();
}
