//
// Created by Mars on 2021/6/30.
//

#ifndef INC_2_SEARCH__UNIONFIND2_HPP_
#define INC_2_SEARCH__UNIONFIND2_HPP_

#include <cassert>

namespace UF2 {

class UnionFind {
 private:
  int *parent; //数组存的是父节点的索引
  int count;

 public:
  UnionFind(int n) {
	parent = new int[n];
	count = n;
	for (int i = 0; i < n; ++i)
	  parent[i] = i;
  }

  ~UnionFind() {
	delete[] parent;
  }

  int find(int p) {
	assert(p >= 0 && count > 0);
	while (p != parent[p]) {
	  p = parent[p];
	}
	return p;
  }

  void unionElements(int p, int q) {
	int pRoot = find(p);
	int qRoot = find(q);
	if (pRoot == qRoot) return;
	parent[pRoot] = qRoot;
  }

  bool isConnected(int p, int q) {
	return find(p) == find(q);
  }
};

}

#endif //INC_2_SEARCH__UNIONFIND2_HPP_
