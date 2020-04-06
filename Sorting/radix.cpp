#include <iostream> 

using namespace std ; 

void init(int [][5]);

void radix(int a[][5], int p[], int n, int dig);

void combine(int a[][5], int p[]);
int main()
{
	
	int *p, i, j, k, n;
	int a[10][5];
	int dig = 1;

	cout << "Enter count of nos." << endl;
	cin >> n;

	p = new int[n];

	cout << "Enter the nos" << endl;
	
	for(i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	
	for(k=0; k<2; k++)
	{
		init(a);
		radix(a, p, n, dig);
		/*for(i=0; i<10; i++)
		{
			for(j=0; j<5; j++)
			{
				cout << a[i][j] << "\t";
			}
			cout << endl;
		}*/
		combine(a, p);
	}
	for(i=0; i<n; i++)
		cout << p[i] << "\t";
}

void init(int a[10][5])
{
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<5; j++)
		{
			a[i][j] = 0;
		}
	}
}

void radix(int a[][5], int p[], int n, int dig)
{
	int index, i, j;
	for(i=0; i<n; i++)
	{
		index = (p[i] / dig) % 10;
		for(j=0; j<5; j++)
		{
			if(a[index][j] == 0)
			{
				a[index][j] = p[i];
				break;
			}
		}
	}
}

void combine(int a[][5], int p[])
{
	int i, j;
	int index = 0; 
	for(i=0; i<10; i++)
	{
		for(j=0; j<5; j++)
		{
			if(a[i][j] != 0)
			{
				p[index] = a[i][j];
				index++;
			}
			else
				break;
		}	
	}
}
