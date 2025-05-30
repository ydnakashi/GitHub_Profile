#include "firebutton.h"

FireButton::FireButton(QObject *parent)
    : Button(parent)
{

}

void FireButton::signalFire() {
    qInfo() << "Fire Signaled to Building Safety Service";
}
