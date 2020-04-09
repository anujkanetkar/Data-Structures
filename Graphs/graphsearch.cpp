#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*struct Node
{
	int data;
	Node *next;
};*/ 

class Graph
{
	private:
		vector<vector <int> > arr;

	public:
		Graph();
		void dfs(int, vector<bool> &);
		void bfs(int);
};

Graph::Graph()
{
	for(int i = 0; i < 8; i++)
	{
		vector<int> x;
		for(int j = 0; j < 8; j++)
		{
			x.push_back(0);
		}
		arr.push_back(x);
	}
	
	arr[0][1] = 1;
	arr[0][2] = 1;
	arr[1][3] = 1;
	arr[1][4] = 1;
	arr[2][5] = 1;
	arr[2][6] = 1;
	arr[3][1] = 1;
	arr[3][7] = 1;
	arr[4][1] = 1;
	arr[4][7] = 1;
	arr[5][2] = 1;
	arr[5][7] = 1;
	arr[6][2] = 1;
	arr[6][7] = 1;
	arr[7][3] = 1;
	arr[7][4] = 1;
	arr[7][5] = 1;
	arr[7][6] = 1;
}

void Graph::dfs(int init, vector <bool> &v)
{
	v[init] = true;
	cout << init << "\t";
	for(int i=0; i<8; i++)
	{
		if(arr[init][i] == 1 && v[i] == false)
			dfs(i, v);
	}		
}

void Graph::bfs(int init)
{
	queue <int> q;
	q.push(init);
	vector <bool> v(8, false);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		if(v[x] == false)
			cout << x << "\t";
		v[x] = true;
		for(int i=0; i<8; i++)
		{
			if(arr[x][i] == 1 && v[i] == false)
				q.push(i);
		}
	}
}

int main()
{
	Graph g;
	vector <bool> v(8, false);
	g.dfs(0, v);
	cout << endl;
	g.bfs(0);
}
