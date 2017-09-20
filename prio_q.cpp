#include <iostream> 
#include <cstdlib>

using namespace std;

class Node
{ 
	private:
		int prio;	
		string job;
		Node *link; 
	public: 
		Node()
		{
			prio = 0;
			job = "";
			link = NULL;
		}

	friend class Prioq;
};

class Prioq
{ 
	private:
		Node *p; 
	public:
		Prioq()
		{
			p = NULL;
		} 

		void add(int, string);
		string del();
		void display();
};

void Prioq :: add(int pr, string j)
{
	Node *t, *r, *prev;
	bool flag = false;
	if(p == NULL)
	{
		t = new Node;
		t -> prio = pr;
		t -> job = j;
		t -> link = NULL;
		p = t;
	}
	else
	{
		t = p;
		/*while(t -> link != NULL)
		{
			if(pr > t -> prio)
			{
				s = new Node;
				s -> prio = pr;
				s -> job = j;
				s -> link = t;
			}
			t = t -> link;
			prev = t;
		}*/
		while(t -> prio > pr)
		{
			if(t -> link != NULL)
			{
				prev = t;
				t = t -> link;
				flag = true;
			}
			else
			{	
				r = new Node;
				r -> prio = pr;
				r -> job = j;
				r -> link = NULL;
				t -> link = r;
				return;
			}
		}
		r = new Node;
		r -> prio = pr;
		r -> job = j;
		r -> link = t;
		if(flag == true)
		{
			prev -> link = r;
		}
		else
		{
			p = r;
		}
	}
}

void Prioq :: display()
{
	Node *t;
	t = p;
	while(t != NULL)
	{
		cout << t -> prio << " " << t -> job << "\t";
		t = t -> link;
	}
	cout << endl;
}

string Prioq :: del()
{
	Node *t;
	t = p;
	string s = t -> job;
	p = t -> link;
	delete t;
	return s;
}

int main()
{
	Prioq p;
	int choice, pr;
	string j;
	while(true)
	{
		cout << "1. Add" << endl;
		cout << "2. Delete" << endl;
		cout << "3. Display" << endl;
		cout << "0. Exit" << endl;

		cout << "Enter choice" << endl;
		cin >> choice;

		switch(choice)
		{
			case 1:
				cout << "Enter priority and job name" << endl;
				cin >> pr >> j; 
				p.add(pr, j);
				break;
			case 2:
				j = p.del();
				cout << "Job " << j << " completed and deleted from Q" << endl; 
				break;
			case 3:
				p.display();
				break;
			case 0:
				exit (1);
		} 
	}
}     
