#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(SimulationController* sim, QWidget *parent):
    QMainWindow(parent), ui(new Ui::MainWindow), sim(sim)
{
    ui->setupUi(this);

    // Simulation Control
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startSimulation);
    connect(ui->pauseButton, &QPushButton::clicked, sim, &SimulationController::pause);
    connect(ui->resumeButton, &QPushButton::clicked, sim, &SimulationController::resume);
    connect(ui->stopButton, &QPushButton::clicked, sim, &SimulationController::stop);
    connect(this, &MainWindow::startRequest, sim, &SimulationController::start);

    // List Control
    connect(ui->passengerActionAddRowButton, SIGNAL(released()), this, SLOT(addPassengerActionRow()));
    connect(ui->safetyEventAddRowButton, SIGNAL(released()), this, SLOT(addSafetyEventRow()));
    connect(ui->passengerActionRemoveRowButton, SIGNAL(released()), this, SLOT(removePassengerActionRow()));
    connect(ui->safetyEventRemoveRowButton, SIGNAL(released()), this, SLOT(removeSafetyEventRow()));
    connect(ui->numPassengerSpinBox, SIGNAL(editingFinished()), this, SLOT(addPassengerInput()));
    connect(ui->passengerTableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::updatePassengerList);
    connect(ui->numFloorSpinBox, SIGNAL(editingFinished()), this, SLOT(updateBehaviourList()));

    // Simulation Setup UI
    connect(ui->setupTabSimNameLineEdit, SIGNAL(editingFinished()), this, SLOT(enableStartButton()));
    connect(ui->clearRadioButton, &QRadioButton::toggled, ui->clearPushButton, &QPushButton::setEnabled);
    connect(ui->clearPushButton, SIGNAL(released()), this, SLOT(clearEverything()));
    connect(sim, &SimulationController::enableResumeButton, this, [this](){
        ui->resumeButton->setEnabled(true);
    });
    connect(sim, &SimulationController::disableResumeButton, this, [this](){
        ui->resumeButton->setDisabled(true);
    });
    connect(sim, &SimulationController::updateElevatorFloor, this, &MainWindow::updateElevatorFloor);

    // Simulation to Window Updates
    connect(sim, &SimulationController::updateTimeStep, this, &MainWindow::updateTimeStepLabel);
    connect(sim, &SimulationController::sendSystemLog, this, &MainWindow::receiveSystemLog);

    ui->startButton->setDisabled(true);
    ui->resumeButton->setDisabled(true);
    ui->stopButton->setDisabled(true);
    ui->pauseButton->setDisabled(true);
    ui->clearPushButton->setDisabled(true);
    ui->logTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startSimulation() {
    sim->setName(ui->setupTabSimNameLineEdit->text());
    sim->setNumFloors(ui->numFloorSpinBox->value());
    sim->setNumElevators(ui->numElevatorSpinBox->value());
    sim->setNumPassengers(ui->numPassengerSpinBox->value());
    ui->tabWidget->setCurrentWidget(ui->logTab);

    updatePassengerList();
    QVector<Event*> events;
    processPassengerActionTable(events);
    processSafetyEventTable(events);
    sim->setEventList(events);
    emit startRequest();

    setupStatesTable();
    ui->stopButton->setEnabled(true);
    ui->pauseButton->setEnabled(true);
}

void MainWindow::enableStartButton() {
    if (ui->setupTabSimNameLineEdit->text() != "")
        ui->startButton->setEnabled(true);
    else
        ui->startButton->setDisabled(true);
}

void MainWindow::clearEverything() {
    ui->setupTabSimNameLineEdit->clear();
    ui->numElevatorSpinBox->clear();
    ui->numFloorSpinBox->clear();
    ui->numPassengerSpinBox->clear();
    clearTable(ui->passengerTableWidget);
    clearTable(ui->passengerActionTableWidget);
    clearTable(ui->safetyEventTableWidget);
}

void MainWindow::clearTable(QTableWidget* tableWidget) {
    for (int row = tableWidget->rowCount()-1; row >= 0; --row) {
        tableWidget->removeRow(row);
    }
}

void MainWindow::updateBehaviourList() {
    QStringList newBehaviourList = {"Press Up", "Press Down", "Hold Open", "Release Open", "Press Close", "Press Help"};
    sim->setBehaviourList(newBehaviourList);

    // Update Passenger Actions Table Widget
    for (int row = 0;  row < ui->passengerActionTableWidget->rowCount(); ++row) {
        QComboBox* comboBox = new QComboBox();
        comboBox->addItems(sim->getBehaviourList());
        ui->passengerActionTableWidget->setCellWidget(row, 2, comboBox);
    }
}

void MainWindow::updatePassengerList() {
    QVector<Passenger*> passengers;
    processPassengerTable(passengers);
    sim->setPassengerList(passengers);

    // Update combo box
    QStringList nameList;
    for (Passenger* pas:sim->getPassengerList()) {
        nameList.append(pas->getName());
    }
    for (int row = 0;  row < ui->passengerActionTableWidget->rowCount(); ++row) {
        QComboBox* comboBox = new QComboBox();
        comboBox->addItems(nameList);
        ui->passengerActionTableWidget->setCellWidget(row, 0, comboBox);
    }
}

void MainWindow::addPassengerInput() {
    int numPassengers = ui->numPassengerSpinBox->value();
    if (numPassengers > ui->passengerTableWidget->rowCount()) {
        for (int row = ui->passengerTableWidget->rowCount(); row > numPassengers; --row) {
            ui->passengerTableWidget->removeRow(row);
        }
    }
    for (int row = ui->passengerTableWidget->rowCount(); row < numPassengers; ++row) {
        ui->passengerTableWidget->insertRow(row);
        ui->passengerTableWidget->setItem(row, 0, new QTableWidgetItem("Unamed Passenger"));
        ui->passengerTableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(0)));
        ui->passengerTableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(0)));
    }
}

