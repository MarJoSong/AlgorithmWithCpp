//
// Created by mars on 2021/6/17.
// 快速回忆可参考菜鸟教程 (https://www.runoob.com/data-structures/data-structures-tutorial.html)
//
#include <iostream>
#include "Student.h"
#include "SortTestHelper.hpp"
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "SelectionSort.hpp"
#include "ShellSort.hpp"
#include "Heap.hpp"

using namespace std;


int main() {
  int n = 500000;
  int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
  int *arr2 = SortTestHelper::copyArray(arr1, n);
  int *arr3 = SortTestHelper::copyArray(arr1, n);
  int *arr4 = SortTestHelper::copyArray(arr1, n);

  SortTestHelper::testSort("MergeB2T  Sort", mergeSortB2T, arr1, n);
  SortTestHelper::testSort("Quick3WaysSort", quickSort3Ways, arr3, n);
  SortTestHelper::testSort("Heap      Sort", heapSort2, arr3, n);
  SortTestHelper::testSort("Heap      Sort", heapSort, arr4, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  delete[] arr4;

  arr1 = SortTestHelper::generateNearlySmall2BigArray(n, 100);
  arr2 = SortTestHelper::copyArray(arr1, n);
  arr3 = SortTestHelper::copyArray(arr1, n);
  arr4 = SortTestHelper::copyArray(arr1, n);

  SortTestHelper::testSort("MergeB2T  Sort", mergeSortB2T, arr1, n);
  SortTestHelper::testSort("Quick3WaysSort", quickSort3Ways, arr3, n);
  SortTestHelper::testSort("Heap      Sort", heapSort2, arr3, n);
  SortTestHelper::testSort("Heap      Sort", heapSort, arr4, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  delete[] arr4;

  arr1 = SortTestHelper::generateNearlyBig2SmallArray(n, 100);
  arr2 = SortTestHelper::copyArray(arr1, n);
  arr3 = SortTestHelper::copyArray(arr1, n);
  arr4 = SortTestHelper::copyArray(arr1, n);

  SortTestHelper::testSort("MergeB2T  Sort", mergeSortB2T, arr1, n);
  SortTestHelper::testSort("Quick3WaysSort", quickSort3Ways, arr3, n);
  SortTestHelper::testSort("Heap      Sort", heapSort2, arr3, n);
  SortTestHelper::testSort("Heap      Sort", heapSort, arr4, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  delete[] arr4;

  arr1 = SortTestHelper::generateRandomArray(n, 10, 99);
  arr2 = SortTestHelper::copyArray(arr1, n);
  arr3 = SortTestHelper::copyArray(arr1, n);
  arr4 = SortTestHelper::copyArray(arr1, n);

  SortTestHelper::testSort("MergeB2T  Sort", mergeSortB2T, arr1, n);
  SortTestHelper::testSort("Quick3WaysSort", quickSort3Ways, arr3, n);
  SortTestHelper::testSort("Heap      Sort", heapSort2, arr3, n);
  SortTestHelper::testSort("Heap      Sort", heapSort, arr4, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  delete[] arr4;

  return 0;
}