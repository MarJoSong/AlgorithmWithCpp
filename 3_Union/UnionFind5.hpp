//
// Created by Mars on 2021/6/30.
//

#ifndef INC_2_SEARCH__UNIONFIND5_HPP_
#define INC_2_SEARCH__UNIONFIND5_HPP_

#include <cassert>

namespace UF5 {

class UnionFind {
 private:
  int *parent;    //数组存的是父节点的索引
  int count;

 public:
  UnionFind(int n) {
	parent = new int[n];
	count = n;
	for (int i = 0; i < n; ++i) {
	  parent[i] = i;
	}
  }

  ~UnionFind() {
	delete[] parent;
  }

  int find(int p) {
	assert(p >= 0 && count > 0);
#if 0
	//路径压缩
	while (p != parent[p]) {
	  parent[p] = parent[parent[p]];
	  p = parent[p];
	}
#endif
	//查找的时间复杂度为O(1)，总体的时间复杂度近乎为O(1)
	if (p != parent[p])
	  parent[p] = find(parent[p]);
	return parent[p];
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

#endif //INC_2_SEARCH__UNIONFIND5_HPP_
