#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <QObject>

class Fibonachi : public QObject
{
    Q_OBJECT
public:
    Fibonachi();

    quint64 getFirstNumber() const;

    quint64 getSecondnumber() const;

    quint64 getResult() const;

    int getCurrent() const;

public slots:
    void calc(int order);

signals:
    void calced();
    void finished();

private:
    quint64 firstNumber;
    quint64 secondnumber;
    int current;
    quint64 result;
//protected:
};

#endif // FIBONACHI_H
