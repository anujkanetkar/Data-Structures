#include <iostream> 
#include <vector>
#include <stack>

using namespace std;

class Graph
{ 
	private:
		vector<vector <int> > arr; 
	public:
	 	Graph();
		void topologicalsort();
		void topologicalhelper(int, stack <int> &, vector <bool> &);
};   

Graph::Graph()
{
	for(int i=0; i<6; i++)
	{
		vector <int> x;
		for(int j=0; j<6; j++)
			x.push_back(0);

		arr.push_back(x);	
	}

	arr[2][3] = 1;
	arr[3][1] = 1;
	arr[4][0] = 1;
	arr[4][1] = 1;
	arr[5][0] = 1;
	arr[5][2] = 1;
};

void Graph::topologicalsort()
{
	vector <bool> visited(6, false);

	stack <int> s;

	for(int i=0; i<6; i++)
	{
		if(visited[i] == false)
			topologicalhelper(i, s, visited);
	}

	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}

void Graph::topologicalhelper(int idx, stack <int> &s, vector <bool> &visited)
{
	visited[idx] = true;

	for(int i=0; i<6; i++)
	{
		if(visited[i] == false && arr[idx][i] == 1)
			topologicalhelper(i, s, visited);
	}

	s.push(idx);
}

int main()
{
	Graph g;
	g.topologicalsort();

	return 0;
}
