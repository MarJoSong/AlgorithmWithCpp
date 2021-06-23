//
// Created by mars on 2021/6/22.
//

#ifndef INC_1_SORT__QUICKSORT_HPP_
#define INC_1_SORT__QUICKSORT_HPP_

//对arr[l...r]内的元素进行二分操作
//返回值pos, 使得arr[l...pos-1]<arr[pos], arr[pos+1...r]>=arr[pos]
template<typename T>
int __partition(T arr[], int l, int r) {

  /*
   * 对基本有序的数组, 如果每次去第一个数组值作为二分基准,
   * 会导致二分后的两个数组数量及其不均匀, 严重时(数组已经有序)时间复杂度退化到O(n^2)
   * 优化: 1.随机选点; 2.三点取中
   */
#if 0
  //随机选点
  swap(arr[l], arr[rand() % (r - l + 1) + l]);
#else
  //三点[l, mid, r]取中值
  int mid = l + (r - l) / 2;
  if (arr[l] > arr[r]) swap(arr[l], arr[r]);
  if (arr[mid] > arr[r]) swap(arr[mid], arr[r]);
  if (arr[mid] > arr[l]) swap(arr[mid], arr[l]);
#endif

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
  //优化: 在数组待归并元素范围比较小时，转而使用插入排序
  if (r - l <= 15) {
    auxInsertionSort(arr, l, r);
    return;
  }

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
  srand(time(NULL));
  __quickSort(arr, 0, n - 1);
}

/**********************************************************************
 * 两路快速排序, 实现是对arr[l...r]内的元素进行两路二分
 * 当待排序数组包含大量重复性元素时，如1,2,2...2,3, 取中值2,
 * 根据数组arr1 < 2 和 arr2 >= 2的条件
 * 二分后变成[1]和[2,2...2,3]两个极不均匀数组, 时间复杂度退化
 * 解决的策略是, 将中值均分到两个数组中
 *********************************************************************/
template<typename T>
int __partition2Ways(T arr[], int l, int r) {

  int mid = l + (r - l) / 2;
  if (arr[l] > arr[r]) swap(arr[l], arr[r]);
  if (arr[mid] > arr[r]) swap(arr[mid], arr[r]);
  if (arr[mid] > arr[l]) swap(arr[mid], arr[l]);

  T v = arr[l];
  /*
   * 设置初值, 使得 arr[l+1, i) <=v 和 arr(j, r] >=v
   */
  int i = l + 1;
  int j = r;
  while (true) {
    while (arr[i] < v) i++;
    while (arr[j] > v) j--;
    if (i >= j) {
      break;
    }
    swap(arr[i], arr[j]);
    i++;
    j--;
  }
  swap(arr[l], arr[j]);

  return j;
}

template<typename T>
void __quickSort2Ways(T arr[], int l, int r) {
  if (l >= r) {
    return;
  }
  //优化: 在数组待归并元素范围比较小时，转而使用插入排序
  if (r - l <= 15) {
    auxInsertionSort(arr, l, r);
    return;
  }

  int pos = __partition2Ways(arr, l, r);
  __quickSort2Ways(arr, l, pos - 1);
  __quickSort2Ways(arr, pos + 1, r);
}

/**
 * 两路快速排序
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void quickSort2Ways(T arr[], int n) {
  __quickSort2Ways(arr, 0, n - 1);
}

/**********************************************************************
 * 三路快速排序, 实现是对arr[l...r]内的元素进行三分
 * 当待排序数组包含大量重复性元素时，如1,2,2...2,3, 取中值2,
 * 根据数组arr1 < 2, arr = 2 和 arr3 > 2的条件
 * 三分成[1], [2,2...2]和[3]
 * 下一步只对arr1和arr3继续进行三路分段
 *********************************************************************/
template<typename T>
int __partition3Ways(T arr[], int l, int r) {

  int mid = l + (r - l) / 2;
  if (arr[l] > arr[r]) swap(arr[l], arr[r]);
  if (arr[mid] > arr[r]) swap(arr[mid], arr[r]);
  if (arr[mid] > arr[l]) swap(arr[mid], arr[l]);

  T v = arr[l];
  /*
   * 设置初值, 使得 arr[l+1, i) <=v 和 arr(j, r] >=v
   */
  int i = l + 1;
  int j = r;
  while (true) {
    while (arr[i] < v) i++;
    while (arr[j] > v) j--;
    if (i >= j) {
      break;
    }
    swap(arr[i], arr[j]);
    i++;
    j--;
  }
  swap(arr[l], arr[j]);

  return j;
}

template<typename T>
void __quickSort3Ways(T arr[], int l, int r) {
  if (l >= r) {
    return;
  }
  //优化: 在数组待归并元素范围比较小时，转而使用插入排序
  if (r - l <= 15) {
    auxInsertionSort(arr, l, r);
    return;
  }

  int mid = l + (r - l) / 2;
  if (arr[l] > arr[r]) swap(arr[l], arr[r]);
  if (arr[mid] > arr[r]) swap(arr[mid], arr[r]);
  if (arr[mid] > arr[l]) swap(arr[mid], arr[l]);
  //int pos = __partition2Ways(arr, l, r);
  T v = arr[l];
  /*
   * 设置初值, 使得 arr[l+1, i] <v 和 arr[j, r] >v
   */
  int i = l;
  int j = r + 1;
  int k = l + 1;
  while (k < j) {
    if (arr[k] < v) {
      i++;
      swap(arr[k], arr[i]);
      k++;
    } else if (arr[k] > v) {
      j--;
      swap(arr[k], arr[j]);
    } else {
      k++;
    }
  }
  swap(arr[l], arr[i]);

  __quickSort3Ways(arr, l, i-1);
  __quickSort3Ways(arr, j, r);
}

/**
 * 三路快速排序
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void quickSort3Ways(T arr[], int n) {
  __quickSort3Ways(arr, 0, n - 1);
}

#endif //INC_1_SORT__QUICKSORT_HPP_
