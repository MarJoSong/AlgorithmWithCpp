//
// Created by mars on 2021/6/22.
//

#ifndef INC_1_SORT__MERGESORT_HPP_
#define INC_1_SORT__MERGESORT_HPP_

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

#endif //INC_1_SORT__MERGESORT_HPP_
