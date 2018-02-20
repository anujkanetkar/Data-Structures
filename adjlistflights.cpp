/*#include <iostream> 
#include <map>
#include <iomanip>
#include <cstdlib>
#include <stack>
#include <queue>*/

#include <bits/stdc++.h>

using namespace std; 

#define stl_graph map<string,multimap<string,int>>
#define d_graph multimap<string,int>

class graph
{
	stl_graph g;
	public:
	void create();
	bool insert_node();
	bool insert_edge();
	void delete_node();
	void delete_edge();
	void dfs();
	void bfs();
	void in_degree();
	void out_degree();
	void display();
};


void graph :: create()
{
	cout<<"Enter number of cities : ";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		if(!insert_node()) i--;
	}
	
	cout<<"Enter Number of flights : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		if(!insert_edge()) i--;
	}
	
}


bool graph :: insert_node()
{
	cout<<"Enter the city name : ";
	string name;
	cin>>name;
	if(g.find(name) == g.end())
	{
		g.insert(make_pair(name,d_graph()));
		return true;
	}
	else cout<<"City already present"<<endl;
	return false;
}


bool graph :: insert_edge()
{
	cout<<"Enter source destination and time : ";
	string s,d;
	int w;
	cin>>s>>d>>w;
	if(g.find(s)!=g.end()&&g.find(d)!=g.end())
	{
		if(g[s].find(d)->second != w)
		{
			g[s].insert(make_pair(d,w));
			return true;
		}
		else cout<<"Entry already present"<<endl;
	}
	else cout<<"Invalid source / destination "<<endl;
	return false;
}


void graph :: delete_node()
{
	cout<<"Enter the node to be deleted"<<endl;
	string s;
	cin>>s;
	if( g.find(s) != g.end() )
	{
		g.erase(s);
		for(auto it=g.begin();it!=g.end();it++)
		{
			it->second.erase(s);
		}
	}
	else cout<<"Node doesnot exist"<<endl;
}


void graph :: delete_edge()
{
	cout<<"Enter the source and destination"<<endl;
	string s,d;
	cin>>s>>d;
	if( g.find(s) != g.end() )
	{
		if(g.find(s)->second.find(d) != g.find(s)->second.end())
		{
			g.find(s)->second.erase(d);
		}
	}
	else cout<<"Edge doesnot exist"<<endl;
}


void graph :: in_degree()
{
	string s;
	int in_count = 0;
	cout<<"Enter the node whose in_degree is to be calculated"<<endl;
	cin>>s;
	if(g.find(s)!=g.end())
	{
		for(auto it=g.begin();it!=g.end();it++)
		{
			for(auto it1=it->second.begin();it1!=it->second.end();it1++)
			{
				if(it1->first==s)
				{
					in_count++;
				}
			}
		}
		cout<<"In_degree of node "<<s<<" is : "<<in_count<<endl;		
	}
	else cout<<"invalid node"<<endl;
}


void graph :: out_degree()
{
	string s;
	int out_count = 0;
	cout<<"Enter the node whose out_degree is to be calculated"<<endl;
	cin>>s;
	if(g.find(s)!=g.end())
	{
		out_count=g.find(s)->second.size();
		cout<<"Out_degree of node "<<s<<" is : "<<out_count<<endl;
	}
	else cout<<"invalid node"<<endl;
}


void graph :: dfs()
{
	stack <string> st;
	vector<string> vt;
	st.push(g.begin()->first);
	cout<<"\n\nDepth First Traversal   :   ";
	while(vt.size() != g.size() && !st.empty())
	{
		if(find(vt.begin(),vt.end(),st.top())==vt.end())
		{
			string c = st.top();
			cout<< setw(5) << c << "\t";
			vt.emplace_back(c);
			st.pop();
			for(auto it=g[c].begin() ; it!=g[c].end() ; it++)
			{
				if(find(vt.begin(),vt.end(),it->first)==vt.end())
				{
					st.push(it->first);
				}
			}
			
		}
		
	}
	cout<<endl;
}


void graph :: bfs()
{
	queue <string> q;
	vector<string> vt;
	q.push(g.begin()->first);
	cout<<"\n\nBreadth First Traversal :   ";
	while(!q.empty() && vt.size() != g.size())
	{
		//cout<<"***"<<endl;
		if(find(vt.begin(),vt.end(),q.front())==vt.end())
		{
			string c = q.front();
			cout<< setw(5) << c << "\t";
			vt.emplace_back(c);
			q.pop();
			for(auto it=g[c].begin() ; it!=g[c].end() ; it++)
			{
				if(find(vt.begin(),vt.end(),it->first)==vt.end())
				{
					q.push(it->first);
				}
			}
		}
	}
	cout<<endl;
}

void graph :: display()
{
	cout<<"\n"<<endl;
	for(auto it=g.begin();it!=g.end();it++)
	{
		string s = "City "+it->first+" is connected with : ";
		int n=s.length();
		cout << s ;
		if(it->second.begin()!=it->second.end())
		{
			cout << setw(5) << it->second.begin()->first << "\ttime : " << it->second.begin()->second << endl;
			for(auto it1 = ++it->second.begin(); it1 != it->second.end() ; it1++)
			{
				cout<<setw(n)<<""<<setw(5)<<it1->first<<"\ttime : "<<it1->second<<endl;
			}
			cout<<endl;
		}
		cout<<endl;
	}
}

int main()
{
	int choice;
	graph g;
	while(true)
	{
		cout << "1. Create graph" << endl;
		cout << "2. Delete edge" << endl;
		cout << "3. Delete vertices" << endl; 
		cout << "4. Indegree" << endl;
		cout << "5. Outdegree" << endl; 
		cout << "6. Display" << endl; 
		cout << "7. Dfs" << endl;
		cout << "8. Bfs" << endl;
		cout << "0. Exit" << endl;  
		cout << "Enter choice" << endl; 
		cin >> choice; 

		switch(choice)
		{
			case 1:
				g.create();	
				g.display();
				break;
			case 2:
				g.delete_edge();
				break;
			case 3:
				g.delete_node();
				break;
			case 4:
				g.in_degree();
				break;
			case 5:
				g.out_degree();
				break;
			case 6:
				g.display();
				break;	
			case 7:
				g.dfs();
				break;
			case 8:
				g.bfs();
				break;
			case 0:
				exit(1);
		}
			
	}

	return 0;
}
