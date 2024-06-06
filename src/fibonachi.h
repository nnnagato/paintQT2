#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <QObject>

class Fibonachi
{
    Q_OBJECT
public:
    Fibonachi();
    void calc(int order);
};

#endif // FIBONACHI_H
