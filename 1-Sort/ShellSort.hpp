//
// Created by mars on 2021/6/22.
//

#ifndef INC_1_SORT__SHELLSORT_HPP_
#define INC_1_SORT__SHELLSORT_HPP_

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

#endif //INC_1_SORT__SHELLSORT_HPP_
