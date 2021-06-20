//
// Created by mars on 2021/6/17.
//

#ifndef INC_1_SORT__SORTTESTHELPER_H_
#define INC_1_SORT__SORTTESTHELPER_H_

#include <cassert>

namespace SortTestHelper {

//生成n元素随机数组，范围[rangeL, rangeR]
int *generateRandomArray(int n, int rangeL, int rangeR) {
  assert(rangeL <= rangeR);
  int *arr = new int[n];
  srand(time(NULL));

  for (int i = 0; i < n; ++i) {
	arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
  }

  return arr;
}

int *dupArray(int arr[], int n) {
    int *dupArr = new int[n];
    memcpy(dupArr, arr, n * sizeof(int));
    return dupArr;
}

template<typename T>
void printArray(T arr[], int n) {
  for (int i = 0; i < n; ++i)
	cout << arr[i] << " ";
  cout << endl;

  return;
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
  cout << sortName << ": " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

}

#endif //INC_1_SORT__SORTTESTHELPER_H_
