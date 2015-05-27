#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <qstring.h>
#include "SortAlgorithm.h"

template <class T>
class ShellSort: public SortAlgorithm<T> {
public:
    ShellSort();
    virtual ~ShellSort();
    void sort(T* elements, int size);
};

#include "ShellSort.cpp"

#endif // SHELLSORT_H
