#include "closebutton.h"

CloseButton::CloseButton(QObject *parent)
    : Button(parent)
{

}

void CloseButton::openDoor() {
    qInfo() <<"Door held open";
}
