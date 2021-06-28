//
// Created by mars on 2021/6/27.
//

#include <iostream>
#include "binarySearch.hpp"

int main() {
  int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::cout << binarySearch(a1, 10, 7) << std::endl;

  int a2[] = {0, 1, 2, 3, 4, 8, 8, 8, 8, 9};

  std::pair<int, int> index = binarySearchFloorAndCeil(a2, 10, 7);
  std::cout << index.first << " " << index.second << std::endl;

  return 0;
}

