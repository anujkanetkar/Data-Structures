#include <iostream>
#include <stack> 

using namespace std;

struct Node
{
	Node *left;
	char data;
	Node *right;
}; 

class BET
{
	private:
		Node *root;
	public:
		BET();
		Node* getRoot();
		void create(string);
		void inorder(Node*);
		bool isoperator(char);	
		int priority(char);
		string convert(string);
};

BET::BET()
{
	root = NULL;
}

Node* BET::getRoot()
{
	return root;
}

string BET::convert(string s)
{
	stack <char> stk;
	string post = "";
	int i = 0;
	
	while(i < s.length())
	{
		if(s[i] == '(')
			stk.push(s[i]);
		if(isalpha(s[i]))
			post = post + s[i];
		if(isoperator(s[i]))
		{
			if(priority(stk.top()) >= priority(s[i]))
			{
				post = post + stk.top();
				stk.pop();
			}
			stk.push(s[i]);
		}
		if(s[i] == ')')
		{
			while(stk.top() != ')')
			{
				post = post + stk.top();
				stk.pop();
			}
		}
		i++;
	}

	while(!stk.empty())
	{
		post = post + stk.top();
		stk.pop();
	}

	return post;
}

/*void BET::create(string str)
{
	stack <Node*> s;
	
	for(int i=0; i<str.length(); i++)
	{
		if(isoperator(str[i]))
		{
			Node *t = new Node;
			t->left = t->right = NULL;
			t->data = str[i];

			Node *t1 = s.top();
			s.pop();
			Node *t2 = s.top();
			s.pop();

			t->right = t1;
			t->left = t2;
			s.push(t);
		}
		else
		{
			Node *t = new Node;
			s.push(t);
		}
	}

	root = s.top();
	s.pop();
}*/

bool BET::isoperator(char ch)
{
	string s = "+-*/";
	int i = 0;
	while(i < s.length())
	{
		if(ch == s[i])
			return true;
		i++;
	}
	return false;	
}

int BET:: priority(char ch)
{
	if(ch == '/' || ch == '*')
		return 2;
	else if(ch == '+' || ch == '-')
		return 1;
	else
		return 0;
}

void BET::inorder(Node *r)
{
	if(r == NULL)
		return;
	inorder(r->left);
	cout << r->data << "\t";
	inorder(r->right);
}

int main()
{
	string in = "a-b*c-d/e+f";
	//string expr = "abc*-de/f+";
	BET expTree;
	string expr = expTree.convert(in);
	cout << expr;
	//expTree.create(expr);
	//Node *root = expTree.getRoot();
	//expTree.inorder(root);
}
