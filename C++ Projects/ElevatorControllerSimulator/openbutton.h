#ifndef OPENBUTTON_H
#define OPENBUTTON_H

#include "button.h"
#include <QDebug>

class OpenButton : public Button
{
public:
    explicit OpenButton(QObject *parent = nullptr);

public slots:
    void heldDown();
};

#endif // OPENBUTTON_H
