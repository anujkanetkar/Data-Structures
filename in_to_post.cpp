#include <iostream> 
#include <string>
#include <cstdlib>

using namespace std;

const int MAX = 100;

class Stack
{
private:
	char a[MAX];
	int top; 
public:
	Stack()
	{
		top = -1;
	}

	void push(char);
	char pop();
	bool isEmpty();
};

//template <class T>
void Stack::push(char t)
{
	top++;
	a[top] = t;
}

//template <class T>
char Stack::pop()
{
	char c;
	c = a[top];
	top--;
	return c;
}

bool Stack::isEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Post
{
private:
	string expr;
public:
	Post()
	{
		expr = "";
	}

	void convert(string);
	void display();
	int priority(char);
	int isoperator(char);
	int evaluate();
};

void Post::convert(string exp)
{
	Stack s;
	int i = 0;
	char opr;
	while (i < exp.length())
	{
		if (exp[i] == ' ')
		{
			i++;
		}

		if (exp[i] == '(')
		{
			s.push(exp[i]);
			i++;
		}

		if (isdigit(exp[i]) || isalpha(exp[i]))
		{
			expr = expr + exp[i];
			//expr.push_back(exp[i]);
			//expr.append(1, exp[i]);
			i++;
		}

		if (isoperator(exp[i]))
		{
			if (!s.isEmpty())
			{
				opr = s.pop();
				while (priority(opr) >= priority(exp[i]))
				{
					expr += opr;
					opr = s.pop();
				}
				
				s.push(opr);
			}
			s.push(exp[i]);
			i++;	
		}

		if (exp[i] == ')')
		{
			opr = s.pop();
			while (opr != '(')
			{
				expr += opr;
				opr = s.pop();
			}
			i++;
		}
	}

	while (!s.isEmpty())
	{
		opr = s.pop();
		expr += opr;
	}
	//expr += '\0';
}

void Post::display()
{
	cout << expr << endl;
}

int Post::evaluate()
{
	Stack s1;
	int i = 0;
	int n1, n2, n3, res;
	while (expr[i] != '\0')
	{
		if (isdigit(expr[i]))
		{
			res = expr[i];
			s1.push(expr[i]);
		}
		else
		{
			n1 = s1.pop() - 48;
			n2 = s1.pop() - 48;
			switch (expr[i])
			{
				case '+':
					n3 = n2 + n1;
					break;
				case '-':
					n3 = n2 - n1;
					break;
			case '*':
				n3 = n2 * n1;
				break;
			case '/':
				n3 = n2 / n1;
				break;
			}
			s1.push(n3+48);
		}
		i++;
	}
	res = s1.pop() - 48;
	return res;
}

int Post::priority(char ch)
{
	if (ch == '/' || ch == '*')
	{
		return 2;
	}
	if (ch == '+' || ch == '-')
	{
		return 1;
	}
	return 0;
}

int Post::isoperator(char ch)
{
	string s = "+-*/";
	int i = 0;
	while (s[i] != '\0')
	{
		if (ch == s[i])
		{
			return 1;
		}
		i++;
	}
	return 0;
}

int main()
{
	Post p;
	string infix;
	int ans;
	char choice = 'y';
	while (choice == 'y')
	{
		cout << "Enter an expression in Infix form" << endl;
		//cin.ignore();
		//getline(cin, infix);
		cin >> infix;
		cout << "Postfix form is:";
		p.convert(infix);
		p.display();
		ans = p.evaluate();
		cout << ans << endl;
		cout << "Continue? (y/n)" << endl;
		cin >> choice;
	}
}


