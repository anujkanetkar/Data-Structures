#include <iostream> 
#include <vector>
using namespace std;
/*class
{ 
	private: 
		vector<int> arr;
	public: 
		Sorting()
		{
			
		}
};*/    

void selection(vector<int>);
void bubble(vector<int>);
void insertion(vector<int>);
void display(vector<int>);


int main()
{
	vector<int> arr{2, 7, 8, 1 ,2, 4, 3, 5, 6};

	selection(arr);
	bubble(arr);
	insertion(arr);
} 

void insertion(vector<int> v)
{
	for(int i=1; i<v.size(); i++)
	{
		int key = v[i];
		int j = i - 1;

		while(j >= 0 && v[j] > key)
		{
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = key;
	}

	display(v);
}

void bubble(vector<int> v)
{
	for(int i=0; i<v.size(); i++)
	{
		for(int j=0; j<v.size()-i-1; j++)
		{
			if(v[j] > v[j+1])
			{
				int temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			} 
		}
	}

	display(v);
}

void selection(vector<int> v)
{
	for(int i=0; i<v.size(); i++)
	{
		for(int j=i+1; j<v.size(); j++)
		{
			if(v[i] > v[j])
			{
				int temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}

	display(v);
}

void display(vector<int> v)
{
	for(int x : v)
		cout << x << " ";
	cout << endl;
}
