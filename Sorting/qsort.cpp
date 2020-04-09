#include <iostream>
#include <vector>
using namespace std;

class Sort
{
	private:
		vector<int> v;
	public:
		Sort()
		{
			v.push_back(2);
			v.push_back(7);
			v.push_back(8);
			v.push_back(1);
			v.push_back(2);
			v.push_back(4);
			v.push_back(3);
			v.push_back(5);
			v.push_back(6);
			cout << "hi1";
		}

		int getsize()
		{
			return v.size();
		}

		void quicksort(int, int);
		int split(int, int);
		void display();
};

void Sort::quicksort(int l, int u)
{
	int i;
	if(l < u)
	{
		i = split(l, u);
		quicksort(l, i-1);
		quicksort(i+1, u);
	}

	cout << "hi";
}

int Sort::split(int l, int u)
{
	cout << "h1";
	int pivot = v[l];
	int p = l + 1;
	int q = u;

	while(p <= q)
	{
		while(v[p] < pivot)
			p++;
		while(v[q] > pivot)
			q--;
		if(p < q)
		{
			int temp = v[p];
			v[p] = v[q];
			v[q] = temp;
		}
	}

	int x = v[l];
	v[l] = v[q];
	v[q] = x;

	return q;
}

void Sort::display()
{
	/*for(int i=0; i<v.size(); i++)
		cout << v[i] << " ";*/
	for(auto x : v)
		cout << x << " ";
	cout << endl;
}

int main()
{
	cout << "12";
	Sort s1;
	cout << "hello";
	int sz = s1.getsize();
	
	s1.quicksort(0, sz-1);
	s1.display();

	return 0;
}
