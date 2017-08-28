#include <iostream>

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

		//bool isFull();
		//bool isEmpty();
		void push(char);
		char pop();
};

/*bool Stack :: isFull()
{
	if(top == MAX-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}*/

/*bool Stack :: isEmpty()
{
	if(top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}*/

void Stack :: push(char ch)
{
	if(top == MAX-1)
	{
		throw("Stack is full");
	}
	else
	{
		top++;
		str[top] = ch;
	}
}

char Stack :: pop()
{
	char ch;
	if(top == -1)
	{
		throw("Stack is empty");	
	}
	else
	{
		ch = str[top];
		top--;
		return ch;
	}
}

int isMatching();

int main()
{
	//Stack s;
	//bool flag1, flag2, flag3;
	//flag1 = flag2 = flag3 = true;
	//char exp[MAX], par;
	//char choice;
	int i;
	
	try
	{
		i = isMatching();
	}

	catch(string s)
	{
		cout << s << endl;
	}
	/*do
	{
		cout << "Enter the expression:" << endl;
		cin >> exp;
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
								cout << "Expression not well parenthesized" << endl;
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
								cout << "Expression not well parenthesized" << endl;
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
								cout << "Expression not well parenthesized" << endl;
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
		}
		if(flag1 == true && flag2 == true && flag3 == true)
		{
			cout << "Expression is well parenthesized" << endl;
		}
		cout << "Continue? (y/n)" << endl;
		cin >> choice;
	}while(choice != 'n');*/
}

int isMatching()
{
	Stack s;
	bool flag = true;
	int i = 0;
	char choice;
	char exp[MAX];
	do
	{
		cout << "Enter the expression";
		cin >> exp;
		while(exp[i] != '\0')
		{
			if(exp[0] == '}' || exp[0] == ']' || exp[0] == ')')
                	{
                	        cout << "Invalid expression" << endl;
                	        return 0;
                	}
			else
			{
				if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
				{
					s.push(exp[i]);
					i++;
					continue;
				}
				if(exp[i] == ')')
				{
					if(s.pop() == '(')
					{
						i++;
						continue;
					}
					else
					{
						cout << "Not well parenthesized";
						return 0;
					}
				}
				if(exp[i] == ']')
                                {
                                        if(s.pop() == '[')
                                        {
                                                i++;
                                                continue;
                                        }
                                        else
                                        {
                                                cout << "Not well parenthesized";
                                                return 0;
                                        }
                                }
				if(exp[i] == '}')
                                {
                                        if(s.pop() == '{')
                                        {
                                                i++;
                                                continue;
                                        }
                                        else
                                        {
                                                cout << "Not well parenthesized";
                                                return 0;
                                        }
                                }
				flag = false;
			}
		}
	}while(choice != 'n');
	if(flag == false)
	{
		cout << "Not well parenthesized";
		return 0;
	}
	else
	{
		cout << "Expression is well parenthesized" << endl;
	}
}
