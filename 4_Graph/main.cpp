#include <iostream>
#include "DenseGraph.hpp"
#include "SparseGraph.hpp"
#include "ReadGraph.hpp"
#include "Component.hpp"
#include "Path.hpp"
#include "ShortestPath.hpp"

using namespace std;

int main() {
#if 0
  int N = 20;
  int M = 100;

  srand(time(NULL));

  SparseGraph sg(N, false);
  for (int i = 0; i < M; i++) {
	int a = rand() % N;
	int b = rand() % N;
	sg.addEdge(a, b);
  }

  cout << "for_each SparseGraph" << endl;
  //O(E),有多少条边就遍历多少次
  for (int v = 0; v < N; v++) {
	cout << v << " : ";
	SparseGraph::adjIterator adj(sg, v);
	for (int w = adj.begin(); !adj.end(); w = adj.next())
	  cout << w << " ";
	cout << endl;
  }
  cout << endl;


  DenseGraph dg(N, false);

  for (int i = 0; i < M; i++) {
	int a = rand() % N;
	int b = rand() % N;
	dg.addEdge(a, b);
  }

  cout << "for_each DenseGraph" << endl;
  //O(V^2),复杂度是点数量的平方
  for (int v = 0; v < N; v++) {
	cout << v << " : ";
	DenseGraph::adjIterator adj(dg, v);
	for (int w = adj.begin(); !adj.end(); w = adj.next())
	  cout << w << " ";
	cout << endl;
  }
  cout << endl;
#endif
#if 0
  DenseGraph g2(13, false);
  ReadGraph<DenseGraph> readGraph2(g2, filename);
  g2.show();
#endif
#if 0
  string filename1 = "testG1.txt";
  SparseGraph g1(13, false);
  ReadGraph<SparseGraph> readGraph1(g1, filename1);
  Component<SparseGraph> component1(g1);
  cout << "TestG1.txt, Component Count: " << component1.count() << endl;
#endif


  string filename1 = "testG2.txt";
  SparseGraph g1(7, false);
  ReadGraph<SparseGraph> readGraph1(g1, filename1);
  Component<SparseGraph> component1(g1);
  cout << "TestG2.txt, Component Count: " << component1.count() << endl;

  Path<SparseGraph> dfs1(g1, 0);
  cout << "DFS: ";
  dfs1.showPath(6);

  ShortestPath<SparseGraph> bfs1(g1, 0);
  cout << "BFS: " << endl;
  bfs1.showPath(6);
  cout << "Shortest path length: " << bfs1.length(6);

  string filename2 = "testG3.txt";
  SparseGraph g2(8, false);
  ReadGraph<SparseGraph> readGraph2(g2, filename2);
  Component<SparseGraph> component2(g2);
  cout << "TestG2.txt, Component Count: " << component2.count() << endl;

  Path<SparseGraph> dfs2(g2, 0);
  cout << "DFS: ";
  dfs2.showPath(7);

  ShortestPath<SparseGraph> bfs2(g2, 0);
  cout << "BFS: " << endl;
  bfs2.showPath(7);
  cout << "Shortest path length: " << bfs2.length(7);

  return 0;
}
