//
// Created by mars on 2021/6/17.
// 快速回忆可参考菜鸟教程 (https://www.runoob.com/data-structures/data-structures-tutorial.html)
//
#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

/**
 * 选择排序, 时间复杂度为O(n^2), 空间复杂度为1, 不稳定排序
 * @tparam T
 * @param arr
 * @param n
 * @return void
 */
template<typename T>
void selectionSort(T arr[], int n) {
  //优化: i的判断可以是i<n-1, 因为i若为n-1, j=n必不满足j<n
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

/**
 * 插入排序, 拥有比选择排序时间复杂度低的O(n^2)排序算法(优化swap), 空间复杂度为1,
 * 对近乎有序的数组排序效率极高, 完全有序时进化为O(n)级别, 稳定排序
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void insertionSort(T arr[], int n) {
  for (int i = 1; i < n; ++i) {
#if 0
    for (int j = i; j > 0 && arr[j] < arr[j-1]; --j)
        swap(arr[j], arr[j-1]);
#else
    T e = arr[i];
    int j = i - 1;
    for (; j >= 0 && arr[j] > e; --j)
      arr[j + 1] = arr[j];
    arr[j + 1] = e;
#endif
  }
}

template<typename T>
void auxInsertionSort(T arr[], int l, int r) {
  for (int i = l + 1; i <= r; ++i) {
    T e = arr[i];
    int j = i;
    for (; j > l && arr[j - 1] > e; --j)
      arr[j] = arr[j - 1];
    arr[j] = e;
  }
}

/**
 * 希尔排序(缩小增量排序), 改进版的插入排序，时间复杂度为 O(n^(1.3—2)), 空间复杂度为常数阶 O(1), 如果插入排序的分组粒度为 1,
 * 那么希尔排序的初始分组粒度 gap=arr.length()/2, 逐次将分组粒度逼近为 1, 不稳定排序。
 * 希尔排序没有时间复杂度为 O(n(logn))的快速排序算法快, 因此对中等大小规模表现良好, 但对规模非常大的数据排序不是最优选择,
 * 总之比一般 O(n^2 ) 复杂度的算法快得多。
 */
template<typename T>
void shellSort(T arr[], int n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; ++i) {
#if 0
      for (int j=i;j-gap>=0 && arr[j]< arr[j-gap]; j-=gap) {
        swap(arr[j],arr[j-gap]);
      }
#else
      T tmp = arr[i];
      int j = i;
      for (; j - gap >= 0 && tmp < arr[j - gap]; j -= gap) {
        arr[j] = tmp;
      }
      arr[j] = tmp;
#endif
    }
  }
}

/**
 * 冒泡排序, 是比选择排序时间复杂度高的O(n^2)排序算法, 空间复杂度为1,
 * 比选择排序要慢, 因为每次冒泡都涉及交换, 稳定排序
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void bubbleSort(T arr[], int n) {
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[j + 1])
        swap(arr[j + 1], arr[j]);
    }
  }
}

/**
 * 归并排序归并函数, 将arr[l...mid]和arr[mid+1...r]两个数组进行排序
 * @tparam T
 * @param arr
 * @param l
 * @param mid
 * @param r
 */
template<typename T>
void __merge(T arr[], int l, int mid, int r) {
  T *aux = new T[r - l + 1];
  for (int i = l; i <= r; ++i) {
    aux[i - l] = arr[i];
  }

  int i = l, j = mid + 1;
  for (int k = l; k <= r; ++k) {
    if (i > mid) {
      arr[k] = aux[j - l];
      j++;
    } else if (j > r) {
      arr[k] = aux[i - l];
      i++;
    } else if (aux[i - l] < aux[j - l]) {
      arr[k] = aux[i - l];
      i++;
    } else {
      arr[k] = aux[j - l];
      j++;
    }
  }

  delete[] aux;
}

/**
 * 归并排序递归函数, 对arr[l...r]的范围进行排序
 * @tparam T
 * @param arr
 * @param l
 * @param r
 */
template<typename T>
void __mergeSort(T arr[], int l, int r) {
  //优化一: 在数组待归并元素范围比较小时，转而使用插入排序
  if (r - l <= 15) {
    auxInsertionSort(arr, l, r);
    return;
  }

  int mid = l + (r - l) / 2;
  __mergeSort(arr, l, mid);
  __mergeSort(arr, mid + 1, r);
  //优化一: 若数组arr[l...r]已经有序，则不在归并
  if (arr[mid] > arr[mid + 1])
    __merge(arr, l, mid, r);
}

/**
 * 归并排序, O(nlogn)时间复杂度的排序算法, 空间复杂度为n,
 * 需要辅助数组, 不稳定排序
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void mergeSort(T arr[], int n) {
  __mergeSort(arr, 0, n - 1);
}

/**
 * 自底向上的归并排序
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void mergeSortB2T(T arr[], int n) {
  for (int sz = 1; sz <= n; sz += sz) {
    //for (int i = 0; i < n; i += sz + sz) {
    //归并的条件是保证第二个数组的存在, i+sz<n保证了第二个数组的存在
    for (int i = 0; i + sz < n; i += sz + sz) {
      //对arr[i...i+sz-1]和arr[i+sz...i+sz*2-1]进行归并
      __merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
    }
  }
}

template<typename T>
int partition(T arr[], int l, int r) {
  T v = arr[l];
  int i = l + 1, j = l + 1;
  for (int k = l + 1; k < r; ++k) {
    if (arr[k] < v) {
      swap(arr[k], arr[j]);
      ++j;
    }
  }
  swap(arr[l], arr[j - 1]);

  return j - 1;
}

template<typename T>
void __quickSort(T arr[], int l, int r) {
  if (l >= r) {
    return;
  }

  int mid = partition(arr, l, r);
  __quickSort(arr, l, mid);
  __quickSort(arr, mid + 1, r);
}

template<typename T>
void quickSort(T arr[], int n) {
  __quickSort(arr, 0, n);
}

int main() {
  /*
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
  */
  int n = 40000000;
  int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
  //int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, 0);
  //int *arr2 = SortTestHelper::copyArray(arr1, n);
  //int *arr3 = SortTestHelper::copyArray(arr1, n);
  //int *arr4 = SortTestHelper::copyArray(arr1, n);
  int *arr5 = SortTestHelper::copyArray(arr1, n);
  int *arr6 = SortTestHelper::copyArray(arr1, n);
  //selectionSort(arr, n);
  //SortTestHelper::printArray(arr, n);

  //SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
  //SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
  //SortTestHelper::testSort("Bubble    Sort", bubbleSort, arr3, n);
  //SortTestHelper::testSort("Shell     Sort", shellSort, arr4, n);
  //SortTestHelper::testSort("Merge     Sort", mergeSort, arr5, n);
  SortTestHelper::testSort("MergeB2T  Sort", mergeSortB2T, arr5, n);
  SortTestHelper::testSort("Quick     Sort", quickSort, arr6, n);
  delete[] arr1;
  //delete[] arr2;
  //delete[] arr3;
  //delete[] arr4;
  delete[] arr5;
  delete[] arr6;

  return 0;
}