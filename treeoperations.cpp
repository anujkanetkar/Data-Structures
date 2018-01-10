#include <iostream>nclude <iostream>
#include <stack>
#include <queue>
#include <cstdlib>

using namespace std;

struct Node
{
	Node *left;
	int data;
	Node *right;
};

class BinTree
{
	private:
		Node *root;
	public:
		BinTree();
		void create();
		void inorder(Node*);
		void preorder(Node*);
		void postorder(Node*);
		Node* getRoot();
		void preOrder(Node*);
		void postOrder(Node*);
		int height(Node*);
		int leaves(Node*);
		void delall(Node*);
		void mirror(Node*);
		int intnodes(Node*);
		void operator=(BinTree&);
		Node* copy(Node*);
};

BinTree::BinTree()
{
	root = NULL;
}

void BinTree::create()
{
	char ch;
	do
	{
		bool flag = false;
		int val;
		cout << "Enter data" << endl;
		cin >> val;
		Node *p = new Node;
		p->left = p->right = NULL;
		p->data = val;

		if(root == NULL)
			root = p;
		else
		{

			Node *q = root;
			do
			{
				cout << "Enter l for left and r for right" << endl;
				char c;
				cin >> c;
				if(c == 'l')
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

Node* BinTree::getRoot()
{
	return root;
}

void BinTree::inorder(Node *r)
{
	if(r == NULL)
		return;

	inorder(r->left);
	cout << r->data << " ";
	inorder(r->right);
}

void BinTree::preorder(Node *r)
{
	if(r == NULL)
		return;

	cout << r->data << " ";
	preorder(r->left);
	preorder(r->right);
}

void BinTree::postorder(Node *r)
{
	if(r == NULL)
		return;

	postorder(r->left);
	postorder(r->right);
	cout << r->data << " ";
}

void BinTree::preOrder(Node *r)
{
	stack <Node*> s;
	while(true)
	{
			while(r != NULL)
			{
				cout << r->data << " ";
				s.push(r);
				r = r->left;
			}
			if(!s.empty())
			{
				r = s.top();
				s.pop();
				r = r->right;
			}
			else
				break;
	}
}

void BinTree::postOrder(Node *r)
{
	stack <Node*> s;

	do
	{
		while(r != NULL)
		{
			if(r->right != NULL)
				s.push(r->right);
			s.push(r);
			r = r->left;
		}

		r = s.top();
		s.pop();

		if(!s.empty() && r->right != NULL && r->right == s.top())
		{
			Node *x = s.top();
			s.pop();
			s.push(r);
			r = x;
		}
		else
		{
			cout << r->data << " ";
			r = NULL;
		}

	}while(!s.empty());
}

int BinTree::height(Node *r)
{
	if(r == NULL)
		return 0;
	else
	{
		int lh = height(r->left);
		int rh = height(r->right);
		return (max(lh, rh) + 1);
	}
}

int BinTree::leaves(Node *r)
{
	if(r == NULL)
		return 0;
	else if(r->left == NULL && r->right == NULL)
		return 1;
	else
		return(leaves(r->left) + leaves(r->right));
}

int BinTree::intnodes(Node *r)
{
	int count = 0;

	if(r->left != NULL || r->right != NULL)
	{
		count = 1;
		if(r->left != NULL)
			count = count + intnodes(r->left);
		if(r->right != NULL)
			count = count + intnodes(r->right);
	}

	return count;
}

void BinTree::delall(Node *root)
{
	if(root == NULL)
		return;

	delall(root->right);
	delall(root->left);
	delete root;
}

void BinTree::mirror(Node *r)
{
	if(r == NULL)
		return;

	Node *temp;

	mirror(r->left);
	mirror(r->right);

	temp = r->left;
	r->left = r->right;
	r->right = temp;
}

/*void BinTree::operator=(BinTree &bt)
{
	queue <Node*> qo, qc;

	root = new Node;
	root->data = bt.root->data;
	root->left = root->right = NULL;

	Node *o = bt.root;
	Node *c = root;

	qo.push(o);
	qc.push(c);

	while(!qo.empty())
	{
		o = qo.front();
		c = qc.front();

		if(o->left != NULL)
		{
			c->left = new Node;
			c->left->data = o->left->data;
			qo.push(o->left);
			qc.push(c->left);
		}

		if(o->right != NULL)
		{
			c->right = new Node;
			c->right->data = o->right->data;
			qo.push(o->right);
			qc.push(c->right);
		}

		qo.pop();
		qc.pop();
	}
}*/

void BinTree::operator=(BinTree &t)
{
	if(t.root == NULL)
		return;

	root = copy(t.root);
}

Node* BinTree::copy(Node *ro)
{
	if(ro == NULL)
		return NULL;

	Node *temp = new Node;
	temp->data = ro->data;
	temp->left = copy(ro->left);
	temp->right = copy(ro->right);

	return temp;

}

int main()
{
	BinTree bt;
	bt.create();
	Node *r = bt.getRoot();
	BinTree bt1;

	while(true)
	{

		cout << "1. Preorder traversal" << endl;
		cout << "2. Postorder traversal" << endl;
		cout << "3. Mirror image" << endl;
		cout << "4. Height" << endl;
		cout << "5. Copy" << endl;
		cout << "6. Leaves" << endl;
		cout << "7. Internal nodes" << endl;
		cout << "8. Erase all" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice" << endl;
		int choice;
		cin >> choice;

		switch(choice)
		{
			case 1:
				cout << "Recursive: ";
				bt.preorder(r);
				cout << endl;
				cout << "Non-recursive: ";
				bt.preOrder(r);
				cout << endl;
				break;

			case 2:
				bt.postorder(r);
				cout << endl;
				bt.postOrder(r);
				cout << endl;
				break;

			case 3:
			{
				Node *r1 = bt1.getRoot();
				bt1.mirror(r1);
				bt1.inorder(r1);
				cout << endl;
			}
				break;

			case 4:
			{
				int ht = bt.height(r);
				if(ht == 1)
					cout << "Height is: " << ht << endl;
				else
						cout << "Height is: " << ht - 1 << endl;
			}
				break;

			case 5:
			{
				bt1 = bt;
				Node *r1 = bt1.getRoot();
				bt1.inorder(r1);
				cout << endl;
			}
				break;

			case 6:
			{
				int lc = bt.leaves(r);
				cout << "No of leaves are: " << lc << endl;
			}
				break;

			case 7:
			{
				int count = bt.intnodes(r);
				cout << "Internal nodes are: " << count << endl;
			}
				break;

			case 8:
				bt.delall(r);
				r = NULL;
				break;

			case 0:
				exit(1);
		}

	}

	return 0;
}

