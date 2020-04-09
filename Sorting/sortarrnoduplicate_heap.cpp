#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void heapify(vector<int> &v, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < n && v[left] > v[largest])
		largest = left;
	if(right < n && v[right] > v[largest])
		largest = right;

	if(largest != i)
	{
		int temp = v[largest];
		v[largest] = v[i];
		v[i] = temp;

		heapify(v, n, largest);
	}
}

void display(vector<int> v)
{
	for(auto x : v)
		cout << x << " ";
	cout << endl;
}

void dispstk(stack<int> s)
{
	while(!s.empty())
	{
		int x = s.top();
		s.pop();
		cout << x << " ";
	}
	cout << endl;
}

void heapsort(vector<int> &v, int n, stack<int> &s)
{
	for(int i=n/2-1; i>=0; i--)
	{
		heapify(v, n, i);
	}

	for(int i=n-1; i>=0; i--)
	{
		int temp = v[i];
		v[i] = v[0];
		v[0] = temp;
		if(s.empty())
			s.push(v[i]);
		else
		{
			if(s.top() != v[i])
				s.push(v[i]);
		}
		heapify(v, i, 0);
	}

	display(v);
	dispstk(s);
}

int main()
{
	vector<int> v{2,7,8,1,2,4,3,5,6};
	stack<int> s;

	heapsort(v, v.size(), s);
}