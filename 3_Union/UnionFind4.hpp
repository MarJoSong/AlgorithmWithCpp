//
// Created by Mars on 2021/6/30.
//

#ifndef INC_2_SEARCH__UNIONFIND4_HPP_
#define INC_2_SEARCH__UNIONFIND4_HPP_

#include <cassert>

namespace UF4 {

class UnionFind {
 private:
  int *parent;    //数组存的是父节点的索引
  int *rank;    //sz[i]表示以i为根节点的数的层数
  int count;

 public:
  UnionFind(int n) {
	parent = new int[n];
	rank = new int[n];
	count = n;
	for (int i = 0; i < n; ++i) {
	  parent[i] = i;
	  rank[i] = 1;
	}
  }

  ~UnionFind() {
	delete[] parent;
	delete[] rank;
  }

  int find(int p) {
	assert(p >= 0 && count > 0);
	while (p != parent[p]) {
	  parent[p] = parent[parent[p]];
	  p = parent[p];
	}
	return p;
  }

  void unionElements(int p, int q) {
	int pRoot = find(p);
	int qRoot = find(q);
	if (pRoot == qRoot) return;

	if (rank[pRoot] < rank[qRoot]) {
	  parent[pRoot] = qRoot;
	} else if (rank[pRoot] > rank[qRoot]) {
	  parent[qRoot] = pRoot;
	} else {
	  parent[pRoot] = qRoot;
	  rank[qRoot]++;
	}
  }

  bool isConnected(int p, int q) {
	return find(p) == find(q);
  }
};

}

#endif //INC_2_SEARCH__UNIONFIND4_HPP_
