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

  struct Student stu[4] = {{"D", 90}, {"B", 95}, {"A", 95}, {"C", 100}};
  selectionSort(stu, 4);
  for (auto i : stu)
	cout << i << endl;

  int n = 100000;
  int *arr = SortTestHelper::generateRandomArray(n, 0, n);
  selectionSort(arr, n);
  //SortTestHelper::printArray(arr, n);
  SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
  delete[] arr;

  return 0;
}