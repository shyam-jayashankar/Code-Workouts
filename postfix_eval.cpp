#include<iostream>
#include<stack>

using namespace std;

void eval_postfix(string s)
{
	stack<int>st;

	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9')
			st.push(s[i]-'0');

		else
		{
			int op2=st.top();
			st.pop();
			int op1=st.top();
			st.pop();

			switch(s[i])
			{
				case '+':
					st.push(op1+op2);
					break;
				case '-':
					st.push(op1-op2);
					break;
				case '*':
					st.push(op1*op2);
					break;
				case '/':
					st.push(op1/op2);
					break;
				case '^':
					st.push(op1^op2);
					break;
			}


		}

	}

	cout<<"\n Result: "<<st.top();

}

int main()
{
	string s="21+3*";
	eval_postfix(s);
	return 0;
}