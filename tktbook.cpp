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
		Dcll();
		bool book(int, int);
		bool isSold();
		void cancel(int, int);
		void display();
};

Dcll :: Dcll()
{
	Node *t, *r;
	int i, j;
	for(i=0; i<10; i++)
	{
		p[i] = NULL;
	}
	for(i=0; i<10; i++)
	{
		for(j=0; j<7; j++)
		{
			if(p[i] == NULL)
			{
				r = new Node;
				r -> status = false;
				r -> prev = r -> next = r;
				p[i] = r;
			}
			else
			{
				t = p[i] -> prev;
				r = new Node;	
				r -> status = false;
				r -> prev = t;
				r -> next = p[i];
				t -> next = r;
			}
		}
	}
}

void Dcll :: display()
{
	int i, j;
	Node *t;
	for(i=0; i<10; i++)
	{
		t = p[i];
		for(j=0; j<7; j++)
		{
			cout << t -> status << " ";
			t = t -> next; 
		}
		cout << endl;
	}
}

/*void Dcll :: book(int r, int c)
{
	int i, j;
	Node *t;
	bool flag = false;	

	for(i=0; i<10; i++)
	{
		t = p[i];
		for(j=0; j<7; j++)
		{
			if(t -> status == true)
			{
				flag = true;
				t = t -> next;
			}
			else
			{
				if(r == i+1 && c == j+1)
				{
					t -> status = true;
					//cout << i << " " << j << " " << t -> status;
					return;		
				}
				else
				{
					t = t -> next;
				}
			}
		}
	}
	if(flag == true)
	{
		cout << "Sold out" << endl;
		return;
	}
}*/

bool Dcll :: isSold()
{
	int i, j;
	bool flag = false;
	Node *t;

	for(i=0; i<10; i++)
	{
		t = p[i];
		for(j=0; j<7; j++)
		{
			if(t -> status == true)
			{
				flag = true;
				t = t -> next;
			}
			else
			{
				return false;
			}
		}
	}
	if(flag == true)
	{
		return true;
	}
}

bool Dcll :: book(int r, int c)
{
	int i; int j = 0;
	bool flag;
	Node *t;

	/*for(i=0; i<10; i++)
	{
		t = p[i];
		for(j=0; j<7; j++)
		{
			if(r == i+1 && c == j+1)
			{
				if(t -> status == true)
				{
					return false;
				}
				else
				{
					t -> status = true;
					return true;
				}
			}
			else
			{
				t = t -> next;
			}
		}
	}*/
	t = p[r-1];
	/*for(j=0; j<7; j++)
	{
		if(c == j+1)
		{
			if(t -> status == true)
			{
				return false;
			}
			else
			{
				t -> status = true;
				return true;
			}
		}
		else
		{
			t = t -> next;
		}
	}*/
	while(c != j+1)
	{
		t = t -> next;
		j++;
	}
	if(t -> status == true)
	{
		return false;
	}
	else
	{
		t -> status = true;
		return true;
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
			if(t -> status == false)
			{
				cout << "No booking made" << endl;
				return;
			}
			else
			{
				if(r == i && c == j)
				{
					t -> status = false;
					return;
				}
			}
		}
	}
}

int main()
{
	Dcll seats;
	int choice, r, c;
	bool flag;
	while(true)
	{
		cout << "1. Available seats" << endl;
		cout << "2. Book seat" << endl;
		cout << "3. Cancel booking" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter choice" << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				seats.display();
				break;
			case 2:
				if(seats.isSold())
				{
					cout << "Sold out" << endl;
				}
				else
				{
					cout << "Enter the seat row and column to be booked:" << endl;
					cin >> r >> c;
					if(!seats.book(r, c))
					{
						cout << "Already booked" << endl;	
					}
					else
					{
						cout << "Your seat has been booked" << endl;
					}
				}
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

