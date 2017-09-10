#include <iostream> 
#include <string>

using namespace std; 

const int MAX = 100;

template <class T>
class Stack
{ 
	private:
		T a[MAX];
		int top; 
	public:
		Stack()
		{
			top = -1;
		} 

		void push(T);
		T pop();
};

template <class T>
void Stack <class T> :: push(T t)
{
	if(top == MAX - 1)
	{
		cout << "Stack is full" << endl;
	}
	else
	{
		top++;
		a[top] = t;
	}
}

template <class T>
T Stack <class T> :: pop()
{
	if(top == -1)
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		T t;
		t = a[top];
		top--;
		return t;	
	}
}

class Post
{ 
	private : 
		string expr;
	public : 
		Post()
		{
			 expr = '\0';
		}

		void convert();
		void display();
};  

void Post :: convert(string exp)
{	
	int i = 0;
	char opr;
	while(exp[i] != '\0')
	{
		if(exp[i] == ' ')
		{
			i++;
		}
			
		if(exp[i] == '(')
		{
			push(exp[i]);
			i++;
		}
		if(isdigit(exp[i]) || isalpha(exp[i]))
		{
			expr.append(exp[i]);
			i++;
		}
		if(isoperator(exp[i]))
		{
			if(top != -1)
			{
				opr = pop();
				while(priority(opr) >= priority(exp[i]));
				{
					expr.append(opr);
					opr = pop();		
				}
				push(exp[i]);
				i++;
			}
			else
			{
				push(exp[i]);
				i++;
			}				
		}		
	}
}

void Post :: display()
{
	cout << expr << endl;
}

int Post :: evaluate()
{
	int i = 0;
	int n1, n2, res;
	while(expr[i] != '\0')
	{
		if(isdigit(expr[i]))
		{
			res = expr[i];
			push(expr[i]);
		}
		else
		{
			n1 = pop();
			n2 = pop();
			switch(expr[i])
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
			push(n3);
		}
		i++;
	}
	res = pop();
	return res;
}

int priority(char ch)
{
	if(ch == '/' || ch == '*')
	{
		return 2;
	}
	if(ch == '+' || ch == '-')
	{
		return 1;
	}
	return 0;
}

int isoperator(char ch)
{
	string s = "+-*/";
	int i = 0;
	while(s[i] != '\0')
	{
		if(ch == s[i])
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
	while(true)
	{
		cout << "Enter an expression in Infix form" << endl;
		cin.ignore();
		getline(cin, infix);
		cout << "Postfix form is:";
		p.convert(infix);
		p.display();
		ans = p.evaluate();	
	}
}
