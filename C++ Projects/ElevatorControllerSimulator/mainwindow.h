#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QComboBox>
#include <QVector>
#include <QRadioButton>
#include <QPushButton>
#include "simulationcontroller.h"
#include "event.h"
#include "passengeraction.h"
#include "safetyevent.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(SimulationController* sim, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SimulationController *sim;

    void clearTable(QTableWidget*);
    void processPassengerTable(QVector<Passenger*>&);
    void processPassengerActionTable(QVector<Event*>&);
    void processSafetyEventTable(QVector<Event*>&);
    void setupStatesTable();

public slots:
    void startSimulation();
    void enableStartButton();
    void addPassengerActionRow();
    void removePassengerActionRow();
    void addSafetyEventRow();
    void removeSafetyEventRow();
    void addPassengerInput();
    void updateBehaviourList();
    void updatePassengerList();
    void clearEverything();
    void updateTimeStepLabel(const QTime& timeStep);
    void updateElevatorFloor(int elevatorID, int floor);
    void receiveSystemLog(const QString& log, const QString& response);

signals:
    void startRequest();
};
#endif // MAINWINDOW_H
