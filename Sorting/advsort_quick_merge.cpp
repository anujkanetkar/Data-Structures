#include <iostream>
#include <vector>
using namespace std;

class Sort
{
	private:
		vector<int> v;
		int size;
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
			size = v.size();
		}

		int getsize()
		{
			return v.size();
		}

		vector<int> getvec()
		{
			return v;
		}

		void quicksort(int, int);
		int split(int, int);
		void mergesort(vector<int>, int, int);
		void merge(vector<int>, int, int, int);
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

	//cout << "hi";
}

int Sort::split(int l, int u)
{
	//	cout << "h1";
	int pivot = v[l];
	int p = l + 1;
	int q = u;

	while(p <= q)
	{
		while(v[p] <= pivot)
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

void Sort::mergesort(vector<int> aux, int l, int u)
{
	//if(l == u)
	//	return;
	if(l < u)
	{
		int mid =  l + (u - l) / 2;
		mergesort(aux, l, mid);
		mergesort(aux, mid+1, u);
		merge(aux, l, mid, u);
	}
}

void Sort::merge(vector<int> aux, int l, int mid, int u)
{
	int i = l, j = mid + 1;
	int k = l;

	while(i <= mid && j <= u)
	{
		if(v[i] < v[j])
		{
			aux[k] = v[i];
			k++;
			i++;
		}
		else if(v[j] < v[i])
		{
			aux[k] = v[j];
			k++;
			j++;
		}
		else
		{
			aux[k] = v[i];
			k++;
			i++;
			j++;
			size--;
		}
	}

	while(i <= mid)
	{
		aux[k] = v[i];
		k++;
		i++;
	}

	while(j <= u)
	{
		aux[k] = v[j];
		k++;
		j++;
	}

	for(int idx=l; idx<k; idx++)
		v[idx] = aux[idx];
}

void Sort::display()
{
	for(int i=0; i<size; i++)
		cout << v[i] << " ";
	/*for(auto x : v)
		cout << x << " ";*/
	cout << endl;
}

int main()
{
	//cout << "12";
	Sort s1;
	//cout << "hello";
	int sz = s1.getsize();
	
	s1.quicksort(0, sz-1);
	s1.display();
	Sort s2;
	vector<int> aux = s2.getvec();
	
	s2.mergesort(aux, 0, sz-1);
	s2.display();
	return 0;
}