#ifndef SAFETYEVENT_H
#define SAFETYEVENT_H

#include "event.h"
#include <QDebug>

class SafetyEvent : public Event
{
    Q_OBJECT
public:
    explicit SafetyEvent(const QString& name, QTime timeStep, const QString& strType, QObject *parent = nullptr);
    const QString& getType();
    QString execute() override;

private:
    QString type;

signals:
    void eventExecuted(const QString& type);
};

#endif // SAFETYEVENT_H
