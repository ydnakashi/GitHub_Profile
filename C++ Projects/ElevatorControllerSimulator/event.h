#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include <QDebug>
#include <QTime>

class Event : public QObject
{
    Q_OBJECT
public:
    explicit Event(const QString& name, QTime timeStep, QObject *parent = nullptr);
    virtual ~Event() = default;

    // Getter
    const QString& getName() const {return name;};
    QTime getTimeStep() const {return timeStep;};
    virtual QString execute() = 0;
    void display() const {qInfo() <<"Name: " + name + " Time Step: " + timeStep.toString("mm:ss");};

protected:
    QString name;
    QTime timeStep;

//signals:
//     void eventExecuted(const QString& event);

};

#endif // EVENT_H
