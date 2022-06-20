#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
	int M; 

	list<int>* adj;

	void topologicalSort(int m, bool visited[], stack<int>& Stack);

public:
	Graph(int M); 

	void addEdge(int m, int n);

	void topological();
};

Graph::Graph(int M)
{
	this->M = M;
	adj = new list<int>[M];
}

void Graph::addEdge(int m, int n)
{
	adj[m].push_back(n); 
}

void Graph::topologicalSort(int m, bool visited[],stack<int>& Stack)
{
	visited[m] = true;

	list<int>::iterator i;
	for (i = adj[m].begin(); i != adj[m].end(); ++i)
		if (!visited[*i])
			topologicalSort(*i, visited, Stack);

	Stack.push(m);
}

void Graph::topological()
{
	stack<int> Stack;

	bool* visited = new bool[M];
	for (int i = 0; i < M; i++)
		visited[i] = false;

	for (int i = 0; i < M; i++)
		if (visited[i] == false)
			topologicalSort(i, visited, Stack);

	while (Stack.empty() == false) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

int main()
{
	Graph g(5);
	g.addEdge(3, 1);
	g.addEdge(4, 3);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 2);

	cout << "Following is a Topological Sort of the given graph: \n ";
	g.topological();

	return 0;
}