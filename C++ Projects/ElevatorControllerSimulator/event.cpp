#include "event.h"

Event::Event(const QString& name, QTime timeStep, QObject *parent)
    : QObject(parent), name(name), timeStep(timeStep)
{

}
