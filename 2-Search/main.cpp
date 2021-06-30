//
// Created by mars on 2021/6/27.
//

#include <iostream>
#include <ctime>
#include <windows.h>
#include "binarySearch.hpp"

int main() {
  int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::cout << binarySearch(a1, 10, 7) << std::endl;

  int a2[] = {0, 1, 2, 3, 4, 8, 8, 8, 8, 9};

  std::pair<int, int> index = binarySearchFloorAndCeil(a2, 10, 7);
  std::cout << index.first << " " << index.second << std::endl;

  auto *bst = new BinarySearchTree<int, int>();

  srand(time(NULL));
  for (int i = 0; i < 15; i++) {
    i = rand() % 15;
    bst->insert(i, 1);
  }

  std::cout << "levelorder: ";
  bst->levelOrder();
  std::cout << "inOrder: ";
  bst->inOrder();
  std::cout << bst->size() << std::endl;

  bst->removeMin();
  bst->removeMax();
  std::cout << "inOrder: ";
  bst->inOrder();
  std::cout << bst->size() << std::endl;

  bst->remove(10);
  std::cout << "inOrder: ";
  bst->inOrder();
  std::cout << bst->size();

  return 0;
}

