#ifndef PASSENGER_H
#define PASSENGER_H

#include <QObject>
#include <QDebug>

class Passenger : public QObject
{
    Q_OBJECT
public:
    explicit Passenger(const QString& name = "Unamed Passenger", int startingFloor = 0, int targetFloor = 0, QObject *parent = nullptr);
    ~Passenger();

    // Getters
    const QString& getName() const;
    int getCurrentFloor() const;
    int getElevatorID() const;

    // Setters
//    void setName(const QString&);
    void setCurrentFloor(int);

    // Other
    void display() const;
    void enterElevator(int elevatorID);
    void exitElevator();
    void requestFloor();

private:
    QString name;
    int elevatorID; //-1 = not in elevator
    int startingFloor;
    int targetFloor;
    int currentFloor;

signals:
    void passengerEnteredElevator(Passenger* passenger, int elevatorID);
    void passengerExitedElevator(Passenger* passenger, int elevatorID);
    void floorButtonPress(int floor);
};

#endif // PASSENGER_H
