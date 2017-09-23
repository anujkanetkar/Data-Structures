#include <iostream> 

using namespace std;

class QSort
{ 
	private: 
		float *a;
		int no_terms;
	public:
		QSort(int);
		void getper();
		void quicksort(int, int);
		int split(int, int);
		void display();
};

QSort :: QSort(int n)
{
	no_terms = n;
	a = new float[no_terms];
}

void QSort :: getper()
{
	int i; 
	for(i=0; i<no_terms; i++)
	{
		cin >> a[i]; 
	}
}

void QSort :: quicksort(int lower, int upper)
{
	int i;
	if(upper > lower)
	{
		i = split(lower, upper);
		quicksort(lower, i-1);
		quicksort(i+1, upper);
	}
}

int QSort :: split(int lower, int upper)
{
	int i, p, q, t;
	p = lower + 1;
	q = upper;
	i = a[lower];

	while(p <= q)
	{
		while(a[p] >= i)
		{
			p++;
		}
		while(a[q] < i)
		{
			q--;
		}
		if(p < q)
		{
			t = a[p];
			a[p] = a[q];
			a[q] = t;
		}
	}

	t = a[lower];
	a[lower] = a[q];
	a[q] = t;
	
	return q;
}

void QSort :: display()
{
	for(int i=0; i<5; i++)
	{
		cout << a[i] << "\t" ; 
	}
	cout << endl;
}

int main()
{
	int num;
	char ch = 'y';	

	while(ch == 'y')
	{
		cout << "Enter no of students" << endl;
		cin >> num;
		QSort s(num);
		cout << "Enter first year  percentage" << endl; 
		s.getper();
		//s.display();
		s.quicksort(0, num-1);
		cout << "Top 5 scores are: "; 
		s.display();

		cout << "Continue ?(y/n)" << endl;
		cin >> ch;
	}
	return 0;
}   
