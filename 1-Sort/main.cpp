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
/*
  int n = 10000000;
#if 1
  int *arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
#else
  int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, 0);
#endif
  int *arr2 = SortTestHelper::copyArray(arr1, n);
  int *arr3 = SortTestHelper::copyArray(arr1, n);

  SortTestHelper::testSort("MergeB2T  Sort", mergeSortB2T, arr1, n);
  //SortTestHelper::testSort("Quick     Sort", quickSort, arr2, n);
  SortTestHelper::testSort("Quick2WaysSort", quickSort2Ways, arr2, n);
  SortTestHelper::testSort("Quick3WaysSort", quickSort3Ways, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
*/
  Heap<int> test = Heap<int>(10);
  srand(time(NULL));
  for (int i=0; i< 10; i++) {
    test.shiftUp(rand() % 100);
  }

  test.printArr();

  return 0;
}