void MainWindow::addPassengerActionRow() {
    int row = ui->passengerActionTableWidget->rowCount();
    ui->passengerActionTableWidget->insertRow(row);

    QStringList nameList;
    for (const Passenger* pas: sim->getPassengerList()) {
        nameList.append(pas->getName());
    }
    QComboBox* nameComboBox = new QComboBox();
    nameComboBox->addItems(nameList);
    ui->passengerActionTableWidget->setCellWidget(row, 0, nameComboBox);
    ui->passengerActionTableWidget->setItem(row, 1, new QTableWidgetItem("0:00"));

    QComboBox* behaviourComboBox = new QComboBox();
    behaviourComboBox->addItems(sim->getBehaviourList());
    ui->passengerActionTableWidget->setCellWidget(row, 2, behaviourComboBox);
}

void MainWindow::removePassengerActionRow() {
    int index = ui->passengerActionTableWidget->selectionModel()->currentIndex().row();
    ui->passengerActionTableWidget->removeRow(index);
}

void MainWindow::addSafetyEventRow() {
    int row = ui->safetyEventTableWidget->rowCount();
    ui->safetyEventTableWidget->insertRow(row);

    ui->safetyEventTableWidget->setItem(row, 0, new QTableWidgetItem("Unamed Event"));
    ui->safetyEventTableWidget->setItem(row, 1, new QTableWidgetItem("0:00"));

    QStringList eventList = {"Power Out", "Overload", "Fire Signal", "Door Obstacle"};
    QComboBox* comboBox = new QComboBox();
    comboBox->addItems(eventList);
    ui->safetyEventTableWidget->setCellWidget(row, 2, comboBox);
}

void MainWindow::removeSafetyEventRow() {
    int index = ui->safetyEventTableWidget->selectionModel()->currentIndex().row();
    ui->safetyEventTableWidget->removeRow(index);
}

void MainWindow::processPassengerTable(QVector<Passenger*>& list) {
    QTableWidget* tableWidget = ui->passengerTableWidget;
    int startingFloor, targetFloor;
    int maxNum = sim->getNumFloors()-1;
    int minNum = 0;
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        QString name = tableWidget->item(row, 0)->text();
        startingFloor = tableWidget->item(row, 1)->text().toInt() % (maxNum + 1 - minNum) + minNum;
        targetFloor = tableWidget->item(row, 2)->text().toInt() % (maxNum + 1 - minNum) + minNum;
        Passenger* passenger = new Passenger(name, startingFloor, targetFloor);
        list.append(passenger);
    }
}

void MainWindow::processPassengerActionTable(QVector<Event*>& list) {
    QTableWidget* tableWidget = ui->passengerActionTableWidget;
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        QString name = (qobject_cast<QComboBox*>)(tableWidget->cellWidget(row, 0))->currentText();
        Passenger* passenger = nullptr;
        for (Passenger* pas:sim->getPassengerList()) {
            if (pas->getName() == name) {
                passenger = pas;
                break;
            }
        }
        QTime timeStep = QTime::fromString(tableWidget->item(row, 1)->text(), "m:ss");
        QString value = (qobject_cast<QComboBox*>)(tableWidget->cellWidget(row, 2))->currentText();
        list.append(new PassengerAction(passenger, timeStep, value));
    }
}

void MainWindow::processSafetyEventTable(QVector<Event*>& list) {
    QTableWidget* tableWidget = ui->safetyEventTableWidget;
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        QString name = tableWidget->item(row, 0)->text();
        QTime timeStep = QTime::fromString(tableWidget->item(row, 1)->text(), "m:ss");
        QString value = (qobject_cast<QComboBox*>)(tableWidget->cellWidget(row, 2))->currentText();
        list.append(new SafetyEvent(name, timeStep, value));
    }
}

void MainWindow::setupStatesTable() {
    for (int i = 0; i < sim->getNumElevators(); ++i) {
        int row = ui->statesTableWidget->rowCount();
        ui->statesTableWidget->insertRow(row);

        ui->statesTableWidget->setItem(row, 0, new QTableWidgetItem(QString("E%1").arg(i))); // System Event
        ui->statesTableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(i))); // System Response
    }
}

void MainWindow::updateTimeStepLabel(const QTime& timeStep) {
    ui->timeStepLabel->setText("TimeStep: " + timeStep.toString("m:ss"));
}

void MainWindow::updateElevatorFloor(int elevatorID, int floor) {
    ui->statesTableWidget->setItem(elevatorID, 1, new QTableWidgetItem(QString::number(floor)));
}

void MainWindow::receiveSystemLog(const QString& log, const QString& response) {
    int row = ui->logTableWidget->rowCount();
    ui->logTableWidget->insertRow(row);

    ui->logTableWidget->setItem(row, 0, new QTableWidgetItem(log)); // System Event
    ui->logTableWidget->setItem(row, 1, new QTableWidgetItem(response)); // System Response
}

//void MainWindow::processTable(QTableWidget* tableWidget, QVector<Event*>& list,
//                              std::function<Event*(const QString&, QTime, const QString&)> factory) {
//    for (int row = 0; row < tableWidget->rowCount(); ++row) {
//        QString name = tableWidget->item(row, 0)->text();
//        QTime timeStep = QTime::fromString(tableWidget->item(row, 1)->text(), "m:ss");
//        QString value = (qobject_cast<QComboBox*>)(tableWidget->cellWidget(row, 2))->currentText();
//        Event* obj = factory(name, timeStep, value);
//        list.append(obj);
//    }

//    for (const auto &obj : list) {
//        obj->display();
//    }
//}

