#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Graph
{
	private:
		vector <vector <int> > arr;
	public:
		Graph();
		void dijkstra();
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

	arr[0][0] = 7;
	arr[0][1] = 5;
	arr[1][0] = 7;
	arr[1][3] = 2;
	arr[2][1] = 3;
	arr[3][0] = 4;
	arr[3][2] = 1;
}

void Graph::dijkstra()
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

int main()
{
	Graph g;
	g.dijkstra();
}
