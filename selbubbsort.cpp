#include <iostream> 

using namespace std;

class Sort
{
	private:
		float *a;
	public:
		Sort(int);
		void getper(int);
		void selsort(int);
		void bubbsort(int);
		void display(int);
}; 

Sort :: Sort(int n)
{
	a = new float[n];
}

void Sort :: getper(int n)
{
	for(int i=0; i<n; i++)
	{
		cin >> a[i]; 
	}
}

void Sort :: selsort(int n)
{
	int i, j;
	float temp;
	int min;

	for(i=0; i<n-1; i++)
	{
		min = i;
		for(j=i+1; j<n; j++)
		{
			if(a[min] > a[j])
			{
				min = j;
			}	
		}
		temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}

void Sort :: bubbsort(int n)
{
	int i, j, temp;
	bool flag;
	for(i=0; i<n-1; i++)
	{
		flag = false;
		for(j=0; j<n-1-i; j++)
		{
			if(a[j] > a[j+1])
			{
				flag = true;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		if(flag == false)
			break;
	}
}

void Sort :: display(int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		cout << a[i] << "\t"; 
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
		Sort s(num);
		cout << "Enter first year percentage" << endl;
		s.getper(num); 
		s.selsort(num);
		s.display(num);
		s.bubbsort(num);
		s.display(num);

		cout << "Continue ?(y/n)" << endl;
		cin >> ch; 
	}
}


