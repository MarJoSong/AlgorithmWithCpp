//
// Created by mars on 2021/6/22.
//

#ifndef INC_1_SORT__BUBBLESORT_HPP_
#define INC_1_SORT__BUBBLESORT_HPP_

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

#endif //INC_1_SORT__BUBBLESORT_HPP_
