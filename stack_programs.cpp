#include<iostream>
#include<stack>

using namespace std;

bool matching(char a, char b)
{
	return((a=='{' && b=='}')||(a=='(' && b==')')||(a=='[' && b==']'));
}


bool check_balance_paranthesis(string s, int length)
{
	stack<char>st;

	for(int i=0;i<length;i++)
	{
		if(s[i]=='('||s[i]=='['||s[i]=='{')
			st.push(s[i]);

		else
		{
			if(st.empty())
				return false;

			else if(matching(st.top(),s[i])==false)
				return false;

			else
				st.pop();
		}
		
	}

	return (st.empty());
}


int main()
{
	string input="[()]";
	int n=input.length();
	if(check_balance_paranthesis(input,n))
		cout<<"\n given expression is balanced";
	else
		cout<<"\n given expression is not balanced";
	cout<<endl;
	return 0;
}