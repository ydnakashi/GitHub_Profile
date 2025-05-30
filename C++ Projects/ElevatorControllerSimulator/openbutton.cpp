#include "openbutton.h"

OpenButton::OpenButton(QObject *parent)
    : Button(parent)
{

}

void OpenButton::heldDown() {
    qInfo() <<"Open button held down.";
}
