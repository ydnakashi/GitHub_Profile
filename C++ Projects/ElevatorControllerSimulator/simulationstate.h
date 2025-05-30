#ifndef SIMULATIONSTATE_H
#define SIMULATIONSTATE_H

#include <QObject>

class SimulationController;

class SimulationState: public QObject
{
    Q_OBJECT
public:
    SimulationState();
    virtual ~SimulationState() = default;
    virtual void handleRequest(SimulationController*) = 0;
protected:
    void setState(SimulationController*, SimulationState*);
};

#endif // SIMULATIONSTATE_H
