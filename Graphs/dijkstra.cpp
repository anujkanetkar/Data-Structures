#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <set>
#include <utility>
#include <queue>
#include <unordered_set>
#include <map>

using namespace std;

class Graph
{
	private:
		unordered_map<int, set<pair<int, int>>> graph;
		vector <vector <int> > arr;
	public:
		Graph();
		void dijkstra_adjmat();
		void dijkstra_adjlist();
		int findMin(vector <int> &, vector <bool> &);
};

Graph::Graph() 
{
	for(int i=0; i<4; i++)
	{
		vector <int> x;
		for(int j=0; j<4; j++)
			x.push_back(0);
		arr.push_back(x);
	}

	//arr[0][0] = 7;
	arr[0][1] = 5;
	arr[1][0] = 7;
	arr[1][3] = 2;
	arr[2][1] = 3;
	arr[3][0] = 4;
	arr[3][2] = 1;

	//graph[0].insert(make_pair(0, 7));
	graph[0].insert(make_pair(1, 5));
	graph[1].insert(make_pair(0, 7));
	graph[1].insert(make_pair(3, 2));
	graph[2].insert(make_pair(1, 3));
	graph[3].insert(make_pair(0, 4));
	graph[3].insert(make_pair(2, 1));

	//how adj list looks like
	for(auto i : graph)
	{
		set<pair<int, int>> s = i.second;
		cout << i.first << " ";
		for(auto x : s)
			cout << "(" << x.first << "," << x.second << ")";
		cout << endl;
	}
}

void Graph::dijkstra_adjmat()
{
	int n = arr.size();
	vector <int> distance(n, INT_MAX);
	vector <bool> doneset(n, false);

	distance[0] = 0;

	for(int count=0; count<n-1; count++)
	{
		int vertex = findMin(distance, doneset);
		doneset[vertex] = true;
		for(int i=0; i<n; i++)
		{
			if(doneset[i] == false && arr[vertex][i] != 0 && distance[vertex] != INT_MAX && distance[i] > distance[vertex]+arr[vertex][i])
				distance[i] = distance[vertex] + arr[vertex][i];
		}
	}

	for(int i=0; i<n; i++)
		cout << "Vertex " << i << " distance " << distance[i] << endl;

}

int Graph::findMin(vector <int> &distance, vector <bool> &doneset)
{
	int mindist = INT_MAX;
	int minindex = 0; 
	int n = arr.size();
	for(int i=0; i<n; i++)
	{
		if(distance[i] != INT_MAX && doneset[i] == false &&  mindist > distance[i])
		{
			mindist = distance[i];
			minindex = i;
		}
	}

	return minindex;
}

struct Cmp
{
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		if(p1.second <= p2.second)
			return true;
		else
			return false;
	}
};

void Graph::dijkstra_adjlist()
{
	int src = 0;
	vector<int> dist(4, INT_MAX);
	dist[src] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	pq.push(make_pair(src, 0));

	while(!pq.empty())
	{
		pair<int, int> p = pq.top();
		pq.pop();

		for(auto vtxwt : graph[p.first])
		{
			if(dist[p.first] + vtxwt.second < dist[vtxwt.first])
			{
				dist[vtxwt.first] = dist[p.first] + vtxwt.second;
				pq.push(make_pair(vtxwt.first, dist[vtxwt.first]));
			}
		}
	}

	for(int i = 0; i < dist.size(); i++)
		cout << "Vertex " << i << " Distance " << dist[i] << endl;
}

int main()
{
	Graph g;
	g.dijkstra_adjmat();
	g.dijkstra_adjlist();
}
