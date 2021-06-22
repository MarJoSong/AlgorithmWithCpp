//
// Created by mars on 2021/6/22.
//

#ifndef INC_1_SORT__INSERTIONSORT_HPP_
#define INC_1_SORT__INSERTIONSORT_HPP_

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

#endif //INC_1_SORT__INSERTIONSORT_HPP_
