#include <iostream>
#include "headers/Graph.h"

int main(){

	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	std::cout << "\nDFS From Vertice 2:\n";
	g.v_DFS(2);

	std::cout << "\nDFS From All Vertices:\n";
	g.DFS();

}