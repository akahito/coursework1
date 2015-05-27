#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortAlgorithm.h"

template <class T>
class MergeSort: public SortAlgorithm<T> {
public:
    MergeSort();
    virtual ~MergeSort();
    void sort(T* elements, int size);
private:
    void sort(T* elements, T* result, int from, int to);
    void merge(T* elements, T* result, int firstFrom, int firstTo, int secondFrom, int secondTo);
};

#include "MergeSort.cpp"

#endif // MERGESORT_H

