#include <iostream> 

using namespace std;

class Search
{ 
	private: 
		int *a;
	public: 
		Search(int);
		void getroll(int);
		void linsearch(int, int);
		void sentsearch(int, int);
};   

Search :: Search(int n)
{
	a = new int[n];
}

void Search :: getroll(int n)
{
	for(int i=0; i<n; i++)
	{
		cin >> a[i]; 
	}
}

void Search :: linsearch(int item, int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(a[i] == item)
		{
			break;
		}
	}

	if(i == n)
	{
		cout << "Roll no " << item << " did not attend training program" << endl; 
	}
	else
	{
		cout << "Roll no " << item << " attended training program" << endl;  
	}
}

void Search :: sentsearch(int item, int n)
{
	int last = a[n-1];
	a[n-1] = item;
	int i = 0;

	while(a[i] != item)
	{
		i++;
	}

	a[n-1] = last;
	
	if(i < n-1 || item == a[n-1])
	{ 
		cout << "Roll no " << item << " attended training program" << endl; 
	}
	else
	{
		cout << "Roll no " << item << " did not attend training program" << endl; 
	}
}

int main()
{
	int item, num;
	char ch = 'y';
	while(ch == 'y')
	{
		cout << "Enter no of students" << endl;
		cin >> num;
		Search s(num);
		cout << "Enter the roll nos" << endl;
		s.getroll(num);
		while(ch == 'y')
		{
			cout << "Enter roll no to check" << endl;
			cin >> item;
			s.linsearch(item, num);
			s.sentsearch(item, num);
			cout << "Continue checking?(y/n)" << endl;
			cin >> ch;
		}
		cout << "New list?(y/n)" << endl;
		cin >> ch;
	}

	return 0;
}
