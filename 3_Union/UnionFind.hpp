//
// Created by Mars on 2021/6/30.
//

#ifndef INC_2_SEARCH__UNIONFIND_HPP_
#define INC_2_SEARCH__UNIONFIND_HPP_

#include <cassert>

namespace UF1 {

class UnionFind {
 private:
  int *id;
  int count;

 public:
  UnionFind(int n) {
    count = n;
    id = new int[n];
    for (int i = 0; i < n; ++i)
      id[i] = i;
  }

  ~UnionFind() {
    delete[] id;
  }

  int find(int p) {
    assert(p >= 0 && count > 0);
    return id[p];
  }

  void unionElements(int p, int q) {
    int pId = find(p);
    int qId = find(q);
    if (pId == qId) return;
    for (int i = 0; i < count; ++i) {
      if (pId == id[i])
        id[i] = qId;
    }
  }

  bool isConnected(int p, int q) {
    return find(p) == find(q);
  }
};

}

#endif //INC_2_SEARCH__UNIONFIND_HPP_
