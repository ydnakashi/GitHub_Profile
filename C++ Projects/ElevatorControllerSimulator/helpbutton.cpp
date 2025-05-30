#include "helpbutton.h"

HelpButton::HelpButton(QObject *parent)
    : Button(parent)
{

}

void HelpButton::connectHelp() {
    qInfo() <<"Building Safety Service Connected.";
}
