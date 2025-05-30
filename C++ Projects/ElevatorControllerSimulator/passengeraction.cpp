#include "passengeraction.h"

PassengerAction::PassengerAction(Passenger* passenger, QTime timeStep, const QString& behaviour, QObject *parent)
    : Event(passenger->getName(), timeStep, parent), passenger(passenger), behaviour(behaviour)
{

}

QString PassengerAction::execute() {
    if (behaviour  == "Press Up")
        emit upButtonPress();
    else if (behaviour == "Press Down")
        emit downButtonPress();
    return QString("%1: %2 did the %3 action.").arg(timeStep.toString("mm:ss")).arg(passenger->getName()).arg(behaviour);
}

