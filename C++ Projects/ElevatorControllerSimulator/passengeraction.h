#ifndef PASSENGERACTION_H
#define PASSENGERACTION_H

#include "event.h"
#include "passenger.h"
#include <QRegularExpression>

class PassengerAction : public Event
{
    Q_OBJECT
public:
    explicit PassengerAction(Passenger* passenger, QTime timeStep, const QString& behaviour, QObject *parent = nullptr);
    const QString& getBehaviour() const {return behaviour;};
    int getFloor() {return passenger->getCurrentFloor();};
    int getElevatorID() {return passenger->getElevatorID();};
    QString execute() override;

private:
    Passenger* passenger;
    QString behaviour;

signals:
    void upButtonPress();
    void downButtonPress();
//    void helpButtonPress(int elevatorID);
//    void openButtonPress();
//    void closeButtonPress();

};

#endif // PASSENGERACTION_H
