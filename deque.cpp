#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX = 10;

class Deque
{ 
	private: 
		int a[MAX];
		int f,r;	
	public: 	
		Deque();
		void addatend(int);
		void addatbegin(int);
		int delatbegin();
		int delatend();
		void display();
};   

Deque :: Deque()
{
	f = r = -1;
	for(int i=0; i<MAX; i++)
	{
		a[i] = 0;
	}
}

void Deque :: addatend(int n)
{
	int i;
	if(f == 0 && r == MAX - 1)
	{
		cout << "Deque is full" << endl;
		return; 
	}

	if(f == -1)
	{
		f = r = 0;
		a[r] = n;
		return;
	}

	if(r == MAX - 1)
	{
		for(i=f-1; i<r; i++)
		{
			a[i] = a[i+1];
		}
		f--;
	}
	else
	{
		r++;
	}
	a[r] = n;
}

void Deque :: addatbegin(int n)
{
	int i;
	if(f == 0 && r == MAX - 1)
	{
		cout << "Deque is full"<< endl;
		return; 
	}

	if(f == -1)
	{
		f = r = 0;
		a[r] = n;
	}

	if(f == 0)
	{
		for(i=r+1; i>f; i--)
		{
			a[i] = a[i-1];
		}
		r++;
	}
	else
	{
		f--;
	}
	a[f] = n;
}

int Deque :: delatbegin()
{
	int item;
	if(f == -1)
	{
		cout << "Deque is empty" << endl; 
		return 0;
	}
	item = a[f];
	a[f] = 0;
	if(f == r)
	{
		f = r = -1;
	}
	else
	{
		f++;
	}

	return item;
}

int Deque :: delatend()
{
	int item;
	if(f == -1)
	{	
		cout << "Deque is empty" << endl;
		return 0; 
	}
	
	item = a[r];
	a[r] = 0;
	r--;
	if(r == -1)
	{
		f == -1;
	}

	return item;
}

void Deque :: display()
{
	int i;
	for(i=0; i<MAX; i++)
	{
		cout << a[i] << "\t"; 
	}
	cout << endl;
}

int main()
{
	Deque d;
	int choice, num;
	int item;
	while(true)
	{
		cout << "1. Display array" << endl; 
		cout << "2. Add at end" << endl;
		cout << "3. Add at beginning" << endl; 
		cout << "4. Delete at beginning" << endl; 
		cout << "5. Delete at end" << endl; 
		
		cout << "0. Exit" << endl;
		cin >> choice; 
	
		switch(choice) 
		{
			case 1:
				cout << "Deque :" << endl;
				d.display();
				break;
			case 2:
				cout << "Enter the no to be added" << endl;
				cin >> num;
				d.addatend(num);
				break;
			case 3:
				cout << "Enter the no to be added" << endl;
				cin >> num;
				d.addatbegin(num);
				break;
			case 4:
				item = d.delatbegin();
				cout << "No deleted is: " << item << endl; 
				break;
			case 5:
				d.delatend();
				cout << "No deleted is: " << item << endl; 
				break;
			case 0:
				exit(1); 			
		}	
	}	
}
