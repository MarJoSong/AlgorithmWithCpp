//
// Created by 76920 on 2020/9/25.
//

#ifndef SELECTIONSORT_INSERTIONSORT_H
#define SELECTIONSORT_INSERTIONSORT_H

#include "stdafx.h"

template<typename  T>
void insertionSort(T arr[], int n) {
    for (int i=2; i<n; i++) {
        for (int j=i; j>0 && arr[j] < arr[j-1]; j--) {
            /*
             * ��������i�Ѿ�����i-1ʱ��ѭ����������,�ж�����������for������
            if (arr[j] < arr[j-1])
                swap(arr[j], arr[j-1]);
            */
            swap(arr[j], arr[j-1]);
        }
    }
}

template<typename  T>
void insertionSortOptimise(T arr[], int n) {
    for (int i=1; i<n; i++) {

        T tmp = arr[i];
        int j;
        for (j=i; j>0 && arr[j-1]>tmp; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
}

#endif //SELECTIONSORT_INSERTIONSORT_H
