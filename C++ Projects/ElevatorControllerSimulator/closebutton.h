#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H

#include "button.h"
#include <QDebug>

class CloseButton : public Button
{
public:
    explicit CloseButton(QObject *parent = nullptr);

public slots:
    void openDoor();
};

#endif // CLOSEBUTTON_H
