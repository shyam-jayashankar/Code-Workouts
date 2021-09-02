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

void infix_to_prefix(string s)
{
	stack<char>st;

	string result;

	for(int i=s.length()-1;i>=0;i--)
	{
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            result+=s[i];

		else if(s[i]=='(')
			st.push(s[i]);

		else if (s[i]==')')
		{
			while(!st.empty() && st.top()!='(' )
			{
				result+=st.top();
				st.pop();
			}
			st.pop(); //remove the equivalent open paranthesis as well
		}

		else 
		{
			while(!st.empty() && preceed(st.top())>=preceed(s[i]) )
			{
				result+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}

	//if any characters remaining in stack, print them

	while(!st.empty())
	{
		result+=st.top();
		st.pop();
	}

	reverse(result.begin(), result.end());
	cout<<result;

}

int main()

{
	string s="x+y*z";
	infix_to_prefix(s);
	return 0;
}