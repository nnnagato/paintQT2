#include "fibonachi.h"
#include <QThread>

Fibonachi::Fibonachi()
{
//    connect(this, &Fibonachi::finished, );
}

void Fibonachi::calc(int order)
{
    firstNumber = 0;
    secondnumber = 1;
    current = 1;
    result = 1;
    while (current<order)
    {
        current++;
        result = firstNumber + secondnumber;
        firstNumber = secondnumber;
        secondnumber = result;
        emit calced();
        QThread::msleep(10);
    }
    emit finished();
}

int Fibonachi::getCurrent() const
{
    return current;
}

quint64 Fibonachi::getResult() const
{
    return result;
}

quint64 Fibonachi::getSecondnumber() const
{
    return secondnumber;
}

quint64 Fibonachi::getFirstNumber() const
{
    return firstNumber;
}
