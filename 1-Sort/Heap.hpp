//
// Created by Mars on 2021/6/23.
//

#ifndef INC_1_SORT__HEAP_HPP_
#define INC_1_SORT__HEAP_HPP_

template<typename T>
void printHeap(T arr, int n) {
  int flag = 1;
  int max = 1;
  while (max < n) max <<= 1;
  max <<= 1;
  cout << "The structure of Heap:";
  for (int i = 0; i < n; ++i) {
	if (i+1 == flag) {
	  cout << endl;
	  flag <<= 1;
	  max /= 2;
	  for (int k = 0; k < max / 2; ++k)
		cout << "  ";
	}
	cout << setw(2) << arr[i];
	for (int k = 0; k < max - 1; ++k)
	  cout << "  ";
  }
  cout << endl;
}

template<typename T>
void __shiftDown(T arr[], int n, int k) {
  while (2 * k + 1 < n) {
	int j = 2 * k + 1;
	if (j + 1 < n && arr[j + 1] > arr[j]) {
	  ++j;
	}
	if (arr[j] > arr[k]) {
	  swap(arr[j], arr[k]);
	} else {
	  break;
	}
	k = j;
  }
}
/*
 * 原地堆排序
 */
template<typename T>
void heapSort(T arr[], int n) {
  for (int i = (n - 1) / 2; i >= 0; --i) {
	__shiftDown(arr, n, i);
  }

  for (int i = n - 1; i > 0; --i) {
	swap(arr[i], arr[0]);
	__shiftDown(arr, i, 0);
  }
}

template<typename Item>
class MaxHeap {
 private:
  Item *data;
  int count;
  int capacity;

  void shiftUp(Item n) {
	data[++count] = n;

	int k = count;
	while (k > 1 && data[k / 2] < data[k]) {
	  swap(data[k / 2], data[k]);
	  k /= 2;
	}
  }

  void shiftDown(Item n) {
	while (n * 2 <= count) {
	  int j = n * 2;
	  if (j + 1 <= count && data[j + 1] > data[j]) {
		++j;
	  }
	  if (data[n] < data[j])
		swap(data[n], data[j]);
	  n = j;
	}
  }

 public:
  MaxHeap(int n) {
	data = new Item[n + 1];
	capacity = n;
	count = 0;
  }

  MaxHeap(Item arr[], int n) {
	data = new Item[n + 1];
	capacity = n;
	count = n;
	copy(arr, arr + n, this->data + 1);

	//heapify的算法复杂度为O(n)
	for (int i = n / 2; i >= 1; i--) {
	  shiftDown(i);
	  //printHeap();
	}
  }

  ~MaxHeap() {
	delete[]data;
  }

  void insert(Item n) {
	assert(count + 1 <= capacity);
	shiftUp(n);
  }

  int extractMax(void) {
	assert(count >= 1);
	int ret = data[1];
	data[1] = data[count--];
	if (count > 1)
	  shiftDown(1);

	return ret;
  }

  void printHeap() {
	int flag = 1;
	int max = 1;
	while (max < count) max <<= 1;
	max <<= 1;
	cout << "The structure of Heap:";
	for (int i = 1; i <= count; ++i) {
	  if (i == flag) {
		cout << endl;
		flag <<= 1;
		max /= 2;
		for (int k = 0; k < max / 2; ++k)
		  cout << "  ";
	  }
	  cout << setw(2) << data[i];
	  for (int k = 0; k < max - 1; ++k)
		cout << "  ";
	}
	cout << endl;
  }

};

/**
 * 将n个元素插入到一个空堆中，算法复杂度是O(nlogn)
 * 将n个元素extractMax的算法复杂度也是O(nlogn)
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void heapSort1(T arr[], int n) {
  MaxHeap<T> maxheap = MaxHeap<T>(n);
  for (int i = 0; i < n; ++i) {
	maxheap.insert(arr[i]);
  }

  for (int i = n - 1; i >= 0; i--) {
	arr[i] = maxheap.extractMax();
  }
}

template<typename T>
void heapSort2(T arr[], int n) {
  MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
  for (int i = n - 1; i >= 0; i--) {
	arr[i] = maxheap.extractMax();
  }
}

#endif //INC_1_SORT__HEAP_HPP_
