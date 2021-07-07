//
// Created by mars on 2021/7/7.
//

#ifndef INC_4_GRAPH_CMAKE_BUILD_DEBUG_DENSEGRAPH_H_
#define INC_4_GRAPH_CMAKE_BUILD_DEBUG_DENSEGRAPH_H_

#include <vector>
#include <cassert>

using namespace std;

//稠密图 - 邻接矩阵
class DenseGraph {
 private:
  int n;//点的数量
  int e;//边的数量
  bool directed;//是否为有向图
  vector<vector<bool>> g;

 public:
  DenseGraph(int n, bool directed) {
	this->n = n;
	this->e = 0;
	this->directed = directed;
	for (int i = 0; i < n; ++i) {
	  g.push_back(vector<bool>(n, false));
	}
  }

  ~DenseGraph() {};

  int V() { return n; }
  int E() { return e; }

  bool hasEdge(int v, int w) {
	assert(v >= 0 && v < n);
	assert(w >= 0 && w < n);
	return g[v][w];
  }

  void addEdge(int v, int w) {
	assert(v >= 0 && v < n);
	assert(w >= 0 && w < n);

	if (hasEdge(v, w)) return;
	g[v][w] = true;
	if (!directed)
	  g[w][v] = true;

	e++;
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
	DenseGraph &G;
	int v;
	int index;

   public:
	//graph - 要迭代的图 , v - 要迭代的顶点
	adjIterator(DenseGraph &graph, int v) : G(graph) {
	  this->v = v;
	  index = -1;
	}

	int begin() {
	  index = -1;
	  return next();
	}

	int next() {
	  for (index += 1; index < G.V(); index++)
		if (G.g[v][index])
		  return index;
	  return -1;
	}

	bool end() {
	  return index >= G.V();
	}
  };

};

#endif //INC_4_GRAPH_CMAKE_BUILD_DEBUG_DENSEGRAPH_H_
