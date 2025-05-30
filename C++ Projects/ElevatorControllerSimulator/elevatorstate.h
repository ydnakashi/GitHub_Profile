#ifndef ELEVATORSTATE_H
#define ELEVATORSTATE_H

class Elevator;

class ElevatorState
{
public:
    ElevatorState();
    virtual ~ElevatorState() = default;
    virtual void handleRequest(Elevator*) = 0;
protected:
    void setState(Elevator*, ElevatorState*);
};

#endif // ELEVATORSTATE_H
