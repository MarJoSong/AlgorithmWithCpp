#include "stdafx.h"
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"


int main() {
    /*
    Student d[4] = {
            Student("D", 88),
            Student("B", 100),
            Student("A", 98),
            Student("C", 88)
    };
    selectionSort(d, 4);
    for (const auto &x : d) {
        cout << x;
    }
    */

    int n = 50000;
    int *arr1 = SortTestHelper::genereateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("SelectionSort", selectionSort, arr1, n);
    SortTestHelper::testSort("InsertionSortOptimise", insertionSortOptimise, arr2, n);
    SortTestHelper::testSort("MergeSort", mergeSort, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    //优化后的插入排序在大部分有序的数组上效率惊人
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, 3);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("SelectionSort", selectionSort, arr1, n);
    SortTestHelper::testSort("InsertionSortOptimise", insertionSortOptimise, arr2, n);
    SortTestHelper::testSort("MergeSort", mergeSort, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}
