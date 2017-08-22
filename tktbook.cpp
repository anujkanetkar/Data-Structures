#include <iostream>
#include <cstdlib>

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
	public:
		Dcll()
		{
			Node *t, *r, *h;
			//bool flag;
			int i, j;
			for(i=0; i<10; i++)
			{
				p[i] = new Node;
				p[i] -> next = NULL;
			}
			for(i=0; i<10; i++)
			{
				//flag = false;
				for(j=0; j<7; j++)
				{
					t = p[i];
					r = new Node;
					t -> next = r;
					r -> status = false;
					r -> prev = t -> next;
					r -> next = p[i];

				}
			}
		}
		void available();
		void book(int, int);
		void cancel(int, int);
};

void Dcll :: available()
{
	int i, j;
	Node *t;
	for(i=0; i<10; i++)
	{
		t = p[i];
		for(j=0; j<7; j++)
		{
			if(t -> status == false)
			{
				cout << "The following seats are available:" << endl;
			}
		}
	}
}

void Dcll :: book(int r, int c)
{
	int i, j;
	Node *t;

	for(i=0; i<10; i++)
	{
		t = p[i];
		for(j=0; j<7; j++)
		{
			if(r == i && c == j)
			{
				t -> status = true;
				return;
			}
		}
	}

}

void Dcll :: cancel(int r, int c)
{
	int i, j;
	Node *t;

	for(i=0; i<10; i++)
	{
		t = p[i];
		for(j=0; j<7; j++)
		{
			if(r == i && c == j)
			{
				t -> status = false;
				return;
			}
		}
	}
}

int main()
{
	Dcll seats;
	int choice, r, c;

	while(true)
	{
		cout << "1. Available seats" << endl;
		cout << "2. Book seats(s)" << endl;
		cout << "3. Cancel booking" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter choice" << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				seats.available();
				break;
			case 2:
				cout << "Enter the seat row and column to be booked:" << endl;
				cin >> r >> c;
				seats.book(r, c);
				break;
			case 3:
				cout << "Enter the seat row and column to be cancelled:" << endl;
				cin >> r >> c;
				seats.cancel(r, c);
				break;
			case 0:
				exit(1);
			default:
				cout << "Invalid choice code" << endl;
		}
	}
}

