#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 100;

class Stack
{
	private:
		char str[MAX];
		int top;
	public:
		Stack()
		{
			top = -1;
		}

		bool isFull();
		bool isEmpty();
		void push(char);
		char pop();
};

bool Stack :: isFull()
{
	if(top == MAX-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Stack :: isEmpty()
{
	if(top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Stack :: push(char ch)
{
	top++;
	str[top] = ch;
}

char Stack :: pop()
{
	char ch;
	ch = str[top];
	top--;
	return ch;
}

int main()
{
	Stack s;
	bool flag1, flag2, flag3;

	char exp[MAX], par;
	char choice;
	int i;

	do
	{
		flag1 = flag2 = flag3 = true;
		cout << "Enter the expression:" << endl;
		//fflush(stdin);
		cin >> exp;
		i = 0;

		if(exp[0] == '}' || exp[0] == ']' || exp[0] == ')')
		{
			cout << "Invalid expression" << endl;
			return 0;
		}
		else
		{
			while(exp[i] != '\0')
			{
				switch(exp[i])
				{
					case '{':
						if(!s.isFull())
						{
							s.push(exp[i]);
						}
						else
						{
							cout << "Stack is full" << endl;
						}
						break;
					case '(':
						if(!s.isFull())
						{
							s.push(exp[i]);
						}
						else
						{
							cout << "Stack is full" << endl;
						}
						break;
					case '[':
						if(!s.isFull())
						{
							s.push(exp[i]);
						}
						else
						{
							cout << "Stack is full" << endl;
						}
						break;
					case '}':
						if(!s.isEmpty())
						{
							par = s.pop();
							if(par == '{')
							{
								//cout << "Expression is well parenthesized" << endl;
								flag1 = true;
							}
							else
							{
								//cout << "Expression not well parenthesized" << endl;
								flag1 = false;
							}
						}
						else
						{
							cout << "Not well parenthesized" << endl;
							flag1 = false;
						}
						break;
					case ')':
						if(!s.isEmpty())
						{
							par = s.pop();
							if(par == '(')
							{
								//cout << "Expression is well parenthesized" << endl;
								flag2 = true;
							}
							else
							{
								//cout << "Expression not well parenthesized" << endl;
								flag2 = false;
							}
						}
						else
						{
							cout << "Not well parenthesized" << endl;
							flag2 = false;
						}
						break;
					case ']':
						if(!s.isEmpty())
						{
							par = s.pop();
							if(par == '[')
							{
								flag3 = true;
								//cout << "Expression is well parenthesized" << endl;
							}
							else
							{
								//cout << "Expression not well parenthesized" << endl;
								flag3 = false;
							}
						}
						else
						{
							cout << "Not well parenthesized" << endl;
							flag3 = false;
						}
						break;
				}
				i++;
			}
			if(flag1 == true && flag2 == true && flag3 == true)
					{
						cout << "Expression is well parenthesized" << endl;
					}
			else
			{
				cout << "Expression not well parenthesized" << endl;
			}
					//cout << "Continue? (y/n)" << endl;
		}
		/*if(flag1 == true && flag2 == true && flag3 == true)
		{
			cout << "Expression is well parenthesized" << endl;
		}*/
		cout << "Continue? (y/n)" << endl;
		cin >> choice;
		//fflush(stdin);
	}while(choice != 'n');
}
