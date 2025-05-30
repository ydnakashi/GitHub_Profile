#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>

class Button : public QObject
{
    Q_OBJECT
public:
    explicit Button(bool light = false, QObject *parent = nullptr);
    void illuminate() {illuminated = true;};
    void darken() {illuminated = false;};

protected:
    bool illuminated;

public slots:
    void handlePress();

signals:
    void pressed();

};

#endif // BUTTON_H
