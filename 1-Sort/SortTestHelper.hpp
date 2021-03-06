//
// Created by mars on 2021/6/22.
//

#ifndef INC_1_SORT__SORTTESTHELPER_HPP_
#define INC_1_SORT__SORTTESTHELPER_HPP_

#include <cassert>
#include <iomanip>
#include <iostream>

namespace SortTestHelper {

//生成n元素随机数组，范围[rangeL, rangeR]
int *generateRandomArray(int n, int rangeL, int rangeR) {
  assert(rangeL <= rangeR);
  int *arr = new int[n];
  srand(time(NULL));

  for (int i = 0; i < n; ++i) {
    arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
  }
  cout << "Test Random Nearly Ordered Array, size = " << n << ", range = [" << rangeL << ", " << rangeR << "]" << endl;
  return arr;
}

int *generateNearlySmall2BigArray(int n, int swapTimes) {
  int *arr = new int[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = i;
  }

  srand(time(NULL));
  for (int i = 0; i < swapTimes; ++i) {
    int posx = rand() % n;
    int posy = rand() % n;
    swap(arr[posx], arr[posy]);
  }
  cout << "Test Random Nearly Small2Big Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
  return arr;
}

int *generateNearlyBig2SmallArray(int n, int swapTimes) {
  int *arr = new int[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = n-1-i;
  }

  srand(time(NULL));
  for (int i = 0; i < swapTimes; ++i) {
    int posx = rand() % n;
    int posy = rand() % n;
    swap(arr[posx], arr[posy]);
  }
  cout << "Test Random Nearly Big2Small Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
  return arr;
}

int *copyArray(int *arr, int n) {
  int *dupArr = new int[n];
  memcpy(dupArr, arr, n * sizeof(int));
  return dupArr;
}

template<typename T>
void printArray(T arr[], int n) {
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

template<typename T>
static bool isSorted(T arr[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    if (arr[i] > arr[i + 1])
      return false;
  }
  return true;
}

template<typename T>
void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
  clock_t startTime = clock();
  sort(arr, n);
  clock_t endTime = clock();
  assert(isSorted(arr, n));
  cout << sortName << ": " << setprecision(6) << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

}

#endif //INC_1_SORT__SORTTESTHELPER_HPP_
