#include <iostream>

using namespace std;

const int MAX = 100;

class String
{
    private:
        char str[MAX];
    public:
        String()
        {
            str[0] = '\0';
        }

        void getString()
        {
            cout << "Enter a string: " << endl;
            cin >> str;
        }

        void display()
        {
	    cout << str << endl;      
        }

        int getLength()
        {
            int i,count;
            i = count = 0;
            while(str[i])
            {
                count++;
                i++;
            }
            return count;
        }
	
	//copy ctor
        /*String(const String &s)
        {
            int i;
		i = 0;
            while(s.str[i])
            {
                str[i] = s.str[i];
                i++;
            }
            str[i] = '\0';
        }*/

        void append(String s1)
        {
            int i;
		i = 0;
            while(str[i])
                i++;
            int j = 0;
            while(s1.str[j])
                str[i++] = s1.str[j++];
        }

        void reverse()
        {
            int i,l;
		char j;
            l = getLength();
            if(l%2 == 0)
            {
                for(i=0; i<=l/2-1; i++)
		{
			j = str[i];
			str[i] = str[l-(i+1)];
			str[l-(i+1)] = j;
		}
            }
		else
		{
			for(i=0; i<(l-1)/2; i++)
			{
				j = str[i];
				str[i] = str[l-(i+1)];		
				str[l-(i+1)] = j;
			}
	    	}
        }

        int getFrequency(char ch)
        {
            int i,count;
		count = 0;
            while(str[i])
            {
                if(ch == str[i])
                    count++;
                i++;
            }
            return count;
        }
};

int main()
{
	String s,s2,s3;
    int choice;
    int l;
    int freq_char;
	char ch;
    while(1)
    {
        cout << "Enter choice code: 1 for length, 2 for copying, 3 for concatenation, 4 for reversal, 5 for frequency of a character" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                s.getString();
                int l;
                l = s.getLength();
                cout << "Length of string is: " << l << endl;
                break;
           /* case 2:
                s.getString();
                String s1 = s;
                break;*/
            case 3:
                s2.getString();
                s3.getString();
                cout << "Concatenated string is: ";
                s2.append(s3);
                s2.display();
                break;
            case 4:
                s.getString();
                cout << "Reversed string is: ";
                s.reverse();
		s.display();
                break;
            case 5:
                s.getString();
		cout << "Enter the character to be counted: " << endl;
		cin >> ch;
                freq_char = s.getFrequency(ch);
                cout << "Frequency of the character is: " << freq_char << endl;
                break;
            default:
                cout << "Invalid code entered" << endl;
        }
    }
    return 0;
}
