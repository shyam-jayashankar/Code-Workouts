#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int preceed(char s)
{
	if(s=='^')
		return 4;
	if(s=='*'||s=='/')
		return 3;
	if(s=='+'||s=='-')
		return 2;
	else
		return -1;
}

void infix_to_postfix(string s)
{
	stack<char>st;

	//string result;

	for(int i=0;i<s.length();i++)
	{
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            cout<<s[i];

		else if(s[i]=='(')
			st.push(s[i]);

		else if (s[i]==')')
		{
			while(!st.empty() && st.top()!='(' )
			{
				cout<<st.top();
				st.pop();
			}
			st.pop(); //remove the equivalent open paranthesis as well
		}

		else 
		{
			while(!st.empty() && preceed(st.top())>=preceed(s[i]) )
			{
				cout<<st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}

	//if any characters remaining in stack, print them

	while(!st.empty())
	{
		cout<<st.top();
		st.pop();
	}


}

int main()

{
	string s="a+b*(c^d-e)^(f+g*h)-i";
	infix_to_postfix(s);
	return 0;
}