//
// Created by Mars on 2021/6/30.
//

#ifndef INC_2_SEARCH__UNIONFIND3_HPP_
#define INC_2_SEARCH__UNIONFIND3_HPP_

#include <cassert>

namespace UF3 {

class UnionFind {
 private:
  int *parent;    //数组存的是父节点的索引
  int *sz;    //sz[i]表示以i为根节点的集合节点的总数量
  int count;

 public:
  UnionFind(int n) {
	parent = new int[n];
	sz = new int[n];
	count = n;
	for (int i = 0; i < n; ++i) {
	  parent[i] = i;
	  sz[i] = 1;
	}
  }

  ~UnionFind() {
	delete[] parent;
	delete[] sz;
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

	if (sz[pRoot] < sz[qRoot]) {
	  parent[pRoot] = qRoot;
	  sz[qRoot] += sz[pRoot];
	} else {
	  parent[qRoot] = pRoot;
	  sz[pRoot] += sz[qRoot];
	}
  }

  bool isConnected(int p, int q) {
	return find(p) == find(q);
  }
};

}

#endif //INC_2_SEARCH__UNIONFIND3_HPP_
