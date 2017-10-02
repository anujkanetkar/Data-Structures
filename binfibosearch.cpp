#include <iostream> 

using namespace std;

class Search
{ 
	private:
		int *a; 
	public: 
		Search(int);
		void getroll(int);
		int binsearch(int, int);
		int fibosearch(int, int);
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

int min(int x, int size)
{
	return(x >= size) ? x : size; 
}   

int Search :: binsearch(int item, int n)
{
		int l = 0, u = n - 1;
		int m;
		bool flag = false;

		while(l <= u)
		{
			m = (l + u) / 2;
			if(a[m] == item)
			{
				flag = true;
				return m;
			}	
			
			a[m] > item ? (u = m - 1) : (l = m + 1);
		}

		if(flag == false)
		{
			return -1;
		}
}

int Search :: fibosearch(int item, int n)
{
	int mm1 = 0, mm2 = 1, offset = -1;
	int fibm = mm1 + mm2;

	while(fibm < n)
	{
		mm2 = mm1;
		mm1 = fibm ;
		fibm = mm1 + mm2;	
	}

	while(fibm < n)
	{
		int i = min(offset+mm2, n-1);

		if(a[mm2] > item)
		{
			fibm = mm2;
			mm1 = mm1 - mm2;
			mm2 = fibm - mm1;
		}
		else if(a[mm2] < item)
		{
			fibm = mm1;
			mm1 = mm2;
			mm2 = fibm - mm1;
			offset = i;
		}
		else
		{
			return i;
		}
	}

	if(mm1 && a[offset+1] == item)	
	{
		return (offset+1);
	}

	return -1;
}

int main()
{
	int item, num, index;
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
                        index = s.binsearch(item, num);
			if(index < 0)
			{
				cout << "Student did not attend training program" << endl;
			}
			else	
			{
				cout << "Student attended training program" << endl; 
			}
	
                        index = s.fibosearch(item, num);
			if(index < 0)
			{
				cout << "Student did not attend training program" << endl;
			}
			else	
			{
				cout << "Student attended training program" << endl; 
			}
	                cout << "Continue checking?(y/n)" << endl;
                        cin >> ch;
               	}
					
		cout << "New list? (y/n)" << endl;
		cin >> ch;
	}
}
