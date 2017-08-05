#include <iostream>

using namespace std;

class Node
{
	public:
		int prn;
		string name;
		Node *link;
	public:
		/*Node(int PRN = 0, string s = "")
		{
			prn = PRN;
			name = s;
		}*/

		friend class LinkedList;
};

class LinkedList
{
	private:
		Node *p;
	public:
		LinkedList()
		{
			p = NULL;
		}

		void addprez(int, string);
		void addsecy(int, string);
		void addmember(int, string, int);
		void delprez();
		void delsecy();
		void delmember(int);
		int count();
		void display();
		void disp_rev(Node*);
		void concatenate(LinkedList);
		void sort();
};

void LinkedList :: addprez(int n, string s)
{
	Node *t;
	t = new Node;
	t -> prn = n;
	t -> name = s;
	t -> link = p;
	p = t;
}

void LinkedList :: addsecy(int n, string s)
{
	Node *r, *t;
	r = new Node;
	r -> prn = n;
	r -> name = s;
	if(p == NULL)
	{
		//p = r;
		cout << "Empty list" << endl;
	}
	else
	{
		t = p;
		while(t -> link != NULL)
		{
			t = t -> link;
		}
		t -> link = r;
	}
}

void LinkedList :: addmember(int n, string s, int pos)
{
	int i;
	Node *t, *r, *prev;
	if(p == NULL)
	{
		cout << "Empty list" << endl;
		return;
	}
	else
	{
		t = p;
		for(i=0; i<pos; i++)
		{
			if(t -> link != NULL)
			{
				prev = t;
				t = t -> link;
			}
			else
			{
				break;
			}
		}
		r = new Node;
		r -> prn = n;
		r -> name = s;
		r -> link = t;
		prev -> link = r;
		
	}
}

void LinkedList :: delprez()
{
	Node *t;
	t = p;
	p = t -> link;
	delete t;
	return;
}

void LinkedList :: delsecy()
{
	Node *t, *prev;
	t = p;
	while(t -> link != NULL)
	{
		prev = t;
		t = t -> link;
	}
	delete t;
	prev -> link = NULL;
}

void LinkedList :: delmember(int n)
{
	Node *t, *prev;
	t = p;
	while(t != NULL)
	{
		if(t -> prn == n)
		{
			if(t == p)
			{
				p = t -> link;
			}
			else
			{
				prev -> link = t -> link;
			}
			delete t;
			return;
		}
		else
		{
			prev = t;
			t = t -> link;
		}
	}
	cout << "Element not found" << endl;
}

int LinkedList :: count()
{
	int c;
	Node *t;
	t = p;
	while(t != NULL)
	{
		t = t -> link;
		c++;
	}
	return c;
}

void LinkedList :: display()
{
	Node *t;
	t = p;
	while(t != NULL)
	{
		cout << t -> prn << " " << t -> name << "\t";
		t = t -> link;
	}
}

void LinkedList :: disp_rev(Node *t)
{
	t = p;
	if(t == NULL)
	{
		return;	
	}
	else
	{
		while(t != NULL)
		{
			disp_rev(t -> link);
			cout << t -> prn << " " << t -> name << "\t";
		}
	}
}

void LinkedList :: concatenate(LinkedList l)
{
	Node *t;
	t = p;
	while(t -> link != NULL)
	{
		t = t -> link;
	}
	t -> link = l.p;
	delete l.p;
}

void LinkedList :: sort()
{
	Node *t, *r;
	int temp_prn;
	string temp_name;
	if(p == NULL)
	{
		cout << "Empty list" << endl;
		return;
	}
	else
	{
		r = p;
		while(r -> link != NULL)
		{
			t = r -> link;
			while(t != NULL)
			{
				if(r -> prn > t -> prn)
				{
					temp_prn = r -> prn;
					r -> prn = t -> prn;
					t -> prn = temp_prn;
					temp_name = r -> name;
					r -> name = t -> name;
					t -> name = temp_name;			
				}
				t = t -> link;
			}
			r = r -> link;
		}
	}
}

int main()
{
	LinkedList ll, ll1;
	int choice, n, pos, cnt;
	string s;
	while(true)
	{
		cout << "1. Insert President" << endl;
		cout << "2. Insert Secretary" << endl;
		cout << "3. Insert Member" << endl;
		cout << "4. Display Members" << endl;
		cout << "5. Delete President" << endl;
		cout << "6. Delete Secretary" << endl;
		cout << "7. Delete Member" << endl;
		cout << "8. Total members" << endl;
		cout << "9. Display in reverse" << endl;
		cout << "10. Concatenate lists" << endl;
		cout << "11. Sort" << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Enter PRN no:" << endl;
				cin >> n;
				cout << "Enter name:" << endl;
				cin.ignore();
				getline(cin, s);
				ll.addprez(n,s);
				break;
			case 2:
				cout << "Enter PRN no:" << endl;
				cin >> n;
				cout << "Enter name:" << endl;
				cin.ignore();
				getline(cin, s);
				ll.addsecy(n,s);
				break;
			case 3:
				cout << "Enter PRN no:" << endl;
				cin >> n;
				cout << "Enter name:" << endl;
				cin.ignore();
				getline(cin, s);
				cout << "Enter position:" << endl;
				cin >> pos;
				ll.addmember(n,s,pos);
				break;
			case 4:
				ll.display();
				break;
			case 5:
				ll.delprez();
				break;
			case 6:
				ll.delsecy();
				break;
			case 7:
				cout << "Enter prn to be deleted";
				cin >> n;
				ll.delmember(n);
				break;
			case 8:
				cnt = ll.count();
				cout << "Total no of members are: " << cnt << endl;
				break;
			case 10:
				cout << "Enter PRN no:" << endl;
				cin >> n;
				cout << "Enter name:" << endl;
				cin.ignore();
				getline(cin, s);
				ll1.addprez(n,s);
				cout << "Enter PRN no:" << endl;
				cin >> n;
				cout << "Enter name:" << endl;
				cin.ignore();
				getline(cin, s);
				ll1.addsecy(n,s);
				cout << "Enter PRN no:" << endl;
				cin >> n;
				cout << "Enter name:" << endl;
				cin.ignore();
				getline(cin, s);
				cout << "Enter position:" << endl;
				cin >> pos;
				ll1.addmember(n,s,pos);
				ll.concatenate(ll1);
			case 11:
				ll.sort();
		}
	}
}



