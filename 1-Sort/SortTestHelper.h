//
// Created by 76920 on 2020/9/18.
//

#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H

#include "stdafx.h"

namespace SortTestHelper {
    //随机种子
    default_random_engine e;

    //生成n的元素的随机数组，范围为[rangeL, rangeR]
    int *genereateRandomArray(int n, int rangeL, int rangeR) {

        assert(rangeL <= rangeR);

        int *arr = new int[n];
        static uniform_int_distribution<int> u(rangeL, rangeR);
        for (int i = 0; i < n; ++i)
            arr[i] = u(e);
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    template<typename T>
    void testSort(const string &sortName, void(*sort)(T [], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }

    template<typename T>
    T *copyIntArray(T a[], int n) {
        T *arr = new T[n];
        copy(a, a + n, arr);
        return arr;
    }

    int *generateNearlyOrderedArray(int n, int swaptimes) {
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = i;

        uniform_int_distribution<unsigned int> u(0, n - 1);
        for (int i = 0; i < swaptimes; i++) {
            int posx = u(e);
            int posy = u(e);
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }
}

#endif //SELECTIONSORT_SORTTESTHELPER_H
