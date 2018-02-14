#include <iostream>
#include <cstdlib> 

using namespace std;

struct Node
{
	Node *left;
	bool lt;
	int data;
	bool rt;
	Node *right;
}; 

class ThreadedBT
{ 
	private:
		Node *root;	 
	public:
		ThreadedBT(); 
		Node* getRoot();
		void create(int);
		void inorder();
		void preorder();
};  

ThreadedBT::ThreadedBT()
{
	root = NULL;
}

Node* ThreadedBT::getRoot()
{
	return root;
}

void ThreadedBT::create(int num)
{
	Node *z = new Node;
	z->data = num;
	z->lt = z->rt = true;
	
	Node *h = root;

	if(h == NULL)
	{
		Node *h = new Node;
		h->left = z;
		h->right = h;
		h->data = -9999;
		h->lt = h->rt = false;
		z->left = z->right = h;
		root = h;
		return;
	}

	Node *p = h;
	p = p->left;

	while(p != h)
	{
		if(num < p->data)
		{
			if(p->lt == false)
				p = p->left;
			else
			{
			        z->left = p->left;
				p->left = z;
				p->lt = false;
				z->right = p;
				
				return;						
			}
			
		}
		else if(num > p->data)
		{
			if(p->rt == false)
				p = p->right;
			else
			{
				z->right = p->right;
				p->right = z;
				p->rt = false;
				z->left = p;

				return;
			}
		}	
	}	
}

void ThreadedBT::inorder()
{
	Node *p;
	Node *h = root;
	
	p = h->left;

	while(p != h)
	{
		if(p->lt == false)
			p = p->left;
		
		cout << p->data << " ";
		while(p->rt == true)
		{
			p = p->right;
			if(p == h)
				break;
			cout << p->data << " ";
		}
		p = p->right;
	}
}

void ThreadedBT::preorder()
{
	Node *p;
	Node *h = root;
	p = h->left;

	while(p != h)
	{
		cout << p->data << " ";

		if(p->lt == false)
			p = p->left;

		else
		{
			if(p->rt == false)
				p = p->right;
			else
			{
				while(p != h && p->rt == true)
					p = p->right;
				if(p != h)
					p = p->right;
			}
		}
	}
}

int main()
{
	ThreadedBT thtree;

	while(true)
	{
		int choice, num;
		cout << "1. Add node/data" << endl;
		cout << "2. Display" << endl;
		cout << "0. Exit" << endl; 
		cout << "Enter choice" << endl;
		cin >> choice; 
		
		switch(choice)
		{
			case 1:
				cout << "Enter data as an integer" << endl;
				cin >> num;  
				thtree.create(num);
				break;
			case 2:
				thtree.inorder();
				cout << endl; 
				thtree.preorder();
				cout << endl;
				break;
			case 0:
				exit(1);
		}  
	}

	return 0;
}
