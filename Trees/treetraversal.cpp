#include <iostream> 
#include <queue>
#include <stack>

using namespace std;

struct Node
{
	Node *lc;
	int data;
	Node *rc;
};

class BST
{
	private:
		Node *bt;
	public:
		BST()
		{
			bt = NULL;
		}

		Node* getRoot();
		Node* insert(Node*, int);
		void inorder(Node*);
		void preorder(Node*);
		void postorder(Node*);
		void bfs(Node*);
		void desc(Node*);
		int height(Node*);
		void inOrder(Node*);
		void preOrder(Node*);
		void postOrder(Node*);
		void Desc(Node*);
		int totnodes(Node*);
		int leaves(Node*);
		int rleaves(Node*);
		void delall(Node*);
};

Node* BST :: getRoot()
{
	return bt;
}

Node* BST :: insert(Node* root, int n)
{
	if(root == NULL)
	{
		Node *r = new Node;
		r -> rc = r -> lc = NULL;
		r -> data = n;
		root = r;
	}
	else
	{
		if(n < root -> data)
		{
			root->lc = insert(root->lc, n);
		}
		else
		{	
			root->rc = insert(root->rc, n);
		}
	}
	return root;
}

void BST :: inorder(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	inorder(root -> lc);
	cout << root -> data << "\t";
	inorder(root -> rc);
}

void BST :: preorder(Node *root)
{
	if(root == NULL)
		return;
	cout << root->data << "\t";
	preorder(root->lc);
	preorder(root->rc);
}

void BST :: postorder(Node *root)
{
	if(root == NULL)
		return;
	postorder(root->lc);
	postorder(root->rc);
	cout << root->data << "\t";
}

void BST :: bfs(Node *root)
{
	queue <Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node *node = q.front();
		q.pop();
		cout << node->data << "\t";
		if(node->lc != NULL)
			q.push(node->lc);
		if(node->rc != NULL)
			q.push(node->rc);
	}
}

void BST :: desc(Node *root)
{
	if(root == NULL)
		return;
	desc(root->rc);
	cout << root->data << "\t";
	desc(root->lc);
}

int BST :: height(Node *root)
{	
	int left, right;
	if(root == NULL)
		return 0;
	else
	{
		left = height(root->lc);
		right = height(root->rc);
		return (max(left, right) + 1);
	}
}

void BST :: inOrder(Node *root)
{
	stack <Node*> s;
	while(true)
	{
		while(root != NULL)
		{
			s.push(root);
			root = root->lc;
		}

		if(!s.empty())
		{
			root = s.top();
			s.pop();
			cout << root->data << "\t";
			root = root->rc;
		}
		else
			break;
	}
}

void BST :: preOrder(Node *root)
{
	stack <Node*> s;
	while(true)
	{
		while(root != NULL)
		{
			cout << root->data << "\t";
			s.push(root);
			root = root->lc;
		}

		if(!s.empty())
		{
			root = s.top();
			s.pop();
			root = root->rc;
		}
		else
		 	break;
	}
}

void BST :: postOrder(Node *root)
{
	stack <Node*> s;
	
	do
	{
		while(root != NULL)
		{
			if(root->rc != NULL)
				s.push(root->rc);
			s.push(root);
			root = root->lc;
		}
		root = s.top();
		s.pop();

		if(!s.empty() && root->rc != NULL && root->rc == s.top())
		{
			Node *t = s.top();
			s.pop();
			s.push(root);
			root = t;
		}
		else
		{
			cout << root->data << "\t";
			root = NULL;
		}
	}while(!s.empty());
}

void BST :: Desc(Node *root)
{
	stack <Node*> s;

	while(true)
	{
		while(root != NULL)
		{
			s.push(root);
			root = root->rc;	
		}

		if(!s.empty())
		{
			root = s.top();
			s.pop();
			cout << root->data << "\t";
			root = root->lc;
		}
		else 
			break;
	}
}

int BST :: totnodes(Node *root)
{
	if(root == NULL)
		return 0;
	else
		return (1 + totnodes(root->lc) + totnodes(root->rc));
}

int BST :: leaves(Node *root)
{
	queue <Node*> q;
	int count = 0;

	if(root == NULL)
		return 0;
	q.push(root);
	while(!q.empty())
	{	
		root = q.front();
		q.pop();
		if(root->lc != NULL)
			q.push(root->lc);
		if(root->rc != NULL)
			q.push(root->rc);
		if(root->lc == NULL && root->rc == NULL)
			count++;
	}

	return count;
	
}

int BST :: rleaves(Node *root)
{
	if(root == NULL)
		return 0;
	if(root->lc == NULL && root->rc == NULL)
		return 1;
	else
		return(rleaves(root->lc) + rleaves(root->rc));
}

void BST :: delall(Node *root)
{
	if(root == NULL)
		return;
	delall(root->lc);
	delall(root->rc);
	delete root;
}

int main()
{
	BST *bst = new BST;
	Node* root = bst->getRoot();
	root = bst->insert(root,10);
	
	bst->insert(root,2);
	bst->insert(root,5);
	bst->insert(root,22);
	bst->insert(root,12);
	bst->insert(root,11);
	
	bst->inorder(root);
	cout << endl;
	bst->preorder(root);
	cout << endl;
	bst-> postorder(root);
	cout << endl;

	bst->bfs(root);
	cout << endl;

	bst->desc(root);
	cout << endl;

	int h = bst->height(root);
	cout << h << endl;

	bst->inOrder(root);
	cout << endl;
	bst->preOrder(root);
	cout << endl;
	bst->postOrder(root);
	cout << endl;

	bst->Desc(root);
	cout << endl;

	int n = bst->totnodes(root);
	cout << n << endl;

	int c = bst->leaves(root);
	cout << c << endl;
	c = bst->rleaves(root);
	cout << c << endl;

	bst->delall(root);
	return 0;
} 
