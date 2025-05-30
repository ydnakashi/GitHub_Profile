#include "mainwindow.h"
#include "simulationcontroller.h"
#include "elevatorcontroller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ElevatorController elevatorController;
    SimulationController sim(&elevatorController);
    MainWindow w(&sim);
    w.show();
    return a.exec();
}
