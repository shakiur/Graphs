#include <list>

class Graph{
	int vertices;
	std::list<int>* adjacent;
	void DFSUtil(int, bool[]);

	public:
		Graph(int);
		void addEdge(int, int);
		void DFS();
		void v_DFS(int);
};

Graph::Graph(int n){
	vertices = n;
	adjacent = new std::list<int>[n];
}

void Graph::addEdge(int v1, int v2){
	adjacent[v1].push_back(v2);
}

void Graph::DFSUtil(int v, bool visited[]){
	visited[v] = true;
	std::cout << v << " ";

	// Visit all vertices connected that are not visited
	std::list<int>::iterator itr;

	for(itr = adjacent[v].begin(); itr != adjacent[v].end(); itr++){
		if(!visited[*itr])
			DFSUtil(*itr, visited);
	}
}

void Graph::v_DFS(int v){
	bool * visited = new bool[vertices];

	// Set all visits to false
	for(int i = 0; i < vertices; i++)
		visited[i] = false;

	// Find all connected vertices
	DFSUtil(v, visited);

	std::cout << std::endl;

}

void Graph::DFS(){
	bool * visited = new bool[vertices];

	// Set all visits to false
	for(int i = 0; i < vertices; i++)
		visited[i] = false;

	// Visit each vertices to print its adjacencies
	for(int i = 0; i < vertices; i++){
		if(visited[i] == false){
			DFSUtil(i, visited);
			std::cout << std::endl;
		}
	}

}