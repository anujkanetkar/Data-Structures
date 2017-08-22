#include <iostream>

using namespace std;

class Node
{
	private:
		Node *prev;
		bool status;
		Node *next;
	public:
		Node()
		{
			prev = next = NULL;
		}
	friend class Dcll;
};

class Dcll
{
	private:
		Node *p[10];
		int cnt;
	public:
		Dcll()
		{
			int i, j;
			for(i=0; i<10; i++)
			{
				p[i] = new Node;
				p[i] -> next = NULL;
				p[i].cnt = 0;	
			}
		}
		
};
