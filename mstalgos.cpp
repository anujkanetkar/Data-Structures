#include <iostream> 
#include <vector>

using namespace std;

class Graph
{ 
	private: 
		vector<vector <int> > arr;
	public: 
		Graph(int);
		void create();
};   

Graph::Graph(int n)
{
	for(int i=0; i<n; i++)
	{
		vector<int> x;
		for(int j=0; j<n; j++)
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
		cout << "Continue? (y/n)" << endl; 	 
		cin >> ch; 
	}while(ch == 'y');
}

int main()
{
	int n;
	cout << "Enter no of vertices" << endl; 
	cin >> n; 
	Graph g(n);
	g.create();
}



