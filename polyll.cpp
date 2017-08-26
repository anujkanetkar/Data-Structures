#include <iostream>
#include <cstdlib>
#include <cmath>

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
		int evaluate(int);
		Poly add(Poly);
};

Poly :: Poly()
{
	p = NULL;
}

void Poly :: input()
{
	char ch;
	Node *t, *r;
	
	while(ch != 'n')
	{
		cout << "Enter coeff and exponent" << endl;
		if(p == NULL)
		{
			t = new Node;
			cin >> t -> coeff >> t -> exp;
			t -> link = t;
			p = t; 		
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
		t = t -> link;
	}
	cout << t -> coeff << "x^" << t -> exp << endl;
}

int Poly :: evaluate(int x)
{
	Node *t;
	int val = 0;
	t = p;
	while(t -> link != p)
	{
		val = val + t -> coeff * pow(x,t -> exp);
		t = t -> link;		
	}	
	val = val + t -> coeff * pow(x,t -> exp);
	return val;
}

Poly Poly :: add(Poly P)
{
	Poly res;
	Node *t1, *t2;
	t1 = p;
	t2 = P.p;
	while(t -> link != p && P.t -> link != p)
	{
		if(t1 -> exp == P.t2 -> exp)
		{
			
		}
	}
}

int main()
{
	Poly p1;
	int choice, x, ans;
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
				ans = p1.evaluate(x);
				cout << "Result is: " << ans << endl; 
			case 2:
				p1.input();
				p1.display();
				p2.input();
				p2.display();
				p3 = p1.add(p2);
				p3.display();		
			case 0:
				exit(1);
			default:
				cout << "Invalid choice code" << endl;
				
		}
	}
}
