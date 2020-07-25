#include <bits/stdc++.h>

using namespace std;

class Graph
{
	private:
		unordered_map<int, unordered_set<int>> graph;
	public:
		Graph();
		void undirected();
		bool undirectedUtil(int, vector<bool>&, int);
		void directed();
		bool directedUtil(int, vector<bool>&, vector<bool>&);
};

Graph::Graph()
{
	graph[0].insert(1);
	graph[1].insert(0);
	graph[0].insert(2);
	graph[2].insert(0);
	graph[1].insert(3);
	graph[3].insert(1);
	graph[1].insert(4);
	graph[4].insert(1);
	graph[2].insert(5);
	graph[5].insert(2);
	graph[4].insert(5);
	graph[5].insert(4);
}

void Graph::undirected()
{
	vector<bool> visited(6, false);
	bool flag = false;
	for(int i = 0; i < 6; i++)
	{
		if(visited[i] == false)
		{
			if(undirectedUtil(i, visited, -1))
			{
				flag = true;
				break;
			}
		}
	}

	if(flag == true)
		cout << "Cycle Detected";
	else
		cout << "Cycle not detected";
}

bool Graph::undirectedUtil(int curr, vector<bool>& visited, int par)
{
	visited[curr] = true;
	bool cycle = false;
	for(auto v : graph[curr])
	{
		if(par == v)
			continue;
		if(visited[v] == true)
		{
			cycle = true;
			break;
		}
		if(undirectedUtil(v, visited, curr))
		{
			cycle = true;
			break;
		}
	}

	if(cycle == true)
		return true;
	return false;
}

void Graph::directed()
{
	vector<bool> visited(6, false);
	vector<bool> recstack(6, false);

	bool flag = false;
	for(int i = 0; i < 6; i++)
	{
		if(directedUtil(i, visited, recstack))
		{
			flag = true;
			break;
		}
	}

	if(flag == true)
		cout << "Cycle detected";
	else
		cout << "Cycle not detected";
}

bool Graph::directedUtil(int curr, vector<bool>& visited, vector<bool>& recstack)
{
	if(visited[curr] == false)
	{
		visited[curr] = true;
		recstack[curr] = true;

		for(auto v : graph[curr])
		{
			if(visited[v] == false && directedUtil(v, visited, recstack))
				return true;
			else if(recstack[v] == true)
				return true;
		}
	}

	recstack[curr] = false;
	return false;
}

int main()
{
	Graph g;
	g.undirected();
	//g.directed();
}