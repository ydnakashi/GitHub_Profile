#ifndef FIREBUTTON_H
#define FIREBUTTON_H

#include "button.h"
#include <QDebug>

class FireButton : public Button
{
public:
    explicit FireButton(QObject *parent = nullptr);

public slots:
    void signalFire();
};

#endif // FIREBUTTON_H
