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

template<typename T>
void printHeap(T arr, int n) {
  int flag = 1;
  int max = 1;
  while (max < n) max <<= 1;
  max <<= 1;
  cout << "The structure of Heap:";
  for (int i = 1; i <= n; ++i) {
    if (i == flag) {
      cout << endl;
      flag <<= 1;
      max /= 2;
      for (int k = 0; k < max / 2; ++k)
        cout << "  ";
    }
    cout << setw(2) << arr[i];
    for (int k = 0; k < max - 1; ++k)
      cout << "  ";
  }
  cout << endl;
}

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

  int *arr1 = SortTestHelper::generateRandomArray(10, 10, 99);
  int *arr2 = new int[11];
  copy(arr1, arr1 + 10, arr2 + 1);
  printHeap(arr2, 10);

  Heap<int> hp = Heap<int>(arr1, 10);
  for (int i = 0; i < 10; i++)
    cout << hp.extract() << " ";
  cout << endl;


  return 0;
}