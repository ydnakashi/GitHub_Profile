#ifndef HELPBUTTON_H
#define HELPBUTTON_H

#include "button.h"
#include <QDebug>

class HelpButton : public Button
{
public:
    explicit HelpButton(QObject *parent = nullptr);

signals:
    void connectHelp();
};

#endif // HELPBUTTON_H
