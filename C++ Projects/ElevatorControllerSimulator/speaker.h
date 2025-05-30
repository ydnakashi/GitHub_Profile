#ifndef SPEAKER_H
#define SPEAKER_H

#include <QString>
#include <QDebug>

class Speaker
{
public:
    Speaker();

private:
    QString contents;
    int volume;
};

#endif // SPEAKER_H
