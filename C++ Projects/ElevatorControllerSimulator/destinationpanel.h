#ifndef DESTINATIONPANEL_H
#define DESTINATIONPANEL_H

#include <QObject>
#include <QDebug>
#include "button.h"

class DestinationPanel : public Button
{
    Q_OBJECT
public:
    explicit DestinationPanel(int numFloors = 1, QObject *parent = nullptr);
    int getNumFloors() {return numFloors;};

private:
    int numFloors;

public slots:
    void addFloorRequest(int floor);

signals:
    void addFloorToQueue(int floor);
};

#endif // DESTINATIONPANEL_H
