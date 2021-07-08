//
// Created by mars on 2021/7/8.
//

#ifndef INC_4_GRAPH__COMPONENT_HPP_
#define INC_4_GRAPH__COMPONENT_HPP_

template<typename Graph>
class Component {
 private:
  Graph &G;
  bool *visited;//节点是否被访问过
  int ccount;//联通分量
  int *id;//联通节点表示，id一样，表示同属一个联通分量

  void dfs(int v) {
    visited[v] = true;
	id[v] = ccount;

    typename Graph::adjIterator adj(G, v);
    for (int i=adj.begin(); !adj.end(); i = adj.next()) {
      if (!visited[i])
        dfs(i);
    }
  }

 public:
  Component(Graph&graph) : G(graph) {
    visited = new bool[G.V()];
    id = new int[G.V()];
    ccount = 0;
	for (int i = 0; i < G.V(); ++i) {
	  visited[i] = false;
	  id[i] = -1;
	}
	for (int i = 0; i< G.V(); i++) {
	  if (!visited[i]) {
		dfs(i);
		ccount++;
	  }
	}
  }

  ~Component() {
    delete[] visited;
    delete[] id;
  }

  int count() {
    return ccount;
  }

  bool isConnected(int v, int w) {
	assert(v>=0 && v < G.V());
	assert(w>=0 && w < G.V());
	return id[v] == id[w];
  }
};

#endif //INC_4_GRAPH__COMPONENT_HPP_
