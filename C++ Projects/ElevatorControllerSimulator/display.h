#ifndef DISPLAY_H
#define DISPLAY_H

#include <QString>
#include <QDebug>

class Display
{
public:
    Display();
    void setContents(const QString& contents) {this->contents = contents;};
    const QString& getContent() const {return contents;};
private:
    QString contents;
};

#endif // DISPLAY_H
