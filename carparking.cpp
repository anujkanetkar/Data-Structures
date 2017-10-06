#include <iostream> 
#include <cstdio>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std; 

const int FLOORS = 5;
const int ROWS = 3;
const int COLS = 10;
const int VACANT = -1;
const int OCCUPIED = 1;

class Slot
{ 
	private: 
		int a[FLOORS][ROWS][COLS];
	public: 
		Slot();
		string allot(int);
		int exit(int, int, int, int);
};  

Slot :: Slot()
{
	int i, j, k;
	for(i=0; i<FLOORS; i++)
	{
		for(j=0; j<ROWS; j++)
		{
			for(k=0; k<COLS; k++)
			{
				a[i][j][k] = VACANT;
			}
		}
	}
}

string Slot :: allot(int timectr)
{
	int i, j, k;
	char str[10];
	bool flag = false;
	string s;
	
	for(i=0; i<FLOORS; i++)
	{
		for(j=0; j<ROWS; j++)
		{
			for(k=0; k<COLS; k++)
			{
				if(a[i][j][k] == VACANT)
				{
					a[i][j][k] = timectr;	
					sprintf(str,"%02d%02d%02d",i,j,k);
					string tktno(str);
					flag = true;
					return tktno;			
				}
				
			}
		}
	}

	if(flag == false)
	{
		s = "No parking slot available";
		return s;
	}
}

int Slot :: exit(int i, int j, int k, int currtime)
{
	int timediff, cost;
	if(a[i][j][k] != VACANT)
	{
		timediff = currtime - a[i][j][k];
		a[i][j][k] = VACANT;
		cost = timediff * 100;
		return cost;
	}
	else
	{
		return -1;
	}
}

int main()
{
	Slot s;
	int choice;
	string tktno;
	string s1, s2, s3;
	int money;
	int intime;
	int i, j, k;
	i = j = k = 0;
	int timectr = 0;
	while(true)
	{
		timectr++;
		cout << "1. Get a parking slot" << endl;
		cout << "2. Exit from parking slot" << endl;
		cout << "0. Exit from program" << endl;

		cout << "Enter any choice" << endl;
		cin >> choice;

		switch(choice)
		{
			case 1:
				//cout << "Enter time of entry" << endl;
				//cin >> intime;
				//cout << "Enter no of hours to be booked" << endl;
				//cin >> book;	
				tktno = s.allot(timectr);
				
				cout << "Your ticket no. is: " << tktno << endl; 
			
				break;
			case 2:
			{
				cout << "Enter the tkt no" << endl;
				cin >> tktno;
				s1 = tktno.substr(0, 2);
				s2 = tktno.substr(2, 2);
				s3 = tktno.substr(4, 2);
				stringstream floor(s1);
				floor >> i;
				stringstream row(s2);
				row >> j;
				stringstream col(s3);	
				col >> k;
				money = s.exit(i, j, k, timectr);
				if(money > 0)
				{
					cout << "Cost incurred is: " << money << endl;
				}
				else
				{
					cout << "You entered the wrong ticket number" << endl; 
				}
			}
				break;
			case 0: 
				exit(1);		
		}
	}

	return 0;
}
