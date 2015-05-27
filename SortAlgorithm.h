#ifndef SORT_H
#define SORT_H

#include <QDebug>
#include <QRunnable>
#include <QTime>
#include <QString>

template <class T>
class SortAlgorithm {
public:
    SortAlgorithm(QString name);
    virtual ~SortAlgorithm();

    virtual void sort(T* elements, int size) = 0;
    QString getName();
protected:
    void swap(T* elements, int i, int j);

private:
    QString name;
};

#include "SortAlgorithm.cpp"

#endif // SORT_H
