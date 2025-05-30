#include "simulationcontroller.h"

SimulationController::SimulationController(ElevatorController* eleControl, QObject *parent):
    QObject(parent), elevatorController(eleControl) {
    state = nullptr;
    currentEventIndex = 0;
}

SimulationController::~SimulationController() {
    delete state;
}

void SimulationController::start(){
    setState(new SetupState());
}

void SimulationController::pause() {
    qInfo("Simulation paused.");
    setState(new PauseState());
}

void SimulationController::resume() {
    if (dynamic_cast<RunningState*>(state)) {
        qInfo() << "Simulation is already in running state.";;
        return;
    }
    qInfo("Simulation resumed.");
    setState(new RunningState());
}

void SimulationController::stop() {
    qInfo("Simulation stopped.");
    setState(new StopState());
}

void SimulationController::setState(SimulationState *newState) {
    if (state) delete state;
    state = newState;
    state->handleRequest(this);
}

void SimulationController::setPassengerList(const QVector<Passenger*>& list) {
    for (Passenger *p:passengerList){
        delete p;
    }
    passengerList = list;
    for (Passenger* passenger : passengerList) {
        connect(passenger, &Passenger::passengerEnteredElevator, this, &SimulationController::passengerEnteredElevator);
        connect(passenger, &Passenger::passengerExitedElevator, this, &SimulationController::passengerExitedElevator);
    }
}

void SimulationController::setEventList(const QVector<Event*>& list) {
    eventList = list;
    std::sort(eventList.begin(), eventList.end(),
              [](Event* e1, Event* e2) {
                  return e1->getTimeStep() < e2->getTimeStep();
              });
}

void SimulationController::processNextEvent() {
    if (currentEventIndex >= eventList.size()) {
           setState(new StopState());
           return;
    }

    Event* currentEvent = eventList[currentEventIndex++];
    QString log = currentEvent->execute();
    QString response = "";  // Add response logic
    logSystemEvent(log, response);
    qDebug() << log;

    timeStep = timeStep.addSecs(1);
    emit updateTimeStep(timeStep);

    QTimer::singleShot(2000, this, [this]() {
       processNextEvent();  // Call the next event after 2 seconds
    });
}

void SimulationController::passengerEnteredElevator(Passenger* passenger, int elevatorID) {
    Elevator* elevator = elevatorController->getElevatorList()[elevatorID];
    connect(passenger, &Passenger::floorButtonPress, &elevator->getDestinationPanel(), &DestinationPanel::addFloorRequest);
}

void SimulationController::passengerExitedElevator(Passenger* passenger, int elevatorID) {
    Elevator* elevator = elevatorController->getElevatorList()[elevatorID];
    disconnect(passenger, nullptr, &elevator->getDestinationPanel(), nullptr);
}

void SimulationController::elevatorFloorChangeReceived(int elevatorID, int floorNum) {
    emit updateElevatorFloor(elevatorID, floorNum);
}

void SimulationController::logSystemEvent(const QString & log, const QString& response) {
    emit sendSystemLog(log, response);
}
//void SimulationController::processNextEvent() {

//}

//void SimulationController::triggerFloorButton(int floor, bool up) {
//    emit floorButtonPressed(floor, up);
//}

//void SimulationController::triggerElevatorButton(int elevatorID, int targetFloor) {
//    emit elevatorButtonPressed(elevatorID, targetFloor);
//}

