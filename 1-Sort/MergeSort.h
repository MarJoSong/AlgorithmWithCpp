//
// Created by 76920 on 2020/9/25.
//

#ifndef SELECTIONSORT_MERGESORT_H
#define SELECTIONSORT_MERGESORT_H

#include "stdafx.h"

template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    T *aux = new T[r - l + 1]; //auxiliary ������
    for (int i = l; i <= r; i++)
        aux[i - l] = arr[i];

    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {
            arr[k] = arr[j - l];
            j++;
        } else if (j > r) {
            arr[k] = arr[i - l];
            i++;
        } else if (aux[i - l] < aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        } else {
            arr[k] = aux[j - l];
            j++;
        }
    }

    delete[] aux;
}

template<typename T>
//��arr�����[l,r]���������еݹ�ϸ��֮��鲢
void __mergeSort(T arr[], int l, int r) {
    //˵���Ѿ�����С���䣬ֻ��һ��Ԫ�ػ���һ��û�У�ֱ�ӷ���
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}

#endif //SELECTIONSORT_MERGESORT_H
