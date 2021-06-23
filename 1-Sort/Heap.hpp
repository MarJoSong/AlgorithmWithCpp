//
// Created by Mars on 2021/6/23.
//

#ifndef INC_1_SORT__HEAP_HPP_
#define INC_1_SORT__HEAP_HPP_

template<typename T>
class Heap {
 public:
  Heap(int n) {
    arr = new T[n + 1];
    int capacity = n;
    count = 0;
  }

  ~Heap() {
    delete[]arr;
  }

  void shiftUp(T n) {
    assert(count + 1 <= capacity);
    arr[++count] = n;

    int k = count;
    while (k > 1 && arr[k / 2] < arr[k]) {
      swap(arr[k / 2], arr[k]);
      k /= 2;
    }
  }

  void printArr() {
    for (int i = 1; i <= count; ++i) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

 private:
  T *arr;
  int count;
  int capacity;
};

#endif //INC_1_SORT__HEAP_HPP_
