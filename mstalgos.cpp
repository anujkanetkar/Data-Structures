#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Graph
{
	private:
		vector<vector <int> > arr;
		int v;
	public:
		Graph();
		void create();
		int kruskal();
		int prims(int);
		int minKey(vector<int> &, vector<bool> &);
};

Graph::Graph()
{
	cout << "Enter no of vertices" << endl;
	cin >> v;

	for(int i=0; i<v; i++)
	{
		vector<int> x;
		for(int j=0; j<v; j++)
		{
			x.push_back(0);
		}
		arr.push_back(x);
	}
}

void Graph::create()
{
	char ch;

	do
	{
		int i,j,c;
		cout << "Enter the 2 vertices" << endl;
		cin >> i >> j;
		cout << "Enter the cost" << endl;
		cin >> c;
		arr[i][j] = c;
		arr[j][i] = c;
		cout << "Continue? (y/n)" << endl;
		cin >> ch;
	}while(ch == 'y');
}

/*int Graph::kruskal()
{
	int mst_cost = 0;
	vector<bool> visited(0,v);

	int p = 0;
	while(p < v)
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			if(arr[i][j] != INT_MAX && visited[i] == false)
			{
				int count = 0;
				for(int k=0; k<v; k++)

			}
		}
	}

	return mst_cost;
}*/

int Graph::prims(int start)
{
	int mst_cost = 0;
	vector<bool> visited(v,false);
	vector<int> key(v,INT_MAX);

	key[start] = 0;

	for(int i=0; i<v; i++)
	{
		int u = minKey(key, visited);
		visited[u] = true;

		for(int j=0; j<v; j++)
		{
			if(arr[u][j]!=0 && arr[u][j]<key[j] && visited[j]==false)
			{
				key[j] = arr[u][j];
				mst_cost += arr[u][j];
			}
		}
	}

	return mst_cost;

}

int Graph::minKey(vector<int> &key, vector<bool> &vis)
{
	int min_key = INT_MAX;
	int min_idx;

	for(int i=0; i<v; i++)
	{
		if(vis[i]==false && key[i]<min_key)
		{
			min_key = key[i];
			min_idx = i;
		}
	}

	return min_idx;
}

int main()
{
	Graph g;
	g.create();
	//g.kruskal();
	int start;
	cout << "Enter starting vertex" << endl;
	cin >> start;
	int min_cost = g.prims(start);
	cout << min_cost << endl;

	return 0;
}





