#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
	Node *left;
	string keyword;
	string meaning;
	Node *right;
};

class BST
{
	private:
		Node *root;
	public:
		BST();
		void create();
		void inorder(Node*);
		Node* getRoot();
		void operator=(BST&);
		Node* copy(Node*);
		//void add(Node*, string, string);
		void add(string, string);
		void update(string, string);
		int search(string, string);
		Node* delnode(Node*, string);
		Node* findMin(Node*);
};

BST::BST()
{
	root = NULL;
}

void BST::create()
{
	char ch;

	do
	{
		bool flag = false;
		string kw, m;
		cout << "Enter keyword" << endl;
		cin >> kw;
		cout << "Enter meaning" << endl;
		cin.ignore();
		getline(cin, m);
		Node *p = new Node;
		p->left = p->right = NULL;
		p->keyword = kw;
		p->meaning = m;

		if(root == NULL)
			root = p;
		else
		{
			Node *q = root;

			do
			{
				if((p->keyword).compare(q->keyword) < 0)
				{
					if(q->left != NULL)
						q = q->left;
					else
					{
						q->left = p;
						flag = true;
					}
				}
				else
				{
					if(q->right != NULL)
						q = q->right;
					else
					{
						q->right = p;
						flag = true;
					}
				}

			}while(flag == false);
		}

		cout << "Continue? (y/n)" << endl;
		cin >> ch;
	}while(ch == 'y');
}

void BST::inorder(Node *r)
{
	if(r == NULL)
		return;

	inorder(r->left);
	cout << r->keyword << " : " << r->meaning << endl;
	inorder(r->right);
}

Node* BST::getRoot()
{
	return root;
}

void BST::operator=(BST &t)
{
	if(t.root == NULL)
		return;

	root = copy(t.root);
}

Node* BST::copy(Node *root)
{
	if(root == NULL)
		return NULL;

	Node *temp = new Node;
	temp->keyword = root->keyword;
	temp->meaning = root->meaning;
	temp->left = copy(root->left);
	temp->right = copy(root->right);

	return temp;
}

/*void BST::add(Node *r, string kw, string m)
{
	if(r == NULL)
	{
		r = new Node;
		r->keyword = kw;
		r->meaning = m;
		r->left = r->right = NULL;

		return;
	}

	if(kw.compare(r->keyword) < 0)
		add(r->left, kw, m);
	else
		add(r->right, kw, m);
}*/

void BST::add(string kw, string m)
{
	bool flag = false;


	Node *p = new Node;
	p->left = p->right = NULL;
	p->keyword = kw;
	p->meaning = m;

	if(root == NULL)
		root = p;
	else
	{
		Node *q = root;

		do
		{
			if((p->keyword).compare(q->keyword) < 0)
			{
				if(q->left != NULL)
					q = q->left;
				else
				{
					q->left = p;
					flag = true;
				}
			}
			else
			{
				if(q->right != NULL)
					q = q->right;
				else
				{
					q->right = p;
					flag = true;
				}
			}

		}while(flag == false);
	}
}

void BST::update(string kw, string m)
{
	if(root == NULL)
	{
		cout << "No word present" << endl;
		return;
	}

	Node *q = root;
	bool flag = false;
	do
	{
		if(kw.compare(q->keyword) < 0)
		{
			if(q->left != NULL)
				q = q->left;
			else
			{
				cout << "Keyword not present" << endl;
				return;
			}
		}
		else if(kw.compare(q->keyword) > 0)
		{
			if(q->right != NULL)
				q = q->right;
			else
			{
				cout << "Keyword not present" << endl;
				return;
			}
		}
		else
		{
			char ch;
			cout << "Update this meaning ?(y/n)" << endl;
			cout << q->keyword << " : " << q->meaning << endl;
			cin >> ch;
			if(ch == 'y')
			{
				char c;
				cout << "y to add another meaning, n to replace the existing meaning" << endl;
				cin >> c;
				if(c == 'y')
					q->meaning = q->meaning + ", " + m;
				else
					q->meaning = m;
				flag = true;
			}
			else
				break;
		}
	}while(flag == false);
}

int BST::search(string kw, string m)
{
	if(root == NULL)
	{
		cout << "No word present" << endl;
		return 0;
	}

	Node *q = root;
	bool flag = false;
	int cnt = 0;
	do
	{
		if(kw.compare(q->keyword) < 0)
		{
			cnt++;
			if(q->left != NULL)
				q = q->left;
			else
			{
				cout << "Keyword not present" << endl;
				return cnt;
			}
		}
		else if(kw.compare(q->keyword) > 0)
		{
			cnt++;
			if(q->right != NULL)
				q = q->right;
			else
			{
				cout << "Keyword not present" << endl;
				return cnt;
			}
		}
		else
		{
			cnt++;
			cout << q->keyword << " : " << q->meaning << endl;
			flag = true;
		}
	}while(flag == false);

	return cnt;
}

Node* BST::delnode(Node *q, string kw)
{

	if(kw.compare(q->keyword) < 0)
		q->left = delnode(q->left, kw);
	else if(kw.compare(q->keyword) > 0)
		q->right = delnode(q->right,kw);
	else
	{
		if(q->left == NULL && q->right == NULL)
		{
			delete q;
			q = NULL;
		}
		else if(q->left == NULL)
		{
			Node *t = q;
			q = q->right;
			delete t;
		}
		else if(q->right == NULL)
		{
			Node *t = q;
			q = q->left;
			delete t;
		}
		else
		{
			Node *t = findMin(q->left);
			q->keyword = t->keyword;
			q->meaning = t->meaning;
			q->left = delnode(q->left, t->keyword);
		}
	}

	return q;
}

Node* BST::findMin(Node* r)
{
	if(r == NULL)
		return NULL;

	while(r->right != NULL)
	{
		r = r->right;
	}

	return r;
}

int main()
{
	BST dict;
	dict.create();
	Node *r = dict.getRoot();

	while(true)
	{
		int choice;
		cout << "1. Add new keyword" << endl;
		cout << "2. Delete a keyword" << endl;
		cout << "3. Update the meaning" << endl;
		cout << "4. Make a copy of the dictionary" << endl;
		cout << "5. Display the whole data in the dictionary" << endl;
		cout << "6. Search a particular keyword" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;

		switch(choice)
		{
			case 1:
			{
				string kw, m;
				cout << "Enter keyword" << endl;
				cin >> kw;
				cout << "Enter meaning" << endl;
				cin.ignore();
				getline(cin, m);
				//dict.add(r, kw, m);
				dict.add(kw, m);
			}
				break;

			case 2:
			{
				string kw;
				cout << "Enter the keyword" << endl;
				cin >> kw;
				dict.delnode(r, kw);
			}
				break;

			case 3:
			{
				string kw, m;
				cout << "Enter the keyword" << endl;
				cin >> kw;
				cout << "Enter the updated meaning" << endl;
				cin.ignore();
				getline(cin, m);
				dict.update(kw, m);
			}
				break;

			case 4:
			{
				BST dictcopy;
				dictcopy = dict;
				Node *r1 = dictcopy.getRoot();
				dictcopy.inorder(r1);
			}
				break;

			case 5:
				dict.inorder(r);
				cout << endl;
				break;

			case 6:
			{
				string kw, m;
				cout << "Enter the keyword" << endl;
				cin >> kw;
				int cmp = dict.search(kw, m);
				cout << "No of comparisons made were: " << cmp << endl;
			}
				break;


			case 0:
				exit(1);
		}
	}

	return 0;
}




