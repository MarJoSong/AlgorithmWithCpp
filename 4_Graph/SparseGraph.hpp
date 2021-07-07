//
// Created by mars on 2021/7/7.
//

#ifndef INC_4_GRAPH_CMAKE_BUILD_DEBUG_SPARESGRAPH_H_
#define INC_4_GRAPH_CMAKE_BUILD_DEBUG_SPARESGRAPH_H_

#include <vector>
#include <cassert>

using namespace std;

//稀疏图 - 邻接表
class SparseGraph {
 private:
  int n;//点的数量
  int m;//边的数量
  bool directed;//是否为有向图
  vector<vector<int>> g;

 public:
  SparseGraph(int n, bool directed) {
	this->n = n;
	this->m = 0;
	this->directed = directed;
	for (int i = 0; i < n; ++i) {
	  g.push_back(vector<int>());
	}
  }

  ~SparseGraph() {};

  int V() { return n; }
  int E() { return m; }

  bool hasEdge(int v, int w) {
	assert(v >= 0 && v < n);
	assert(w >= 0 && w < n);

	for (int i = 0; i < g[v].size(); ++i)
	  if (g[v][i] == w)
		return true;
	return false;
  }

  void addEdge(int v, int w) {
	assert(v >= 0 && v < n);
	assert(w >= 0 && w < n);

	//if (hasEdge(v, w)) return;
	g[v].push_back(w);
	if (!directed)
	  g[w].push_back(v);
	m++;
  }

  void show() {
	for (int i = 0; i < n; i++) {
	  cout << "vertex " << i << ":\t";
	  for (int j = 0; j < g[i].size(); j++)
		cout << g[i][j] << "\t";
	  cout << endl;
	}
  }

  //相邻边迭代器
  class adjIterator {
   private:
	SparseGraph &G;
	int v;
	int index;

   public:
	//graph - 要迭代的图 , v - 要迭代的顶点
	adjIterator(SparseGraph &graph, int v) : G(graph) {
	  this->v = v;
	  index = 0;
	}

	int begin() {
	  index = 0;
	  if (this->G.g[v].size())
		return G.g[v][index];
	}

	int next() {
	  index++;
	  if (index < G.g[v].size())
		return G.g[v][index];
	  return -1;
	}

	bool end() {
	  return index >= G.g[v].size();
	}
  };

};

#endif //INC_4_GRAPH_CMAKE_BUILD_DEBUG_SPARESGRAPH_H_
