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
		void delmember(int, string);
		int count();
		void display();
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
		p = r;
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
	Node *t, *r;
	t = p;
	if(p == NULL)
	{
		cout << "Empty list" << endl;
		return;
	}
	else
	{
		for(i=0; i<pos; i++)
		{
			if(t -> link == NULL)
			{
				break;
			}
			t = t -> link;
		}
		r = new Node;
		r -> prn = n;
		r -> name = s;
		r -> link = t -> link;
		t -> link = r;
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
}

void LinkedList :: delmember(int n, string s)
{
	Node *t, *prev;
	t = p;
	while(t != NULL)
	{
		if(t -> prn == n && t -> name == s)
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
		prev = t;
		t = t -> link;
	}
	cout << "Element not found" << endl;
}

int LinkedList :: count()
{
	int c;
	while(p != NULL)
	{
		p = p -> link;
		c++;
	}
	return c;
}

void LinkedList :: display()
{
	while(p != NULL)
	{
		cout << p -> prn << " " << p -> name << "\t";
		p = p -> link;
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
	Node *t;
	int temp_prn;
	string temp_name;
	if(p == NULL)
	{
		cout << "Empty list" << endl;
		return;
	}
	else
	{
		while(p != NULL)
		{
			t = p -> link;
			while(t != NULL)
			{
				if(p -> prn > t -> prn)
				{
					temp_prn = p -> prn;
					p -> prn = t -> prn;
					t -> prn = temp_prn;
					temp_name = p -> name;
					p -> name = t -> name;
					t -> name = temp_name;			
				}
				t = t -> link;
			}
			p = p -> link;
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
				cout << "Enter value/data to be deleted";
				cin >> n >> s;
				ll.delmember(n,s);
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



