#ifndef SORTTHREAD_H
#define SORTTHREAD_H

#include <QRunnable>
#include <QObject>
#include <QString>
#include <vector>
#include "SortAlgorithm.h"
#include "SortMethod.h"
#include "SortType.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "ShellSort.h"

class SortThread: public QObject, public QRunnable {
    Q_OBJECT
public:
    SortThread();
    ~SortThread();
    void start(QString text, SortMethod method, SortType type);

private:
    void run();
    void sortString();
    void sortDouble();

    QString text;
    SortMethod method;
    SortType type;
    std::vector<SortAlgorithm<QString>*> stringAlgorithms;
    std::vector<SortAlgorithm<double>*> doubleAlgorithms;

signals:
    void end(QString result, int time);
};

#endif // SORTTHREAD_H
