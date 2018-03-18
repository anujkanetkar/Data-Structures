#include <iostream>
using namespace std;

struct bucket
{
	string var;
	string att;
	int chain;
};

class hash 
{
	bucket b[10];
	public:
		hash();
	//virtual ~hash();
		void input();
		void display();
		void value(int,int);
		void search();
};

hash :: hash()
{
	int i;
		for(i=0;i<10;i++)
		{
			b[i].var="";
			b[i].att="";
			b[i].chain=-1;
		}
}
void hash :: input()
{
	int i,j,sum=0,key,index,x,s=0,y;
	bool flag=false;
	string v,atb;

	cout<<"\n\t Enter variable : ";
	cin>>v;
	cout<<"\n\t Enter corresponding attribute : ";
	cin>>atb;

	for(i=0;i<v.length();i++)
	{
		//x = pn[i]-48;
		sum=sum+v[i];
	}

	key=sum%10;

	if(b[key].var=="")
	{
		b[key].var=v;
		b[key].att=atb;
	}
	else if(b[key].chain==-1)
	{
		for(i=key+1;i<10;i++)
		{
			if(b[i].var=="")
			{
				b[i].var=v;
				b[i].att=atb;
				//value(key,i);
				for(j=0;j<b[key].var.length();j++)
				{
					s=s+b[key].var[j];
				}
				if(s % 10 == key)
				{
					b[key].chain=i;
				}

				//b[key].chain=i;
				flag=true;
				break;
			}

		}

		if(flag==false)
		{
			for(i=0;i<key;i++)
			{
				if(b[i].var=="")
				{
					b[i].var=v;
					//value(key,i);
					for(j=0;j<b[key].var.length();j++)
					{
						s=s+b[key].var[j];
					}
					if(s % 10 == key)
					{
						b[key].chain=i;
					}
					flag=true;
					break;
				}
			}
		}
		if(flag==false)
		{
			cout<<"\n\t ** TABLE IS FULL CANNOT INSERT THE ELEMENT **";
		}
	}

	else
	{
		index=b[key].chain;
		do
		{
			if(b[index].chain==-1)
			{
				for(i=index+1;i<10;i++)
				{
					if(b[i].var=="")
					{
						b[i].var=v;
						b[i].att=atb;
						//value(var,i);
						for(j=0;j<b[index].var.length();j++)
						{
							//y = b[index].var[j]-48;
							s=s+b[index].var[j];
						}
						if(s % 10 == key)
						{
							b[index].chain=i;
						}

						flag=true;
						break;
					}

				}

				if(flag==false)
				{
					for(i=0;i<index;i++)
					{
						if(b[i].var=="")
						{
							b[i].var=v;
							//value(var,i);
							for(j=0;j<b[index].var.length();j++)
							{
								//y = b[index].var[j]-48;
								s=s+b[index].var[j];
							}
							if(s % 10 == key)
							{
								b[index].chain=i;
							}
							flag=true;
							break;
						}
					}
					if(flag==false)
					{
						flag=true;
						cout<<"\n\n\t ** Table is full cannot insert **";
					}
				}
			}
			else
			{
				index=b[index].chain;
			}
		}while(flag==false);
	}
}


void hash :: display()
{
	int i;
	cout<<"\n\n\t bucket\tvar \tatt \tchain";

	for(i=0;i<10;i++)
	{
		cout << "\n\t " << i <<" \t "<<b[i].var<<" \t "<<b[i].att<<" \t\t\t "<<b[i].chain;
	}
}

void hash :: search()
{
	string v;
	int sum=0,i,x,key;
	bool flag=false;

	cout<<"\n\n\t Enter identifier you want to search : ";
	cin>>v;

	for(i=0;i<v.length();i++)
	{
		sum=sum+v[i];
	}

	key=sum%10;

	if(v.compare(b[key].var) == 0)
	{
		cout<<"\n\tFOUND";
		cout << b[key].var << " : " << b[key].att << endl; 
		cout<<"\n\t It is found at its own index number : "<<key;
		//cout<<"\n\t Chain of "<<key<<" is modified to "<<i;
	}
	else if(b[key].chain == -1)
	{
		for(i=key+1;i<10;i++)
		{
			if(v.compare(b[i].var)==0)
			{
				cout<<"\n\t Searched successfull";
				cout<<"\n\n\t the number is not found at its own index";
				cout<<"\n\t Hence Linear probing is carried out";
				cout<<"\n\t It is found at index number : "<<i;
				cout << b[i].var << " : " << b[i].att << endl; 
				//cout<<"\n\t Chain of "<<key<<" is modified to "<<i;
				flag=true;
				break;
			}
		}

		if(flag == false)
		{
			for(i=0;i<key;i++)
			{
				if(v.compare(b[i].var)==0)
				{
					cout<<"\n\t SEARCHED successfull";
					cout<<"\n\n\t the number is not found at its own index";
					cout<<"\n\t Hence Linear probing is carried out";
					cout<<"\n\t It is found at index number : "<<i;
					cout << b[i].var << " : " << b[i].att << endl; 
					flag=true;
					break;
				}
			}
			if(flag==false)
			{
				cout<<"\n\n\t NUMBER NOT PRESENT IN THE hashing TABLE ";
				flag=true;
			}
		}
	}
	else
	{
		int idx;

		idx=b[key].chain;

		do
		{
			if(v.compare(b[idx].var)==0)
			{
				cout<<"\n\t number found";
				cout<<"\n\n\t the number is not found at its own index";
				cout<<"\n\t Hence open addressing is carried out";
				cout<<"\n\t It is found at index number : "<<idx;
				cout << b[idx].var << " : " << b[idx].att << endl; 
				flag=true;
			}
			else if(b[idx].chain!=-1)
			{
				idx=b[idx].chain;
			}
			else
			{
				for(i=idx+1;i<10;i++)
				{
					if(v.compare(b[i].var)==0)
					{
						cout<<"\n\t Searched successfull1";
						cout<<"\n\n\t the number is not found at its own index";
						cout<<"\n\t Hence open addressing is carried out";
						cout<<"\n\t It is found at index number : "<<i;
						cout << b[i].var << " : " << b[i].att << endl; 
						flag=true;
						break;
					}
				}
				if(flag == false)
				{
					for(i=0;i<idx;i++)
					{
						if(v.compare(b[i].var)==0)
						{
							cout<<"\n\t SEARCHED successfull1";
							cout<<"\n\n\t the number is not found at its own index";
							cout<<"\n\t Hence open addressing is carried out";
							cout<<"\n\t It is found at index number : "<<i;
							cout << b[i].var << " : " << b[i].att << endl; 
							flag=true;
							break;
						}
					}
					if(flag==false)
					{
						cout<<"\n\n\t NO NOT PRESENT IN THE TABLE";
						flag=true;
					}
				}
			}
		}while(flag==false);
	}
}

int main() 
{
	hash h;

	h.input();
	h.display();
	h.input();
		h.display();
		h.input();
			h.display();
			h.input();
				h.display();
				h.input();
								h.display();
	h.search();
	h.search();
	h.search();
	

	return 0;
}

