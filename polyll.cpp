#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
	private:
		int coeff;
		int exp;
		Node *link;
	public:
		Node()
		{
			coeff = exp = 0;
			link = NULL;
		}
	friend class Poly;
};

class Poly
{
	private:
		Node *p;
	public:
		Poly();	
		void input();
		void display();
};

Poly :: Poly()
{
	p = NULL;
}

void Poly :: input()
{
	char ch;
	Node *t, *r;
	t = p;
	
	while(ch != 'n')
	{
		cout << "Enter coeff and exponent" << endl;
		if(p == NULL)
		{
			t = new Node;
			cin >> t -> coeff >> t -> exp;
			t -> link = p; 		
		}
		else
		{
			r = new Node;
			cin >> r -> coeff >> r -> exp;
			t -> link = r;
			r -> link = p;
			t = r;
		}
		cout << "Continue? (y/n)" << endl;
		cin >> ch; 
	}
}

void Poly :: display()
{
	Node *t;
	t = p;
	while(t -> link != p)
	{
		cout << t -> coeff << "x^" << t -> exp << "+";
	}
}

int Poly :: evaluate(int x)
{
	while(t -> link != p)
	{
		
	}
}

int main()
{
	Poly p1;
	int choice, x;
	while(true)
	{
		cout << "1. Evaluate" << endl; 
		cout << "2. Add" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter choice" << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				p1.input();
				p1.display();
				cout << "Enter the value of x" << endl;
				cin >> x;
				p1.evaluate(x);
			case 0:
				exit(1);
			default:
				cout << "Invalid choice code" << endl;
				
		}
	}
}
