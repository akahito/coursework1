#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortAlgorithm.h"

template <class T>
class QuickSort : public SortAlgorithm<T> {
public:
    QuickSort();
    virtual ~QuickSort();
    void sort(T* elements, int size);
private:
    void sort(T* elements, int from, int to);
    int partition(T* elements, int from, int to);
};

#include "QuickSort.cpp"

#endif // QUICKSORT_H
