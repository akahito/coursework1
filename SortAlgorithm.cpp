#include "SortAlgorithm.h"

#ifndef SORT_ALGORITHM_CPP
#define SORT_ALGORITHM_CPP

template <class T>
SortAlgorithm<T>::SortAlgorithm(QString name):
    name(name) {}

template <class T>
SortAlgorithm<T>::~SortAlgorithm() {}

template <class T>
void SortAlgorithm<T>::swap(T* elements, int i, int j) {
    T tmp = elements[i];
    elements[i] = elements[j];
    elements[j] = tmp;
}

template <class T>
QString SortAlgorithm<T>::getName() {
    return name;
}

#endif // SORT_ALGORITHM_CPP
