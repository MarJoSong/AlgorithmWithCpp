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

using namespace std;

int main() {

  int n = 1000000;
#if 0
  //int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
#else
  int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, 10);
#endif
  int *arr2 = SortTestHelper::copyArray(arr1, n);

  SortTestHelper::testSort("MergeB2T  Sort", mergeSortB2T, arr1, n);
  SortTestHelper::testSort("Quick     Sort", quickSort, arr2, n);

  delete[] arr1;
  delete[] arr2;

  return 0;
}