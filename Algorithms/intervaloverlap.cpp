#include <iostream> 

using namespace std;

bool overlap(int a, int b, int c, int d)
{
	if(a > b)
	{
		int t = a;
		a = b;
		b = t;
	}

	if(c > d)
	{
		int t = c;
		c = d;
		d = t;
	}

	bool ans = false;

	if(c>a && c<b)
		ans = true;
	else if(a>c && a<d)
		ans = true;

	return ans;		
	
}

int main()
{
	int a = 2, b = 6, c = 5, d = 10;
	bool res = overlap(a, b, c, d);
	cout << res << endl;
} 
