//
// Created by mars on 2021/6/22.
//

#ifndef INC_1_SORT__SELECTIONSORT_HPP_
#define INC_1_SORT__SELECTIONSORT_HPP_

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

#endif //INC_1_SORT__SELECTIONSORT_HPP_
