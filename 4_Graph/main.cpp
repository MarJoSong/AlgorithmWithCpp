#include <iostream>
#include <cstdlib>
#include "DenseGraph.hpp"
#include "SparseGraph.hpp"
#include "ReadGraph.hpp"

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

  string filename = "testG1.txt";

  SparseGraph g1(13, false);
  ReadGraph<SparseGraph> readGraph1(g1, filename);
  g1.show();

  DenseGraph g2(13, false);
  ReadGraph<DenseGraph> readGraph2(g2, filename);
  g2.show();

  return 0;
}
