//
// Created by mars on 2021/6/22.
//

#ifndef INC_1_SORT__QUICKSORT_HPP_
#define INC_1_SORT__QUICKSORT_HPP_

//对arr[l...r]内的元素进行二分操作
//返回值pos, 使得arr[l...pos-1]<arr[pos], arr[pos+1...r]>=arr[pos]
template<typename T>
int __partition(T arr[], int l, int r) {
  T v = arr[l];
  /*
   * ----------------------------------------
   * |v|...<v...|....>v....|................|
   *  l        j            i
   * l指向数组最左边位置, j指向小于v数组的最右边, i之后大于v数组最右边的后一个元素
   * i = l+1, 合理初始化变量, 使得满足以下条件arr[l+1...j] < v, arr[j+1...i) > v
   * 令j = l, 满足上述条件且各数组初始个数为 0
   */
  //
  int j = l;
  for (int i = l + 1; i <= r; ++i) {
	if (arr[i] < v) {
	  swap(arr[i], arr[++j]);
	}
  }
  swap(arr[l], arr[j]);

  return j;
}

//对arr[l...r]内的元素进行快速排序
template<typename T>
void __quickSort(T arr[], int l, int r) {
  if (l >= r) {
	return;
  }
  //优化一: 在数组待归并元素范围比较小时，转而使用插入排序
  /*
  if (r - l <= 15) {
	auxInsertionSort(arr, l, r);
	return;
  }
   */

  int pos = __partition(arr, l, r);
  __quickSort(arr, l, pos - 1);
  __quickSort(arr, pos + 1, r);
}

/**
 * 快速排序, O(nlogn)时间复杂度的排序算法, 空间复杂度为1
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void quickSort(T arr[], int n) {
  __quickSort(arr, 0, n - 1);
}

#endif //INC_1_SORT__QUICKSORT_HPP_
