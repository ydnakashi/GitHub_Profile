#include "button.h"

Button::Button(bool light, QObject *parent)
    : QObject(parent), illuminated(light)  {}

void Button::handlePress() {
    illuminate();
    emit pressed();
}
