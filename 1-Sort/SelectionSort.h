//
// Created by 76920 on 2020/9/21.
//

#ifndef SELECTIONSORT_SELECTIONSORT_H
#define SELECTIONSORT_SELECTIONSORT_H

#include "stdafx.h"

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

#endif //SELECTIONSORT_SELECTIONSORT_H
