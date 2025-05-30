#include "setupstate.h"

SetupState::SetupState(){qInfo() << "SetupState Created";}

void SetupState::handleRequest(SimulationController* sim) {
    qInfo("Simulation started.");
    sim->elevatorController->setupNumElevators(sim->numElevators);
    sim->elevatorController->setupNumFloors(sim->numFloors);

    for (Event* event : sim->eventList) {
           if (PassengerAction* passengerAction = dynamic_cast<PassengerAction*>(event)) {
               if (passengerAction->getBehaviour() == "Press Up" ) {
                   int floorIndex = passengerAction->getFloor();
                   if (floorIndex < 0 || floorIndex >= sim->elevatorController->getFloorList().size()) {
                       qWarning() << "Error: Invalid floor index" << floorIndex;
                   }
                   const Button* floorButton = sim->elevatorController->getFloorList()[floorIndex]->getUpButton();
                   connect(passengerAction, &PassengerAction::upButtonPress, floorButton, &Button::handlePress);
               } else if (passengerAction->getBehaviour() == "Press Down") {
                   int floorIndex = passengerAction->getFloor();
                   if (floorIndex < 0 || floorIndex >= sim->elevatorController->getFloorList().size()) {
                       qWarning() << "Error: Invalid floor index" << floorIndex;
                   }
                   const Button* floorButton = sim->elevatorController->getFloorList()[floorIndex]->getDownButton();
                   connect(passengerAction, &PassengerAction::downButtonPress, floorButton, &Button::handlePress);
               } else {
                   // For open, close, help buttons
               }
           }
           else if (SafetyEvent* safetyEvent = dynamic_cast<SafetyEvent*>(event)) {
               connect(safetyEvent, &SafetyEvent::eventExecuted, sim->elevatorController, &ElevatorController::safetyEventReceived);
           }
           else {
               qWarning() << "Unknown event type encountered!";
           }
      }

    for (Elevator* elevator : sim->elevatorController->getElevatorList()) {
        connect(elevator, &Elevator::elevatorFloorChange, sim, &SimulationController::elevatorFloorChangeReceived);
    }

    setState(sim, new RunningState());
}
