#include "safetyevent.h"

SafetyEvent::SafetyEvent(const QString& name, QTime timeStep, const QString& type, QObject *parent)
    : Event(name, timeStep, parent), type(type)
{

}

QString SafetyEvent::execute() {
    emit eventExecuted(type);
    return QString("%1: Safety event %2 triggered.").arg(timeStep.toString("mm:ss")).arg(type);
}
