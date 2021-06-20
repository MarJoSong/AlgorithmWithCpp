//
// Created by mars on 2021/6/17.
//
#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

//选择排序，时间复杂度为O(n^2), 空间复杂度为1
template<typename T>
void selectionSort(T arr[], int n) {
  //优化：i的判断可以是i < n - 1;因为i若为n-1, j=n必不满足j<n
  for (int i = 0; i < n; ++i) {
    //寻找[i, n)区间里的最小值和i进行位置交换
    int minIndex = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[j] < arr[minIndex])
        minIndex = j;
    }
    swap(arr[i], arr[minIndex]);
  }
}

//插入排序，拥有比选择排序时间复杂度低的O(n^2)排序算法, 空间复杂度为1, 对近乎有序的数组排序效率极高，完全有序时进化为O(n)级别
template<typename T>
void insertionSort(T arr[], int n) {
  for (int i = 1; i < n; ++i) {
#if 0
    for (int j = i; j > 0 && arr[j] < arr[j-1]; --j)
        swap(arr[j], arr[j-1]);
#else
    T e = arr[i];
    int j = i-1;
    for (; j >= 0 && arr[j] > e; --j)
      arr[j + 1] = arr[j];
    arr[j+1] = e;
#endif
  }
}

//冒泡排序，是比选择排序时间复杂度高的O(n^2)排序算法, 空间复杂度为1, 比选择排序要慢，因为每次冒泡都涉及交换
template<typename T>
void bubbleSort(T arr[], int n) {
  for (int i = n - 1; i > 0; i--) {
    for (int j = 1; j <= i; j++) {
      if (arr[j - 1] > arr[j])
        swap(arr[j - 1], arr[j]);
    }
  }
}

int main() {
  int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  selectionSort(a, 10);
  for (auto i : a)
    cout << i << " ";
  cout << endl;

  float b[5] = {4.4f, 9.0f, 3.6f, 1.f, .2f};
  selectionSort(b, 5);
  for (auto i : b)
    cout << i << " ";
  cout << endl;

  string s[4] = {"hello", "World", "Jack", "Ques"};
  selectionSort(s, 4);
  for (auto i : s)
    cout << i << " ";
  cout << endl;

  struct Student stu[4] = {{"D", 90},
                           {"B", 95},
                           {"A", 95},
                           {"C", 100}};
  selectionSort(stu, 4);
  for (auto i : stu)
    cout << i << endl;

  int n = 10000;
  int *arr = SortTestHelper::generateRandomArray(n, 0, n);
  int *arr2 = SortTestHelper::dupArray(arr, n);
  int *arr3 = SortTestHelper::dupArray(arr, n);
  //selectionSort(arr, n);
  //SortTestHelper::printArray(arr, n);

  SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
  SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
  SortTestHelper::testSort("Bubble    Sort", bubbleSort, arr3, n);
  delete[] arr;
  delete[] arr2;
  delete[] arr3;

  return 0;
}