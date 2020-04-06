#include <iostream>
#include <vector>
#include <utility>
#include <limits.h>
#include <algorithm>

using namespace std;

/*struct Node
{
	int data;
	Node *next;
};*/ 

class Graph
{
	private:
		vector<vector<int> > arr;

	public:
		Graph();
		void prims();
		vector<int> minDist(vector<bool>);
		void kruskal();
		bool addEdge(vector<vector<int> >&, int, int);
		bool dfs(vector<vector<int> >, int, vector<bool>&, int);
		bool hasCycle(vector<vector<int> >);
		void display(vector<vector<int> >);
};

Graph::Graph()
{
	for(int i = 0; i < 9; i++)
	{
		vector<int> x;
		for(int j = 0; j < 9; j++)
		{
			x.push_back(0);
		}
		arr.push_back(x);
	}
	
	arr[7][6] = 1;
	arr[6][7] = 1;
	arr[8][2] = 2;
	arr[2][8] = 2;
	arr[6][5] = 2;
	arr[5][6] = 2;
	arr[0][1] = 4;
	arr[1][0] = 4;
	arr[2][5] = 4;
	arr[5][2] = 4;
	arr[8][6] = 6;
	arr[6][8] = 6;
	arr[2][3] = 7;
	arr[3][2] = 7;
	arr[7][8] = 7;
	arr[8][7] = 7;
	arr[0][7] = 8;
	arr[7][0] = 8;
	arr[1][2] = 8;
	arr[2][1] = 8;
	arr[3][4] = 9;
	arr[4][3] = 9;
	arr[5][4] = 10;
	arr[4][5] = 10;
	arr[1][7] = 11;
	arr[7][1] = 11;
	arr[3][5] = 14;
	arr[5][3] = 14;
}

void Graph::display(vector<vector<int> > ans)
{
	for(int i=0; i<ans.size(); i++)
		cout << ans[i][1] << " " << ans[i][2] << " " << ans[i][0] << endl;
}

void Graph::prims()
{
	vector<vector<int> > ans;
	vector<bool> mstSet(9, false);

	int start = 0;
	mstSet[0] = true;
	int mindis = INT_MAX, minidx = 0;
	int curr = 0;
	for(int count=0; count<8; count++)
	{
		vector<int> v = minDist(mstSet);
		ans.push_back(v);
		int src = v[1];
		int dest = v[2];
		int edge = v[0];
		mstSet[dest] = true;

		//cout << v[1] << " " << v[2] << " " << v[0] << endl;
	}

	display(ans);
	
}

vector<int> Graph::minDist(vector<bool> mstSet)
{
	vector<vector<int> > v;
	for(int i=0; i<mstSet.size(); i++)
	{
		int mindis = INT_MAX;
		int minsrc = -1, mindes = -1;
		if(mstSet[i] == true)
		{
			for(int vtx=0; vtx<9; vtx++)
			{
				if(i != vtx && mstSet[vtx] == false && arr[i][vtx] != 0 && arr[i][vtx] < mindis)
				{
					minsrc = i;
					mindis = arr[i][vtx];
					mindes = vtx;
				}
			}
			vector<int> tmp(3);
			tmp[0] = mindis;
			tmp[1] = minsrc;
			tmp[2] = mindes;
			v.push_back(tmp);
		}
	}

	int smallestdist = v[0][0], smallestsrc = v[0][1], smallestdest = v[0][2];
	for(int i=1; i<v.size(); i++)
	{
		if(v[i][0] < smallestdist)
		{
			smallestdist = v[i][0];
			smallestsrc = v[i][1];
			smallestdest = v[i][2];
		}
	}

	vector<int> final(3);
	final[0] = smallestdist;
	final[1] = smallestsrc;
	final[2] = smallestdest;

	return final;
}

bool cmp(const vector<int> &v1, const vector<int> &v2)
{
	if(v1[0] < v2[0])
		return true;
	else
		return false;
}


void Graph::kruskal()
{
	vector<vector<int> > v;
	vector<bool> visited(9, false);
	for(int i=0; i<arr.size(); i++)
	{
		for(int j=0; j<arr[0].size(); j++)
		{
			if(visited[j] == false && arr[i][j] != 0)
			{
				vector<int> tmp(3);
				tmp[0] = arr[i][j];
				tmp[1] = i;
				tmp[2] = j;
				v.push_back(tmp);
			}
		}
		visited[i] = true;
	}
	
	sort(v.begin(), v.end(), cmp);

	vector<vector<int> > ans;
	vector<vector<int> > tmpgraph(9, vector<int>(9, 0));
	//vector<bool> mstSet(9, false);
	ans.push_back(v[0]);
	//mstSet[v[0][1]] = true;
	addEdge(tmpgraph, v[0][1], v[0][2]);
	ans.push_back(v[1]);
	//mstSet[v[1][1]] = true;
	addEdge(tmpgraph, v[1][1], v[1][2]);

	for(int i=2; i<v.size(); i++)
	{
		bool added = addEdge(tmpgraph, v[i][1], v[i][2]);	
		if(added == false)
			ans.push_back(v[i]);
	}

	display(ans);
}

bool Graph::addEdge(vector<vector<int> > &tmpgraph, int src, int des)  //returns true if cycle is found
{
	tmpgraph[src][des] = true;
	bool res = hasCycle(tmpgraph);
	if(res == true)
		tmpgraph[src][des] = false;
	return res;
}

bool Graph::dfs(vector<vector<int> > tmpgraph, int vtx, vector<bool> &visited, int par)
{
	visited[vtx] = true;
	for(int v=0; v<9; v++)
	{
		if(tmpgraph[vtx][v] == true)
		{
			if(par == v)
				continue;
			if(visited[v] == true)
				return true;
			bool found = dfs(tmpgraph, v, visited, vtx);
			if(found)
				return true;
		}
	}

	return false;
}

bool Graph::hasCycle(vector<vector<int> > tmpgraph)
{
	vector<bool> visited(9, false);
	for(int i=0; i<9; i++)
	{
		if(visited[i] == true)
			continue;
		bool flag = dfs(tmpgraph, i, visited, -1);
		if(flag)
			return true;
	}
	return false;
}


int main()
{
	Graph g;
	g.prims();
	g.kruskal();
}
